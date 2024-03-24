# Anagramy

## Opis problemu

{% content-ref url="../../../../algorithms/text/anagrams.md" %}
[anagrams.md](../../../../algorithms/text/anagrams.md)
{% endcontent-ref %}

## Implementacja

```python
def are_anagrams(a: str, b: str) -> bool:
    return sorted(a) == sorted(b)


a = "rokowanie"
b = "korowanie"

if are_anagrams(a, b):
    print(f"{a} i {b} są anagramami")
else:
    print(f"{a} i {b} nie są anagramami")
```

### Link do implementacji

{% embed url="https://ideone.com/EZQcCD" %}
Test anagramów
{% endembed %}

### Opis implementacji

TODO
