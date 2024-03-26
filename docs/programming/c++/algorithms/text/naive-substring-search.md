# Naiwne wyszukiwanie wzorca w tekście

## [Opis problemu](../../../../algorithms/text/naive-substring-search.md)


## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

bool isSubstring(string a, string b) {
    int j;

    for (int i = 0; i < b.length() - a.length(); i++) {
        j = 0;
        while (j < a.length()) {
            if (a[j] == b[i + j]) {
                j++;
            } else {
                break;
            }
        }

        if (j == a.length()) {
            return true;
        }
    }

    return false;
}

int main() {
    string a = "kot";
    string b = "alamakota";

    bool result = isSubstring(a, b);

    if (result) {
        cout << a << " is substring of " << b << endl;
    } else {
        cout << a << " is not substring of " << b << endl;
    }

    return 0;
}
```

