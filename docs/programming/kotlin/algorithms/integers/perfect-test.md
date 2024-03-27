# Test doskonałości

## [Opis problemu](../../../../algorithms/integers/perfect-test.md)

## Implementacja

```kotlin
fun isPerfect(n: Int): Boolean {
  var sum = 0

  for (i in 1 until n) {
    if (n % i == 0) {
      sum += i
    }
  }

  return sum == n
}

fun main() {
  val n = 6

  val result = isPerfect(n)

  if (result) {
    println("$n jest liczba doskonala")
  } else {
    println("$n nie jest liczba doskonala")
  }
}
```

### Link do implementacji

[Test doskonałości](https://ideone.com/FVvc2L)

### Opis implementacji

TODO
