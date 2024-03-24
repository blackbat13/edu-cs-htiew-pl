# Rekurencja w labiryncie

```cpp
#include <iostream>
#include <random>
#include <ctime>
using namespace std;

void wypisz(string labirynt[], int n) {
    for(int i = 0; i < n; i++) {
        cout << labirynt[i] << endl;
    }

    cout << endl;
}

bool sprawdzKorytarz(int wys, int szer, string labirynt[], int n) {
    /// Sprawdzamy, czy jestesmy u celu
    if(wys == n-2 && szer == n-2) {
        return true;
    }

    bool wynik = false;

    /// Jezeli jest krawedz w dol
    if(labirynt[wys+1][szer] == ' ') {
        wynik = sprawdzKorytarz(wys + 2, szer, labirynt, n);
        if(wynik == true) {
            return true;
        }
    }

    if(labirynt[wys][szer+1] == ' ') {
        wynik = sprawdzKorytarz(wys, szer + 2, labirynt, n);
        if(wynik == true) {
            return true;
        }
    }

    /// Skoro dotarlismy tutaj w kodzie, to nie zwrocilismy true
    return false;
}

int main() {
    /// Inicjalizujemy liczby losowe
    srand(time(NULL));

    int n;
    cout << "Podaj wymiar labiryntu: ";
    cin >> n;
    string labirynt[n];

    // Krok 1. Wypelniamy cala tablice scianami (#)
    // Krok 2. Zamieniamy co drugie pole na puste

    // Dla kazdego wiersza
    for(int w = 0; w < n; w++) {
        // Dla kazdej kolumny
        for(int k = 0; k < n; k++) {
            // Dopisujemy znak # do wiersza w
            labirynt[w] += 219;
        }
    }

    for(int w = 1; w < n - 1; w += 2) {
        for(int k = 1; k < n - 1; k += 2) {
            labirynt[w][k] = ' ';
        }
    }

    wypisz(labirynt, n);

    /*
        1. Dla kazdego pustego pola, wykonuj:
            2. Wybierz jednego z sasiadow: lewo lub gora (jezeli istnieje)
            3. Usun sciane w wybranym kierunku
    */

    for(int w = 1; w < n - 1; w += 2) {
        for(int k = 1; k < n - 1; k += 2) {
            if(w == 1 && k != 1) {
                /// Robimy przejscie w lewo
                labirynt[w][k-1] = ' ';
            } else if(w != 1 && k == 1) {
                /// Robimy przejscie do gory
                labirynt[w-1][k] = ' ';
            } else if(w != 1 && k != 1) {
                /// Losowo wybieramy lewo lub gora
                int losowa;
                losowa = rand() % 2;
                if(losowa == 0) {
                    labirynt[w][k-1] = ' ';
                } else {
                    labirynt[w-1][k] = ' ';
                }
            }
        }
    }

    wypisz(labirynt, n);

    cout << sprawdzKorytarz(1, 1, labirynt, n) << endl;

    /*
        Zaczynamy w (1,1) - lewy gorny rog
        Chcemy dotrzec do punktu (n-2, n-2) - prawy dolny rog
    */

    /// Idea:
    /// Zaczynamy w punkcie startowym
    ///  Sprawdzamy sciezke w dol, a jak nie dotrzemy do sprawdzamy w prawo
    return 0;
}

/// bool sprawdzKorytarz(int wys, int szer)
///      Jezeli jestesmy u celu, to zwracamy prawda i konczymy
///   .  Jezeli nie jestesmy u celu, to:
///   .      Jezeli jest krawedz w dol, to sprawdzamy, czy idac w dol dojdziemy do celu
///             sprawdzKorytarz(wys+2, szer)
///   .      Jezeli to nie pomoglo i mozemy pojsc w prawo, to sprawdzamy czy w prawo dojdziemy do celu
///             sprawdzKorytarz(wys, szer+2)
///      Jezeli nie dotarlismy, albo nie mozemy isc w dol ani w prawo, to zwracamy falsz
/*
    labirynt[0] = "###########";
    labirynt[1] = "# # # # # #";
    labirynt[2] = "###########";
    labirynt[3] = "# # # # # #";
    labirynt[4] = "###########";
    labirynt[5] = "# # # # # #";
    labirynt[6] = "###########";
    labirynt[7] = "# # # # # #";
    labirynt[8] = "###########";
    labirynt[9] = "# # # # # #";
    labirynt[10] ="###########";
    */

```
