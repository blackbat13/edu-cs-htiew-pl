# Sortowanie przez kopcowanie

## [Opis problemu](../../../../algorithms/sorting/heap-sort.md)


## Implementacja

```python linenums="1"
def build_heap(array: [], n: int):
    for i in range(1, n):
        parent_index = (i - 1) // 2
        j = i
        
        while j > 0 and array[j] > array[parent_index]:
            array[j], array[parent_index] = array[parent_index], array[j]
            j = parent_index
            parent_index = (j - 1) // 2
            

def heap_sort(array: []):
    for i in range(len(array) - 1, 0, -1):
        build_heap(array, i + 1)
        array[0], array[i] = array[i], array[0]


array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]
    
heap_sort(array)

print(array)
```

