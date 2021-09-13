#include "timer.h"


int Timer::last_timer_id;

Timer::Timer(
	PyObject* function,
	PyObject* arguments,
	unsigned int interval,
	bool repeating
) :
	function(function),
	arguments(arguments),
	interval(interval),
	repeating(repeating),
	pending_deletion(false)
{
	id = ++last_timer_id;
	last_call_tick = GetTickCount();
	Py_INCREF(function);
	Py_XINCREF(arguments);
}

Timer::~Timer()
{
	Py_DECREF(function);
	Py_XDECREF(arguments);
}

Timer* Timer::from_args(PyObject *args, PyObject *arguments)
{
	PyObject* function;
	unsigned int interval;
	bool repeating;

	if(!PyArg_ParseTuple(args, "OIb:SetTimer", &function, &interval, &repeating))
		return NULL;

	if(!PyCallable_Check(function))
	{
		PyErr_SetString(PyExc_TypeError, "SetTimer() 'function' argument must be callable (pos 1)");
		return NULL;
	}

	return new Timer(
		function,
		arguments,
		interval,
		repeating
	);
}

bool Timer::process(unsigned int current_tick)
{
	if((last_call_tick + interval) > current_tick)
		return false;

	last_call_tick = current_tick;
	PyObject_CallObject(function, arguments);

	if(PyErr_Occurred() != NULL)
	{
		PyErr_Print();
		return false;
	}

	return true;
}


TimerManager::TimerManager()
: disabled(false)
{
	Timer::last_timer_id = -1;
}

void TimerManager::add_timer(Timer& timer)
{
	timers.push_back(timer);
}

void TimerManager::remove_timer(int id)
{
	for(auto timer = timers.begin(); timer != timers.end(); ++timer)
	{
		if(timer->get_id() != id)
			continue;

		timer->set_pending_deletion();
		break;
	}
}

void TimerManager::process_timers(unsigned int current_tick)
{
	if(disabled)
		return;

	for(auto timer = timers.begin(); timer != timers.end();)
	{
		if(timer->is_pending_deletion())
		{
			++timer;
			continue;
		}

		int id = timer->get_id();
		bool repeating = timer->is_repeating();

		if(
			timer->process(current_tick)
			&& !repeating
			&& !timer->is_pending_deletion()
		)
		{
			timer = timers.erase(timer);
			continue;
		}

		++timer;
	}

	for(auto timer = timers.begin(); timer != timers.end();)
	{
		if(timer->is_pending_deletion())
			timer = timers.erase(timer);
		else
			++timer;
	}
}

void TimerManager::clear_timers()
{
	for(auto timer = timers.begin(); timer != timers.end();)
		timer = timers.erase(timer);
}
