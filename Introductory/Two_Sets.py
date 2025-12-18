n = int(input())
summ = (n*(n+1))//2
if(summ&1):
    print("NO")
else:
    print("YES")
    arr = [i for i in range(1,n+1)]
    arr.sort(reverse=True)
    cnt = 0
    tot = 0
    arra = []
    arrb = []
    ident = -1
    j = -1
    for i in range(n):
        if((summ)//2 - tot >= arr[i]):
            cnt+=1
            tot+=(arr[i])
            arra.append(arr[i])
        elif((summ)//2 - tot >=1):
            cnt+=1
            arra.append((summ//2)-tot)
            ident = summ//2 - tot
            j =i
            break
        else:
            j = i
            break
    for i in range(j,n):
        if(arr[i] == ident):
            continue
        else:
            arrb.append(arr[i])
    arra.sort()
    arrb.sort()
    print(cnt)
    print(*arra)
    print(n-cnt)
    print(*arrb)
