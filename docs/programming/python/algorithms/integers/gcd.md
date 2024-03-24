---
description: Największy Wspólny Dzielnik
---

# NWD

## Opis problemu

{% content-ref url="../../../../algorithms/integers/gcd.md" %}
[gcd.md](../../../../algorithms/integers/gcd.md)
{% endcontent-ref %}

## Algorytm NWD z odejmowaniem

{% code overflow="wrap" lineNumbers="true" %}
```python
def gcd(a: int, b: int) -> int:
    while a != b:
        if a > b:
            a -= b
        else:
            b -= a

    return a


a = 32
b = 12

result = gcd(a, b)

print(f"GCD({a}, {b}) = {result}")
```
{% endcode %}

## Algorytm Euklidesa - wersja iteracyjna

{% code overflow="wrap" lineNumbers="true" %}
```python
def gcd(a: int, b: int) -> int:
    while b != 0:
        a, b = b, a % b

    return a


a = 32
b = 12

result = gcd(a, b)

print(f"GCD({a},{b}) = {result}")
```
{% endcode %}

## Algorytm Euklidesa - wersja rekurencyjna

{% code overflow="wrap" lineNumbers="true" %}
```python
def gcd(a: int, b: int) -> int:
    if b == 0:
        return a
        
    return gcd(b, a % b)


a = 32
b = 12

result = gcd(a, b)

print(f"GCD({a},{b}) = {result}")
```
{% endcode %}
