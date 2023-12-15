#include "thread_hdr.h"

void add_ready_thread(thread* ready_thread)
{
    ready_thread->clock_times = 0;
    ready_queue.push_back(ready_thread);
}

void schedule()
{
	if (current_thread != &idle_thread) {
        current_thread->clock_times = 0;
        ready_queue.push_back(current_thread);
        current_thread = &idle_thread;
    }
	if (ready_queue.size()) {
		current_thread = ready_queue.front();
        ready_queue.pop_front();
    }
}

void current_thread_finished()
{
	if(current_thread != &idle_thread) {
		current_thread = &idle_thread;
		schedule();
	}
}

void current_thread_blocked()
{
	if (current_thread != &idle_thread) {
        current_thread->clock_times = 0;
        blocked_queue.push_back(current_thread);
        current_thread = &idle_thread;
        schedule();
    }
}

void notify()
{
	if (blocked_queue.size()) {
        ready_queue.push_back(blocked_queue.front());
        blocked_queue.pop_front();
    }
}

void notify_all()
{
    ready_queue.insert(ready_queue.end(), blocked_queue.begin(), blocked_queue.end());
    blocked_queue.clear();
}

unsigned int time_ticks;
unsigned int time_interval;

void on_clock()
{
	if (current_thread == &idle_thread) {
        schedule();
        return;
    }
    current_thread->clock_times += time_interval;
	if (current_thread->clock_times >= time_ticks) {
        schedule();
    }
}

void set_time_ticks(unsigned int ticks)
{
    time_ticks = ticks;
}

void set_time_interval(unsigned int interval)
{
    time_interval = interval;
}