# Superfactorial

## [:link: Opis problemu](../../../../algorithms/integers/superfactorial.md)

## Implementacja

```python linenums="1"
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
