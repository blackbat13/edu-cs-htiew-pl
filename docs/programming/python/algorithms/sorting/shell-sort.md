# Sortowanie Shella

## [Opis problemu](../../../../algorithms/sorting/shell-sort.md)

## Implementacja

```python linenums="1"
def shell_sort(array: list):
    gap = len(array) // 2
    while gap > 0:
        for i in range(0, len(array) - gap):
            if array[i] > array[i + gap]:
                array[i], array[i + gap] = array[i + gap], array[i]

        gap //= 2

array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

shell_sort(array)

print(array)
```
