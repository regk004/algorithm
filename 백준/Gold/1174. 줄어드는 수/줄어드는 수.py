N = int(input())

num = [0]*10

if N == 1: print(0)
else:
    for _ in range(N-1):
        if num == [9,8,7,6,5,4,3,2,1,0]: print(-1); break
        for idx in range(9,-1,-1):
            if num[idx] < 9 and (idx == 0  or num[idx-1] == 0 or num[idx-1] > num[idx]+1): 
                if idx != 9 and num[idx] == 0: num[idx] = 9-idx 
                else: num[idx] += 1
                for j in range(idx+1,10): num[j] = 9-j
                break
    else:
        while num[0] == 0: del num[0]
        print("".join(map(str,num)))