# Test doskonałości

## Opis problemu

{% content-ref url="../../../../algorithms/integers/perfect-test.md" %}
[perfect-test.md](../../../../algorithms/integers/perfect-test.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def is_perfect(n: int) -> bool:
    divisors_sum = 1
    i = 2
    
    while i * i <= n:
        if n % i == 0:
            divisors_sum += i
            
            if n // i != i:
                divisors_sum += n // i
        
        i += 1

    return divisors_sum == n


n = 6

if is_perfect(n):
    print(f'{n} is a perfect number')
else:
    print(f'{n} is not a perfect number')
```
{% endcode %}
