# Całkowanie numeryczne

## Opisy algorytmów


[numerical-integration.md](../../../../../algorithms/numerical-methods/numerical-integration.md)



[monte-carlo.md](../../../../../algorithms/numerical-methods/monte-carlo.md)


## Zadanie 1

Dana jest następująca funkcja:

$
f(x) = \sin{(\cos{(x)})}
$

Oszacuj wartość całki podanej funkcji na przedziale $[0, 3]$, tzn.:

$
\int_{0}^{3} \sin{(\cos{(x)})} \ dx
$

Możesz założyć, że:

$
\int_{0}^{3} \sin{(\cos{(x)})} \ dx \simeq 0.118889545631
$

Wykorzystaj metodę **prostokątów** w celu oszacowania wartości całki. Korzystając z arkusza kalkulacyjnego przygotuj symulację wyników algorytmu dla następującej liczby przedziałów:

- $10$
- $10^2$
- $10^3$
- $10^4$
- $10^5$
- $10^6$

Przedstaw na wykresie jak zmienia się dokładność oszacowania wartości całki w zależności od liczby wylosowanych punktów. Dokładność przedstaw jako *odłegłość* uzyskanego wyniku od oczekiwanej wartości całki podanej wcześniej, czyli jako wartość bezwzględną różnicy pomiędzy tymi wartościami.

## Zadanie 2

Wykorzystaj metodę **trapezów** w celu oszacowania wartości całki. Korzystając z arkusza kalkulacyjnego przygotuj symulację wyników algorytmu dla następującej liczby przedziałów:

- $10$
- $10^2$
- $10^3$
- $10^4$
- $10^5$
- $10^6$

Przedstaw na wykresie jak zmienia się dokładność oszacowania wartości całki w zależności od liczby wylosowanych punktów. Dokładność przedstaw jako *odłegłość* uzyskanego wyniku od oczekiwanej wartości całki podanej wcześniej, czyli jako wartość bezwzględną różnicy pomiędzy tymi wartościami.

## Zadanie 3

Wykorzystaj metodę **Monte Carlo** w celu oszacowania wartości całki. Korzystając z arkusza kalkulacyjnego przygotuj symulację wyników algorytmu dla następującej liczby wylosowanych punktów:

- $10$
- $10^2$
- $10^3$
- $10^4$
- $10^5$
- $10^6$

Przedstaw na wykresie jak zmienia się dokładność oszacowania wartości całki w zależności od liczby wylosowanych punktów. Dokładność przedstaw jako *odłegłość* uzyskanego wyniku od oczekiwanej wartości całki podanej wcześniej, czyli jako wartość bezwzględną różnicy pomiędzy tymi wartościami.

## Zadanie 4

Utwórz wykres przedstawiający porównanie dokładności wyników z zadań $1$, $2$ i $3$.
