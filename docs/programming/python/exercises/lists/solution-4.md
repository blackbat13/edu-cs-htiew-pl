# Rozwiązanie 4

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$t1[n],\ t2[n]$$ - dwie listy liczb całkowitych

#### Wynik

* Tablica powstała poprzez dodanie do siebie wartości z list $$t1$$ i $$t2$$ 

## Rozwiązanie

```python
n = int(input("Podaj liczbę wartości: "))

t1 = [int(input(f"Podaj liczbę nr {i + 1} z pierwszej tablicy: ")) for i in range(n)]
t2 = [int(input(f"Podaj liczbę nr {i + 1} z drugiej tablicy: ")) for i in range(n)]
t3 = [el1 + el2 for el1, el2 in zip(t1, t2)]

print(f"Wynikowa tablica: {t3}")
```