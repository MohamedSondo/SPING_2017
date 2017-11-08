void clear_array_pointer(int *ary, int size)
{
	int *p;
	for (p = &ary[0]; p < &ary[size]; p++)
		*p = 0;
}