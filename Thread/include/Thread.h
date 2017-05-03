#ifndef THREAD_SRC_H
#define THREAD_SRC_H
#include <pthread.h>

class Thread {
private:
	pthread_t mThreadId;
	bool isRunning;
public:
	Thread ();
	static void* threadExecute(void* arg);
	virtual void run() {};
	virtual void* join();
	virtual void start();
	virtual void cancel();
};
#endif