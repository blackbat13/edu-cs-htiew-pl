# Znajdowanie lidera w zbiorze

## [Opis problemu](../../../../algorithms/searching/majority.md)

## Implementacja

```python linenums="1"
def find_majority(array: list) -> int:
    counter = current_candidate = 0
    
    for el in array:
        if counter == 0:
            current_candidate = el
            counter = 1
        elif el == current_candidate:
            counter += 1
        else:
            counter -= 1

    if array.count(current_candidate) >= len(array) / 2:
        return current_candidate
    else:
        return -1

array = [1, 2, 5, 5, 7, 5, 5, 10, 5, 5]

majority = find_majority(array)

print(majority)
```

Początkowo ustawiamy zmienną `count` na $0$.
W pętli `for` iterujemy po każdym elemencie `el` z listy `array`.
W każdej iteracji sprawdzamy, czy `el` jest równy poszukiwanemu elementowi `element`. Jeśli tak, inkrementujemy zmienną `count`.
Po zakończeniu pętli, zwracamy wartość zmiennej `count`, która reprezentuje liczbę wystąpień elementu w liście.

Funkcja `find_majority` przyjmuje jako argument listę `array` (lista liczb) i zwraca liczbę dominującą (`majority`) lub $-1$ w przypadku braku liczby dominującej.

Na początku ustawiamy zmienną `counter` na $0$ i `current_candidate` na $0$.
W pętli `for` iterujemy po każdym elemencie `el` z listy `array`.
Jeśli `counter` jest równy $0$, oznacza to, że aktualnie nie mamy żadnego kandydata na liczbę dominującą. Ustawiamy `current_candidate` na bieżący element `el` i `counter` na $1$.
W przeciwnym przypadku, jeśli `counter` jest większy od $0$, sprawdzamy, czy bieżący element `el` jest równy aktualnemu kandydatowi `current_candidate`. Jeśli tak, inkrementujemy `counter` o $1$.
Jeśli `el` nie jest równy `current_candidate`, dekrementujemy `counter` o $1$.

Po zakończeniu pętli, sprawdzamy, czy liczba wystąpień `current_candidate` w liście `array` jest większa lub równa połowie długości listy (`len(array) / 2`). Jeśli tak, zwracamy `current_candidate` jako liczbę dominującą.
W przeciwnym przypadku, gdy brak liczby dominującej, zwracamy $-1$.

W przykładzie podana jest konkretna lista `array`. Funkcja `find_majority` jest wywoływana z tą listą, a wynikowa liczba dominująca jest wyświetlana przy użyciu funkcji `print`.

W wyniku wykonania tego kodu zostanie wyświetlona wartość $5$ ponieważ liczba $5$ występuje $6$ razy w liście, co jest większe niż połowa długości listy.
