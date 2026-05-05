import math

def solution(signals):
    time_gcd = sum(signals[0])
    max_time = 1
    for signal in signals:
        max_time *= sum(signal)
        time_gcd = math.gcd(sum(signal),time_gcd)
    lcm = max_time/time_gcd
    t = 0
    
    while(t < lcm):
        for signal in signals:
            if (not (signal[0] < t % sum(signal) <= signal[0]+signal[1])): break
        else:
            return t
        t += 1
        
    return -1