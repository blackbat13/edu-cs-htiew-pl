# Sortowanie szybkie

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/quick-sort.md" %}
[quick-sort.md](../../../../algorithms/sorting/quick-sort.md)
{% endcontent-ref %}

## Implementacja

```kotlin
fun quickSort(array: MutableList<Int>, left: Int, right: Int) {
    if (right <= left) {
        return
    }

    val pivot = array[(left + right) / 2]
    var i = left
    var j = right

    while (i <= j) {
        while (array[i] < pivot) {
            i += 1
        }

        while (array[j] > pivot) {
            j -= 1
        }

        if (i > j) {
            break
        } 

        val tmp = array[i]
        array[i] = array[j]
        array[j] = tmp

        i++
        j--
    }
    
    quickSort(array, left, j)
    quickSort(array, i, right)
}

fun main() {
    val array = mutableListOf(7, 3, 0, 1, 5, 2, 5, 19, 10, 5)

    quickSort(array, 0, array.count() - 1)

    println(array)
}
```

### Link do implementacji

{% embed url="https://ideone.com/vwYIuK" %}
Sortowanie szybkie
{% endembed %}