# Liczby gnomiczne

Liczby gnomiczne to liczby naturalne postaci $2n+1$ spełniające poniższe równanie:

$$
2n+1+n^2=(n+1)^2
$$

Przykładem liczby gnomicznej jest $7$, ponieważ:

$$
7 = 2*3+1 \\
2*3 + 1 + 3^2 = (3+1)^2
$$

## Zadanie 1

Uzupełnij poniższą tabelkę określając dla podanej liczby $k$ czy jest liczbą gnomiczną.

| **k** | **Liczba gnomiczna** |
|:-----:|:-----------------:|
|   9   |        TAK        |
|  10  |        NIE        |
|   15  |                   |
|  24  |                   |
|  121  |                   |

## Zadanie 2

Zaprojektuj algorytm sprawdzający, dla zadanej liczby naturalnej $k$, czy jest ona liczbą gnomiczną.

**Uwaga**: w swoim zapisie możesz korzystać jedynie z podstawowych operacji arytmetycznych (dodawanie, odejmowanie, mnożenie, dzielenie, reszta z dzielenia, dzielenie całkowite), instrukcji kontroli przepływu (instrukcja warunkowa, pętla warunkowa, pętla licząca), instrukcji dotyczących podstawowych operacji na zmiennych (utworzenie zmiennej, przypisanie wartości, odczytanie wartości), instrukcji dotyczących podstawowych operacji na tablicach (utworzenie tablicy o zadanym rozmiarze wypełnionej jedną wartością, odwołanie do elementu tablicy pod zadanym indeksem) oraz samodzielnie zdefiniowanych funkcji.

## Zadanie 3

W pliku *gnomiczne.txt* podanych jest $100$ liczb naturalnych zapisanych w systemie **binarnym**, każda w osobnej linii.

[:material-note-text: gnomiczne.txt](../../../../assets/gnomic-numbers/gnomiczne.txt)

W pliku *gnomiczne_przyklad.txt* podanych jest $10$ liczb naturalnych zapisanych w systemie binarnym, każda w osobnej linii.

[:material-note-text: gnomiczne_przyklad.txt](../../../../assets/gnomic-numbers/gnomiczne_przyklad.txt)

Napisz program, który policzy, ile jest liczb gnomicznych w pliku.

Dla pliku *gnomiczne_przyklad.txt* odpowiedź to: $4$.
