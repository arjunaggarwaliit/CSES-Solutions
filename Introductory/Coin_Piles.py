for _ in range(int(input())):
    a,b = map(int,input().split())
    x = min(a,b)
    y = max(a,b)
    a,b = y,x
    x = a-b
    if(x<=b and (b-x)%3 == 0):
        p = (b-x)//3
        if(a-3*p == 2*x):
            print("YES")
        else:
            print("NO")
    else:
        print("NO")
