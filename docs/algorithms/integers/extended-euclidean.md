# Rozszerzony algorytm Euklidesa

Rozszerzony algorytm Euklidesa jest modyfikacją klasycznego algorytmu Euklidesa, który służy do obliczania największego wspólnego dzielnika (NWD) dwóch liczb całkowitych. Problemem, który rozwiązuje rozszerzony algorytm Euklidesa, jest znalezienie rozwiązań równania Diofantycznego postaci $ax + by = NWD(a,b)$, gdzie $a$ i $b$ są liczbami całkowitymi, a $x$ i $y$ są niewiadomymi. Jest to przydatne w wielu dziedzinach, takich jak kryptografia, teoria liczb, matematyka dyskretna czy programowanie liniowe.

## Specyfikacja

### Dane

* $a, b$ — liczby naturalne, większe od zera

### Wynik

* $x, y$ - liczby całkowite, takie że $ax + by = NWD(a,b)$
* $NWD(a, b)$ — największy wspólny dzielnik liczb $a$ i $b$ 

## Przykład

### Dane

```
a := 6
b := 21
```

### Wynik

```
x := -3
y := 1
NWD(a, b) := 3
```

!!! info
	**Wyjaśnienie**
	
	$6 * (-3) + 21 * 1 = 3$

## Implementacja

### C++


[extended-euclidean.md](../../programming/c++/algorithms/integers/extended-euclidean.md)


### Python


[extended-euclidean.md](../../programming/python/algorithms/integers/extended-euclidean.md)

