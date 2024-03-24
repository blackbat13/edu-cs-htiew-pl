# Sortowanie bąbelkowe

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/bubble-sort.md" %}
[bubble-sort.md](../../../../algorithms/sorting/bubble-sort.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```kotlin
fun bubbleSort(array: MutableList<Int>) {
	var sorted = false
	var i = 1
    while (!sorted) {
    	sorted = true
        for(j in array.count() - 1 downTo i) {
            if(array[j] < array[j - 1]) {
                val tmp = array[j]
                array[j] = array[j - 1]
                array[j - 1] = tmp
                sorted = false
            }
        }
        
        i++
    }
}

fun main() {
    val array = mutableListOf(7, 3, 0, 1, 5, 2, 5, 19, 10, 5)

    bubbleSort(array)

    println(array)
}
```
{% endcode %}

### Opis implementacji

Zaczynamy od utworzenia funkcji sortującej *bubbleSort* (**linia 1**), która przyjmuje jeden argument: listę elementów do posortowania. Przekazywana lista jest typu *MutableList*, ponieważ będziemy modyfikować jej elementy.

Wewnątrz funkcji tworzymy zmienne pomocnicze do pamiętania, czy lista jest już posortowana (**linia 2**) oraz do pamiętania liczby posortowanych elementów (**linia 3**). Następnie uruchamiamy pętlę, która będzie wykonywać operacje aż do posortowania całej listy (**linia 4**). W pętli na początku zakładamy, że lista została już posortowana (**linia 5**), a następnie zaczynamy kolejną pętlę przechodzącą indeksami od końca tablicy do jej początku, uwzględniając liczbę posortowanych już elementów (**linia 6**). W tej zagnieżdżonej pętli porównujemy ze sobą sąsiednie elementy listy (**linia 7**), a gdy są ułożone niezgodnie z porządkiem sortowania, to zamieniamy je miejscami (**linie 8-10**). Zapamiętujemy także, że lista nie została jeszcze posortowana, ponieważ dokonaliśmy zamiany (**linia 11**). Po wyjściu z zagnieżdżonej pętli zwiększamy licznik posortowanych elementów (**linia 15**).

W części głównej (**linia 19**) tworzymy listę do sortowania (**linia 20**), sortujemy ją wywołując naszą funkcję sortującą *bubbleSort* (**linia 22**) i wypisujemy posortowaną listę na ekranie (**linia 24**).
