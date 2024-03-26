# Rozwiązanie 5

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $n, k$ - liczby naturalne, większe od zera
* $n$ liczb naturalnych

#### Wynik

* Ilość liczb podzielnych przez $k$ z podanych $n$ liczb

## Rozwiązanie

```python
n = int(input("Podaj liczbę wartości: "))
k = int(input("Podaj dzielnik: "))

podzielne = 0

for i in range(n):
    liczba = int(input(f"Podaj liczbę nr {i + 1}: "))
    if liczba % k == 0:
        podzielne += 1

print(f"Podzielne: {podzielne}")
```