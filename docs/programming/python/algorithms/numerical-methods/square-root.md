# Pierwiastek kwadratowy

## [Opis problemu](../../../../algorithms/numerical-methods/square-root.md)

## Metoda Herona

```python linenums="1"
def sqrt(n: float, p: float) -> float:
    x1 = n / 2
    x2 = (x1 + (n / x1)) / 2
    while abs(x2 - x1) > p:
        x1 = (x2 + n / x2) / 2
        x1, x2 = x2, x1

    return x2

n = 9.0
p = 0.00000001

result = sqrt(n, p)

print(f"sqrt({n}) ~= {result}")
```

### Opis implementacji

Na początku definiujemy funkcję `sqrt` (**linia 1**), która przyjmuje dwa parametry: liczbę, której pierwiastek chcemy policzyć ($n$) oraz dokładność obliczeń ($p$). Wewnątrz funkcji zaczynamy od obliczenia pierwszego przybliżenia wartości pierwiastka kwadratowego z $n$, które zapisujemy w zmiennej `x1` (**linia 2**). Następnie ze wzoru obliczamy kolejne przybliżenie i zapisujemy je w zmiennej `x2` (**linia 3**). Teraz przechodzimy do pętli warunkowej (**linia 4**), w której obliczenia przeprowadzamy tak długo, jak wartość bezwzględna różnicy pomiędzy kolejnymi przybliżeniami (`abs(x2 - x1)`) jest większa od podanej dokładności. Wewnątrz pętli obliczamy kolejne przybliżenie, które zapisujemy w zmiennej `x1` (**linia 5**). Następnie zamieniamy wartościami zmienne `x1` oraz `x2` (**linia 6**), tak aby w zmiennej `x1` było poprzednie przybliżenie, a w zmiennej `x2` było kolejne przybliżenie. Po zakończeniu obliczeń i wyjściu z pętli, zwracamy wynik zapisany w zmiennej `x2` (**linia 8**).

W części głównej definiujemy dane wejściowe do naszego problemu (**linie 11 oraz 12**), wywołujemy funkcję `sqrt` z przygotowanymi danymi (**linia 14**) i jej wynik zapisujemy w zmiennej `result`, a na koniec wypisujemy wynik na ekran (**linia 16**).

## Metoda Herona z wykresem

```python linenums="1"
import matplotlib.pyplot as plt

def sqrt(n: float, p: float) -> float:
    x1 = n / 2
    x2 = (x1 + (n / x1)) / 2
    plot_values = [x1, x2]
    while abs(x2 - x1) > p:
        x1 = (x2 + n / x2) / 2
        x1, x2 = x2, x1
        plot_values.append(x2)

    plt.plot(plot_values, label=f"heron({n},{p})")
    plt.legend()

    return x2

n = 9.0
p = 0.00000001

result = sqrt(n, p)

print(f"sqrt({n}) ~= {result}")

plt.show()
```

### Opis implementacji

Na początku importujemy moduł *pyplot* z biblioteki *matplotlib*, który posłuży nam do narysowania wykresu. Zaimportowanemu modułowi nadajemy skrótową nazwę *plt* (**linia 1**). Następnie definiujemy funkcję `sqrt` (**linia 4**), która przyjmuje dwa parametry: liczbę, której pierwiastek chcemy policzyć ($n$) oraz dokładność obliczeń ($p$). Wewnątrz funkcji zaczynamy od obliczenia pierwszego przybliżenia wartości pierwiastka kwadratowego z $n$, które zapisujemy w zmiennej `x1` (**linia 5**). Następnie ze wzoru obliczamy kolejne przybliżenie i zapisujemy je w zmiennej `x2` (**linia 6**). Obie wartości zapisujemy w nowo utworzonej liście `plot_values` (**linia 7**), którą użyjemy do utworzenia wykresu. Teraz przechodzimy do pętli warunkowej (**linia 8**), w której obliczenia przeprowadzamy tak długo, jak wartość bezwzględna różnicy pomiędzy kolejnymi przybliżeniami (`abs(x2 - x1)`) jest większa od podanej dokładności. Wewnątrz pętli obliczamy kolejne przybliżenie, które zapisujemy w zmiennej `x1` (**linia 9**). Następnie zamieniamy wartościami zmienne `x1` oraz `x2` (**linia 10**), tak aby w zmiennej `x1` było poprzednie przybliżenie, a w zmiennej `x2` było kolejne przybliżenie. Nowy wynik przybliżenia dopisujemy do listy `plot_values` (**linia 11**). Po zakończeniu obliczeń i wyjściu z pętli, rysujemy wykres za pomocą funkcji `plot` z biblioteki *matplotlib* (**linia 13**), dodajemy legendę do wykresu (**linia 14**), a na końcu zwracamy wynik zapisany w zmiennej `x2` (**linia 16**).

W części głównej definiujemy dane wejściowe do naszego problemu (**linie 19 oraz 20**), wywołujemy funkcję `sqrt` z przygotowanymi danymi (**linia 22**) i jej wynik zapisujemy w zmiennej `result`, a następnie wypisujemy wynik na ekran (**linia 24**). Na koniec wyświetlamy wykres za pomocą funkcji `show` (**linia 26**).