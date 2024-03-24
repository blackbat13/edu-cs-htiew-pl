# Funkcje

## Zadanie 1

Napisz program zgodny z poniższą specyfikacją. Wypisanie komunikatu powinno zostać zrealizowane za pomocą funkcji.

### Specyfikacja

#### Dane

* $$imie$$ - ciąg znaków, małych i wielkich liter alfabetu angielskiego

#### Wynik

* Komunikat powitania w formie "_Witaj \[**imie**]!_", np. "_Witaj Damian!_"

## Zadanie 2

Napisz program zgodny z poniższą specyfikacją. Obliczanie sumy powinno być zrealizowane za pomocą funkcji.

### Specyfikacja

#### Dane

* $$a, b$$ - dwie liczby całkowite

#### Wynik

* Suma liczb $$a$$ i $$b$$ 

## Zadanie 3

Napisz program zgodny z poniższą specyfikacją. Obliczenie i wypisywanie dzielników powinno być zrealizowane za pomocą funkcji.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* Wszystkie dzielniki liczby $$n$$ 

### Przykład

#### Dane

```
n := 10
```

**Wynik**: $$1, 2, 5, 10$$ 

## Zadanie 4

Napisz program zgodny z poniższą specyfikacją. Wczytywanie tablicy oraz wypisywanie tablicy na ekranie zrealizuj za pomocą osobnych funkcji.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$tab[n]$$ - tablica liczb całkowitych

#### Wynik

* Wczytana tablica wypisana na ekranie w jednej linii, każdy element oddzielony spacją

## Zadanie 5

Napisz program zgodny z poniższą specyfikacją. Losowanie tablicy oraz wypisywanie tablicy na ekranie zrealizuj za pomocą osobnych funkcji.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$p, k$$ - liczby całkowite, $$p < k$$

#### Wynik

* $$n$$-elementowa tablica losowych liczb całkowitych z przedziału $$[p,k)$$

## Zadanie 6

Napisz program zgodny z poniższą specyfikacją. Wczytywanie tablicy, przemnażanie tablicy oraz wypisywanie tablicy na ekranie zrealizuj za pomocą osobnych funkcji.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$k$$ - liczba całkowita
* $$tab[n]$$ - tablica liczb całkowitych

#### Wynik

* Tablica powstała poprzez przemnożenie każdego elementu tablicy $$tab$$ przez liczbę $$k$$ 

### Przykład

#### Dane

```
n := 5
k := 2
tab := [4, 1, 7, 0, 2]
```

**Wynik**: $$[8, 2, 14, 0, 4]$$ 

## Zadanie 7

Napisz program zgodny z poniższą specyfikacją. Wczytywanie tablicy, a także obliczanie każdej ze statystyk zrealizuj za pomocą osobnych funkcji.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$tab[n]$$ - tablica liczb całkowitych

#### Wynik

* Statystyki tablicy $$tab$$: minimum, maksimum, suma, średnia

### Przykład

#### Dane

```
n := 5
tab := [4, 1, 7, 0, 2]
```

#### Wynik

```
minimum := 0
maksimum := 7
suma := 14
srednia := 2.8
```