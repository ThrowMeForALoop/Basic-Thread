#ifndef LOCKQUEUE_SOURCE_H
#define LOCKQUEUE_SOURCE_H
#include "Semaphore.h"
#include <vector>

using namespace std;
class LockQueue {
private:
	vector <int> mVector;
	Semaphore mSemaphore;
public:
	LockQueue();

	int push_back(const int& value);
	int pop_back (int& out);
};

#endif