# Sito Eratostenesa

## Opis problemu

{% content-ref url="../../../../algorithms/integers/eratosthenes-sieve.md" %}
[eratosthenes-sieve.md](../../../../algorithms/integers/eratosthenes-sieve.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
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
{% endcode %}
