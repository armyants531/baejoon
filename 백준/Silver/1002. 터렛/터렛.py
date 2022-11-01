# 1002 # 터렛 # 기하학 1
import math
T = int(input())

for _ in range(T):
  info = list(map(int, input().split()))
  x1 = info[0]
  y1 = info[1]
  r1 = info[2]
  x2 = info[3]
  y2 = info[4]
  r2 = info[5]

  L = math.sqrt((x1-x2) ** 2 + (y1-y2) ** 2)
  if L == 0 and r1 == r2: # 류재명이 있을 수 있는 위치가 원을 이루는 경우
    print(-1)
  elif L != 0 and (L == abs(r1 - r2) or L == r1 + r2): # 두 터렛과 류재명이 일직선 상에 있는 경우
    print(1)
  elif L < r1 + r2 and r1 < L + r2 and r2 < L + r1: # 두 터렛과 류재명이 삼각형을 이루는 경우
    print(2)
  else: # 잘못된 경우
    print(0)