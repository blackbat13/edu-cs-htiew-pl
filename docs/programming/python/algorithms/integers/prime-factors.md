# Rozkład na czynniki pierwsze

## [Opis problemu](../../../../algorithms/integers/prime-factors.md)


## Implementacja

```python linenums="1"
def distribute(n: int) -> list:
    prime_factors = []
    i = 2
    
    while n > 1:
        if n % i == 0:
            prime_factors.append(i)
            n /= i
        else:
            i += 1

    return prime_factors


n = 124

print(f"Prime factors of {n}: {distribute(n)}")
```

