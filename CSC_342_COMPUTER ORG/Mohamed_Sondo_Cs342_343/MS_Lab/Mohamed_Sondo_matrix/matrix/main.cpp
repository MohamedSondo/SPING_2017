#include "matrix_multiplication.h"
#include <Windows.h>
#include <smmintrin.h>
#include <iostream>
using namespace std;

int main()
{
	_int64 ctr1 = 0, ctr2 = 0, freq = 0;
	static const int size = 512;
	static float Arr1[size][size], Arr2[size][size], Arr3[size][size];

	// initialize arrays
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			Arr1[i][j] = 0.0;
			Arr2[i][j] = 0.0;
			Arr3[i][j] = 0.0;
		}
	}

	if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0)
	{
		matrix_multiplication(Arr1, Arr2, Arr3);		// call function
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);

		cout << "Start Value:" << ctr1 << endl;
		cout << "End Value:" << ctr2 << endl;

		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

		cout << "QueryPerformanceCounter minimum resolution: 1/" << freq << "Seconds," << endl;
		cout << size << "x" << size << " Maxtrix Multiplication: " << ((ctr2 - ctr1)* 1.0 / freq) * 1000000 << "Microseconds." << endl;
	}
	else
	{
		DWORD dwError = GetLastError();
		cout << "Error value" << dwError << endl;
	}
	system("PAUSE");

	return 0;
}

