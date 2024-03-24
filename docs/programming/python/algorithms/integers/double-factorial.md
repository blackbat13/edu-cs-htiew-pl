# Podwójna silnia

## Opis problemu

{% content-ref url="../../../../algorithms/integers/double-factorial.md" %}
[double-factorial.md](../../../../algorithms/integers/double-factorial.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def double_factorial(n: int) -> int:
    result = 1
    for i in range(n, 0, -2):
        result *= i

    return result


n = 8

result = double_factorial(n)

print(f"{n}!! = {result}")
```
{% endcode %}
