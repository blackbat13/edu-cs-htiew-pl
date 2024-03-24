# C++

## Implementacja

```cpp
#include <cstdio>

int sign(int number) {
    if(number < 0) {
        return -1;
    } else if(number > 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int n, result = 1, lastSign = 0, currentSign;

    scanf("%d", &n);

    int tab[n];

    for(int i = 0; i < n; i++) {
        scanf("%d", &tab[i]);
    }

    if (n > 1) {
        lastSign = sign(tab[1] - tab[0]);
        if(lastSign == -1) {
            result++;
        }
    }

    for(int i = 2; i < n; i++) {
        currentSign = sign(tab[i] - tab[i - 1]);
        if (lastSign == 0) {
            lastSign = currentSign;
            if(lastSign == -1) {
                result++;
            }
        }
        
        if (currentSign != 0 && currentSign != lastSign) {
            result++;
            lastSign = currentSign;
        }
    }

    printf("%d\n", result);
    
    return 0;
}
```