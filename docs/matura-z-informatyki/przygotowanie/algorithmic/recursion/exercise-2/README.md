# Ćwiczenie 2

Zapoznaj się z poniższą specyfikacją oraz pseudokodem, a następnie rozwiąż zadania.

## Specyfikacja

### Dane

* $n$ - liczba naturalna, $n>0$.

## Pseudokod

```
Funkcja sklej(n):
    1. Jeżeli n = 1, to:
        2. Zwróc 0
    3. Jeżeli n mod 2 = 0, to:
        4. Zwróc n - 1 + 2 * sklej(n / 2)
    5. W przeciwnym wypadku:
        6. Zwróc n - 1 + sklej((n - 1) / 2) + sklej((n + 1) / 2)
```

!!! info
	 **mod** oznacza resztę z dzielenia.

## Zadanie 1

Wykonanie funkcji `sklej` można przedstawić w postaci drzewa wywołań rekurencyjnych ilustrującego wszystkie wywołania funkcji po jej uruchomieniu dla zadanego argumentu. Narysuj takie drzewo dla wywołania `sklej(5)`.

## Zadanie 2

Narysuj *drzewo wywołań rekurencyjnych* dla wywołania `sklej(7)`.

## Zadanie 3

Ile razy zostanie wykonane wywołanie `sklej(1)` podczas obliczania `sklej(7)`?.

## Zadanie 4

Uzupełnij poniższą tabelę, podając wyniki działania funkcji `sklej` dla wskazanych argumentów.

|  n  | sklej(n) |
| :-: | :----: |
|  1  |    0   |
|  2  |    1   |
|  3  |        |
|  4  |        |
|  5  |        |
|  6  |        |

## Zadanie 5

Chcemy wypełnić tablicę $s[1..n]$ w taki sposób, że $s[i]=sklej(i)$ dla każdego $1\leq i\leq n$. Podaj algorytm wypełniający tablicę $s$ odpowiednimi wartościami **bez wywoływania** funkcji *sklej*, tnz. **bez użycia rekurencji**.

Rozwiązanie zapisz w postaci pseudokodu. W swoim zapisie możesz korzystać jedynie z podstawowych operacji arytmetycznych (dodawanie, odejmowanie, mnożenie, dzielenie, reszta z dzielenia, dzielenie całkowite), instrukcji kontroli przepływu (instrukcja warunkowa, pętla warunkowa, pętla licząca), instrukcji dotyczących podstawowych operacji na zmiennych (utworzenie zmiennej, przypisanie wartości, odczytanie wartości), instrukcji dotyczących podstawowych operacji na tablicach (utworzenie tablicy o zadanym rozmiarze wypełnionej jedną wartością, odwołanie do elementu tablicy pod zadanym indeksem) oraz samodzielnie zdefiniowanych funkcji.

### Specyfikacja

#### Dane

- $n$ - liczba naturalna, $n>0$

#### Wynik

- $s[1..n]$ - tablica liczb całkowitych, taka, że $s[i]=sklej(i)$ dla każdego $1\leq i\leq n$
