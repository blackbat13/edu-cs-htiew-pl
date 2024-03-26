# Najdłuższy wspólny podciąg

Podciąg to sekwencja znaków wybrana z tekstu bez zmiany ich kolejności, niekoniecznie znajdujących się obok siebie. Najdłuższy wspólny podciąg to problem znalezienia najdłuższego podciągu, który jest wspólny dla dwóch tekstów.

## Specyfikacja

### Dane

* $a, b$ - dwa ciągi znaków

### Wynik

* Najdłuższy wspólny podciąg ciągów $a$ i $b$

## Przykład

### Dane

```
a := "kitten"
b := "sitting"
```

### Wynik

`"ittn"`

## Algorytm

### Lista kroków

1. **Utworzenie tabeli**: stwórz tablicę o wymiarach `(m+1) x (n+1)`, gdzie `m` i `n` to długości dwóch porównywanych tekstów. Element `tab[i][j]` będzie przechowywał długość najdłuższego wspólnego podciągu dla kolejnych fragmentów zadanych tekstów: do `i-tego` znaku pierwszego tekstu i `j-tego` znaku drugiego tekstu.

2. **Inicjalizacja**: ustaw wszystkie elementy pierwszej kolumny i pierwszego wiersza na 0.

3. **Wypełnienie tabeli**:
   - Dla każdego `i` od 1 do `m` i każdego `j` od 1 do `n`:
     - Jeśli znaki na pozycji `i` pierwszego tekstu i pozycji `j` drugiego tekstu są takie same, to `tab[i][j] = tab[i-1][j-1] + 1`.
     - W przeciwnym przypadku `tab[i][j] = max(tab[i - 1][j], tab[i][j - 1])`.

4. **Wyznaczenie wyniku**:
   - Odczytaj prawy dolny element tablicy - będzie to długość najdłuższego wspólnego podciągu.
   - W oparciu o wartości w tablicy odtwórz najdłuższy wspólny podciąg.

## Złożoność

Złożoność czasowa algorytmu to `O(mn)`, gdzie `m` i `n` to długości analizowanych tekstów. Złożoność pamięciowa to również `O(mn)` z uwagi na wymagania tablicy.

## Implementacja

### C++


[longest-common-subsequence.md](../../programming/c++/algorithms/text/longest-common-subsequence.md)


### Python


[longest-common-subsequence.md](../../programming/python/algorithms/text/longest-common-subsequence.md)

