t = int(input())

while t>0:
    
    l = [int(i) for i in input().split()]
    print(sum(l) - max(l) - min(l))
    t-=1