import sys
input = sys.stdin.readline

Z = int(input())

for _ in range(Z):
    n, *seq = map(int,input().split())
    seq.sort(reverse = True)
    res = 0
    for i in range(n):  
        if seq[i] <= i: break
        res += (seq[i]-i)
    print(res)

