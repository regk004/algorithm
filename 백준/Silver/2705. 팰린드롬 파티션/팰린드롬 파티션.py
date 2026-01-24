import sys
input = sys.stdin.readline

T = int(input())

dp = [0]*1001
dp[0] = 1

for i in range(1,1001):
    for j in range(0,i//2+1):
        dp[i] += dp[j]

for _ in range(T):
    N = int(input())
    print(dp[N])
