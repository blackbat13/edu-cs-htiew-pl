# Znajdowanie lidera w zbiorze

## [Opis problemu](../../../../algorithms/searching/majority.md)

## Implementacja

```kotlin
fun countOccurrences(element: Int, array: List<Int>): Int {
  var count = 0

  for (el in array) {
    if (el == element) {
      count += 1
    }
  }

  return count
}

fun findMajority(array: List<Int>): Int {
  var counter = 0
  var currentCandidate = 0

  for (el in array) {
    if(counter == 0) {
      currentCandidate = el
      counter = 1
    } else if (el == currentCandidate) {
      counter += 1
    } else {
      counter -= 1
    }
  }

  if (countOccurrences(currentCandidate, array) >= array.count() / 2) {
    return currentCandidate
  } else {
    return -1
  }
}

fun main() {
  val array = listOf(1, 2, 5, 5, 7, 5, 5, 10, 5, 5)

  val majority = findMajority(array)

  if (majority == -1) {
    println("Nie ma lidera")
  } else {
    println("Lider to $majority")
  }
}
```

### Link do implementacji

[Znajdowanie lidera w zbiorze](https://ideone.com/btfNVv)

### Opis implementacji

TODO
