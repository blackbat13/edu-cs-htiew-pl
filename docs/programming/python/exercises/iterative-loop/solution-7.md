# Rozwiązanie 7

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $n$ - liczba naturalna

#### Wynik

* Wszystkie pary liczb naturalnych, których suma wynosi $n$

## Rozwiązanie

```python
n = int(input("Podaj liczbę naturalną: "))

silnia = 1

for i in range((n // 2) + 1):
    print(f"({i}, {n - 1})")
```