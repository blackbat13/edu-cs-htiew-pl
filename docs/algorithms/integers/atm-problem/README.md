# Problem bankomatu (wydawanie reszty)

## Opis problemu

Problem bankomatu, czy też problem wydawania reszty, to problem, w którym zadajemy sobie następujące pytanie: ile co najmniej monet i/lub banknotów potrzeba do wydania zadanej kwoty?

### Specyfikacja

#### Dane

* $$n$$ — liczba naturalna, ilość dostępnych nominałów
* $$nominały[1..n]$$ — tablica dostępnych nominałów (liczb całkowitych) o rozmiarze $$n$$
* $$kwota$$ — liczba naturalna, kwota do wydania

#### Wynik

* Minimalna liczba potrzebnych monet i/lub banknotów do wydania podanej kwoty przy użyciu dostępnych nominałów.

### Przykład 1

#### Dane

```
n := 4
nominały := [1, 2, 5, 10]
kwota := 28
```

#### Wynik

Minimalna liczba potrzebnych monet i/lub banknotów: $$5$$.

Wykorzystane monety/banknoty: $$1, 2, 5, 10, 10$$

### Przykład 2

#### Dane

```
n := 3
nominały := [1, 7, 10]
kwota := 14
```

#### Wynik

Minimalna liczba potrzebnych monet i/lub banknotów: $$2$$.

Wykorzystane monety/banknoty: $$7, 7$$