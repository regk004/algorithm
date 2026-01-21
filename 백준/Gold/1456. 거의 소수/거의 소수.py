A,B = map(int,input().split())

Max = int(B**0.5)+1

visited = [False]*(Max+1)
prime = set()



for i in range(2,Max):
    if not visited[i]: 
        prime.add(i)
        cur = i*2
        while cur <= Max:
            visited[cur] = True
            cur += i

cnt = 0
for n in prime:
    cur = n**2
    while cur <= B:
        if A <= cur <= B: cnt += 1
        cur*=n

print(cnt)