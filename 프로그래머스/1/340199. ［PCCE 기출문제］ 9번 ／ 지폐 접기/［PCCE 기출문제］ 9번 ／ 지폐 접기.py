def solution(wallet, bill):
    w_D, w_d = max(wallet),min(wallet)
    b_D, b_d = max(bill),min(bill)
    
    cnt = 0
    while(b_D > w_D or b_d > w_d):
        b_D //= 2
        if(b_d > b_D): b_D,b_d = b_d,b_D
        cnt += 1
        
    return cnt