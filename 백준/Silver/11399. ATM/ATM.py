# 11399 # ATM
n = int(input())
P_list = list(map(int, input().split()))

P_list.sort()
total_time = 0  

for i in range(n):
  total_time += P_list[i] * (n - i)

print(total_time)