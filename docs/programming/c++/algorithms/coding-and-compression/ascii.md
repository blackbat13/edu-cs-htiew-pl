# Kod ASCII

## [Opis problemu](../../../../algorithms/coding-and-compression/ascii.md)


## Podstawowa tablica ASCII

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int main() {
    char c;
    
    for (int i = 0; i <= 127; i++) {
        c = (char) i;
        cout << i << " = " << c << endl;
    }
    
    return 0;
}
```


## Rozszerzona tablica ASCII

### Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int main() {
    unsigned char c;
    
    for (int i = 0; i <= 255; i++) {
        c = (unsigned char) i;
        cout << i << " = " << c << endl;
    }
    
    return 0;
}
```

