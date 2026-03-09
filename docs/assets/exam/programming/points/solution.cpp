#include <iostream>
#include <fstream>
#include <set>

using namespace std;

void exercise1()
{
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
}

void exercise2()
{
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
}

void exercise3()
{
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
}

void exercise4() {
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

    file.close();
}

void exercise5() {
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
}

void exercise6() {
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
}

void exercise7() {
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
}

void exercise8() {
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
}

int main()
{
    exercise1();
    exercise2();
    exercise3();
    exercise4();
    exercise5();
    exercise6();
    exercise7();
    exercise8();
    return 0;
}