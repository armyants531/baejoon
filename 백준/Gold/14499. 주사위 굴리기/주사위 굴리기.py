dice = [0] * 6

N, M, x, y, K = map(int, input().split())
map_list = [list(map(int, input().split())) for i in range(N)]
order = list(map(int, input().split()))

def east_roll(dice):
    dice2 = [0] * 6 
    dice2[0] = dice[3]
    dice2[1] = dice[1]
    dice2[2] = dice[0]
    dice2[3] = dice[5]
    dice2[4] = dice[4]
    dice2[5] = dice[2]
    return dice2

def west_roll(dice):
    dice2 = [0] * 6 
    dice2[0] = dice[2]
    dice2[1] = dice[1]
    dice2[2] = dice[5]
    dice2[3] = dice[0]
    dice2[4] = dice[4]
    dice2[5] = dice[3]
    return dice2

def north_roll(dice):
    dice2 = [0] * 6 
    dice2[0] = dice[4]
    dice2[1] = dice[0]
    dice2[2] = dice[2]
    dice2[3] = dice[3]
    dice2[4] = dice[5]
    dice2[5] = dice[1]
    return dice2

def south_roll(dice):
    dice2 = [0] * 6 
    dice2[0] = dice[1]
    dice2[1] = dice[5]
    dice2[2] = dice[2]
    dice2[3] = dice[3]
    dice2[4] = dice[0]
    dice2[5] = dice[4]
    return dice2
    
for i in range(K):
    if order[i] == 1:
        if y <= M-2:
            y += 1
            dice = east_roll(dice)
            if map_list[x][y] == 0:
                map_list[x][y] = dice[5]
            else:
                dice[5] = map_list[x][y]
                map_list[x][y] = 0
            print(dice[0])    
        
    elif order[i] == 2:
        if y >= 1:
            y -= 1
            dice = west_roll(dice)
            if map_list[x][y] == 0:
                map_list[x][y] = dice[5]
            else:
                dice[5] = map_list[x][y]
                map_list[x][y] = 0
            print(dice[0])
        
    elif order[i] == 3:
        if x >= 1:
            x -= 1
            dice = north_roll(dice)
            if map_list[x][y] == 0:
                map_list[x][y] = dice[5]
            else:
                dice[5] = map_list[x][y]
                map_list[x][y] = 0
            print(dice[0])
          
    elif order[i] == 4:
        if x <= N-2:
            x += 1
            dice = south_roll(dice)
            if map_list[x][y] == 0:
                map_list[x][y] = dice[5]
            else:
                dice[5] = map_list[x][y]
                map_list[x][y] = 0
            print(dice[0])