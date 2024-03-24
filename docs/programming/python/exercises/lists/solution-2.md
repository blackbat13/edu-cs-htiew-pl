# Rozwiązanie 2

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$a_1,a_2,\dots,a_n$$ - $$n$$ liczb całkowitych
* $$k$$ - liczba naturalna, $$1<=k<=n$$

#### Wynik

* $$a_k$$ - $$k$$-ta podana liczba

## Rozwiązanie

```python
n = int(input("Podaj liczbę wartości: "))
tab = [int(input(f"Podaj liczbę nr {i + 1}: ")) for i in range(n)]
k = int(input("Podaj numer elementu: "))

print(f"Element numer {k}: {tab[k - 1]}")
```

### Opis rozwiązania

Na początku wczytujemy od użytkownika liczbę elementów i zapisujemy ją w zmiennej $$n$$ (**linia 1**).

Następnie tworzymy listę wczytując do niej wartości (**linia 2**).

Następnie wczytujemy od użytkownika numer elementu, który należy wypisać (**linia 3**).

Teraz pozostało wypisać właściwy element. Ponieważ tablica jest numerowana (indeksowana) od zera, należy wypisać element pod indeksem $$k - 1$$ (**linia 5**).