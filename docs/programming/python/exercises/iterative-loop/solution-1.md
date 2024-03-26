# Rozwiązanie 1

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $n$ - liczba naturalna

#### Wynik

* $n!$ 

## Rozwiązanie

```python
n = int(input("Podaj liczbę naturalną: "))

silnia = 1

for i in range(2, n + 1):
    silnia *= i

print(f"{n}! = {silnia}")
```
