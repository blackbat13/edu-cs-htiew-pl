# Rozwiązanie 5

## Treść zadania

Napisz funkcję `ZliczWyrazy`, która dla podanego tekstu zwróci liczbę wyrazów w nim zawartych. Za wyraz uznajemy ciąg znaków nie zawierający spacji, a wyrazy są oddzielone pojedynczą spacją.

## Rozwiązanie

```vb
Function ZliczWyrazy(tekst As String) As Integer
    Dim poz, wynik As Integer

    poz = 1
    wynik = 0
    
    While poz > 0 And poz < Len(tekst)
        poz = InStr(poz, tekst, " ")
        If poz > 0 Then
            poz = poz + 1
        End If
        
        wynik = wynik + 1
    Wend
    
    ZliczWyrazy = wynik
End Function
```

## Opis rozwiązania

### 1. Definicja funkcji

```vb
Function ZliczWyrazy(tekst As String) As Integer
```

- `Function ZliczWyrazy` rozpoczyna definicję funkcji o nazwie `ZliczWyrazy`.
- `tekst As String` oznacza, że funkcja przyjmuje jeden argument (wejście) o nazwie `tekst`, który jest typu `String` (ciąg znaków).
- `As Integer` na końcu mówi, że funkcja zwraca wartość całkowitą (`Integer`).

### 2. Deklarowanie i inicjalizacja zmiennych

```vb
Dim poz, wynik As Integer

poz = 1
wynik = 0
```

- `Dim poz, wynik As Integer` deklaruje dwie zmienne `poz` i `wynik` jako liczby całkowite.
- `poz = 1` inicjalizuje zmienną `poz` wartością 1, która będzie używana do śledzenia pozycji w tekście.
- `wynik = 0` inicjalizuje zmienną `wynik` wartością 0, która będzie używana do zliczania wyrazów.

### 3. Pętla obliczeniowa

```vb
While poz > 0 And poz < Len(tekst)
```

- `While poz > 0 And poz < Len(tekst)` rozpoczyna pętlę, która będzie się wykonywać, dopóki `poz` jest większe od 0 i mniejsze od długości całego tekstu.

### 4. Szukanie spacji i zliczanie wyrazów

```vb
    poz = InStr(poz, tekst, " ")
    If poz > 0 Then
        poz = poz + 1
    End If
    
    wynik = wynik + 1
```

- `poz = InStr(poz, tekst, " ")` szuka pierwszej spacji w tekście zaczynając od pozycji `poz`. Jeśli znajdzie, `poz` zostanie zaktualizowane do pozycji tej spacji.
- `If poz > 0 Then poz = poz + 1` przesuwa `poz` o jeden dalej, aby uniknąć ponownego zliczania tej samej spacji.
- `wynik = wynik + 1` inkrementuje zmienną `wynik` o 1 za każdym razem, gdy znaleziono spację, co oznacza kolejny wyraz.

### 5. Koniec pętli

```vb
Wend
```

- `Wend` kończy pętlę `While`.

### 6. Zwracanie wyniku

```vb
ZliczWyrazy = wynik
```

- `ZliczWyrazy = wynik` przypisuje ostateczną wartość zmiennej `wynik` do samej funkcji `ZliczWyrazy`, co oznacza, że funkcja zwróci tę wartość jako swój wynik.

### 7. Koniec funkcji

```vb
End Function
```

- `End Function` oznacza koniec definicji funkcji.
