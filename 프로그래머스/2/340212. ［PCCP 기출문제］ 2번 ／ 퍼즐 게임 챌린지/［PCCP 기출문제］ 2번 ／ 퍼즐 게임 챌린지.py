def solution(diffs, times, limit):
    answer = 0
    
    s,e = 1,max(diffs)
    while(s < e):
        mid = (s+e)//2
        Sum = max(0,diffs[0]-mid)*times[0]+times[0]
        for i in range(1,len(diffs)):
            Sum += max(0,diffs[i]-mid)*(times[i-1]+times[i]) + times[i]
        
        if Sum > limit: s = mid+1
        else: e = mid
        
    answer = s
    
    return answer