N = int(input())
seq = list(map(int,input().split()))
cnt = 0
Max = 0
for n in seq:
    if n == 1: cnt += 1; Max= max(Max,cnt)
    else: cnt = 0
print(Max)
