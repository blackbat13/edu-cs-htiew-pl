# Wyszukiwanie minimum i maksimum

## [:link: Opis problemu](../../../../algorithms/searching/min-or-max.md)

## Wyszukiwanie wartości minimum i maksimum

### Implementacja

```kotlin
fun findMinVal(array: List<Int>): Int {
  var minVal = array[0]

  for (el in array) {
    if (el < minVal) {
      minVal = el
    }
  }

  return minVal
}

fun findMaxVal(array: List<Int>): Int {
  var maxVal = array[0]

  for(el in array) {
    if(el > maxVal) {
      maxVal = el
    }
  }

  return maxVal
}

fun main() {
  val array = listOf(8, 2, 9, 10, 5, 4, 2, 7, 18, 0)

  val minVal = findMinVal(array)
  val maxVal = findMaxVal(array)

  println("Min: $minVal")
  println("Max: $maxVal")
}
```

### Link do implementacji

[Wyszukiwanie wartości minimum i maksimum](https://ideone.com/ksC9K4)

### Opis implementacji

TODO

## Wyszukiwanie indeksów wartości minimum i maksimum

### Implementacja

```kotlin
fun findMinInd(array: List<Int>): Int {
  var minInd = 0

  for (i in array.indices) {
    if (array[i] < array[minInd]) {
      minInd = i
    }
  }

  return minInd
}

fun findMaxInd(array: List<Int>): Int {
  var maxInd = 0

  for(i in array.indices) {
    if(array[i] > array[maxInd]) {
      maxInd = i
    }
  }

  return maxInd
}

fun main() {
  val array = listOf(8, 2, 9, 10, 5, 4, 2, 7, 18, 0)

  val minInd = findMinInd(array)
  val maxInd = findMaxInd(array)

  println("Wartosc minimum znajduje sie na pozycji: $minInd")
  println("Wartosc maximum znajduje sie na pozycji: $maxInd")
}
```

### Link do implementacji

[Wyszukiwanie indeksów wartości min i maks](https://ideone.com/bA2kuB)

### Opis implementacji

TODO
