n = int(input())
arr = list(map(int,input().split()))
print(max(sum(arr),2*max(arr)))