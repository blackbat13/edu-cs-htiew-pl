# Szyfr ROT13

ROT13 (od ang. *rotate by 13 places*) to specjalny przypadek szyfru Cezara, w którym przesunięcie wynosi 13 miejsc. Jest to technika używana głównie do ukrywania tekstu, a nie dla rzeczywistych zastosowań kryptograficznych, ze względu na jej przewidywalność.

## Opis działania

1. **Podstawowa zasada**: każda litera w alfabecie jest przesuwana o 13 miejsc. Dla alfabetu łacińskiego oznacza to, że litery od A do M są przesuwane do liter od N do Z, a litery od N do Z są przesuwane do liter od A do M.

2. **Przykład**:
   - A staje się N
   - B staje się O
   - C staje się P
   - ...
   - Z staje się M

3. **Rekursywność**: jednym z ciekawych aspektów ROT13 jest to, że dwukrotne zastosowanie algorytmu przynosi tekst jawny. Oznacza to, że ROT13 jest zarówno metodą szyfrowania, jak i deszyfrowania.

## Przykład

Załóżmy, że chcemy zaszyfrować tekst "ALGORYTM".
Po zastosowaniu ROT13 otrzymujemy: "NYTBEGLZ".

Gdybyśmy teraz zaszyfrowali "NYTBEGLZ" za pomocą ROT13, wrócilibyśmy do oryginalnego tekstu "ALGORYTM".

## Bezpieczeństwo

ROT13 nie jest bezpiecznym sposobem szyfrowania informacji. Jest łatwo rozpoznawalny i łatwo deszyfrowalny, nawet bez znajomości metody. W praktyce jest często używany do ukrywania spoilerów w dyskusjach online lub do lekkiego zaciemnienia tekstu, ale nie powinien być używany w sytuacjach, gdzie bezpieczeństwo jest ważne.

## Specyfikacja

### Dane

- **jawny/szyfrogram** - tekst do zaszyfrowania/odszyfrowania, składający się z małych liter alfabetu angielskiego

### Wynik

- Zaszyfrowany/odszyfrowany tekst.

## Szyfrowanie i deszyfrowanie

### Funkcje pomocnicze

- **Pozycja(litera)** - zwraca liczbę od $1$ do $26$ - pozycję przekazanej jako argument litery w alfabecie angielskim
- **Alfabet(pozycja)** - zwraca literę na zadanej pozycji w alfabecie angielskim
- **Długość(tekst)** - zwraca długość tekstu

### Pseudokod

```
funkcja Rot13(tekst):
    1. wynik := ""
    2. Dla i := 1 do Długość(tekst), wykonuj:
        3. nowaPozycja := Pozycja(tekst[i]) + 13
        4. Jeżeli nowaPozycja > 26, to:
            5. nowaPozycja := nowaPozycja - 26
        6. nowaLitera := Alfabet(nowaPozycja)
        7. wynik := wynik + nowaLitera

    8. Zwróć wynik
```

## Implementacja

### [:simple-cplusplus: C++](../../../programming/c++/algorithms/cryptography/rot13.md){ .md-button }

### [:simple-python: Python](../../../programming/python/algorithms/cryptography/rot13.md){ .md-button }
