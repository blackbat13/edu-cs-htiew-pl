# Primorial

Primorial (symbolizowany przez $n\#$) jest to produkt pierwszych $n$ liczb pierwszych. Na przykład, $5\#$ to wynik mnożenia pierwszych pięciu liczb pierwszych: $2 * 3 * 5 * 7 * 11 = 2310$.

W sposób bardziej formalny, primorial liczby $n$, oznaczany jako $n\#$, jest zdefiniowany jako iloczyn pierwszych $n$ liczb pierwszych. 

Innymi słowy, jeżeli $p_i$ oznacza $i$-tą liczbę pierwszą (tak, że $p_1 = 2$, $p_2 = 3$, $p_3 = 5$, itd.), to:

$n\# = p_1 * p_2 * ... * p_n$.

W szczególności, dla $n = 0$, definujemy $0\# = 1$, zgodnie z konwencją, że iloczyn zbioru pustego to $1$.

Primorial nie powinien być mylony z funkcją silni, $n!$, która jest iloczynem wszystkich liczb naturalnych do $n$. Obie funkcje rosną bardzo szybko, ale silnia rośnie znacznie szybciej.

## Implementacja

### [Python](../../programming/python/algorithms/integers/primorial.md)
