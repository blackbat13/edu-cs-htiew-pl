# Podwójna silnia

## [Opis problemu](../../../../algorithms/integers/double-factorial.md)

## Implementacja

```python linenums="1"
def double_factorial(n: int) -> int:
    result = 1
    for i in range(n, 0, -2):
        result *= i

    return result

n = 8

result = double_factorial(n)

print(f"{n}!! = {result}")
```
