# Wszystkie dzielniki

## [:link: Opis problemu](../../../../algorithms/integers/divisors.md)

## Rozwiązanie zupełnie naiwne

```python linenums="1"
def divisors(n: int):
    for i in range(1, n + 1):
        if n % i == 0:
            print(i)

n = 12
 
divisors(n)
```

## Rozwiązanie naiwne

```python linenums="1"
def divisors(n: int):
    for i in range(1, (n // 2) + 1):
        if n % i == 0:
            print(i)
 
    if n > 1:
        print(n)

n = 12
 
divisors(n)
```

## Rozwiązanie optymalne

```python linenums="1"
def divisors(n: int):
    i = 1
    while i * i <= n:
        if n % i == 0:
            print(i)
            if i != (n // i):
                print(n // i)
        i += 1

n = 12
 
divisors(n)
```
