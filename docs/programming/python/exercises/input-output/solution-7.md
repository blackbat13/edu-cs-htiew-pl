# Rozwiązanie 7

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Wykorzystaj funkcję **max**.

### Specyfikacja

#### Dane

* $a, b, c$ - trzy liczby całkowite

#### Wynik

* Największa z liczb $a$, $b$ i $c$, lub dowolna gdy są sobie równe

## Rozwiązanie

```python
a = int(input("Podaj pierwszą liczbę: "))
b = int(input("Podaj drugą liczbę: "))
c = int(input("Podaj trzecią liczbę: "))

wynik = max(a, b, c)

print(f"Maksimum z {a}, {b} i {c} wynosi {wynik}")
```
