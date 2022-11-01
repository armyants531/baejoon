#11051번 # 1 <= n <= 1000 이기 때문에 동적 프로그래밍 필요
n, k = map(int, input().split())

table = [[1] * 1001 for i in range(1001)]

for i in range(n+1):
  for j in range(k+1):
    if j != 0 and j != i:
      table[i][j] = table[i-1][j] + table[i-1][j-1]

print(table[n][k] % 10007)