# Punkt na odcinku

## [Opis problemu](../../../../algorithms/2d-geometry/point-on-segment.md)


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


a = Point(1, 1)
b = Point(5, 5)
c = Point(2, 2)

result = point_on_segment(a, b, c)

if result:
    print(f"Point ({c.x}, {c.y}) on segment [({a.x}, {a.y}), ({b.x}, {b.y})]")
else:
    print(f"Point ({c.x}, {c.y}) not on segment [({a.x}, {a.y}), ({b.x}, {b.y})]")
```

