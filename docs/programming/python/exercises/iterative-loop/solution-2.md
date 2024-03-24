# Rozwiązanie 2

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Nie korzystaj z operatora `**`.

### Specyfikacja

#### Dane

* $$a, n$$ - dwie liczby naturalne

#### Wynik

* $$a^n$$ 

## Rozwiązanie

```python
a = int(input("Podaj pierwszą liczbę: "))
n = int(input("Podaj drugą liczbę: "))

wynik = 1

for i in range(n):
    wynik *= a

print(f"{a} do {n} = {wynik}")
```
