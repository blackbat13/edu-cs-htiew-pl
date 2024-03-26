# Rozwiązanie 7

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $n$ - liczba naturalna
* $tab[n]$ - tablica liczb całkowitych

#### Wynik

* Komunikat "niemalejaco" jeżeli elementy tablicy posortowane są niemalejąco
* Komunikat "nierosnaco" jeżeli elementy tablicy posortowane są nierosnąco
* Komunikat "nieposortowane" jeżeli elementy tablicy nie są posortowane

## Rozwiązanie

```python
n = int(input("Podaj liczbę wartości: "))
tab = [int(input(f"Podaj liczbę nr {i + 1}: ")) for i in range(n)]

niemalejaco = True
nierosnaco = True

for i in range(1, n):
  if tab[i] > tab[i - 1]:
    nierosnaco = False

  if tab[i] < tab[i - 1]:
    niemalejaco = False

if nierosnaco:
  print("nierosnąco")
elif niemalejaco:
  print("niemalejąco")
else:
  print("nieposortowane")
```