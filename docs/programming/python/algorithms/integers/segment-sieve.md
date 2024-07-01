# Sito Segmentowe

## [Opis problemu](../../../../algorithms/integers/segment-sieve.md)

## Implementacja

```python linenums="1"
import math


def sieve(n):
    is_prime = [True] * (n + 1)

    for i in range(2, int(math.sqrt(n)) + 1):
        if is_prime[i]:
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    primes = [i for i in range(2, n + 1) if is_prime[i]]

    return primes


def segment_sieve(num_from, num_to):
    limit = int(math.sqrt(num_to)) + 1
    primes = sieve(limit)

    n = num_to - num_from + 1
    is_prime = [True] * n

    for p in primes:
        start = (num_from // p) * p
        if start < num_from:
            start += p
        if start == p:
            start += p
        for j in range(start, num_to + 1, p):
            is_prime[j - num_from] = False

    result = [i + num_from for i in range(n) if is_prime[i]]

    return result


num_from = 100
num_to = 200

primes = segment_sieve(num_from, num_to)

print(*primes)
```
