#ifndef WORKER_SRC_HPP
#define WORKER_SRC_HPP

#include <iostream>
#include "Thread.h"
#include "LockQueue.h"
class Worker: public Thread  {
private:
	LockQueue* mQueue;
public:
	Worker(LockQueue* lockQueue);
	void run();
};


#endif