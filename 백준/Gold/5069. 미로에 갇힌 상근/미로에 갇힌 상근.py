

dp = [[1]]
for i in range(1,15):
    dp.append([0]*(6*i))

res = [1]

for _ in range(14):
    nxt = [[0]]
    for i in range(1,15):
        nxt.append([0]*(6*i))

    for i in range(6):
        nxt[1][i] += dp[0][0]

    for d in range(1,15):
        modular = 6*d
        for idx in range(d*6):
            val = dp[d][idx]
            if val != 0:
                nxt[d][(idx-1)%modular] += val
                nxt[d][(idx+1)%modular] += val
                if idx % d == 0:
                    nxt[d+1][idx+idx//d] += val
                    nxt[d+1][(idx+idx//d-1)%(modular+6)] += val
                    nxt[d+1][(idx+idx//d+1)] += val
                    nxt[d-1][(idx-idx//d)%(max(1,modular-6))] += val
                else:
                    nxt[d+1][idx+idx//d] += val
                    nxt[d+1][(idx+idx//d+1)] += val
                    nxt[d-1][(idx-idx//d-1)% max(1,modular-6)] += val
                    nxt[d-1][(idx-idx//d)% max(1,modular-6)]+= val
    
    res.append(nxt[0][0])
    dp = nxt
T = int(input())
for _ in range(T):
    N = int(input())
    print(res[N])