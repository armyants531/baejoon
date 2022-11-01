int main(void)
{
	int t, a, b, c, i;
	scanf("%d", &t);
	for (i = 1; i <= t; i++) {
		scanf("%d %d", &a, &b);
		c = a + b;
		printf("%d\n", c);
	}
}