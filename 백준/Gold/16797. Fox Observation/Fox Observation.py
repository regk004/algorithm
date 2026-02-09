import sys

input = sys.stdin.readline
N = int(input())

dxdy = (((-1,-1),(-1,0),(0,-1)),((-1,0),(-1,1),(0,1)),((0,1),(1,1),(1,0)),((1,0),(1,-1),(0,-1)))
points = {}

for _ in range(N):
    x,y,w = map(int,input().split())
    points[(x,y)] = w

res = 0
for x,y in points:
    cur = points[(x,y)]
    adj_max = 0
    for i in range(4):
        adj_sum = 0
        for dx,dy in dxdy[i]: 
            if (x+dx,y+dy) in points: adj_sum += points[(x+dx,y+dy)]
        adj_max = max(adj_max,adj_sum)
    res = max(res,cur+adj_max)
print(res,"/",1)


