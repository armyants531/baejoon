#2981번 #공약수를 효율적으로 구해보자
#ex) 20 % 2 = 0 (2는 20의 약수), 20 // 2 = 10 (10은 20의 약수)

def gcd(a, b):
  while b > 0:
    temp = a
    a = b
    b = temp % a
  return a

n = int(input()) 
num_list = []
for i in range(n):
  num_list.append(int(input()))

# 최솟값을 찾고 (리스트의 모든 원소 - 최솟값)을 한 후 최대 공약수 구하기  
min_val = min(num_list) 

# (리스트의 모든 원소 - 최솟값)을 한 리스트
num_list2 = [] 
for i in range(n):
  num_list[i] = num_list[i] - min_val
  if num_list[i] > 0: # 0보다 큰 값만 포함
    num_list2.append(num_list[i]) 

# 최대 공약수 구하기
GCD = 0
if len(num_list2) == 0: # 원래 리스트의 숫자가 모두 같은 경우 # 원소 0개
  GCD = min_val
elif len(num_list2) == 1: # 원소가 1개인 경우
  GCD = num_list2[0]
else: #앞에서 부터 두 수의 최대공약수를 구하고, 
      #구한 최대공약수와 그 다음 수의 최대공약수를 구하는 과정 반복 
  temp = gcd(num_list2[0], num_list2[1])
  for i in range(2, n):
    temp = gcd(temp, num_list[i])
  GCD = temp

# 약수 구하기(1제외)
com_fact = set() # 제곱근일 때 중복을 피하기 위해 set 사용
for i in range(2, int(GCD**0.5) + 1):
  if GCD % i == 0:
    com_fact.add(i)
    com_fact.add(GCD // i)
# 마지막에 GCD 자신도 추가
com_fact.add(GCD)

ans = sorted(list(com_fact))
for i in ans:
  print(i, end=" ")