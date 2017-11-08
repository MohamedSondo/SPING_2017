#include <windows.h>
#include <iostream>
#include <xmmintrin.h>
#include <smmintrin.h>
using namespace std;
const int n = 2;
//const int n = 4;
//const int n = 8;
//const int n = 16;
//const int n = 32;
//const int n = 64;
//const int n = 128;
//const int n = 256;
//const int n = 512;
void MutiMat(float a[][n], float b[][n], float c[][n]);
void DPPSMutiMat(float A[][n], float B[][n], float Result[][n], int n);
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
		//MutiMat(a, b, result);
		DPPSMutiMat(a, b, result, n);
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
	//#pragma loop(hint_parallel(n))
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				result[i][k] += a[i][k] * b[k][j];
			}
		}
	}
}

void DPPSMutiMat(float A[][n], float B[][n], float Result[][n], int n) {
	int i, j, p;
	const int mask = 0x1F;
	__m128 v1 = { 0.0, 0.0, 0.0, 0.0 };
	__m128 v2 = { 0.0, 0.0, 0.0, 0.0 };
	__m128 v3 = { 0.0, 0.0, 0.0, 0.0 };
	__m128 v4 = { 0.0, 0.0, 0.0, 0.0 };
	__m128 s = { 0.0, 0.0, 0.0, 0.0 };
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			for (p = 0; p < n; p = p + 8) {
				v1 = _mm_set_ps(A[i][p], A[i][p + 1], A[i][p + 2], A[i][p + 3]);
				v2 = _mm_set_ps(A[i][p + 4], A[i][p + 5], A[i][p + 6], A[i][p + 7]);
				v3 = _mm_set_ps(B[i][p], B[i][p + 1], B[i][p + 2], B[i][p + 3]);
				v4 = _mm_set_ps(B[i][p + 4], B[i][p + 5], B[i][p + 6], B[i][p + 7]);
				s = _mm_dp_ps(v1, v3, mask);
				Result[i][j] += s.m128_f32[0] + s.m128_f32[1] + s.m128_f32[2] + s.m128_f32[3];
				s = _mm_dp_ps(v2, v4, mask);
				Result[i][j] += s.m128_f32[0] + s.m128_f32[1] + s.m128_f32[2] + s.m128_f32[3];
			}
		}
	}
}