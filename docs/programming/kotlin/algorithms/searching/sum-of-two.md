# Suma dwóch liczb

## Opis problemu

{% content-ref url="../../../../algorithms/searching/sum-of-two.md" %}
[sum-of-two.md](../../../../algorithms/searching/sum-of-two.md)
{% endcontent-ref %}

## Rozwiązanie naiwne

### Implementacja

```kotlin
fun sumOfTwo(array: List<Int>, sum: Int) {
  for (i in array.indices) {
    for (j in i + 1 until array.count()) {
      if (array[i] + array[j] == sum) {
        println("${array[i]} + ${array[j]} = $sum")
      }
    }
  }
}

fun main() {
  val array = listOf(1, 2, 4, 6, 8, 9, 10, 12, 13, 15)
  val sum = 18

  sumOfTwo(array, sum)
}
```

### Link do implementacji

{% embed url="https://ideone.com/AJ50ho" %}
Suma dwóch - rozwiązanie naiwne
{% endembed %}

### Opis implementacji

TODO

## Rozwiązanie optymalne

### Implementacja

```kotlin
fun sumOfTwo(array: List<Int>, sum: Int) {
  var left = 0
  var right = array.count() - 1

  while (left < right && array[left] + array[right] != sum) {
    if (array[left] + array[right] < sum) {
      left += 1
    } else {
      right -= 1
    }
  }

  if (left < right) {
    println("${array[left]} + ${array[right]} = $sum")
  } else {
    println("Nie znaleziono pary dajacej pozadana sume")
  }
}

fun main() {
  val array = listOf(1, 2, 4, 6, 8, 9, 10, 12, 13, 15)
  val sum = 18

  sumOfTwo(array, sum)
}
```

### Link do implementacji

{% embed url="https://ideone.com/MXQjLX" %}
Suma dwóch - rozwiązanie optymalne
{% endembed %}

### Opis implementacji

TODO
