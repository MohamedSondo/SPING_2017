#include <stdio.h> 
#include <windows.h> 
#include <iostream>
using namespace std;
int DotProduct(int[],int[], int);

int main() {
	const int size = 10;
	static int Array1[size];
	static int Array2[size];
	__int64 ctr1 = 0, ctr2 = 0, freq = 0;
	int acc = 0, i = 0;
	int x;// just here to call cin at the end to stop the debug box from going away
	int sum;
		  //   Start timing the code. 
	if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0)
	{
		// Code segment is being timed.  
		sum = DotProduct(Array1, Array2, size);
		// Finish timing the code. 
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);

		printf("Start Value: %d\n", ctr1);
		printf("End   Value: %d\n", ctr2);

		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

		printf("QueryPerformanceCounter minimum resolution: 1/%d Seconds.\n", freq);
		printf("ctr2 - ctr1: %d\n counts.", (ctr2 - ctr1));
		printf("Increments time in millisec: %f milliseconds. \n", ((ctr2 - ctr1) * 1000.0 / freq));
	}
	else
	{
		unsigned int dwError = GetLastError();
		printf("Error code: %d", dwError);
	}
	cin >> x;
	return 0;
}