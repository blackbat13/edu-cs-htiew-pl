# Rozwiązanie 6

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Zadbaj o czytelność programu.

### Specyfikacja

#### Dane

* $a, b$ - dwie liczby całkowite
* $op$ - znak jednej z dozwolonych operacji: $+,-,*,/$ 

#### Wynik

* Wynik działania$a\ op\ b$ (np. $a+b$), lub komunikat, że nie można wykonać dzielenia.

## Rozwiązanie

```python
a = int(input("Podaj pierwszą liczbę: "))
b = int(input("Podaj drugą liczbę: "))

op = input("Podaj znak operacji (+, -, *, /): ")

if op == "+":
    print(f"{a} + {b} = {a + b}")
elif op == "-":
    print(f"{a} - {b} = {a - b}")
elif op == "*":
    print(f"{a} * {b} = {a * b}")
else:
    print(f"{a} / {b} = {a / b}")
```

## Rozwiązanie alternatywne

```python
a = int(input("Podaj pierwszą liczbę: "))
b = int(input("Podaj drugą liczbę: "))

op = input("Podaj znak operacji (+, -, *, /): ")

wynik = eval(f"{a}{op}{b}")

print(f"{a} {op} {b} = {wynik}")
```