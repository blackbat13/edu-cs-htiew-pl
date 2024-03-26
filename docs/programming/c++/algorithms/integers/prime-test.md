# Test pierwszości

## [Opis problemu](../../../../algorithms/integers/prime-test.md)


## Implementacja

```cpp linenums="1"
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }

    for (int i = 2; i <= sqrt(n); i++) {
        if(n % i == 0) {
            return false;
        }
    }

    return true;
}

int main() {
    int n = 7;

    bool result = isPrime(n);
    
    if (result) {
        cout << n << " is prime" << endl;
    } else {
        cout << n << " is not prime" << endl;
    }

    return 0;
}
```

