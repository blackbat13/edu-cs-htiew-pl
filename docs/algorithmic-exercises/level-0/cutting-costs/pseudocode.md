# Pseudokod

## Rozwiązanie

```
1. Wczytaj a, b, c
2. suma := a + b + c
3. minimum := a
4. Jeżeli b < minimum, to:
    5. minimum := b
6. Jeżeli c < minimum, to:
    7. minimum := c
8. maksimum := a
9. Jeżeli b > maksimum, to:
    10. maksimum := b
11. Jeżeli c > maksimum, to:
    12. maksimum := c
13. wynik := suma - minimum - maksimum
14. Wypisz wynik
```

### Opis

Na początku wczytujemy dane wejściowe: trzy liczby całkowite (**krok 1**).
Następnie obliczamy sumę wczytanych liczb (**krok 2**).

Teraz przystępujemy do znalezienia najmniejszej z wartości. Korzystamy ze standardowego algorytmu na znajdowanie minimum (**kroki 3-7**).
W następnej kolejności, w analogiczny sposób znajdujemy maksimum (**kroki 8-12**).

Na koniec obliczamy wynik, odejmując minimum i maksimum od sumy i w ten sposób pozostawiając wartość środkową (**krok 13**).
Obliczony wynik wypisujemy (**krok 14**).