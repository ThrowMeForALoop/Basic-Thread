#include "Worker.h"
#include <unistd.h>
//#include <sstream.h>
#include <string.h>
#include "AnotherWorker.h"

Worker::Worker(LockQueue* lockQueue) {
	mQueue = lockQueue;
}

void Worker::run() {
	if (mQueue != NULL) {
		for (int i = 0 ; i < 10; i ++) {
			usleep(1000000);
			mQueue->push_back(i);
		}
	}

	while (true) {
		usleep(1000000);
		std::cout << "Worker thread loop" << endl;
	}
}