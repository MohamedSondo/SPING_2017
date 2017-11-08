#include<Windows.h>
#include<iostream>
using namespace std;

void clear_array_pointer(int *, int);
void clear_array_index(int[],int);
int main()
{
	__int64 ctr1 = 0, ctr2 = 0, freq = 0;
	int i = 0;
	
	const int size = 10000;
	int array[size];
	for (i = 0; i < size; i++)
		array[i] = i+1;
	int *p = array;
	if (QueryPerformanceCounter((LARGE_INTEGER*)&ctr1) != 0)
	{
		clear_array_pointer(p, size);
		//clear_array_index(array,size);
		QueryPerformanceCounter((LARGE_INTEGER*)&ctr2);
		cout << "Start Value: " << ctr1 << endl;
		cout << "End Value: " << ctr2 << endl;

		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
		cout << "QueryPerformanceCounter minimu resolution: 1/" << freq
			<< " Seconds." << endl;
		cout << size<<" elements need time: " << ((ctr2 - ctr1)*1.0 / freq) * 1000000
			<< "Microseconds." << endl;
	}
	else
	{
		DWORD dwError = GetLastError();
		cout << "Error value = " << dwError << endl;
	}
	
	return 0;
}