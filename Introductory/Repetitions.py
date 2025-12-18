s = input()
n = len(s)
leng = 0
prev = s[0]
vec = []
for i in range(n):
    if(s[i]==prev):
        leng+=1
    else:
        vec.append(leng)
        leng = 1
        prev = s[i]
vec.append(leng)
print(max(vec))
