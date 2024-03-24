# Rozwiązanie 4

## Treść zadania

Napisz funkcję `IleParzystych` zliczającą ile komórek z podanego zakresu zawiera liczby parzyste.

## Rozwiązanie

```vb
Function IleParzystych(zakres As Range) As Integer
    Dim wynik As Integer
    
    wynik = 0

    For Each kom In zakres
        If kom.Value Mod 2 = 0 Then
            wynik = wynik + 1
        End If
    Next kom
    
    IleParzystych = wynik
End Function
```

## Opis rozwiązania

### 1. Definicja funkcji

```vb
Function IleParzystych(zakres As Range) As Integer
```

- `Function IleParzystych` rozpoczyna definicję funkcji o nazwie `IleParzystych`.
- `zakres As Range` oznacza, że funkcja przyjmuje jeden argument (wejście) o nazwie `zakres`, który jest typu `Range`. `Range` odnosi się do zakresu komórek w arkuszu Excela.
- `As Integer` na końcu mówi, że funkcja zwraca wartość całkowitą (`Integer`).

### 2. Inicjalizacja zmiennej wynikowej

```vb
Dim wynik As Integer
wynik = 0
```

- `Dim wynik As Integer` deklaruje zmienną `wynik` jako liczbę całkowitą.
- `wynik = 0` inicjalizuje zmienną `wynik` wartością 0. Ta zmienna będzie służyć do zliczania parzystych liczb.

### 3. Pętla przez komórki w zakresie

```vb
For Each kom In zakres
```

- `For Each kom In zakres` rozpoczyna pętlę, która przejdzie przez każdą komórkę (`kom`) w określonym zakresie (`zakres`).

### 4. Sprawdzenie parzystości i zliczanie

```vb
    If kom.Value Mod 2 = 0 Then
        wynik = wynik + 1
    End If
```

- `If kom.Value Mod 2 = 0 Then` sprawdza, czy wartość w komórce (`kom.Value`) jest liczbą parzystą. Jeśli reszta z dzielenia wartości komórki przez 2 wynosi 0, to liczba jest parzysta.
- `wynik = wynik + 1` inkrementuje zmienną `wynik`, jeśli liczba jest parzysta.

### 5. Przejście do następnej komórki

```vb
Next kom
```

- `Next kom` kończy bieżący cykl pętli i przechodzi do następnej komórki w zakresie.

### 6. Zwracanie wyniku

```vb
IleParzystych = wynik
```

- Przypisuje ostateczną wartość zmiennej `wynik` do samej funkcji `IleParzystych`, co oznacza, że funkcja zwróci tę wartość jako swój wynik.

### 7. Koniec funkcji

```vb
End Function
```

- `End Function` oznacza koniec definicji funkcji.
