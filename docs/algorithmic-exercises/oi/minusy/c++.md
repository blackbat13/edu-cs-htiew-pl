# C++

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int n;
    char sign;
    bool plus = false;

    scanf("%d", &n);

    for(int i = 0; i < n - 1; i++) {
        cin >> sign;
        if (sign == '-' && plus) {
            printf(")");
            plus = false;
        } else if (sign == '+' && !plus){
            printf("(");
            plus = true;
        }

        printf("-");
    }

    if (plus) {
        printf(")");
    }

    printf("\n");
    return 0;
}
```
{% endcode %}