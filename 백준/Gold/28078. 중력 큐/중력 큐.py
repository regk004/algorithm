import sys
from collections import deque

input = sys.stdin.readline

Q = int(input())

#RDLU
#0 : b 1: w
stat = 0
cnt_b,cnt_w = 0,0
queue = deque([])

def per_grav (s,q):
    global cnt_b,cnt_w
    if s == 1:
        while q and q[-1] == 0: q.pop(); cnt_b -= 1
    elif s == 3:
        while q and q[0] == 0: q.popleft(); cnt_b -= 1



for _ in range(Q):
    query = input().rstrip()

    if query == "push b":
        if stat in (0,2) or (stat == 1 and queue): queue.appendleft(0); cnt_b += 1
    elif query == "push w": 
        queue.appendleft(1); cnt_w += 1
    elif query == "pop":
        if queue: 
            if queue.pop() == 0: cnt_b -= 1
            else: cnt_w -= 1
    elif query == "rotate l": stat -= 1; stat %= 4
    elif query == "rotate r": stat += 1; stat %= 4
    elif query == "count b": print(cnt_b)
    elif query == "count w": print(cnt_w)
    per_grav(stat,queue)
        
    