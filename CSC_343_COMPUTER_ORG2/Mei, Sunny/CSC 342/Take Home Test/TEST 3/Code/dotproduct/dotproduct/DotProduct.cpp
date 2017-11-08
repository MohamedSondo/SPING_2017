int DotProduct(int X[], int Y[], int n) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += X[i] * Y[i];
	}
	return sum;
}