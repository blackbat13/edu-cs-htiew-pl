# Rozwiązanie 5

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $a$ - liczba naturalna

#### Wynik

* Pierwiastek z $a$

## Rozwiązanie

```python
import math


a = int(input("Podaj liczbę naturalną: "))

pierwiastek = math.sqrt(a)

print(f"Pierwiastek z {a} = {pierwiastek}")
```
