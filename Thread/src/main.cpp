#include <iostream>
#include <unistd.h>
#include <string.h>

#include "Worker.h"
#include "AnotherWorker.h"
#include "LockQueue.h"

using namespace std;

typedef struct {
	int length;
	char* data;
} TestStruct;

int main(int argc, char*argv[]) 
{
    LockQueue* lockQueue = new LockQueue();

    Worker produceWorker(lockQueue);
    produceWorker.start();

    AnotherWorker consumeWorker(lockQueue);
    consumeWorker.start();
 
    while (true) {
    	usleep(1000000);
    	//cout << "Main thread id: " << pthread_self()<< endl;
    }
    return 0;
}
