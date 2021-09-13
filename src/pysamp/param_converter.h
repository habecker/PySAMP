#ifndef PARAMCONVERTER_H
#define PARAMCONVERTER_H

#include <string>
#include <Python.h>
#include "sampgdk.h"
#include "pysamp.h"


class ParamConverter
{
public:
	cell* from_tuple(PyObject* tuple);
	PyObject* to_tuple(cell* params, const std::string format, AMX* amx);
};

#endif
