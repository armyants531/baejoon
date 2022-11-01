M = int(input())
N = int(input())

list_prime = []

for i in range(M, N + 1):
  isPri = True
  if i == 1:
    isPri = False
  else:
    for j in range(2, i):
      if i % j == 0:
        isPri = False
  if isPri == True:
    list_prime.append(i)

if len(list_prime) != 0:
  print(sum(list_prime))
  print(list_prime[0])
else:
  print(-1)