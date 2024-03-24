# Całkowanie numeryczne

## Opis problemu

{% content-ref url="../../../../algorithms/numerical-methods/numerical-integration.md" %}
[numerical-integration.md](../../../../algorithms/numerical-methods/numerical-integration.md)
{% endcontent-ref %}

## Metoda prostokątów

```kotlin
fun f(x: Double): Double {
    return x * x + 2 * x
}

fun rectanglesMethod(a: Int, b: Int, n: Int): Double {
    val rectangleWidth = (b - a).toDouble() / n.toDouble()
    var area = 0.0
    var currentPoint = a.toDouble()

    for (i in 1..n) {
        currentPoint += rectangleWidth
        val rectangleHeight = f(currentPoint)
        area += rectangleHeight * rectangleWidth
    }

    return area
}


fun main() {
    val a = 0
    val b = 10
    val n = 100
    
    val area = rectanglesMethod(a, b, n)
    
    println(area)
}
```

### Link do implementacji

{% embed url="https://ideone.com/MnVUpY" %}
Całkowanie numeryczne - metoda prostokątów
{% endembed %}

## Metoda trapezów

```kotlin
fun f(x: Double): Double {
    return x * x + 2 * x
}

fun trapezesMethod(a: Int, b: Int, n: Int): Double {
    val trapezeHeight = (b - a).toDouble() / n.toDouble()
    var area = 0.0
    var currentPoint = a.toDouble()

    for (i in 1..n) {
        val trapezeFirstSide = f(currentPoint)
        currentPoint += trapezeHeight
        val trapezeSecondSide = f(currentPoint)
        area += ((trapezeFirstSide + trapezeSecondSide) * trapezeHeight) / 2
    }

    return area
}

fun main() {
    val a = 0
    val b = 10
    val n = 100
    
    val area = trapezesMethod(a, b, n)
    
    println(area)
}
```

### Link do implementacji

{% embed url="https://ideone.com/4lw4tL" %}
Całkowanie numeryczne - metoda trapezów
{% endembed %}