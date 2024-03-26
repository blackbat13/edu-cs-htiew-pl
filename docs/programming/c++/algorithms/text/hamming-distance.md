# Odległość Hamminga

## [Opis problemu](../../../../algorithms/text/hamming-distance.md)


## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int hammingDistance(string a, string b) {
    int distance = 0;
    
    for (int i = 0; i < a.length(); i++) {
        if (a[i] != b[i]) {
            distance++;
        }
    }

    return distance;
}

int main() {
    string a = "karolin";
    string b = "kerstin";
    
    int distance = hammingDistance(a, b);
    
    cout << distance << endl;

    return 0;
}
```

