int is_simple(int n);

int main()
{
	int n = 6;

	int result = is_simple(n);

	return 0;
}

int is_simple(int n)
{
	int sum = 0;
	int check = 0;
	for (int i = 1; i < n; ++i) {
		if (n % i == 0) {
			sum += i;
		}
	}
	if (n == sum) {
		check = 1;
	}
	return check;
}
