# Rozwiązanie 3

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. Obliczanie dzielników powinno być zrealizowane za pomocą funkcji.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* Wszystkie dzielniki liczby $$n$$ 

## Rozwiązanie

```python
def dzielniki(n: int) -> []:
    wynik = []

    for i in range(1, n + 1):
        if n % i == 0:
            wynik.append(i)

    return wynik


n = int(input("Podaj liczbę naturalną: "))

wynik = dzielniki(n)

print(f"Dzielniki {n}: {wynik}")
```
