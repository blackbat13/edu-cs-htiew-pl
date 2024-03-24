# Sortowanie przez scalanie

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/merge-sort.md" %}
[merge-sort.md](../../../../algorithms/sorting/merge-sort.md)
{% endcontent-ref %}

## Implementacja

```kotlin
fun merge(array: MutableList<Int>, left: Int, right: Int, division: Int) {
    val mergedLength = right - left
    val merged = Array<Int>(mergedLength){0}
    var index1 = left
    var index2 = division

    for(i in 0 until mergedLength) {
        if(index1 >= division) {
            merged[i] = array[index2]
            index2++
        } else if(index2 >= right) {
            merged[i] = array[index1]
            index1++
        } else if(array[index1] <= array[index2]) {
            merged[i] = array[index1]
            index1++
        } else {
            merged[i] = array[index2]
            index2++
        }
    }

    for(i in left until right) {
        array[i] = merged[i - left]
    }
}

fun mergeSort(array: MutableList<Int>, left: Int, right: Int) {
    if(right - left <= 1) {
        return;
    }

    val division = (left + right) / 2
    mergeSort(array, left, division)
    mergeSort(array, division, right)

    merge(array, left, right, division)
}

fun main() {
    val array = mutableListOf(7, 3, 0, 1, 5, 2, 5, 19, 10, 5)

    mergeSort(array, 0, array.count())

    println(array)
}
```

### Link do implementacji

{% embed url="https://ideone.com/P8XQMA" %}
Sortowanie przez scalanie
{% endembed %}