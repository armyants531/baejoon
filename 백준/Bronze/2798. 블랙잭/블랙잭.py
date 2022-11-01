n, m = map(int, input().split())
cards = list(map(int, input().split()))
sum = 0

for i in range(n-2):
  for j in range(i+1, n-1):
    for k in range(j+1, n):
      if cards[i]+cards[j]+cards[k] > m:
        continue
      elif cards[i]+cards[j]+cards[k] > sum: # 더 근접한 것이 있으면 
        sum = cards[i]+cards[j]+cards[k]
      if sum == m:
        break

print(sum)