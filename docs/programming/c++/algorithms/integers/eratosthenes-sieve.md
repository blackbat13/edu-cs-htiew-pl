# Sito Eratostenesa

## [Opis problemu](../../../../algorithms/integers/eratosthenes-sieve.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void eratosthenesSieve(int n) {
    bool prime[n + 1];
    prime[0] = false;
    prime[1] = false;

    for (int i = 2; i <= n; i++) {
        prime[i] = true;
    }

    for (int i = 2; i < n; i++) {
        if (!prime[i]) {
            continue;
        }

        for (int j = 2 * i; j <= n; j += i) {
            prime[j] = false;
        }
    }

    cout << "Prime numbers from 1 to " << n << ":" << endl;
    for (int i = 2; i <= n; i++) {
        if (prime[i]) {
            cout << i << " ";
        }
    }

    cout << endl;
}

int main() {
    int n = 100;
    
    eratosthenesSieve(n);

    return 0;
}
```
