from math import sqrt
for _ in range(int(input())):
    n = int(input())
    cnt = 0
    for i in range(1,int(sqrt(n))+1):
        if(i*i == n):
            cnt+=1
            continue
        if(n%i == 0):
            cnt+=2
    print(cnt)