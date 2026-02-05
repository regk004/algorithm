a,b = map(int,input().split())

# 1선공, 0후공
dp = [[0 for _ in range(b+1)] for _ in range(a+1)]

for i in range(a+1):
    for j in range(b+1):
        if i == 0:
            if j % 2: dp[i][j] = 1
        elif j == 0:
            if i % 2: dp[i][j] = 1
        else:
            if i >= 3 and dp[i-3][j-1] == 0: dp[i][j] = 1
            elif j >= 3 and dp[i-1][j-3] == 0: dp[i][j] = 1
            elif dp[i-1][j] == 0: dp[i][j] = 1
            elif dp[i][j-1] == 0: dp[i][j] = 1

if dp[a][b]: print("Alice")
else: print("Bob")
