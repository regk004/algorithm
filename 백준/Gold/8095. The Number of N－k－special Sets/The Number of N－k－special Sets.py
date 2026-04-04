
N,K = map(int,input().split())

dp = [[0 for _ in range(K+2)] for _ in range(N+1)]

dp[0][0] = 1
dp[1][1] = 1


for i in range(1,N+1):
    for j in range(i-1):
        for k in range(K+2):
            if i+k >= K+1: dp[i][K+1] += dp[j][k]
            else: dp[i][i+k] += dp[j][k]

res = 0;

for i in range(N+1):
    res += dp[i][K+1]
    
print(res)