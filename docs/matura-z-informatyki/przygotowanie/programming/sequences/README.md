# Sekwencje

W pliku *sequences.txt* znajduje się $10$ wierszy. W każdym wierszu znajduje się liczba naturalna $n$, a następnie sekwencja $n$ liczb naturalnych z przedziału $[1,1000]$ oddzielonych spacją.

[:material-note-text: sequences.txt](../../../../assets/sequences/sequences.txt)

W pliku *sequences_test.txt* znajduje się $10$ wierszy, jak opisano powyżej.

[:material-note-text: sequences_test.txt](../../../../assets/sequences/sequences_test.txt)

Napisz program/programy rozwiązujące poniższe zadania.

## Zadanie 1

Dla każdej sekwencji z pliku podaj sumę jej elementów. Dla pliku *sequences_test.txt* wynik to:

```txt
21784
14030
15888
12353
18191
7084
9632
4959
23868
22518
```

## Zadanie 2

Dla każdej sekwencji z pliku podaj najmniejszą i największą liczbę z tej sekwencji. Dla pliku *sequences_test.txt* wynik to:

```txt
Minimum: 13, Maksimum: 986
Minimum: 50, Maksimum: 928
Minimum: 44, Maksimum: 998
Minimum: 28, Maksimum: 927
Minimum: 9, Maksimum: 981
Minimum: 57, Maksimum: 960
Minimum: 20, Maksimum: 989
Minimum: 129, Maksimum: 801
Minimum: 31, Maksimum: 984
Minimum: 13, Maksimum: 994
```

## Zadanie 3

Dla każdej sekwencji z pliku podaj ile liczb z tej sekwencji jest liczbami pierwszymi oraz wypisz te liczby. Dla pliku *sequences_test.txt* wynik to:

```txt
Ile pierwszych: 5, Liczby pierwsze: 13 457 739 797 37
Ile pierwszych: 2, Liczby pierwsze: 197 907
Ile pierwszych: 3, Liczby pierwsze: 227 857 617
Ile pierwszych: 3, Liczby pierwsze: 661 853 433
Ile pierwszych: 4, Liczby pierwsze: 439 971 631 269
Ile pierwszych: 1, Liczby pierwsze: 521
Ile pierwszych: 0, Liczby pierwsze:
Ile pierwszych: 3, Liczby pierwsze: 491 443 577
Ile pierwszych: 7, Liczby pierwsze: 761 211 409 599 31 241 127
Ile pierwszych: 4, Liczby pierwsze: 41 13 373 587
```

## Zadanie 4

Dla każdej sekwencji z pliku podaj jej najdłuższy wspólny podciąg rosnący, tzn. taki podciąg sąsiednich wartości, że każda kolejna jest dłuższa od poprzedniej. Podaj długość tego podciągu jak i sam podciąg. Dla pliku *sequences_test.txt* wynik to:

```txt
Dlugosc: 5, Sekwencja: 78 84 720 776 878
Dlugosc: 4, Sekwencja: 256 585 844 917
Dlugosc: 3, Sekwencja: 227 514 655
Dlugosc: 2, Sekwencja: 95 676
Dlugosc: 4, Sekwencja: 360 666 704 899
Dlugosc: 2, Sekwencja: 521 688
Dlugosc: 4, Sekwencja: 300 362 470 645
Dlugosc: 3, Sekwencja: 295 577 738
Dlugosc: 4, Sekwencja: 166 280 831 897
Dlugosc: 4, Sekwencja: 80 262 435 657
```

## Zadanie 5

Dla każdej sekwencji z pliku podaj ile jest w niej par liczb względnie pierwszych. Liczby względnie pierwsze to takie, które nie mają wspólnego dzielnika poza wartością 1. Dla pliku *sequences_test.txt* wynik to:

```txt
388
172
231
155
327
46
78
34
493
657
```
