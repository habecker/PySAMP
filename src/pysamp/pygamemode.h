#ifndef PYGAMEMODE_H
#define PYGAMEMODE_H

#include <string>
#include <unordered_map>
#include <Python.h>

#ifdef DEBUG
	#define PY_DEBUG
#endif

#ifdef WIN32
	#include <direct.h>
	#define GETCWD _getcwd
#else
	#include <unistd.h>
	#define GETCWD getcwd
#endif

#include "sampgdk.h"
#include "samp.h"
#include "callbacks.h"


class PyGamemode
{
private:	
	std::string _getcwd();
	PyObject *module = nullptr;
	bool initialized = false;
	bool loaded = false;
	bool disabled = false;
	std::unordered_map<std::string, PyObject*> config;
	CallbacksManager *callbacks;
	PyThreadState *_save;  // The GIL
	// Thread-lock-stack - don't call Py_(UN)BLOCK_THREADS several times in a row
	int threadLockDepth;

public:
	PyGamemode(const char* path, CallbacksManager* callbacks);
	~PyGamemode();
	void load();
	void reload();
	void unload();
	bool isLoaded();
	void disable();
	bool isEnabled();
	void blockThreads();
	void unblockThreads();
	int callback(const std::string name , PyObject* pArgs, cell* retval, bool* stop);
	PyObject* pyConfig(PyObject *self, PyObject *args, PyObject *kwargs);
	std::unordered_map<std::string, PyObject*> getConfig() { return this->config; };
	static const std::unordered_map<std::string, int> constants;
};

#endif
