# Odległość Hamminga

## Opis problemu

{% content-ref url="../../../../algorithms/text/hamming-distance.md" %}
[hamming-distance.md](../../../../algorithms/text/hamming-distance.md)
{% endcontent-ref %}

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

{% embed url="https://ideone.com/QpQzhH" %}
Odległość Hamminga
{% endembed %}

### Opis implementacji

TODO

