N = int(input())
S = input()
T = input()

S_i = 0
T_i = 0
checking = False
T_chk_start = N
S_chk_start = 0
end_search = N
while T_i < end_search:
    if S[S_i] != T[T_i]: 
        if checking:
            checking = False
            S_i = S_chk_start
            T_i = T_chk_start + 1
        else: T_i += 1
    else: 
        if not checking:
            checking = True
            S_chk_start = S_i
            T_chk_start = T_i

        if T_i == end_search-1:
            checking = False
            end_search = T_chk_start
            T_i = 0
            S_i += 1
            continue
        
        S_i += 1
        T_i += 1

if end_search == 0: print('Yes')
else: print('No')
        
