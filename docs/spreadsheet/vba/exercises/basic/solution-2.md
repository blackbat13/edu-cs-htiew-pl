# Rozwiązanie 2

## Treść zadania

Napisz funkcję `KonwTemp` zgodną z poniższą specyfikacją.

Skorzystaj z następujących wzorów:

- $$C = K - 273.15$$
- $$C = \frac{5}{9} * (F - 32)$$
- $$F = \frac{9}{5} * C + 32$$
- $$F = \frac{9}{5} * K - 459.67$$
- $$K = C + 273.15$$
- $$K = \frac{5}{9} * (F + 459.67)$$

gdzie:

* $$C$$ - temperatura podana w stopniach Celsjusza
* $$F$$ - temperatura podana w stopniach Fahrenheita
* $$K$$ - temperatura podana w stopniach Kelvina

### Specyfikacja

#### Dane

* $$temp$$ - liczba rzeczywista, temperatura do konwersji
* $$jednZ$$ - jeden znak, wielka litera oznaczająca jednostkę temperatury z której należy dokonać konwersji
* $$jednDo$$ - jeden znak, wielka litera oznaczająca jednostkę temperatury do której należy dokonać konwersji

#### Wynik

* Podana temperatura przekonwertowana z jednostki $$jednZ$$ do jednostki $$jednDo$$.

## Rozwiązanie

```vb
Function KonwTemp(temp As Double, jednZ As String, jednDo As String) As Double
    If jednZ = "C" Then
        If jednDo = "F" Then
            KonwTemp = ((temp * 9) / 5) + 32
        ElseIf jednDo = "K" Then
            KonwTemp = temp + 273.15
        End If
    ElseIf jednZ = "F" Then
        If jednDo = "C" Then
            KonwTemp = ((temp - 32) * 5) / 9
        ElseIf jednDo = "K" Then
            KonwTemp = ((temp + 459.67) * 5) / 9
        End If
    ElseIf jednZ = "K" Then
        If jednDo = "C" Then
            KonwTemp = temp - 273.15
        ElseIf jednDo = "F" Then
            KonwTemp = ((temp * 9) / 5) - 459.67
        End If
    End If
End Function
```

## Opis rozwiązania

### 1. Definicja funkcji

```vb
Function KonwTemp(temp As Double, jednZ As String, jednDo As String) As Double
```

- Funkcja `KonwTemp` przyjmuje trzy argumenty: `temp` (temperatura do konwersji), `jednZ` (jednostka wyjściowa) i `jednDo` (jednostka docelowa). Zwraca liczbę zmiennoprzecinkową (`Double`).

### 2. Pierwszy warunek - konwersja z Celsjusza

```vb
If jednZ = "C" Then
```

- Sprawdza, czy jednostka wyjściowa to Celsjusz.

    - **Konwersja na Fahrenheita:**
    
    ```vb
    If jednDo = "F" Then
        KonwTemp = ((temp * 9) / 5) + 32
    ```

    - Jeśli jednostka docelowa to Fahrenheit, przelicza temperaturę z Celsjusza na Fahrenheita.

    - **Konwersja na Kelvina:**
    
    ```vb
    ElseIf jednDo = "K" Then
        KonwTemp = temp + 273.15
    ```

    - Jeśli jednostka docelowa to Kelvin, przelicza temperaturę z Celsjusza na Kelvina.

### 3. Drugi warunek - konwersja z Fahrenheita

```vb
ElseIf jednZ = "F" Then
```

- Sprawdza, czy jednostka wyjściowa to Fahrenheit.

    - **Konwersja na Celsjusza:**
    
    ```vb
    If jednDo = "C" Then
        KonwTemp = ((temp - 32) * 5) / 9
    ```

    - Jeśli jednostka docelowa to Celsjusz, przelicza temperaturę z Fahrenheita na Celsjusza.

    - **Konwersja na Kelvina:**
    
    ```vb
    ElseIf jednDo = "K" Then
        KonwTemp = ((temp + 459.67) * 5) / 9
    ```

    - Jeśli jednostka docelowa to Kelvin, przelicza temperaturę z Fahrenheita na Kelvina.

### 4. Trzeci warunek - konwersja z Kelvina

```vb
ElseIf jednZ = "K" Then
```

- Sprawdza, czy jednostka wyjściowa to Kelvin.

    - **Konwersja na Celsjusza:**

    ```vb
    If jednDo = "C" Then
        KonwTemp = temp - 273.15
    ```

    - Jeśli jednostka docelowa to Celsjusz, przelicza temperaturę z Kelvina na Celsjusza.

    - **Konwersja na Fahrenheita:**

    ```vb
    ElseIf jednDo = "F" Then
        KonwTemp = ((temp * 9) / 5) - 459.67
    ```

    - Jeśli jednostka docelowa to Fahrenheit, przelicza temperaturę z Kelvina na Fahrenheita.

### 5. Koniec funkcji

```vb
End If
End Function
```

- `End If` i `End Function` oznaczają koniec struktury warunkowej i samej funkcji.
