# Rozwiązanie 6

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $n$ - liczba naturalna

#### Wynik

* Tabliczka mnożenia z zakresu $[1,n]$

## Rozwiązanie

```python
n = int(input("Podaj liczbę naturalną: "))

for i in range(1, n + 1):
    for j in range(1, n + 1):
        print(i * j, end=" ")
    
    print()
```