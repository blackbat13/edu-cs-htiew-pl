# Rozwiązanie 3

## Treść zadania

Stwórz przycisk, który po kliknięciu wpisze w kolumnie C wszystkie wartości z zakresu `A1:A10`, które występują jednocześnie w zakresie `B1:B10`. Możesz założyć, że w obu zakresach wartości są unikalne w ramach danego zakresu.

## Rozwiązanie

```vb
Sub CzescWspolna_Click()
    Dim dane1, dane2, wynik As Range
    
    Set dane1 = Range("A1:A10")
    Set dane2 = Range("B1:B10")
    Set wynik = Range("C1")
    
    For Each kom1 In dane1
        For Each kom2 In dane2
            If kom1.Value = kom2.Value Then
                wynik.Value = kom1.Value
                Set wynik = wynik.Offset(1, 0)
                Exit For
            End If
        Next kom2
    Next kom1
End Sub
```

## Opis rozwiązania

### 1. Deklarowanie zmiennych

```vb
Dim dane1, dane2, wynik As Range
```

- `Dim` używane jest do deklaracji zmiennych.
- `dane1, dane2, wynik` są zmiennymi reprezentującymi zakresy komórek w arkuszu.

### 2. Ustawianie zakresów

```vb
Set dane1 = Range("A1:A10")
Set dane2 = Range("B1:B10")
Set wynik = Range("C1")
```

- `Set` przypisuje odniesienie do obiektu do zmiennej.
- `dane1` i `dane2` są ustawione na zakresy komórek A1:A10 i B1:B10 odpowiednio, a `wynik` jest ustawiony na komórkę C1.

### 3. Pętla przez każdą komórkę w zakresie dane1

```vb
For Each kom1 In dane1
```

- `For Each` to pętla, która wykonuje blok kodu dla każdego elementu w kolekcji (tutaj dla każdej komórki w zakresie `dane1`).

### 4. Druga pętla przez każdą komórkę w zakresie dane2

```vb
    For Each kom2 In dane2
```

- To druga pętla `For Each` wewnątrz pierwszej, która przechodzi przez każdą komórkę w zakresie `dane2`.

### 5. Porównanie wartości i zapisywanie wyniku

```vb
        If kom1.Value = kom2.Value Then
            wynik.Value = kom1.Value
            Set wynik = wynik.Offset(1, 0)
            Exit For
        End If
```

- `If kom1.Value = kom2.Value Then` sprawdza, czy wartość w komórce z `dane1` jest taka sama jak wartość w komórce z `dane2`.
- Jeśli wartości są takie same, wartość ta jest umieszczana w komórce wskazanej przez `wynik`.
- `Set wynik = wynik.Offset(1, 0)` przesuwa zakres `wynik` o jedną komórkę w dół, by następna wartość wspólna była zapisana w kolejnej komórce.
- `Exit For` natychmiast kończy wewnętrzną pętlę `For Each`, gdy znaleziono dopasowanie, aby uniknąć niepotrzebnego przeszukiwania reszty `dane2` dla tej samej wartości `kom1`.

### 6. Koniec pętli

```vb
        Next kom2
    Next kom1
```

- `Next kom2` i `Next kom1` oznaczają koniec odpowiednich pętli `For Each` i powrót do ich początku, aby przejść do kolejnej komórki w odpowiednich zakresach.

### 7. Koniec procedury

```vb
End Sub
```

- `End Sub` oznacza koniec skryptu (procedury).
