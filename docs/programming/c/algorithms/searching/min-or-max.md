# Wyszukiwanie minimum i maksimum

## [:link: Opis problemu](../../../../algorithms/searching/min-or-max.md)

## Wyszukiwanie wartości minimum i maksimum

### Implementacja

```c linenums="1"
#include <stdio.h>

int findMin(int n, int tab[]) {
  int min = tab[0];

  for (int i = 1; i < n; i++) {
    if (tab[i] < min) {
      min = tab[i];
    }
  }

  return min;
}

int findMax(int n, int tab[]) {
  int max = tab[0];

  for (int i = 1; i < n; i++) {
    if (tab[i] > max) {
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

  printf("Min: %d\n", min);
  printf("Max: %d\n", max);

  return 0;
}
```

## Wyszukiwanie indeksów wartości minimum i maksimum

### Implementacja

```c linenums="1"
#include <stdio.h>

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

  printf("Min index: %d\n", minInd);
  printf("Max index: %d\n", maxInd);

  return 0;
}
```
