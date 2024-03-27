---
description: Największy Wspólny Dzielnik
---

# NWD

## [Opis problemu](../../../../algorithms/integers/gcd.md)

## Wersja z odejmowaniem

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while (a != b) {
        if (a > b) {
            a -= b;
        } else {
            b -= a;
        }
    }

    return a;
}

int main() {
    int a = 32;
    int b = 12;
    
    int result = gcd(a, b);

    cout << "gcd(" << a << "," << b << ") = " << result << endl;

    return 0;
}
```

## Algorytm Euklidesa - wersja iteracyjna

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    while(b != 0) {
        int b2 = b;
        b = a % b;
        a = b2;
    }

    return a;
}

int main() {
    int a = 32;
    int b = 12;
    
    int result = gcd(a, b);

    cout << "gcd(" << a << "," << b << ") = " << result << endl;

    return 0;
}
```

## Algorytm Euklidesa - wersja rekurencyjna

### Implementacja

```cpp
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if(b == 0) {
        return a;
    }

    return gcd(b, a % b);
}

int main() {
    int a = 32;
    int b = 12;
    
    int result = gcd(a, b);

    cout << "gcd(" << a << "," << b << ") = " << result << endl;

    return 0;
}
```

## Operacje binarne - wersja iteracyjna

### Implementacja

```cpp
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    int shift;

    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    for (shift = 0; ((a | b) & 1) == 0; shift++) {
        a >>= 1;
        b >>= 1;
    }

    while ((a & 1) == 0) {
        a >>= 1;
    }

    while (b != 0) {
        while ((b & 1) == 0) {
            b >>= 1;
        }

        if (a > b) {
            swap(a, b);
        }

        b = b - a;
    }

    return a << shift;
}

int main() {
    int a = 32;
    int b = 12;
    
    int result = gcd(a, b);

    cout << "gcd(" << a << "," << b << ") = " << result << endl;

    return 0;
}
```

## Operacje binarne - wersja rekurencyjna

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int gcd(int a, int b) {
    if (a == b) {
        return a;
    }

    if (a == 0) {
        return b;
    }

    if (b == 0) {
        return a;
    }

    if (~a & 1) {
        if (b & 1) {
            return gcd(a >> 1, b);
        } else {
            return gcd(a >> 1, b >> 1) << 1;
        }
    }

    if (~b & 1) {
        return gcd(a, b >> 1);
    }

    if (a > b) {
        return gcd((a - b) >> 1, b);
    }

    return gcd((b - a) >> 1, a);
}

int main() {
    int a = 32;
    int b = 12;
    
    int result = gcd(a, b);

    cout << "gcd(" << a << "," << b << ") = " << result << endl;
    return 0;
}
```
