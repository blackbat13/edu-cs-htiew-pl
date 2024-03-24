# C++

## Implementacja

```cpp
#include <cstdio>

int main() {
    int t, n, counter;

    scanf("%d", &t);

    for(int testCase = 0; testCase < t; testCase++) {
        scanf("%d", &n);

        counter = 0;

        while (n % 2 == 0) {
            n /= 2;
            counter++;
        }

        if (counter % 2 == 0) {
            printf("NIE\n");
        } else {
            printf("TAK\n");
        }
    }
    
    return 0;
}
```