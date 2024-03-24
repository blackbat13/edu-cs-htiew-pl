# Punkt na odcinku

## Opis problemu

{% content-ref url="../../../../algorithms/2d-geometry/point-on-segment.md" %}
[point-on-segment.md](../../../../algorithms/2d-geometry/point-on-segment.md)
{% endcontent-ref %}

## Implementacja

```python
def det3(matrix: list) -> int:
    return matrix[0][0] * matrix[1][1] * matrix[2][2] + matrix[1][0] * matrix[2][1] * matrix[0][2] + matrix[2][0] * \
           matrix[0][1] * matrix[1][2] - matrix[0][2] * matrix[1][1] * matrix[2][0] - matrix[0][1] * matrix[1][0] * \
           matrix[2][2] - matrix[0][0] * matrix[1][2] * matrix[2][1]


def point_on_segment(a_x: int, a_y: int, b_x: int, b_y: int, c_x: int, c_y: int) -> bool:
    """
    Check if point (c_x, c_y) lies on the segment [(a_x, a_y), (b_x, b_y)]
    :return: True if point lies on the given segment, False otherwise
    """
    matrix = [
         [a_x, a_y, 1],
         [b_x, b_y, 1],
         [c_x, c_y, 1]]
    det = det3(matrix)
    
    if det != 0:
        return False

    if min(a_x, b_x) <= c_x <= max(a_x, b_x) and min(a_y, b_y) <= c_y <= max(a_y, b_y):
        return True
    else:
        return False

a_x = 1
a_y = 1
b_x = 5
b_y = 5
c_x = 2
c_y = 2

result = point_on_segment(a_x, a_y, b_x, b_y, c_x, c_y)

if result:
	print(f"Punkt ({c_x}, {c_y}) leży na odcinku [({a_x}, {a_y}), ({b_x}, {b_y})]")
else:
	print(f"Punkt ({c_x}, {c_y}) nie leży na odcinku [({a_x}, {a_y}), ({b_x}, {b_y})]")
```

### Link do implementacji

{% embed url="https://ideone.com/aohGSt" %}
Punkt na odcinku
{% endembed %}

### Opis implementacji

TODO
