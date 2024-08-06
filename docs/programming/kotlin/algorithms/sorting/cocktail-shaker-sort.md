# Sortowanie koktajlowe

## [:link: Opis problemu](../../../../algorithms/sorting/cocktail-shaker-sort.md)

## Implementacja

```kotlin
fun cocktailShakerSort(array: MutableList<Int>) {
    for (i in 0 until array.count() / 2 + 1) {
        for (j in i until array.count() - i - 1) {
            if (array[j] > array[j + 1]) {
                val tmp = array[j]
                array[j] = array[j + 1]
                array[j + 1] = tmp
            }
        }
        
        for (j in array.count() - 1 - i downTo i + 1) {
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
    
    cocktailShakerSort(array)
        
    println(array)
}
```

### Link do implementacji

[Sortowanie koktajlowe](https://ideone.com/oNNYmV)