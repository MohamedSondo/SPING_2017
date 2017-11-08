#include "clear_array_index.h"
#include <windows.h>
#include <iostream>
using namespace std;

int main()
{
	_int64 ctr1 = 0, ctr2 = 0, freq = 0;
	const int num = 100000;
	int i, a[num];

	for (i = 0; i < num; i++)
	{
		a[i] = i + 1;
	}

	if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0)
	{
		clear_array_index(a, num);
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);

		cout << "Start Value:" << ctr1 << endl;
		cout << "End Value:" << ctr2 << endl;

		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

		cout << "QueryPerformanceCounter minimum resolution: 1/" << freq << "Seconds," << endl;
		cout << "Clear Array of 100000 needs:" << ((ctr2 - ctr1)* 1.0 / freq) * 1000000 << "Microseconds." << endl;
	}
	else
	{
		DWORD dwError = GetLastError();
		cout << "Error value" << dwError << endl;
	}
	system("PAUSE");
	return 0;
}