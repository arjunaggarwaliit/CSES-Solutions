def predicate(arr,check,t):
    tot =0
    for i in arr:
        tot += (check//i)
    if(tot >= t):
        return True
    else:
        return False
n,t = map(int,input().split())
times = list(map(int,input().split()))
minn = min(times)
low =0
high = t*(minn)
while(low <= high):
    mid = (low + high)//2
    if(predicate(times,mid,t)):
        high = mid -1
    else:
        low = mid +1
print(low)