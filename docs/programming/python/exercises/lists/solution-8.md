# Rozwiązanie 8

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$p, k$$ - dwie liczby naturalna, $$p <= k$$

#### Wynik

* $$n$$-elementowa lista wypełniona losowymi wartościami z przedziału $$[p, k]$$

## Rozwiązanie

```python
import random


n = int(input("Podaj liczbę wartości: "))
p = int(input("Podaj początek zakresu: "))
k = int(input("Podaj koniec zakresu: "))

tab = [random.randint(p, k) for _ in range(n)]

print(tab)
```