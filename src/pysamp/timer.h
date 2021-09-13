#ifndef PYTIMER_H
#define PYTIMER_H

#include <Python.h>
#include <deque>

#include "sampgdk.h"


class Timer
{
public:
	Timer(
		PyObject* function,
		PyObject* arguments,
		unsigned int interval,
		bool repeating
	);
	~Timer();
	static Timer* from_args(PyObject *args, PyObject *arguments);
	bool process(unsigned int current_tick);
	int get_id() { return id; };
	bool is_repeating() { return repeating; };
	bool is_pending_deletion() { return pending_deletion; };
	void set_pending_deletion() { this->pending_deletion = true; };

	static int last_timer_id;

private:
	int id;
	PyObject* function;
	PyObject* arguments;
	unsigned int interval;
	bool repeating;
	unsigned int last_call_tick;
	bool pending_deletion;
};


class TimerManager
{
public:
	TimerManager();
	~TimerManager() {};
	void add_timer(Timer& timer);
	void remove_timer(int id);
	void process_timers(unsigned int current_tick);
	void clear_timers();
	void enable() { disabled = false; };
	void disable() { disabled = true; };

private:
	std::deque<Timer> timers;
	bool disabled;
};

#endif
