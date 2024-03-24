# Sortowanie przez wybieranie

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/selection-sort.md" %}
[selection-sort.md](../../../../algorithms/sorting/selection-sort.md)
{% endcontent-ref %}

## Implementacja

```kotlin
fun findMin(array: MutableList<Int>, begin: Int): Int {
    var minIndex = begin
    
    for (i in begin + 1 until array.count()) {
        if (array[i] < array[minIndex]) {
            minIndex = i
        }
    }

    return minIndex
}

fun selectionSort(array: MutableList<Int>) {
    for (i in array.indices) {
        val minIndex = findMin(array, i)
        val tmp = array[i]
        array[i] = array[minIndex]
        array[minIndex] = tmp
    }
}

fun main() {
    val array = mutableListOf(7, 3, 0, 1, 5, 2, 5, 19, 10, 5)

    selectionSort(array)

    println(array)
}
```

### Link do implementacji

{% embed url="https://ideone.com/EM3UPA" %}
Sortowanie przez wybieranie
{% endembed %}

### Opis implementacji

Powyższa implementacja składa się z dwóch funkcji: 

* pomocniczej funkcji `findMin` znajdującej indeks najmniejszej wartości na liście, począwszy od podanej pozycji,
* głównej funkcji sortującej metodą sortowania przez wybieranie `selectionSort`

Funkcja `findMin` przyjmuje dwa argumenty: listę do przeszukania (zmienna `array`) oraz indeks elementu, od którego powinniśmy zacząć nasze poszukiwania (zmienna `begin`). Proces znajdowania indeksu wartości minimalnej wygląda standardowo: najpierw zakładamy, że wartość najmniejsza znajduje się w początkowej pozycji (**linia 2**), a następnie przechodzimy pętlą przez pozostałą część listy (**linia 4**). Gdy znajdziemy element o wartości mniejszej niż dotychczasowe minimum (**linia 5**) to zapisujemy jego indeks (**linia 6**). Po sprawdzeniu wszystkich elementów, zwracamy wynik - indeks najmniejszego elementu na liście od wskazanej pozycji (**linia 10**).

Właściwe sortowanie składa się z jednej pętli, w której przechodzimy przez kolejne pozycje na sortowanej liście (**linia 14**), znajdujemy indeks elementu najmniejszego, począwszy od bieżącej pozycji (**linia 15**), a następnie zamieniamy go miejscami z elementem na bieżącej pozycji (**linie 16-18**).

