# C++ - rozwiązanie

```cpp linenums="1"
#include <cstdio>
#include <iostream>
#include <map>

using namespace std;

int main() {
    int n;
    string slogan1, slogan2;
    map<string, string> slogans;

    scanf("%d", &n);
    getline(cin, slogan1);

    for(int i = 0; i < n; ++i) {
        getline(cin, slogan1);
        getline(cin, slogan2);
        slogans[slogan1] = slogan2;
    }

    scanf("%d", &n);
    getline(cin, slogan1);

    for(int i = 0; i < n; ++i) {
        getline(cin, slogan1);
        printf("%s\n", slogans[slogan1].c_str());
    }

    return 0;
}
```

