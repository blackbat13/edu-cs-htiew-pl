# Problem skoczka

## [Opis problemu](../../../../algorithms/backtracking/knights-tour.md)


## Implementacja

```cpp linenums="1"
#include <iostream>
#include <vector>

using namespace std;

const int movesRow[8] = {-1, 1, 2, 2, -2, -2, -1, 1};
const int movesColumn[8] = {-2, -2, -1, 1, -1, 1, 2, 2};

bool knightTour(int n, vector<vector<int> > &chessboard, int visitedCount, int row, int column) {
    chessboard[row][column] = visitedCount - 1;

    if (visitedCount == n * n) {
        return true;
    }

    for(int i = 0; i < 8; i++) {
        int newRow = row + movesRow[i];
        int newColumn = column + movesColumn[i];
        if (newRow >= 0 && newRow < n && newColumn >= 0 && newColumn < n && chessboard[newRow][newColumn] == -1) {
            if (knightTour(n, chessboard, visitedCount + 1, newRow, newColumn)) {
                return true;
            }
        }
    }

    chessboard[row][column] = -1;
    return false;
}

void printChessboard(int n, vector<vector<int> > chessboard) {
    for (int row = 0; row < n; row++) {
        for (int column = 0; column < n; column++) {
            cout << chessboard[row][column] << " ";
        }

        cout << endl;
    }
}

int main() {
    int n = 5;
    vector<vector<int> > chessboard = vector<vector<int> >(n, vector<int>(n, -1));

    bool result = knightTour(n, chessboard, 1, 0, 0);

    if (result) {
        cout << "Result found:" << endl;
        printChessboard(n, chessboard);
    } else {
        cout << "No result" << endl;
    }
    
    return 0;
}
```

