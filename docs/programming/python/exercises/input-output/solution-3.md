# Rozwiązanie 3

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $a, b$ - dwie liczby całkowite, różne od zera.

#### Wynik

* Iloraz (wynik dzielenia), iloczyn (wynik mnożenia), suma oraz różnica liczb $a$ i $b$.

## Rozwiązanie

```python
a = int(input("Podaj pierwszą liczbę: "))
b = int(input("Podaj drugą liczbę: "))

iloraz = a / b
iloczyn = a * b
suma = a + b
roznica = a - b

print("Iloraz:", iloraz)
print("Iloczyn:", iloczyn)
print("Suma:", suma)
print("Różnica:", roznica)
```
