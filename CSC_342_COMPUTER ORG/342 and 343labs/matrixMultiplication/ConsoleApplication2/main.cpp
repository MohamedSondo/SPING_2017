#include<iostream>
#include<iomanip>
#include<Windows.h>
#include<xmmintrin.h>
#include<smmintrin.h>
using namespace std;
const int size = 256;
void print(float[][size], int n);
_declspec(align(16)) float a[size][size];
_declspec(align(16)) float b[size][size];
_declspec(align(16)) float c[size][size];

int main()
{
	int n = size/4;
	__int64 ctr1 = 0, ctr2 = 0, freq = 0;
	int acc = 0;
	//initialize the matrices.
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			a[i][j] = 1.1;
			b[i][j] = 2.1;
		}
	}

	cout << "size of matrices are " << size <<"x "<<size<< endl;
	cout << "In c++ " << endl;
	if (QueryPerformanceCounter((LARGE_INTEGER*)&ctr1) != 0)
	{
		for (int i = 0; i < size; i++)
		{

			for (int j = 0; j < size; j++)
			{
				for (int k = 0; k < size; k++)

					c[i][j] += a[i][k] * b[k][j];
			}

		}
		QueryPerformanceCounter((LARGE_INTEGER*)&ctr2);
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		cout << "Counts: " << (ctr2 - ctr1)*1.0 << endl;
		cout << "Time: " << ((ctr2 - ctr1)*1.0 / freq) << "secs" << endl << endl;
		

	}
	
	//print(c, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			c[i][j] = 0;
		}
	}

	cout << "Auto Parallized C++ : " << endl;
	if (QueryPerformanceCounter((LARGE_INTEGER*)&ctr1) != 0)
	{
		
		for (int i = 0; i < size; i++)
		{
			//#pragma loop(hint_parallel(8))
			for (int j = 0; j < size; j++)
			{
				
				for (int k = 0; k < size; k++)

					c[i][j] += a[i][k] * b[k][j];
			}

		}
		QueryPerformanceCounter((LARGE_INTEGER*)&ctr2);
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		cout << "Counts: " << (ctr2 - ctr1)*1.0 << endl;
		cout << "Time: " << ((ctr2 - ctr1)*1.0 / freq) << "secs" << endl << endl;


	}

	//print(c, size);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			c[i][j] = 0;
		}
	}




	cout << "Using SSE Intrinsic" << endl;


	if (QueryPerformanceCounter((LARGE_INTEGER*)&ctr1) != 0)
	{
		__m128 m1, m2, m3, m4;
		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				m3 = _mm_set_ps(0, 0, 0, 0);
				for (int k = 0; k < size; k+=4)
				{				
					m1 = _mm_set_ps(a[j][k+3], a[j][k+2], a[j][k+1], a[j][k]);
					m2 = _mm_set_ps(b[k + 3][j], b[k + 2][j], b[k + 1][j], b[k][j]);
					m4 = _mm_dp_ps(m1, m2, 0xF1);
					m3 = _mm_add_ss(m3, m4);					
				}
				_mm_store_ss((c[i] + j), m3);
			}
		}
		QueryPerformanceCounter((LARGE_INTEGER*)&ctr2);
		QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
		cout << "Counts: " << (ctr2 - ctr1)*1.0 << endl;
		cout << "Time: " << ((ctr2 - ctr1)*1.0 / freq) << "secs" << endl << endl;

	}
	else
	{
		DWORD dwError = GetLastError();
		cout << "Error value = " << dwError << "\n\n";
	}
	//print(c, size);
	
}

void print(float[][size], int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			cout << setw(10) << c[j][i];
		}
		cout << endl;
	}
}