# Superfactorial

## Opis problemu

{% content-ref url="../../../../algorithms/integers/superfactorial.md" %}
[superfactorial.md](../../../../algorithms/integers/superfactorial.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def superfactorial(n: int) -> int:
    result = factorial = 1
    
    for i in range(2, n + 1):
        factorial *= i
        result *= factorial

    return result


n = 4

result = superfactorial(n)

print(f"{n}$ = {result}")
```
{% endcode %}
