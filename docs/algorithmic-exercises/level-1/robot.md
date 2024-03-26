# Robot

Posiadasz robota, zdolnego do poruszania się wyłącznie wzdłuż osi *x*, z możliwością ruchu w lewo lub prawo. Robot rozpoczyna swoją trasę z pozycji oznaczonej jako $0$. Może wykonać następujące instrukcje::

* LEWO - porusz się o jedną jednostkę w lewo,
* PRAWO - porusz się o jedną jednostkę w prawo,
* JAK W $i$ - wykonaj taki sam ruch, jak w $i$-tej instrukcji. $i$ jest zawsze liczbą naturalną i nie przekracza numeru instrukcji, w której się pojawia. Liczymy instrukcje od jedynki.

Zastanawiasz się, czy robot działa poprawnie. Twoim zadaniem jest napisanie programu, który dla podanego zestawu instrukcji określi pozycję, na której ostatecznie znajdzie się robot.

Źródło: [https://onlinejudge.org/external/125/12503.pdf](https://onlinejudge.org/external/125/12503.pdf)

## Specyfikacja

### Dane

* $n$ - liczba naturalna, liczba instrukcji do wykonania, $1\leq p\leq 100$.
* $n$ linii zawierających jedną z instrukcji tak jak opisano wcześniej.

### Wynik

* Liczba całkowita oznaczająca pozycję robota po wykonaniu wszystkich instrukcji.

## Przykład 1

### Dane

```
3
LEWO
PRAWO
JAK W 2
```

**Wynik:** $1$

## Przykład 2

### Dane

```
5
LEWO
JAK W 1
JAK W 2
JAK W 1
JAK W 4
```

**Wynik:** $-5$
