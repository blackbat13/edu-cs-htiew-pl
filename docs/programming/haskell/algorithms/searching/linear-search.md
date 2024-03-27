# Wyszukiwanie liniowe

## [Opis problemu](../../../../algorithms/searching/linear-search.md)

## Istnienie elementu

### Implementacja

```haskell linenums="1"
linearSearch [] num = False
linearSearch arr num
    | head arr == num = True
    | otherwise = linearSearch (tail arr) num

main = do
  let arr = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0]
  let num = 7

  let result = linearSearch arr num

  if result
    then putStrLn "Liczba jest w tablicy"
    else putStrLn "Liczby nie ma w tablicy"
```

### Opis

Funkcja `linearSearch` (**linie 1 i 2**) zwraca jako wynik wartość prawda/fałsz i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Jeżeli tablica jest pusta to funkcja zwraca wartość `False` informującą o tym, że poszukiwanego elementu nie znaleziono w tablicy (**linia 1**). Jest to tzw. warunek stopu rekurencji. Jeżeli w tablicy pozostały jeszcze jakieś elementy do sprawdzenia, to sprawdzamy, czy pierwszy element tablicy (pobrany za pomocą funkcji `head`) jest poszukiwaną wartością (**linia 3**). Jeżeli tak, to funkcja zwraca wynik `True` (**linia 3**). W przeciwnym przypadku wywołujemy rekurencyjnie funkcję `linearSearch`, jako argumenty przekazując listę bez pierwszego elementu (do tego używamy funkcji `tail`), oraz wartość poszukiwanego elementu.

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 8**) oraz wartość poszukiwanego elementu (**linia 9**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `result` (**linia 11**). W zależności od wyniku (**linia 13**) wypisujemy odpowiedni komunikat (**linie 14 i 15**).

## Pozycja elementu

### Implementacja

```haskell linenums="1"
linearSearch [] num ind = -1
linearSearch arr num ind
    | head arr == num = ind
    | otherwise = linearSearch (tail arr) num (ind + 1)

main = do
  let arr = [8, 2, 9, 10, 5, 4, 2, 7, 18, 0]
  let num = 7

  let index = linearSearch arr num 0

  if index == -1
    then putStrLn "Liczby nie ma w tablicy"
    else do 
        putStr "Liczba jest pod indeksem "
        print index
```

### Opis

Funkcja `linearSearch` (**linie 1 i 2**) zwraca jako wynik liczbę całkowitą i przyjmuje trzy argumenty: tablicę do przeszukania, wartość poszukiwanego elementu oraz numer obecnie sprawdzanego indeksu. Jeżeli tablica jest pusta to funkcja zwraca wartość `-1` informującą o tym, że poszukiwanego elementu nie znaleziono w tablicy (**linia 1**). Jest to tzw. warunek stopu rekurencji. Jeżeli w tablicy pozostały jeszcze jakieś elementy do sprawdzenia, to sprawdzamy, czy pierwszy element tablicy (pobrany za pomocą funkcji `head`) jest poszukiwaną wartością (**linia 3**). Jeżeli tak, to funkcja zwraca jako wynik wartość `ind` (**linia 3**). W przeciwnym przypadku wywołujemy rekurencyjnie funkcję `linearSearch`, jako argumenty przekazując listę bez pierwszego elementu (do tego używamy funkcji `tail`), wartość poszukiwanego elementu oraz indeks zwiększony o jeden.

W części głównej programu na początku przygotowujemy dane do problemu: tablicę (**linia 8**) oraz wartość poszukiwanego elementu (**linia 9**). Następnie wywołujemy funkcję `linearSearch` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w nowej zmiennej `index` (**linia 11**). W zależności od wyniku (**linia 13**) wypisujemy odpowiedni komunikat (**linie 14, 16 i 17**).

## Wszystkie pozycje elementu

### Implementacja

```haskell linenums="1"
linearSearch [] num ind = []
linearSearch arr num ind
    | head arr == num = ind : linearSearch (tail arr) num (ind + 1)
    | otherwise = linearSearch (tail arr) num (ind + 1)

main = do
  let arr = [8, 7, 9, 10, 5, 4, 2, 7, 18, 7]
  let num = 7

  let indexes = linearSearch arr num 0

  print indexes
```

### Opis

Funkcja `linearSearch` przyjmuje trzy argumenty: listę `arr`, szukaną liczbę `num` oraz bieżący indeks `ind`.

1. **Warunek bazowy:** jeśli lista jest pusta (`[]`), funkcja zwraca pustą listę, co oznacza koniec wyszukiwania.
2. **Wyszukiwanie:** w każdym kroku rekurencyjnym, funkcja sprawdza, czy pierwszy element listy (`head arr`) jest równy szukanej liczbie (`num`).
   - **Znalezienie elementu:** jeśli tak, dodaje obecny indeks (`ind`) do listy wynikowej i kontynuuje wyszukiwanie na reszcie listy (`tail arr`), inkrementując indeks (`ind + 1`).
   - **Przechodzenie dalej:** jeśli nie, funkcja kontynuuje wyszukiwanie na reszcie listy bez dodawania indeksu do listy wynikowej.

W głównej części programu (`main`) definiujemy listę `arr` i liczbę `num`, której indeksy chcemy znaleźć. Następnie wywołujemy funkcję `linearSearch` z tymi parametrami. Otrzymana lista `indexes` zawiera wszystkie indeksy, pod którymi znajduje się liczba `num` w liście `arr`.
