# Jednoczesne wyszukiwanie minimum i maksimum

## Opis problemu

{% content-ref url="../../../../algorithms/searching/min-max-search.md" %}
[min-max-search.md](../../../../algorithms/searching/min-max-search.md)
{% endcontent-ref %}

## Podejście naiwne

## Podejście optymalne

{% code overflow="wrap" lineNumbers="true" %}
```julia
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
{% endcode %}
