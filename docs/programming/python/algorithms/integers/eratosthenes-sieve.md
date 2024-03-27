# Sito Eratostenesa

## [Opis problemu](../../../../algorithms/integers/eratosthenes-sieve.md)

## Implementacja

```python linenums="1"
def sieve(n: int) -> list:
    primes = [False, False] + [True] * (n - 1)
    i = 2
    while i * i <= n:
        if not primes[i]:
            i += 1
            continue

        for j in range(2 * i, n + 1, i):
            primes[j] = False

        i += 1

    return primes

def print_prime_numbers(primes: list):
    for i, is_prime in enumerate(primes):
        if is_prime:
            print(i)

n = 100

primes = sieve(n)

print_prime_numbers(primes)
```
