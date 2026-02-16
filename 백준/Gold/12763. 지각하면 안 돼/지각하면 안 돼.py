import heapq
import sys

input = sys.stdin.readline

N = int(input())
T,M = map(int,input().split())
L = int(input())

dist = [[1e9 for _ in range(T+1)] for _ in range(N+1)]
dist[1][0] = 0
graph = [[] for _ in range(N+1)]

for _ in range(L):
    a,b,t,m = map(int,input().split())
    graph[a].append((m,b,t))
    graph[b].append((m,a,t))
    
heap = [[0,1,0]]

while heap:
    cur_m,cur_p,cur_t = heapq.heappop(heap)
    
    if cur_m == dist[cur_p][cur_t] and cur_m <= M:
        for dm,nxt_p,dt in graph[cur_p]:
            if cur_t + dt <= T and dist[nxt_p][cur_t+dt] > cur_m + dm and cur_m +dm <= M:
                dist[nxt_p][cur_t+dt] = cur_m+dm
                heapq.heappush(heap,(cur_m+dm,nxt_p,cur_t+dt))

res = 1e9  
for t in range(1,T+1):
    res = min(res,dist[-1][t])

if res == 1e9: print(-1)
else: print(res)
        
    