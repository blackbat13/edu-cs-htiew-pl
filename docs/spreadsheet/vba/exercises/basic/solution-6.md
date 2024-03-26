# Rozwiązanie 6

## Treść zadania

Napisz funkcję `IleCyfr` zgodną z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $n$ - liczba naturalna

#### Wynik

* Liczba cyfr liczby $n$.

## Rozwiązanie

```vb
Function IleCyfr(n As Long) As Integer
    Dim wynik As Integer
    
    wynik = 1

    While n > 9
        n = n / 10
        wynik = wynik + 1
    Wend
    
    IleCyfr = wynik
End Function
```

## Opis rozwiązania

### 1. Definicja funkcji

```vb
Function IleCyfr(n As Long) As Integer
```

- `Function IleCyfr` rozpoczyna definicję funkcji o nazwie `IleCyfr`.
- `n As Long` oznacza, że funkcja przyjmuje jeden argument (wejście) o nazwie `n`, który jest typu `Long`. Typ `Long` to typ danych służący do przechowywania dużych liczb całkowitych.
- `As Integer` na końcu mówi, że funkcja zwraca wartość całkowitą (`Integer`).

### 2. Inicjalizacja zmiennej wynikowej

```vb
Dim wynik As Integer
wynik = 1
```

- `Dim wynik As Integer` deklaruje zmienną `wynik` jako liczbę całkowitą.
- `wynik = 1` inicjalizuje zmienną `wynik` wartością 1, ponieważ nawet liczba jednocyfrowa ma jedną cyfrę.

### 3. Pętla obliczeniowa

```vb
While n > 9
```

- `While n > 9` rozpoczyna pętlę, która będzie się wykonywać, dopóki `n` jest większe niż 9. Liczba większa niż 9 ma przynajmniej dwie cyfry.

### 4. Dzielenie liczby i zliczanie cyfr

```vb
    n = n / 10
    wynik = wynik + 1
```

- `n = n / 10` dzieli `n` przez 10. To efektywnie "usuwa" ostatnią cyfrę z liczby. Na przykład, 123 podzielone przez 10 daje 12.
- `wynik = wynik + 1` inkrementuje zmienną `wynik` o 1. Każde podzielenie przez 10 oznacza, że znajdujemy kolejną cyfrę.

### 5. Koniec pętli

```vb
Wend
```

- `Wend` kończy pętlę `While`. Pętla będzie kontynuowana, dopóki nie zostanie osiągnięty warunek `n > 9`.

### 6. Zwracanie wyniku

```vb
IleCyfr = wynik
```

- `IleCyfr = wynik` przypisuje ostateczną wartość zmiennej `wynik` do samej funkcji `IleCyfr`, co oznacza, że funkcja zwróci tę wartość jako swój wynik.

### 7. Koniec funkcji

```vb
End Function
```

- `End Function` oznacza koniec definicji funkcji.
