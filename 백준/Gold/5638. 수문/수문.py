import sys
input = sys.stdin.readline

def backT(cur_c,cur_f,gate_idx):
    global N
    if gate_idx == N: 
        raw_gate_case.append((cur_c,cur_f)); return 0

    cur_c += gate[gate_idx][0]
    cur_f += gate[gate_idx][1]
    backT(cur_c,cur_f,gate_idx+1)
    cur_c -= gate[gate_idx][0]
    cur_f -= gate[gate_idx][1]
    backT(cur_c,cur_f,gate_idx+1)

N = int(input())

gate = []

for _ in range(N):
    f,c = map(int,input().split())
    gate.append((c,f))

raw_gate_case = []
gate_case = []
backT(0,0,0)
raw_gate_case.sort(key = lambda x : (x[0],-x[1]))

cur_f = 0
for i in range(2**N):
    if raw_gate_case[i][1] > cur_f:
        cur_f = raw_gate_case[i][1]
        gate_case.append(raw_gate_case[i])

lst_idx = len(gate_case)-1

M = int(input())

for i in range(1,M+1):
    v,t = map(int,input().split())
    if v > gate_case[-1][1]*t: print(f'Case {i}: IMPOSSIBLE')
    else:
        s,e = 0,lst_idx
        while s < e: 
            mid = (s+e)//2
            if gate_case[mid][1]*t >= v: e = mid
            else: s = mid+1
        print(f'Case {i}: {gate_case[s][0]}')