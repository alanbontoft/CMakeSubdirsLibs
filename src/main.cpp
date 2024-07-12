#include <iostream>

#include "MathClass.h"

using namespace std;

void* threadProc(void* arg)
{
	return NULL;
}


int main(int argc, char* argv[])
{
	MathClass *pMath;
	cout << "Hello CMake" << std::endl;
	cout << argc - 1 << " params passed" << std::endl;

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

	pMath = new MathClass(5);

	cout << "pMath initial value: " << pMath->value() << endl;

	for (int i=0; i < 5; i++) pMath->inc();

	cout << "pMath final value: " << pMath->value() << endl;

	return 0;
}

