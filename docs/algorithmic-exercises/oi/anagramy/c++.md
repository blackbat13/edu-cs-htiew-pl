# C++

## Implementacja

```cpp
#include <iostream>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

int main() {
    int n;
    map<string, set<string> > anagramy;
    map<string, set<string> > posortowane_anagramy;
    string wyraz, posortowany;

    cin >> n;

    for(int i = 0; i < n; i++) {
        cin >> wyraz;
        posortowany = wyraz;
        sort(posortowany.begin(), posortowany.end());
        anagramy[posortowany].insert(wyraz);
    }

    for(auto el : anagramy) {
        posortowane_anagramy[*el.second.begin()] = el.second;
    }
    
    for(auto el : posortowane_anagramy) {
        for(auto w : el.second) {
            cout << w << " ";
        }
        
        cout << endl;
    }

    return 0;
}
```