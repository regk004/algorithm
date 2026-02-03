P = int(input())

print(2 + (P-1)*(P)//2,P)
print(1,P)
print(1,P)
for i in range(1,P):
    print(2,P-i,P)
    for _ in range(i-1):
        print(1,P-i)


