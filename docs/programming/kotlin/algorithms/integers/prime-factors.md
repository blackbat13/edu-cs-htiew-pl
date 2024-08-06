# Rozkład na czynniki pierwsze

## [:link: Opis problemu](../../../../algorithms/integers/prime-factors.md)

## Implementacja

```kotlin
fun distribute(num: Int): List<Int> {
  var primeFactors: MutableList<Int> = mutableListOf()
  var i = 2
  var n = num

  while (n > 1) {
    if (n % i == 0) {
      primeFactors.add(i)
      n /= i
    } else {
      i++
    }
  }

  return primeFactors
}

fun main() {
  val n = 124

  val result = distribute(n)

  println("Czynniki pierwsze liczby $n: $result")
}
```

### Link do implementacji

[Rozkład na czynniki pierwsze](https://ideone.com/VAB2Jl)

### Opis implementacji

TODO
