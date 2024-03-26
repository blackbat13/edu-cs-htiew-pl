# Przecinanie się odcinków

## [Opis problemu](../../../../algorithms/2d-geometry/segments-crossing.md)


## Implementacja

```python linenums="1"
class Point:
    def __init__(self, x: int, y: int):
        self.x = x
        self.y = y


def det3(matrix: list) -> int:
    return (
        matrix[0][0] * matrix[1][1] * matrix[2][2]
        + matrix[1][0] * matrix[2][1] * matrix[0][2]
        + matrix[2][0] * matrix[0][1] * matrix[1][2]
        - matrix[0][2] * matrix[1][1] * matrix[2][0]
        - matrix[0][1] * matrix[1][0] * matrix[2][2]
        - matrix[0][0] * matrix[1][2] * matrix[2][1]
    )


def point_on_segment(a: Point, b: Point, c: Point) -> bool:
    matrix = [[a.x, a.y, 1], [b.x, b.y, 1], [c.x, c.y, 1]]

    if det3(matrix) != 0:
        return False

    return min(a.x, b.x) <= c.x <= max(a.x, b.x) and min(a.y, b.y) <= c.y <= max(
        a.y, b.y
    )


def sgn(a: int) -> int:
    if a < 0:
        return -1
    elif a > 0:
        return 1
    else:
        return 0


def segment_crossing(a: Point, b: Point, c: Point, d: Point) -> bool:
    return (
        point_on_segment(a, b, c)
        or point_on_segment(a, b, d)
        or point_on_segment(c, d, a)
        or point_on_segment(c, d, b)
        or sgn(det3([[a.x, a.y, 1], [b.x, b.y, 1], [c.x, c.y, 1]]))
        != sgn(det3([[a.x, a.y, 1], [b.x, b.y, 1], [d.x, d.y, 1]]))
    )


a = Point(1, 1)
b = Point(2, 2)
c = Point(3, 3)
d = Point(4, 4)

result = segment_crossing(a, b, c, d)

if result:
    print(
        f"Segments [({a.x}, {a.y}), ({b.x}, {b.y})] and [({c.x}, {c.y}), ({d.x}, {d.y})] cross"
    )
else:
    print(
        f"Segments [({a.x}, {a.y}), ({b.x}, {b.y})] and [({c.x}, {c.y}), ({d.x}, {d.y})] do not cross"
    )
```

