import sys

dydx = [(0,1),(0,-1),(-1,0),(1,0)]

input = sys.stdin.readline

R,C = map(int,input().split())
matrix = []
Fire = []
jihoon = []

for r in range(R):
    row = list(input().rstrip())
    matrix.append(row)
    for c in range(C):
        if row[c] == "F": Fire.append((r,c))
        elif row[c] == "J": jihoon.append((r,c)); matrix[r][c] = 1


while jihoon:
    nxt_jihoon= []
    nxt_Fire = []


    for cur_y,cur_x in Fire:
        for i in range(4):
            ny = cur_y + dydx[i][0]
            nx = cur_x + dydx[i][1]

            if 0 <= ny < R and 0 <= nx < C and matrix[ny][nx] == ".":
                matrix[ny][nx] = "F"
                nxt_Fire.append((ny,nx))
    Fire = nxt_Fire

    for cur_y,cur_x in jihoon:
        cur_t = matrix[cur_y][cur_x]
        if cur_y in (0,R-1) or cur_x in (0,C-1): print(cur_t); sys.exit()
        for i in range(4):
            ny = cur_y + dydx[i][0]
            nx = cur_x + dydx[i][1]

            if 0 <= ny < R and 0 <= nx < C and matrix[ny][nx] == ".":
                matrix[ny][nx] = cur_t + 1
                nxt_jihoon.append((ny,nx))
    jihoon = nxt_jihoon

print("IMPOSSIBLE")