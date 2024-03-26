# Sortowanie szybkie

## [Opis problemu](../../../../algorithms/sorting/quick-sort.md)


## Implementacja

```python linenums="1"
def quick_sort(array: list, left: int, right: int):
    if right <= left:
        return

    pivot = array[(left + right) // 2]
    i = left
    j = right
    
    while i <= j:
        while array[i] < pivot:
            i += 1

        while array[j] > pivot:
            j -= 1

        if i > j:
            break

        array[i], array[j] = array[j], array[i]

        i += 1
        j -= 1

    quick_sort(array, left, j)
    quick_sort(array, i, right)


array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

quick_sort(array, 0, len(array) - 1)

print(array)
```


### Opis implementacji

Funkcja `quick_sort` (**linia 1**) przyjmuje trzy parametry: listę do posortowania (`array`), początek (`left`) oraz koniec (`right`) sortowanego fragmentu listy. Na początku funkcji sprawdzamy warunek stopu rekurencji (**linia 2**). Gdy jest spełniony to kończymy obecne wywołanie funkcji (**linia 3**). Gdy funkcja nie została zakończona, to obliczamy wartość elementu *pivot* biorąc środkową wartość z sortowanego fragmentu listy (**linia 5**). Tworzymy także dwa liczniki do przechodzenia po liście od lewej (**linia 6**) oraz prawej (**linia 7**) strony. Następnie wykonujemy działania w pętli, dopóki liczniki wyznaczają poprawny przedział (**linia 9**). Wewnątrz pętli najpierw przechodzimy pętlą od lewej strony szukając pierwszego elementu większego lub równego wartości elementu *pivot* (**linie 10 i 11**). W kolejnej pętli robimy podobnie, przechodząc od prawej strony szukając pierwszego elementu mniejszego lub równego wartości elementu *pivot* (**linie 13 i 14**). Następnie sprawdzamy, czy definiowany przez liczniki przedział jest błędny (**linia 16**). Jeżeli tak, to wychodzimy z pętli (**linia 17**). Jeżeli nie zakończyliśmy działania pętli, to zamieniamy miejscami dwa elementy listy wyznaczone przez liczniki (**linia 19**) oraz odpowiednio zwiększamy pierwszy licznik (**linia 21**) oraz zmniejszamy drugi (**linia 22**). Po wyjściu z pętli wykonujemy dwa wywołania rekurencyjne, odpowiednio dla lewego fragmentu listy (**linia 24**) oraz dla prawego fragmentu (**linia 25**).

W części głównej tworzymy listę elementów do posortowania (**linia 28**), sortujemy ją (**linia 30**) oraz wypisujemy na ekranie (**linia 32**).