---
description: Największy Wspólny Dzielnik
---

# NWD

## Opis problemu

{% content-ref url="../../../../algorithms/integers/gcd.md" %}
[gcd.md](../../../../algorithms/integers/gcd.md)
{% endcontent-ref %}

## Algorytm NWD z odejmowaniem

### Implementacja

```kotlin
fun gcd(num1: Int, num2: Int): Int {
  var a = num1
  var b = num2

  while (a != b) {
    if (a > b) {
      a -= b
    } else {
      b -= a
    }
  }

  return a
}

fun main() {
  val a = 32
  val b = 12

  val result = gcd(a, b)

  println("GCD($a, $b) = $result")
}
```

### Link do implementacji

{% embed url="https://ideone.com/4NLzXI" %}
NWD z odejmowaniem
{% endembed %}

### Opis implementacji

TODO

## Algorytm Euklidesa - wersja iteracyjna

### Implementacja

```kotlin
fun gcd(num1: Int, num2: Int): Int {
  var a = num1
  var b = num2

  while (b != 0) {
    val b2 = b
    b = a % b
    a = b2
  }

  return a
}

fun main() {
  val a = 32
  val b = 12

  val result = gcd(a, b)

  println("GCD($a, $b) = $result")
}
```

### Link do implementacji

{% embed url="https://ideone.com/VUGRIi" %}
Algorytm Euklidesa - wersja iteracyjna
{% endembed %}

### Opis implementacji

TODO

## Algorytm Euklidesa - wersja rekurencyjna

### Implementacja

```kotlin
fun gcd(a: Int, b: Int): Int {
  if (b == 0) {
    return a
  }

  return gcd(b, a % b)
}

fun main() {
  val a = 32
  val b = 12

  val result = gcd(a, b)

  println("GCD($a, $b) = $result")
}
```

### Link do implementacji

{% embed url="https://ideone.com/F52FKB" %}
Algorytm Euklidesa - wersja rekurencyjna
{% endembed %}

### Opis implementacji

TODO
