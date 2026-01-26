N = int(input())


def reverse_row(r):
    global N
    for c in range(N):
        matrix[r][c] = (matrix[r][c]+1)%2

def reverse_col(c):
    global N
    for r in range(N):
        matrix[r][c] = (matrix[r][c]+1)%2

def count(d):
    global Min
    cnt_1,cnt_0 = d,d
    for r in range(N):
        for c in range(N):
            if matrix[r][c] == 1: cnt_1 += 1
            else: cnt_0 += 1
    Min = min(Min,cnt_1,cnt_0)



def backT(depth,idx):
    global N

    count(depth)
    if idx == 2*N: return 0

    if idx < N:
        reverse_row(idx)
        backT(depth+1,idx+1)
        reverse_row(idx)
        backT(depth,idx+1)
    else:
        reverse_col(idx-N)
        backT(depth+1,idx+1)
        reverse_col(idx-N)
        backT(depth,idx+1)


Min = 65
matrix = []
for _ in range(N):
    row = list(map(int,input().split()))
    matrix.append(row)

backT(0,0)
print(Min)

