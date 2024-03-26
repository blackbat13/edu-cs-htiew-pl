# Rozwiązanie 4

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $a, b$ - dwie liczby naturalne, większe od zera

#### Wynik

* Wynik dzielenia całkowitego oraz reszta z dzielenia liczb $a$ i $b$ 

## Rozwiązanie

```python
a = int(input("Podaj pierwszą liczbę: "))
b = int(input("Podaj drugą liczbę: "))

div = a // b
mod = a % b

print(f"{a} / {b} = {div}, r. {mod}")
```
