# Permutacje

## [:link: Opis problemu](../../../../algorithms/backtracking/permutations.md)

## Implementacja

```kotlin linenums="1"
fun permutation(elements: Array<Int>, start: Int, stop: Int) {
    if (start == stop) {
        println(elements.contentToString())
        return
    }

    for (i in start until stop + 1) {
        var tmp = elements[start]
        elements[start] = elements[i]
        elements[i] = tmp

        permutation(elements, start + 1, stop)

        tmp = elements[start]
        elements[start] = elements[i]
        elements[i] = tmp
    }
}

fun main() {
  val elements = arrayOf(1, 2, 3)

  println("Permutacje:")
  permutation(elements, 0, 2)
}
```
