#include <iostream>
#include <pthread.h>
#include <time.h>

#include "MathClass.h"

using namespace std;

static timespec time1 = {0};
static timespec time2 = {0};

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
	
void* threadProc(void* arg)
{
	

	for (int i=0; i < 10; i++)
	{
		pthread_mutex_lock(&mutex);
		cout << "Thread: " << i << endl;
		pthread_mutex_unlock(&mutex);
		nanosleep(&time1, NULL);
	}

	cout << "Thread done" << endl;
	
	return NULL;
}


int main(int argc, char* argv[])
{
	MathClass *pMath;
	pthread_t thread;
	cout << "Hello CMake" << std::endl;
	cout << argc - 1 << " params passed" << std::endl;

	time1.tv_nsec = 500000000L;
	time2.tv_nsec = 250000000L;

	if (argc > 2)
	{
		int total = 0;

		for (int i=1; i < argc; i++)
		{
			total += atoi(argv[i]);
			cout << argv[i];

			if (i == (argc - 1))
				cout <<  " = " << total << endl;
			else
				cout << " + ";
		}
	}

	pthread_create(&thread, NULL, &threadProc, NULL);

	pMath = new MathClass(5);

	pthread_mutex_lock(&mutex);
	cout << "pMath initial value: " << pMath->value() << endl << "Waiting for calculation..." << endl;


	pthread_mutex_unlock(&mutex);

	for (int i=0; i < 5; i++)
	{
		pMath->inc();
		nanosleep(&time2, NULL);
	} 

	cout << "pMath final value: " << pMath->value() << endl;

	pthread_join(thread, NULL);

	return 0;
}

