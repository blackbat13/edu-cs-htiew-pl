# Rozwiązanie 4

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $n$ - liczba naturalna
* $k$ - liczba naturalna z zakresu $[0,9]$

#### Wynik

* Liczba powstała poprzez zastąpienie każdej cyfry liczby $n$ przez wartość bezwzględną różnicy liczby $k$ i danej cyfry

## Rozwiązanie

```python
n = int(input("Podaj pierwszą liczbę: "))
k = int(input("Podaj drugą liczbę: "))

nowa = 0
pot = 0

while n > 0:
    cyfra = n % 10
    cyfra = abs(k - cyfra)

    nowa += cyfra * pot
    pot *= 10

    n = n // 10

print(f"Nowa liczba: {nowa}")
```
