# C++

## Implementacja

```cpp
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    unsigned long long int n, sum;
    int digit;
    string binary;

    scanf("%llu", &n);

    sum = 0;

    while (n > 0) {
        digit = n % 2;
        binary = char(digit + '0') + binary;
        sum += digit;
        n /= 2;
    }

    if (binary.length() == 0) {
        binary = "0";
    }

    printf("%s ", binary.c_str());

    binary = "";

    while (sum > 0) {
        digit = sum % 2;
        binary = char(digit + '0') + binary;
        sum /= 2;
    }

    if (binary.length() == 0) {
        binary = "0";
    }

    printf("%s\n", binary.c_str());
    
    return 0;
}
```