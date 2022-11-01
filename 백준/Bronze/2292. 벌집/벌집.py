N = int(input())

if N == 1: 
    print(1)
elif N > 1 and N <= 7:
    print(2)
else: 
    L = (N - 1) / 6
    sum = 1
    m = 2
    while True:
        sum += m
        if L <= sum:
            print(m+1)
            break
        m += 1