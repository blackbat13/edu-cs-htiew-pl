# Całkowanie numeryczne

## [Opis problemu](../../../../algorithms/numerical-methods/numerical-integration.md)

## Metoda prostokątów

```python linenums="1"
def f(x: float) -> float:
    return x * x + 2 * x

def rectangles_method(a: int, b: int, n: int) -> float:
    rectangle_width = (b - a) / n
    area = 0
    current_point = a

    for i in range(n):
        current_point += rectangle_width
        rectangle_height = f(current_point)
        area += rectangle_height * rectangle_width

    return area

a = 0
b = 10
n = 100
area = rectangles_method(a, b, n)
print(area)
```

### Opis implementacji

Funkcja `f` (**linia 1**) przyjmuje jeden parametr rzeczywisty i jako wynik zwraca liczbę rzeczywistą. Funkcja ta symuluje funkcję matematyczną, której pole pod wykresem chcemy policzyć. 

Funkcja `rectangles_method` (**linia 5**) realizuje algorytm całkowania numerycznego metodą prostokątów i przyjmuje trzy parametry: początek przedziału (`a`), koniec przedziału (`b`) oraz liczbę prostokątów (`n`). Funkcja jako wynik zwraca liczbę rzeczywistą reprezentującą przybliżenie pola pod wykresem funkcji $f(x)=x^2+2x$ na przedziale $<a, b>$. Wewnątrz funkcji zaczynamy od policzenia szerokości jednego prostokąta, dzieląc długość przedziału przez liczbę prostokątów (**linia 6**). Następnie tworzymy zmienną do zapamiętania obliczanego pola (**linia 7**) oraz zmienną do zapamiętania obecnej pozycji na osi $x$ (**linia 8**). W następnej kolejności przechodzimy pętlą $n$ razy (**linia 10**). Wewnątrz pętli przesuwamy obecną pozycję na osi $x$ w prawo o szerokość jednego prostokąta (**linia 11**). Następnie obliczamy wysokość prostokąta w obecnym punkcie poprzez obliczenie wartości funkcji w tym miejscu (**linia 12**). Obliczoną wysokość wykorzystujemy do policzenia pola obecnego prostokąta i dodania go do zliczanego pola pod wykresem funkcji (**linia 13**). Na koniec funkcji, po wyjściu z pętli, zwracamy obliczone pole pod wykresem funkcji (**linia 15**).

W części głównej programu przygotowujemy dane do naszego algorytmu: początek przedziału (**linia 18**), koniec przedziału (**linia 19**) oraz liczbę prostokątów (**linia 20**). Następnie wywołujemy funkcję `rectangles_method` z przygotowanymi danymi, a jej wynik zapisujemy w zmiennej `area` (**linia 21**). Na koniec wypisujemy wynik na ekranie (**linia 22**).

## Metoda trapezów

```python linenums="1"
def f(x: float) -> float:
    return x * x + 2 * x

def trapezes_method(a: int, b: int, n: int) -> float:
    trapeze_height = (b - a) / n
    area = 0
    current_point = a

    for i in range(n):
        trapeze_first_side = f(current_point)
        current_point += trapeze_height
        trapeze_second_side = f(current_point)
        area += ((trapeze_first_side + trapeze_second_side) * trapeze_height) / 2

    return area

a = 0
b = 10
n = 100
area = trapezes_method(a, b, n)
print(area)
```

### Opis implementacji

Funkcja `f` (**linia 1**) przyjmuje jeden parametr rzeczywisty i jako wynik zwraca liczbę rzeczywistą. Funkcja ta symuluje funkcję matematyczną, której pole pod wykresem chcemy policzyć. 

Funkcja `trapezes_method` (**linia 5**) realizuje algorytm całkowania numerycznego metodą trapezów i przyjmuje trzy parametry: początek przedziału (`a`), koniec przedziału (`b`) oraz liczbę trapezów (`n`). Funkcja jako wynik zwraca liczbę rzeczywistą reprezentującą przybliżenie pola pod wykresem funkcji $f(x)=x^2+2x$ na przedziale $<a, b>$. Wewnątrz funkcji zaczynamy od policzenia wysokości jednego trapezu, dzieląc długość przedziału przez liczbę trapezów (**linia 6**). Następnie tworzymy zmienną do zapamiętania obliczanego pola (**linia 7**) oraz zmienną do zapamiętania obecnej pozycji na osi $x$ (**linia 8**). W następnej kolejności przechodzimy pętlą $n$ razy (**linia 10**). Wewnątrz pętli obliczamy długość pierwszej podstawy trapezu (**linia 11**), a następnie przesuwamy obecną pozycję na osi $x$ w prawo o wysokość jednego trapezu (**linia 12**). Następnie obliczamy długość drugiej podstawy trapezu w obecnym punkcie poprzez obliczenie wartości funkcji w tym miejscu (**linia 13**). Obliczone długości podstaw wykorzystujemy do policzenia pola obecnego trapezu i dodania go do zliczanego pola pod wykresem funkcji (**linia 14**). Na koniec funkcji, po wyjściu z pętli, zwracamy obliczone pole pod wykresem funkcji (**linia 16**).

W części głównej programu przygotowujemy dane do naszego algorytmu: początek przedziału (**linia 19**), koniec przedziału (**linia 20**) oraz liczbę prostokątów (**linia 21**). Następnie wywołujemy funkcję `trapezes_method` z przygotowanymi danymi, a jej wynik zapisujemy w zmiennej `area` (**linia 22**). Na koniec wypisujemy wynik na ekranie (**linia 23**).
