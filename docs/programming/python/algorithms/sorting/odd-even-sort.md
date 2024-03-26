# Sortowanie odd-even

## [Opis problemu](../../../../algorithms/sorting/odd-even-sort.md)


## Implementacja

```python linenums="1"
def odd_even_sort(array: list):
    for i in range(len(array)):
        for j in range(i % 2 + 1, len(array), 2):
            if array[j] < array[j - 1]:
                array[j], array[j - 1] = array[j - 1], array[j]


array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

odd_even_sort(array)

print(array)
```

