# Rotating Caliper (Brute Force->O(N^2) / Optimized : 0(N))
import math

def distance(p, q):
    return math.hypot(p[0]-q[0], p[1]-q[1])

def cross(o, a, b):
    return (a[0]-o[0]) * (b[1]-o[1]) - (a[1]-o[1]) * (b[0]-o[0])

def rotating_calipers(points):
    n = len(points)
    if n == 2:
        return distance(points[0], points[1])
    maxx = 0.0
    j = 1
    # j -> antipodal pointer (traverses atmost all vertices -> 0(N))
    for i in range(n):
        ni = (i + 1) % n
        while True:
            nj = (j + 1) % n
            curr = abs(cross(points[i], points[ni], points[j]))
            next = abs(cross(points[i], points[ni], points[nj]))
            if next > curr:
                j = nj
            else:
                break
        maxx = max(maxx,distance(points[i], points[j]),distance(points[ni], points[j]))
    return maxx
