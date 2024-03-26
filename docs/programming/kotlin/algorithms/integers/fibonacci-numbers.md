# Liczby Fibonacciego

## [Opis problemu](../../../../algorithms/integers/fibonacci-numbers.md)


## Wersja iteracyjna

### Implementacja

```kotlin
fun fib(n: Int): Int {
  var f1 = 1
  var f2 = 1

  for (i in 3 until n + 1) {
    val f3 = f1 + f2
    f1 = f2
    f2 = f3
  }

  return f2
}

fun main() {
  val n = 10

  val result = fib(n)

  println("fib($n) = $result")
}
```

### Link do implementacji

[Liczby Fibonacciego - wersja iteracyjna](https://ideone.com/4JCa5w)

### Opis implementacji

TODO

## Wersja rekurencyjna

### Implementacja

```kotlin
fun fib(n: Int): Int {
  if (n <= 2) {
    return 1
  }

  return fib(n - 1) + fib(n - 2)
}

fun main() {
  val n = 10

  val result = fib(n)

  println("fib($n) = $result")
}
```

### Link do implementacji

[Liczby Fibonacciego - wersja rekurencyjna](https://ideone.com/cBKjhg)

### Opis implementacji

TODO

