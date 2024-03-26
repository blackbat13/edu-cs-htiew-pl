# Szybkie potęgowanie

## [Opis problemu](../../../../algorithms/numerical-methods/fast-exp.md)


## Rozwiązanie rekurencyjne

```python
def fast_exp_rec(a: int, n : int) -> int:
    if n == 1:
        return a
        
    if n % 2 == 1:
        return fast_exp_rec(a, n // 2) ** 2 * a
    else:
        return fast_exp_rec(a, n // 2) ** 2

 
a = 2
n = 10

result = fast_exp_rec(a, n)

print(f"{a}^{n} = {result}")
```

### Link do implementacji

[Szybkie potęgowanie - wersja rekurencyjna](https://ideone.com/3i2qdR)

### Opis implementacji

TODO

## Rozwiązanie iteracyjne

```python
def fast_exp_iter(a: int, n: int) -> int:
    w = 1
    
    while n > 0:
        if n % 2 == 1:
            w *= a

        a *= a
        n = n // 2

    return w


a = 2
n = 10

result = fast_exp_iter(a, n)

print(f"{a}^{n} = {result}")
```

### Link do implementacji

[Szybkie potęgowanie - wersja iteracyjna](https://ideone.com/pSGzrA)

### Opis implementacji

TODO
