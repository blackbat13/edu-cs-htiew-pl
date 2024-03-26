# # Zaprzeczenie silni

Subfactorial ($!n$, *derangement* lub *zaprzeczenie silni*) to operacja na liczbach naturalnych. Określa liczbę permutacji zbioru $n$-elementowego, w których żaden element nie znajduje się na swoim początkowym miejscu. Takie permutacje nazywane są permutacjami bez punktów stałych lub permutacjami zupełnymi.

Subfactorial dla danej liczby $n$ można obliczyć za pomocą poniższego wzoru:

$!n = n! * (1 - 1/1! + 1/2! - 1/3! + ... + (-1)^n/n!)$

gdzie $n!$ oznacza silnię liczby $n$.

Alternatywnie, subfactorial można obliczyć rekurencyjnie za pomocą poniższego wzoru:

$
!n =  \begin{cases} 
      1 & n = 0 \\
      0 & n = 1 \\
      (n - 1) * (!(n - 1) + !(n - 2)) & n > 1\\
   \end{cases}
$

## Przykład

$!3 = 2$, ponieważ są dwie permutacje zbioru $\{1, 2, 3\}$, w których żaden element nie znajduje się na swoim początkowym miejscu: $(2, 3, 1)$ i $(3, 1, 2)$.

## Implementacja

### Python


[subfactorial.md](../../programming/python/algorithms/integers/subfactorial.md)
