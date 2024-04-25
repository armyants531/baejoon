# nearest smaller to the left
def NSL(nums):
    nsl=[] # save the index
    stack=[] # [(nums[i], i)]
    sudoidx = -1
    for i in range(0, len(nums), 1):
        if len(stack) == 0:
            nsl.append(sudoidx)
        elif stack[-1][0] < nums[i]:
            nsl.append(stack[-1][1])
        else:
            while len(stack) > 0 and stack[-1][0] >= nums[i]:
                stack.pop()
            if len(stack) == 0:
                nsl.append(sudoidx)
            else:
                nsl.append(stack[-1][1])
        stack.append((nums[i], i))
    return nsl

# nearest smaller to the right
def NSR(nums):
    nsr=[] # save the index
    stack=[] # [(nums[i], i)]
    sudoidx = len(nums)
    for i in range(len(nums) - 1, -1, -1):
        if len(stack) == 0:
            nsr.append(sudoidx)
        elif stack[-1][0] < nums[i]:
            nsr.append(stack[-1][1])
        else:
            while len(stack) > 0 and stack[-1][0] >= nums[i]:
                stack.pop()
            if len(stack) == 0:
                nsr.append(sudoidx)
            else:
                nsr.append(stack[-1][1])
        stack.append((nums[i], i))
    nsr.reverse()
    return nsr

if __name__ == '__main__':
    # 여러 줄의 정수 리스트 입력받기
    n = int(input())
    a = [int(input()) for _ in range(n)]
    nsl = NSL(a)
    nsr = NSR(a)
    max_a = 0
    for i in range(0, len(a), 1):
        temp = a[i] * (nsr[i] - nsl[i] - 1)
        if temp > max_a:
            max_a = temp
            
    print(max_a)