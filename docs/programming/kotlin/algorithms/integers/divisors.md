# Wszystkie dzielniki

## Opis problemu

{% content-ref url="../../../../algorithms/integers/divisors.md" %}
[divisors.md](../../../../algorithms/integers/divisors.md)
{% endcontent-ref %}

## Rozwiązanie zupełnie naiwne

### Implementacja

```kotlin
fun printDivisors(n: Int) {
  for (i in 1 until n + 1) {
    if (n % i == 0) {
      println(i)
    }
  }
}

fun main() {
  val n = 12

  println("Dzielniki liczby $n:")
  printDivisors(n)
}
```

### Link do implementacji

{% embed url="https://ideone.com/hfECmZ" %}
Wszystkie dzielniki - podejście zupełnie naiwne
{% endembed %}

### Opis implementacji

TODO

## Rozwiązanie naiwne

### Implementacja

```kotlin
fun printDivisors(n: Int) {
  for (i in 1 until (n / 2) + 1) {
    if (n % i == 0) {
      println(i)
    }
  }

  if (n > 1) {
    println(n)
  }
}

fun main() {
  val n = 12

  println("Dzielniki liczby $n:")
  printDivisors(n)
}
```

### Link do implementacji

{% embed url="https://ideone.com/iD7tJJ" %}
Wszystkie dzielniki - podejście naiwne
{% endembed %}

### Opis implementacji

TODO

## Rozwiązanie optymalne

### Implementacja

```kotlin
import kotlin.math.sqrt


fun printDivisors(n: Int) {
  for (i in 1 until sqrt(n.toDouble()).toInt() + 1) {
    if (n % i == 0) {
      println(i)

      if (i != n / i) {
        println(n / i)
      }
    }
  }
}

fun main() {
  val n = 12

  println("Dzielniki liczby $n:")
  printDivisors(n)
}
```

### Link do implementacji

{% embed url="https://ideone.com/m5v9Hi" %}
Wszystkie dzielniki - podejście optymalne
{% endembed %}

### Opis implementacji

TODO
