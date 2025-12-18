n = int(input())
arr = list(map(int,input().split()))
if(n==1):
    print(0)
else:
    tot =0
    prev = arr[0]
    for i in range(1,n):
        if(arr[i]<prev):
            tot += (prev - arr[i])
        else:
            prev = arr[i]
    print(tot)
