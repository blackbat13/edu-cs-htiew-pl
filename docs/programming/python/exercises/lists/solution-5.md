# Rozwiązanie 5

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $n$ - liczba naturalna, $n>2$

#### Wynik

* $fib[n]$ - lista zawierająca $n$ kolejnych liczb Fibonacciego

## Rozwiązanie

```python
n = int(input("Podaj liczbę wartości: "))

fib = [1, 1]

for i in range(2, n):
    fib.append(fib[i - 1] + fib[i - 2])

print(f"Kolejne {n} liczb Fibonacciego: {fib}")
```