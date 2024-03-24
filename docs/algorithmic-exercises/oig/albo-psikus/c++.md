# C++

## Implementacja

```cpp
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int n, oddCount = 0, evenCount = 0, c;
    unsigned long long int sum = 0, result = 0;

    scanf("%d", &n);

    for(int i = 1; i <= n; i++) {
        scanf("%d", &c);
        sum += c;
        if (sum % 2 == 0) {
            evenCount++;
            result += evenCount;
        } else {
            result += oddCount;
            oddCount++;
        }
    }

    printf("%llu\n", result);

    return 0;
}
```