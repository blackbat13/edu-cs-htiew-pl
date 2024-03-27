# Sortowanie przez scalanie

## [Opis problemu](../../../../algorithms/sorting/merge-sort.md)

## Implementacja

```julia linenums="1"
function merge(array, left, right, division)
    mergedLength = right - left
    merged = Array{Int}(undef, mergedLength)
    index1 = left
    index2 = division

    for i in eachindex(merged)
        if index1 >= division || (index2 < right && array[index1] > array[index2])
            merged[i] = array[index2]
            index2 += 1
        else
            merged[i] = array[index1]
            index1 += 1
        end
    end

    for i in eachindex(merged)
        array[left + i - 1] = merged[i]
    end
end

function mergeSort(array, left, right)
    if right - left <= 1
        return
    end

    division = (left + right) ÷ 2

    mergeSort(array, left, division)
    mergeSort(array, division, right)

    merge(array, left, right, division)
end

array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

mergeSort(array, 1, length(array) + 1)

println(array)
```
