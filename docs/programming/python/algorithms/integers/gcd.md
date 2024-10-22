---
description: Największy Wspólny Dzielnik
---

# NWD

## [:link: Opis problemu](../../../../algorithms/integers/gcd.md)

## Algorytm NWD z odejmowaniem

```python linenums="1"
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

## Algorytm Euklidesa - wersja iteracyjna

```python linenums="1"
def gcd(a: int, b: int) -> int:
    while b != 0:
        a, b = b, a % b

    return a

a = 32
b = 12

result = gcd(a, b)

print(f"GCD({a},{b}) = {result}")
```

## Algorytm Euklidesa - wersja rekurencyjna

```python linenums="1"
def gcd(a: int, b: int) -> int:
    if b == 0:
        return a
        
    return gcd(b, a % b)

a = 32
b = 12

result = gcd(a, b)

print(f"GCD({a},{b}) = {result}")
```
