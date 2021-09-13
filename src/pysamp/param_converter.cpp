#include "param_converter.h"


cell* ParamConverter::from_tuple(PyObject* tuple)
{
	Py_ssize_t len_tuple = PyTuple_Size(tuple);
	cell *amx_params = new cell[len_tuple];
	PyObject* current_argument = NULL;

	amx_params[0] = (len_tuple - 1) * sizeof(cell);

	for(Py_ssize_t i = 1; i < len_tuple; i++)
	{
		current_argument = PyTuple_GetItem(tuple, i);

		if(PyBool_Check(current_argument))
		{
			amx_params[i] = PyObject_IsTrue(current_argument);
		}
		else if(PyLong_Check(current_argument))
		{
			amx_params[i] = PyLong_AsLong(current_argument);
		}
		else if(PyFloat_Check(current_argument))
		{
			float value = PyFloat_AsDouble(current_argument);
			amx_params[i] = amx_ftoc(value);
		}
		else
		{
			char *repr;
			size_t size;
			FILE *bytes_io = open_memstream(&repr, &size);
			PyObject_Print(current_argument, bytes_io, 0);
			fclose(bytes_io);
			PyErr_Format(
				PyExc_TypeError,
				"CallNativeFunction() could not convert argument %s in position %d",
				repr,
				i
			);
			free(repr);
			return NULL;
		}
	}

	return amx_params;
}

PyObject* ParamConverter::to_tuple(cell* params, const std::string format, AMX* amx)
{
	int number_of_arguments = format.length();

	if(number_of_arguments != params[0] / sizeof(cell))
	{
		PyErr_Format(
			PyExc_ValueError,
			"Invalid argument count for callback: expected %d, got %d",
			params[0] / sizeof(cell),
			number_of_arguments
		);
		return NULL;
	}

	PyObject *arguments = PyTuple_New(number_of_arguments);

	for(int i = 0; i < number_of_arguments; ++i)
	{
		const char type = format.at(i);
		cell param = params[i + 1];
		PyObject *argument;

		switch(type)
		{
			case 'i':
				argument = PyLong_FromLong((int) param);
				break;
			case 'O':
				argument = param ? Py_True : Py_False;
				break;
			case 'f':
				argument = PyFloat_FromDouble((double) amx_ctof(param));
				break;
			case 'y':
			{
				int length = -1;
				char *string_value = NULL;
				cell *phys_addr = NULL;

				if(amx_GetAddr(amx, param, &phys_addr) != AMX_ERR_NONE)
				{
					argument = Py_None;
					break;
				}

				amx_StrLen(phys_addr, &length);

				if(length == -1)
				{
					argument = Py_None;
					break;
				}

				string_value = (char *)malloc((length + 1) * sizeof(char));

				if(
					amx_GetString(
						string_value,
						phys_addr,
						0,
						length + 1
					) != AMX_ERR_NONE
					|| string_value == NULL
				)
				{
					free(string_value);
					argument = Py_None;
					break;
				}

				argument = PyUnicode_Decode(
					string_value,
					length,
					PySAMP::getEncoding().c_str(),
					"strict"
				);
				free(string_value);
				break;
			}
		}

		PyTuple_SetItem(arguments, i, argument);
	}

	return arguments;
}
