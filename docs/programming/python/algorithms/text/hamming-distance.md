# Odległość Hamminga

## Opis problemu

{% content-ref url="../../../../algorithms/text/hamming-distance.md" %}
[hamming-distance.md](../../../../algorithms/text/hamming-distance.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
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
{% endcode %}
