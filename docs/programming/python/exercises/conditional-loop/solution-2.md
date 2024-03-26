# Rozwiązanie 2

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $n$ - liczba naturalna

#### Wynik

* Suma cyfr liczby $n$

## Rozwiązanie

```python
n = int(input("Podaj liczbę naturalną: "))

suma = 0

while n > 0:
    cyfra = n % 10
    suma += cyfra
    n = n // 10

print(f"Suma cyfr podanej liczby wynosi {suma}")
```
