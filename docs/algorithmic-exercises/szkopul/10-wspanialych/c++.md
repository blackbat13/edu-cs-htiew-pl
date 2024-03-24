# C++

## Implementacja

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int liczba_kandydatow;

    scanf("%d", &liczba_kandydatow);

    int moce_kandydatow[liczba_kandydatow];

    for(int i = 0; i < liczba_kandydatow; i++) {
        scanf("%d", &moce_kandydatow[i]);
    }

    sort(moce_kandydatow, moce_kandydatow + liczba_kandydatow);

    for(int i = liczba_kandydatow - 1; i >= liczba_kandydatow - 10 && i >= 0; i--) {
        printf("%d ", moce_kandydatow[i]);
    }

    printf("\n");
    
    return 0;
}
```