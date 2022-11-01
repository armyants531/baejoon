word = input()
n = len(word)

result = 1
for i in range(n):
  if word[i] != word[n - 1 - i]:
    result = 0

print(result)