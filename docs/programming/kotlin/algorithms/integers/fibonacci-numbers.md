# Liczby Fibonacciego

## Opis problemu

{% content-ref url="../../../../algorithms/integers/fibonacci-numbers.md" %}
[fibonacci-numbers.md](../../../../algorithms/integers/fibonacci-numbers.md)
{% endcontent-ref %}

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

{% embed url="https://ideone.com/4JCa5w" %}
Liczby Fibonacciego - wersja iteracyjna
{% endembed %}

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

{% embed url="https://ideone.com/cBKjhg" %}
Liczby Fibonacciego - wersja rekurencyjna
{% endembed %}

### Opis implementacji

TODO

