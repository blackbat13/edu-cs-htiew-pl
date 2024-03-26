# Wyszukiwanie minimum i maksimum

## [Opis problemu](../../../../algorithms/searching/min-or-max.md)


## Wyszukiwanie wartości minimum i maksimum

```python linenums="1"
def find_min_max(array: list) -> (int, int):
    min_val = array[0]
    max_val = array[0]
    
    for _, el in enumerate(array, 1):
        min_val = min(min_val, el)
        max_val = max(max_val, el)

    return min_val, max_val


tab = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0]
n = 10
    
min_val, max_val = find_min_max(n, tab)
    
print(f"Min: {min_val}, Max: {max_val}")
```


Funkcja `find_min_max` działa w następujący sposób:

1. Inicjalizuje zmienne `min_val` i `max_val` jako pierwszy element listy.
2. Przechodzi przez listę od drugiego elementu do końca.
3. Jeżeli wartość aktualnego elementu `tab[i]` jest mniejsza od `min_val`, aktualizuje `min_val` na `tab[i]`.
4. Jeżeli wartość aktualnego elementu `tab[i]` jest większa od `max_val`, aktualizuje `max_val` na `tab[i]`.
5. Po przejściu przez całą listę, zwraca krotkę `(min_val, max_val)`, która zawiera minimalną i maksymalną wartość w liście.

W głównej części programu:

1. Definiuje listę `tab` z $10$ elementami.
2. Używa funkcji `find_min_max` do znalezienia minimalnej i maksymalnej wartości w liście.
3. Wyświetla te wartości na ekranie.

## Wyszukiwanie indeksów wartości minimum i maksimum

```python linenums="1"
def find_min_max_ind(array: list) -> (int, int):
    min_val = array[0]
    max_val = array[0]
    min_ind = max_ind = 0
    
    for i, el in enumerate(array, 1):
        if el < min_val:
            min_val = el
            min_ind = i
        elif el > max_val:
            max_val = el
            max_ind = i

    return min_ind, max_ind


tab = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0]
n = 10
    
min_ind, max_ind = find_min_max_ind(n, tab)
    
print(f"Min value index: {min_ind}, Max value index: {max_ind}")
```


Funkcja `find_min_max_ind` działa następująco:

1. Zaczyna od zainicjowania `min_ind` i `max_ind` jako $0$ - indeksy pierwszego elementu listy.
2. Przechodzi przez listę od drugiego elementu do końca.
3. Jeżeli aktualny element `tab[i]` jest mniejszy niż element na pozycji `min_ind`, aktualizuje `min_ind` na $i$.
4. Jeżeli aktualny element `tab[i]` jest większy niż element na pozycji `max_ind`, aktualizuje `max_ind` na $i$.
5. Po przejściu przez całą listę, zwraca krotkę `(min_ind, max_ind)`, która zawiera indeksy minimalnej i maksymalnej wartości w liście.

W głównej części programu:

1. Tworzy listę `tab` z $10$ elementami.
2. Wywołuje funkcję `find_min_max_ind`, która zwraca indeksy minimalnej i maksymalnej wartości w liście.
3. Wyświetla te indeksy na ekranie.

Podobnie jak poprzedni program, ten program jest efektywny, ponieważ zamiast przechodzić przez listę dwa razy (raz do znalezienia indeksu minimum, raz do znalezienia indeksu maksimum), robi to tylko raz, co jest szybsze dla dużych list.
