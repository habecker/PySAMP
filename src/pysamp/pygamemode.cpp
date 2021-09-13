#include "pygamemode.h"


std::string PyGamemode::_getcwd()
{
	// 4096!? See https://eklitzke.org/path-max-is-tricky
	char buf[4096];
	return(
		GETCWD(buf, sizeof(buf))
		? std::string(buf)
		: std::string("")
	);
}

PyGamemode::PyGamemode(CallbacksManager* callbacks)
:
	callbacks(callbacks),
	_save(nullptr)
{
	if(PyImport_AppendInittab("samp", &PyInit_samp) == -1)
	{
		sampgdk::logprintf(
			"Adding samp module to Python interpreter failed."
		);
		return;
	}

	Py_SetPythonHome(PYTHON_HOME);
	Py_Initialize();

	PyObject* syspath = PySys_GetObject("path");

	if(!syspath)
	{
		sampgdk::logprintf("Getting Python sys.path object failed.");
		return;
	}

	PyObject* str_cwd = PyUnicode_FromString(_getcwd().c_str());
	PyList_Append(syspath, str_cwd);
	Py_DECREF(str_cwd);

	PyObject* pysamp_module = PyImport_ImportModule("samp");

	if(!pysamp_module)
	{
		sampgdk::logprintf("Couldn't import samp module:");
		PyErr_Print();
		return;
	}

	for(
		auto item = PyGamemode::constants.begin();
		item != PyGamemode::constants.end();
		++item
	)
	{
		if(
			PyObject_SetAttrString(
				pysamp_module,
				item->first.c_str(),
				Py_BuildValue("i", item->second)
			) == -1
		)
		{
			sampgdk::logprintf("Couldn't set constants on samp module:");
			PyErr_Print();
			return;
		}
	}

	this->config = {
		{"encoding", Py_BuildValue("s", "cp1252")}
	};

	Py_UNBLOCK_THREADS
}

PyGamemode::~PyGamemode()
{
	Py_BLOCK_THREADS

	for(const auto item : this->config)
		Py_DECREF(item.second);

	PyGamemode::unload();
	Py_FinalizeEx();
}

void PyGamemode::load()
{
	PySAMP::GIL gil;

	PyObject* name = PyUnicode_FromString("python");
	this->module = PyImport_Import(name);
	Py_DECREF(name);

	if(this->module == NULL)
	{
		sampgdk::logprintf("PyGamemode::load() failed:");
		PyErr_Print();
		return;
	}

	loaded = true;
	disabled = false;
}

void PyGamemode::reload()
{
	PySAMP::GIL gil;

	if(this->module)
	{
		PyObject* new_module = PyImport_ReloadModule(this->module);

		if(new_module == nullptr)
		{
			sampgdk::logprintf("PyGamemode::reload() failed:");
			PyErr_Print();
		}
		else
		{
			Py_DECREF(this->module);
			Py_INCREF(new_module);
			this->module = new_module;
			disabled = false;
		}
	}
}

void PyGamemode::unload()
{
	PySAMP::GIL gil;
	Py_XDECREF(this->module);
	loaded = false;
	disabled = true;
}

void PyGamemode::disable()
{
	disabled = true;
}

bool PyGamemode::isLoaded()
{
	return PyGamemode::loaded;
}

bool PyGamemode::isEnabled()
{
	return PyGamemode::isLoaded() && !PyGamemode::disabled;
}

PyObject* PyGamemode::pyConfig(PyObject *self, PyObject *args, PyObject *kwargs)
{
	PySAMP::GIL gil;

	if(PyTuple_Size(args) != 0)
	{
		PyErr_SetString(
			PyExc_ValueError,
			"config() does not take any positional argument"
		);
		return NULL;
	}

	if(kwargs == NULL)
	{
		PyObject* return_value = PyDict_New();

		for(auto item : this->config)
			PyDict_SetItemString(return_value, item.first.c_str(), item.second);

		return return_value;
	}

	PyObject* items = PyDict_Items(kwargs);

	for(int i = 0; i < PyList_Size(items); ++i)
	{
		PyObject* item = PyList_GetItem(items, i);
		const char *key_name = PyUnicode_AsUTF8AndSize(
			PyTuple_GetItem(item, 0),
			NULL
		);

		if(this->config.count(key_name) < 1)
		{
			PyErr_Format(
				PyExc_ValueError,
				"config() key %s does not exist",
				key_name
			);
			Py_DECREF(items);
			return NULL;
		}

		this->config[key_name] = PyTuple_GetItem(item, 1);
	}

	Py_DECREF(items);
	Py_RETURN_NONE;
}

int PyGamemode::callback(
	const std::string name,
	PyObject* pArgs,
	cell* retval,
	bool* stop
)
{
	int ret = -1;

	if(
		disabled
		|| this->module == nullptr
	)
		return ret;

	PySAMP::GIL gil;

	if(!PyObject_HasAttrString(this->module, name.c_str()))
		return ret;

	PyObject* pFunc = PyObject_GetAttrString(this->module, name.c_str());

	Py_XINCREF(pFunc);
	Py_XINCREF(pArgs);

	if(pFunc && PyCallable_Check(pFunc))
	{
		PyObject* pValue = PyObject_CallObject(pFunc, pArgs);

		if(PyErr_Occurred())
		{
			PyErr_Print();
			ret = !this->callbacks->getBadret(name);
			pValue = Py_None;
		}

		if(pValue != Py_None)
		{
			ret = PyObject_IsTrue(pValue);

			if(ret == -1)
			{
				PyErr_Print();
				ret = !this->callbacks->getBadret(name);
			}
		}

		Py_XDECREF(pValue);
	}

	Py_XDECREF(pFunc);
	Py_XDECREF(pArgs);

	if(retval != NULL)
		*retval = ret;

	if(
		stop != NULL
		&& ret != -1
		&& ret == this->callbacks->getBadret(name)
	)
		*stop = true;

	return ret;
}

const std::unordered_map<std::string, int> PyGamemode::constants = {
	{"MAX_PLAYER_NAME", 24},
	{"MAX_CLIENT_MESSAGE", 144},
	{"MAX_PLAYERS", 1000},
	{"MAX_VEHICLES", 2000},
	{"MAX_ACTORS", 1000},
	{"INVALID_PLAYER_ID", 0xFFFF},
	{"INVALID_VEHICLE_ID", 0xFFFF},
	{"INVALID_ACTOR_ID", 0xFFFF},
	{"NO_TEAM", 255},
	{"MAX_OBJECTS", 1000},
	{"INVALID_OBJECT_ID", 0xFFFF},
	{"MAX_GANG_ZONES", 1024},
	{"MAX_TEXT_DRAWS", 2048},
	{"MAX_PLAYER_TEXT_DRAWS", 256},
	{"MAX_MENUS", 128},
	{"MAX_3DTEXT_GLOBAL", 1024},
	{"MAX_3DTEXT_PLAYER", 1024},
	{"MAX_PICKUPS", 4096},
	{"INVALID_MENU", 0xFF},
	{"INVALID_TEXT_DRAW", 0xFFFF},
	{"INVALID_GANG_ZONE", -1},
	{"INVALID_3DTEXT_ID", 0xFFFF},
	{"SERVER_VARTYPE_NONE", 0},
	{"SERVER_VARTYPE_INT", 1},
	{"SERVER_VARTYPE_STRING", 2},
	{"SERVER_VARTYPE_FLOAT", 3},
	{"TEXT_DRAW_FONT_SPRITE_DRAW", 4},
	{"TEXT_DRAW_FONT_MODEL_PREVIEW", 5},
	{"DIALOG_STYLE_MSGBOX", 0},
	{"DIALOG_STYLE_INPUT", 1},
	{"DIALOG_STYLE_LIST", 2},
	{"DIALOG_STYLE_PASSWORD", 3},
	{"DIALOG_STYLE_TABLIST", 4},
	{"DIALOG_STYLE_TABLIST_HEADERS", 5},
	{"PLAYER_STATE_NONE", 0},
	{"PLAYER_STATE_ONFOOT", 1},
	{"PLAYER_STATE_DRIVER", 2},
	{"PLAYER_STATE_PASSENGER", 3},
	{"PLAYER_STATE_EXIT_VEHICLE", 4},
	{"PLAYER_STATE_ENTER_VEHICLE_DRIVER", 5},
	{"PLAYER_STATE_ENTER_VEHICLE_PASSENGER", 6},
	{"PLAYER_STATE_WASTED", 7},
	{"PLAYER_STATE_SPAWNED", 8},
	{"PLAYER_STATE_SPECTATING", 9},
	{"PLAYER_MARKERS_MODE_OFF", 0},
	{"PLAYER_MARKERS_MODE_GLOBAL", 1},
	{"PLAYER_MARKERS_MODE_STREAMED", 2},
	{"WEAPON_BRASSKNUCKLE", 1},
	{"WEAPON_GOLFCLUB", 2},
	{"WEAPON_NITESTICK", 3},
	{"WEAPON_KNIFE", 4},
	{"WEAPON_BAT", 5},
	{"WEAPON_SHOVEL", 6},
	{"WEAPON_POOLSTICK", 7},
	{"WEAPON_KATANA", 8},
	{"WEAPON_CHAINSAW", 9},
	{"WEAPON_DILDO", 10},
	{"WEAPON_DILDO2", 11},
	{"WEAPON_VIBRATOR", 12},
	{"WEAPON_VIBRATOR2", 13},
	{"WEAPON_FLOWER", 14},
	{"WEAPON_CANE", 15},
	{"WEAPON_GRENADE", 16},
	{"WEAPON_TEARGAS", 17},
	{"WEAPON_MOLTOV", 18},
	{"WEAPON_COLT45", 22},
	{"WEAPON_SILENCED", 23},
	{"WEAPON_DEAGLE", 24},
	{"WEAPON_SHOTGUN", 25},
	{"WEAPON_SAWEDOFF", 26},
	{"WEAPON_SHOTGSPA", 27},
	{"WEAPON_UZI", 28},
	{"WEAPON_MP5", 29},
	{"WEAPON_AK47", 30},
	{"WEAPON_M4", 31},
	{"WEAPON_TEC9", 32},
	{"WEAPON_RIFLE", 33},
	{"WEAPON_SNIPER", 34},
	{"WEAPON_ROCKETLAUNCHER", 35},
	{"WEAPON_HEATSEEKER", 36},
	{"WEAPON_FLAMETHROWER", 37},
	{"WEAPON_MINIGUN", 38},
	{"WEAPON_SATCHEL", 39},
	{"WEAPON_BOMB", 40},
	{"WEAPON_SPRAYCAN", 41},
	{"WEAPON_FIREEXTINGUISHER", 42},
	{"WEAPON_CAMERA", 43},
	{"WEAPON_NIGHTVISION", 44},
	{"WEAPON_INFRARED", 45},
	{"WEAPON_PARACHUTE", 46},
	{"WEAPON_VEHICLE", 49},
	{"WEAPON_DROWN", 53},
	{"WEAPON_COLLISION", 54},
	{"KEY_ACTION", 1},
	{"KEY_CROUCH", 2},
	{"KEY_FIRE", 4},
	{"KEY_SPRINT", 8},
	{"KEY_SECONDARY_ATTACK", 16},
	{"KEY_JUMP", 32},
	{"KEY_LOOK_RIGHT", 64},
	{"KEY_HANDBRAKE", 128},
	{"KEY_LOOK_LEFT", 256},
	{"KEY_SUBMISSION", 512},
	{"KEY_LOOK_BEHIND", 512},
	{"KEY_WALK", 1024},
	{"KEY_ANALOG_UP", 2048},
	{"KEY_ANALOG_DOWN", 4096},
	{"KEY_ANALOG_LEFT", 8192},
	{"KEY_ANALOG_RIGHT", 16384},
	{"KEY_YES", 65536},
	{"KEY_NO", 131072},
	{"KEY_CTRL_BACK", 262144},
	{"KEY_UP", -128},
	{"KEY_DOWN", 128},
	{"KEY_LEFT", -128},
	{"KEY_RIGHT", 128},
	{"BODY_PART_TORSO", 3},
	{"BODY_PART_GROIN", 4},
	{"BODY_PART_LEFT_ARM", 5},
	{"BODY_PART_RIGHT_ARM", 6},
	{"BODY_PART_LEFT_LEG", 7},
	{"BODY_PART_RIGHT_LEG", 8},
	{"BODY_PART_HEAD", 9},
	{"CLICK_SOURCE_SCOREBOARD", 0},
	{"EDIT_RESPONSE_CANCEL", 0},
	{"EDIT_RESPONSE_FINAL", 1},
	{"EDIT_RESPONSE_UPDATE", 2},
	{"SELECT_OBJECT_GLOBAL_OBJECT", 1},
	{"SELECT_OBJECT_PLAYER_OBJECT", 2},
	{"BULLET_HIT_TYPE_NONE", 0},
	{"BULLET_HIT_TYPE_PLAYER", 1},
	{"BULLET_HIT_TYPE_VEHICLE", 2},
	{"BULLET_HIT_TYPE_OBJECT", 3},
	{"BULLET_HIT_TYPE_PLAYER_OBJECT", 4},
	{"CARMODTYPE_SPOILER", 0},
	{"CARMODTYPE_HOOD", 1},
	{"CARMODTYPE_ROOF", 2},
	{"CARMODTYPE_SIDESKIRT", 3},
	{"CARMODTYPE_LAMPS", 4},
	{"CARMODTYPE_NITRO", 5},
	{"CARMODTYPE_EXHAUST", 6},
	{"CARMODTYPE_WHEELS", 7},
	{"CARMODTYPE_STEREO", 8},
	{"CARMODTYPE_HYDRAULICS", 9},
	{"CARMODTYPE_FRONT_BUMPER", 10},
	{"CARMODTYPE_REAR_BUMPER", 11},
	{"CARMODTYPE_VENT_RIGHT", 12},
	{"CARMODTYPE_VENT_LEFT", 13},
	{"VEHICLE_PARAMS_UNSET", -1},
	{"VEHICLE_PARAMS_OFF", 0},
	{"VEHICLE_PARAMS_ON", 1},
	{"VEHICLE_MODEL_INFO_SIZE", 1},
	{"VEHICLE_MODEL_INFO_FRONTSEAT", 2},
	{"VEHICLE_MODEL_INFO_REARSEAT", 3},
	{"VEHICLE_MODEL_INFO_PETROLCAP", 4},
	{"VEHICLE_MODEL_INFO_WHEELSFRONT", 5},
	{"VEHICLE_MODEL_INFO_WHEELSREAR", 6},
	{"VEHICLE_MODEL_INFO_WHEELSMID", 7},
	{"VEHICLE_MODEL_INFO_FRONT_BUMPER_Z", 8},
	{"VEHICLE_MODEL_INFO_REAR_BUMPER_Z", 9},
	{"OBJECT_MATERIAL_SIZE_32x32", 10},
	{"OBJECT_MATERIAL_SIZE_64x32", 20},
	{"OBJECT_MATERIAL_SIZE_64x64", 30},
	{"OBJECT_MATERIAL_SIZE_128x32", 40},
	{"OBJECT_MATERIAL_SIZE_128x64", 50},
	{"OBJECT_MATERIAL_SIZE_128x128", 60},
	{"OBJECT_MATERIAL_SIZE_256x32", 70},
	{"OBJECT_MATERIAL_SIZE_256x64", 80},
	{"OBJECT_MATERIAL_SIZE_256x128", 90},
	{"OBJECT_MATERIAL_SIZE_256x256", 100},
	{"OBJECT_MATERIAL_SIZE_512x64", 110},
	{"OBJECT_MATERIAL_SIZE_512x128", 120},
	{"OBJECT_MATERIAL_SIZE_512x256", 130},
	{"OBJECT_MATERIAL_SIZE_512x512", 140},
	{"OBJECT_MATERIAL_TEXT_ALIGN_LEFT", 0},
	{"OBJECT_MATERIAL_TEXT_ALIGN_CENTER", 1},
	{"OBJECT_MATERIAL_TEXT_ALIGN_RIGHT", 2},
	{"SPECIAL_ACTION_NONE", 0},
	{"SPECIAL_ACTION_DUCK", 1},
	{"SPECIAL_ACTION_USEJETPACK", 2},
	{"SPECIAL_ACTION_ENTER_VEHICLE", 3},
	{"SPECIAL_ACTION_EXIT_VEHICLE", 4},
	{"SPECIAL_ACTION_DANCE1", 5},
	{"SPECIAL_ACTION_DANCE2", 6},
	{"SPECIAL_ACTION_DANCE3", 7},
	{"SPECIAL_ACTION_DANCE4", 8},
	{"SPECIAL_ACTION_HANDSUP", 10},
	{"SPECIAL_ACTION_USECELLPHONE", 11},
	{"SPECIAL_ACTION_SITTING", 12},
	{"SPECIAL_ACTION_STOPUSECELLPHONE", 13},
	{"SPECIAL_ACTION_DRINK_BEER", 20},
	{"SPECIAL_ACTION_SMOKE_CIGGY", 21},
	{"SPECIAL_ACTION_DRINK_WINE", 22},
	{"SPECIAL_ACTION_DRINK_SPRUNK", 23},
	{"SPECIAL_ACTION_CUFFED", 24},
	{"SPECIAL_ACTION_CARRY", 25},
	{"FIGHT_STYLE_NORMAL", 4},
	{"FIGHT_STYLE_BOXING", 5},
	{"FIGHT_STYLE_KUNGFU", 6},
	{"FIGHT_STYLE_KNEEHEAD", 7},
	{"FIGHT_STYLE_GRABKICK", 15},
	{"FIGHT_STYLE_ELBOW", 16},
	{"WEAPONSKILL_PISTOL", 0},
	{"WEAPONSKILL_PISTOL_SILENCED", 1},
	{"WEAPONSKILL_DESERT_EAGLE", 2},
	{"WEAPONSKILL_SHOTGUN", 3},
	{"WEAPONSKILL_SAWNOFF_SHOTGUN", 4},
	{"WEAPONSKILL_SPAS12_SHOTGUN", 5},
	{"WEAPONSKILL_MICRO_UZI", 6},
	{"WEAPONSKILL_MP5", 7},
	{"WEAPONSKILL_AK47", 8},
	{"WEAPONSKILL_M4", 9},
	{"WEAPONSKILL_SNIPERRIFLE", 10},
	{"WEAPONSTATE_UNKNOWN", -1},
	{"WEAPONSTATE_NO_BULLETS", 0},
	{"WEAPONSTATE_LAST_BULLET", 1},
	{"WEAPONSTATE_MORE_BULLETS", 2},
	{"WEAPONSTATE_RELOADING", 3},
	{"MAX_PLAYER_ATTACHED_OBJECTS", 10},
	{"PLAYER_VARTYPE_NONE", 0},
	{"PLAYER_VARTYPE_INT", 1},
	{"PLAYER_VARTYPE_STRING", 2},
	{"PLAYER_VARTYPE_FLOAT", 3},
	{"MAX_CHATBUBBLE_LENGTH", 144},
	{"MAPICON_LOCAL", 0},
	{"MAPICON_GLOBAL", 1},
	{"MAPICON_LOCAL_CHECKPOINT", 2},
	{"MAPICON_GLOBAL_CHECKPOINT", 3},
	{"CAMERA_CUT", 2},
	{"CAMERA_MOVE", 1},
	{"SPECTATE_MODE_NORMAL", 1},
	{"SPECTATE_MODE_FIXED", 2},
	{"SPECTATE_MODE_SIDE", 3},
	{"PLAYER_RECORDING_TYPE_NONE", 0},
	{"PLAYER_RECORDING_TYPE_DRIVER", 1},
	{"PLAYER_RECORDING_TYPE_ONFOOT", 2}
};
