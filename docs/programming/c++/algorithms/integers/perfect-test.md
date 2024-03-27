# Test doskonałości

## [Opis problemu](../../../../algorithms/integers/perfect-test.md)

## Implementacja

```cpp linenums="1"
#include <iostream>
#include <cmath>

using namespace std;

bool isPerfect(int n) {
    int sum = 0;

    for (int i = 1; i < n; i++) {
        if (n % i == 0) {
            sum += i;
        }
    }

    return sum == n;
}

int main() {
    int n = 6;

    bool result = isPerfect(n);
    
    if (result) {
        cout << n << " is perfect" << endl;
    } else {
        cout << n << " is not perfect" << endl;
    }

    return 0;
}
```
