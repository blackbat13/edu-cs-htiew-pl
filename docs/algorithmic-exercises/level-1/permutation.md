# Permutacja

Tablice stanowią fundament programowania, a posortowane tablice są jednym z jego kluczowych elementów. A czymże jest posortowana tablica, jeśli nie pewną **permutacją** tablicy pierwotnej?

Permutację tablicy można scharakteryzować wskazując docelową kolejność poszczególnych elementów tablicy, a także ich pierwotne rozmieszczenie. Twoim zadaniem jest wygenerowanie permutowanej tablicy na podstawie tak zdefiniowanego opisu.

Źródło: [https://onlinejudge.org/external/4/482.pdf](https://onlinejudge.org/external/4/482.pdf)

## Specyfikacja

### Dane

* $n$ - liczba elementów tablicy
* $p_1,p_2,...,p_n$ - opis permutacji: docelowa kolejność elementów, unikalne (bez powtórzeń) liczby całkowite z przedziału $[1,n]$
* $a_1,a_2,...,a_n$ - wartości tablicy w jej początkowym ułożeniu, liczby całkowite

### Wynik

* Zadana permutacja tablicy, tzn. taka, że element $a_i$ znajduje się na pozycji $p_i$.

## Przykład

### Dane

```
5
3 5 2 1 4
20 41 84 93 12
```

### Wynik

```
93 84 20 12 41  
```

!!! info
	#### Wyjaśnienie
	
	Opis permutacji określa nam docelową pozycję elementów:
	
	* $20$ na miejscu $3$
	* $41$ na miejscu $5$
	* $84$ na miejscu $2$
	* $93$ na miejscu $1$
	* $12$ na miejscu $4$
