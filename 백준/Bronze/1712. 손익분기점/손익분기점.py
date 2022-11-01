try : 
    a, b, c = map(int, input().split())
except ValueError :
    print("3개의 숫자를 입력해야 합니다.")
    
x = 0  # 손익 분기점
profit = c - b  # 1개 판매 당 이익

if profit <= 0:  # 손익 분기점이 없을 때
    x = -1
else:  # 손익 분기점이 있을 때
    x = a // profit + 1 
    
print(x) 