try :
    N, M = map(int, input().split())
except ValueError :
    print("2개의 숫자를 입력해야 합니다.")

num = 0
num = M * N - 1 

print(num)