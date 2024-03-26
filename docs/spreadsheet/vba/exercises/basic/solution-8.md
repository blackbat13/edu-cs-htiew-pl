# Rozwiązanie 8

## Treść zadania

Napisz funkcję `ZWielkiej` zgodną z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $wyraz$ - ciąg znaków

#### Wynik

* Podany wyraz, w którym pierwsza litera jest wielka.

## Rozwiązanie

```vb
Function ZWielkiej(wyraz As String) As String
    Dim wynik As String
    Dim pierwsza As String
    
    pierwsza = Left(wyraz, 1)
    wynik = Right(wyraz, Len(wyraz) - 1)
    wynik = UCase(pierwsza) + wynik
    
    ZWielkiej = wynik
End Function
```

## Opis rozwiązania

### 1. Definicja funkcji

```vb
Function ZWielkiej(wyraz As String) As String
```

- `Function ZWielkiej` rozpoczyna definicję funkcji o nazwie `ZWielkiej`.
- `wyraz As String` oznacza, że funkcja przyjmuje jeden argument (wejście) o nazwie `wyraz`, który jest typu `String` (ciąg znaków).
- `As String` na końcu mówi, że funkcja zwraca wartość typu `String` (ciąg znaków).

### 2. Deklarowanie i inicjalizacja zmiennych

```vb
Dim wynik As String
Dim pierwsza As String
```

- `Dim wynik As String` deklaruje zmienną `wynik` jako ciąg znaków.
- `Dim pierwsza As String` deklaruje zmienną `pierwsza` również jako ciąg znaków.

### 3. Ekstrakcja pierwszej litery i reszty wyrazu

```vb
pierwsza = Left(wyraz, 1)
wynik = Right(wyraz, Len(wyraz) - 1)
```

- `pierwsza = Left(wyraz, 1)` przypisuje pierwszą literę wyrazu do zmiennej `pierwsza`.
- `wynik = Right(wyraz, Len(wyraz) - 1)` przypisuje resztę wyrazu (oprócz pierwszej litery) do zmiennej `wynik`.

### 4. Zmiana pierwszej litery na wielką

```vb
wynik = UCase(pierwsza) + wynik
```

- `UCase(pierwsza)` zmienia pierwszą literę na wielką.
- `+ wynik` dodaje resztę wyrazu (która pozostaje bez zmian) do zmienionej pierwszej litery.

### 5. Zwracanie wyniku

```vb
ZWielkiej = wynik
```

- `ZWielkiej = wynik` przypisuje ostateczną wartość zmiennej `wynik` do samej funkcji `ZWielkiej`, co oznacza, że funkcja zwróci tę wartość jako swój wynik.

### 6. Koniec funkcji

```vb
End Function
```

- `End Function` oznacza koniec definicji funkcji.
