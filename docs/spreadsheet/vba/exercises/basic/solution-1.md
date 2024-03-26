# Rozwiązanie 1

## Treść zadania

Napisz funkcję `CnaF` zgodną z poniższą specyfikacją.

Skorzystaj z następującego wzoru:

$F = \frac{9}{5} * C + 32$

gdzie:

* $C$ - temperatura podana w stopniach Celsjusza
* $F$ - temperatura podana w stopniach Fahrenheita

### Specyfikacja

#### Dane

* $temp$ - liczba rzeczywista, temperatura podana w stopniach Celsjusza

#### Wynik

* Podana temperatura przekonwertowana na stopnie Fahrenheita.

## Rozwiązanie

```vb
Function CtoF(temp As Double) As Double
    CtoF = ((temp * 9) / 5) + 32
End Function
```

## Opis rozwiązania

### 1. Definicja funkcji

```vb
Function CtoF(temp As Double) As Double
```

- `Function CtoF` rozpoczyna definicję funkcji o nazwie `CtoF`.
- `temp As Double` oznacza, że funkcja przyjmuje jeden argument (wejście) o nazwie `temp`, który jest typu `Double`. Typ `Double` to typ danych służący do przechowywania dużych liczb zmiennoprzecinkowych.
- `As Double` na końcu mówi, że funkcja zwraca wartość typu `Double`.

### 2. Wykonanie obliczeń

```vb
    CtoF = ((temp * 9) / 5) + 32
```

- Ta linia jest sercem funkcji. Przeprowadza rzeczywiste przeliczenie temperatury z Celsjusza na Fahrenheita.
- `((temp * 9) / 5) + 32` to wzór matematyczny na przeliczenie Celsjusza na Fahrenheita.
  - Najpierw mnoży temperaturę w Celsjuszu (`temp`) przez 9.
  - Następnie wynik dzieli przez 5.
  - Wreszcie dodaje 32, by uzyskać odpowiednik w stopniach Fahrenheita.
- `CtoF =` przypisuje wynik tego obliczenia do samej funkcji `CtoF`, co oznacza, że funkcja zwróci tę wartość jako swój wynik.

### 3. Koniec funkcji

```vb
End Function
```

- `End Function` oznacza koniec definicji funkcji.
