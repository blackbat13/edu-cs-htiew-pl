# Problem n królowych

## [Opis problemu](../../../../algorithms/backtracking/n-queens.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

bool checkNewPosition(int row, int column, int positions[]) {
    for (int i = 0; i < row; i++) {
        if (positions[i] == column || column - positions[i] == row - i) {
            return false;
        }
    }
    
    return true;
}

bool findSolution(int n, int row, int positions[]) {
    if (row == n) {
        return true;
    }

    for (int column = 0; column < n; column++) {
        if (!checkNewPosition(row, column, positions)) {
            continue;
        }

        positions[row] = column;
        
        if (findSolution(n, row + 1, positions)) {
            return true;
        }
    }
    
    return false;
}

void printCheckboard(int n, int positions[]) {
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {
            if (positions[row] == column) {
                cout << "1 ";
            } else {
                cout << "0 ";
            }
        }
        
        cout << endl;
    }
}
    
int main() {
    int n = 5;
    int positions[n];

    bool result = findSolution(n, 0, positions);

    if (result) {
        printCheckboard(n, positions);
    } else {
        cout << "No result exists" << endl;
    }
    
    return 0;
}
```
