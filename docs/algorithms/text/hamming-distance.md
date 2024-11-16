# Odległość Hamminga

Odległość Hamminga jest miarą różnicy między dwoma ciągami o tej samej długości. W szczególności jest to liczba pozycji, na których odpowiadające sobie znaki w dwóch ciągach są różne. Jest używana głównie w teorii kodowania do mierzenia błędu i jest użyteczna w wielu dziedzinach, takich jak korekcja błędów w systemach komunikacji.

## Definicja

!!! info
	 Dla dwóch ciągów $s_1$ i $s_2$ o tej samej długości $n$, odległość Hamminga $H(s_1, s_2)$ jest określona jako liczba pozycji $i$ dla $1 \leq i \leq n$ takich, że $s_1[i] \neq s_2[i]$.

## Przykład

Niech `s_1 = "karol"` i `s_2 = "koral"`. Odległość Hamminga dla tych ciągów wynosi $2$, ponieważ różnią się one na pozycjach $3$ i $5$.

## Zastosowania

- **Korekcja błędów**: odległość Hamminga może być używana do korekcji błędów w systemach komunikacji, jako że pozwala na wykrywanie i korekcję pojedynczych błędów.
- **Bioinformatyka**: odległość Hamminga może być używana do porównywania sekwencji DNA.
- **Kryptografia**: w niektórych schematach kryptograficznych odległość Hamminga między dwoma ciągami może dostarczyć informacji o stopniu podobieństwa tych ciągów, co może być używane do analizy błędów lub ataków.

## Specyfikacja

### Dane

- $s_1$, $s_2$ - dwa teksty, ciągi znaków liter angielskiego, o tej samej długości

### Wynik

- Odległość Hamminga pomiędzy $s_1$ a $s_2$.

## Algorytm

### Lista kroków

1. Zainicjalizuj licznik na $0$.
2. Dla każdej pozycji $i$ w ciągach:
   - Jeśli znaki na pozycji $i$ w obu ciągach są różne, zwiększ licznik o $1$.
3. Zwróć wartość licznika jako odległość Hamminga.

### Pseudokod

- **Długość(tekst)** - zwraca długość tekstu

```
funkcja OdległośćHamminga(s1, s2):
    1. wynik := 0
    2. Dla i := 1 do Długość(s1), wykonuj:
        1. Jeżeli s1[i] != s2[i], to:
            1. wynik := wynik + 1
    3. Zwróć wynik
```

## Złożoność

Złożoność czasowa algorytmu to $O(n)$, gdzie $n$ to długość ciągów.

## Implementacja

### [:simple-cplusplus: C++](../../programming/c++/algorithms/text/hamming-distance.md){ .md-button }

### [:simple-python: Python](../../programming/python/algorithms/text/hamming-distance.md){ .md-button }
