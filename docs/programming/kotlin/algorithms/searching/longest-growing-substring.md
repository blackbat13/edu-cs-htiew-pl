# Najdłuższy spójny podciąg rosnący

## [:link: Opis problemu](../../../../algorithms/searching/longest-growing-substring.md)

## Implementacja

```kotlin
fun longestGrowingSubstringLength(array: List<Int>): Int {
  var maxLength = 1
  var currentLength = 1

  for (i in 1 until array.count()) {
    if (array[i] > array[i - 1]) {
      currentLength += 1
      if (currentLength > maxLength) {
        maxLength = currentLength
      }
    } else {
      currentLength = 1
    }
  }

  return maxLength
}

fun main() {
  val array = listOf(4, 9, 7, 2, 4, 7, 9, 3, 8, 6)

  val result = longestGrowingSubstringLength(array)

  println("Dlugosc najdluzszego rosnacego spojnego podciagu wynosi $result")
}
```

### Link do implementacji

[Długość najdłuższego spójnego podciągu rosnącego](https://ideone.com/iKkowC)

### Opis implementacji

TODO