# Wyszukiwanie minimum i maksimum

## [Opis problemu](../../../../algorithms/searching/min-or-max.md)


## Wyszukiwanie wartości minimum i maksimum

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int findMin(int n, int tab[]) {
    int min = tab[0];
    
    for(int i = 1; i < n; i++) {
        if(tab[i] < min) {
            min = tab[i];
        }
    }
    
    return min;
}

int findMax(int n, int tab[]) {
    int max = tab[0];
    
    for(int i = 1; i < n; i++) {
        if(tab[i] > max) {
            max = tab[i];
        }
    }
    
    return max;
}

int main() {
    int tab[10] = {8, 2, 9, 10, 5, 4, 2, 7, 18, 0};
    int n = 10;
    
    int min = findMin(n, tab);
    int max = findMax(n, tab);
    
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    
    return 0;
}
```


### Opis implementacji

Program zawiera dwie funkcje, `findMin` i `findMax`, które obie przyjmują liczbę `n` reprezentującą liczbę elementów w tablicy i tablicę `tab` zawierającą te elementy. Funkcja `findMin` zwraca najmniejszą wartość w tablicy, a `findMax` zwraca największą wartość.

Funkcja `findMin` działa następująco:

1. Inicjalizuje zmienną `min` jako pierwszy element tablicy.
2. Przeszukuje tablicę od drugiego elementu do końca.
3. Jeżeli aktualny element tablicy `tab[i]` jest mniejszy od aktualnej wartości `min`, aktualizuje `min` na `tab[i]`.
4. Po przejściu przez całą tablicę, zwraca `min`, które jest najmniejszą wartością w tablicy.

Podobnie, funkcja `findMax` działa w następujący sposób:

1. Inicjalizuje zmienną `max` jako pierwszy element tablicy.
2. Przeszukuje tablicę od drugiego elementu do końca.
3. Jeżeli aktualny element tablicy `tab[i]` jest większy od aktualnej wartości `max`, aktualizuje `max` na `tab[i]`.
4. Po przejściu przez całą tablicę, zwraca `max`, które jest największą wartością w tablicy.

Funkcja `main` definiuje tablicę `tab` z $10$ elementami, używa funkcji `findMin` i `findMax`, aby znaleźć minimalną i maksymalną wartość w tablicy, a następnie wyświetla te wartości na ekranie.

## Wyszukiwanie indeksów wartości minimum i maksimum

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int findMinIndex(int n, int tab[]) {
    int minInd = 0;
    
    for (int i = 1; i < n; i++) {
        if (tab[i] < tab[minInd]) {
            minInd = i;
        }
    }
    
    return minInd;
}

int findMaxIndex(int n, int tab[]) {
    int maxInd = 0;
    
    for (int i = 1; i < n; i++) {
        if (tab[i] > tab[maxInd]) {
            maxInd = i;
        }
    }
    
    return maxInd;
}

int main() {
    int tab[10] = {8, 2, 9, 10, 5, 4, 2, 7, 18, 0};
    int n = 10;
    
    int minInd = findMinIndex(n, tab);
    int maxInd = findMaxIndex(n, tab);
    
    cout << "Min Index: " << minInd << endl;
    cout << "Max Index: " << maxInd << endl;
    
    return 0;
}
```


### Opis implementacji

Program znajduje indeksy minimalnej i maksymalnej wartości w tablicy liczb całkowitych. W tym celu wykorzystuje dwie funkcje: `findMinIndex` i `findMaxIndex`.

Funkcja `findMinIndex` działa następująco:

1. Inicjalizuje zmienną `minInd` jako $0$, co odpowiada indeksowi pierwszego elementu tablicy.
2. Przechodzi przez tablicę od drugiego elementu do końca.
3. Jeżeli wartość aktualnego elementu` tab[i]` jest mniejsza od wartości elementu o indeksie `minInd`, aktualizuje `minInd` na `i`.
4. Po przejściu przez całą tablicę, zwraca `minInd`, które jest indeksem najmniejszego elementu w tablicy.

Podobnie, funkcja `findMaxIndex` działa w następujący sposób:

1. Inicjalizuje zmienną `maxInd` jako $0$, co odpowiada indeksowi pierwszego elementu tablicy.
2. Przechodzi przez tablicę od drugiego elementu do końca.
3. Jeżeli wartość aktualnego elementu `tab[i]` jest większa od wartości elementu o indeksie `maxInd`, aktualizuje `maxInd` na `i`.
4. Po przejściu przez całą tablicę, zwraca `maxInd`, które jest indeksem największego elementu w tablicy.

Funkcja `main` definiuje tablicę `tab` z $10$ elementami, używa funkcji `findMinIndex` i `findMaxIndex` do znalezienia indeksów minimalnej i maksymalnej wartości w tablicy, a następnie wyświetla te indeksy na ekranie.
