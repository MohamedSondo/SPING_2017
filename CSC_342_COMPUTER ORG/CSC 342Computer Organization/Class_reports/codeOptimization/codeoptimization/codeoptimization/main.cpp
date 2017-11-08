#include <tchar.h>
#include <windows.h>
#include <iostream>
void ClearUsingIndex(int Array[], int size);

int main() {
	__int64 ctr1 = 0, ctr2 = 0, freq = 0;
	int acc = 0, i = 0;
	const int size = 100000;
	int Array[size];
	for (int i = 0; i < size; i++) {
		Array[i] = i;
	}
	// Start timing the code.
	if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0)
	{
		// Code segment is being timed.
	ClearUsingIndex(Array, size);
		// Finish timing the code.
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);
		std::cout << "start" << ctr1 << std::endl;
		std::cout << "end" << ctr2 << std::endl;
		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

		std::cout << "QueryPerformanceCounter minimum resolution : 1/ " << freq << "seconds" << std::endl;
		std::cout << "time took to clean Array of : " << size<< " elements : "<< ((ctr2 - ctr1) * 1.0 / freq) * 1000000 << " Microseconds." << std::endl;
	}
	else
	{
		DWORD dwError = GetLastError();
		std::cout << "Error vaflue = " << dwError << std::endl;
	}
	system("PAUSE");

	return 0;
}