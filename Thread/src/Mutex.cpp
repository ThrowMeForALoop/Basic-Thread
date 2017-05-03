#include "Mutex.h"

Mutex::Mutex() {
	int result = pthread_mutex_init(&mMutex, NULL);
}

Mutex::~Mutex() {
	pthread_mutex_destroy(&mMutex);
}

int Mutex::lock() {
	int result = pthread_mutex_lock(&mMutex);
	return result;
}

int Mutex::unlock() {
	int result = pthread_mutex_unlock(&mMutex);
	return result;
}

