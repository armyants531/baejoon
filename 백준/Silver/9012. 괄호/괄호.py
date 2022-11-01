n = int(input())

for i in range(n):
    ps = input()
    stack = []
    isVPS = True
    for j in ps:
        if j == "(":
            stack.append("(")
        elif j == ")":
            if "(" in stack:
                stack.pop()
            else:
                isVPS = False
                break
    if len(stack) == 0 and isVPS:
        print("YES")
    else:
        print("NO")