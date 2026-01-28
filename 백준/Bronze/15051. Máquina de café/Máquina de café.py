
floor_cnt = []

for _ in range(3):
    floor_cnt.append(int(input()))

print(min(floor_cnt[1]*2+floor_cnt[2]*4,floor_cnt[0]*2+floor_cnt[2]*2,floor_cnt[0]*4+floor_cnt[1]*2))
