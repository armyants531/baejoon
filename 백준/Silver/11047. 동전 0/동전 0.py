#11047
N, K = map(int, input().split())

value_list = []
for i in range(N):
  temp = int(input())
  value_list.append(temp)

index = len(value_list) - 1
num = 0
while(True):
  num += K // value_list[index]
  K %= value_list[index]
  index -= 1
  if K == 0:
    break;

print(num)