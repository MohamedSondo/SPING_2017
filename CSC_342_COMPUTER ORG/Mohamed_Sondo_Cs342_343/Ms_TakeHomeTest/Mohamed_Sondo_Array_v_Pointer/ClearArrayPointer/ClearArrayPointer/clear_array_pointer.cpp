#include "clear_array_pointer.h"

void clear_array_pointer(int arr[], int size)
{
	for (int *p = &arr[0]; p < &arr[size]; p++)
		*p = 0;
}
