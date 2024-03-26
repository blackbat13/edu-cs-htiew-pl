# Stos

Stos (ang. *Stack*) jest podstawową strukturą danych, która organizuje elementy w sposób liniowy, przypominający stos lub kolumnę. Wyróżnia go szczególne zachowanie znane jako zasada LIFO (ang. Last In, First Out), co oznacza, że ostatni element dodany do stosu będzie pierwszym elementem usuniętym ze stosu.

Stos obsługuje dwie główne operacje:

- **Push**: dodaje element na szczyt stosu.
- **Pop**: usuwa element ze szczytu stosu.

Niektóre implementacje stosu mogą również obsługiwać dodatkowe operacje, takie jak:

- **Peek / Top**: zwraca element na szczycie stosu bez usuwania go.
- **IsEmpty**: sprawdza, czy stos jest pusty.
- **Size**: zwraca liczbę elementów na stosie.

## Zastosowania

Stosy są wykorzystywane w wielu różnych kontekstach w informatyce, w tym:

- **Wywołanie funkcji**: kiedy funkcja $A$ wywołuje inną funkcję $B$, aktualny stan funkcji $A$ jest umieszczany na stosie, a funkcja $B$ jest wykonywana. Gdy funkcja $B$ zakończy działanie, stan funkcji $A$ jest zdejmowany ze stosu, co umożliwia powrót do miejsca, w którym została przerwana.
- **Odwracanie sekwencji**: elementy dodane do stosu będą zdejmowane w odwrotnej kolejności, dzięki czemu stosy są użyteczne do odwracania sekwencji.
- **Sprawdzanie zrównoważenia nawiasów**: stosy mogą być używane do sprawdzania zrównoważenia nawiasów w wyrażeniach matematycznych lub kodzie programu.
- **Algorytmy wykorzystujące backtracking**: takie jak algorytmy przeszukiwania przestrzeni stanów (np. labiryntu), algorytmy przeszukiwania grafu (DFS), algorytmy rozwiązywania problemów związanych z permutacjami i kombinacjami.

Stosy są więc fundamentalnym narzędziem w informatyce, mającym szerokie zastosowanie zarówno w teorii jak i praktyce.

## Implementacja

Stosy mogą być zaimplementowane za pomocą różnych struktur danych, takich jak tablice lub listy połączone. Wybór konkretnej struktury danych do implementacji stosu zależy od konkretnych wymagań, takich jak efektywność operacji, użycie pamięci, czy łatwość implementacji.

Poniżej znajdziesz przykładowe implementacje stosu w wybranych językach programowania.

### C++


[stack.md](../../programming/c++/algorithms/structures/stack.md)


### Python


[stack.md](../../programming/python/algorithms/structures/stack.md)


## Implementacje — pozostałe

### C


[stack.md](../../programming/c/algorithms/structures/stack.md)

