n = int(input())

l = [int(i) for i in input().split()]

l.sort()

for i in l:
    print(i,end=" ")