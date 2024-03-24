# Najdłuższy spójny podciąg rosnący

## Opis problemu

{% content-ref url="../../../../algorithms/searching/longest-growing-substring.md" %}
[longest-growing-substring.md](../../../../algorithms/searching/longest-growing-substring.md)
{% endcontent-ref %}

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

{% embed url="https://ideone.com/iKkowC" %}
Długość najdłuższego spójnego podciągu rosnącego
{% endembed %}

### Opis implementacji

TODO