# Test pierwszości

## [Opis problemu](../../../../algorithms/integers/prime-test.md)

## Implementacja

```kotlin
import kotlin.math.sqrt

fun isPrime(n: Int): Boolean {
  if (n < 2) {
    return false
  }

  for (i in 2 until sqrt(n.toDouble()).toInt() + 1) {
    if (n % i == 0) {
      return false
    }
  }

  return true
}

fun main() {
  val n = 7

  val result = isPrime(n)

  if (result) {
    println("$n jest liczba pierwsza")
  } else {
    println("$n nie jest liczba pierwsza")
  }
}
```

### Link do implementacji

[Test pierwszości](https://ideone.com/eVaqy4)

### Opis implementacji

TODO
