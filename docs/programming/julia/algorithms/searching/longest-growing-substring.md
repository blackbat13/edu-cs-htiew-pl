# Najdłuższy spójny podciąg rosnący

## Opis problemu

{% content-ref url="../../../../algorithms/searching/longest-growing-substring.md" %}
[longest-growing-substring.md](../../../../algorithms/searching/longest-growing-substring.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```julia
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
{% endcode %}
