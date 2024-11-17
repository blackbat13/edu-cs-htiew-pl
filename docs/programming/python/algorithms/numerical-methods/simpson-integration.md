# Metoda Simpsona

## [:link: Opis problemu](../../../../algorithms/numerical-methods/simpson-integration.md)

## Metoda prostokątów

```python linenums="1"
def f(x: float) -> float:
    return x * x + 2 * x

def simpson_method(a: float, b: float, n: int) -> float:
    h = (b - a) / n
    sum = f(a) + f(b)

    for i in range(1, n + 1, 2):
        sum += 4 * f(a + i * h)

    for i in range(2, n, 2): 
        sum += 2 * f(a + i * h)

    return (h / 3) * sum


a = 1.0
b = 5.0
n = 100
area = simpson_method(a, b, n)
print(area)
```

### Opis implementacji

Funkcja `f` (**linia 1**) przyjmuje jeden parametr rzeczywisty i jako wynik zwraca liczbę rzeczywistą. Funkcja ta symuluje funkcję matematyczną, której pole pod wykresem chcemy policzyć. 

Funkcja `simpson_method` (**linia 5**) realizuje algorytm całkowania numerycznego metodą prostokątów i przyjmuje trzy parametry: początek przedziału (`a`), koniec przedziału (`b`) oraz liczbę podziałów (`n`). Funkcja jako wynik zwraca liczbę rzeczywistą reprezentującą przybliżenie pola pod wykresem funkcji $f(x)=x^2+2x$ na przedziale $[a, b]$.

W części głównej programu przygotowujemy dane do naszego algorytmu: początek przedziału (**linia 18**), koniec przedziału (**linia 19**) oraz liczbę podziałów (**linia 20**). Następnie wywołujemy funkcję `simpson_method` z przygotowanymi danymi, a jej wynik zapisujemy w zmiennej `area` (**linia 21**). Na koniec wypisujemy wynik na ekranie (**linia 22**).
