# Rozwiązania

## Zadanie 1

```
funkcja Maks(n, A):
    1. mx := A[1]
    2. Dla i := 2 do n, wykonuj:
        3. Jeżeli A[i] > mx, to:
            4. mx := A[i]
    5. Zwróć mx
```

## Zadanie 2

```
funkcja MinNat(n, A):
    1. nat[0..10^6+1] - tablica wypełniona zerami, indeksowana od 0
    2. Dla i := 1 do n, wykonuj:
        3. Jeżeli A[i] >= 0, to:
            4. nat[A[i]] := 1
    5. Dla i := 0 do 10^6+1, wykonuj:
        6. Jeżeli nat[i] = 0, to:
            7. Zwróć i
```

## Zadanie 3

```
Funkcja Srednia(n, A):
    1. suma := 0
    2. Dla i := 1 do n, wykonuj:
        3. suma := suma + A[i]
    4. Zwróć suma / n
```

## Zadanie 4

```
Funkcja CzyPierwsza(num):
    1. Jeżeli num < 2, to:
        2. Zwróć Fałsz
    3. i := 2
    4. Dopóki i * i <= num, wykonuj:
        5. Jeżeli num mod i = 0, to:
            6. Zwróć Fałsz
        7. i := i + 1
    8. Zwróć Prawda

Funkcja IlePierwszych(n, A):
    1. ile := 0
    2. Dla i := 1 do n, wykonuj:
        3. Jeżeli CzyPierwsza(A[i]), to:
            4. ile := ile + 1
    5. Zwróć ile
```

## Zadanie 5

```
Funkcja Sortuj(n, A):
    1. Dla i := 1 do n-1, wykonuj:
        2. Dla j := i+1 do n, wykonuj:
            3. Jeżeli A[j] < A[i], to:
                4. Zamień A[i] z A[j]
```
