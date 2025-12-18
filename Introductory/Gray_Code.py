def printbin(i,n):
    for j in range(n-1,-1,-1):
        if(i&(1<<j)):
            print(1,end="")
        else:
            print(0,end="")
    print("\n")
n = int(input())
for i in range(2**n):
    printbin((i^(i>>1)),n)
