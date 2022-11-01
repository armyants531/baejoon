int main(void)
{
	int N, L, n1, n2, R;
	L = 0;
	scanf("%d", &N);
	R = N;
	
	while (1)
	{
		
		n1 = N / 10;
		n2 = N % 10;
		N = 10 * n2 + ((n1 + n2)%10);
		L++;
		if (N == R)
			break;
	}
	printf("%d\n", L);
}
