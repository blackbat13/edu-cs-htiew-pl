# Permutacje

## [:link: Opis problemu](../../../../algorithms/backtracking/permutations.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

void printTab(int tab[], int tabSize) {
    for(int i = 0; i < tabSize; i++) {
        cout << tab[i] << " ";
    }

    cout << endl;
}

void generatePermutations(int tab[], int beginIndex, int endIndex) {
    if(beginIndex > endIndex) {
        printTab(tab, endIndex + 1);
        return;
    }

    for(int i = beginIndex; i <= endIndex; i++) {
        swap(tab[beginIndex], tab[i]);
        generatePermutations(tab, beginIndex + 1, endIndex);
        swap(tab[beginIndex], tab[i]);
    }
}

int main() {
    int tab[3] = {1, 2, 3};
    bool used[3] = {};
    int result[3];

    generatePermutations(tab, 0, 2);

    return 0;
}
```

## Implementacja alternatywna

```cpp linenums="1"
#include <iostream>

using namespace std;

void printTab(int tab[], int tabSize) {
    for(int i = 0; i < tabSize; i++) {
        cout << tab[i] << " ";
    }

    cout << endl;
}

void generatePermutations(int tab[], bool used[], int result[], int index, int tabSize) {
    if(index >= tabSize) {
        printTab(result, tabSize);
        return;
    }

    for(int i = 0; i < tabSize; i++) {
        if (!used[i]) {
            used[i] = true;
            result[index] = tab[i];
            generatePermutations(tab, used, result, index + 1, tabSize);
            used[i] = false;
        }
    }
}

int main() {
    int tab[3] = {1, 2, 3};
    bool used[3] = {};
    int result[3];

    generatePermutations(tab, used, result, 0, 3);

    return 0;
}
```
