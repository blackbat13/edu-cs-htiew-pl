# C++

## Implementacja

```cpp
#include <iostream>

using namespace std;

int main() {
    string socks;
    int b = 0, c = 0, result;

    cin >> socks;

    for(int i = 0; i < socks.length(); i++) {
        if (socks[i] == 'B') {
            b++;
        } else {
            c++;
        }
    }

    result = (b / 2) + (c / 2);

    cout << result << endl;
    
    return 0;
}
```