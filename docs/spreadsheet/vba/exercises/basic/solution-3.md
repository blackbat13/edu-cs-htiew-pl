# Rozwiązanie 3

## Treść zadania

Napisz funkcję `CzyParzysta` zgodną z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* PRAWDA, jeżeli $$n$$ jest liczbą parzystą, FAŁSZ w przeciwnym przypadku.

## Rozwiązanie

```vb
Function CzyParzysta(n As Integer) As Boolean
    If n Mod 2 = 0 Then
        CzyParzysta = True
    Else
        CzyParzysta = False
    End If
End Function
```

## Opis rozwiązania

### 1. Definicja funkcji

```vb
Function CzyParzysta(n As Integer) As Boolean
```

* `Function CzyParzysta` rozpoczyna definicję funkcji o nazwie `CzyParzysta`.
* `n As Integer` oznacza, że funkcja przyjmuje jeden argument (wejście) o nazwie `n`, który jest typu `Integer` (liczba całkowita).
* `As Boolean` na końcu mówi, że funkcja zwraca wartość logiczną (Prawda/Fałsz).

### 2. Sprawdzenie, czy liczba jest parzysta

```vb
If n Mod 2 = 0 Then
```

* `If` rozpoczyna strukturę warunkową.
* `n Mod 2` oblicza resztę z dzielenia liczby `n` przez 2. Działanie `Mod` jest operatorem modulo, który zwraca resztę z dzielenia.
* `= 0` sprawdza, czy reszta z dzielenia przez 2 wynosi 0, co jest prawdziwe dla liczb parzystych.

### 3. Zwrócenie wartości True lub False

```vb
    CzyParzysta = True
Else
    CzyParzysta = False
End If
```

* Jeśli warunek `n Mod 2 = 0` jest spełniony (czyli liczba jest parzysta), funkcja przypisuje `True` do `CzyParzysta`, co oznacza, że zwróci wartość `True`.
* `Else` oznacza, że jeśli warunek nie jest spełniony (liczba jest nieparzysta), funkcja przypisuje `False` do `CzyParzysta`, co oznacza, że zwróci wartość `False`.
* `End If` kończy strukturę warunkową.

### 4. Koniec funkcji

```vb
End Function
```

* `End Function` oznacza koniec definicji funkcji.
