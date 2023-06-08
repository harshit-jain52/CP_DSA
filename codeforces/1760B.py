t = int(input())

while t>0:
    n = int(input())
    s = input()
    c = 'a'
    
    for i in s:
        if i > c:
            c = i

    print(ord(c)- ord('a') +1 )        
    t-=1