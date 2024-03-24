# C++

## Implementacja

```cpp
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, mx;

    scanf("%d", &n);

    int values[n + 1];
    values[0] = 0;

    for(int i = 1; i <= n; i++) {
        scanf("%d", &values[i]);
        mx = values[i] + values[i - 1];
        for(int j = 2; j <= 6 && i - j >= 1; j++) {
            mx = max(mx, values[i] + values[i - j]);
        }

        values[i] = mx;
    }

    printf("%d\n", values[n]);
    
    return 0;
}
```