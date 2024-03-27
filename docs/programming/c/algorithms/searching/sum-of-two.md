# Suma dwóch liczb

## [Opis problemu](../../../../algorithms/searching/sum-of-two.md)

## Rozwiązanie naiwne

### Implementacja

```c linenums="1"
#include <stdio.h>

void sumOfTwoNaive(int n, int tab[], int sum) {
    for (int i = 0; i < n; i++) {
        for (int j = i+1; j < n; j++) {
            if (tab[i] + tab[j] == sum) {
              printf("%d, %d\n", tab[i], tab[j]);
                return;
            }
        }
    }

  printf("Not found\n");
}

int main() {
    int n = 10;
    int tab[10] = {1, 2, 4, 6, 8, 9, 10, 12, 13, 15};
    int sum = 18;

    sumOfTwoNaive(n, tab, sum);

    return 0;
}
```

## Rozwiązanie optymalne

### Implementacja

```c linenums="1"
#include <stdio.h>

void sumOfTwoOptimal(int n, int tab[], int sum) {
  int left = 0;
  int right = n - 1;

  while (left < right && tab[left] + tab[right] != sum) {
    if (tab[left] + tab[right] < sum) {
      left++;
    } else {
      right--;
    }
  }

  if (left < right) {
    printf("%d, %d\n", tab[left], tab[right]);
  } else {
    printf("Not found\n");
  }
}

int main() {
  int n = 10;
  int tab[10] = {1, 2, 4, 6, 8, 9, 10, 12, 13, 15};
  int sum = 18;

  sumOfTwoOptimal(n, tab, sum);

  return 0;
}
```
