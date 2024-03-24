# Rozwiązanie 1

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* Kolejne cyfry liczby $$n$$, wypisane od końca, tzn. zaczynając od cyfry jedności

## Rozwiązanie

```python
n = int(input("Podaj liczbę naturalną: "))

while n > 0:
    cyfra = n % 10
    print(cyfra)
    n = n // 10
```
