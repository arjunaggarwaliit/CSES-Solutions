n = int(input())
arr = list(map(int,input().split()))
tot =0
for i in range(1,n+1):
    tot+=i
print(tot-sum(arr))
