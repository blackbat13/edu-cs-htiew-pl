# Wyszukiwanie binarne

## [Opis problemu](../../../../algorithms/searching/binary-search.md)

## Istnienie elementu

### Implementacja

```haskell linenums="1"
binarySearch lst num left right
  | left > right = False
  | lst !! mid == num = True
  | lst !! mid < num = binarySearch lst num (mid + 1) right
  | otherwise = binarySearch lst num left (mid - 1)
  where mid = (left + right) `div` 2

main = do
  let lst = [0, 2, 4, 5, 7, 8, 9, 10, 18]
  let num = 4

  let result = binarySearch lst num 0 (length lst - 1)

  if result
    then putStrLn "Liczba jest w tablicy"
    else putStrLn "Liczby nie ma w tablicy"
```

### Opis implementacji

Funkcja `binarySearch` przyjmuje cztery argumenty: `lst` (lista, w której szukamy), `num` (liczba, której szukamy), `left` (indeks początkowy przeszukiwania) i `right` (indeks końcowy przeszukiwania). Podstawą funkcji jest podejście rekurencyjne, dzielące problem na mniejsze części.

1. Najpierw sprawdzamy, czy indeks początkowy jest większy niż końcowy. Jeśli tak, oznacza to, że liczba nie została znaleziona, więc funkcja zwraca `False`.
2. Następnie obliczamy środkowy indeks listy (`mid`). Jeśli element w środku listy jest równy szukanej liczbie (`num`), funkcja zwraca `True`.
3. Jeśli element środkowy jest mniejszy niż `num`, funkcja ponownie wywołuje siebie, ale tym razem z przesuniętym indeksem początkowym na pozycję za środkowym indeksem (`mid + 1`).
4. W przeciwnym razie, jeśli element środkowy jest większy niż `num`, funkcja ponownie wywołuje się z indeksem końcowym ustawionym na jeden przed środkowym (`mid - 1`).

W części `main`, definiujemy uporządkowaną listę `lst` i liczbę `num`, którą chcemy znaleźć. Wywołujemy funkcję `binarySearch` z tymi wartościami oraz z początkowym i końcowym indeksem listy. Wynik wyszukiwania (`result`) określa, czy liczba znajduje się w liście, czy nie. W zależności od wyniku, program wyświetla odpowiedni komunikat.

## Pozycja elementu

### Implementacja

```haskell linenums="1"
binarySearch lst num left right
  | left > right = -1
  | lst !! mid == num = mid
  | lst !! mid < num = binarySearch lst num (mid + 1) right
  | otherwise = binarySearch lst num left (mid - 1)
  where mid = (left + right) `div` 2

main = do
  let lst = [0, 2, 4, 5, 7, 8, 9, 10, 18]
  let num = 4

  let index = binarySearch lst num 0 (length lst - 1)

  if index == -1
    then putStrLn "Liczby nie ma w tablicy"
    else do 
        putStr "Liczba jest pod indeksem "
        print index
```

### Opis implementacji

Funkcja `binarySearch` przyjmuje cztery argumenty: listę `lst`, szukaną liczbę `num`, oraz indeksy `left` i `right`, które określają zakres przeszukiwania w liście.

1. **Warunek końca:** jeśli `left` jest większe niż `right`, oznacza to, że przeszukiwany zakres został wyczerpany, a liczba nie została znaleziona. W takim przypadku, funkcja zwraca `-1`.
2. **Znalezienie liczby:** obliczamy środkowy indeks (`mid`) listy. Jeśli element w środku jest równy szukanej liczbie (`num`), funkcja zwraca ten indeks.
3. **Przeszukiwanie prawej części:** jeżeli element środkowy jest mniejszy niż `num`, funkcja kontynuuje wyszukiwanie w prawej części listy, aktualizując indeks `left` na `mid + 1`.
4. **Przeszukiwanie lewej części:** w przeciwnym razie, jeśli element środkowy jest większy niż `num`, wyszukiwanie jest kontynuowane w lewej części, aktualizując indeks `right` na `mid - 1`.

W części `main` programu, definiujemy posortowaną listę `lst` i liczbę `num`, której indeks chcemy znaleźć. Następnie wywołujemy funkcję `binarySearch` z odpowiednimi parametrami. Wynik, jaki otrzymujemy, to indeks szukanej liczby w liście.

- Jeśli wynik to `-1`, oznacza to, że liczba nie znajduje się w liście, co jest sygnalizowane odpowiednim komunikatem.
- W przeciwnym wypadku, program wyświetla indeks, pod którym znajduje się szukana liczba.
