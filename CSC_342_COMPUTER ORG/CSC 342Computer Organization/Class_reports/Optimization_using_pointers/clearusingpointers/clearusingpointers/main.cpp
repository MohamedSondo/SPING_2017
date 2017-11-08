#include <tchar.h>
#include <windows.h>
#include <iostream>

void ClearUsingPointers(int*, int);
int main() {

	__int64 ctr1 = 0, ctr2 = 0, freq = 0;
	int acc = 0, i = 0;
	const int size = 10000;
	int Array[size];
	for (int i = 0; i < size; i++) {
		Array[i] = i;
	}



	// Start timing the code.

	if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0)
	{
		// Code segment is being timed.
		//ClearUsingIndex(Array, size);
		ClearUsingPointers(Array, size);
		//for (i = 0; i < 10000; i++) acc++;
		// Finish timing the code.
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);
		std::cout << "start" << ctr1 << std::endl;
		std::cout << "end" << ctr2 << std::endl;
		//Console::WriteLine("Start Value: {0}",ctr1.ToString());
		//Console::WriteLine("End Value: {0}",ctr2.ToString());

		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

		std::cout << "QueryPerformanceCounter minimum resolution : 1/ " << freq << "seconds" << std::endl;
		//Console::WriteLine(S"QueryPerformanceCounter minimum resolution: 1/{0} Seconds.",freq.ToString());
		// In Visual Studio 2005, this line should be changed to: Console::WriteLine("QueryPerformanceCounter minimum resolution: 1/{0} Seconds.",freq.ToString());

		std::cout << "100 Increment time: " << ((ctr2 - ctr1) * 1.0 / freq) * 1000000 << " Microseconds." << std::endl;
		//Console::WriteLine("100 Increment time: {0} seconds.",((ctr2 - ctr1) * 1.0 / freq).ToString());
	}
	else
	{
		DWORD dwError = GetLastError();
		std::cout << "Error vaflue = " << dwError << std::endl;
		//Console::WriteLine(S"Error value = {0}",dwError.ToString());// In Visual Studio 2005, this line should be changed to: Console::WriteLine("Error value = {0}",dwError.ToString());
	}


	// Make the console window wait.
	system("PAUSE");

	return 0;
}
