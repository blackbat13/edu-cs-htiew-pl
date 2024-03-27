# Test pierwszości

## [Opis problemu](../../../../algorithms/integers/prime-test.md)

## Implementacja

```python linenums="1"
def is_prime(n: int) -> bool:
    if n < 2:
        return False
    
    i = 2
    
    while i * i <= n:
        if n % i == 0:
            return False

        i += 1

    return True

n = 7

if is_prime(n):
    print(f"{n} is a prime number")
else:
    print(f"{n} is not a prime number")
```
