# Metoda Simpsona

Metoda Simpsona jest bardziej zaawansowaną techniką całkowania numerycznego, która pozwala na uzyskanie dokładniejszych wyników niż metody prostokątów i trapezów. Polega ona na przybliżeniu funkcji za pomocą parabol, a następnie obliczeniu pola pod tymi parabolami.

## Wzór

Wzór metody Simpsona dla przedziału $[a, b]$ z $n$ podprzedziałami (gdzie $n$ jest parzyste) jest następujący:

$$
\int_{a}^{b} f(x) \, dx \approx \frac{h}{3} \left[ f(a) + 4 \sum_{k=1}^{n/2} f(a + (2k-1)h) + 2 \sum_{k=1}^{n/2-1} f(a + 2kh) + f(b) \right]
$$

gdzie:

- $h = (b - a) / n$ jest szerokością podprzedziału,
- $\sum_{k=1}^{n/2}$ oznacza sumowanie dla $k$ od $1$ do $n/2$.

### Podział przedziału

1. Dzielimy przedział $[a, b]$ na $n$ równych podprzedziałów, gdzie $n$ jest parzyste.
2. Każdy podprzedział ma szerokość $h$.

### Obliczanie całek na kolejnych fragmentach

1. Obliczamy wartości funkcji $f(x)$ w punktach $a, a + h, a + 2h, \dots, b$.
2. Sumujemy wartości funkcji w punktach końcowych przedziału ($a$ i $b$), punktach środkowych ($a + (2k-1)h$) z wagą $4$ oraz punktach wewnętrznycha ($a+2kh$) z wagą $2$.

### Łączenie całego wyniku

Mnożymy sumę przez $h/3$, aby uzyskać przybliżoną wartość całki oznaczonej.

## Błąd dokładności

Błąd przybliżenia wartości całki metodą Simpsona jest rzędu $O(h^4)$. W praktyce oznacza to, że metoda Simpsona jest bardzo dokładna dla funkcji, które są dobrze przybliżane przez parabolę na małych przedziałach. Jednakże, dla funkcji o dużych zmianach krzywizny, błąd może być większy.

## Specyfikacja

### Dane

* $f(x)$ — funkcja, której wykres nas interesuje
* $a$ — liczba rzeczywista, początek przedziału
* $b$ — liczba rzeczywista, koniec przedziału
* $n$ — liczba podziałów (im większa, tym większa dokładność)

### Wynik

* $pole$ — przybliżona wartość pola pod wykresem funkcji $f(x)$ w przedziale $[a,b]$

## Rozwiązanie

### Pseudokod

```
funkcja MetodaSimpsona(f, a, b, n):
    1. jeżeli n jest nieparzyste, zwiększ n o 1
    2. szer := (b - a) / n
    3. pole := f(a) + f(b)
    
    4. Dla i od 1 do n-1, wykonuj:
        5. x := a + i * szer
        6. jeżeli i jest parzyste, pole := pole + 2 * f(x)
        7. jeżeli i jest nieparzyste, pole := pole + 4 * f(x)
        
    8. pole := pole * szer / 3
    9. Zwróć pole
```

### Schemat blokowy

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
    START(["MetodaSimpsona(f, a, b, n)"]) --> K1["jeżeli n jest nieparzyste, zwiększ n o 1"]
    K1 --> K2["szer := (b - a) / n
    pole := f(a) + f(b)"]
    K2 --> K4["Dla i od 1 do n-1, wykonuj"]
    K4 --> K5["x := a + i * szer"]
    K5 --> K6{"i jest parzyste?"}
    K6 -- TAK --> K7["pole := pole + 2 * f(x)"]
    K6 -- NIE --> K8["pole := pole + 4 * f(x)"]
    K7 --> K4
    K8 --> K4
    K4 -->|koniec| K9["pole := pole * szer / 3"]
    K9 --> K10[/Zwróć pole/]
    K10 --> STOP([STOP])
```

## Implementacja

### [:simple-cplusplus: C++](../../programming/c++/algorithms/numerical-methods/simpson-integration.md){ .md-button }

### [:simple-python: Python](../../programming/python/algorithms/numerical-methods/simpson-integration.md){ .md-button }
