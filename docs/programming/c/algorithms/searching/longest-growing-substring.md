# Najdłuższy spójny podciąg rosnący

## [Opis problemu](../../../../algorithms/searching/longest-growing-substring.md)

## Implementacja

```c linenums="1"
#include <stdio.h>

int longestGrowingSubstringLength(int n, int tab[]) {
  int mx = 1;
  int length = 1;

  for (int i = 1; i < n; i++) {
    if (tab[i] > tab[i - 1]) {
      length += 1;
      if (length > mx) {
        mx = length;
      }
    } else {
      length = 1;
    }
  }

  return mx;
}

int main() {
  int tab[10] = {4, 9, 7, 2, 4, 7, 9, 3, 8, 6};
  int n = 10;

  int result = longestGrowingSubstringLength(n, tab);

  printf("%d\n", result);

  return 0;
}
```
