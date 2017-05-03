#include "LockQueue.h"	
#include <iostream>


LockQueue::LockQueue() {

}

int LockQueue::push_back(const int& value) {
	int result = 0;
	mSemaphore.lock();
	mVector.push_back(value);
    std::cout << "Push to queue value " << value << std::endl;

	mSemaphore.signal();
	mSemaphore.unlock();
	return result;
}

int LockQueue::pop_back(int& out) {
	int result = 0;
	mSemaphore.lock();

	if (mVector.empty()) {
		result = mSemaphore.timeWait(100);
	}

	if (result ==0)  {
		out = mVector.back();
		mVector.pop_back();
		std::cout << "Pop from queue value " << out << std::endl;
	} else 
		std::cout << "Queue empty" << std::endl;

	mSemaphore.unlock();
	return result;
}