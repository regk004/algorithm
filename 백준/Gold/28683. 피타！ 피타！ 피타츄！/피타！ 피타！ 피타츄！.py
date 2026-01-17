N = int(input())

root_n = int(N**0.5)

if N == root_n**2: print(-1)
else:
    cnt = 0

    for i in range(1,root_n+1):
        if N % i == 0:
            rm = N //i
            if rm >= 2+i and (rm-2-i)%2 == 0:
                cnt += 1
    
    for A in range(1,int((N//2)**0.5)+1):
        B = N - A**2
        if int((B**0.5))**2 == B: cnt += 1

    print(cnt)
