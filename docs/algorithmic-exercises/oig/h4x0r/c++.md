# C++

## Implementacja

```cpp
#include <iostream>

using namespace std;

int main() {
    string txt;

    cin >> txt;

    for(int i = 0; i < txt.length(); i++) {
        switch (txt[i]) {
            case 'a':
                txt[i] = '4';
                break;
            case 'e':
                txt[i] = '3';
                break;
            case 'i':
                txt[i] = '1';
                break;
            case 'o':
                txt[i] = '0';
                break;
            case 's':
                txt[i] = '5';
                break;
            default:
                break;
        }
    }

    cout << txt << endl;

    return 0;
}
```