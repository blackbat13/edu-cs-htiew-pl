# Najdłuższy spójny podciąg rosnący

## [Opis problemu](../../../../algorithms/searching/longest-growing-substring.md)


## Implementacja

```julia linenums="1"
function longestGrowingSubstring(array)
    maxLength = 1
    currentLength = 1

    for i in 2:length(array)
        if array[i] > array[i - 1]
            currentLength += 1
            maxLength = max(maxLength, currentLength)
        else
            currentLength = 1
        end
    end

    return maxLength
end


array = [4, 9, 7, 2, 4, 7, 9, 3, 8, 6]

println(longestGrowingSubstring(array))
```

