# Zaprzeczenie silni

## Opis problemu

{% content-ref url="../../../../algorithms/integers/subfactorial.md" %}
[subfactorial.md](../../../../algorithms/integers/subfactorial.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def subfactorial(n: int) -> int:
    if n == 0:
        return 1
    elif n == 1:
        return 0

    a, b = 1, 0
    for i in range(2, n + 1):
        a, b = b, (i - 1) * (a + b)

    return b


n = 3

result = subfactorial(n)

print(f"!{n} = {result}")
```
{% endcode %}
