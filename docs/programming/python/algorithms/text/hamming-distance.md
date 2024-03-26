# Odległość Hamminga

## [Opis problemu](../../../../algorithms/text/hamming-distance.md)


## Implementacja

```python linenums="1"
def hamming_distance(a: str, b: str) -> int:
    distance = 0
    
    for el1, el2 in zip(a, b):
        if el1 != el2:
            distance += 1
            
    return distance



a = "karolin"
b = "kerstin"
    
distance = hamming_distance(a, b)
    
print(f"Odległość Hamminga pomiędzy wyrazami {a} i {b} wynosi {distance}")
```

