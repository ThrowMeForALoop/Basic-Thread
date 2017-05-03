#include "Thread.h"
#include <iostream>
Thread::Thread() {
	
}

void Thread::start() {
	int result = pthread_create(&mThreadId, NULL, threadExecute, this);
	isRunning = (result == 0? true:false) ;
}

void* Thread::threadExecute(void* arg) {
	Thread* thisThread = static_cast<Thread*>(arg);
	thisThread->run();
}

void* Thread::join() {
	void* returnVal = NULL;

	if (isRunning) 
			pthread_join(mThreadId, &returnVal);
	return returnVal;
}

void Thread::cancel() {
	pthread_cancel(mThreadId);
	isRunning = false;
}