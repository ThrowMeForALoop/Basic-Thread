#include "Semaphore.h"
#include <iostream>
#include <errno.h>
using namespace std;

Semaphore::Semaphore() {
	int result = pthread_cond_init(&mConditionVar, NULL);
}

Semaphore::~Semaphore() {
	pthread_cond_destroy(&mConditionVar);
}

int Semaphore::wait () {
	int result = pthread_cond_wait(&mConditionVar, &mMutex);
	return result;
}

int Semaphore:: timeWait(const int timeOffsetInMs) {
	struct timespec timetoExpire;
	clock_gettime(CLOCK_REALTIME, &timetoExpire);
	timespec_add(timeOffsetInMs, &timetoExpire);

	int result = pthread_cond_timedwait(&mConditionVar, &mMutex, &timetoExpire);
	// if (result == ETIMEDOUT) {
	// 	std::cout << "Wait time out " << result << endl;
	// }

	return result;
}

int Semaphore::signal() {
	int result = pthread_cond_signal(&mConditionVar);
	return result;
}

void Semaphore::timespec_add(const int timeOffsetInMs, struct timespec* out) {
	time_t sec = out->tv_sec + timeOffsetInMs / 1000;
    long nsec = out->tv_nsec + timeOffsetInMs % 1000;

    sec += nsec / 1000000000L;
    nsec = nsec % 1000000000L;

    out->tv_sec = sec;
    out->tv_nsec = nsec;
}
