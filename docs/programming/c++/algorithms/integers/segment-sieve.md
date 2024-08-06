# Sito Segmentowe

## [:link: Opis problemu](../../../../algorithms/integers/segment-sieve.md)

## Implementacja

```cpp linenums="1"
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

vector<int> sieve(int n) {
    vector<int> primes;
    vector<bool> is_prime(n + 1, true);

    for (int i = 2; i * i <= n; i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }

    for(int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            primes.push_back(i);
        }
    }

    return primes;
}

vector<int> segment_sieve(int num_from, int num_to) {
    int limit = sqrt(num_to) + 1;
    vector<int> primes = sieve(limit);

    int n = num_to - num_from + 1;
    vector<int> is_prime(n, true);

    for (int p : primes) {
        int start = (num_from / p) * p;
        if (start < num_from) {
            start += p;
        }
        if (start == p) {
            start += p;
        }
        for (int j = start; j <= num_to; j += p) {
            is_prime[j - num_from] = false;
        }
    }

    vector<int> result;
    for (int i = 0; i < n; i++) {
        if (is_prime[i]) {
            result.push_back(i + num_from);
        }
    }

    return result;
} 

int main() {
    int num_from, num_to;

    num_from = 100;
    num_to = 200;

    vector<int> primes = segment_sieve(num_from, num_to);
    
    for(int prime : primes) {
        cout << prime << " ";
    }

    cout << endl;

    return 0;
}
```
