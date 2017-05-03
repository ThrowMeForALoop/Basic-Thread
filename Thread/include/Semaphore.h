#ifndef SEMAPHORE_SRC_HPP
#define SEMAPHORE_SRC_HPP
#include "Mutex.h"
#include <sys/time.h>

class Semaphore: public Mutex {
private:
	pthread_cond_t mConditionVar;
public:
	Semaphore();
	virtual ~Semaphore();
	int wait();
	int signal();
	int timeWait(const int timeOffsetInMs);

	void timespec_add(const int timeOffsetInMs, struct timespec* out);
};
#endif