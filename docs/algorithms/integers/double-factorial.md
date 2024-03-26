# Podwójna silnia

Podwójna silnia (ang. *double factorial*) to operacja na liczbach naturalnych, która jest rozszerzeniem standardowego pojęcia silni.

## Definicja

Dla liczby naturalnej $n$, podwójna silnia $n!!$ jest iloczynem wszystkich liczb z zakresu od $1$ do $n$ włącznie, które mają tę samą parzystość co $n$. Czyli, dla liczby parzystej $n$, $n!!$ to iloczyn wszystkich liczb parzystych od $2$ do $n$, a dla liczby nieparzystej $n$, $n!!$ to iloczyn wszystkich liczb nieparzystych od $1$ do $n$.

Zatem:

- dla $n = 0$ lub $n = 1$, $n!! = 1$
- dla $n$ parzystego, $n!! = 2 * 4 * 6 * ... * n$
- dla $n$ nieparzystego, $n!! = 1 * 3 * 5 * ... * n$

Na przykład:

- $8!! = 2 * 4 * 6 * 8 = 384$
- $7!! = 1 * 3 * 5 * 7 = 105$

## Zastosowanie

Podwójna silnia pojawia się w wielu wzorach w matematyce i fizyce, w szczególności w statystyce, teorii szeregów, analizie kombinatorycznej i teorii grafów.

Warto zauważyć, że podwójna silnia rośnie bardzo szybko, podobnie jak standardowa silnia.

## Implementacja

### Python


[double-factorial.md](../../programming/python/algorithms/integers/double-factorial.md)
