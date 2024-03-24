# Sortowanie przez kopcowanie

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/heap-sort.md" %}
[heap-sort.md](../../../../algorithms/sorting/heap-sort.md)
{% endcontent-ref %}

## Implementacja

```kotlin
fun buildHeap(array: MutableList<Int>, n: Int) {
    for (i in 1 until n) {
        var parentIndex = (i - 1) / 2
        var j = i
        
        while (j > 0 && array[j] > array[parentIndex]) {
            val tmp = array[j]
            array[j] = array[parentIndex]
            array[parentIndex] = tmp
            j = parentIndex
            parentIndex = (j - 1) / 2
        }
    }
}
            

fun heapSort(array: MutableList<Int>) {
    for (i in array.count() - 1 downTo 1) {
        buildHeap(array, i + 1)
        val tmp = array[0]
        array[0] = array[i]
        array[i] = tmp
    }
}

fun main() {
    val array = mutableListOf(7, 3, 0, 1, 5, 2, 5, 19, 10, 5)

    heapSort(array)

    println(array)
}
```

### Link do implementacji

{% embed url="https://ideone.com/spy6YJ" %}
Sortowanie przez kopcowanie
{% endembed %}