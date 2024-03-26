# Szybkie potęgowanie

## [Opis problemu](../../../../algorithms/numerical-methods/fast-exp.md)


## Rozwiązanie iteracyjne

```julia linenums="1"
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

