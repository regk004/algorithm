import sys
input = sys.stdin.readline

def find(n):
    if parent[n] != n:
        parent[n] = find(parent[n])
    return parent[n]

def union(u,v):
    root_u = find(u)
    root_v = find(v)
    if root_u != root_v:
        if rank[root_u] < rank[root_v]:
            parent[root_u] = root_v
            rank[root_v] += rank[root_u]
        else:
            parent[root_v] = root_u
            rank[root_u] += rank[root_v]


N,Q = map(int,input().split())
parent = [i for i in range(N+1)]
rank = [1]*(N+1)

edge = []
for _ in range(N-1):
    p,q,r = map(int,input().split())
    edge.append((r,p,q))
edge.sort(reverse = True)

query = []
query_res = [-1]*Q
for idx in range(Q):
    k,v = map(int,input().split())
    query.append((k,v,idx))
query.sort(reverse = True)

edge_idx = 0
for k,v,idx in query:
    while edge_idx < N-1 and edge[edge_idx][0] >= k:
        union(edge[edge_idx][1],edge[edge_idx][2])
        edge_idx += 1
    query_res[idx] = rank[find(v)]-1
print("\n".join(map(str,query_res)))





