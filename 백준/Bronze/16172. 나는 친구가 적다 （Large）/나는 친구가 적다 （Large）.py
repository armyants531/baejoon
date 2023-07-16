a, b = input(), input()

for num in ['0', '1', '2', '3', '4', '5', '6', '7', '8', '9']:
    a = a.replace(num, '')
    
if b in a:
    print(1)
else:
    print(0)