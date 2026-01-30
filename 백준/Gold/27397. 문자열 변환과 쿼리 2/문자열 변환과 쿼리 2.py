import sys
input = sys.stdin.readline


S, n = input().split()
size = len(S)
n = int(n)
s_lst = set(S)
pointing = {chr(i) : chr(i) for i in range(ord("A"),ord("Z")+1)}
for i in range(ord("a"),ord("z")+1):
    pointing[chr(i)] = chr(i)

for _ in range(n):
    query = list(input().split())
    if query[0] == '1': 
        old_s, new_s = query[1:]
        for key in pointing:
            if pointing[key] == old_s: pointing[key] = new_s
    else:
        Max = 1
        cnt = 1
        cur_s = pointing[S[0]]
        for i in range(1,size):
            if pointing[S[i]] == cur_s: cnt += 1
            else: 
                Max = max(Max,cnt)
                cnt = 1
                cur_s = pointing[S[i]]
        Max = max(Max,cnt)
        print(Max)
