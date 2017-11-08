#include "clear_array_index.h"
void clear_array_index(int ary[], int size)
{
	for (int k = 0; k < size; k++)
		ary[k] = 0;
}