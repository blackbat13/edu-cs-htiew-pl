# Rozwiązanie 6

## Treść zadania

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $n$ - liczba naturalna

#### Wynik

* $mno[n][n]$ - dwuwymiarowa lista reprezentująca tabliczkę mnożenia liczb z zakresu $[0,n-1]$, gdzie $mno[i][j]=i*j$

## Rozwiązanie

```python
from pprint import pprint


n = int(input("Podaj liczbę wartości: "))

mno = [[i * j for j in range(n)] for i in range(n)]

pprint(mno)
```