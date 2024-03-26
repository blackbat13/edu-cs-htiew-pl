# C++

## Implementacja

```cpp linenums="1"
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    string number;
    unsigned long long int result = 0, first, second;

    unsigned long currentDigit, previousDigit, twoDigits;

    first = 1;
    
    cin >> number;

    result = number[0] - '0' + 1;
    second = result;

    for(int i = 1; i < number.length(); i++) {
        currentDigit = number[i] - '0';
        previousDigit = number[i - 1] - '0';
        
        result = currentDigit + 1;
        result *= second;

        if (previousDigit == 1) {
            result += (9 - currentDigit) * first;
        }

        first = second;
        second = result;
    }

    printf("%llu\n", result);
    
    return 0;
}
```
