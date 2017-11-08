#include<Windows.h>
#include<iostream>
using namespace std;

int main()
{
	__int64 ctr1 = 0, ctr2 = 0, freq = 0;
	int acc = 0, i = 0;
	if (QueryPerformanceCounter((LARGE_INTEGER*)&ctr1) != 0)
	{
		
		QueryPerformanceCounter((LARGE_INTEGER*)&ctr2);
		cout << "Start Value: " << ctr1 << endl;
		cout << "End Value: " << ctr2 << endl;

		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
		cout << "QueryPerformanceCounter minimu resolution: 1/" << freq
			<< " Seconds." << endl;
		cout << "100 Increment time: " << ((ctr2 - ctr1)*1.0 / freq) * 1000000
			<< "Microseconds." << endl;
	}
	else
	{
		DWORD dwError = GetLastError();
		cout << "Error value = " << dwError << endl;
	}
	system("PAUSE");
	return 0;
}