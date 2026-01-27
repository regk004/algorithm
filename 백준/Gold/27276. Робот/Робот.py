import sys
import heapq

input = sys.stdin.readline

N = int(input())

heap = []
total = 0
work = [(0,-1,-1)]

for i in range(1,N+1):
    d,w = map(int,input().split())
    work.append((d,w,i))
    total += w

work.sort(reverse = True)
cur_day = N

idx = 0
day = [-1]*N
res = [-1]*N
day_idx = N-1
while idx < N:
    while idx < N and work[idx][0] == cur_day:
        heapq.heappush(heap,(-work[idx][1],work[idx][2]))
        idx += 1

    emp_day = cur_day - work[idx][0]
    cur_day = work[idx][0]

    for _ in range(emp_day):
        if heap:
            w,i = heapq.heappop(heap)
            total += w
            day[day_idx] = i
        day_idx -= 1
    
for idx in range(N):
    if day[idx] == -1:
        w,i = heapq.heappop(heap)
        day[idx] = i

for i in range(N):
    res[day[i]-1] = i+1


print(total)
print(" ".join(map(str,res)))
    
