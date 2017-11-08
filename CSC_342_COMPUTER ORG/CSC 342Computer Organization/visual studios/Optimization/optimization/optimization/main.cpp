void ClearUsingIndex(int Array[], int size);
static int Array[10] = { 1,2,3,4,5,6,7,8,9,-1 };
int main() {
	int size = 10;
	ClearUsingIndex(Array, size);
}

/*#include <tchar.h>
#include <windows.h>
__int64 ctr1 = 0, ctr2 = 0, freq = 0;
int acc = 0, i = 0;

// Start timing the code.
if (QueryPerformanceCounter((LARGE_INTEGER *)&ctr1)!= 0)
{
// Code segment is being timed.
for (i=0; i<100; i++) acc++;

// Finish timing the code.
QueryPerformanceCounter((LARGE_INTEGER *)&ctr2);

Console::WriteLine("Start Value: {0}",ctr1.ToString());
Console::WriteLine("End Value: {0}",ctr2.ToString());

QueryPerformanceFrequency((LARGE_INTEGER *)&freq);

Console::WriteLine(S"QueryPerformanceCounter minimum resolution: 1/{0} Seconds.",freq.ToString());
// In Visual Studio 2005, this line should be changed to: Console::WriteLine("QueryPerformanceCounter minimum resolution: 1/{0} Seconds.",freq.ToString());
Console::WriteLine("100 Increment time: {0} seconds.",((ctr2 - ctr1) * 1.0 / freq).ToString());
}
else
{
DWORD dwError = GetLastError();
Console::WriteLine(S"Error value = {0}",dwError.ToString());// In Visual Studio 2005, this line should be changed to: Console::WriteLine("Error value = {0}",dwError.ToString());
}

// Make the console window wait.
Console::WriteLine();
Console::Write("Press ENTER to finish.");
Console::Read();

return 0;
*/