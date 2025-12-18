def modular_exponentiation(n,base=2,mod = 10**9 + 7):
    res = base
    tot = 1
    while(n>0):
        if(n&1):
            tot*=res
            tot%=mod
        n>>=1
        res*=res
        res%=mod
    return tot
n= int(input())
print(modular_exponentiation(n))
