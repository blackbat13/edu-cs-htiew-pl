# Naiwne wyszukiwanie wzorca w tekście

## Opis problemu

{% content-ref url="../../../../algorithms/text/naive-substring-search.md" %}
[naive-substring-search.md](../../../../algorithms/text/naive-substring-search.md)
{% endcontent-ref %}

## Znajdowanie miejsca pierwszego wystąpienia wzorca w tekście 

```python
def substring_pos(a: str, b: str) -> int:
    for i in range(len(a) - len(b)):
        j = 0
        while j < len(b) and b[j] == a[i + j]:
            j += 1
 
        if j == len(b):
            return i
 
    return -1
 
 
a = "alamakota"
b = "kot"
 
pos = substring_pos(a, b)
if pos == -1:
    print(f'{b} is not a substring of {a}')
else:
    print(f'{b} is substring of {a} and starts at position {pos}')
```

### Link do implementacji

{% embed url="https://ideone.com/mZaOZo" %}
Znajdowanie miejsca pierwszego wystąpienia wzorca w tekście
{% endembed %}

### Opis implementacji

TODO
