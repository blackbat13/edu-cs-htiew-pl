# Sortowanie przez wstawianie

## [Opis problemu](../../../../algorithms/sorting/insertion-sort.md)


## Implementacja

```python linenums="1"
def insertion_sort(array: list):
    for i in range(1, len(array)):
        j = i
        
        while j > 0 and array[j] < array[j - 1]:
            array[j], array[j - 1] = array[j - 1], array[j]
            j -= 1


array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

insertion_sort(array)

print(array)
```

