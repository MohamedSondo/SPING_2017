int ComputeDotProduct(int arrayA[], int arrayB[], int size) {
	int sum = 0;
	for (int i=0;i<size;i++){
		sum = sum + arrayA[i] * arrayB[i];
	}
	return sum;
}