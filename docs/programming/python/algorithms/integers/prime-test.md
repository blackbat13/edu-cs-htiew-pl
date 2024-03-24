# Test pierwszości

## Opis problemu

{% content-ref url="../../../../algorithms/integers/prime-test.md" %}
[prime-test.md](../../../../algorithms/integers/prime-test.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
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
{% endcode %}
