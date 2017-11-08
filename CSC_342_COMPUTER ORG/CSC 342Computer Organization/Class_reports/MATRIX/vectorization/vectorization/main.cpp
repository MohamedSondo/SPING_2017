#include <tchar.h>
#include <Windows.h>
#include <iostream>

using namespace std;

void multiplication(float *matrix, float *inVector, float *outVector, int size);
void matrixMultiplication(float *matrix, float *inVector, float *outVector);
void assemblyMultiplication(float *matrix, float *inVector, float *outVector);

int main() {
	float matrix[256];
	float inVector[64];
	float outVector[64];
	int size = 64;
	_int64 ctr1 = 0, ctr2 = 0, freq = 0;
	int acc = 0, i = 0;

	for (int i = 0; i < 256; i++) {
		matrix[i] = i;
		if (i < 16) {
			inVector[i] = 40.0 - i;
		}
	}
	if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0)
	{
		// Code segment is being timed.
		multiplication (matrix,  inVector, outVector, size);
		// Finish timing the code.
		QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);
		std::cout << "start" << ctr1 << std::endl;
		std::cout << "end" << ctr2 << std::endl;
		QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
		std::cout << "ctr1 - ctr2 = " << ctr1 - ctr2 << endl;
		std::cout << "QueryPerformanceCounter minimum resolution : 1/ " << freq << "seconds" << std::endl;
		std::cout << "Function takes time: " << ((ctr2 - ctr1) * 1.0 / freq) * 1000000 << " Microseconds." << std::endl;
	}
	else
	{
		DWORD dwError = GetLastError();
		std::cout << "Error vaflue = " << dwError << std::endl;
	}
	system("PAUSE");

	return 0;
}