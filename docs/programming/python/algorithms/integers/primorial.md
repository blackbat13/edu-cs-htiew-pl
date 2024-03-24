# Primorial

## Opis problemu

{% content-ref url="../../../../algorithms/integers/primorial.md" %}
[primorial.md](../../../../algorithms/integers/primorial.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def is_prime(n: int) -> bool:
  if n < 2:
    return False
    
  return all(n % i != 0 for i in range(2, int(n**0.5) + 1))


def primorial(n: int) -> int:
  primes = []
  num = 2
  while len(primes) < n:
    if is_prime(num):
      primes.append(num)
      
    num += 1

  result = 1
  for prime in primes:
    result *= prime

  return result


n = 3

result = primorial(n)

print(f"{n}# = {result}")

```
{% endcode %}
