int factorial (int n)
{
	if (n==1)
		return 1;
	return (n*factorial(n-1));
}

void main()
{
	int n_fact = factorial(5);
}