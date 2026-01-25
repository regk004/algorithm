import sys
import heapq

input = sys.stdin.readline


T = int(input())

def dijikstra(dist_arr,start):
    dist_arr[start] = 0
    heap = [(0,start)]
    while heap:
        cur_d,cur_p = heapq.heappop(heap)

        if dist_arr[cur_p] == cur_d:
            for nxt_d,nxt_p in graph[cur_p]:
                if nxt_d + cur_d < dist_arr[nxt_p]:
                    dist_arr[nxt_p] = nxt_d + cur_d
                    heapq.heappush(heap,(dist_arr[nxt_p],nxt_p))


for _ in range(T):
    n,m,t = map(int,input().split())
    s,g,h = map(int,input().split())

    graph = [[] for _ in range(n+1)]
    dist = [1e9 for _ in range(n+1)]
    dist_g = [1e9 for _ in range(n+1)]
    dist_h = [1e9 for _ in range(n+1)]
    
    g_h = 0

    for _ in range(m):
        a,b,d = map(int,input().split())

        if (a,b) in ((g,h),(h,g)): g_h = d
        graph[a].append((d,b))
        graph[b].append((d,a))

    dijikstra(dist,s)
    dijikstra(dist_g,g)
    dijikstra(dist_h,h)

    res = []
    for _ in range(t):
        x = int(input())

        if dist[x] == g_h + min(dist[g]+dist_h[x],dist[h]+dist_g[x]): res.append(x)
        
    
    res.sort()
    print(" ".join(map(str,res)))

