# C++

## Implementacja

```cpp
#include <iostream>

using namespace std;

int main() {
    string word;
    int result = 0;
    
    cin >> word;

    for(int i = 1; i < word.length(); i++) {
        if (word[i] == word[i - 1]) {
            result++;
        }
    }

    cout << result << endl;
    
    return 0;
}
```