# Rozwiązanie 4

## Treść zadania

Komórki `A1:A10` zawierają imiona i nazwiska oddzielone pojedynczą spacją. Stwórz przycisk, który po kliknięciu umieści w kolumnie B imiona, a w kolumnie C nazwiska z odpowiadających komórek z kolumny A.

## Rozwiązanie

```vb
Sub Podziel_Click()
    Dim dane, imiona, nazwiska As Range
    Dim poz As Integer
    
    Set dane = Range("A1:A10")
    Set imiona = Range("B1")
    Set nazwiska = Range("C1")
    
    For Each kom In dane
        poz = InStr(kom.Value, " ")
        imiona.Value = Left(kom.Value, poz)
        nazwiska.Value = Right(kom.Value, Len(kom.Value) - poz)
        Set imiona = imiona.Offset(1, 0)
        Set nazwiska = nazwiska.Offset(1, 0)
    Next kom
End Sub
```

## Opis rozwiązania

### 1. Deklarowanie zmiennych

```vb
Dim dane, imiona, nazwiska As Range
Dim poz As Integer
```

- `Dim` to skrót od "Dimension" i służy do deklarowania zmiennych.
- `dane, imiona, nazwiska` to zmienne, które będą przechowywać odniesienia do zakresów komórek (czyli grup komórek) w arkuszu.
- `poz` to zmienna typu Integer, która będzie przechowywać pozycję, gdzie znajduje się spacja w ciągu znaków.

### 2. Ustawianie zakresów

```vb
Set dane = Range("A1:A10")
Set imiona = Range("B1")
Set nazwiska = Range("C1")
```

- `Set` służy do przypisania odniesienia do obiektu do zmiennej.
- `dane` jest ustawiony na komórki od A1 do A10, `imiona` na komórkę B1, a `nazwiska` na C1.

### 3. Pętla przez komórki w zakres1

```vb
For Each kom In dane
```

- `For Each` rozpoczyna pętlę, która wykona blok kodu dla każdego elementu w kolekcji (tutaj dla każdej komórki w zakresie `dane`).

### 4. Szukanie pozycji spacji i dzielenie tekstu

```vb
    poz = InStr(kom.Value, " ")
    imiona.Value = Left(kom.Value, poz)
    nazwiska.Value = Right(kom.Value, Len(kom.Value) - poz)
```

- `InStr(kom.Value, " ")` znajduje pozycję pierwszej spacji w tekście komórki.
- `Left(kom.Value, poz)` wycina lewą część tekstu do spacji.
- `Right(kom.Value, Len(kom.Value) - poz)` wycina prawą część tekstu od spacji.

### 5. Przesuwanie zakresów

```vb
    Set imiona = imiona.Offset(1, 0)
    Set nazwiska = nazwiska.Offset(1, 0)
```

- `Offset(1, 0)` przesuwa zakres o jedną komórkę w dół. To oznacza, że następny podzielony tekst zostanie umieszczony w kolejnej komórce w dół.

### 6. Koniec pętli

```vb
Next kom
```

- `Next` oznacza koniec pętli `For Each` i powrót do jej początku, by przejść do kolejnej komórki w zakresie `dane`.

### 7. Koniec procedury

```vb
End Sub
```

- `End Sub` oznacza koniec skryptu (procedury).
