# Test doskonałości

## [Opis problemu](../../../../algorithms/integers/perfect-test.md)


## Implementacja

```python linenums="1"
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

