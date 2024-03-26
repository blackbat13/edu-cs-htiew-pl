# Najdłuższy wspólny podciąg

## [Opis problemu](../../../../algorithms/text/longest-common-subsequence.md)


## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

string longestCommonSubsequence(string a, string b) {
    int matrix[a.length() + 1][b.length() + 1] = {};
    int value, i, j;
    string result = "";

    for (i = 1; i <= a.length(); i++) {
        for (j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                matrix[i][j] = matrix[i - 1][j - 1] + 1;
            } else {
                matrix[i][j] = max(matrix[i - 1][j], matrix[i][j - 1]);
            }
        }
    }

    value = matrix[a.length()][b.length()];
    i = a.length();
    j = b.length();
    
    while (value > 0) {
        if (matrix[i - 1][j] == value) {
            i--;
        } else if (matrix[i][j - 1] == value) {
            j--;
        } else {
            result = a[i - 1] + result;
            i--;
            j--;
            value--;
        }
    }

    return result;
}

int main() {
    string a = "kitten";
    string b = "sitting";
    
    string lcs = longestCommonSubsequence(a, b);
    
    cout << lcs << endl;
    
    return 0;
}
```

