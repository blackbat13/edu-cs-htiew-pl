# C++

## Implementacja

```cpp
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n, number, div;

    unsigned long long int allFactors[50005] = {};
    unsigned long long int counter, result;

    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &number);

        div = 2;

        while(number > 1) {
            counter = 0;
            while(number % div == 0) {
                counter++;
                number /= div;
            }

            if(allFactors[div] < counter) {
                allFactors[div] = 0;
            } else {
                allFactors[div] -= counter;
            }

            allFactors[div] += counter;

            div++;
        }
    }

    result = 1;

    for (int i = 0; i <= 50000; i++) {
        result *= (allFactors[i] + 1);
        result %= 12345678;
    }

    if(result < n) {
        result += 12345678;
    }

    result -= n;

    printf("%llu\n", result);

    return 0;
}
```