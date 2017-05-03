#ifndef MUTEX_SRC_HPP
#define MUTEX_SRC_HPP
#include <pthread.h>
class Mutex {
protected:
	pthread_mutex_t mMutex;
public:
	Mutex();
	virtual ~Mutex();
	virtual int lock();
	virtual int unlock();
};
#endif