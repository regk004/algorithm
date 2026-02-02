n, k = map(int,input().split())

pivot = k/2
cnt = (2*n+1)**2

if pivot == n: cnt -= 2*n+1
elif pivot < n:
    if pivot == int(pivot):
        cnt -= 2*n+1
    pivot = int(pivot)
    cnt -= (n-pivot+1)*(n-pivot)*2

print(cnt)