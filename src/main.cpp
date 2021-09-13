#include "main.h"


extern void *pAMXFunctions;

PLUGIN_EXPORT unsigned int PLUGIN_CALL Supports()
{
	return sampgdk::Supports() | SUPPORTS_PROCESS_TICK;
}

PLUGIN_EXPORT bool PLUGIN_CALL Load(void **ppData) 
{
	pAMXFunctions = ppData[PLUGIN_DATA_AMX_EXPORTS];
	bool ret = sampgdk::Load(ppData);

#ifndef WIN32
	dlopen(PYTHON_LIBRARY, RTLD_GLOBAL);
#endif

	sampgdk::logprintf("\n\n%s", PYSAMP_LOADING_SCREEN_1);
	sampgdk::logprintf("%s", PYSAMP_LOADING_SCREEN_2);
	sampgdk::logprintf("%s", PYSAMP_LOADING_SCREEN_3);
	sampgdk::logprintf("%s\n\n", PYSAMP_LOADING_SCREEN_4);
	sampgdk::logprintf("PySAMP %s for Python %s\n", PYSAMP_VERSION_STR, PYTHON_VERSION_STR);

	return ret;
}

PLUGIN_EXPORT void PLUGIN_CALL Unload()
{
	PySAMP::unload();
	sampgdk::Unload();
}

PLUGIN_EXPORT void PLUGIN_CALL ProcessTick()
{
	if(PySAMP::isLoaded())
		PySAMP::processTick(GetTickCount());

	sampgdk::ProcessTick();
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeInit()
{
	if(!PySAMP::isLoaded())
		PySAMP::load();
	else
		PySAMP::reload();

	return PySAMP::callback("OnGameModeInit");
}

PLUGIN_EXPORT bool PLUGIN_CALL OnGameModeExit()
{
	PySAMP::disable();
	return PySAMP::callback("OnGameModeExit");
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPublicCall2(
	AMX *amx,
	const char *name,
	cell *params,
	cell *retval,
	bool *stop
)
{
	if(!PySAMP::isLoaded())
		return false;

	if(
		strcmp(name, "OnGameModeInit") == 0
		|| strcmp(name, "OnGameModeExit") == 0
		|| strcmp(name, "OnPlayerCommandText") == 0
	)
		return false;

	return PySAMP::callback(
		name,
		PySAMP::amxParamsToTuple(amx, name, params),
		retval,
		stop
	);
}

PLUGIN_EXPORT bool PLUGIN_CALL OnRconCommand(const char * cmd)
{
	if(strcmp(cmd, "pyreload") == 0)
	{
		PySAMP::reload();
		return true;
	}

	return false;
}

PLUGIN_EXPORT bool PLUGIN_CALL OnPlayerCommandText(
	int playerid,
	const char *cmdtext
)
{
	return PySAMP::onPlayerCommandText(playerid, cmdtext);
}
