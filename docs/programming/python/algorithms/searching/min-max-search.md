# Jednoczesne wyszukiwanie minimum i maksimum

## [:link: Opis problemu](../../../../algorithms/searching/min-max-search.md)

## Podejście naiwne

```python linenums="1"
def find_min_max(array: list) -> (int, int):
    min_val = array[0]
    max_val = array[0]
    
    for _, el in enumerate(array, 1):
        min_val = min(min_val, el)
        max_val = max(max_val, el)

    return min_val, max_val

array = [3, 6, 1, 9, 10, 4, -4, 6, 12, 5, 11]

min_val, max_val = find_min_max(array)

print(f'Min: {min_val}, Max: {max_val}')
```

Funkcja `find_min_max` przyjmuje jako argument listę `array` (lista liczb) i zwraca parę wartości (`min`, `max`).

Początkowo ustawiamy zmienne `min` i `max` na pierwszy element listy `array` (`array[0]`). W pętli `for` iterujemy od drugiego elementu (indeks $1$) do końca listy, czyli od $1$ do długości listy minus $1$. W każdej iteracji porównujemy element `array[i]` z dotychczasowym minimum (`min`). Jeśli `array[i]` jest mniejsze od `min`, aktualizujemy wartość `min` na `array[i]`. Następnie porównujemy element `array[i]` z dotychczasowym maksimum (`max`). Jeśli `array[i]` jest większe od `max`, aktualizujemy wartość `max` na `array[i]`.

Po zakończeniu pętli, mamy już najmniejszą wartość `min` i największą wartość `max` z całej listy. Zwracamy parę wartości (`min`, `max`).

W przykładzie podana jest konkretna lista `array`. Funkcja `find_min_max` jest wywoływana z tą listą, a wynikowe wartości dla `min` i `max` są wyświetlane przy użyciu funkcji `print`.

W wyniku wykonania tego kodu zostanie wyświetlone: `Minimum: -4, Maximum: 12`.

## Podejście optymalne

```python linenums="1"
def find_min_max(array: list) -> (int, int):
    min_candidates = []
    max_candidates = []
    
    for i in range(1, len(array), 2):
        if array[i - 1] < array[i]:
            min_candidates.append(array[i - 1])
            max_candidates.append(array[i])
        else:
            min_candidates.append(array[i])
            max_candidates.append(array[i - 1])

    if len(array) % 2 != 0:
        min_candidates.append(array[len(array) - 1])
        max_candidates.append(array[len(array) - 1])

    min_val = min(min_candidates)
    max_val = max(max_candidates)

    return min_val, max_val

array = [3, 6, 1, 9, 10, 4, -4, 6, 12, 5, 11]

min_val, max_val = find_min_max(array)

print(f'Min: {min_val}, Max: {max_val}')
```

Funkcja `find_min_max` przyjmuje jako argument listę `array` (lista liczb) i zwraca parę wartości (`min_val`, `max_val`).

Na początku tworzone są dwie puste listy: `min_candidates` (kandydaci na najmniejszą wartość) i `max_candidates` (kandydaci na największą wartość).
W pętli `for` iterujemy po indeksach od $1$ do `len(array)-1` z krokiem $2$, aby iterować po parzystych indeksach.
W każdej iteracji porównujemy elementy na indeksach `i-1` i `i`. Jeśli wartość na indeksie `i-1` jest mniejsza niż wartość na indeksie `i`, dodajemy wartość z indeksu `i-1` do listy `min_candidates`, a wartość z indeksu `i` do listy `max_candidates`. W przeciwnym przypadku, dodajemy wartość z indeksu `i` do listy `min_candidates`, a wartość z indeksu `i-1` do listy `max_candidates`.

Jeśli lista `array` ma nieparzystą liczbę elementów, dodajemy ostatni element do list `min_candidates` i `max_candidates`.

Następnie inicjalizujemy zmienne `min_val` i `max_val` wartościami pierwszych kandydatów z list `min_candidates` i `max_candidates`.

W kolejnej pętli `for` iterujemy od $1$ do długości listy kandydatów minus $1$. Nie ma znaczenia, której listy długość weźmiemy, jako że obie mają tyle samo elementów. Wewnątrz pętli porównujemy każdy element z listy `min_candidates` z dotychczasowym minimum (`min_val`) i każdy element z listy `max_candidates` z dotychczasowym maksimum (`max_val`). Jeśli dany kandydat jest mniejszy od `min_val`, aktualizujemy `min_val` na tę wartość. Jeśli dany kandydat jest większy od `max_val`, aktualizujemy `max_val` na tę wartość.

Na koniec zwracamy parę wartości (`min_val`, `max_val`).

W przykładzie podana jest konkretna lista `array`. Funkcja `find_min_max` jest wywoływana z tą listą, a wynikowe wartości dla `min_val` i `max_val` są wyświetlane przy użyciu funkcji `print`.

W wyniku wykonania tego kodu zostanie wyświetlone: `Minimum: -4, Maximum: 12`.
