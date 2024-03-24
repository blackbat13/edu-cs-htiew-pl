# Rozwiązanie 5

## Treść zadania

Napisz funkcję `NWW` zgodną z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$a$$ - liczba naturalna
* $$b$$ - liczba naturalna

#### Wynik

* Najmniejsza wspólna wielokrotność liczb $$a$$ i $$b$$.

## Rozwiązanie

```vb
Function NWW(a As Integer, b As Integer) As Integer
    Dim na As Integer
    Dim nb As Integer

    na = a
    nb = b

    While na <> nb
        If na < nb Then
            na = na + a
        Else
            nb = nb + b
        End If
    Wend
    
    NWW = na
End Function
```

## Opis rozwiązania

### 1. Definicja funkcji

```vb
Function NWW(a As Integer, b As Integer) As Integer
```

- `Function NWW` rozpoczyna definicję funkcji o nazwie `NWW`.
- `a As Integer, b As Integer` oznacza, że funkcja przyjmuje dwa argumenty (`a` i `b`), oba będące liczbami całkowitymi.
- `As Integer` na końcu mówi, że funkcja zwraca wartość całkowitą (`Integer`).

### 2. Deklarowanie i inicjalizacja zmiennych

```vb
Dim na As Integer
Dim nb As Integer

na = a
nb = b
```

- `Dim na As Integer` i `Dim nb As Integer` deklarują dwie zmienne pomocnicze, `na` i `nb`.
- `na = a` i `nb = b` inicjalizują te zmienne wartościami argumentów `a` i `b`. Zmienne te będą modyfikowane w trakcie obliczeń, zachowując oryginalne wartości `a` i `b`.

### 3. Pętla obliczeniowa

```vb
While na <> nb
```

- `While na <> nb` rozpoczyna pętlę, która będzie się wykonywać, dopóki `na` nie będzie równe `nb`. To warunek konieczny do znalezienia NWW.

### 4. Logika obliczeniowa

```vb
    If na < nb Then
        na = na + a
    Else
        nb = nb + b
    End If
```

- `If na < nb Then` sprawdza, czy `na` jest mniejsze niż `nb`.
- `na = na + a` zwiększa `na` o wartość `a`, jeśli `na` jest mniejsze. Cel jest taki, by zwiększyć mniejszą z liczb, zbliżając ją do wartości większej.
- `nb = nb + b` zwiększa `nb` o wartość `b`, jeśli `na` jest większe lub równe `nb`. Podobnie, cel jest taki, by zwiększyć mniejszą liczbę.

### 5. Koniec pętli

```vb
Wend
```

- `Wend` kończy pętlę `While`. Pętla będzie kontynuowana, dopóki `na` nie będzie równe `nb`.

### 6. Zwracanie wyniku

```vb
NWW = na
```

- `NWW = na` przypisuje wynik obliczeń (który teraz jest równy w obu zmiennych, `na` i `nb`) do samej funkcji `NWW`, co oznacza, że funkcja zwróci tę wartość jako swój wynik.

### 7. Koniec funkcji

```vb
End Function
```

- `End Function` oznacza koniec definicji funkcji.
