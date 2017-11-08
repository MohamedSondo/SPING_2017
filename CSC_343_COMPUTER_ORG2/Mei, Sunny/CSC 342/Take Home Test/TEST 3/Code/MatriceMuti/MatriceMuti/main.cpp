#include <windows.h>
#include <iostream>
#include <xmmintrin.h>
using namespace std;
//const int n = 2;
//const int n = 4;
//const int n = 8;
//const int n = 16;
//const int n = 32;
//const int n = 64;
//const int n = 128;
const int n = 256;
//const int n = 512;
void MutiMat(float a[][n], float b[][n], float c[][n]);
float a[n][n], b[n][n], result[n][n];
int main()
{
	_int64 ctr1 = 0, ctr2 = 0, freq = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			a[i][j] = 1.0f;
			b[i][j] = 1.0f;
			result[i][j] = 0.0f;
		}
	}
	if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1) != 0)
	{
		
			MutiMat(a, b, result);
			QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);
			cout << "Start value: " << ctr1 << endl;
			cout << "End value: " << ctr2 << endl;
			QueryPerformanceFrequency((LARGE_INTEGER *)&freq);
			cout << "QueryPerformanceCounter minimum resoluton (ms) : " << freq <<
				endl;
			cout << "Step size :" << (ctr2 - ctr1) << endl;
			cout << n << " x " << n << " Increment time in ms: " << (ctr2 - ctr1) * 1000.0 /
				freq << endl;
		
	}
	else
	{
		DWORD dwError = GetLastError();
		cout << "Error Value = " << dwError << endl;
	}
	system("PAUSE");
	return 0;
}

void MutiMat(float a[][n], float b[][n], float result[][n]) {
	//#pragma loop(hint_parallel[n])
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				result[i][k] += a[i][k] * b[k][j];
			}
		}
	}
}

