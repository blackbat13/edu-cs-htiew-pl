# Prostokąty

W pliku **rectangles.txt** znajduje się opis $100$ prostokątów. Każda linia w pliku zawiera cztery liczby całkowite oddzielone spacją. Liczby oznaczają kolejno współrzędne lewego górnego wierzchołka prostokąta, oraz współrzędne prawego dolnego wierzchołka prostokąta. Np. wartości `1 4 3 2` oznaczają prostokąt o lewym górnym wierzchołku $(1, 4)$, a prawym dolnym wierzchołku $(3, 2)$. Każdy prostokąt jest *poprawnie zdefiniowany*, tzn. ma niezerowe pole, a jego krawędzie są równoległe do osi układu współrzędnych.

[:material-note-text: rectangles.txt](../../../../assets/rectangles/rectangles.txt)

W pliku *rectangles_test.txt* znajduje się opis $10$ prostokątów, taki jak napisano wyżej.

[:material-note-text: rectangles_test.txt](../../../../assets/rectangles/rectangles_test.txt)

Napisz program/programy rozwiązujące poniższe zadania.

## Zadanie 1

Oblicz sumaryczne pole wszystkich prostokątów. 

Dla pliku *rectangles_test.txt* wynik to $6508$.

## Zadanie 2

Oblicz, ile par prostokątów się przecina. **Uwaga**: jeżeli prostokąty tylko stykają się krawędziami albo wierzchołkami, ale nie nachodzą na siebie, to uznajemy, że się **nie** przecinają.

Wynik dla pliku *rectangles_test.txt* to $21$.

## Zadanie 3

Dla każdej pary prostokątów, które się przecinają, oblicz ich wspólne pole. Podaj sumę wszystkich takich pól. 

Wynik dla pliku *rectangles_test.txt* to $3628$.

## Zadanie 4

Podaj wszystkie prostokąty, oraz ich liczbę, które zawierają **wewnątrz** (nie na krawędzi) środek układu współrzędnych (punkt $(0,0)$).

Wynik dla pliku *rectangles_test.txt* to:

```
-33 11 34 -30
Łącznie prostokątów: 1
```

## Zadanie 5

Oblicz ile jest takich par prostokątów, że jeden jest **całkowicie** zawarty wewnątrz drugiego (nie stykają się krawędziami).

Wynik dla pliku *rectangles_test.txt* to: $2$.

## Zadanie 6

Analizując wszystkie **punkty** podane w pliku, znajdź parę punktów, które są od siebie najbardziej oddalone. Wypisz tę parę oraz odległość pomiędzy nimi z dokładnością do dwóch miejsc po przecinku. Jeżeli jest kilka takich par, wypisz wszystkie.

Wynik dla pliku *rectangles_test.txt* to:

```
(-33, 11) (50, -50)
Odległość: 103.00
```
