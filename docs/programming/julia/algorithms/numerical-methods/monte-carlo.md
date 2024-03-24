# Metoda Monte Carlo

## Opis problemu

{% content-ref url="../../../../algorithms/numerical-methods/monte-carlo.md" %}
[monte-carlo.md](../../../../algorithms/numerical-methods/monte-carlo.md)
{% endcontent-ref %}

## Obliczanie wartości liczby PI

{% code overflow="wrap" lineNumbers="true" %}
```julia
function MonteCarloPi(pointsCount)
    pointsInCircleCount = 0
    centerX = 1
    centerY = 1
    radius = 1

    for i in 1:pointsCount
        x = rand() * 2
        y = rand() * 2
        distance = (x - centerX)^2 + (y - centerY)^2

        if distance <= radius^2
            pointsInCircleCount += 1
        end
    end

    return (4 * pointsInCircleCount) / pointsCount
end


println(MonteCarloPi(100000000))
```
{% endcode %}
