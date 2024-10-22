# Wyszukiwanie minimum i maksimum

## [:link: Opis problemu](../../../../algorithms/searching/min-or-max.md)

## Wyszukiwanie wartości minimum i maksimum

### Implementacja

```julia linenums="1"
function findMinMax(array)
    minVal = array[1]
    maxVal = array[1]

    for el in array
        if el < minVal
            minVal = el
        elseif el > maxVal
            maxVal = el
        end
    end

    return min, max
end

array = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0]

println("Values: ", findMinMax(array))
```

## Wyszukiwanie indeksów wartości minimum i maksimum

### Implementacja

```julia linenums="1"
function findMinMaxIndex(array)
    minVal = array[1]
    minInd = 1
    maxVal = array[1]
    maxInd = 1

    for i in eachindex(array)
        if array[i] < minVal
            minVal = array[i]
            minInd = i
        elseif array[i] > maxVal
            maxVal = array[i]
            maxInd = i
        end
    end

    return minInd, maxInd
end

array = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0]
    
println("Indexes: ", findMinMaxIndex(array))
```
