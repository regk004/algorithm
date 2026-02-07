import itertools


'''
성냥깨비 왼쪽 위에서 오른쪽 아래로 0 -> 23
3:3 - 0
2:2 - 1,2,3,4
1:1 - 5,6,7,8,9,10,11,12,13
'''

N, K = map(int,input().split())


Case = itertools.combinations(range(24),N)

stick = [{0,1,5},{0,1,2,6},{0,2,7},
         {0,1,5},{2,5,6},{1,6,7},{0,2,7},
         {3,5,8},{3,4,6,9},{4,7,10},
         {0,1,3,8},{2,4,8,9},{1,3,9,10},{0,2,4,10},
         {1,8,11},{1,2,9,12},{2,10,13},
         {0,3,11},{4,11,12},{3,12,13},{0,4,13},
         {0,3,11},{0,3,4,12},{0,4,13}]
grid = []
stick_coordinate  = [[] for _ in range(24)]

for _ in range(3):
    grid.append(list('+--+--+--+'))
    grid.append(list('|..|..|..|'))
    grid.append(list('|..|..|..|'))
grid.append(list('+--+--+--+'))


for i in range(24):
    if i % 7 in (0,1,2): 
        r,c = 3*(i//7),3*(i%7)+1
        stick_coordinate[i].append((r,c))
        stick_coordinate[i].append((r,c+1))
    else:
        r,c = 3*(i//7)+1,3*(i%7-3)
        stick_coordinate[i].append((r,c))
        stick_coordinate[i].append((r+1,c))

deleted_cnt = 14-K
for case in Case:
    deleted_square = set()

    for i in case: deleted_square |= stick[i]
    if len(deleted_square) == deleted_cnt:
        for i in case:
            for r,c in stick_coordinate[i]: grid[r][c] = "."
        for i in range(10): print("".join(grid[i]))
        break

    