import bisect

class segment:
    def __init__(self, id, x1, y1, x2, y2):
        self.id = id
        if x1 > x2:
            x1, y1, x2, y2 = x2, y2, x1, y1
        self.x1, self.y1, self.x2, self.y2 = x1, y1, x2, y2

    def get_y(self, x):
        if self.x1 == self.x2: return self.y1
        return self.y1 + (self.y2 - self.y1) * (x - self.x1) / (self.x2 - self.x1)

def intersect(s1, s2):

    def orientation(p, q, r):
        val = (q[1] - p[1]) * (r[0] - q[0]) - (q[0] - p[0]) * (r[1] - q[1])
        if val == 0: return 0
        return 1 if val > 0 else 2

    def on_segment(p, q, r):
        return (min(p[0], r[0]) <= q[0] <= max(p[0], r[0]) and
                min(p[1], r[1]) <= q[1] <= max(p[1], r[1]))

    p1, q1 = (s1.x1, s1.y1), (s1.x2, s1.y2)
    p2, q2 = (s2.x1, s2.y1), (s2.x2, s2.y2)

    o1 = orientation(p1, q1, p2)
    o2 = orientation(p1, q1, q2)
    o3 = orientation(p2, q2, p1)
    o4 = orientation(p2, q2, q1)

    if (o1 != o2 and o3 != o4):
        return True

    if o1 == 0 and on_segment(p1, p2, q1): return True
    if o2 == 0 and on_segment(p1, q2, q1): return True
    if o3 == 0 and on_segment(p2, p1, q2): return True
    if o4 == 0 and on_segment(p2, q1, q2): return True

    return False

def line_sweep(segments):
    events = []
    for s in segments:
        events.append((s.x1, 'L', s))
        events.append((s.x2, 'R', s))
    events.sort()

    active = []
    intersections = set()

    for x, typ, seg in events:
        if typ == 'L':
            y_curr = seg.get_y(x)
            active_ys = [s.get_y(x) for s in active]
            idx = bisect.bisect_left(active_ys, y_curr)
            active.insert(idx, seg)

            if idx > 0:
                if intersect(active[idx], active[idx-1]):
                    intersections.add(tuple(sorted((active[idx].id, active[idx-1].id))))
            if idx < len(active) - 1:
                if intersect(active[idx], active[idx+1]):
                    intersections.add(tuple(sorted((active[idx].id, active[idx+1].id))))

        else:
            try:
                idx = active.index(seg)
                above = active[idx - 1] if idx > 0 else None
                below = active[idx + 1] if idx < len(active) - 1 else None
                active.pop(idx)

                if above and below:
                    if intersect(above, below):
                        intersections.add(tuple(sorted((above.id, below.id))))

            except ValueError:
                pass

    return intersections