N,M,R = map(int,input().split())

matrix = []
for _ in range(N):
    matrix.append(list(input().split()))


query = list(input().split())

for q in query:
    nxt = []
    if q == '1':
        for r in range(N-1,-1,-1):
            nxt.append(matrix[r])
        matrix = nxt
    elif q == '2':
        for r in range(N):
            matrix[r].reverse()
    elif q == '3':
        for c in range(M):
            row = []
            for r in range(N-1,-1,-1):
                row.append(matrix[r][c])
            nxt.append(row)
        matrix = nxt
        N,M = M,N
    elif q == '4':
        for c in range(M-1,-1,-1):
            row = []
            for r in range(N):
                row.append(matrix[r][c])
            nxt.append(row)
        matrix = nxt
        N,M = M,N
    elif q == "5":
        for r in range(N//2):
            row = matrix[N//2+r][0:M//2]
            row.extend(matrix[r][0:M//2])
            nxt.append(row)
        for r in range(N//2):
            row = matrix[N//2+r][M//2:M]
            row.extend(matrix[r][M//2:M])
            nxt.append(row)
        matrix = nxt
    elif q == "6":
        for r in range(N//2):
            row = matrix[r][M//2:M]
            row.extend(matrix[N//2+r][M//2:M])
            nxt.append(row)
        for r in range(N//2):
            row = matrix[r][:M//2]
            row.extend(matrix[N//2+r][0:M//2])
            nxt.append(row)
        matrix = nxt

    

for r in range(N):
    print(" ".join(matrix[r]))