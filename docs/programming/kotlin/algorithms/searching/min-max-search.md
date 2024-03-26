# Jednoczesne wyszukiwanie minimum i maksimum

## [Opis problemu](../../../../algorithms/searching/min-max-search.md)


## Podejście naiwne

### Implementacja

```kotlin
fun findMinMax(array: List<Int>): Pair<Int,Int> {
  var min = array[0]
  var max = array[0]

  for (el in array) {
    if (el < min) {
      min = el
    } else if (el > max) {
      max = el
    }
  }

  return Pair(min, max)
}

fun main() {
  val array = listOf(3, 6, 1, 9, 10, 4, -4, 6, 12, 5, 11)

  val (min, max) = findMinMax(array)

  println("Minimum: $min, Maximum: $max")
}
```

### Link do implementacji

[Jednoczesne wyszukiwanie minimum i maksimum - podejście naiwne](https://ideone.com/freoSQ)

### Opis implementacji

TODO

## Podejście optymalne

```kotlin
fun findMinMax(array: List<Int>): Pair<Int,Int> {
  var minCandidates = mutableListOf<Int>()
  var maxCandidates = mutableListOf<Int>()

  for (i in 1 until array.count() step 2) {
    if (array[i - 1] < array[i]) {
      minCandidates.add(array[i - 1])
      maxCandidates.add(array[i])
    } else {
      minCandidates.add(array[i])
      maxCandidates.add(array[i - 1])
    }
  }

  if (array.count() % 2 != 0) {
    minCandidates.add(array[array.count() - 1])
    maxCandidates.add(array[array.count() - 1])
  }

  var min = minCandidates[0]
  var max = maxCandidates[0]

  for (i in minCandidates.indices) {
    if (min > minCandidates[i]) {
      min = minCandidates[i]
    }

    if (max < maxCandidates[i]) {
      max = maxCandidates[i]
    }
  }

  return Pair(min, max)
}

fun main() {
  val array = listOf(3, 6, 1, 9, 10, 4, -4, 6, 12, 5, 11)

  val (min, max) = findMinMax(array)

  println("Minimum: $min, Maximum: $max")
}
```

### Link do implementacji

[Jednoczesne wyszukiwanie minimum i maksimum - podejście optymalne](https://ideone.com/r8KFFR)

### Opis implementacji

TODO
