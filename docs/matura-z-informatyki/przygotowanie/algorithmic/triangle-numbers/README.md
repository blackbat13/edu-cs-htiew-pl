# Liczby trójkątne

Liczby trójkątne to liczby naturalne, które można zapisać w postaci sumy kolejnych liczb naturalnych od $1$ do $n$. Przykładami liczb trójkątnych są: $1$, $3$ ($1+2$), $6$ ($1+2+3$).

## Zadanie 1

Uzupełnij poniższą tabelkę określając, czy podana liczba $k$ jest liczbą trójkątną, a jeżeli tak, to dla jakiego $n$ spełnione jest równanie $k=1+2+...+n$.

| $k$  | $k$ jest liczbą trójkątną  | $n$ |
| :----: | :-------------------------:  | :----: |
| 6    | TAK                        | 3    |
| 8    | NIE                        | -    |
| 18   |                            |      |
| 28   |                            |      |
| 56   |                            |      |
| 465  |                            |      |

## Zadanie 2

Zaprojektuj algorytm sprawdzający, dla zadanej liczby naturalnej $k$, czy jest ona liczbą trójkątną.

Twoje rozwiazanie powinno działać w czasie **logarytmicznym**.

**Uwaga**: w swoim zapisie możesz korzystać jedynie z podstawowych operacji arytmetycznych (dodawanie, odejmowanie, mnożenie, dzielenie, reszta z dzielenia, dzielenie całkowite), instrukcji kontroli przepływu (instrukcja warunkowa, pętla warunkowa, pętla licząca), instrukcji dotyczących podstawowych operacji na zmiennych (utworzenie zmiennej, przypisanie wartości, odczytanie wartości), instrukcji dotyczących podstawowych operacji na tablicach (utworzenie tablicy o zadanym rozmiarze wypełnionej jedną wartością, odwołanie do elementu tablicy pod zadanym indeksem) oraz samodzielnie zdefiniowanych funkcji.

## Zadanie 3

W pliku *trojkatne.txt* podanych jest $100$ liczb naturalnych, każda w osobnej linii.

[:material-note-text: trojkatne.txt](../../../../assets/triangle-numbers/trojkatne.txt)

W pliku *trojkatne_przyklad.txt* podanych jest $10$ liczb naturalnych, każda w osobnej linii.

[:material-note-text: trojkatne_przyklad.txt](../../../../assets/triangle-numbers/trojkatne_przyklad.txt)

Napisz program, który znajdzie wszystkie liczby trójkątne z pliku.

Dla pliku *trojkatne_przyklad.txt* odpowiedź to:

```
253
561
```
