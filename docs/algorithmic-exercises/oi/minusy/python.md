# Python

!!! warning
	**Uwaga**
	
	Chociaż rozwiązanie jest stosunkowo proste, to Python jest niestety zbyt wolny do tego zadania, dlatego w niektórych testach zostanie przekroczony limit czasu.

## Implementacja

```python linenums="1"
plus = False
result = ""
n = int(input())

for _ in range(n - 1):
    sign = input()

    if sign == "-" and plus:
        result += ")"
        plus = False
    elif sign == "+" and not plus:
        result += "("
        plus = True

    result += "-"

if plus:
    result += ")"

print(result)
```


## Opis implementacji

Na początku tworzymy zmienną `plus` do zapamiętania, czy ostatni wczytany symbol był znakiem dodawania (**linia 1**). Definiujemy także zmienną `result` do przechowywania wyniku (**linia 2**). Następnie wczytujemy liczbę znaków do zmiennej `n` (**linia 3**). 

W kolejnym kroku przechodzimy pętlą przez $n-1$ znaków (**linia 5**). W pętli wczytujemy kolejny znak do zmiennej `sign` (**linia 6**). Następnie sprawdzamy, czy obecny znak to minus, a poprzedni był plusem (**linia 8**). Jeżeli tak, to dodajemy nawias zamykający do wyniku (**linia 9**) i zapamiętujemy, że ostatni znak nie był plusem (**linia 10**). W przeciwnym przypadku sprawdzamy, czy obecny znak to plus i poprzedni nie był plusem (**linia 11**). Jeżeli tak, to dodajemy otwierający nawias do wyniku (**linia 12**) i zapamiętujemy, że ostatni znak był plusem. (**linia 13**) Na koniec pętli dopisujemy znak odejmowania do wyniku (**linia 15**).

Po wyjściu z pętli sprawdzamy, czy ostatni znak był znakiem dodawania (**linia 17**). Jeżeli tak, to dopisujemy do wyniku nawias zamykający (**linia 18**). Na koniec programu wypisujemy wynik na ekranie (**linia 20**).