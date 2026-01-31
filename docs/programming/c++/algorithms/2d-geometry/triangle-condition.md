# Warunek trójkąta

## [:link: Opis problemu](../../../../algorithms/2d-geometry/triangle-condition.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

bool canBuildTriangle(int a, int b, int c) {
    return a + b > c && a + c > b && b + c > a;
}

int main() {
    int a = 5;
    int b = 3;
    int c = 4;

    bool result = canBuildTriangle(a, b, c);

    if (result) {
        cout << "Triangle can be build using lengths:  " << a << ", " << b << ", " << c << endl; 
    } else {
        cout << "Triangle cannot be build using lengths:  " << a << ", " << b << ", " << c << endl; 
    }

    return 0;
}
```
