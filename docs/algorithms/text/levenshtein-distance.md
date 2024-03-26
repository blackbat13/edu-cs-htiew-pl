# Odległość Levenshteina (edycyjna)

Odległość Levenshteina, znana również jako odległość edycyjna, jest miarą różnicy między dwoma ciągami znaków. Pozwala określić, jak bardzo dwa wyrazy są podobne do siebie, poprzez obliczenie minimalnej liczby operacji wymaganych do przekształcenia jednego wyrazu w drugi. Do dozwolonych operacji należą: **wstawienie** (ang. *insertion*), **usunięcie** (ang. *deletion*) oraz **zamiana** (ang. *substitution*) pojedynczego znaku.

Odległość Levenshteina jest używana w wielu dziedzinach, takich jak korekta pisowni, porównywanie sekwencji DNA w biologii, czy systemy rozpoznawania mowy. Jest to przydatne narzędzie w przetwarzaniu języka naturalnego i innych dziedzinach wymagających analizy podobieństwa tekstów.

## Przykład 1

Aby przekształcić wyraz "kot" w "kotek", należy wykonać dwie operacje:

- wstawienie na koniec wyrazu litery "e",
- wstawienie na koniec wyrazu litery "k".

Odległość Levenshteina dla tekstów "kot" i "kotek" wynosi 2.

## Przykład 2

Aby przekształcić wyraz "kotek" w "kartek", należy wykonać dwie operacje:

- zamienić literę "o" na "a",
- wstawić literę "r" na trzecim miejscu.

Odległość Levenshteina dla tekstów "kotek" i "kartek" wynosi 2.

## Specyfikacja

### Dane

- **tekst1**, **tekst2** - dwa teksty, ciągi znaków liter angielskiego

### Wynik

- Odległość Levenshteina pomiędzy **tekst1** a **tekst2**.

## Rozwiązanie

### Funkcje pomocnicze

- **Długość(tekst)** - zwraca długość tekstu
- **Min(a, b, c)** - zwraca najmniejszą z trzech podanych wartości

### Pseudokod

```
funkcja OdległośćLevenshteina(tekst1, tekst2):
    1. macierz[0..Długość(tekst1)][0..Długość[tekst2]] := macierz wypełniona zerami
    2. Dla i := 1 do Długość(tekst1), wykonuj:
        3. Dla j := 1 do Długość(tekst2), wykonuj:
            4. Jeżeli tekst1[i] == tekst2[i], to
                5. koszt := 0
            6. w przeciwnym przypadku:
                7. koszt := 1
            8. macierz[i][j] = Min(macierz[i - 1][j - 1] + koszt, macierz[i - 1][j] + 1, macierz[i][j - 1] + 1)

    9. Zwróć macierz[Długość(tekst1)][Długość(tekst2)]
```

## Implementacja

### C++


[levenshtein-distance.md](../../programming/c++/algorithms/text/levenshtein-distance.md)


### Python


[levenshtein-distance.md](../../programming/python/algorithms/text/levenshtein-distance.md)

