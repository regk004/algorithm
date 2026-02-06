from collections import deque

import sys
input = sys.stdin.readline

N = int(input().rstrip())
queue = deque([])
res = []


for _ in range(N):
    query = input()
    if query[0] == "R":
        name = query[4:]
        queue.appendleft(name)
    else:
        idx = ((len(query)-3)//4) % len(queue)
        cur_program = queue[idx]
        del queue[idx]
        queue.appendleft(cur_program)
    res.append(queue[0])
print("".join(map(str,res)))