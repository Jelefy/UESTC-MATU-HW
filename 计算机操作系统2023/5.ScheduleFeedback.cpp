#include "thread_hdr.h"

unsigned int time_ticks[2];
unsigned int time_interval;

void add_ready_thread(thread* ready_thread)
{
    ready_thread->clock_times = 0;
    ready_thread->max_clock_times = 0;
    first_ready_queue.push_back(ready_thread);
}

void schedule() {
    if (current_thread != &idle_thread) {
        return;
    }
    if (first_ready_queue.size()) {
        current_thread = first_ready_queue.front();
        first_ready_queue.pop_front();
    }
    else if (second_ready_queue.size()) {
        current_thread = second_ready_queue.front();
        second_ready_queue.pop_front();
    }
}

void current_thread_finished()
{
    if (current_thread == &idle_thread) {
        return;
    }
    current_thread = &idle_thread;
    schedule();
}

void current_thread_blocked()
{
    if (current_thread == &idle_thread) {
        return;
    }
    current_thread->clock_times = 0;
    current_thread->max_clock_times = 0;
    blocked_queue.push_back(current_thread);
    current_thread = &idle_thread;
    schedule();
}

void notify()
{
	if (blocked_queue.empty()) {
        return;
    }
    first_ready_queue.push_back(blocked_queue.front());
    blocked_queue.pop_front();
}

void notify_all()
{
    if (blocked_queue.empty()) {
        return;
    }
    first_ready_queue.insert(first_ready_queue.end(), blocked_queue.begin(), blocked_queue.end());
    blocked_queue.clear();
}

void on_clock()
{
    if (current_thread == &idle_thread) {
        schedule();
        return;
    }
    if (first_ready_queue.size() && current_thread->max_clock_times == 1) {
        current_thread->clock_times = 0;
        second_ready_queue.push_back(current_thread);
        current_thread = first_ready_queue.front();
        first_ready_queue.pop_front();
        return;
    }
    current_thread->clock_times += time_interval;
    if (current_thread->clock_times >= time_ticks[current_thread->max_clock_times]) {
        current_thread->max_clock_times = 1;
        current_thread->clock_times = 0;
        second_ready_queue.push_back(current_thread);
        current_thread = &idle_thread;
        schedule();
    }
}

void set_first_time_ticks(unsigned int ticks)
{
    time_ticks[0] = ticks;
}

void set_second_time_ticks(unsigned int ticks)
{
    time_ticks[1] = ticks;
}

void set_time_interval(unsigned int interval)
{
    time_interval = interval;
}