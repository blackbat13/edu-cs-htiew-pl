# C++

## Implementacja

```cpp
#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    string results;
    int a = 0, b = 0;

    cin >> results;

    for(int i = 0; i < results.length(); i++) {
        if (results[i] == 'A') {
            a++;
        } else {
            b++;
        }
    }

    printf("%d : %d\n", a, b);
    
    return 0;
}
```