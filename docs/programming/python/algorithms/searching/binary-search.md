# Wyszukiwanie binarne

## [Opis problemu](../../../../algorithms/searching/binary-search.md)

## Wersja iteracyjna

```python linenums="1"
def binary_search_iterative(array: list, number: int) -> int:
    left = 0
    right = len(array) - 1
    
    while left < right:
        middle = (left + right) // 2
        
        if number < array[middle]:
            right = middle
        elif number > array[middle]:
            left = middle + 1
        else:
            return middle

    if left < len(array) and array[left] == number:
        return left

    return -1

array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
number = 8

index = binary_search_iterative(array, number)

print(index)
```

Funkcja `binary_search_iterative` przyjmuje dwa argumenty: listę `array` oraz liczbę `number`, którą chcemy znaleźć. Oto, jak działa ta funkcja:

1. Ustawia lewy `left` indeks na $0$, a prawy `right` indeks na długość listy minus jeden.
2. W pętli while, dopóki lewy indeks jest mniejszy od prawego, wykonuje następujące operacje:
    1. Wyznacza indeks środkowy `middle` jako średnią indeksów lewego i prawego (dzielenie całkowite).
    2. Jeżeli szukana liczba `number` jest mniejsza od liczby w środku listy, ustawia prawy indeks na środkowy.
    3. Jeżeli szukana liczba jest większa od liczby w środku listy, ustawia lewy indeks na środkowy plus jeden.
    4. Jeżeli liczba w środku listy jest równa szukanej liczbie, zwraca indeks środkowy.
3. Po zakończeniu pętli, jeżeli lewy indeks jest mniejszy od długości listy i liczba pod tym indeksem jest równa szukanej liczbie, zwraca lewy indeks.
4. Jeżeli liczba nie została znaleziona, zwraca $-1$.

W głównym ciele programu:

1. Definiuje listę `array` oraz szukaną liczbę `number`.
2. Wywołuje funkcję `binary_search_iterative` z listą i szukaną liczbą.
3. Wyświetla indeks, pod którym znajduje się szukana liczba. Jeżeli liczba nie została znaleziona, wyświetli $-1$.

## Wersja rekurencyjna

```python linenums="1"
def binary_search_recursive(array: list, number: int, left: int, right: int) -> int:
    if left < right:
        middle: int = (left + right) // 2
        
        if number < array[middle]:
            return binary_search_recursive(array, number, left, middle)
        elif number > array[middle]:
            return binary_search_recursive(array, number, middle + 1, right)
        else:
            return middle
    elif left < len(array) and array[left] == number:
        return left

    return -1

array = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
number = 8

index = binary_search_recursive(array, number, 0, len(array))

print(index)
```

Funkcja `binary_search_recursive` przyjmuje cztery argumenty: listę `array`, liczbę `number` do znalezienia, oraz indeksy `left` i `right` określające zakres, w którym szukamy liczby. Oto jak działa ta funkcja:

1. Jeżeli lewy indeks `left` jest mniejszy od prawego indeksu `right`, wykonuje następujące operacje:
   1. Wyznacza indeks środkowy `middle` jako średnią indeksów lewego i prawego (dzielenie całkowite).
   2. Jeżeli szukana liczba `number` jest mniejsza od liczby w środku listy, wywołuje sama siebie rekurencyjnie z niezmienionym lewym indeksem i środkowym indeksem jako prawym indeksem.
   3. Jeżeli szukana liczba jest większa od liczby w środku listy, wywołuje sama siebie rekurencyjnie ze środkowym indeksem plus jeden jako lewym indeksem i niezmienionym prawym indeksem.
   4. Jeżeli liczba w środku listy jest równa szukanej liczbie, zwraca indeks środkowy.
2. Jeżeli lewy indeks jest mniejszy od długości listy i liczba pod tym indeksem jest równa szukanej liczbie, zwraca lewy indeks.
3. Jeżeli liczba nie została znaleziona, zwraca $-1$.

W głównym ciele programu:

1. Definiuje listę `array` oraz szukaną liczbę `number`.
2. Wywołuje funkcję `binary_search_recursive` z listą, szukaną liczbą oraz indeksami $0$ i długość listy.
3. Wyświetla indeks, pod którym znajduje się szukana liczba. Jeżeli liczba nie została znaleziona, wyświetli $-1$.
