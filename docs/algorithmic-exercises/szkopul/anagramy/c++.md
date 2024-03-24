# C++

## Implementacja

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    string a, b;

    cin >> a >> b;

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    if (a == b) {
        cout << "TAK" << endl;
    } else {
        cout << "NIE" << endl;
    }

    return 0;
}
```