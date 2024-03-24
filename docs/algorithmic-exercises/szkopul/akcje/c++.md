# C++

## Implementacja

```cpp
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n, result = 0;

    scanf("%d", &n);

    int tab[n], tabMin[n], tabMax[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
    }

    tabMin[0] = tab[0];
    tabMax[n - 1] = tab[n - 1];

    for(int i = 1; i < n; i++) {
        tabMin[i] = min(tab[i], tabMin[i - 1]);
    }

    for(int i = n - 2; i >= 0; i--) {
        tabMax[i] = max(tab[i], tabMax[i + 1]);
    }

    for(int i = 0; i < n - 1; i++) {
        result = max(tabMax[i + 1] - tabMin[i], result);
    }

    printf("%d\n", result);
    
    return 0;
}
```