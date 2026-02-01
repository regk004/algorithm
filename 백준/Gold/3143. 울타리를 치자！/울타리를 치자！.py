import sys
import heapq

input = sys.stdin.readline

N = int(input())

seq = list(map(int,input().split()))
doyoon = []
board =[]
board_match = [-1 for _ in range(N)]
heap = []

for i in range(N):
    doyoon.append((seq[i],i))
doyoon.sort(reverse = True)

for n in range(1,N+1):
    h,c = map(int,input().split())
    board.append((h,c,n))
board.sort(reverse = True)

cur_idx = 0
cost_res = 0
for i in range(N):
    while cur_idx < N and board[cur_idx][0] >= doyoon[i][0]:
        cost, board_num = board[cur_idx][1:]
        heapq.heappush(heap,(-cost,board_num))
        cur_idx += 1
    if heap: 
        c,num = heapq.heappop(heap)
        cost_res -= c
        board_match[doyoon[i][1]] = num

for i in range(N):
    if board_match[i] == -1:
        if heap: board_match[i] = heapq.heappop(heap)[1]
        else:
            board_match[i] = board[cur_idx][2]
            cur_idx += 1
print(cost_res)
print(" ".join(map(str,board_match)))
    
    




