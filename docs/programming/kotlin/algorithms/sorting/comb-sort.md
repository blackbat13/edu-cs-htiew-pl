# Sortowanie grzebieniowe

## [Opis problemu](../../../../algorithms/sorting/comb-sort.md)


## Implementacja

```kotlin
fun combSort(array: MutableList<Int>) {
    var gap = array.count()
    val shrink = 1.3
    var sorted = false
    while (!sorted) {
        gap = (gap / shrink).toInt()
        if (gap <= 1) {
            gap = 1
            sorted = true
        }

        var i = 0
        while (i + gap < array.count()) {
            if (array[i] > array[i + gap]) {
                val tmp = array[i]
                array[i] = array[i + gap]
                array[i + gap] = tmp
                sorted = false
            }

            i++
        }
    }
}


fun main() {
    val array = mutableListOf(7, 3, 0, 1, 5, 2, 5, 19, 10, 5)
    
    combSort(array)
        
    println(array)
}
```

### Link do implementacji

[Sortowanie grzebieniowe](https://ideone.com/WJ7PjF)