n = int(input())
res =5
tot = 0
while(1):
    temp = n//(res)
    if(temp ==0):
        break
    else:
        tot += temp
        res*=5
print(tot)
