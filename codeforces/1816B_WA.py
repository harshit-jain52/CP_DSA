t = int(input())

while(t>0):
    t-=1
    n = int(input())

    num = 2*n-1
    diff = 2*n-1 - 3
    ct = 1
    while(ct<n):
        print(num,end=" ")
        num += ((-1)**ct)*diff
        diff -= 2
        ct+=1
    print(1)

    num = 2
    diff = 2*n-1 - 3
    ct = 0
    while(ct<n-1):
        print(num,end=" ")
        num += ((-1)**ct)*diff
        diff -= 2
        ct+=1
    print(2*n)