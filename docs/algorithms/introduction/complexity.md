# Złożoność

**Złożoność** jest bardzo ważnym elementem dyskusji na temat algorytmów. Często jest to kluczowy czynnik według którego porównujemy **efektywność** dwóch rozwiązań/algorytmów. Wyróżniamy przede wszystkim:

* **złożoność czasową/obliczeniową** - tzn. ile operacji w zależności od rozmiaru danych wejściowych program musi wykonać,
* **złożoność pamięciową** - ile pamięci (w zależności od rozmiaru danych wejściowych) program potrzebuje.

W tym kursie nie będziemy rozmawiać, ani też obliczać dokładnej złożoności algorytmów. Skupimy się na ich **szacunkowej pesymistycznej złożoności**.

Dlatego nie będziemy wchodzić głęboko w szczegóły matematyczne. Zainteresowanych odsyłam do zewnętrznych źródeł, np.:

* [https://pl.wikipedia.org/wiki/Z%C5%82o%C5%BCono%C5%9B%C4%87\_obliczeniowa](https://pl.wikipedia.org/wiki/Z%C5%82o%C5%BCono%C5%9B%C4%87\_obliczeniowa)
* [https://pl.wikipedia.org/wiki/Asymptotyczne_tempo_wzrostu](https://pl.wikipedia.org/wiki/Asymptotyczne_tempo_wzrostu)

## Notacja dużego O (asymptotyczna)

Nie będziemy tutaj wchodzić w szczegóły notacji asymptotycznej dużego O. W dużym skrócie będziemy jej używać do określania **pesymistycznej** złożoności czasowej algorytmu. Dla przykładu, jeżeli algorytm będzie miał złożoność $O(n)$ to oznacza, że w najgorszym przypadku będzie działał liniowo w stosunku do rozmiaru danych. Oczywiście nie wyklucza do sytuacji, w których taki algorytm zadziała szybciej.

## Podstawowe klasy złożoności

| Zapis            | Nazwa                                   | Przykład                               |
| ---------------- | --------------------------------------- | -------------------------------------- |
| $O(1)$         | stała                                   | Sprawdzenie warunku trójkąta           |
| $O(\log{n})$   | logarytmiczna                           | Wyszukiwanie binarne                   |
| $O(n)$         | liniowa                                 | Wyszukiwanie liniowe                   |
| $O(n\log{n})$  | liniowo logarytmiczna                   | Sortowanie przez scalanie              |
| $O(n^2)$       | kwadratowa                              | Sortowanie bąbelkowe                   |
| $O(n^3)$       | sześcienna                              | Algorytm Floyda-Warshalla              |
| $O(n^k)$       | wielomianowa ( $k$ - stała, $k>1$ ) | -                                      |
| $O(n!)$        | n-silnia                                | Wypisanie wszystkich permutacji zbioru |
| $O(2^n)$       | wykładnicza                             | Wypisanie wszystkich podzbiorów zbioru |

## Szacowanie złożoności

### Przykład - złożoność liniowa

```
1. Od i := 1 do n, wykonuj:
    2. Wypisz i
```

### Przykład - złożoność kwadratowa

```
1. Od i := 1 do n, wykonuj:
    2. Od j := 1 do n, wykonuj:
        3. Wypisz i * j
```

### Przykład - złożoność sześcienna

```
1. Od i := 1 do n, wykonuj:
    2. Od j := 1 do n, wykonuj:
        3. Od k := 1 do n, wykonuj:
            4. Wypisz i * j * k
```

### Przykład - złożoność logarytmiczna

```
1. Dopóki n > 0, wykonuj:
    2. Wypisz n
    3. n := n div 2
```

!!! info
    **div** oznacza dzielenie całkowite

## Ściąga

[https://github.com/ro31337/bigoposter/blob/master/bigoposter.pdf](https://github.com/ro31337/bigoposter/blob/master/bigoposter.pdf)
