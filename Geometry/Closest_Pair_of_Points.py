import math

def dist(p1,p2):
    return math.sqrt((p1[0]-p2[0])**2 + (p1[1]-p2[1])**2)

def bruteforce(points):
    n = len(points)
    minn = float('inf')
    for i in range(n):
        for j in range(i+1,n):
            d = dist(points[i],points[j])
            if(d < minn):
                minn = d
    return minn

def stripclosest(strip,d):
    minn = d
    strip.sort(key = lambda p : p[1])

    for i in range(len(strip)):
        j = i+1
        #  will check maximum 7 points
        while j< len(strip) and (strip[j][1] - strip[i][1] < minn):
            minn = min(minn, dist(strip[i],strip[j]))
            j += 1
    return minn

def closestutil(points):
    n = len(points)
    if(n <= 3):
        return bruteforce(points)

    mid = n//2
    midpoint = points[mid]

    dl = closestutil(points[:mid])
    dr = closestutil(points[mid:])
    d = min(dl,dr)
    strip = [p for p in points if abs(p[0] - midpoint[0]) < d]

    return min(d, stripclosest(strip,d))

def closestpair(points):
    points.sort(key = lambda p :p[0])
    return closestutil(points)
