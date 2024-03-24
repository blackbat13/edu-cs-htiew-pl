# Rozwiązanie 1

## Treść zadania

Napisz funkcję `SzukajMax`, która dla podanego zakresu komórek, znajdzie i zwróci jako wynik adres komórki zawierającej wartość maksymalną. Jeżeli kilka komórek zawiera tę wartość, funkcja powinna zwrócić adres pierwszej z nich.

## Rozwiązanie

```vb
Function SzukajMax(zakres As Range) As String
    maks = Application.WorksheetFunction.Max(zakres)
    
    For Each kom In zakres
        If kom.Value = maks Then
            SzukajMax = kom.Address
            Exit For
        End If
    Next kom
End Function
```

## Opis rozwiązania

### 1. Definicja funkcji

```vb
Function SzukajMax(zakres As Range) As String
```

- `Function SzukajMax` rozpoczyna definicję funkcji o nazwie `SzukajMax`.
- `zakres As Range` oznacza, że funkcja przyjmuje jeden argument (wejście) o nazwie `zakres`, który jest typu `Range`. `Range` odnosi się do zakresu komórek w arkuszu Excela.
- `As String` na końcu mówi, że funkcja zwraca wartość typu `String` (ciąg znaków), który będzie adresem komórki.

### 2. Znalezienie maksymalnej wartości

```vb
maks = Application.WorksheetFunction.Max(zakres)
```

- `maks = Application.WorksheetFunction.Max(zakres)` wykorzystuje wbudowaną funkcję `Max` do znalezienia największej wartości w podanym zakresie `zakres`. Wynik jest przypisywany do zmiennej `maks`.

### 3. Przeszukiwanie zakresu w poszukiwaniu maksymalnej wartości

```vb
For Each kom In zakres
```

- `For Each kom In zakres` rozpoczyna pętlę, która przejdzie przez każdą komórkę (`kom`) w określonym zakresie (`zakres`).

### 4. Porównanie wartości i znalezienie adresu

```vb
    If kom.Value = maks Then
        SzukajMax = kom.Address
        Exit For
    End If
```

- `If kom.Value = maks Then` sprawdza, czy wartość w aktualnie przeglądanej komórce (`kom.Value`) jest równa maksymalnej znalezionej wartości (`maks`).
- `SzukajMax = kom.Address` przypisuje adres komórki z maksymalną wartością do samej funkcji `SzukajMax`, co oznacza, że funkcja zwróci ten adres jako swój wynik.
- `Exit For` natychmiast kończy pętlę po znalezieniu komórki z maksymalną wartością, ponieważ już znaleziono potrzebne informacje.

### 5. Koniec pętli

```vb
Next kom
```

- `Next kom` kończy bieżący cykl pętli i przechodzi do następnej komórki w zakresie, jeśli nie znaleziono jeszcze komórki z maksymalną wartością.

### 6. Koniec funkcji

```vb
End Function
```

- `End Function` oznacza koniec definicji funkcji.
