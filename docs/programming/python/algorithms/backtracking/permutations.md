# Permutacje

## Opis problemu

{% content-ref url="../../../../algorithms/backtracking/permutations.md" %}
[permutations.md](../../../../algorithms/backtracking/permutations.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
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
{% endcode %}
