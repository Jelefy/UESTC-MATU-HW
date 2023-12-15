#include "thread_hdr.h"

void add_ready_thread(thread* ready_thread)
{
    ready_queue.push_back(ready_thread);
}

void schedule()
{
	if (current_thread != NULL) {
        ready_queue.push_back(current_thread);
        current_thread = NULL;
    }
	if(ready_queue.size()) {
    	current_thread = ready_queue.front();
        ready_queue.pop_front();
    }
}
