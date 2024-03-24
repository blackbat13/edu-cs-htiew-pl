# C++

## Implementacja

```cpp
#include <cstdio>

using namespace std;

int main() {
    int n;

    scanf("%d", &n);

    int tab[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
    }

    if (tab[n - 1] == 0 || (n > 1 && tab[n-1] > tab[n-2] && tab[n-1] != 15)) {
        printf("UP\n");
    } else if (tab[n - 1] == 15 || (n > 1 && tab[n-1] < tab[n-2])) {
        printf("DOWN\n");
    } else {
        printf("UNKNOWN\n");
    }

    return 0;
}
```