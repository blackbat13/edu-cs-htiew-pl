# Sito Eratostenesa

## [:link: Opis problemu](../../../../algorithms/integers/eratosthenes-sieve.md)

## Implementacja

```kotlin
fun sieve(n: Int): List<Boolean> {
  var primes = mutableListOf(false, false)

  for (i in 2 until n + 1) {
    primes.add(true)
  }

  for (i in 2 until n) {
    if (!primes[i]) {
      continue
    }

    for (j in 2 * i until n + 1 step i) {
      primes[j] = false
    }
  }

  return primes
}

fun printPrimeNumbers(primes: List<Boolean>) {
  for (i in 0 until primes.count()) {
    if (primes[i]) {
      println(i)
    }
  }
}

fun main() {
  val n = 100

  val primes = sieve(n)

  println("Liczby pierwsze od 1 do $n:")
  printPrimeNumbers(primes)
}
```

### Link do implementacji

[Sito Eratostenesa](https://ideone.com/GUPgH6)

### Opis implementacji

TODO
