# Kodowanie obrazka

Grafika komputerowa jest niezwykle istotnym obszarem informatyki. Ponieważ przechowujemy na komputerach mnóstwo zdjęć, istotne jest efektywne reprezentowanie ich w pamięci komputera. W tym zadaniu skupimy się na szczególnym przypadku kodowania grafiki. Grafikę przedstawiamy jako prostokątną tablicę liter alfabetu angielskiego, gdzie każda litera koduje jeden region. Identyczne regiony są reprezentowane przez takie same litery.

Twoje zadanie polega na obliczeniu, ile bajtów pamięci jest potrzebnych do reprezentacji tak zaprezentowanej grafiki. Zasady są proste: obszar o najwyższym priorytecie reprezentowany jest za pomocą 2 bajtów, natomiast wszystkie pozostałe obszary za pomocą jednego bajta.

Obszar o **najwyższym** priorytecie to taki, który występuje **najczęściej**, czyli litera reprezentująca ten obszar pojawia się najwięcej razy w opisie grafiki. Jeżeli kilka obszarów ma taką samą, największą liczbę wystąpień, to wszystkie z nich uznajemy za obszary o najwyższym priorytecie.

Źródło: [https://onlinejudge.org/external/115/11588.pdf](https://onlinejudge.org/external/115/11588.pdf)

## Specyfikacja

### Dane

* $h, w$ - wymiary tablicy, jej wysokość i szerokość
* $pix[h][w]$ - opis grafiki, tablica dwuwymiarowa o wymiarach $h\times w$, której każdym elementem jest wielka litera alfabetu angielskiego

### Wynik

* Liczba bajtów potrzebna do reprezentacji podanej grafiki

## Przykład

### Dane

```
1
5 4
ABCD
ABCA
EFAC
BCAG
AZIP
```

### Wynik

```
26
```

!!! info
	#### Wyjaśnienie
	
	Najczęściej występującym regionem jest region **A**. Występuje on dokładnie $6$ razy. Oznacza to, że region **A** kodujemy za pomocą $2$ bajtów, a wszystkie pozostałe (których jest $14$), za pomocą $1$ bajta. Stąd otrzymujemy wynik: $6*2 + 14*1 = 12 + 14 = 26$
