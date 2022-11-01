c = int(input())

for i in range(c):
    nums = list(map(int, input().split())) 
    avg = sum(nums[1:])/nums[0] 
    count = 0
    for j in range(1, nums[0] + 1):  # index 1부터 nums[0]까지(nums[0]은 학생 수) 
        if nums[j] > avg:
            count += 1
    rate = count / nums[0] * 100
    print("%.3f%%" %rate)