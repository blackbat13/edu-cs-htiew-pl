# Sortowanie odd-even

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/odd-even-sort.md" %}
[odd-even-sort.md](../../../../algorithms/sorting/odd-even-sort.md)
{% endcontent-ref %}

## Implementacja

```kotlin
fun oddEvenSort(array: MutableList<Int>) {
    for (i in array.indices) {
        for (j in i % 2 + 1 until array.count() step 2) {
            if (array[j] < array[j - 1]) {
                val tmp = array[j]
                array[j] = array[j - 1]
                array[j - 1] = tmp
            }
        }
    }
}

fun main() {
    val array = mutableListOf(7, 3, 0, 1, 5, 2, 5, 19, 10, 5)

    oddEvenSort(array)

    println(array)
}
```

### Link do implementacji

{% embed url="https://ideone.com/ZfC5Rh" %}
Sortowanie odd-even
{% endembed %}