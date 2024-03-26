# Rozwiązanie 6

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Wykorzystaj funkcję **min**.

### Specyfikacja

#### Dane

* $a, b$ - dwie liczby całkowite

#### Wynik

* Mniejsza z liczb $a$ i $b$, lub dowolna gdy są sobie równe

## Rozwiązanie

```python
a = int(input("Podaj pierwszą liczbę: "))
b = int(input("Podaj drugą liczbę: "))

wynik = min(a, b)

print(f"Minimum z {a} i {b} wynosi {wynik}")
```
