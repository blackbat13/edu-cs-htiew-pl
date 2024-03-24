# Rozwiązanie 4

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna, większa od $$0$$ 
* $$n$$liczb naturalnych

#### Wynik

* Największa z podanych $$n$$ liczb

## Rozwiązanie

```python
n = int(input("Podaj liczbę wartości: "))

maks = -1

for i in range(n):
    liczba = int(input(f"Podaj liczbę nr {i + 1}: "))
    if liczba > maks:
        maks = liczba

print(f"Maksimum z podanych liczb wynosi {maks}")
```

## Rozwiązanie alternatywne

```python
n = int(input("Podaj liczbę wartości: "))

maks = -1

for i in range(n):
    liczba = int(input(f"Podaj liczbę nr {i + 1}: "))
    maks = max(maks, liczba)

print(f"Maksimum z podanych liczb wynosi {maks}")
```