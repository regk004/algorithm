import sys
input = sys.stdin.readline

def find(n):
    if parent[n] != n:
        parent[n] = find(parent[n])
    return parent[n]


T = int(input())
for _ in range(T):
    edge = []
    res = 0
    R,C = map(int,input().split())
    parent = [i for i in range(R*C)]
    for r in range(R):
        cost = list(map(int,input().split()))
        for c in range(C-1):
            edge.append((cost[c],r*C+c,r*C+c+1))
    
    for r in range(R-1):
        cost = list(map(int,input().split()))
        for c in range(C):
            edge.append((cost[c],r*C+c ,(r+1)*C+c))
    
    edge.sort()
    
    for c,a,b in edge:
        root_a = find(a)
        root_b = find(b)
        if root_a != root_b:
            parent[root_a] = root_b
            res += c
    print(res)

