# Rozwiązanie 1

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Nie korzystaj z funkcji **abs**

### Specyfikacja

#### Dane

* $$a$$ - liczba całkowita

#### Wynik

* Wartość bezwzględna z $$a$$

## Rozwiązanie

```python
a = int(input("Podaj liczbę całkowitą: "))

if a < 0:
    print(f"|{a}| = {-a}")
else:
    print(f"|{a}| = {a}")
```
