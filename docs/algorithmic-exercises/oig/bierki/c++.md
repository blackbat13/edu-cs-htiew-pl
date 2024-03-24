# C++

## Implementacja

```cpp
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int liczbaBierek, ogon, glowa;
    int min1, min2, max, wynik, dlugosc;
    
    scanf("%d", &liczbaBierek);
    
    int bierki[liczbaBierek];

    for(int i = 0; i < liczbaBierek; i++) {
        scanf("%d", &bierki[i]);
    }

    sort(bierki, bierki + liczbaBierek);

    ogon = 0;
    glowa = 2;
    wynik = 0;

    while(glowa < liczbaBierek) {
        dlugosc = glowa - ogon + 1;
        
        if(dlugosc < 3) {
            glowa++;
            continue;
        }
        
        min1 = bierki[ogon];
        min2 = bierki[ogon + 1];
        max = bierki[glowa];

        if (min1 + min2 <= max) {
            ogon++;
        } else {
            if(dlugosc > wynik) {
                wynik = dlugosc;
            }

            glowa++;
        }
    }

    printf("%d\n", wynik);
    
    return 0;
}
```