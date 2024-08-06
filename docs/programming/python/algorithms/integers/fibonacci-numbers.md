# Liczby Fibonacciego

## [:link: Opis problemu](../../../../algorithms/integers/fibonacci-numbers.md)

## Wersja iteracyjna

```python linenums="1"
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

## Wersja rekurencyjna

```python linenums="1"
def fib(n: int) -> int:
    if n <= 2:
        return 1
        
    return fib(n - 1) + fib(n - 2)

n = 10

result = fib(n)

print(f"fib({n}) = {result}")
```
