from collections import Counter
n = int(input())
arr = list(map(int,input().split()))
hash = Counter(arr)
MOD = 10**9 + 7
pro = 1
for value in hash.values():
    pro *= (value+1)
    pro%=MOD
pro+= (MOD-1)
pro%=MOD
print(pro)