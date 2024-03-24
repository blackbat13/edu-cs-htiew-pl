# Sortowanie gnoma

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/gnome-sort.md" %}
[gnome-sort.md](../../../../algorithms/sorting/gnome-sort.md)
{% endcontent-ref %}

## Implementacja

```kotlin
fun gnomeSort(array: MutableList<Int>) {
    var i = 0
    while (i < array.count()) {
        if (i == 0 || array[i] >= array[i - 1]) {
            i++
        } else {
            val tmp = array[i]
            array[i] = array[i - 1]
            array[i - 1] = tmp
            i--
        }
    }
}

fun main() {
    val array = mutableListOf(7, 3, 0, 1, 5, 2, 5, 19, 10, 5)

    gnomeSort(array)

    println(array)
}
```

### Link do implementacji

{% embed url="https://ideone.com/etOxuN" %}
Sortowanie gnoma
{% endembed %}