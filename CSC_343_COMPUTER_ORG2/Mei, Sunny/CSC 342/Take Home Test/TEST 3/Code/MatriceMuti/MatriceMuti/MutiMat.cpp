void MutiMat(float a[][n], float b[][n], float result[][n]) {
	//#pragma loop(hint_parallel(16))
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				result[i][k] += a[i][k] * b[k][j];
			}
		}
	}
}