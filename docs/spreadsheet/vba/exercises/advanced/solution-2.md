# Rozwiązanie 2

## Treść zadania

Stwórz przycisk, który po kliknięciu pokoloruje wszystkie komórki w zakresie `A1:A10`, które zawierają wartość poniżej średniej z tego zakresu.

## Rozwiązanie

```vb
Sub PonizejSredniej_Click()
    Dim zakres As Range
    Dim srednia As Double
    
    Set zakres = Range("A1:A10")
    srednia = Application.WorksheetFunction.Average(zakres)
    
    For Each kom In zakres
        If kom.Value < srednia Then
            kom.Interior.Color = RGB(0, 255, 0)
        End If
    Next kom
End Sub
```

## Opis rozwiązania

### 1. Deklarowanie zmiennych

```vb
Dim zakres As Range
Dim srednia As Double
```

- `Dim zakres As Range` deklaruje zmienną `zakres`, która będzie przechowywać odniesienie do zakresu komórek.
- `Dim srednia As Double` deklaruje zmienną `srednia`, która będzie przechowywać średnią wartość jako liczbę zmiennoprzecinkową (`Double`).

### 2. Ustawianie zakresu i obliczanie średniej

```vb
Set zakres = Range("A1:A10")
srednia = Application.WorksheetFunction.Average(zakres)
```

- `Set zakres = Range("A1:A10")` przypisuje zakres komórek od A1 do A10 do zmiennej `zakres`.
- `srednia = Application.WorksheetFunction.Average(zakres)` oblicza średnią wartość dla podanego zakresu za pomocą funkcji `Average` i przypisuje wynik do zmiennej `srednia`.

### 3. Pętla przez komórki w zakresie

```vb
For Each kom In zakres
```

- `For Each kom In zakres` rozpoczyna pętlę, która wykona blok kodu dla każdej komórki (`kom`) w określonym zakresie (`zakres`).

### 4. Sprawdzanie wartości i zmiana koloru tła

```vb
    If kom.Value < srednia Then
        kom.Interior.Color = RGB(0, 255, 0)
    End If
```

- `If kom.Value < srednia Then` sprawdza, czy wartość aktualnie przeglądanej komórki (`kom.Value`) jest mniejsza niż średnia (`srednia`).
- `kom.Interior.Color = RGB(0, 255, 0)` zmienia kolor tła komórki na zielony (za pomocą kodu koloru RGB), jeśli wartość jest poniżej średniej.

### 5. Koniec pętli

```vb
Next kom
```

- `Next kom` kończy bieżący cykl pętli i przechodzi do następnej komórki w zakresie, jeśli nie wszystkie komórki zostały jeszcze sprawdzone.

### 6. Koniec procedury

```vb
End Sub
```

- `End Sub` oznacza koniec procedury.
