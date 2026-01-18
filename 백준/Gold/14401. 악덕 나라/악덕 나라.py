import sys
input = sys.stdin.readline

def ccw(A,B,C):
    v1 = (B[0]-A[0],B[1]-A[1])
    v2 = (C[0]-B[0],C[1]-B[1])

    return v2[1]*v1[0]-v1[1]*v2[0]

def find(n):
    if parent[n] != n:
        parent[n] = find(parent[n])
    return parent[n]

def union(a,b):
    global N
    root_a = find(a)
    root_b = find(b)
    if root_a != root_b:
        x_l,x_r = points[a][0],points[b][0]
        if x_l > x_r : x_l,x_r = x_r,x_l
        for c in range(1,N+1):
            if c not in (a,b) and x_l < points[c][0] < x_r:
                if ccw(points[a],points[c],points[b]) == 0: return 0

        parent[root_b] = root_a
        return 1
    return 0


N,M = map(int,input().split())
parent = [i for i in range(N+1)]
points = [-1]
edge = []
connected = set()
res = 0

for _ in range(N):
    points.append((tuple(map(int,input().split()))))
    
for _ in range(M):
    a,b = map(int,input().split())
    if a > b: a,b = b,a
    connected.add((a,b))
    union(a,b)

for i in range(1,N+1):
    for j in range(i+1,N+1):
        if (i,j) not in connected:
            edge.append(((points[i][0]-points[j][0])**2+(points[i][1]-points[j][1])**2,i,j))

edge.sort(reverse = True)

for cost,p1,p2 in edge:
    if union(p1,p2): res += cost
print(res)