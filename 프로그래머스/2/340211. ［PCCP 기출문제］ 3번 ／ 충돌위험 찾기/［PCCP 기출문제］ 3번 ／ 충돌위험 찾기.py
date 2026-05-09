def solution(points, routes):
    
    cur_dr = [[0,0] for _ in range(len(routes))]
    cur_dest_idx = [0 for _ in range(len(routes))]
    cur_pos = []
    for route in routes:
        cur_pos.append(points[route[0]-1][:])
    
    cnt = 0
    r_size = len(routes)
    c_size = len(routes[0])
    goal = r_size*c_size
    
    tmp = dict()
    for r,c in cur_pos:
            if (r,c) in tmp: tmp[(r,c)] += 1
            else: tmp[(r,c)] = 1
            
    for i in tmp.values():
        if(i > 1): cnt += 1
    
    while(sum(cur_dest_idx) != goal):
        flag = False
        for i in range(r_size):
            
            if cur_dr[i] == [0,0] and cur_dest_idx[i] < c_size:
                if cur_dest_idx[i] == c_size-1: cur_dest_idx[i] += 1
                else:
                    cur_dest_idx[i] += 1
                    cur_dr[i][0] += points[routes[i][cur_dest_idx[i]]-1][0]-cur_pos[i][0]
                    cur_dr[i][1] += points[routes[i][cur_dest_idx[i]]-1][1]-cur_pos[i][1]         
            val = 0;
            if cur_dr[i][0] != 0:
                if cur_dr[i][0] > 0: val = 1
                else:  val = -1
                
                cur_dr[i][0] -= val
                cur_pos[i][0] += val
                
            elif cur_dr[i][1] != 0:
                if cur_dr[i][1] > 0: val = 1
                else:  val = -1
                
                cur_dr[i][1] -= val
                cur_pos[i][1] += val    
        tmp = dict()
        for i in range(r_size):
            if cur_dest_idx[i] == c_size: continue
            
            r,c = cur_pos[i]
            if (r,c) in tmp: tmp[(r,c)] += 1
            else: tmp[(r,c)] = 1
            
        for i in tmp.values():
            if(i > 1): cnt += 1
            
            
    return cnt