#include "logprintf.h"


typedef struct
{
	PyObject_HEAD
	std::string *line_buffer;
} LogPrintfObject;

static PyObject* LogPrintf_new(PyTypeObject *type, PyObject *args, PyObject *kwds)
{
	LogPrintfObject *self;
	self = (LogPrintfObject*)type->tp_alloc(type, 0);

	if(self != NULL)
	{
		self->line_buffer = new std::string();
	}

	return (PyObject*)self;
}

static void LogPrintf_dealloc(LogPrintfObject *self)
{
	delete self->line_buffer;
	Py_TYPE(self)->tp_free((PyObject *) self);
}

static PyObject* LogPrintf_write(LogPrintfObject *self, PyObject *args)
{
	const char *text = NULL;

	if(!PyArg_ParseTuple(args, "s", &text))
		return NULL;

	std::stringstream text_stream(*(self->line_buffer) + text);
	std::string line, text_stream_string = text_stream.str();
	unsigned int num_lines = std::count(
		text_stream_string.begin(),
		text_stream_string.end(),
		'\n'
	), printed_len = 0;

	for(
		unsigned int current_line = 0;
		current_line < num_lines
		&& std::getline(text_stream, line);
		++current_line
	)
	{
		sampgdk::logprintf(line.c_str());
		printed_len += line.length();
	}

	std::getline(text_stream, *(self->line_buffer));

	return PyLong_FromUnsignedLong(printed_len);
}

static PyObject* LogPrintf_flush(LogPrintfObject *self, PyObject *args)
{
	if(self->line_buffer->length())
	{
		sampgdk::logprintf(self->line_buffer->c_str());
		self->line_buffer->clear();
	}
	Py_RETURN_NONE;
}

static PyMethodDef LogPrintf_methods[] = {
	{"write", (PyCFunction)LogPrintf_write, METH_VARARGS, "Writes to server_log.txt - assigned to sys.std{out,err}.write at startup."},
	{"flush", (PyCFunction)LogPrintf_flush, METH_VARARGS, "Flushes server_log.txt writes - empties internal line buffer into server_log.txt."},
	{NULL},
};

PyTypeObject LogPrintfType = {
	PyVarObject_HEAD_INIT(NULL, 0)
	.tp_name = "samp.LogPrintf",
	.tp_basicsize = sizeof(LogPrintfObject),
	.tp_itemsize = 0,
	.tp_dealloc = (destructor)LogPrintf_dealloc,
	.tp_flags = Py_TPFLAGS_DEFAULT,
	.tp_doc = "Standard output to logprintf adapter",
	.tp_methods = LogPrintf_methods,
	.tp_new = LogPrintf_new,
};
