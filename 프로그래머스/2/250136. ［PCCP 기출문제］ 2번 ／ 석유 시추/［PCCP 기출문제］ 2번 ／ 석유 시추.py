from collections import deque


dr = [0,0,-1,1]
dc = [1,-1,0,0]

def solution(land):
    
    group = 0
    volume = {}
    
    R = len(land)
    C = len(land[0])
    
    visited = [[-1]*C for _ in range(R)]
    
    for r in range(R):
        for c in range(C):
            if visited[r][c] == -1 and land[r][c] == 1:
                queue = deque([(r,c)])
                visited[r][c] = group
                cnt = 0
                while(queue):
                    cur_r,cur_c = queue.popleft()
                    cnt += 1
                    for i in range(4):
                        nxt_r = cur_r + dr[i]
                        nxt_c = cur_c + dc[i]
                        
                        if 0 <= nxt_r < R and 0 <= nxt_c < C and visited[nxt_r][nxt_c] == -1 and land[nxt_r][nxt_c] == 1:
                            visited[nxt_r][nxt_c] = group
                            queue.append((nxt_r,nxt_c))
                            
                volume[group] = cnt
                group += 1
                
    Max = 0
    for c in range(C):
        cur_group = set()
        Sum = 0
        for r in range(R):
            if visited[r][c] != -1: cur_group.add(visited[r][c])
        for g in cur_group:
            Sum += volume[g]
        Max = max(Max,Sum)
        
    return Max