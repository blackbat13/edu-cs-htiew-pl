# Anagramy

## [:link: Opis problemu](../../../../algorithms/text/anagrams.md)

## Implementacja

```python linenums="1"
def are_anagrams(a: str, b: str) -> bool:
    return sorted(a) == sorted(b)

a = "rokowanie"
b = "korowanie"

if are_anagrams(a, b):
    print(f"{a} i {b} są anagramami")
else:
    print(f"{a} i {b} nie są anagramami")
```
