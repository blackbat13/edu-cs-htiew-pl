# Saper

## Opis

Jak wygląda klasyczna już gra **Saper** wie chyba każdy. Dla porządku przypomnijmy jednak jej najważniejsze aspekty:

* Prostokątna plansza wypełniona kwadratowymi polami.
* Na części z pól znajdują się tzw. bomby.
* Pozostałe pola wypełnione są liczbami, które oznaczają, ile sąsiednich pól (na ukos także) zajmują bomby.

Początkowo plansza jest zakryta, a celem gry jest odkrycie wszystkich pól poza bombami. My jednak zajmiemy się czymś prostszym: **dla zadanej odkrytej planszy wypełnionej bombami należy uzupełnić pozostałe pola właściwymi liczbami**.

### Specyfikacja

#### Dane:

* $$n$$ - liczba naturalna, wysokość planszy
* $$m$$ - liczba naturalna, szerokość planszy
* $$plansza[n][m]$$ - plansza wypełniona znakami $$*$$ oraz $$.$$ oznaczającymi odpowiednio bombę i pole puste

#### Wynik

* $$plansza[n][m]$$ - plansza wypełniona bombami i liczbami zgodnie z regułami gry saper

## Implementacja

```cpp
#include <iostream>

using namespace std;

/// Funkcja wypisuje tablice na ekranie
void wypisz(string tab[], int n) {
    for(int i = 0; i < n; i++) {
        cout << tab[i] << endl;
    }

    cout << endl;
}

/// Funkcja zastepuje kropki wartosciami oznaczajacymi ilosc sasiadujacych z polem bomb
void policz(string tab[], int n, int m) {
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            int licznikBomb = 0;

            /*if(x > 0) {
                if(tab[x-1][y] == '*') {
                    licznikBomb++;
                }
            }*/

            for(int px = -1; px <= 1; px++) {
                for(int py = -1; py <= 1; py++) {
                    int noweX = x + px;
                    int noweY = y + py;

                    /// Sprawdzamy, czy nowe pole miesci sie w tablicy
                    if(noweX >= 0 && noweY >= 0 && noweX < n && noweY < m) {
                        if(tab[noweX][noweY] == '*') {
                            licznikBomb++;
                        }
                    }
                }
            }

            /// Jeżeli obecne pole jest puste
            if(tab[x][y] == '.') {
                /// Zeby przekonwertowac liczbe na znak, dodajemy do niej wartosc znaku '0' z tablicy ASCII
                tab[x][y] = licznikBomb + '0';
            }
        }
    }
}

void policz2(string tab[], int n, int m) {
    for(int x = 0; x < n; x++) {
        for(int y = 0; y < m; y++) {
            int licznikBomb = 0;

            /// Tworzymy pomocnicze tablice
            /// okreslaja gdzie leza sasiedzi

            int X[8] = {-1, -1, -1,  0, 0,  1, 1, 1};
            int Y[8] = {-1,  0,  1, -1, 1, -1, 0, 1};

            for(int k = 0; k <= 7; k++) {
                int noweX = x + X[k];
                int noweY = y + Y[k];

                /// Sprawdzamy, czy nowe pole miesci sie w tablicy
                if(noweX >= 0 && noweY >= 0 && noweX < n && noweY < m) {
                    if(tab[noweX][noweY] == '*') {
                        licznikBomb++;
                    }
                }
            }

            /// Jeżeli obecne pole jest puste
            if(tab[x][y] == '.') {
                /// Zeby przekonwertowac liczbe na znak, dodajemy do niej wartosc znaku '0' z tablicy ASCII
                tab[x][y] = licznikBomb + '0';
            }
        }
    }
}

/// Odwiedzamy sasiaduje pola
/// Dla kazdej napotkanej bomby zwiekszamy licznik
/// Po sprawdzeniu sasiadow wpisujemy wartosc licznika do obecnego pola

/// Potencjalne problemy:
///  - Wyjscie poza tablice
///  - Konwersja liczby na znak
///  - Uciazliwe odwiedzanie sasiadow

/*
    (x+(-1), y-1) (x-1, y) (x-1, y+1)
    (x+0,   y-1) (x,   y) (x,   y+1)
    (x+1, y-1) (x+1, y) (x+1, y+1)
*/

int main() {
    int n, m; /// Wymiary planszy n x m

    n = 5;
    m = 6;

    string plansza[n];

    plansza[0] = "*.....";
    plansza[1] = "......";
    plansza[2] = "**....";
    plansza[3] = "....**";
    plansza[4] = "....**";

    cout << "Plansza gry:" << endl;
    wypisz(plansza, n);

    policz2(plansza, n, m);

    cout << "Policzona plansza gry:" << endl;
    wypisz(plansza, n);

    return 0;
}
```

### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/Saper#main.cpp" %}
