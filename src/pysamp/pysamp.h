#ifndef PYSAMP_H
#define PYSAMP_H

#if PY_TEST == 0
	#define PYTHON_PATH "python"
#else
	#ifdef WIN32
		#define PYTHON_PATH "python\\test"
	#else
		#define PYTHON_PATH "python/test"
	#endif
#endif


#include "timer.h"
#include "callbacks.h"
#include "param_converter.h"


class PyGamemode;
class ParamConverter;

class PySAMP
{
private:
	static PyGamemode* gamemode;
	static TimerManager* timer_manager;
	static CallbacksManager* callbacks;
	static ParamConverter* param_converter;
public:
	static void load();
	static void reload();
	static void unload();
	static void disable();
	static bool isInitialized();
	static bool isLoaded();
	static bool isEnabled();
	static void addTimer(Timer& timer);
	static void removeTimer(int id);
	static void processTick(unsigned int currentTick);
	static int callback(const std::string name);
	static int callback(const std::string name, PyObject* pArgs);
	static int callback(const std::string name, PyObject* pArgs, cell* retval, bool* stop);
	static bool onPlayerCommandText(int playerid, const char* cmdtext);
	static std::string getEncoding();
	static void registerCallback(const std::string name, const std::string format);
	static std::string* getCallbackFormat(const std::string callback_name);
	static int getConstant(std::string);
	static PyObject* pyConfig(PyObject *self, PyObject *args, PyObject *kwargs);
	static PyObject* amxParamsToTuple(AMX *amx, const std::string callback_name, cell *params);
	static cell* tupleToAmxParams(PyObject* tuple);
};



#endif // PYSAMP_H
