# Odległość Levenshteina (edycyjna)

## Opis problemu

{% content-ref url="../../../../algorithms/text/levenshtein-distance.md" %}
[levenshtein-distance.md](../../../../algorithms/text/levenshtein-distance.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

int levenshteinDistance(string a, string b) {
    int matrix[a.length() + 1][b.length() + 1] = {};
    int cost;

    for (int i = 1; i <= a.length(); i++) {
        for (int j = 1; j <= b.length(); j++) {
            if (a[i - 1] == b[j - 1]) {
                cost = 0;
            } else {
                cost = 1;
            }

            matrix[i][j] = min(matrix[i - 1][j - 1] + cost, min(matrix[i - 1][j] + 1, matrix[i][j - 1] + 1));
        }
    }

    return matrix[a.length()][b.length()];
}

int main() {
    string a = "kitten";
    string b = "sitting";
    
    int distance = levenshteinDistance(a, b);
    
    cout << distance << endl;

    return 0;
}
```
{% endcode %}
