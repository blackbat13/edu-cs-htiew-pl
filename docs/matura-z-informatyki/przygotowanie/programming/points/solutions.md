# Rozwiązania

## Zadanie 1

=== "Python"

    ```python linenums="1"
    tab = [[False] * 101 for _ in range(101)]
    result = 0
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            if not tab[row][col]:
                result += 1
                tab[row][col] = True
    
    print("Zadanie 1:", result)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        bool tab[101][101] = {};
        int row, col, result = 0;
        ifstream file("points.txt");
        for (int i = 0; i < 1000; i++)
        {
            file >> row >> col;
            if (!tab[row][col])
            {
                result++;
                tab[row][col] = true;
            }
        }

        cout << "Zadanie 1: " << result << endl;
        file.close();
        
        return 0;
    }
    ```

## Zadanie 2

=== "Python"

    ```python linenums="1"
    rows = [False] * 101
    cols = [False] * 101
    rowCount = 0
    colCount = 0
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            if not rows[row]:
                rowCount += 1
                rows[row] = True
            if not cols[col]:
                colCount += 1
                cols[col] = True

    print("Zadanie 2:")
    print("Wiersze:", rowCount)
    print("Kolumny:", colCount)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        bool rows[101] = {};
        bool cols[101] = {};
        int row, col, rowCount = 0, colCount = 0;
        ifstream file("points.txt");
        for (int i = 0; i < 1000; i++)
        {
            file >> row >> col;
            if (!rows[row])
            {
                rowCount++;
                rows[row] = true;
            }
            if (!cols[col])
            {
                colCount++;
                cols[col] = true;
            }
        }

        cout << "Zadanie 2: " << endl;
        cout << "Wiersze: " << rowCount << endl;
        cout << "Kolumny: " << colCount << endl;
        file.close();
        
        return 0;
    }
    ```

## Zadanie 3

=== "Python"

    ```python linenums="1"
    tab = [[0] * 101 for _ in range(101)]
    result = 0
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            tab[row][col] += 1
            if tab[row][col] == 2:
                result += 1
    
    print("Zadanie 3:", result)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        int tab[101][101] = {};
        int row, col, result = 0;
        ifstream file("points.txt");
        for (int i = 0; i < 1000; i++)
        {
            file >> row >> col;
            tab[row][col]++;
            if (tab[row][col] == 2)
            {
                result++;
            }
        }

        cout << "Zadanie 3: " << result << endl;
        file.close();
        
        return 0;
    }
    ```

## Zadanie 4

=== "Python"

    ```python linenums="1"
    tab = [[0] * 101 for _ in range(101)]
    maxVal = 0
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            tab[row][col] += 1
            maxVal = max(maxVal, tab[row][col])

    print("Wartość:", maxVal)
    print("Współrzędne:")

    for row in range(1, 101):
        for col in range(1, 101):
            if tab[row][col] == maxVal:
                print(row, col)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        int tab[101][101] = {};
        int row, col, maxVal = 0;
        ifstream file("points.txt");
        for (int i = 0; i < 1000; i++)
        {
            file >> row >> col;
            tab[row][col]++;
            maxVal = max(maxVal, tab[row][col]);
        }

        cout << "Zadanie 4: " << endl;
        cout << "Wartosc: " << maxVal << endl;
        cout << "Wspolrzedne:" << endl;

        for (int r = 1; r <= 100; r++)
        {
            for (int c = 1; c <= 100; c++)
            {
                if (tab[r][c] == maxVal)
                {
                    cout << r << " " << c << endl;
                }
            }
        }
        
        return 0;
    }
    ```

## Zadanie 5

=== "Python"

    ```python linenums="1"
    tab = [[0] * 102 for _ in range(102)]
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            tab[row][col] += 1

    result = 0
    for row in range(1, 101):
        for col in range(1, 101):
            if tab[row][col] > 0:
                if tab[row - 1][col] == 0 and tab[row + 1][col] == 0 and tab[row][col - 1] == 0 and tab[row][col + 1] == 0:
                    result += 1

    print("Zadanie 5:", result)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        int tab[102][102] = {};
        int row, col, result = 0;
        ifstream file("points.txt");
        for (int i = 0; i < 1000; i++)
        {
            file >> row >> col;
            tab[row][col]++;
        }

        for (int r = 1; r <= 100; r++)
        {
            for (int c = 1; c <= 100; c++)
            {
                if (tab[r][c] > 0)
                {
                    if(tab[r-1][c] == 0 && tab[r+1][c] == 0 && tab[r][c-1] == 0 && tab[r][c+1] == 0) {
                        result++;
                    }
                }
            }
        }

        cout << "Zadanie 5: " << result << endl;
        file.close();
        
        return 0;
    }
    ```

## Zadanie 6

=== "Python"

    ```python linenums="1"
    tab = [[0] * 101 for _ in range(101)]
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            tab[row][col] += 1

    counters = [0] * 4
    for row in range(1, 101):
        for col in range(1, 101):
            counters[tab[row][col]] += 1
    
    for i in range(len(counters)):
        print(f"Wartość {i}: {counters[i]}")
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        int tab[101][101] = {};
        int row, col;
        ifstream file("points.txt");
        for (int i = 0; i < 1000; i++)
        {
            file >> row >> col;
            tab[row][col]++;
        }

        int counters[4] = {};
        for (int r = 1; r <= 100; r++)
        {
            for (int c = 1; c <= 100; c++)
            {
                counters[tab[r][c]]++;
            }
        }

        cout << "Zadanie 6: " << endl;
        for (int i = 0; i < 4; i++) {
            cout << "Wartosc " << i << ": " << counters[i] << endl;
        }

        file.close();
        
        return 0;
    }
    ```

## Zadanie 7

=== "Python"

    ```python linenums="1"
    tab = [[0] * 101 for _ in range(101)]
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            tab[row][col] += 1

    sum1 = 0
    sum2 = 0
    sum3 = 0
    sum4 = 0
    for row in range(1, 101):
        for col in range(1, 101):
            if row == col:
                sum1 += tab[row][col]
            elif col == 101 - row - 1:
                sum2 += tab[row][col]
            elif row > col:
                sum3 += tab[row][col]
            elif row < col:
                sum4 += tab[row][col]

    print("Główna przekątna:", sum1)
    print("Druga przekątna:", sum2)
    print("Pod główną przekątną:", sum3)
    print("Nad główną przekątną:", sum4)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        int tab[101][101] = {};
        int row, col;
        ifstream file("points.txt");
        for (int i = 0; i < 1000; i++)
        {
            file >> row >> col;
            tab[row][col]++;
        }

        int sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0;
        for (int r = 1; r <= 100; r++)
        {
            for (int c = 1; c <= 100; c++)
            {
                if (r == c)
                {
                    sum1 += tab[r][c];
                }
                else if (c == 101 - r - 1)
                {
                    sum2 += tab[r][c];
                }
                else if (r > c)
                {
                    sum3 += tab[r][c];
                }
                else if (r < c)
                {
                    sum4 += tab[r][c];
                }
            }
        }

        cout << "Zadanie 7: " << endl;
        cout << "Glowna przekatna: " << sum1 << endl;
        cout << "Druga przekatna: " << sum2 << endl;
        cout << "Pod glowna przekatna: " << sum3 << endl;
        cout << "Nad glowna przekatna: " << sum4 << endl;

        file.close();
        
        return 0;
    }
    ```

## Zadanie 8

=== "Python"

    ```python linenums="1"
    tab = [[0] * 101 for _ in range(101)]
    with open("points.txt") as file:
        for line in file:
            row, col = map(int, line.split())
            tab[row][col] += 1

    result = 0

    for row in range(1, 100):
        for col in range(1, 100):
            current_set = set()
            for i in range(2):
                for j in range(2):
                    current_set.add(tab[row + i][col + j])

            if len(current_set) == 4:
                result += 1

    print("Zadanie 8:", result)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <set>

    using namespace std;

    int main() {
        int tab[101][101] = {};
        int row, col, result = 0;
        ifstream file("points.txt");
        for (int i = 0; i < 1000; i++)
        {
            file >> row >> col;
            tab[row][col]++;
        }

        for(int r = 1; r < 100; r++) {
            for(int c = 1; c < 100; c++) {
                set<int> values;
                for(int i = 0; i <= 1; i++) {
                    for(int j = 0; j <= 1; j++) {
                        values.insert(tab[r+i][c+j]);
                    }
                }
                
                if(values.size() == 4) {
                    result++;
                }
            }
        }

        cout << "Zadanie 8: " << result << endl;
        file.close();
        
        return 0;
    }
    ```