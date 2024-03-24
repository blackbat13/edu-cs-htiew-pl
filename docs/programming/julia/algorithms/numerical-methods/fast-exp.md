# Szybkie potęgowanie

## Opis problemu

{% content-ref url="../../../../algorithms/numerical-methods/fast-exp.md" %}
[fast-exp.md](../../../../algorithms/numerical-methods/fast-exp.md)
{% endcontent-ref %}

## Rozwiązanie iteracyjne

{% code overflow="wrap" lineNumbers="true" %}
```julia
function fastExp(a, n)
    result = 1

    while n > 0
        if n % 2 == 1
            result *= a
        end

        a *= a
        n ÷= 2
    end

    return result
end


println(fastExp(2, 10))
```
{% endcode %}
