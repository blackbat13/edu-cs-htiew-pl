# Jednoczesne wyszukiwanie minimum i maksimum

## [:link: Opis problemu](../../../../algorithms/searching/min-max-search.md)

## Podejście naiwne

## Podejście optymalne

```julia linenums="1"
function MinMax(array)
    minCandidates = []
    maxCandidates = []

    for i in 2:2:length(array)
        if array[i - 1] < array[i]
            push!(minCandidates, array[i - 1])
            push!(maxCandidates, array[i])
        else
            push!(minCandidates, array[i])
            push!(maxCandidates, array[i - 1])
        end
    end
    
    if length(array) % 2 == 1
        push!(minCandidates, array[end])
        push!(maxCandidates, array[end])
    end
    
    minValue = minCandidates[1]
    maxValue = maxCandidates[1]

    for i in eachindex(minCandidates)
        minValue = min(minValue, minCandidates[i])
        maxValue = max(maxValue, maxCandidates[i])
    end

    return minValue, maxValue
end

array = [3, 6, 1, 9, 10, 4, -4, 6, 12, 5, 11]
println(MinMax(array))
```
