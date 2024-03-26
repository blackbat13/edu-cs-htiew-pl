# Sortowanie szybkie

## [Opis problemu](../../../../algorithms/sorting/quick-sort.md)


## Implementacja

```julia linenums="1"
function quicksort(array, left, right)
    if right <= left
        return
    end

    pivot = array[(left + right) ÷ 2]
    i = left
    j = right

    while i <= j
        while array[i] < pivot
            i += 1
        end

        while array[j] > pivot
            j -= 1
        end

        if i > j
            break
        end

        array[i], array[j] = array[j], array[i]

        i += 1
        j -= 1
    end

    quicksort(array, left, j)
    quicksort(array, i, right)
end


array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

quicksort(array, 1, length(array))

println(array)
```

