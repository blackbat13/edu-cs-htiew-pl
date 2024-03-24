# Sortowanie przez wybieranie

## Opis problemu

{% content-ref url="../../../../algorithms/sorting/selection-sort.md" %}
[selection-sort.md](../../../../algorithms/sorting/selection-sort.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
def find_min(array: list, begin: int) -> int:
    min_index = begin
    
    for i in range(begin + 1, len(array)):
        if array[i] < array[min_index]:
            min_index = i

    return min_index


def selection_sort(array: list):
    for i in range(len(array)):
        min_index = find_min(array, i)
        array[i], array[min_index] = array[min_index], array[i]


array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

selection_sort(array)

print(array)
```
{% endcode %}

### Opis implementacji

Powyższa implementacja składa się z dwóch funkcji: 

* pomocniczej funkcji `find_min` znajdującej indeks najmniejszej wartości na liście, począwszy od podanej pozycji,
* głównej funkcji sortującej metodą sortowania przez wybieranie `selection_sort`

Funkcja `find_min` przyjmuje dwa argumenty: listę do przeszukania (zmienna `array`) oraz indeks elementu, od którego powinniśmy zacząć nasze poszukiwania (zmienna `begin`). Proces znajdowania indeksu wartości minimalnej wygląda standardowo: najpierw zakładamy, że wartość najmniejsza znajduje się w początkowej pozycji (**linia 2**), a następnie przechodzimy pętlą przez pozostałą część listy (**linia 4**). Gdy znajdziemy element o wartości mniejszej niż dotychczasowe minimum (**linia 5**) to zapisujemy jego indeks (**linia 6**). Po sprawdzeniu wszystkich elementów, zwracamy wynik - indeks najmniejszego elementu na liście od wskazanej pozycji (**linia 8**).

Właściwe sortowanie składa się z jednej pętli, w której przechodzimy przez kolejne pozycje na sortowanej liście (**linia 12**), znajdujemy indeks elementu najmniejszego, począwszy od bieżącej pozycji (**linia 13**), a następnie zamieniamy go miejscami z elementem na bieżącej pozycji (**linia 14**).
