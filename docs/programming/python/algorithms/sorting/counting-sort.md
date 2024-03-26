# Sortowanie przez zliczanie

## [Opis problemu](../../../../algorithms/sorting/counting-sort.md)


## Implementacja

```python linenums="1"
def count_occurrences(array: list) -> list:
    max_number = max(array)
    occurrences = [0] * (max_number + 1)

    for number in array:
        occurrences[number] += 1
        
    return occurrences


def counting_sort(array: list):
    occurrences = count_occurrences(array)

    array.clear()
    
    for i in range(len(occurrences)):
        for j in range(occurrences[i]):
            array.append(i)


array = [7, 3, 0, 1, 5, 2, 5, 19, 10, 5]

counting_sort(array)

print(array)
```


### Opis implementacji

Zaczynamy od stworzenia funkcji `count_occurences` (**linia 1**) służącej do zliczenia wystąpień każdej liczby od zera do maksymalnej wartości w liście. Na początku funkcji zaczynamy od znalezienia maksymalnej wartości w liście (**linia 2**). Następnie tworzymy listę `occurrences` służącą do zliczania liczby wystąpień poszczególnych wartości w liście `array` (**linia 3**). Na początku wypełniamy ją zerami od pozycji 0 do pozycji wyznaczonej przez maksymalny element (zmienna `max_number`). Po utworzeniu listy liczników przechodzimy do zliczania. Dla każdego elementu (zmienna `number`) w liście `array `(**linia 5**) zwiększamy przypisany do tego elementu licznik (**linia 6**). Na koniec funkcji zwracamy jej wynik w postaci listy liczników (**linia 8**).

W następnej kolejności tworzymy funkcję `counting_sort` (**linia 11**) do sortowania przez zliczanie. Funkcja przyjmuje tylko jeden parametr: listę do posortowania. Na początku funkcji zliczamy wystąpienia każdej liczby na sortowanej liście wywołując funkcję `count_occurrences` (**linia 12**). Liczniki zapisujemy w zmiennej `occurrences`. Po zliczeniu wszystkich elementów, czyścimy sortowaną listę za pomocą polecenia `clear()` (**linia 14**), by móc ją wypełnić posortowanymi wartościami. Następnie przechodzimy przez wszystkie liczniki na liście `occurrences` (**linia 16**) i dla każdego licznika tyle razy ile wynosi jego wartość (**linia 17**) dodajemy odpowiednią liczbę do sortowanej listy (**linia 18**).

W kodzie głównym na początku tworzymy listę do posortowania (**linia 21**), następnie sortujemy listę metodą sortowania przez zliczanie (**linia 23**), a na końcu wypisujemy posortowaną listę na ekranie (**linia 25**).
