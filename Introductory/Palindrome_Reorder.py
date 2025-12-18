s = input()
arr = [0 for _ in range(26)]
n = len(s)
for i in range(n):
    arr[ord(s[i])-ord('A')]+=1
cnt = 0
num = -1
for i in range(26):
    if(arr[i]&1):
        cnt+=1
        num = i
if(cnt>1):
    print("NO SOLUTION")
else:
    dq = []
    mid = chr(ord('A')+num)
    if(cnt == 1):
        arr[num]-=1
    for i in range(26):
        p = arr[i]//2
        c = chr(ord('A')+i)
        for i in range(p):
            dq.append(c)
    ans = "".join(dq)
    print(ans[::-1],end="")
    if(cnt == 1):
        print(mid,end="")
    print(ans,end="")
    print("\n")
