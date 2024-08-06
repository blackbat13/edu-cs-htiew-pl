# Permutacje

## [:link: Opis problemu](../../../../algorithms/backtracking/permutations.md)

## Implementacja

```python linenums="1"
def permutation(elements, start, stop):
    if start == stop:
        print(elements)
        return

    for i in range(start, stop + 1):
        elements[start], elements[i] = elements[i], elements[start]

        permutation(elements, start + 1, stop)

        elements[start], elements[i] = elements[i], elements[start]

elements = list(range(1, 4))

print("Permutacje:")
permutation(elements, 0, 2)
```
