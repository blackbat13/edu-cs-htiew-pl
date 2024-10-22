# Warunek trójkąta

## [:link: Opis problemu](../../../../algorithms/2d-geometry/triangle-condition.md)

## Implementacja

```python linenums="1"
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
