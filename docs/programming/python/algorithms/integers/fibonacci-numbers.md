# Liczby Fibonacciego

## Opis problemu

{% content-ref url="../../../../algorithms/integers/fibonacci-numbers.md" %}
[fibonacci-numbers.md](../../../../algorithms/integers/fibonacci-numbers.md)
{% endcontent-ref %}

## Wersja iteracyjna

{% code overflow="wrap" lineNumbers="true" %}
```python
def fib(n: int) -> int:
    f1 = 1
    f2 = 1
    
    for _ in range(3, n + 1):
        f1, f2 = f2, f1 + f2

    return f2


n = 10

result = fib(n)

print(f"fib({n}) = {result}")
```
{% endcode %}

## Wersja rekurencyjna

{% code overflow="wrap" lineNumbers="true" %}
```python
def fib(n: int) -> int:
    if n <= 2:
        return 1
        
    return fib(n - 1) + fib(n - 2)


n = 10

result = fib(n)

print(f"fib({n}) = {result}")
```
{% endcode %}
