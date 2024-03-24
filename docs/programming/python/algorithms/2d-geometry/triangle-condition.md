# Warunek trójkąta

## Opis problemu

{% content-ref url="../../../../algorithms/2d-geometry/triangle-condition.md" %}
[triangle-condition.md](../../../../algorithms/2d-geometry/triangle-condition.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def can_create_triangle(a: int, b: int, c: int) -> bool:
    return a < b + c and b < a + c and c < a + b


a = 3
b = 8
c = 9

if can_create_triangle(a, b, c):
    print(f"Triangle can be created from {a}, {b} and {c}")
else:
    print(f"Triangle cannot be created from {a}, {b} and {c}")
```
{% endcode %}
