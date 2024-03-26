# Odległość Hamminga

## [Opis problemu](../../../../algorithms/text/hamming-distance.md)


## Implementacja

```python
def hamming_distance(a: str, b: str) -> int:
    distance = 0
    
    for i in range(len(a)):
        if a[i] != b[i]:
            distance += 1
            
    return distance



a = "karolin"
b = "kerstin"
    
distance = hamming_distance(a, b)
    
print(f"Odległość Hamminga pomiędzy wyrazami {a} i {b} wynosi {distance}")
```

### Link do implementacji

[Odległość Hamminga](https://ideone.com/QpQzhH)

### Opis implementacji

TODO

