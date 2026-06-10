import math

class point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __repr__(self):
        return f"({self.x}, {self.y})"


class utils:
    @staticmethod
    def orientation(a, b, c):
        return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x)

    @staticmethod
    def dist(a, b):
        dx = a.x - b.x
        dy = a.y - b.y
        return dx * dx + dy * dy

    @staticmethod
    def miny(points):
        minn = points[0]
        for p in points[1:]:
            if p.y < minn.y or (p.y == minn.y and p.x < minn.x):
                minn = p
        return minn


class grahamscan:
    def scan(self, points):
        if len(points) <= 2:
            return points

        p0 = utils.miny(points)

        def polar_angle(p):
            return math.atan2(p.y - p0.y, p.x - p0.x)

        points = [p0] + sorted(points[1:], key = lambda p :(polar_angle(p),utils.dist(p0,p)))
        stack = []
        stack.append(points[0])
        stack.append(points[1])

        for i in range(2, len(points)):
            while len(stack) >= 2 and utils.orientation(stack[-2], stack[-1], points[i]) <= 0:
                stack.pop()
            stack.append(points[i])

        return stack
