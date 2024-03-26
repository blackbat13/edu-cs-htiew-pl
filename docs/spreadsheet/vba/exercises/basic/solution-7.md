# Rozwiązanie 7

## Treść zadania

Napisz funkcję `Fibonacci` zgodną z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $n$ - liczba naturalna

#### Wynik

* Liczba Fibonacciego o indeksie $n$.

## Rozwiązanie

```vb
Function Fibonacci(n As Integer) As Long
    Dim a As Long
    Dim b As Long
    Dim temp As Long
    
    a = 0
    b = 1

    For i = 1 To n
        temp = a + b
        a = b
        b = temp
    Next i
    
    Fibonacci = a
End Function
```

## Opis rozwiązania

### 1. Definicja funkcji

```vb
Function Fibonacci(n As Integer) As Long
```

- `Function Fibonacci` rozpoczyna definicję funkcji o nazwie `Fibonacci`.
- `n As Integer` oznacza, że funkcja przyjmuje jeden argument (wejście) o nazwie `n`, który jest typu `Integer`.
- `As Long` na końcu mówi, że funkcja zwraca wartość typu `Long` (używany do przechowywania dużych liczb całkowitych).

### 2. Deklarowanie i inicjalizacja zmiennych

```vb
Dim a As Long
Dim b As Long
Dim temp As Long

a = 0
b = 1
```

- `Dim a As Long`, `Dim b As Long` i `Dim temp As Long` deklarują trzy zmienne typu `Long`.
- `a` i `b` są inicjalizowane wartościami początkowymi ciągu Fibonacciego: 0 i 1.

### 3. Pętla obliczeniowa

```vb
For i = 1 To n
```

- `For i = 1 To n` rozpoczyna pętlę, która będzie wykonywana `n` razy.

### 4. Obliczanie kolejnego wyrazu ciągu

```vb
    temp = a + b
    a = b
    b = temp
```

- `temp = a + b` oblicza kolejny wyraz ciągu, dodając dwie ostatnie liczby.
- `a = b` przypisuje wartość `b` do `a`. Teraz `a` jest drugim z ostatnich dwóch wyrazów ciągu.
- `b = temp` przypisuje obliczoną sumę do `b`. Teraz `b` jest najnowszym wyrazem ciągu.

### 5. Koniec pętli

```vb
Next i
```

- `Next i` kończy bieżący cykl pętli i przechodzi do następnego, zwiększając `i`.

### 6. Zwracanie wyniku

```vb
Fibonacci = a
```

- `Fibonacci = a` przypisuje ostateczną wartość zmiennej `a` do samej funkcji `Fibonacci`, co oznacza, że funkcja zwróci tę wartość jako swój wynik. `a` reprezentuje n-ty wyraz ciągu Fibonacciego.

### 7. Koniec funkcji

```vb
End Function
```

- `End Function` oznacza koniec definicji funkcji.
