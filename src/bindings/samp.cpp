#include "samp.h"


extern "C"
{
	PyMODINIT_FUNC PyInit_samp()
	{
		PyObject *logprintf;

		if(PyType_Ready(&LogPrintfType) < 0)
			return NULL;

		logprintf = PyObject_CallObject((PyObject*)&LogPrintfType, NULL);

		if(logprintf == NULL)
			return NULL;

		PySys_SetObject("stdout", logprintf);
		PySys_SetObject("stderr", logprintf);
		Py_DECREF(logprintf);

		return PyModule_Create(&PySAMPModule);
	}
}

WITH_GIL(pysamp_createactor, PyObject *self, PyObject *args)
{
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffff:CreateActor", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	int ret = CreateActor(arg0, arg1, arg2, arg3, arg4);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_destroyactor, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:DestroyActor", &arg0))
		return NULL;

	bool ret = DestroyActor(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isactorstreamedin, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:IsActorStreamedIn", &arg0, &arg1))
		return NULL;

	bool ret = IsActorStreamedIn(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setactorvirtualworld, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetActorVirtualWorld", &arg0, &arg1))
		return NULL;

	bool ret = SetActorVirtualWorld(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getactorvirtualworld, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetActorVirtualWorld", &arg0))
		return NULL;

	int ret = GetActorVirtualWorld(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_applyactoranimation, PyObject *self, PyObject *args)
{
	int arg8 = -1;
	int arg7 = 0;
	int arg6 = 0;
	int arg5 = 0;
	int arg4 = 0;
	float arg3 = -1.0f;
	const char* arg2;
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iesesfppppi:ApplyActorAnimation", &arg0, PySAMP::getEncoding().c_str(), &arg1, PySAMP::getEncoding().c_str(), &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8))
		return NULL;

	bool ret = ApplyActorAnimation(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);

	PyMem_Free((void *)arg2);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_clearactoranimations, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:ClearActorAnimations", &arg0))
		return NULL;

	bool ret = ClearActorAnimations(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setactorpos, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff:SetActorPos", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = SetActorPos(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getactorpos, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetActorPos", &arg0))
		return NULL;

	bool ret = GetActorPos(arg0, &arg1, &arg2, &arg3);
	PyObject* out = Py_BuildValue("fff", arg1, arg2, arg3);
	return out;
}

WITH_GIL(pysamp_setactorfacingangle, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "if:SetActorFacingAngle", &arg0, &arg1))
		return NULL;

	bool ret = SetActorFacingAngle(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getactorfacingangle, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetActorFacingAngle", &arg0))
		return NULL;

	bool ret = GetActorFacingAngle(arg0, &arg1);
	PyObject* out = Py_BuildValue("f", arg1);
	return out;
}

WITH_GIL(pysamp_setactorhealth, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "if:SetActorHealth", &arg0, &arg1))
		return NULL;

	bool ret = SetActorHealth(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getactorhealth, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetActorHealth", &arg0))
		return NULL;

	bool ret = GetActorHealth(arg0, &arg1);
	PyObject* out = Py_BuildValue("f", arg1);
	return out;
}

WITH_GIL(pysamp_setactorinvulnerable, PyObject *self, PyObject *args)
{
	int arg1 = true;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i|p:SetActorInvulnerable", &arg0, &arg1))
		return NULL;

	bool ret = SetActorInvulnerable(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isactorinvulnerable, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsActorInvulnerable", &arg0))
		return NULL;

	bool ret = IsActorInvulnerable(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isvalidactor, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsValidActor", &arg0))
		return NULL;

	bool ret = IsValidActor(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_createobject, PyObject *self, PyObject *args)
{
	float arg7 = 0.0;
	float arg6 = -1.0f;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffffff|f:CreateObject", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7))
		return NULL;

	int ret = CreateObject(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_attachobjecttovehicle, PyObject *self, PyObject *args)
{
	float arg7 = -1.0f;
	float arg6 = -1.0f;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiffffff:AttachObjectToVehicle", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7))
		return NULL;

	bool ret = AttachObjectToVehicle(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_attachobjecttoobject, PyObject *self, PyObject *args)
{
	int arg8 = false;
	float arg7 = -1.0f;
	float arg6 = -1.0f;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiffffff|p:AttachObjectToObject", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8))
		return NULL;

	bool ret = AttachObjectToObject(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_attachobjecttoplayer, PyObject *self, PyObject *args)
{
	float arg7 = -1.0f;
	float arg6 = -1.0f;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiffffff:AttachObjectToPlayer", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7))
		return NULL;

	bool ret = AttachObjectToPlayer(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setobjectpos, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff:SetObjectPos", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = SetObjectPos(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getobjectpos, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetObjectPos", &arg0))
		return NULL;

	bool ret = GetObjectPos(arg0, &arg1, &arg2, &arg3);
	PyObject* out = Py_BuildValue("fff", arg1, arg2, arg3);
	return out;
}

WITH_GIL(pysamp_setobjectrot, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff:SetObjectRot", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = SetObjectRot(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getobjectrot, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetObjectRot", &arg0))
		return NULL;

	bool ret = GetObjectRot(arg0, &arg1, &arg2, &arg3);
	PyObject* out = Py_BuildValue("fff", arg1, arg2, arg3);
	return out;
}

WITH_GIL(pysamp_getobjectmodel, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetObjectModel", &arg0))
		return NULL;

	int ret = GetObjectModel(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setobjectnocameracol, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:SetObjectNoCameraCol", &arg0))
		return NULL;

	bool ret = SetObjectNoCameraCol(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isvalidobject, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsValidObject", &arg0))
		return NULL;

	bool ret = IsValidObject(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_destroyobject, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:DestroyObject", &arg0))
		return NULL;

	bool ret = DestroyObject(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_moveobject, PyObject *self, PyObject *args)
{
	float arg7 = -1000.0;
	float arg6 = -1000.0;
	float arg5 = -1000.0;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffff|fff:MoveObject", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7))
		return NULL;

	int ret = MoveObject(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_stopobject, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:StopObject", &arg0))
		return NULL;

	bool ret = StopObject(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isobjectmoving, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsObjectMoving", &arg0))
		return NULL;

	bool ret = IsObjectMoving(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_editobject, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:EditObject", &arg0, &arg1))
		return NULL;

	bool ret = EditObject(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_editplayerobject, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:EditPlayerObject", &arg0, &arg1))
		return NULL;

	bool ret = EditPlayerObject(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_selectobject, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:SelectObject", &arg0))
		return NULL;

	bool ret = SelectObject(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_canceledit, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:CancelEdit", &arg0))
		return NULL;

	bool ret = CancelEdit(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_createplayerobject, PyObject *self, PyObject *args)
{
	float arg8 = 0.0;
	float arg7 = -1.0f;
	float arg6 = -1.0f;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiffffff|f:CreatePlayerObject", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8))
		return NULL;

	int ret = CreatePlayerObject(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_attachplayerobjecttoplayer, PyObject *self, PyObject *args)
{
	float arg8 = -1.0f;
	float arg7 = -1.0f;
	float arg6 = -1.0f;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiiffffff:AttachPlayerObjectToPlayer", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8))
		return NULL;

	bool ret = AttachPlayerObjectToPlayer(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_attachplayerobjecttovehicle, PyObject *self, PyObject *args)
{
	float arg8 = -1.0f;
	float arg7 = -1.0f;
	float arg6 = -1.0f;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiiffffff:AttachPlayerObjectToVehicle", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8))
		return NULL;

	bool ret = AttachPlayerObjectToVehicle(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayerobjectpos, PyObject *self, PyObject *args)
{
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iifff:SetPlayerObjectPos", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = SetPlayerObjectPos(arg0, arg1, arg2, arg3, arg4);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerobjectpos, PyObject *self, PyObject *args)
{
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:GetPlayerObjectPos", &arg0, &arg1))
		return NULL;

	bool ret = GetPlayerObjectPos(arg0, arg1, &arg2, &arg3, &arg4);
	PyObject* out = Py_BuildValue("fff", arg2, arg3, arg4);
	return out;
}

WITH_GIL(pysamp_setplayerobjectrot, PyObject *self, PyObject *args)
{
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iifff:SetPlayerObjectRot", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = SetPlayerObjectRot(arg0, arg1, arg2, arg3, arg4);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerobjectrot, PyObject *self, PyObject *args)
{
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:GetPlayerObjectRot", &arg0, &arg1))
		return NULL;

	bool ret = GetPlayerObjectRot(arg0, arg1, &arg2, &arg3, &arg4);
	PyObject* out = Py_BuildValue("fff", arg2, arg3, arg4);
	return out;
}

WITH_GIL(pysamp_getplayerobjectmodel, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:GetPlayerObjectModel", &arg0, &arg1))
		return NULL;

	int ret = GetPlayerObjectModel(arg0, arg1);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setplayerobjectnocameracol, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetPlayerObjectNoCameraCol", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerObjectNoCameraCol(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isvalidplayerobject, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:IsValidPlayerObject", &arg0, &arg1))
		return NULL;

	bool ret = IsValidPlayerObject(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_destroyplayerobject, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:DestroyPlayerObject", &arg0, &arg1))
		return NULL;

	bool ret = DestroyPlayerObject(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_moveplayerobject, PyObject *self, PyObject *args)
{
	float arg8 = -1000.0;
	float arg7 = -1000.0;
	float arg6 = -1000.0;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiffff|fff:MovePlayerObject", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8))
		return NULL;

	int ret = MovePlayerObject(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_stopplayerobject, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:StopPlayerObject", &arg0, &arg1))
		return NULL;

	bool ret = StopPlayerObject(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isplayerobjectmoving, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:IsPlayerObjectMoving", &arg0, &arg1))
		return NULL;

	bool ret = IsPlayerObjectMoving(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setobjectmaterial, PyObject *self, PyObject *args)
{
	int arg5 = 0;
	const char* arg4;
	const char* arg3;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiieses|i:SetObjectMaterial", &arg0, &arg1, &arg2, PySAMP::getEncoding().c_str(), &arg3, PySAMP::getEncoding().c_str(), &arg4, &arg5))
		return NULL;

	bool ret = SetObjectMaterial(arg0, arg1, arg2, arg3, arg4, arg5);

	PyMem_Free((void *)arg4);
	PyMem_Free((void *)arg3);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayerobjectmaterial, PyObject *self, PyObject *args)
{
	int arg6 = 0;
	const char* arg5;
	const char* arg4;
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiiieses|i:SetPlayerObjectMaterial", &arg0, &arg1, &arg2, &arg3, PySAMP::getEncoding().c_str(), &arg4, PySAMP::getEncoding().c_str(), &arg5, &arg6))
		return NULL;

	bool ret = SetPlayerObjectMaterial(arg0, arg1, arg2, arg3, arg4, arg5, arg6);

	PyMem_Free((void *)arg5);
	PyMem_Free((void *)arg4);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setobjectmaterialtext, PyObject *self, PyObject *args)
{
	int arg9 = 0;
	int arg8 = 0;
	int arg7 = 0xFFFFFFFF;
	int arg6 = true;
	int arg5 = 24;
	const char* arg4 = NULL;
	int arg3 = OBJECT_MATERIAL_SIZE_256x128;
	int arg2 = 0;
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies|iiesipiii:SetObjectMaterialText", &arg0, PySAMP::getEncoding().c_str(), &arg1, &arg2, &arg3, PySAMP::getEncoding().c_str(), &arg4, &arg5, &arg6, &arg7, &arg8, &arg9))
		return NULL;

	bool ret = SetObjectMaterialText(arg0, arg1, arg2, arg3, arg4 != NULL ? arg4 : "Arial", arg5, arg6, arg7, arg8, arg9);

	PyMem_Free((void *)arg4);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayerobjectmaterialtext, PyObject *self, PyObject *args)
{
	int arg10 = 0;
	int arg9 = 0;
	int arg8 = 0xFFFFFFFF;
	int arg7 = true;
	int arg6 = 24;
	const char* arg5 = NULL;
	int arg4 = OBJECT_MATERIAL_SIZE_256x128;
	int arg3 = 0;
	const char* arg2;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iies|iiesipiii:SetPlayerObjectMaterialText", &arg0, &arg1, PySAMP::getEncoding().c_str(), &arg2, &arg3, &arg4, PySAMP::getEncoding().c_str(), &arg5, &arg6, &arg7, &arg8, &arg9, &arg10))
		return NULL;

	bool ret = SetPlayerObjectMaterialText(arg0, arg1, arg2, arg3, arg4, arg5 != NULL ? arg5 : "Arial", arg6, arg7, arg8, arg9, arg10);

	PyMem_Free((void *)arg5);
	PyMem_Free((void *)arg2);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setobjectsdefaultcameracol, PyObject *self, PyObject *args)
{
	int arg0 = false;
	if (!PyArg_ParseTuple(args, "p:SetObjectsDefaultCameraCol", &arg0))
		return NULL;

	bool ret = SetObjectsDefaultCameraCol(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setspawninfo, PyObject *self, PyObject *args)
{
	int arg12 = -1;
	int arg11 = -1;
	int arg10 = -1;
	int arg9 = -1;
	int arg8 = -1;
	int arg7 = -1;
	float arg6 = -1.0f;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiiffffiiiiii:SetSpawnInfo", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9, &arg10, &arg11, &arg12))
		return NULL;

	bool ret = SetSpawnInfo(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_spawnplayer, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:SpawnPlayer", &arg0))
		return NULL;

	bool ret = SpawnPlayer(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayerpos, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff:SetPlayerPos", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = SetPlayerPos(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayerposfindz, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff:SetPlayerPosFindZ", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = SetPlayerPosFindZ(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerpos, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerPos", &arg0))
		return NULL;

	bool ret = GetPlayerPos(arg0, &arg1, &arg2, &arg3);
	PyObject* out = Py_BuildValue("fff", arg1, arg2, arg3);
	return out;
}

WITH_GIL(pysamp_setplayerfacingangle, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "if:SetPlayerFacingAngle", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerFacingAngle(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerfacingangle, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerFacingAngle", &arg0))
		return NULL;

	bool ret = GetPlayerFacingAngle(arg0, &arg1);
	PyObject* out = Py_BuildValue("f", arg1);
	return out;
}

WITH_GIL(pysamp_isplayerinrangeofpoint, PyObject *self, PyObject *args)
{
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffff:IsPlayerInRangeOfPoint", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = IsPlayerInRangeOfPoint(arg0, arg1, arg2, arg3, arg4);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerdistancefrompoint, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff:GetPlayerDistanceFromPoint", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	float ret = GetPlayerDistanceFromPoint(arg0, arg1, arg2, arg3);
	PyObject* out = Py_BuildValue("f", ret);
	return out;
}

WITH_GIL(pysamp_isplayerstreamedin, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:IsPlayerStreamedIn", &arg0, &arg1))
		return NULL;

	bool ret = IsPlayerStreamedIn(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayerinterior, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetPlayerInterior", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerInterior(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerinterior, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerInterior", &arg0))
		return NULL;

	int ret = GetPlayerInterior(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setplayerhealth, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "if:SetPlayerHealth", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerHealth(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerhealth, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerHealth", &arg0))
		return NULL;

	bool ret = GetPlayerHealth(arg0, &arg1);
	PyObject* out = Py_BuildValue("f", arg1);
	return out;
}

WITH_GIL(pysamp_setplayerarmour, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "if:SetPlayerArmour", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerArmour(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerarmour, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerArmour", &arg0))
		return NULL;

	bool ret = GetPlayerArmour(arg0, &arg1);
	PyObject* out = Py_BuildValue("f", arg1);
	return out;
}

WITH_GIL(pysamp_setplayerammo, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:SetPlayerAmmo", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = SetPlayerAmmo(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerammo, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerAmmo", &arg0))
		return NULL;

	int ret = GetPlayerAmmo(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayerweaponstate, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerWeaponState", &arg0))
		return NULL;

	int ret = GetPlayerWeaponState(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayertargetplayer, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerTargetPlayer", &arg0))
		return NULL;

	int ret = GetPlayerTargetPlayer(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayertargetactor, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerTargetActor", &arg0))
		return NULL;

	int ret = GetPlayerTargetActor(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setplayerteam, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetPlayerTeam", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerTeam(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerteam, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerTeam", &arg0))
		return NULL;

	int ret = GetPlayerTeam(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setplayerscore, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetPlayerScore", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerScore(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerscore, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerScore", &arg0))
		return NULL;

	int ret = GetPlayerScore(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayerdrunklevel, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerDrunkLevel", &arg0))
		return NULL;

	int ret = GetPlayerDrunkLevel(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setplayerdrunklevel, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetPlayerDrunkLevel", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerDrunkLevel(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayercolor, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	unsigned long arg0 = -1;
	if (!PyArg_ParseTuple(args, "ik:SetPlayerColor", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerColor(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayercolor, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerColor", &arg0))
		return NULL;

	int ret = GetPlayerColor(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setplayerskin, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetPlayerSkin", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerSkin(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerskin, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerSkin", &arg0))
		return NULL;

	int ret = GetPlayerSkin(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_giveplayerweapon, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:GivePlayerWeapon", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = GivePlayerWeapon(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_resetplayerweapons, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:ResetPlayerWeapons", &arg0))
		return NULL;

	bool ret = ResetPlayerWeapons(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayerarmedweapon, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetPlayerArmedWeapon", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerArmedWeapon(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerweapondata, PyObject *self, PyObject *args)
{
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:GetPlayerWeaponData", &arg0, &arg1))
		return NULL;

	bool ret = GetPlayerWeaponData(arg0, arg1, &arg2, &arg3);
	PyObject* out = Py_BuildValue("ii", arg2, arg3);
	return out;
}

WITH_GIL(pysamp_giveplayermoney, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:GivePlayerMoney", &arg0, &arg1))
		return NULL;

	bool ret = GivePlayerMoney(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_resetplayermoney, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:ResetPlayerMoney", &arg0))
		return NULL;

	bool ret = ResetPlayerMoney(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayername, PyObject *self, PyObject *args)
{
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies:SetPlayerName", &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	int ret = SetPlayerName(arg0, arg1);
	PyMem_Free((void *)arg1);

	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayermoney, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerMoney", &arg0))
		return NULL;

	int ret = GetPlayerMoney(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayerstate, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerState", &arg0))
		return NULL;

	int ret = GetPlayerState(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayerip, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerIp", &arg0))
		return NULL;

	// Max IP size is 16 including final '\0'
	char arg1[16];
	bool ret = GetPlayerIp(arg0, arg1, 16);
	PyObject* out = Py_BuildValue("s", arg1);
	return out;
}

WITH_GIL(pysamp_getplayerping, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerPing", &arg0))
		return NULL;

	int ret = GetPlayerPing(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayerweapon, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerWeapon", &arg0))
		return NULL;

	int ret = GetPlayerWeapon(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayerkeys, PyObject *self, PyObject *args)
{
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerKeys", &arg0))
		return NULL;

	bool ret = GetPlayerKeys(arg0, &arg1, &arg2, &arg3);
	PyObject* out = Py_BuildValue("iii", arg1, arg2, arg3);
	return out;
}

WITH_GIL(pysamp_getplayername, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerName", &arg0))
		return NULL;

	char arg1[MAX_PLAYER_NAME + 1];
	int ret = GetPlayerName(arg0, arg1, MAX_PLAYER_NAME);
	PyObject* out = Py_BuildValue("s", arg1);
	return out;
}

WITH_GIL(pysamp_setplayertime, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:SetPlayerTime", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = SetPlayerTime(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayertime, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerTime", &arg0))
		return NULL;

	bool ret = GetPlayerTime(arg0, &arg1, &arg2);
	PyObject* out = Py_BuildValue("ii", arg1, arg2);
	return out;
}

WITH_GIL(pysamp_toggleplayerclock, PyObject *self, PyObject *args)
{
	int arg1 = false;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ip:TogglePlayerClock", &arg0, &arg1))
		return NULL;

	bool ret = TogglePlayerClock(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayerweather, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetPlayerWeather", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerWeather(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_forceclassselection, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:ForceClassSelection", &arg0))
		return NULL;

	bool ret = ForceClassSelection(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayerwantedlevel, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetPlayerWantedLevel", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerWantedLevel(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerwantedlevel, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerWantedLevel", &arg0))
		return NULL;

	int ret = GetPlayerWantedLevel(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setplayerfightingstyle, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetPlayerFightingStyle", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerFightingStyle(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerfightingstyle, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerFightingStyle", &arg0))
		return NULL;

	int ret = GetPlayerFightingStyle(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setplayervelocity, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff:SetPlayerVelocity", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = SetPlayerVelocity(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayervelocity, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerVelocity", &arg0))
		return NULL;

	bool ret = GetPlayerVelocity(arg0, &arg1, &arg2, &arg3);
	PyObject* out = Py_BuildValue("fff", arg1, arg2, arg3);
	return out;
}

WITH_GIL(pysamp_playcrimereportforplayer, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:PlayCrimeReportForPlayer", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayCrimeReportForPlayer(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playaudiostreamforplayer, PyObject *self, PyObject *args)
{
	int arg6 = false;
	float arg5 = 50.0;
	float arg4 = 0.0;
	float arg3 = 0.0;
	float arg2 = 0.0;
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies|ffffp:PlayAudioStreamForPlayer", &arg0, PySAMP::getEncoding().c_str(), &arg1, &arg2, &arg3, &arg4, &arg5, &arg6))
		return NULL;

	bool ret = PlayAudioStreamForPlayer(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_stopaudiostreamforplayer, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:StopAudioStreamForPlayer", &arg0))
		return NULL;

	bool ret = StopAudioStreamForPlayer(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayershopname, PyObject *self, PyObject *args)
{
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies:SetPlayerShopName", &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	bool ret = SetPlayerShopName(arg0, arg1);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayerskilllevel, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:SetPlayerSkillLevel", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = SetPlayerSkillLevel(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayersurfingvehicleid, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerSurfingVehicleID", &arg0))
		return NULL;

	int ret = GetPlayerSurfingVehicleID(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayersurfingobjectid, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerSurfingObjectID", &arg0))
		return NULL;

	int ret = GetPlayerSurfingObjectID(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_removebuildingforplayer, PyObject *self, PyObject *args)
{
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiffff:RemoveBuildingForPlayer", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5))
		return NULL;

	bool ret = RemoveBuildingForPlayer(arg0, arg1, arg2, arg3, arg4, arg5);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayerlastshotvectors, PyObject *self, PyObject *args)
{
	float arg6 = -1.0f;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerLastShotVectors", &arg0))
		return NULL;

	bool ret = GetPlayerLastShotVectors(arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6);
	PyObject* out = Py_BuildValue("ffffff", arg1, arg2, arg3, arg4, arg5, arg6);
	return out;
}

WITH_GIL(pysamp_setplayerattachedobject, PyObject *self, PyObject *args)
{
	int arg14 = -1;
	int arg13 = -1;
	float arg12 = 1.0;
	float arg11 = 1.0;
	float arg10 = 1.0;
	float arg9 = 0.0;
	float arg8 = 0.0;
	float arg7 = 0.0;
	float arg6 = 0.0;
	float arg5 = 0.0;
	float arg4 = 0.0;
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiii|fffffffffii:SetPlayerAttachedObject", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9, &arg10, &arg11, &arg12, &arg13, &arg14))
		return NULL;

	bool ret = SetPlayerAttachedObject(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11, arg12, arg13, arg14);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_removeplayerattachedobject, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:RemovePlayerAttachedObject", &arg0, &arg1))
		return NULL;

	bool ret = RemovePlayerAttachedObject(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isplayerattachedobjectslotused, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:IsPlayerAttachedObjectSlotUsed", &arg0, &arg1))
		return NULL;

	bool ret = IsPlayerAttachedObjectSlotUsed(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_editattachedobject, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:EditAttachedObject", &arg0, &arg1))
		return NULL;

	bool ret = EditAttachedObject(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_createplayertextdraw, PyObject *self, PyObject *args)
{
	const char* arg3;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffes:CreatePlayerTextDraw", &arg0, &arg1, &arg2, PySAMP::getEncoding().c_str(), &arg3))
		return NULL;

	int ret = CreatePlayerTextDraw(arg0, arg1, arg2, arg3);
	PyMem_Free((void *)arg3);
	PyObject* out = Py_BuildValue("i", ret);

	return out;
}

WITH_GIL(pysamp_playertextdrawdestroy, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:PlayerTextDrawDestroy", &arg0, &arg1))
		return NULL;

	bool ret = PlayerTextDrawDestroy(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawlettersize, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiff:PlayerTextDrawLetterSize", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = PlayerTextDrawLetterSize(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawtextsize, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiff:PlayerTextDrawTextSize", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = PlayerTextDrawTextSize(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawalignment, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:PlayerTextDrawAlignment", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerTextDrawAlignment(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawcolor, PyObject *self, PyObject *args)
{
	unsigned long arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iik:PlayerTextDrawColor", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerTextDrawColor(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawusebox, PyObject *self, PyObject *args)
{
	int arg2 = false;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iip:PlayerTextDrawUseBox", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerTextDrawUseBox(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawboxcolor, PyObject *self, PyObject *args)
{
	unsigned long arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iik:PlayerTextDrawBoxColor", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerTextDrawBoxColor(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawsetshadow, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:PlayerTextDrawSetShadow", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerTextDrawSetShadow(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawsetoutline, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:PlayerTextDrawSetOutline", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerTextDrawSetOutline(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawbackgroundcolor, PyObject *self, PyObject *args)
{
	unsigned long arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iik:PlayerTextDrawBackgroundColor", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerTextDrawBackgroundColor(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawfont, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:PlayerTextDrawFont", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerTextDrawFont(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawsetproportional, PyObject *self, PyObject *args)
{
	int arg2 = false;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iip:PlayerTextDrawSetProportional", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerTextDrawSetProportional(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawsetselectable, PyObject *self, PyObject *args)
{
	int arg2 = false;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iip:PlayerTextDrawSetSelectable", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerTextDrawSetSelectable(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawshow, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:PlayerTextDrawShow", &arg0, &arg1))
		return NULL;

	bool ret = PlayerTextDrawShow(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawhide, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:PlayerTextDrawHide", &arg0, &arg1))
		return NULL;

	bool ret = PlayerTextDrawHide(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawsetstring, PyObject *self, PyObject *args)
{
	const char* arg2;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iies:PlayerTextDrawSetString", &arg0, &arg1, PySAMP::getEncoding().c_str(), &arg2))
		return NULL;

	bool ret = PlayerTextDrawSetString(arg0, arg1, arg2);
	PyMem_Free((void *)arg2);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawsetpreviewmodel, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:PlayerTextDrawSetPreviewModel", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerTextDrawSetPreviewModel(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawsetpreviewrot, PyObject *self, PyObject *args)
{
	float arg5 = 1.0;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iifff|f:PlayerTextDrawSetPreviewRot", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5))
		return NULL;

	bool ret = PlayerTextDrawSetPreviewRot(arg0, arg1, arg2, arg3, arg4, arg5);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playertextdrawsetpreviewvehcol, PyObject *self, PyObject *args)
{
	unsigned long arg3 = -1;
	unsigned long arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iikk:PlayerTextDrawSetPreviewVehCol", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = PlayerTextDrawSetPreviewVehCol(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setpvarint, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iesi:SetPVarInt", &arg0, PySAMP::getEncoding().c_str(), &arg1, &arg2))
		return NULL;

	bool ret = SetPVarInt(arg0, arg1, arg2);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getpvarint, PyObject *self, PyObject *args)
{
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies:GetPVarInt", &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	int ret = GetPVarInt(arg0, arg1);
	PyMem_Free((void *)arg1);
	PyObject* out = Py_BuildValue("i", ret);

	return out;
}

WITH_GIL(pysamp_setpvarstring, PyObject *self, PyObject *args)
{
	const char* arg2;
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ieses:SetPVarString", &arg0, PySAMP::getEncoding().c_str(), &arg1, PySAMP::getEncoding().c_str(), &arg2))
		return NULL;

	bool ret = SetPVarString(arg0, arg1, arg2);
	PyMem_Free((void *)arg2);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getpvarstring, PyObject *self, PyObject *args)
{
	int arg3 = PySAMP::getConstant("MAX_CLIENT_MESSAGE");
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies|i:GetPVarString", &arg0, PySAMP::getEncoding().c_str(), &arg1, &arg3))
		return NULL;

	if(arg3 < 0)
	{
		PyErr_SetString(PyExc_TypeError, "Expected a positive length as third argument.");
		PyErr_Print();
		return NULL;
	}
	char* arg2 = new char[arg3 + 1];
	int ret = GetPVarString(arg0, arg1, arg2, arg3);
	PyMem_Free((void *)arg1);
	PyObject* out = (ret > 0) ? Py_BuildValue("s", arg2) : Py_None;
	delete[] arg2;
	return out;
}

WITH_GIL(pysamp_setpvarfloat, PyObject *self, PyObject *args)
{
	float arg2 = -1.0f;
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iesf:SetPVarFloat", &arg0, PySAMP::getEncoding().c_str(), &arg1, &arg2))
		return NULL;

	bool ret = SetPVarFloat(arg0, arg1, arg2);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getpvarfloat, PyObject *self, PyObject *args)
{
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies:GetPVarFloat", &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	float ret = GetPVarFloat(arg0, arg1);
	PyMem_Free((void *)arg1);
	PyObject* out = Py_BuildValue("f", ret);

	return out;
}

WITH_GIL(pysamp_deletepvar, PyObject *self, PyObject *args)
{
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies:DeletePVar", &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	bool ret = DeletePVar(arg0, arg1);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getpvarsupperindex, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPVarsUpperIndex", &arg0))
		return NULL;

	int ret = GetPVarsUpperIndex(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getpvarnameatindex, PyObject *self, PyObject *args)
{
	int arg3 = PySAMP::getConstant("MAX_CLIENT_MESSAGE");
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii|i:GetPVarNameAtIndex", &arg0, &arg1, &arg3))
		return NULL;

	if(arg3 < 0)
	{
		PyErr_SetString(PyExc_TypeError, "Expected a positive length as third argument.");
		PyErr_Print();
		return NULL;
	}
	char* arg2 = new char[arg3 + 1];
	bool ret = GetPVarNameAtIndex(arg0, arg1, arg2, arg3);
	PyObject* out = Py_BuildValue("s", arg2);
	delete[] arg2;
	return out;
}

WITH_GIL(pysamp_getpvartype, PyObject *self, PyObject *args)
{
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies:GetPVarType", &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	int ret = GetPVarType(arg0, arg1);
	PyMem_Free((void *)arg1);
	PyObject* out = Py_BuildValue("i", ret);

	return out;
}

WITH_GIL(pysamp_setplayerchatbubble, PyObject *self, PyObject *args)
{
	int arg4 = -1;
	float arg3 = -1.0f;
	unsigned long arg2 = -1;
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ieskfi:SetPlayerChatBubble", &arg0, PySAMP::getEncoding().c_str(), &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = SetPlayerChatBubble(arg0, arg1, arg2, arg3, arg4);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_putplayerinvehicle, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:PutPlayerInVehicle", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PutPlayerInVehicle(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayervehicleid, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerVehicleID", &arg0))
		return NULL;

	int ret = GetPlayerVehicleID(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayervehicleseat, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerVehicleSeat", &arg0))
		return NULL;

	int ret = GetPlayerVehicleSeat(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_removeplayerfromvehicle, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:RemovePlayerFromVehicle", &arg0))
		return NULL;

	bool ret = RemovePlayerFromVehicle(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_toggleplayercontrollable, PyObject *self, PyObject *args)
{
	int arg1 = false;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ip:TogglePlayerControllable", &arg0, &arg1))
		return NULL;

	bool ret = TogglePlayerControllable(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playerplaysound, PyObject *self, PyObject *args)
{
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iifff:PlayerPlaySound", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = PlayerPlaySound(arg0, arg1, arg2, arg3, arg4);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_applyanimation, PyObject *self, PyObject *args)
{
	int arg9 = false;
	int arg8 = -1;
	int arg7 = false;
	int arg6 = false;
	int arg5 = false;
	int arg4 = false;
	float arg3 = -1.0f;
	const char* arg2;
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iesesfppppi|p:ApplyAnimation", &arg0, PySAMP::getEncoding().c_str(), &arg1, PySAMP::getEncoding().c_str(), &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9))
		return NULL;

	bool ret = ApplyAnimation(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9);
	PyMem_Free((void *)arg2);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_clearanimations, PyObject *self, PyObject *args)
{
	int arg1 = false;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i|p:ClearAnimations", &arg0, &arg1))
		return NULL;

	bool ret = ClearAnimations(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayeranimationindex, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerAnimationIndex", &arg0))
		return NULL;

	int ret = GetPlayerAnimationIndex(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getanimationname, PyObject *self, PyObject *args)
{
	int arg4 = PySAMP::getConstant("MAX_CLIENT_MESSAGE");
	int arg2 = PySAMP::getConstant("MAX_CLIENT_MESSAGE");
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i|ii:GetAnimationName", &arg0, &arg2, &arg4))
		return NULL;

	if(
		arg2 < 0
		|| arg4 < 0
	)
	{
		PyErr_SetString(PyExc_TypeError, "Expected positive lengths as second and third arguments.");
		PyErr_Print();
		return NULL;
	}
	char* arg3 = new char[arg4 + 1];
	char* arg1 = new char[arg2 + 1];
	bool ret = GetAnimationName(arg0, arg1, arg2, arg3, arg4);
	PyObject* out = Py_BuildValue("ss", arg1, arg3);
	delete[] arg3;
	delete[] arg1;
	return out;
}

WITH_GIL(pysamp_getplayerspecialaction, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerSpecialAction", &arg0))
		return NULL;

	int ret = GetPlayerSpecialAction(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setplayerspecialaction, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetPlayerSpecialAction", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerSpecialAction(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_disableremotevehiclecollisions, PyObject *self, PyObject *args)
{
	int arg1 = false;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ip:DisableRemoteVehicleCollisions", &arg0, &arg1))
		return NULL;

	bool ret = DisableRemoteVehicleCollisions(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayercheckpoint, PyObject *self, PyObject *args)
{
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffff:SetPlayerCheckpoint", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = SetPlayerCheckpoint(arg0, arg1, arg2, arg3, arg4);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_disableplayercheckpoint, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:DisablePlayerCheckpoint", &arg0))
		return NULL;

	bool ret = DisablePlayerCheckpoint(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayerracecheckpoint, PyObject *self, PyObject *args)
{
	float arg8 = -1.0f;
	float arg7 = -1.0f;
	float arg6 = -1.0f;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iifffffff:SetPlayerRaceCheckpoint", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8))
		return NULL;

	bool ret = SetPlayerRaceCheckpoint(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_disableplayerracecheckpoint, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:DisablePlayerRaceCheckpoint", &arg0))
		return NULL;

	bool ret = DisablePlayerRaceCheckpoint(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayerworldbounds, PyObject *self, PyObject *args)
{
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffff:SetPlayerWorldBounds", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = SetPlayerWorldBounds(arg0, arg1, arg2, arg3, arg4);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayermarkerforplayer, PyObject *self, PyObject *args)
{
	unsigned long arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iik:SetPlayerMarkerForPlayer", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = SetPlayerMarkerForPlayer(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_showplayernametagforplayer, PyObject *self, PyObject *args)
{
	int arg2 = false;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iip:ShowPlayerNameTagForPlayer", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = ShowPlayerNameTagForPlayer(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayermapicon, PyObject *self, PyObject *args)
{
	int arg7 = MAPICON_LOCAL;
	unsigned long arg6 = -1;
	int arg5 = -1;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iifffik|i:SetPlayerMapIcon", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7))
		return NULL;

	bool ret = SetPlayerMapIcon(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_removeplayermapicon, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:RemovePlayerMapIcon", &arg0, &arg1))
		return NULL;

	bool ret = RemovePlayerMapIcon(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_allowplayerteleport, PyObject *self, PyObject *args)
{
	int arg1 = false;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ip:AllowPlayerTeleport", &arg0, &arg1))
		return NULL;

	bool ret = AllowPlayerTeleport(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayercamerapos, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff:SetPlayerCameraPos", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = SetPlayerCameraPos(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayercameralookat, PyObject *self, PyObject *args)
{
	int arg4 = CAMERA_CUT;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff|i:SetPlayerCameraLookAt", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = SetPlayerCameraLookAt(arg0, arg1, arg2, arg3, arg4);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setcamerabehindplayer, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:SetCameraBehindPlayer", &arg0))
		return NULL;

	bool ret = SetCameraBehindPlayer(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayercamerapos, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerCameraPos", &arg0))
		return NULL;

	bool ret = GetPlayerCameraPos(arg0, &arg1, &arg2, &arg3);
	PyObject* out = Py_BuildValue("fff", arg1, arg2, arg3);
	return out;
}

WITH_GIL(pysamp_getplayercamerafrontvector, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerCameraFrontVector", &arg0))
		return NULL;

	bool ret = GetPlayerCameraFrontVector(arg0, &arg1, &arg2, &arg3);
	PyObject* out = Py_BuildValue("fff", arg1, arg2, arg3);
	return out;
}

WITH_GIL(pysamp_getplayercameramode, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerCameraMode", &arg0))
		return NULL;

	int ret = GetPlayerCameraMode(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_enableplayercameratarget, PyObject *self, PyObject *args)
{
	int arg1 = false;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ip:EnablePlayerCameraTarget", &arg0, &arg1))
		return NULL;

	bool ret = EnablePlayerCameraTarget(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayercameratargetobject, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerCameraTargetObject", &arg0))
		return NULL;

	int ret = GetPlayerCameraTargetObject(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayercameratargetvehicle, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerCameraTargetVehicle", &arg0))
		return NULL;

	int ret = GetPlayerCameraTargetVehicle(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayercameratargetplayer, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerCameraTargetPlayer", &arg0))
		return NULL;

	int ret = GetPlayerCameraTargetPlayer(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayercameratargetactor, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerCameraTargetActor", &arg0))
		return NULL;

	int ret = GetPlayerCameraTargetActor(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getplayercameraaspectratio, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerCameraAspectRatio", &arg0))
		return NULL;

	float ret = GetPlayerCameraAspectRatio(arg0);
	PyObject* out = Py_BuildValue("f", ret);
	return out;
}

WITH_GIL(pysamp_getplayercamerazoom, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerCameraZoom", &arg0))
		return NULL;

	float ret = GetPlayerCameraZoom(arg0);
	PyObject* out = Py_BuildValue("f", ret);
	return out;
}

WITH_GIL(pysamp_attachcameratoobject, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:AttachCameraToObject", &arg0, &arg1))
		return NULL;

	bool ret = AttachCameraToObject(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_attachcameratoplayerobject, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:AttachCameraToPlayerObject", &arg0, &arg1))
		return NULL;

	bool ret = AttachCameraToPlayerObject(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_interpolatecamerapos, PyObject *self, PyObject *args)
{
	int arg8 = CAMERA_CUT;
	int arg7 = -1;
	float arg6 = -1.0f;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffffffi|i:InterpolateCameraPos", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8))
		return NULL;

	bool ret = InterpolateCameraPos(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_interpolatecameralookat, PyObject *self, PyObject *args)
{
	int arg8 = CAMERA_CUT;
	int arg7 = -1;
	float arg6 = -1.0f;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffffffi|i:InterpolateCameraLookAt", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8))
		return NULL;

	bool ret = InterpolateCameraLookAt(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isplayerconnected, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsPlayerConnected", &arg0))
		return NULL;

	bool ret = IsPlayerConnected(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isplayerinvehicle, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:IsPlayerInVehicle", &arg0, &arg1))
		return NULL;

	bool ret = IsPlayerInVehicle(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isplayerinanyvehicle, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsPlayerInAnyVehicle", &arg0))
		return NULL;

	bool ret = IsPlayerInAnyVehicle(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isplayerincheckpoint, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsPlayerInCheckpoint", &arg0))
		return NULL;

	bool ret = IsPlayerInCheckpoint(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isplayerinracecheckpoint, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsPlayerInRaceCheckpoint", &arg0))
		return NULL;

	bool ret = IsPlayerInRaceCheckpoint(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setplayervirtualworld, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetPlayerVirtualWorld", &arg0, &arg1))
		return NULL;

	bool ret = SetPlayerVirtualWorld(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayervirtualworld, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerVirtualWorld", &arg0))
		return NULL;

	int ret = GetPlayerVirtualWorld(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_enablestuntbonusforplayer, PyObject *self, PyObject *args)
{
	int arg1 = false;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ip:EnableStuntBonusForPlayer", &arg0, &arg1))
		return NULL;

	bool ret = EnableStuntBonusForPlayer(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_enablestuntbonusforall, PyObject *self, PyObject *args)
{
	int arg0 = false;
	if (!PyArg_ParseTuple(args, "p:EnableStuntBonusForAll", &arg0))
		return NULL;

	bool ret = EnableStuntBonusForAll(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_toggleplayerspectating, PyObject *self, PyObject *args)
{
	int arg1 = false;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ip:TogglePlayerSpectating", &arg0, &arg1))
		return NULL;

	bool ret = TogglePlayerSpectating(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playerspectateplayer, PyObject *self, PyObject *args)
{
	int arg2 = SPECTATE_MODE_NORMAL;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii|i:PlayerSpectatePlayer", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerSpectatePlayer(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_playerspectatevehicle, PyObject *self, PyObject *args)
{
	int arg2 = SPECTATE_MODE_NORMAL;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii|i:PlayerSpectateVehicle", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = PlayerSpectateVehicle(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_startrecordingplayerdata, PyObject *self, PyObject *args)
{
	const char* arg2;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iies:StartRecordingPlayerData", &arg0, &arg1, PySAMP::getEncoding().c_str(), &arg2))
		return NULL;

	bool ret = StartRecordingPlayerData(arg0, arg1, arg2);
	PyMem_Free((void *)arg2);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_stoprecordingplayerdata, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:StopRecordingPlayerData", &arg0))
		return NULL;

	bool ret = StopRecordingPlayerData(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_createexplosionforplayer, PyObject *self, PyObject *args)
{
	float arg5 = -1.0f;
	int arg4 = -1;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifffif:CreateExplosionForPlayer", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5))
		return NULL;

	bool ret = CreateExplosionForPlayer(arg0, arg1, arg2, arg3, arg4, arg5);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_sendclientmessage, PyObject *self, PyObject *args)
{
	const char* arg2;
	unsigned long arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ikes:SendClientMessage", &arg0, &arg1, PySAMP::getEncoding().c_str(), &arg2))
		return NULL;

	bool ret = SendClientMessage(arg0, arg1, arg2);
	PyMem_Free((void *)arg2);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_sendclientmessagetoall, PyObject *self, PyObject *args)
{
	const char* arg1;
	unsigned long arg0 = -1;
	if (!PyArg_ParseTuple(args, "kes:SendClientMessageToAll", &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	bool ret = SendClientMessageToAll(arg0, arg1);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_sendplayermessagetoplayer, PyObject *self, PyObject *args)
{
	const char* arg2;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iies:SendPlayerMessageToPlayer", &arg0, &arg1, PySAMP::getEncoding().c_str(), &arg2))
		return NULL;

	bool ret = SendPlayerMessageToPlayer(arg0, arg1, arg2);
	PyMem_Free((void *)arg2);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_sendplayermessagetoall, PyObject *self, PyObject *args)
{
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies:SendPlayerMessageToAll", &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	bool ret = SendPlayerMessageToAll(arg0, arg1);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_senddeathmessage, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:SendDeathMessage", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = SendDeathMessage(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_senddeathmessagetoplayer, PyObject *self, PyObject *args)
{
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiii:SendDeathMessageToPlayer", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = SendDeathMessageToPlayer(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gametextforall, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	const char* arg0;
	if (!PyArg_ParseTuple(args, "esii:GameTextForAll", PySAMP::getEncoding().c_str(), &arg0, &arg1, &arg2))
		return NULL;

	bool ret = GameTextForAll(arg0, arg1, arg2);
	PyMem_Free((void *)arg0);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gametextforplayer, PyObject *self, PyObject *args)
{
	int arg3 = -1;
	int arg2 = -1;
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iesii:GameTextForPlayer", &arg0, PySAMP::getEncoding().c_str(), &arg1, &arg2, &arg3))
		return NULL;

	bool ret = GameTextForPlayer(arg0, arg1, arg2, arg3);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gettickcount, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":GetTickCount"))
		return NULL;

	int ret = GetTickCount();
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getmaxplayers, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":GetMaxPlayers"))
		return NULL;

	int ret = GetMaxPlayers();
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_vectorsize, PyObject *self, PyObject *args)
{
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	float arg0 = -1.0f;
	if (!PyArg_ParseTuple(args, "fff:VectorSize", &arg0, &arg1, &arg2))
		return NULL;

	float ret = VectorSize(arg0, arg1, arg2);
	PyObject* out = Py_BuildValue("f", ret);
	return out;
}

WITH_GIL(pysamp_getplayerpoolsize, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":GetPlayerPoolSize"))
		return NULL;

	int ret = GetPlayerPoolSize();
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getvehiclepoolsize, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":GetVehiclePoolSize"))
		return NULL;

	int ret = GetVehiclePoolSize();
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getactorpoolsize, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":GetActorPoolSize"))
		return NULL;

	int ret = GetActorPoolSize();
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setsvarint, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	const char* arg0;
	if (!PyArg_ParseTuple(args, "esi:SetSVarInt", PySAMP::getEncoding().c_str(), &arg0, &arg1))
		return NULL;

	bool ret = SetSVarInt(arg0, arg1);
	PyMem_Free((void *)arg0);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getsvarint, PyObject *self, PyObject *args)
{
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es:GetSVarInt", PySAMP::getEncoding().c_str(), &arg0))
		return NULL;

	int ret = GetSVarInt(arg0);
	PyMem_Free((void *)arg0);
	PyObject* out = Py_BuildValue("i", ret);

	return out;
}

WITH_GIL(pysamp_setsvarstring, PyObject *self, PyObject *args)
{
	const char* arg1;
	const char* arg0;
	if (!PyArg_ParseTuple(args, "eses:SetSVarString", PySAMP::getEncoding().c_str(), &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	bool ret = SetSVarString(arg0, arg1);
	PyMem_Free((void *)arg1);
	PyMem_Free((void *)arg0);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getsvarstring, PyObject *self, PyObject *args)
{
	int arg2 = PySAMP::getConstant("MAX_CLIENT_MESSAGE");
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es|i:GetSVarString", PySAMP::getEncoding().c_str(), &arg0, &arg2))
		return NULL;

	if(arg2 < 0)
	{
		PyErr_SetString(PyExc_TypeError, "Expected a positive length as second argument.");
		PyErr_Print();
		return NULL;
	}
	char* arg1 = new char[arg2 + 1];
	bool ret = GetSVarString(arg0, arg1, arg2);
	PyObject* out = Py_BuildValue("s", arg1);
	delete[] arg1;
	PyMem_Free((void *)arg0);
	return out;
}

WITH_GIL(pysamp_setsvarfloat, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	const char* arg0;
	if (!PyArg_ParseTuple(args, "esf:SetSVarFloat", PySAMP::getEncoding().c_str(), &arg0, &arg1))
		return NULL;

	bool ret = SetSVarFloat(arg0, arg1);
	PyMem_Free((void *)arg0);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getsvarfloat, PyObject *self, PyObject *args)
{
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es:GetSVarFloat", PySAMP::getEncoding().c_str(), &arg0))
		return NULL;

	float ret = GetSVarFloat(arg0);
	PyMem_Free((void *)arg0);
	PyObject* out = Py_BuildValue("f", ret);

	return out;
}

WITH_GIL(pysamp_deletesvar, PyObject *self, PyObject *args)
{
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es:DeleteSVar", PySAMP::getEncoding().c_str(), &arg0))
		return NULL;

	bool ret = DeleteSVar(arg0);
	PyMem_Free((void *)arg0);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getsvarsupperindex, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":GetSVarsUpperIndex"))
		return NULL;

	int ret = GetSVarsUpperIndex();
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getsvarnameatindex, PyObject *self, PyObject *args)
{
	int arg2 = PySAMP::getConstant("MAX_CLIENT_MESSAGE");
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i|i:GetSVarNameAtIndex", &arg0, &arg2))
		return NULL;

	if(arg2 < 0)
	{
		PyErr_SetString(PyExc_TypeError, "Expected a positive length as second argument.");
		PyErr_Print();
		return NULL;
	}
	char* arg1 = new char[arg2 + 1];
	bool ret = GetSVarNameAtIndex(arg0, arg1, arg2);
	PyObject* out = Py_BuildValue("s", arg1);
	delete[] arg1;
	return out;
}

WITH_GIL(pysamp_getsvartype, PyObject *self, PyObject *args)
{
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es:GetSVarType", PySAMP::getEncoding().c_str(), &arg0))
		return NULL;

	int ret = GetSVarType(arg0);
	PyMem_Free((void *)arg0);
	PyObject* out = Py_BuildValue("i", ret);

	return out;
}

WITH_GIL(pysamp_setgamemodetext, PyObject *self, PyObject *args)
{
	const char* arg0;

	if (!PyArg_ParseTuple(args, "es:SetGameModeText", PySAMP::getEncoding().c_str(), &arg0))
		return NULL;

	bool ret = SetGameModeText(arg0);
	PyMem_Free((void *)arg0);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setteamcount, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:SetTeamCount", &arg0))
		return NULL;

	bool ret = SetTeamCount(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_addplayerclass, PyObject *self, PyObject *args)
{
	int arg10 = -1;
	int arg9 = -1;
	int arg8 = -1;
	int arg7 = -1;
	int arg6 = -1;
	int arg5 = -1;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffffiiiiii:AddPlayerClass", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9, &arg10))
		return NULL;

	int ret = AddPlayerClass(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_addplayerclassex, PyObject *self, PyObject *args)
{
	int arg11 = -1;
	int arg10 = -1;
	int arg9 = -1;
	int arg8 = -1;
	int arg7 = -1;
	int arg6 = -1;
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiffffiiiiii:AddPlayerClassEx", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8, &arg9, &arg10, &arg11))
		return NULL;

	int ret = AddPlayerClassEx(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8, arg9, arg10, arg11);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_addstaticvehicle, PyObject *self, PyObject *args)
{
	int arg6 = -1;
	int arg5 = -1;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffffii:AddStaticVehicle", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6))
		return NULL;

	int ret = AddStaticVehicle(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_addstaticvehicleex, PyObject *self, PyObject *args)
{
	int arg8 = false;
	int arg7 = -1;
	int arg6 = -1;
	int arg5 = -1;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffffiii|p:AddStaticVehicleEx", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8))
		return NULL;

	int ret = AddStaticVehicleEx(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_addstaticpickup, PyObject *self, PyObject *args)
{
	int arg5 = 0;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iifff|i:AddStaticPickup", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5))
		return NULL;

	int ret = AddStaticPickup(arg0, arg1, arg2, arg3, arg4, arg5);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_createpickup, PyObject *self, PyObject *args)
{
	int arg5 = 0;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iifff|i:CreatePickup", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5))
		return NULL;

	int ret = CreatePickup(arg0, arg1, arg2, arg3, arg4, arg5);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_destroypickup, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:DestroyPickup", &arg0))
		return NULL;

	bool ret = DestroyPickup(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_shownametags, PyObject *self, PyObject *args)
{
	long arg0 = 0;
	if (!PyArg_ParseTuple(args, "p:ShowNameTags", &arg0))
		return NULL;

	bool ret = ShowNameTags(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_showplayermarkers, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:ShowPlayerMarkers", &arg0))
		return NULL;

	bool ret = ShowPlayerMarkers(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gamemodeexit, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":GameModeExit"))
		return NULL;

	bool ret = GameModeExit();
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setworldtime, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:SetWorldTime", &arg0))
		return NULL;

	bool ret = SetWorldTime(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getweaponname, PyObject *self, PyObject *args)
{
	int arg2 = PySAMP::getConstant("MAX_CLIENT_MESSAGE");
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i|i:GetWeaponName", &arg0, &arg2))
		return NULL;

	if(arg2 < 0)
	{
		PyErr_SetString(PyExc_TypeError, "Expected a positive length as second argument.");
		PyErr_Print();
		return NULL;
	}
	char* arg1 = new char[arg2 + 1];
	bool ret = GetWeaponName(arg0, arg1, arg2);
	PyObject* out = Py_BuildValue("s", arg1);
	delete[] arg1;
	return out;
}

WITH_GIL(pysamp_enabletirepopping, PyObject *self, PyObject *args)
{
	int arg0 = false;
	if (!PyArg_ParseTuple(args, "p:EnableTirePopping", &arg0))
		return NULL;

	bool ret = EnableTirePopping(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_enablevehiclefriendlyfire, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":EnableVehicleFriendlyFire"))
		return NULL;

	bool ret = EnableVehicleFriendlyFire();
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_allowinteriorweapons, PyObject *self, PyObject *args)
{
	int arg0 = false;
	if (!PyArg_ParseTuple(args, "p:AllowInteriorWeapons", &arg0))
		return NULL;

	bool ret = AllowInteriorWeapons(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setweather, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:SetWeather", &arg0))
		return NULL;

	bool ret = SetWeather(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setgravity, PyObject *self, PyObject *args)
{
	float arg0 = -1.0f;
	if (!PyArg_ParseTuple(args, "f:SetGravity", &arg0))
		return NULL;

	bool ret = SetGravity(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getgravity, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":GetGravity"))
		return NULL;

	float ret = GetGravity();
	PyObject* out = Py_BuildValue("f", ret);
	return out;
}

WITH_GIL(pysamp_allowadminteleport, PyObject *self, PyObject *args)
{
	int arg0 = false;
	if (!PyArg_ParseTuple(args, "p:AllowAdminTeleport", &arg0))
		return NULL;

	bool ret = AllowAdminTeleport(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setdeathdropamount, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:SetDeathDropAmount", &arg0))
		return NULL;

	bool ret = SetDeathDropAmount(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_createexplosion, PyObject *self, PyObject *args)
{
	float arg4 = -1.0f;
	int arg3 = -1;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	float arg0 = -1.0f;
	if (!PyArg_ParseTuple(args, "fffif:CreateExplosion", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = CreateExplosion(arg0, arg1, arg2, arg3, arg4);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_enablezonenames, PyObject *self, PyObject *args)
{
	int arg0 = false;
	if (!PyArg_ParseTuple(args, "p:EnableZoneNames", &arg0))
		return NULL;

	bool ret = EnableZoneNames(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_useplayerpedanims, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":UsePlayerPedAnims"))
		return NULL;

	bool ret = UsePlayerPedAnims();
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_disableinteriorenterexits, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":DisableInteriorEnterExits"))
		return NULL;

	bool ret = DisableInteriorEnterExits();
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setnametagdrawdistance, PyObject *self, PyObject *args)
{
	float arg0 = -1.0f;
	if (!PyArg_ParseTuple(args, "f:SetNameTagDrawDistance", &arg0))
		return NULL;

	bool ret = SetNameTagDrawDistance(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_disablenametaglos, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":DisableNameTagLOS"))
		return NULL;

	bool ret = DisableNameTagLOS();
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_limitglobalchatradius, PyObject *self, PyObject *args)
{
	float arg0 = -1.0f;
	if (!PyArg_ParseTuple(args, "f:LimitGlobalChatRadius", &arg0))
		return NULL;

	bool ret = LimitGlobalChatRadius(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_limitplayermarkerradius, PyObject *self, PyObject *args)
{
	float arg0 = -1.0f;
	if (!PyArg_ParseTuple(args, "f:LimitPlayerMarkerRadius", &arg0))
		return NULL;

	bool ret = LimitPlayerMarkerRadius(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_connectnpc, PyObject *self, PyObject *args)
{
	const char* arg1;
	const char* arg0;
	if (!PyArg_ParseTuple(args, "eses:ConnectNPC", PySAMP::getEncoding().c_str(), &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	bool ret = ConnectNPC(arg0, arg1);
	PyMem_Free((void *)arg1);
	PyMem_Free((void *)arg0);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isplayernpc, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsPlayerNPC", &arg0))
		return NULL;

	bool ret = IsPlayerNPC(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isplayeradmin, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsPlayerAdmin", &arg0))
		return NULL;

	bool ret = IsPlayerAdmin(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_kick, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:Kick", &arg0))
		return NULL;

	bool ret = Kick(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_ban, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:Ban", &arg0))
		return NULL;

	bool ret = Ban(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_banex, PyObject *self, PyObject *args)
{
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies:BanEx", &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	bool ret = BanEx(arg0, arg1);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_sendrconcommand, PyObject *self, PyObject *args)
{
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es:SendRconCommand", PySAMP::getEncoding().c_str(), &arg0))
		return NULL;

	bool ret = SendRconCommand(arg0);
	PyMem_Free((void *)arg0);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayernetworkstats, PyObject *self, PyObject *args)
{
	int arg2 = PySAMP::getConstant("MAX_CLIENT_MESSAGE");
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i|i:GetPlayerNetworkStats", &arg0, &arg2))
		return NULL;

	if(arg2 < 0)
	{
		PyErr_SetString(PyExc_TypeError, "Expected a positive length as second argument.");
		PyErr_Print();
		return NULL;
	}
	char* arg1 = new char[arg2 + 1];
	bool ret = GetPlayerNetworkStats(arg0, arg1, arg2);
	PyObject* out = Py_BuildValue("s", arg1);
	delete[] arg1;
	return out;
}

WITH_GIL(pysamp_getnetworkstats, PyObject *self, PyObject *args)
{
	int arg1 = PySAMP::getConstant("MAX_CLIENT_MESSAGE");
	if (!PyArg_ParseTuple(args, "|i:GetNetworkStats", &arg1))
		return NULL;

	if(arg1 < 0)
	{
		PyErr_SetString(PyExc_TypeError, "Expected a positive length as argument.");
		PyErr_Print();
		return NULL;
	}
	char* arg0 = new char[arg1 + 1];
	bool ret = GetNetworkStats(arg0, arg1);
	PyObject* out = Py_BuildValue("s", arg0);
	delete[] arg0;
	return out;
}

WITH_GIL(pysamp_getplayerversion, PyObject *self, PyObject *args)
{
	int arg2 = PySAMP::getConstant("MAX_CLIENT_MESSAGE");
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i|i:GetPlayerVersion", &arg0, &arg2))
		return NULL;

	if(arg2 < 0)
	{
		PyErr_SetString(PyExc_TypeError, "Expected a positive length as second argument.");
		PyErr_Print();
		return NULL;
	}
	char* arg1 = new char[arg2 + 1];
	bool ret = GetPlayerVersion(arg0, arg1, arg2);
	PyObject* out = Py_BuildValue("s", arg1);
	delete[] arg1;
	return out;
}

WITH_GIL(pysamp_blockipaddress, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	const char* arg0;
	if (!PyArg_ParseTuple(args, "esi:BlockIpAddress", PySAMP::getEncoding().c_str(), &arg0, &arg1))
		return NULL;

	bool ret = BlockIpAddress(arg0, arg1);
	PyMem_Free((void *)arg0);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_unblockipaddress, PyObject *self, PyObject *args)
{
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es:UnBlockIpAddress", PySAMP::getEncoding().c_str(), &arg0))
		return NULL;

	bool ret = UnBlockIpAddress(arg0);
	PyMem_Free((void *)arg0);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getservervarasstring, PyObject *self, PyObject *args)
{
	int arg2 = PySAMP::getConstant("MAX_CLIENT_MESSAGE");
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es|i:GetServerVarAsString", PySAMP::getEncoding().c_str(), &arg0, &arg2))
		return NULL;

	if(arg2 < 0)
	{
		PyErr_SetString(PyExc_TypeError, "Expected a positive length as second argument.");
		PyErr_Print();
		return NULL;
	}
	char* arg1 = new char[arg2 + 1];
	bool ret = GetServerVarAsString(arg0, arg1, arg2);
	PyMem_Free((void *)arg0);
	PyObject* out = Py_BuildValue("s", arg1);
	delete[] arg1;
	return out;
}

WITH_GIL(pysamp_getservervarasint, PyObject *self, PyObject *args)
{
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es:GetServerVarAsInt", PySAMP::getEncoding().c_str(), &arg0))
		return NULL;

	int ret = GetServerVarAsInt(arg0);
	PyMem_Free((void *)arg0);
	PyObject* out = Py_BuildValue("i", ret);

	return out;
}

WITH_GIL(pysamp_getservervarasbool, PyObject *self, PyObject *args)
{
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es:GetServerVarAsBool", PySAMP::getEncoding().c_str(), &arg0))
		return NULL;

	bool ret = GetServerVarAsBool(arg0);
	PyMem_Free((void *)arg0);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getconsolevarasstring, PyObject *self, PyObject *args)
{
	int arg2 = PySAMP::getConstant("MAX_CLIENT_MESSAGE");
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es|i:GetConsoleVarAsString", PySAMP::getEncoding().c_str(), &arg0, &arg2))
		return NULL;

	if(arg2 < 0)
	{
		PyErr_SetString(PyExc_TypeError, "Expected a positive length as second argument.");
		PyErr_Print();
		return NULL;
	}
	char* arg1 = new char[arg2 + 1];
	bool ret = GetConsoleVarAsString(arg0, arg1, arg2);
	PyMem_Free((void *)arg0);
	PyObject* out = Py_BuildValue("s", arg1);
	delete[] arg1;
	return out;
}

WITH_GIL(pysamp_getconsolevarasint, PyObject *self, PyObject *args)
{
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es:GetConsoleVarAsInt", PySAMP::getEncoding().c_str(), &arg0))
		return NULL;

	int ret = GetConsoleVarAsInt(arg0);
	PyMem_Free((void *)arg0);
	PyObject* out = Py_BuildValue("i", ret);

	return out;
}

WITH_GIL(pysamp_getconsolevarasbool, PyObject *self, PyObject *args)
{
	const char* arg0;
	if (!PyArg_ParseTuple(args, "es:GetConsoleVarAsBool", PySAMP::getEncoding().c_str(), &arg0))
		return NULL;

	bool ret = GetConsoleVarAsBool(arg0);
	PyMem_Free((void *)arg0);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getservertickrate, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":GetServerTickRate"))
		return NULL;

	int ret = GetServerTickRate();
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_netstats_getconnectedtime, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:NetStats_GetConnectedTime", &arg0))
		return NULL;

	int ret = NetStats_GetConnectedTime(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_netstats_messagesreceived, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:NetStats_MessagesReceived", &arg0))
		return NULL;

	int ret = NetStats_MessagesReceived(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_netstats_bytesreceived, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:NetStats_BytesReceived", &arg0))
		return NULL;

	int ret = NetStats_BytesReceived(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_netstats_messagessent, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:NetStats_MessagesSent", &arg0))
		return NULL;

	int ret = NetStats_MessagesSent(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_netstats_bytessent, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:NetStats_BytesSent", &arg0))
		return NULL;

	int ret = NetStats_BytesSent(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_netstats_messagesrecvpersecond, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:NetStats_MessagesRecvPerSecond", &arg0))
		return NULL;

	int ret = NetStats_MessagesRecvPerSecond(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_netstats_packetlosspercent, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:NetStats_PacketLossPercent", &arg0))
		return NULL;

	float ret = NetStats_PacketLossPercent(arg0);
	PyObject* out = Py_BuildValue("f", ret);
	return out;
}

WITH_GIL(pysamp_netstats_connectionstatus, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:NetStats_ConnectionStatus", &arg0))
		return NULL;

	int ret = NetStats_ConnectionStatus(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_netstats_getipport, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:NetStats_GetIpPort", &arg0))
		return NULL;

	// Max IP+port size is 22 including final '\0'
	char arg1[22];
	bool ret = NetStats_GetIpPort(arg0, arg1, 22);
	PyObject* out = Py_BuildValue("s", arg1);
	return out;
}

WITH_GIL(pysamp_createmenu, PyObject *self, PyObject *args)
{
	float arg5 = -1.0f;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	const char* arg0;
	if (!PyArg_ParseTuple(args, "esiffff:CreateMenu", PySAMP::getEncoding().c_str(), &arg0, &arg1, &arg2, &arg3, &arg4, &arg5))
		return NULL;

	int ret = CreateMenu(arg0, arg1, arg2, arg3, arg4, arg5);
	PyMem_Free((void *)arg0);
	PyObject* out = Py_BuildValue("i", ret);

	return out;
}

WITH_GIL(pysamp_destroymenu, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:DestroyMenu", &arg0))
		return NULL;

	bool ret = DestroyMenu(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_addmenuitem, PyObject *self, PyObject *args)
{
	const char* arg2;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iies:AddMenuItem", &arg0, &arg1, PySAMP::getEncoding().c_str(), &arg2))
		return NULL;

	int ret = AddMenuItem(arg0, arg1, arg2);
	PyMem_Free((void *)arg2);
	PyObject* out = Py_BuildValue("i", ret);

	return out;
}

WITH_GIL(pysamp_setmenucolumnheader, PyObject *self, PyObject *args)
{
	const char* arg2;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iies:SetMenuColumnHeader", &arg0, &arg1, PySAMP::getEncoding().c_str(), &arg2))
		return NULL;

	bool ret = SetMenuColumnHeader(arg0, arg1, arg2);
	PyMem_Free((void *)arg2);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_showmenuforplayer, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:ShowMenuForPlayer", &arg0, &arg1))
		return NULL;

	bool ret = ShowMenuForPlayer(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_hidemenuforplayer, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:HideMenuForPlayer", &arg0, &arg1))
		return NULL;

	bool ret = HideMenuForPlayer(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isvalidmenu, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsValidMenu", &arg0))
		return NULL;

	bool ret = IsValidMenu(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_disablemenu, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:DisableMenu", &arg0))
		return NULL;

	bool ret = DisableMenu(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_disablemenurow, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:DisableMenuRow", &arg0, &arg1))
		return NULL;

	bool ret = DisableMenuRow(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getplayermenu, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetPlayerMenu", &arg0))
		return NULL;

	int ret = GetPlayerMenu(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_textdrawcreate, PyObject *self, PyObject *args)
{
	const char* arg2;
	float arg1 = -1.0f;
	float arg0 = -1.0f;
	if (!PyArg_ParseTuple(args, "ffes:TextDrawCreate", &arg0, &arg1, PySAMP::getEncoding().c_str(), &arg2))
		return NULL;

	int ret = TextDrawCreate(arg0, arg1, arg2);
	PyMem_Free((void *)arg2);
	PyObject* out = Py_BuildValue("i", ret);

	return out;
}

WITH_GIL(pysamp_textdrawdestroy, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:TextDrawDestroy", &arg0))
		return NULL;

	bool ret = TextDrawDestroy(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawlettersize, PyObject *self, PyObject *args)
{
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iff:TextDrawLetterSize", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = TextDrawLetterSize(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawtextsize, PyObject *self, PyObject *args)
{
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iff:TextDrawTextSize", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = TextDrawTextSize(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawalignment, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:TextDrawAlignment", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawAlignment(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawcolor, PyObject *self, PyObject *args)
{
	unsigned long arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ik:TextDrawColor", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawColor(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawusebox, PyObject *self, PyObject *args)
{
	int arg1 = false;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ip:TextDrawUseBox", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawUseBox(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawboxcolor, PyObject *self, PyObject *args)
{
	unsigned long arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ik:TextDrawBoxColor", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawBoxColor(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawsetshadow, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:TextDrawSetShadow", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawSetShadow(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawsetoutline, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:TextDrawSetOutline", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawSetOutline(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawbackgroundcolor, PyObject *self, PyObject *args)
{
	unsigned long arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ik:TextDrawBackgroundColor", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawBackgroundColor(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawfont, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:TextDrawFont", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawFont(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawsetproportional, PyObject *self, PyObject *args)
{
	int arg1 = false;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ip:TextDrawSetProportional", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawSetProportional(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawsetselectable, PyObject *self, PyObject *args)
{
	int arg1 = false;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ip:TextDrawSetSelectable", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawSetSelectable(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawshowforplayer, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:TextDrawShowForPlayer", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawShowForPlayer(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawhideforplayer, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:TextDrawHideForPlayer", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawHideForPlayer(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawshowforall, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:TextDrawShowForAll", &arg0))
		return NULL;

	bool ret = TextDrawShowForAll(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawhideforall, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:TextDrawHideForAll", &arg0))
		return NULL;

	bool ret = TextDrawHideForAll(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawsetstring, PyObject *self, PyObject *args)
{
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies:TextDrawSetString", &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	bool ret = TextDrawSetString(arg0, arg1);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawsetpreviewmodel, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:TextDrawSetPreviewModel", &arg0, &arg1))
		return NULL;

	bool ret = TextDrawSetPreviewModel(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawsetpreviewrot, PyObject *self, PyObject *args)
{
	float arg4 = 1.0;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff|f:TextDrawSetPreviewRot", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = TextDrawSetPreviewRot(arg0, arg1, arg2, arg3, arg4);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_textdrawsetpreviewvehcol, PyObject *self, PyObject *args)
{
	unsigned long arg2 = -1;
	unsigned long arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ikk:TextDrawSetPreviewVehCol", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = TextDrawSetPreviewVehCol(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_selecttextdraw, PyObject *self, PyObject *args)
{
	unsigned long arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ik:SelectTextDraw", &arg0, &arg1))
		return NULL;

	bool ret = SelectTextDraw(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_cancelselecttextdraw, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:CancelSelectTextDraw", &arg0))
		return NULL;

	bool ret = CancelSelectTextDraw(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gangzonecreate, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	float arg0 = -1.0f;
	if (!PyArg_ParseTuple(args, "ffff:GangZoneCreate", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	int ret = GangZoneCreate(arg0, arg1, arg2, arg3);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_gangzonedestroy, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GangZoneDestroy", &arg0))
		return NULL;

	bool ret = GangZoneDestroy(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gangzoneshowforplayer, PyObject *self, PyObject *args)
{
	unsigned long arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iik:GangZoneShowForPlayer", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = GangZoneShowForPlayer(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gangzoneshowforall, PyObject *self, PyObject *args)
{
	unsigned long arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ik:GangZoneShowForAll", &arg0, &arg1))
		return NULL;

	bool ret = GangZoneShowForAll(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gangzonehideforplayer, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:GangZoneHideForPlayer", &arg0, &arg1))
		return NULL;

	bool ret = GangZoneHideForPlayer(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gangzonehideforall, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GangZoneHideForAll", &arg0))
		return NULL;

	bool ret = GangZoneHideForAll(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gangzoneflashforplayer, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:GangZoneFlashForPlayer", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = GangZoneFlashForPlayer(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gangzoneflashforall, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:GangZoneFlashForAll", &arg0, &arg1))
		return NULL;

	bool ret = GangZoneFlashForAll(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gangzonestopflashforplayer, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:GangZoneStopFlashForPlayer", &arg0, &arg1))
		return NULL;

	bool ret = GangZoneStopFlashForPlayer(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gangzonestopflashforall, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GangZoneStopFlashForAll", &arg0))
		return NULL;

	bool ret = GangZoneStopFlashForAll(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}


WITH_GIL(pysamp_create3dtextlabel, PyObject *self, PyObject *args)
{
	const char* text;
	unsigned long color = -1;
	float x = 0.0;
	float y = 0.0;
	float z = 0.0;
	float drawDistance = 0.0;
	int virtualworld = -1;
	int testLOS = 0;

	if (!PyArg_ParseTuple(args, "eskffffi|i:Create3DTextLabel", PySAMP::getEncoding().c_str(), &text, &color, &x, &y, &z, &drawDistance, &virtualworld, &testLOS))
		return NULL;


	int ret = Create3DTextLabel(text, color, x, y, z, drawDistance, virtualworld, testLOS);
	PyMem_Free((void *)text);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_delete3dtextlabel, PyObject *self, PyObject *args)
{
	int id = -1;
	if (!PyArg_ParseTuple(args, "i", &id))
		return NULL;

	bool ret = Delete3DTextLabel(id);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_attach3dtextlabeltoplayer, PyObject *self, PyObject *args)
{
	int id;
	int playerid;
	float offsetX;
	float offsetY;
	float offsetZ;

	if (!PyArg_ParseTuple(args, "iifff", &id, &playerid, &offsetX, &offsetY, &offsetZ))
		return NULL;


	bool ret = Attach3DTextLabelToPlayer(id, playerid, offsetX, offsetY, offsetZ);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_attach3dtextlabeltovehicle, PyObject *self, PyObject *args)
{
	int id;
	int vehicleid;
	float offsetX;
	float offsetY;
	float offsetZ;

	if (!PyArg_ParseTuple(args, "iifff", &id, &vehicleid, &offsetX, &offsetY, &offsetZ))
		return NULL;


	bool ret = Attach3DTextLabelToVehicle(id, vehicleid, offsetX, offsetY, offsetZ);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_update3dtextlabeltext, PyObject *self, PyObject *args)
{
	int id;
	unsigned long color;
	const char* text;

	if (!PyArg_ParseTuple(args, "ikes", &id, &color, PySAMP::getEncoding().c_str(), &text))
		return NULL;


	bool ret = Update3DTextLabelText(id, color, text);
	PyMem_Free((void *)text);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_createplayer3dtextlabel, PyObject *self, PyObject *args)
{
	int playerid;
	const char* text;
	unsigned long color;
	float x;
	float y;
	float z;
	float drawDistance;
	int attachedplayer = 0xFFFF;
	int attachedvehicle = 0xFFFF;
	int testLOS = 0;

	if (!PyArg_ParseTuple(args, "ieskffff|iip", &playerid, PySAMP::getEncoding().c_str(), &text, &color, &x, &y, &z, &drawDistance, &attachedplayer, &attachedvehicle, &testLOS))
		return NULL;


	int ret = CreatePlayer3DTextLabel(playerid, text, color, x, y, z, drawDistance, attachedplayer, attachedvehicle, testLOS);
	PyMem_Free((void *)text);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_deleteplayer3dtextlabel, PyObject *self, PyObject *args)
{
	int playerid;
	int id;

	if (!PyArg_ParseTuple(args, "ii", &playerid, &id))
		return NULL;


	bool ret = DeletePlayer3DTextLabel(playerid, id);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_updateplayer3dtextlabeltext, PyObject *self, PyObject *args)
{
	int playerid;
	int id;
	unsigned long color;
	const char* text;

	if (!PyArg_ParseTuple(args, "iikes", &playerid, &id, &color, PySAMP::getEncoding().c_str(), &text))
		return NULL;


	bool ret = UpdatePlayer3DTextLabelText(playerid, id, color, text);
	PyMem_Free((void *)text);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}


WITH_GIL(pysamp_showplayerdialog, PyObject *self, PyObject *args)
{
	const char* arg6;
	const char* arg5;
	const char* arg4;
	const char* arg3;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiieseseses:ShowPlayerDialog", &arg0, &arg1, &arg2, PySAMP::getEncoding().c_str(), &arg3, PySAMP::getEncoding().c_str(), &arg4, PySAMP::getEncoding().c_str(), &arg5, PySAMP::getEncoding().c_str(), &arg6))
		return NULL;

	bool ret = ShowPlayerDialog(arg0, arg1, arg2, arg3, arg4, arg5, arg6);
	PyMem_Free((void *)arg6);
	PyMem_Free((void *)arg5);
	PyMem_Free((void *)arg4);
	PyMem_Free((void *)arg3);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_gpci, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:gpci", &arg0))
		return NULL;

	// Max gpci size is 41 including final '\0'
	char arg1[41];
	bool ret = gpci(arg0, arg1, 41);
	PyObject* out = Py_BuildValue("s", arg1);
	return out;
}

WITH_GIL(pysamp_isvalidvehicle, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsValidVehicle", &arg0))
		return NULL;

	bool ret = IsValidVehicle(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getvehicledistancefrompoint, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff:GetVehicleDistanceFromPoint", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	float ret = GetVehicleDistanceFromPoint(arg0, arg1, arg2, arg3);
	PyObject* out = Py_BuildValue("f", ret);
	return out;
}

WITH_GIL(pysamp_createvehicle, PyObject *self, PyObject *args)
{
	int arg8 = false;
	int arg7 = -1;
	int arg6 = -1;
	int arg5 = -1;
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iffffiii|p:CreateVehicle", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7, &arg8))
		return NULL;

	int ret = CreateVehicle(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7, arg8);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_destroyvehicle, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:DestroyVehicle", &arg0))
		return NULL;

	bool ret = DestroyVehicle(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_isvehiclestreamedin, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:IsVehicleStreamedIn", &arg0, &arg1))
		return NULL;

	bool ret = IsVehicleStreamedIn(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getvehiclepos, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehiclePos", &arg0))
		return NULL;

	bool ret = GetVehiclePos(arg0, &arg1, &arg2, &arg3);
	PyObject* out = Py_BuildValue("fff", arg1, arg2, arg3);
	return out;
}

WITH_GIL(pysamp_setvehiclepos, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff:SetVehiclePos", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = SetVehiclePos(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getvehiclezangle, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleZAngle", &arg0))
		return NULL;

	bool ret = GetVehicleZAngle(arg0, &arg1);
	PyObject* out = Py_BuildValue("f", arg1);
	return out;
}

WITH_GIL(pysamp_getvehiclerotationquat, PyObject *self, PyObject *args)
{
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleRotationQuat", &arg0))
		return NULL;

	bool ret = GetVehicleRotationQuat(arg0, &arg1, &arg2, &arg3, &arg4);
	PyObject* out = Py_BuildValue("ffff", arg1, arg2, arg3, arg4);
	return out;
}

WITH_GIL(pysamp_setvehiclezangle, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "if:SetVehicleZAngle", &arg0, &arg1))
		return NULL;

	bool ret = SetVehicleZAngle(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setvehicleparamsforplayer, PyObject *self, PyObject *args)
{
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiii:SetVehicleParamsForPlayer", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = SetVehicleParamsForPlayer(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_manualvehicleengineandlights, PyObject *self, PyObject *args)
{
	if (!PyArg_ParseTuple(args, ":ManualVehicleEngineAndLights"))
		return NULL;

	bool ret = ManualVehicleEngineAndLights();
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setvehicleparamsex, PyObject *self, PyObject *args)
{
	int arg7 = -1;
	int arg6 = -1;
	int arg5 = -1;
	int arg4 = -1;
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiiiiiii:SetVehicleParamsEx", &arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7))
		return NULL;

	bool ret = SetVehicleParamsEx(arg0, arg1, arg2, arg3, arg4, arg5, arg6, arg7);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getvehicleparamsex, PyObject *self, PyObject *args)
{
	int arg7 = -1;
	int arg6 = -1;
	int arg5 = -1;
	int arg4 = -1;
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleParamsEx", &arg0))
		return NULL;

	bool ret = GetVehicleParamsEx(arg0, &arg1, &arg2, &arg3, &arg4, &arg5, &arg6, &arg7);
	PyObject* out = Py_BuildValue("iiiiiii", arg1, arg2, arg3, arg4, arg5, arg6, arg7);
	return out;
}

WITH_GIL(pysamp_getvehicleparamssirenstate, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleParamsSirenState", &arg0))
		return NULL;

	int ret = GetVehicleParamsSirenState(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setvehicleparamscardoors, PyObject *self, PyObject *args)
{
	int arg4 = -1;
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiiii:SetVehicleParamsCarDoors", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = SetVehicleParamsCarDoors(arg0, arg1, arg2, arg3, arg4);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getvehicleparamscardoors, PyObject *self, PyObject *args)
{
	int arg4 = -1;
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleParamsCarDoors", &arg0))
		return NULL;

	bool ret = GetVehicleParamsCarDoors(arg0, &arg1, &arg2, &arg3, &arg4);
	PyObject* out = Py_BuildValue("iiii", arg1, arg2, arg3, arg4);
	return out;
}

WITH_GIL(pysamp_setvehicleparamscarwindows, PyObject *self, PyObject *args)
{
	int arg4 = -1;
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiiii:SetVehicleParamsCarWindows", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = SetVehicleParamsCarWindows(arg0, arg1, arg2, arg3, arg4);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getvehicleparamscarwindows, PyObject *self, PyObject *args)
{
	int arg4 = -1;
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleParamsCarWindows", &arg0))
		return NULL;

	bool ret = GetVehicleParamsCarWindows(arg0, &arg1, &arg2, &arg3, &arg4);
	PyObject* out = Py_BuildValue("iiii", arg1, arg2, arg3, arg4);
	return out;
}

WITH_GIL(pysamp_setvehicletorespawn, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:SetVehicleToRespawn", &arg0))
		return NULL;

	bool ret = SetVehicleToRespawn(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_linkvehicletointerior, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:LinkVehicleToInterior", &arg0, &arg1))
		return NULL;

	bool ret = LinkVehicleToInterior(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_addvehiclecomponent, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:AddVehicleComponent", &arg0, &arg1))
		return NULL;

	bool ret = AddVehicleComponent(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_removevehiclecomponent, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:RemoveVehicleComponent", &arg0, &arg1))
		return NULL;

	bool ret = RemoveVehicleComponent(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_changevehiclecolor, PyObject *self, PyObject *args)
{
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iii:ChangeVehicleColor", &arg0, &arg1, &arg2))
		return NULL;

	bool ret = ChangeVehicleColor(arg0, arg1, arg2);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_changevehiclepaintjob, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:ChangeVehiclePaintjob", &arg0, &arg1))
		return NULL;

	bool ret = ChangeVehiclePaintjob(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setvehiclehealth, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "if:SetVehicleHealth", &arg0, &arg1))
		return NULL;

	bool ret = SetVehicleHealth(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getvehiclehealth, PyObject *self, PyObject *args)
{
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleHealth", &arg0))
		return NULL;

	bool ret = GetVehicleHealth(arg0, &arg1);
	PyObject* out = Py_BuildValue("f", arg1);
	return out;
}

WITH_GIL(pysamp_attachtrailertovehicle, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:AttachTrailerToVehicle", &arg0, &arg1))
		return NULL;

	bool ret = AttachTrailerToVehicle(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_detachtrailerfromvehicle, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:DetachTrailerFromVehicle", &arg0))
		return NULL;

	bool ret = DetachTrailerFromVehicle(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_istrailerattachedtovehicle, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:IsTrailerAttachedToVehicle", &arg0))
		return NULL;

	bool ret = IsTrailerAttachedToVehicle(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getvehicletrailer, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleTrailer", &arg0))
		return NULL;

	int ret = GetVehicleTrailer(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_setvehiclenumberplate, PyObject *self, PyObject *args)
{
	const char* arg1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ies:SetVehicleNumberPlate", &arg0, PySAMP::getEncoding().c_str(), &arg1))
		return NULL;

	bool ret = SetVehicleNumberPlate(arg0, arg1);
	PyMem_Free((void *)arg1);

	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getvehiclemodel, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleModel", &arg0))
		return NULL;

	int ret = GetVehicleModel(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getvehiclecomponentinslot, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:GetVehicleComponentInSlot", &arg0, &arg1))
		return NULL;

	int ret = GetVehicleComponentInSlot(arg0, arg1);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getvehiclecomponenttype, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleComponentType", &arg0))
		return NULL;

	int ret = GetVehicleComponentType(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_repairvehicle, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:RepairVehicle", &arg0))
		return NULL;

	bool ret = RepairVehicle(arg0);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getvehiclevelocity, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleVelocity", &arg0))
		return NULL;

	bool ret = GetVehicleVelocity(arg0, &arg1, &arg2, &arg3);
	PyObject* out = Py_BuildValue("fff", arg1, arg2, arg3);
	return out;
}

WITH_GIL(pysamp_setvehiclevelocity, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff:SetVehicleVelocity", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = SetVehicleVelocity(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setvehicleangularvelocity, PyObject *self, PyObject *args)
{
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	float arg1 = -1.0f;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ifff:SetVehicleAngularVelocity", &arg0, &arg1, &arg2, &arg3))
		return NULL;

	bool ret = SetVehicleAngularVelocity(arg0, arg1, arg2, arg3);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getvehicledamagestatus, PyObject *self, PyObject *args)
{
	int arg4 = -1;
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleDamageStatus", &arg0))
		return NULL;

	bool ret = GetVehicleDamageStatus(arg0, &arg1, &arg2, &arg3, &arg4);
	PyObject* out = Py_BuildValue("iiii", arg1, arg2, arg3, arg4);
	return out;
}

WITH_GIL(pysamp_updatevehicledamagestatus, PyObject *self, PyObject *args)
{
	int arg4 = -1;
	int arg3 = -1;
	int arg2 = -1;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "iiiii:UpdateVehicleDamageStatus", &arg0, &arg1, &arg2, &arg3, &arg4))
		return NULL;

	bool ret = UpdateVehicleDamageStatus(arg0, arg1, arg2, arg3, arg4);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_setvehiclevirtualworld, PyObject *self, PyObject *args)
{
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:SetVehicleVirtualWorld", &arg0, &arg1))
		return NULL;

	bool ret = SetVehicleVirtualWorld(arg0, arg1);
	if (ret)
		Py_RETURN_TRUE;
	Py_RETURN_FALSE;
}

WITH_GIL(pysamp_getvehiclevirtualworld, PyObject *self, PyObject *args)
{
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "i:GetVehicleVirtualWorld", &arg0))
		return NULL;

	int ret = GetVehicleVirtualWorld(arg0);
	PyObject* out = Py_BuildValue("i", ret);
	return out;
}

WITH_GIL(pysamp_getvehiclemodelinfo, PyObject *self, PyObject *args)
{
	float arg4 = -1.0f;
	float arg3 = -1.0f;
	float arg2 = -1.0f;
	int arg1 = -1;
	int arg0 = -1;
	if (!PyArg_ParseTuple(args, "ii:GetVehicleModelInfo", &arg0, &arg1))
		return NULL;

	bool ret = GetVehicleModelInfo(arg0, arg1, &arg2, &arg3, &arg4);
	PyObject* out = Py_BuildValue("fff", arg2, arg3, arg4);
	return out;
}

WITH_GIL(pysamp_settimer, PyObject *self, PyObject *args)
{
	PyObject* arguments = NULL;
	Py_ssize_t len_args = PyTuple_Size(args);

	if(len_args > 3)
	{
		arguments = PyTuple_GetSlice(args, 3, len_args);
		args = PyTuple_GetSlice(args, 0, 3);
	}

	Timer* timer = Timer::from_args(args, arguments);

	if(len_args > 3)
	{
		Py_XDECREF(arguments);
		Py_DECREF(args);
	}

	if(timer == NULL)
		return NULL;

	PySAMP::addTimer(*timer);

	return Py_BuildValue("i", timer->get_id());
}

WITH_GIL(pysamp_killtimer, PyObject *self, PyObject *args)
{
	int id;

	if(!PyArg_ParseTuple(args, "i:KillTimer", &id))
		return NULL;

	PySAMP::removeTimer(id);
	Py_RETURN_NONE;
}

WITH_GIL(pysamp_callnativefunction, PyObject *self, PyObject *args)
{
	PyObject* function_str = NULL;
	const char *function_name = NULL;

	function_str = PyTuple_GetItem(args, 0);

	if(function_str == NULL)
	{
		PyErr_SetString(
			PyExc_TypeError,
			"CallNativeFunction() missing required argument 'func_name' (pos 1)"
		);
		return NULL;
	}

	function_name = PyUnicode_AsUTF8(function_str);

	if(function_name == NULL)
	{
		PyErr_Format(
			PyExc_TypeError,
			"CallNativeFunction() argument 'func_name' (pos 1) must be str, not %s",
			Py_TYPE(function_str)->tp_name
		);
		return NULL;
	}

	AMX_NATIVE amx_function = sampgdk::FindNative(function_name);

	if(amx_function == NULL)
	{
		PyErr_Format(
			PyExc_ValueError,
			"CallNativeFunction() unknown native function %s",
			function_name
		);
		return NULL;
	}

	cell *amx_params = PySAMP::tupleToAmxParams(args);

	if(amx_params == NULL)
		return NULL;

	cell return_value = sampgdk::CallNative(amx_function, amx_params);
	delete[] amx_params;

	return Py_BuildValue("i", return_value);
}

WITH_GIL(pysamp_config, PyObject *self, PyObject *args, PyObject *kwargs)
{
	if(!PySAMP::isInitialized())
		return PyDict_New();

	return PySAMP::pyConfig(self, args, kwargs);
}

WITH_GIL(pysamp_registercallback, PyObject *self, PyObject *args)
{
	const char
		*name = NULL,
		*format = NULL
	;

	if(!PyArg_ParseTuple(args, "ss:RegisterCallback", &name, &format))
		return NULL;

	if(!PySAMP::isInitialized())
		Py_RETURN_NONE;

	PySAMP::registerCallback(name, format);
	Py_RETURN_NONE;
}

static PyMethodDef PySAMPMethods[] = {
	{ "CreateActor", pysamp_createactor, METH_VARARGS, NULL },
	{ "DestroyActor", pysamp_destroyactor, METH_VARARGS, NULL },
	{ "IsActorStreamedIn", pysamp_isactorstreamedin, METH_VARARGS, NULL },
	{ "SetActorVirtualWorld", pysamp_setactorvirtualworld, METH_VARARGS, NULL },
	{ "GetActorVirtualWorld", pysamp_getactorvirtualworld, METH_VARARGS, NULL },
	{ "ApplyActorAnimation", pysamp_applyactoranimation, METH_VARARGS, NULL },
	{ "ClearActorAnimations", pysamp_clearactoranimations, METH_VARARGS, NULL },
	{ "SetActorPos", pysamp_setactorpos, METH_VARARGS, NULL },
	{ "GetActorPos", pysamp_getactorpos, METH_VARARGS, NULL },
	{ "SetActorFacingAngle", pysamp_setactorfacingangle, METH_VARARGS, NULL },
	{ "GetActorFacingAngle", pysamp_getactorfacingangle, METH_VARARGS, NULL },
	{ "SetActorHealth", pysamp_setactorhealth, METH_VARARGS, NULL },
	{ "GetActorHealth", pysamp_getactorhealth, METH_VARARGS, NULL },
	{ "SetActorInvulnerable", pysamp_setactorinvulnerable, METH_VARARGS, NULL },
	{ "IsActorInvulnerable", pysamp_isactorinvulnerable, METH_VARARGS, NULL },
	{ "IsValidActor", pysamp_isvalidactor, METH_VARARGS, NULL },
	{ "CreateObject", pysamp_createobject, METH_VARARGS, NULL },
	{ "AttachObjectToVehicle", pysamp_attachobjecttovehicle, METH_VARARGS, NULL },
	{ "AttachObjectToObject", pysamp_attachobjecttoobject, METH_VARARGS, NULL },
	{ "AttachObjectToPlayer", pysamp_attachobjecttoplayer, METH_VARARGS, NULL },
	{ "SetObjectPos", pysamp_setobjectpos, METH_VARARGS, NULL },
	{ "GetObjectPos", pysamp_getobjectpos, METH_VARARGS, NULL },
	{ "SetObjectRot", pysamp_setobjectrot, METH_VARARGS, NULL },
	{ "GetObjectRot", pysamp_getobjectrot, METH_VARARGS, NULL },
	{ "GetObjectModel", pysamp_getobjectmodel, METH_VARARGS, NULL },
	{ "SetObjectNoCameraCol", pysamp_setobjectnocameracol, METH_VARARGS, NULL },
	{ "IsValidObject", pysamp_isvalidobject, METH_VARARGS, NULL },
	{ "DestroyObject", pysamp_destroyobject, METH_VARARGS, NULL },
	{ "MoveObject", pysamp_moveobject, METH_VARARGS, NULL },
	{ "StopObject", pysamp_stopobject, METH_VARARGS, NULL },
	{ "IsObjectMoving", pysamp_isobjectmoving, METH_VARARGS, NULL },
	{ "EditObject", pysamp_editobject, METH_VARARGS, NULL },
	{ "EditPlayerObject", pysamp_editplayerobject, METH_VARARGS, NULL },
	{ "SelectObject", pysamp_selectobject, METH_VARARGS, NULL },
	{ "CancelEdit", pysamp_canceledit, METH_VARARGS, NULL },
	{ "CreatePlayerObject", pysamp_createplayerobject, METH_VARARGS, NULL },
	{ "AttachPlayerObjectToPlayer", pysamp_attachplayerobjecttoplayer, METH_VARARGS, NULL },
	{ "AttachPlayerObjectToVehicle", pysamp_attachplayerobjecttovehicle, METH_VARARGS, NULL },
	{ "SetPlayerObjectPos", pysamp_setplayerobjectpos, METH_VARARGS, NULL },
	{ "GetPlayerObjectPos", pysamp_getplayerobjectpos, METH_VARARGS, NULL },
	{ "SetPlayerObjectRot", pysamp_setplayerobjectrot, METH_VARARGS, NULL },
	{ "GetPlayerObjectRot", pysamp_getplayerobjectrot, METH_VARARGS, NULL },
	{ "GetPlayerObjectModel", pysamp_getplayerobjectmodel, METH_VARARGS, NULL },
	{ "SetPlayerObjectNoCameraCol", pysamp_setplayerobjectnocameracol, METH_VARARGS, NULL },
	{ "IsValidPlayerObject", pysamp_isvalidplayerobject, METH_VARARGS, NULL },
	{ "DestroyPlayerObject", pysamp_destroyplayerobject, METH_VARARGS, NULL },
	{ "MovePlayerObject", pysamp_moveplayerobject, METH_VARARGS, NULL },
	{ "StopPlayerObject", pysamp_stopplayerobject, METH_VARARGS, NULL },
	{ "IsPlayerObjectMoving", pysamp_isplayerobjectmoving, METH_VARARGS, NULL },
	{ "SetObjectMaterial", pysamp_setobjectmaterial, METH_VARARGS, NULL },
	{ "SetPlayerObjectMaterial", pysamp_setplayerobjectmaterial, METH_VARARGS, NULL },
	{ "SetObjectMaterialText", pysamp_setobjectmaterialtext, METH_VARARGS, NULL },
	{ "SetPlayerObjectMaterialText", pysamp_setplayerobjectmaterialtext, METH_VARARGS, NULL },
	{ "SetObjectsDefaultCameraCol", pysamp_setobjectsdefaultcameracol, METH_VARARGS, NULL },
	{ "SetSpawnInfo", pysamp_setspawninfo, METH_VARARGS, NULL },
	{ "SpawnPlayer", pysamp_spawnplayer, METH_VARARGS, NULL },
	{ "SetPlayerPos", pysamp_setplayerpos, METH_VARARGS, NULL },
	{ "SetPlayerPosFindZ", pysamp_setplayerposfindz, METH_VARARGS, NULL },
	{ "GetPlayerPos", pysamp_getplayerpos, METH_VARARGS, NULL },
	{ "SetPlayerFacingAngle", pysamp_setplayerfacingangle, METH_VARARGS, NULL },
	{ "GetPlayerFacingAngle", pysamp_getplayerfacingangle, METH_VARARGS, NULL },
	{ "IsPlayerInRangeOfPoint", pysamp_isplayerinrangeofpoint, METH_VARARGS, NULL },
	{ "GetPlayerDistanceFromPoint", pysamp_getplayerdistancefrompoint, METH_VARARGS, NULL },
	{ "IsPlayerStreamedIn", pysamp_isplayerstreamedin, METH_VARARGS, NULL },
	{ "SetPlayerInterior", pysamp_setplayerinterior, METH_VARARGS, NULL },
	{ "GetPlayerInterior", pysamp_getplayerinterior, METH_VARARGS, NULL },
	{ "SetPlayerHealth", pysamp_setplayerhealth, METH_VARARGS, NULL },
	{ "GetPlayerHealth", pysamp_getplayerhealth, METH_VARARGS, NULL },
	{ "SetPlayerArmour", pysamp_setplayerarmour, METH_VARARGS, NULL },
	{ "GetPlayerArmour", pysamp_getplayerarmour, METH_VARARGS, NULL },
	{ "SetPlayerAmmo", pysamp_setplayerammo, METH_VARARGS, NULL },
	{ "GetPlayerAmmo", pysamp_getplayerammo, METH_VARARGS, NULL },
	{ "GetPlayerWeaponState", pysamp_getplayerweaponstate, METH_VARARGS, NULL },
	{ "GetPlayerTargetPlayer", pysamp_getplayertargetplayer, METH_VARARGS, NULL },
	{ "GetPlayerTargetActor", pysamp_getplayertargetactor, METH_VARARGS, NULL },
	{ "SetPlayerTeam", pysamp_setplayerteam, METH_VARARGS, NULL },
	{ "GetPlayerTeam", pysamp_getplayerteam, METH_VARARGS, NULL },
	{ "SetPlayerScore", pysamp_setplayerscore, METH_VARARGS, NULL },
	{ "GetPlayerScore", pysamp_getplayerscore, METH_VARARGS, NULL },
	{ "GetPlayerDrunkLevel", pysamp_getplayerdrunklevel, METH_VARARGS, NULL },
	{ "SetPlayerDrunkLevel", pysamp_setplayerdrunklevel, METH_VARARGS, NULL },
	{ "SetPlayerColor", pysamp_setplayercolor, METH_VARARGS, NULL },
	{ "GetPlayerColor", pysamp_getplayercolor, METH_VARARGS, NULL },
	{ "SetPlayerSkin", pysamp_setplayerskin, METH_VARARGS, NULL },
	{ "GetPlayerSkin", pysamp_getplayerskin, METH_VARARGS, NULL },
	{ "GivePlayerWeapon", pysamp_giveplayerweapon, METH_VARARGS, NULL },
	{ "ResetPlayerWeapons", pysamp_resetplayerweapons, METH_VARARGS, NULL },
	{ "SetPlayerArmedWeapon", pysamp_setplayerarmedweapon, METH_VARARGS, NULL },
	{ "GetPlayerWeaponData", pysamp_getplayerweapondata, METH_VARARGS, NULL },
	{ "GivePlayerMoney", pysamp_giveplayermoney, METH_VARARGS, NULL },
	{ "ResetPlayerMoney", pysamp_resetplayermoney, METH_VARARGS, NULL },
	{ "SetPlayerName", pysamp_setplayername, METH_VARARGS, NULL },
	{ "GetPlayerMoney", pysamp_getplayermoney, METH_VARARGS, NULL },
	{ "GetPlayerState", pysamp_getplayerstate, METH_VARARGS, NULL },
	{ "GetPlayerIp", pysamp_getplayerip, METH_VARARGS, NULL },
	{ "GetPlayerPing", pysamp_getplayerping, METH_VARARGS, NULL },
	{ "GetPlayerWeapon", pysamp_getplayerweapon, METH_VARARGS, NULL },
	{ "GetPlayerKeys", pysamp_getplayerkeys, METH_VARARGS, NULL },
	{ "GetPlayerName", pysamp_getplayername, METH_VARARGS, NULL },
	{ "SetPlayerTime", pysamp_setplayertime, METH_VARARGS, NULL },
	{ "GetPlayerTime", pysamp_getplayertime, METH_VARARGS, NULL },
	{ "TogglePlayerClock", pysamp_toggleplayerclock, METH_VARARGS, NULL },
	{ "SetPlayerWeather", pysamp_setplayerweather, METH_VARARGS, NULL },
	{ "ForceClassSelection", pysamp_forceclassselection, METH_VARARGS, NULL },
	{ "SetPlayerWantedLevel", pysamp_setplayerwantedlevel, METH_VARARGS, NULL },
	{ "GetPlayerWantedLevel", pysamp_getplayerwantedlevel, METH_VARARGS, NULL },
	{ "SetPlayerFightingStyle", pysamp_setplayerfightingstyle, METH_VARARGS, NULL },
	{ "GetPlayerFightingStyle", pysamp_getplayerfightingstyle, METH_VARARGS, NULL },
	{ "SetPlayerVelocity", pysamp_setplayervelocity, METH_VARARGS, NULL },
	{ "GetPlayerVelocity", pysamp_getplayervelocity, METH_VARARGS, NULL },
	{ "PlayCrimeReportForPlayer", pysamp_playcrimereportforplayer, METH_VARARGS, NULL },
	{ "PlayAudioStreamForPlayer", pysamp_playaudiostreamforplayer, METH_VARARGS, NULL },
	{ "StopAudioStreamForPlayer", pysamp_stopaudiostreamforplayer, METH_VARARGS, NULL },
	{ "SetPlayerShopName", pysamp_setplayershopname, METH_VARARGS, NULL },
	{ "SetPlayerSkillLevel", pysamp_setplayerskilllevel, METH_VARARGS, NULL },
	{ "GetPlayerSurfingVehicleID", pysamp_getplayersurfingvehicleid, METH_VARARGS, NULL },
	{ "GetPlayerSurfingObjectID", pysamp_getplayersurfingobjectid, METH_VARARGS, NULL },
	{ "RemoveBuildingForPlayer", pysamp_removebuildingforplayer, METH_VARARGS, NULL },
	{ "GetPlayerLastShotVectors", pysamp_getplayerlastshotvectors, METH_VARARGS, NULL },
	{ "SetPlayerAttachedObject", pysamp_setplayerattachedobject, METH_VARARGS, NULL },
	{ "RemovePlayerAttachedObject", pysamp_removeplayerattachedobject, METH_VARARGS, NULL },
	{ "IsPlayerAttachedObjectSlotUsed", pysamp_isplayerattachedobjectslotused, METH_VARARGS, NULL },
	{ "EditAttachedObject", pysamp_editattachedobject, METH_VARARGS, NULL },
	{ "CreatePlayerTextDraw", pysamp_createplayertextdraw, METH_VARARGS, NULL },
	{ "PlayerTextDrawDestroy", pysamp_playertextdrawdestroy, METH_VARARGS, NULL },
	{ "PlayerTextDrawLetterSize", pysamp_playertextdrawlettersize, METH_VARARGS, NULL },
	{ "PlayerTextDrawTextSize", pysamp_playertextdrawtextsize, METH_VARARGS, NULL },
	{ "PlayerTextDrawAlignment", pysamp_playertextdrawalignment, METH_VARARGS, NULL },
	{ "PlayerTextDrawColor", pysamp_playertextdrawcolor, METH_VARARGS, NULL },
	{ "PlayerTextDrawUseBox", pysamp_playertextdrawusebox, METH_VARARGS, NULL },
	{ "PlayerTextDrawBoxColor", pysamp_playertextdrawboxcolor, METH_VARARGS, NULL },
	{ "PlayerTextDrawSetShadow", pysamp_playertextdrawsetshadow, METH_VARARGS, NULL },
	{ "PlayerTextDrawSetOutline", pysamp_playertextdrawsetoutline, METH_VARARGS, NULL },
	{ "PlayerTextDrawBackgroundColor", pysamp_playertextdrawbackgroundcolor, METH_VARARGS, NULL },
	{ "PlayerTextDrawFont", pysamp_playertextdrawfont, METH_VARARGS, NULL },
	{ "PlayerTextDrawSetProportional", pysamp_playertextdrawsetproportional, METH_VARARGS, NULL },
	{ "PlayerTextDrawSetSelectable", pysamp_playertextdrawsetselectable, METH_VARARGS, NULL },
	{ "PlayerTextDrawShow", pysamp_playertextdrawshow, METH_VARARGS, NULL },
	{ "PlayerTextDrawHide", pysamp_playertextdrawhide, METH_VARARGS, NULL },
	{ "PlayerTextDrawSetString", pysamp_playertextdrawsetstring, METH_VARARGS, NULL },
	{ "PlayerTextDrawSetPreviewModel", pysamp_playertextdrawsetpreviewmodel, METH_VARARGS, NULL },
	{ "PlayerTextDrawSetPreviewRot", pysamp_playertextdrawsetpreviewrot, METH_VARARGS, NULL },
	{ "PlayerTextDrawSetPreviewVehCol", pysamp_playertextdrawsetpreviewvehcol, METH_VARARGS, NULL },
	{ "SetPVarInt", pysamp_setpvarint, METH_VARARGS, NULL },
	{ "GetPVarInt", pysamp_getpvarint, METH_VARARGS, NULL },
	{ "SetPVarString", pysamp_setpvarstring, METH_VARARGS, NULL },
	{ "GetPVarString", pysamp_getpvarstring, METH_VARARGS, NULL },
	{ "SetPVarFloat", pysamp_setpvarfloat, METH_VARARGS, NULL },
	{ "GetPVarFloat", pysamp_getpvarfloat, METH_VARARGS, NULL },
	{ "DeletePVar", pysamp_deletepvar, METH_VARARGS, NULL },
	{ "GetPVarsUpperIndex", pysamp_getpvarsupperindex, METH_VARARGS, NULL },
	{ "GetPVarNameAtIndex", pysamp_getpvarnameatindex, METH_VARARGS, NULL },
	{ "GetPVarType", pysamp_getpvartype, METH_VARARGS, NULL },
	{ "SetPlayerChatBubble", pysamp_setplayerchatbubble, METH_VARARGS, NULL },
	{ "PutPlayerInVehicle", pysamp_putplayerinvehicle, METH_VARARGS, NULL },
	{ "GetPlayerVehicleID", pysamp_getplayervehicleid, METH_VARARGS, NULL },
	{ "GetPlayerVehicleSeat", pysamp_getplayervehicleseat, METH_VARARGS, NULL },
	{ "RemovePlayerFromVehicle", pysamp_removeplayerfromvehicle, METH_VARARGS, NULL },
	{ "TogglePlayerControllable", pysamp_toggleplayercontrollable, METH_VARARGS, NULL },
	{ "PlayerPlaySound", pysamp_playerplaysound, METH_VARARGS, NULL },
	{ "ApplyAnimation", pysamp_applyanimation, METH_VARARGS, NULL },
	{ "ClearAnimations", pysamp_clearanimations, METH_VARARGS, NULL },
	{ "GetPlayerAnimationIndex", pysamp_getplayeranimationindex, METH_VARARGS, NULL },
	{ "GetAnimationName", pysamp_getanimationname, METH_VARARGS, NULL },
	{ "GetPlayerSpecialAction", pysamp_getplayerspecialaction, METH_VARARGS, NULL },
	{ "SetPlayerSpecialAction", pysamp_setplayerspecialaction, METH_VARARGS, NULL },
	{ "DisableRemoteVehicleCollisions", pysamp_disableremotevehiclecollisions, METH_VARARGS, NULL },
	{ "SetPlayerCheckpoint", pysamp_setplayercheckpoint, METH_VARARGS, NULL },
	{ "DisablePlayerCheckpoint", pysamp_disableplayercheckpoint, METH_VARARGS, NULL },
	{ "SetPlayerRaceCheckpoint", pysamp_setplayerracecheckpoint, METH_VARARGS, NULL },
	{ "DisablePlayerRaceCheckpoint", pysamp_disableplayerracecheckpoint, METH_VARARGS, NULL },
	{ "SetPlayerWorldBounds", pysamp_setplayerworldbounds, METH_VARARGS, NULL },
	{ "SetPlayerMarkerForPlayer", pysamp_setplayermarkerforplayer, METH_VARARGS, NULL },
	{ "ShowPlayerNameTagForPlayer", pysamp_showplayernametagforplayer, METH_VARARGS, NULL },
	{ "SetPlayerMapIcon", pysamp_setplayermapicon, METH_VARARGS, NULL },
	{ "RemovePlayerMapIcon", pysamp_removeplayermapicon, METH_VARARGS, NULL },
	{ "AllowPlayerTeleport", pysamp_allowplayerteleport, METH_VARARGS, NULL },
	{ "SetPlayerCameraPos", pysamp_setplayercamerapos, METH_VARARGS, NULL },
	{ "SetPlayerCameraLookAt", pysamp_setplayercameralookat, METH_VARARGS, NULL },
	{ "SetCameraBehindPlayer", pysamp_setcamerabehindplayer, METH_VARARGS, NULL },
	{ "GetPlayerCameraPos", pysamp_getplayercamerapos, METH_VARARGS, NULL },
	{ "GetPlayerCameraFrontVector", pysamp_getplayercamerafrontvector, METH_VARARGS, NULL },
	{ "GetPlayerCameraMode", pysamp_getplayercameramode, METH_VARARGS, NULL },
	{ "EnablePlayerCameraTarget", pysamp_enableplayercameratarget, METH_VARARGS, NULL },
	{ "GetPlayerCameraTargetObject", pysamp_getplayercameratargetobject, METH_VARARGS, NULL },
	{ "GetPlayerCameraTargetVehicle", pysamp_getplayercameratargetvehicle, METH_VARARGS, NULL },
	{ "GetPlayerCameraTargetPlayer", pysamp_getplayercameratargetplayer, METH_VARARGS, NULL },
	{ "GetPlayerCameraTargetActor", pysamp_getplayercameratargetactor, METH_VARARGS, NULL },
	{ "GetPlayerCameraAspectRatio", pysamp_getplayercameraaspectratio, METH_VARARGS, NULL },
	{ "GetPlayerCameraZoom", pysamp_getplayercamerazoom, METH_VARARGS, NULL },
	{ "AttachCameraToObject", pysamp_attachcameratoobject, METH_VARARGS, NULL },
	{ "AttachCameraToPlayerObject", pysamp_attachcameratoplayerobject, METH_VARARGS, NULL },
	{ "InterpolateCameraPos", pysamp_interpolatecamerapos, METH_VARARGS, NULL },
	{ "InterpolateCameraLookAt", pysamp_interpolatecameralookat, METH_VARARGS, NULL },
	{ "IsPlayerConnected", pysamp_isplayerconnected, METH_VARARGS, NULL },
	{ "IsPlayerInVehicle", pysamp_isplayerinvehicle, METH_VARARGS, NULL },
	{ "IsPlayerInAnyVehicle", pysamp_isplayerinanyvehicle, METH_VARARGS, NULL },
	{ "IsPlayerInCheckpoint", pysamp_isplayerincheckpoint, METH_VARARGS, NULL },
	{ "IsPlayerInRaceCheckpoint", pysamp_isplayerinracecheckpoint, METH_VARARGS, NULL },
	{ "SetPlayerVirtualWorld", pysamp_setplayervirtualworld, METH_VARARGS, NULL },
	{ "GetPlayerVirtualWorld", pysamp_getplayervirtualworld, METH_VARARGS, NULL },
	{ "EnableStuntBonusForPlayer", pysamp_enablestuntbonusforplayer, METH_VARARGS, NULL },
	{ "EnableStuntBonusForAll", pysamp_enablestuntbonusforall, METH_VARARGS, NULL },
	{ "TogglePlayerSpectating", pysamp_toggleplayerspectating, METH_VARARGS, NULL },
	{ "PlayerSpectatePlayer", pysamp_playerspectateplayer, METH_VARARGS, NULL },
	{ "PlayerSpectateVehicle", pysamp_playerspectatevehicle, METH_VARARGS, NULL },
	{ "StartRecordingPlayerData", pysamp_startrecordingplayerdata, METH_VARARGS, NULL },
	{ "StopRecordingPlayerData", pysamp_stoprecordingplayerdata, METH_VARARGS, NULL },
	{ "CreateExplosionForPlayer", pysamp_createexplosionforplayer, METH_VARARGS, NULL },
	{ "SendClientMessage", pysamp_sendclientmessage, METH_VARARGS, NULL },
	{ "SendClientMessageToAll", pysamp_sendclientmessagetoall, METH_VARARGS, NULL },
	{ "SendPlayerMessageToPlayer", pysamp_sendplayermessagetoplayer, METH_VARARGS, NULL },
	{ "SendPlayerMessageToAll", pysamp_sendplayermessagetoall, METH_VARARGS, NULL },
	{ "SendDeathMessage", pysamp_senddeathmessage, METH_VARARGS, NULL },
	{ "SendDeathMessageToPlayer", pysamp_senddeathmessagetoplayer, METH_VARARGS, NULL },
	{ "GameTextForAll", pysamp_gametextforall, METH_VARARGS, NULL },
	{ "GameTextForPlayer", pysamp_gametextforplayer, METH_VARARGS, NULL },
	{ "GetTickCount", pysamp_gettickcount, METH_VARARGS, NULL },
	{ "GetMaxPlayers", pysamp_getmaxplayers, METH_VARARGS, NULL },
	{ "VectorSize", pysamp_vectorsize, METH_VARARGS, NULL },
	{ "GetPlayerPoolSize", pysamp_getplayerpoolsize, METH_VARARGS, NULL },
	{ "GetVehiclePoolSize", pysamp_getvehiclepoolsize, METH_VARARGS, NULL },
	{ "GetActorPoolSize", pysamp_getactorpoolsize, METH_VARARGS, NULL },
	{ "SetSVarInt", pysamp_setsvarint, METH_VARARGS, NULL },
	{ "GetSVarInt", pysamp_getsvarint, METH_VARARGS, NULL },
	{ "SetSVarString", pysamp_setsvarstring, METH_VARARGS, NULL },
	{ "GetSVarString", pysamp_getsvarstring, METH_VARARGS, NULL },
	{ "SetSVarFloat", pysamp_setsvarfloat, METH_VARARGS, NULL },
	{ "GetSVarFloat", pysamp_getsvarfloat, METH_VARARGS, NULL },
	{ "DeleteSVar", pysamp_deletesvar, METH_VARARGS, NULL },
	{ "GetSVarsUpperIndex", pysamp_getsvarsupperindex, METH_VARARGS, NULL },
	{ "GetSVarNameAtIndex", pysamp_getsvarnameatindex, METH_VARARGS, NULL },
	{ "GetSVarType", pysamp_getsvartype, METH_VARARGS, NULL },
	{ "SetGameModeText", pysamp_setgamemodetext, METH_VARARGS, NULL },
	{ "SetTeamCount", pysamp_setteamcount, METH_VARARGS, NULL },
	{ "AddPlayerClass", pysamp_addplayerclass, METH_VARARGS, NULL },
	{ "AddPlayerClassEx", pysamp_addplayerclassex, METH_VARARGS, NULL },
	{ "AddStaticVehicle", pysamp_addstaticvehicle, METH_VARARGS, NULL },
	{ "AddStaticVehicleEx", pysamp_addstaticvehicleex, METH_VARARGS, NULL },
	{ "AddStaticPickup", pysamp_addstaticpickup, METH_VARARGS, NULL },
	{ "CreatePickup", pysamp_createpickup, METH_VARARGS, NULL },
	{ "DestroyPickup", pysamp_destroypickup, METH_VARARGS, NULL },
	{ "ShowNameTags", pysamp_shownametags, METH_VARARGS, NULL },
	{ "ShowPlayerMarkers", pysamp_showplayermarkers, METH_VARARGS, NULL },
	{ "GameModeExit", pysamp_gamemodeexit, METH_VARARGS, NULL },
	{ "SetWorldTime", pysamp_setworldtime, METH_VARARGS, NULL },
	{ "GetWeaponName", pysamp_getweaponname, METH_VARARGS, NULL },
	{ "EnableTirePopping", pysamp_enabletirepopping, METH_VARARGS, NULL },
	{ "EnableVehicleFriendlyFire", pysamp_enablevehiclefriendlyfire, METH_VARARGS, NULL },
	{ "AllowInteriorWeapons", pysamp_allowinteriorweapons, METH_VARARGS, NULL },
	{ "SetWeather", pysamp_setweather, METH_VARARGS, NULL },
	{ "SetGravity", pysamp_setgravity, METH_VARARGS, NULL },
	{ "GetGravity", pysamp_getgravity, METH_VARARGS, NULL },
	{ "AllowAdminTeleport", pysamp_allowadminteleport, METH_VARARGS, NULL },
	{ "SetDeathDropAmount", pysamp_setdeathdropamount, METH_VARARGS, NULL },
	{ "CreateExplosion", pysamp_createexplosion, METH_VARARGS, NULL },
	{ "EnableZoneNames", pysamp_enablezonenames, METH_VARARGS, NULL },
	{ "UsePlayerPedAnims", pysamp_useplayerpedanims, METH_VARARGS, NULL },
	{ "DisableInteriorEnterExits", pysamp_disableinteriorenterexits, METH_VARARGS, NULL },
	{ "SetNameTagDrawDistance", pysamp_setnametagdrawdistance, METH_VARARGS, NULL },
	{ "DisableNameTagLOS", pysamp_disablenametaglos, METH_VARARGS, NULL },
	{ "LimitGlobalChatRadius", pysamp_limitglobalchatradius, METH_VARARGS, NULL },
	{ "LimitPlayerMarkerRadius", pysamp_limitplayermarkerradius, METH_VARARGS, NULL },
	{ "ConnectNPC", pysamp_connectnpc, METH_VARARGS, NULL },
	{ "IsPlayerNPC", pysamp_isplayernpc, METH_VARARGS, NULL },
	{ "IsPlayerAdmin", pysamp_isplayeradmin, METH_VARARGS, NULL },
	{ "Kick", pysamp_kick, METH_VARARGS, NULL },
	{ "Ban", pysamp_ban, METH_VARARGS, NULL },
	{ "BanEx", pysamp_banex, METH_VARARGS, NULL },
	{ "SendRconCommand", pysamp_sendrconcommand, METH_VARARGS, NULL },
	{ "GetPlayerNetworkStats", pysamp_getplayernetworkstats, METH_VARARGS, NULL },
	{ "GetNetworkStats", pysamp_getnetworkstats, METH_VARARGS, NULL },
	{ "GetPlayerVersion", pysamp_getplayerversion, METH_VARARGS, NULL },
	{ "BlockIpAddress", pysamp_blockipaddress, METH_VARARGS, NULL },
	{ "UnBlockIpAddress", pysamp_unblockipaddress, METH_VARARGS, NULL },
	{ "GetServerVarAsString", pysamp_getservervarasstring, METH_VARARGS, NULL },
	{ "GetServerVarAsInt", pysamp_getservervarasint, METH_VARARGS, NULL },
	{ "GetServerVarAsBool", pysamp_getservervarasbool, METH_VARARGS, NULL },
	{ "GetConsoleVarAsString", pysamp_getconsolevarasstring, METH_VARARGS, NULL },
	{ "GetConsoleVarAsInt", pysamp_getconsolevarasint, METH_VARARGS, NULL },
	{ "GetConsoleVarAsBool", pysamp_getconsolevarasbool, METH_VARARGS, NULL },
	{ "GetServerTickRate", pysamp_getservertickrate, METH_VARARGS, NULL },
	{ "NetStats_GetConnectedTime", pysamp_netstats_getconnectedtime, METH_VARARGS, NULL },
	{ "NetStats_MessagesReceived", pysamp_netstats_messagesreceived, METH_VARARGS, NULL },
	{ "NetStats_BytesReceived", pysamp_netstats_bytesreceived, METH_VARARGS, NULL },
	{ "NetStats_MessagesSent", pysamp_netstats_messagessent, METH_VARARGS, NULL },
	{ "NetStats_BytesSent", pysamp_netstats_bytessent, METH_VARARGS, NULL },
	{ "NetStats_MessagesRecvPerSecond", pysamp_netstats_messagesrecvpersecond, METH_VARARGS, NULL },
	{ "NetStats_PacketLossPercent", pysamp_netstats_packetlosspercent, METH_VARARGS, NULL },
	{ "NetStats_ConnectionStatus", pysamp_netstats_connectionstatus, METH_VARARGS, NULL },
	{ "NetStats_GetIpPort", pysamp_netstats_getipport, METH_VARARGS, NULL },
	{ "CreateMenu", pysamp_createmenu, METH_VARARGS, NULL },
	{ "DestroyMenu", pysamp_destroymenu, METH_VARARGS, NULL },
	{ "AddMenuItem", pysamp_addmenuitem, METH_VARARGS, NULL },
	{ "SetMenuColumnHeader", pysamp_setmenucolumnheader, METH_VARARGS, NULL },
	{ "ShowMenuForPlayer", pysamp_showmenuforplayer, METH_VARARGS, NULL },
	{ "HideMenuForPlayer", pysamp_hidemenuforplayer, METH_VARARGS, NULL },
	{ "IsValidMenu", pysamp_isvalidmenu, METH_VARARGS, NULL },
	{ "DisableMenu", pysamp_disablemenu, METH_VARARGS, NULL },
	{ "DisableMenuRow", pysamp_disablemenurow, METH_VARARGS, NULL },
	{ "GetPlayerMenu", pysamp_getplayermenu, METH_VARARGS, NULL },
	{ "TextDrawCreate", pysamp_textdrawcreate, METH_VARARGS, NULL },
	{ "TextDrawDestroy", pysamp_textdrawdestroy, METH_VARARGS, NULL },
	{ "TextDrawLetterSize", pysamp_textdrawlettersize, METH_VARARGS, NULL },
	{ "TextDrawTextSize", pysamp_textdrawtextsize, METH_VARARGS, NULL },
	{ "TextDrawAlignment", pysamp_textdrawalignment, METH_VARARGS, NULL },
	{ "TextDrawColor", pysamp_textdrawcolor, METH_VARARGS, NULL },
	{ "TextDrawUseBox", pysamp_textdrawusebox, METH_VARARGS, NULL },
	{ "TextDrawBoxColor", pysamp_textdrawboxcolor, METH_VARARGS, NULL },
	{ "TextDrawSetShadow", pysamp_textdrawsetshadow, METH_VARARGS, NULL },
	{ "TextDrawSetOutline", pysamp_textdrawsetoutline, METH_VARARGS, NULL },
	{ "TextDrawBackgroundColor", pysamp_textdrawbackgroundcolor, METH_VARARGS, NULL },
	{ "TextDrawFont", pysamp_textdrawfont, METH_VARARGS, NULL },
	{ "TextDrawSetProportional", pysamp_textdrawsetproportional, METH_VARARGS, NULL },
	{ "TextDrawSetSelectable", pysamp_textdrawsetselectable, METH_VARARGS, NULL },
	{ "TextDrawShowForPlayer", pysamp_textdrawshowforplayer, METH_VARARGS, NULL },
	{ "TextDrawHideForPlayer", pysamp_textdrawhideforplayer, METH_VARARGS, NULL },
	{ "TextDrawShowForAll", pysamp_textdrawshowforall, METH_VARARGS, NULL },
	{ "TextDrawHideForAll", pysamp_textdrawhideforall, METH_VARARGS, NULL },
	{ "TextDrawSetString", pysamp_textdrawsetstring, METH_VARARGS, NULL },
	{ "TextDrawSetPreviewModel", pysamp_textdrawsetpreviewmodel, METH_VARARGS, NULL },
	{ "TextDrawSetPreviewRot", pysamp_textdrawsetpreviewrot, METH_VARARGS, NULL },
	{ "TextDrawSetPreviewVehCol", pysamp_textdrawsetpreviewvehcol, METH_VARARGS, NULL },
	{ "SelectTextDraw", pysamp_selecttextdraw, METH_VARARGS, NULL },
	{ "CancelSelectTextDraw", pysamp_cancelselecttextdraw, METH_VARARGS, NULL },
	{ "GangZoneCreate", pysamp_gangzonecreate, METH_VARARGS, NULL },
	{ "GangZoneDestroy", pysamp_gangzonedestroy, METH_VARARGS, NULL },
	{ "GangZoneShowForPlayer", pysamp_gangzoneshowforplayer, METH_VARARGS, NULL },
	{ "GangZoneShowForAll", pysamp_gangzoneshowforall, METH_VARARGS, NULL },
	{ "GangZoneHideForPlayer", pysamp_gangzonehideforplayer, METH_VARARGS, NULL },
	{ "GangZoneHideForAll", pysamp_gangzonehideforall, METH_VARARGS, NULL },
	{ "GangZoneFlashForPlayer", pysamp_gangzoneflashforplayer, METH_VARARGS, NULL },
	{ "GangZoneFlashForAll", pysamp_gangzoneflashforall, METH_VARARGS, NULL },
	{ "GangZoneStopFlashForPlayer", pysamp_gangzonestopflashforplayer, METH_VARARGS, NULL },
	{ "GangZoneStopFlashForAll", pysamp_gangzonestopflashforall, METH_VARARGS, NULL },
	{ "ShowPlayerDialog", pysamp_showplayerdialog, METH_VARARGS, NULL },
	{ "gpci", pysamp_gpci, METH_VARARGS, NULL },
	{ "IsValidVehicle", pysamp_isvalidvehicle, METH_VARARGS, NULL },
	{ "GetVehicleDistanceFromPoint", pysamp_getvehicledistancefrompoint, METH_VARARGS, NULL },
	{ "CreateVehicle", pysamp_createvehicle, METH_VARARGS, NULL },
	{ "DestroyVehicle", pysamp_destroyvehicle, METH_VARARGS, NULL },
	{ "IsVehicleStreamedIn", pysamp_isvehiclestreamedin, METH_VARARGS, NULL },
	{ "GetVehiclePos", pysamp_getvehiclepos, METH_VARARGS, NULL },
	{ "SetVehiclePos", pysamp_setvehiclepos, METH_VARARGS, NULL },
	{ "GetVehicleZAngle", pysamp_getvehiclezangle, METH_VARARGS, NULL },
	{ "GetVehicleRotationQuat", pysamp_getvehiclerotationquat, METH_VARARGS, NULL },
	{ "SetVehicleZAngle", pysamp_setvehiclezangle, METH_VARARGS, NULL },
	{ "SetVehicleParamsForPlayer", pysamp_setvehicleparamsforplayer, METH_VARARGS, NULL },
	{ "ManualVehicleEngineAndLights", pysamp_manualvehicleengineandlights, METH_VARARGS, NULL },
	{ "SetVehicleParamsEx", pysamp_setvehicleparamsex, METH_VARARGS, NULL },
	{ "GetVehicleParamsEx", pysamp_getvehicleparamsex, METH_VARARGS, NULL },
	{ "GetVehicleParamsSirenState", pysamp_getvehicleparamssirenstate, METH_VARARGS, NULL },
	{ "SetVehicleParamsCarDoors", pysamp_setvehicleparamscardoors, METH_VARARGS, NULL },
	{ "GetVehicleParamsCarDoors", pysamp_getvehicleparamscardoors, METH_VARARGS, NULL },
	{ "SetVehicleParamsCarWindows", pysamp_setvehicleparamscarwindows, METH_VARARGS, NULL },
	{ "GetVehicleParamsCarWindows", pysamp_getvehicleparamscarwindows, METH_VARARGS, NULL },
	{ "SetVehicleToRespawn", pysamp_setvehicletorespawn, METH_VARARGS, NULL },
	{ "LinkVehicleToInterior", pysamp_linkvehicletointerior, METH_VARARGS, NULL },
	{ "AddVehicleComponent", pysamp_addvehiclecomponent, METH_VARARGS, NULL },
	{ "RemoveVehicleComponent", pysamp_removevehiclecomponent, METH_VARARGS, NULL },
	{ "ChangeVehicleColor", pysamp_changevehiclecolor, METH_VARARGS, NULL },
	{ "ChangeVehiclePaintjob", pysamp_changevehiclepaintjob, METH_VARARGS, NULL },
	{ "SetVehicleHealth", pysamp_setvehiclehealth, METH_VARARGS, NULL },
	{ "GetVehicleHealth", pysamp_getvehiclehealth, METH_VARARGS, NULL },
	{ "AttachTrailerToVehicle", pysamp_attachtrailertovehicle, METH_VARARGS, NULL },
	{ "DetachTrailerFromVehicle", pysamp_detachtrailerfromvehicle, METH_VARARGS, NULL },
	{ "IsTrailerAttachedToVehicle", pysamp_istrailerattachedtovehicle, METH_VARARGS, NULL },
	{ "GetVehicleTrailer", pysamp_getvehicletrailer, METH_VARARGS, NULL },
	{ "SetVehicleNumberPlate", pysamp_setvehiclenumberplate, METH_VARARGS, NULL },
	{ "GetVehicleModel", pysamp_getvehiclemodel, METH_VARARGS, NULL },
	{ "GetVehicleComponentInSlot", pysamp_getvehiclecomponentinslot, METH_VARARGS, NULL },
	{ "GetVehicleComponentType", pysamp_getvehiclecomponenttype, METH_VARARGS, NULL },
	{ "RepairVehicle", pysamp_repairvehicle, METH_VARARGS, NULL },
	{ "GetVehicleVelocity", pysamp_getvehiclevelocity, METH_VARARGS, NULL },
	{ "SetVehicleVelocity", pysamp_setvehiclevelocity, METH_VARARGS, NULL },
	{ "SetVehicleAngularVelocity", pysamp_setvehicleangularvelocity, METH_VARARGS, NULL },
	{ "GetVehicleDamageStatus", pysamp_getvehicledamagestatus, METH_VARARGS, NULL },
	{ "UpdateVehicleDamageStatus", pysamp_updatevehicledamagestatus, METH_VARARGS, NULL },
	{ "SetVehicleVirtualWorld", pysamp_setvehiclevirtualworld, METH_VARARGS, NULL },
	{ "GetVehicleVirtualWorld", pysamp_getvehiclevirtualworld, METH_VARARGS, NULL },
	{ "GetVehicleModelInfo", pysamp_getvehiclemodelinfo, METH_VARARGS, NULL },
	{ "Create3DTextLabel", pysamp_create3dtextlabel, METH_VARARGS, NULL },
	{ "Delete3DTextLabel", pysamp_delete3dtextlabel, METH_VARARGS, NULL },
	{ "Attach3DTextLabelToPlayer", pysamp_attach3dtextlabeltoplayer, METH_VARARGS, NULL },
	{ "Attach3DTextLabelToVehicle", pysamp_attach3dtextlabeltovehicle, METH_VARARGS, NULL },
	{ "Update3DTextLabelText", pysamp_update3dtextlabeltext, METH_VARARGS, NULL },
	{ "CreatePlayer3DTextLabel", pysamp_createplayer3dtextlabel, METH_VARARGS, NULL },
	{ "DeletePlayer3DTextLabel", pysamp_deleteplayer3dtextlabel, METH_VARARGS, NULL },
	{ "UpdatePlayer3DTextLabelText", pysamp_updateplayer3dtextlabeltext, METH_VARARGS, NULL },
	{ "SetTimer", pysamp_settimer, METH_VARARGS, NULL },
	{ "KillTimer", pysamp_killtimer, METH_VARARGS, NULL },
	{ "CallNativeFunction", pysamp_callnativefunction, METH_VARARGS, NULL },
	{ "config", (PyCFunction)pysamp_config, METH_VARARGS | METH_KEYWORDS, "Sets the specified config keyword arguments, returns the config as dict if called without arguments" },
	{ "RegisterCallback", pysamp_registercallback, METH_VARARGS, NULL },
	{ NULL, NULL, 0, NULL }
};

struct PyModuleDef PySAMPModule = {
	PyModuleDef_HEAD_INIT,
	.m_name = "samp",
	.m_doc = "PySAMP native functions",
	.m_size = -1,
	.m_methods = PySAMPMethods,
};
