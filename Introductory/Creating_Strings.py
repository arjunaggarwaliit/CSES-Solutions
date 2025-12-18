from collections import Counter
def perms(i,hash,d,chars,s,n,store):
    if(i==n):
        store.append(s)
        return
    for letter in chars:
        if(d[letter]<hash[letter]):
            d[letter]+=1
            perms(i+1,hash,d,chars,s + letter,n,store)
            d[letter]-=1
        else:
            continue
s = input()
chars = set()
for alphabet in s:
    chars.add(alphabet)
chars = sorted(chars)
hash = Counter(s)
d = dict()
for alphabet in chars:
    d[alphabet] = 0
store = []
perms(0,hash,d,chars,"",len(s),store)
print(len(store))
for it in store:
    print(it)
