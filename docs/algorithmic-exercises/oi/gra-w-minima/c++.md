# C++

## Implementacja

```cpp
#include <algorithm>
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n;
    int result = 0;

    scanf("%d", &n); 

    int cards[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &cards[i]);
    }

    sort(cards, cards + n);

    for(auto el: cards) {
        result = max(result, el - result);
    }

    printf("%d\n", result);
    
    return 0;
}
```