# Gra planszowa

Bajtek stworzył nową grę planszową. Gra ta składa się z jednej planszy o $$n$$ polach, kości o $$n$$ ściankach z wartościami od $$1$$ do $$n$$, oraz jednego pionka. Plansza to $$n$$ pól ułożonych obok siebie, co tworzy jedną długą linię. Na każdym z pól umieszczona jest liczba całkowita, reprezentująca liczbę punktów przypisaną do danego pola. Pierwsze pole zawsze ma przypisaną wartość $$0$$.

Reguły gry są proste. Gracz umieszcza swój pionek na pierwszym polu planszy i rzuca kością. Potem przesuwa pionek o liczbę pól odpowiadającą liczbie oczek na kości. Ten ruch powtarza się wielokrotnie, za każdym razem przesuwając pionek o tyle samo pól, aż pionek przekroczy krawędź planszy. Punkty z pól, przez które przechodził pionek, są sumowane i stanowią wynik gracza.

Na przykład, jeśli mamy planszę o długości $$5$$ z wartościami $$[0, 6, -1, 2, 4]$$, a rzut kością wskazał liczbę $$2$$, pionek odwiedzi trzy pola: pierwsze, trzecie oraz piąte (następny ruch wyjdzie już poza planszę). Wartości tych pól to odpowiednio: $$0$$, $$-1$$ oraz $$4$$, co daje łącznie $$0+(-1)+4=3$$ punkty.

Bajtek jest doświadczonym graczem i potrafi rzucić kością tak, aby wypadła dowolna, wybrana przez niego liczba. Jednak nie wie, jaką liczbę powinien wylosować, aby osiągnąć maksymalny wynik dla danej planszy, dlatego zwraca się o pomoc do Ciebie!

## Dane

Wejście zawiera liczbę $$n$$ ($$1\lq n\lq 10^6$$), która oznacz długość planszy. Następnie podanych jest $$n$$ liczb całkowitych z przedziału $$<-1000, 1000>$$, każda w oddzielnej linii.

## Wynik

Na wyjściu powinny pojawić się dwie liczby całkowite: maksymalna możliwa do uzyskania liczba punktów oraz liczba oczek na kości (z zakresu od $$1$$ do $$n$$), która jest potrzebna do osiągnięcia tego wyniku. Jeżeli można uzyskać maksymalny wynik na kilka sposobów, wypisz dowolny z nich.

## Przykład

### Dane

```
5
0
6
-1
2
4
```

### Wynik

```
12
1
```
