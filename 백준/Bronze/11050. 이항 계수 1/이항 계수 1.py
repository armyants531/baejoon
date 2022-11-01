#11050번
n, k = map(int, input().split())

def factorial(a):
  if a <= 1:
    return 1
  else:
    return a * factorial(a-1)

binomial_coef = factorial(n) // (factorial(n-k) * factorial(k))
print(binomial_coef)