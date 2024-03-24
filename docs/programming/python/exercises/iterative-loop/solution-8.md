# Rozwiązanie 8

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* Wszystkie trójki liczb naturalnych, których suma wynosi $$n$$

## Rozwiązanie

```python
n = int(input("Podaj liczbę naturalną: "))

silnia = 1

for i in range((n // 3) + 1):
    for j in range(i, ((n - i) // 2) + 1):
        print(f"({i}, {j}, {n - i - j})")
```
