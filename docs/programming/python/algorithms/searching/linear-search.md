# Wyszukiwanie liniowe

## [Opis problemu](../../../../algorithms/searching/linear-search.md)


## Istnienie elementu

```python linenums="1"
def linear_search(array: list, number: int) -> bool:
    for el in array:
        if el == number:
            return True

    return False


array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
number = 8

result = linear_search(array, number)

if result:
    print("Poszukiwana wartość jest w liście")
else:
    print("Poszukiwanej wartości nie ma w liście")
```


Funkcja `linear_search` (**linia 1**) zwraca jako wynik wartość prawda/fałsz i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne elementy listy (**linia 2**). Dla każdego elementu sprawdzamy, czy jego wartość jest tą, której szukamy (**linia 3**). Jeżeli tak, to zwracamy informację o znalezieniu wartości w liście (**linia 4**). Po przejściu przez wszystkie elementy listy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość `False` informującą, że poszukiwany element nie znajduje się w liście (**linia 6**).

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 9**) oraz wartość poszukiwanego elementu (**linia 10**). Następnie wywołujemy funkcję `linear_search` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `result` (**linia 12**). W zależności od wyniku (**linia 14**) wypisujemy odpowiedni komunikat (**linie 15 i 17**).

## Pozycja elementu

```python linenums="1"
def linear_search(array: list, number: int) -> int:
    for i, el in enumerate(array):
        if number == el:
            return i

    return -1


array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
number = 8

index = linear_search(array, number)

if index == -1:
    print("Poszukiwanej wartości nie ma w liście")
else:
    print("Poszukiwana wartość znajduje się pod indeksem", index)
```


Funkcja `linear_search` (**linia 1**) zwraca jako wynik liczbę całkowitą i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w liście od $0$ do długości listy minus 1 włącznie (**linia 2**). Rozmiar listy pobieramy za pomocą funkcji `len()`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w liście znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to zwracamy indeks wartości w liście (**linia 4**). Po przejściu przez wszystkie indeksy i wyjściu z pętli (tzn. gdy nie znaleźliśmy poszukiwanego elementu) zwracamy wartość $-1$ informującą, że poszukiwany element nie znajduje się w liście (**linia 6**).

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 9**) oraz wartość poszukiwanego elementu (**linia 10**). Następnie wywołujemy funkcję `linear_search` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `index` (**linia 12**). W zależności od wyniku (**linia 14**) wypisujemy odpowiedni komunikat (**linie 15 i 17**).

## Wszystkie pozycje elementu

```python linenums="1"
def linear_search(array: list, number: int):
    for i, el in enumerate(array):
        if number == el:
            print(i)


array = [8, 2, 8, 4, 5, 6, 7, 8, 9, 8]
number = 8

print("Poszukiwana wartość znajduje się pod następującymi indeksami:")
linear_search(array, number)
```


Funkcja `linear_search` (**linia 1**) nie zwraca wyniku i przyjmuje dwa argumenty: listę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w liście od $0$ do długości listy minus 1 włącznie (**linia 2**). Rozmiar listy pobieramy za pomocą funkcji `len()`. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w liście znajduje się poszukiwana wartość (**linia 3**). Jeżeli tak, to wypisujemy ten indeks (**linia 4**).

W części głównej programu na początku przygotowujemy dane do problemu: listę (**linia 7**) oraz wartość poszukiwanego elementu (**linia 8**). Następnie wypisujemy stosowny komunikat (**linia 10**) i wywołujemy funkcję `linear_search` z wcześniej przygotowanymi parametrami (**linia 11**).
