#ifndef ANOTHERWORKER_SRC_HPP
#define ANOTHERWORKER_SRC_HPP
#include "Thread.h"
#include <iostream>
#include <unistd.h>
#include "LockQueue.h"

class AnotherWorker: public Thread {
public:
	AnotherWorker(LockQueue* lockQueue) {
		mQueue = lockQueue;
	}

	void run () {
		int poppedValue;
		while (mQueue) {
			mQueue->pop_back(poppedValue);
			usleep(100000);
		}	
	}
private:
	LockQueue* mQueue;
};
#endif