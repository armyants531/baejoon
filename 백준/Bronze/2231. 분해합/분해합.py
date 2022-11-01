N = int(input())
isDecompositionExists = 0
for i in range(N):
  temp_sum = i + sum(list(map(int, str(i))))
  if temp_sum == N:
    isDecompositionExists = 1
    print(i)
    break
if isDecompositionExists == 0:
  print(0)