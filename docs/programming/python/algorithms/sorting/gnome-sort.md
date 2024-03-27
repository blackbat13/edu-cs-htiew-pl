# Sortowanie gnoma

## [Opis problemu](../../../../algorithms/sorting/gnome-sort.md)

## Implementacja

```python linenums="1"
def gnome_sort(array: list):
    i = 0
    while i < len(array):
        if i == 0 or array[i] >= array[i - 1]:
            i += 1
        else:
            array[i], array[i - 1] = array[i - 1], array[i]
            i -= 1

array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

gnome_sort(array)
    
print(array)
```

### Opis implementacji

Funkcja `gnome_sort` (**linia 1**) przyjmuje tylko jeden argument: listę elementów do posortowania. Wewnątrz funkcji zaczynamy od stworzenia licznika zapamiętującego obecną pozycję na liście (**linia 2**). Następnie przechodzimy pętlą warunkową dopóki nie dotrzemy do końca listy (**linia 3**). Wewnątrz pętli sprawdzamy, czy znajdujemy się na początkowej pozycji na liście lub czy obecny element jest większy bądź równy od poprzedniego (**linia 4**). Jeżeli tak jest, to przechodzimy do kolejnego elementu poprzez zwiększenie licznika (**linia 5**). W przeciwnym przypadku (**linia 6**) zamieniamy obecny element na liście z poprzednim (**linia 7**) i cofamy się do poprzedniego elementu na liście poprzez zmniejszenie licznika (**linia 8**).

W części głównej przygotowujemy listę elementów do posortowania (**linia 11**), następnie sortujemy listę (**linia 13**) i wypisujemy ją na ekranie (**linia 15**).