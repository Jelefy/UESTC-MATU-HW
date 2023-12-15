#include "thread_hdr.h"

void add_ready_thread(thread* ready_thread)
{
	ready_queue.push_back(ready_thread);
}

void schedule()
{
	if (current_thread != &idle_thread) {
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
    current_thread = &idle_thread;
    schedule();
}