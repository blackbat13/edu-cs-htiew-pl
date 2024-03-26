# Kłódka

Czas zająć się projektowaniem Escape Roomu, a kłódki szyfrowe czekają na swoją kolej. W swoim magazynie posiadasz kłódki z okrągłą tarczą, takie jak na zdjęciu poniżej. Tarcza kłódki składa się z $40$ przedziałek, które są numerowane od $0$ do $39$. Kombinacja do kłódki składa się z trzech liczb z tego zakresu.

![Thegreenj, CC BY-SA 3.0 <http://creativecommons.org/licenses/by-sa/3.0/>, via Wikimedia Commons](https://upload.wikimedia.org/wikipedia/commons/a/a1/Masterpadlock.jpg)

Aby otworzyć kłódkę, należy postępować zgodnie z poniższym schematem:

* Obróć tarczę dwa razy w pełnym obwodzie zgodnie z ruchem wskazówek zegara.
* Kontynuując ruch, zatrzymaj się na pierwszej liczbie z kombinacji.
* Wykonaj pełny obrót tarczy przeciwnie do ruchu wskazówek zegara.
* Kontynuując ruch, zatrzymaj się na drugiej liczbie z kombinacji.
* Następnie obróć tarczę zgodnie z ruchem wskazówek zegara, zatrzymując się na trzeciej liczbie z kombinacji.
* Teraz możesz pociągnąć za zamek i otworzyć kłódkę.

Twoim zadaniem jest wyliczenie, o ile stopni musisz łącznie obrócić tarczę, aby otworzyć kłódkę. Te informacje przydadzą się przy tworzeniu jednej z zagadek w Escape Roomie!

Źródło: [https://onlinejudge.org/external/105/10550.pdf](https://onlinejudge.org/external/105/10550.pdf)

## Specyfikacja

### Dane

* $p$ - liczba naturalna, początkowe ustawienie tarczy, $0\leq p\leq 39$.
* $c1$ - liczba naturalna, pierwsza liczba kombinacji, $0\leq c1\leq 39$.
* $c2$ - liczba naturalna, druga liczba kombinacji, $0\leq c2\leq 39$.
* $c3$ - liczba naturalna, trzecia liczba kombinacji, $0\leq c3\leq 39$.

### Wynik

* Liczba naturalna oznaczająca łączną liczbę stopni, o które należy obrócić tarczę, by otworzyć kłódkę.

## Przykład 1

### Dane

```
0 30 0 30
```

**Wynik:** $1350$

## Przykład 2

### Dane

```
5 35 5 35
```

**Wynik:** $1350$

## Przykład 3

### Dane

```
0 20 0 20
```

**Wynik:** $1620$

## Przykład 4

### Dane

```
7 27 7 27
```

**Wynik:** $1620$

## Przykład 5

### Dane

```
0 10 0 10
```

**Wynik:** $1890$

## Przykład 6

### Dane

```
9 19 9 19
```

**Wynik:** $1890$
