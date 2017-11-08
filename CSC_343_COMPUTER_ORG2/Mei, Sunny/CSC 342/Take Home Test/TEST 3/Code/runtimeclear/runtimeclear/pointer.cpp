void ClearUsingPointers(int *array, int size) {
	int *p; 
	for (p = &array[0]; p < &array[size]; p = p + 1)
		*p = 0;
}