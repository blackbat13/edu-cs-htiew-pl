# Rozwiązanie 5

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $n$ - liczba naturalna

#### Wynik

* Zapis binarny liczby $n$

## Rozwiązanie

```python
n = int(input("Podaj liczbę naturalną: "))

binarna = ""

while n > 0:
    cyfra = n % 2
    
    binarna = str(cyfra) + binarna

    n = n // 2

print(f"Wartość binarna podanej liczby: {binarna}")
```
