# Prosta ścieżka w labiryncie

Dany jest "prosty" labirynt, tzn. z jednym korytarzem bez rozgałęzień. Celem jest dotarcie z punktu startowego do końcowego i policzenie ilości wykonanych kroków.

#### Specyfikacja

**Dane**:

* `n` - długość boku labiryntu;
* labirynt o wymiarach `n x n` podany w formie znaków `#` oraz spacji, gdzie `#` oznacza ścianę, a spacja pusty korytarz;
* `(startW, startK)` - współrzędne punktu startowego
* `(stopW, stopK)` - współrzędne punktu docelowego

**Wynik**:

* Długość korytarza z punktu startowego do punktu docelowego, czyli ilość kroków, które trzeba wykonać.

### Opis pomysłu

Komputer zostawia za sobą "ślady", odznaczając miejsca w labiryncie, które już odwiedził. W każdym kroku algorytmu komputer porusza się w kierunku, w którym znajduje się pusty, nie oznaczony jeszcze korytarz.

Jeżeli dotrzemy do ślepego zaułka i nie możemy wykonać kolejnego ruchu, oznacza to, że poszliśmy na początku w złym kierunku i miejsce docelowe znajduje się z drugiej strony. Dlatego "przeskakujemy" na pozycję startową i kontynuujemy przechodzenie przez labirynt zgodnie z opisaną wyżej metodą, pamiętając. by wyzerować licznik kroków.

```cpp
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main() {
    int n = 10; /// Labirynt ma wymiar n x n
    string labirynt[10];

    labirynt[0] = "##########";
    labirynt[1] = "#        #";
    labirynt[2] = "######## #";
    labirynt[3] = "#      # #";
    labirynt[4] = "# #### # #";
    labirynt[5] = "# # ## # #";
    labirynt[6] = "# #    # #";
    labirynt[7] = "# ###### #";
    labirynt[8] = "#        #";
    labirynt[9] = "##########";

    int startK = 6; /// Kolumna
    int startW = 1; /// Wiersz

    int stopK = 3; /// Kolumna
    int stopW = 5; /// Wiersz

    /// Zmienne do pozycji komputera
    int pozycjaK;
    int pozycjaW;

    /// Zapamietujemy, ile wykonalismy ruchow
    int ileRuchow = 0;

    /// Na poczatku komputer jest w miejscu start
    pozycjaK = startK;
    pozycjaW = startW;

    /// Dopoki nie jestesmy w miejscu stop
    while(pozycjaK != stopK || pozycjaW != stopW) {
        /// Jezeli pole z lewej strony jest puste
        if(labirynt[pozycjaW][pozycjaK - 1] == ' ') {
            /// Wykonujemy ruch
            labirynt[pozycjaW][pozycjaK] = '.'; /// Oznaczamy obecne miejsce jako odwiedzone
            pozycjaK--; /// Poruszamy sie w lewo
            ileRuchow++; /// Zwiekszamy licznik krokow
        } else if(labirynt[pozycjaW][pozycjaK + 1] == ' ') {
            labirynt[pozycjaW][pozycjaK] = '.';
            pozycjaK++;
            ileRuchow++;
        } else if(labirynt[pozycjaW - 1][pozycjaK] == ' ') {
            labirynt[pozycjaW][pozycjaK] = '.';
            pozycjaW--;
            ileRuchow++;
        } else if(labirynt[pozycjaW + 1][pozycjaK] == ' ') {
            labirynt[pozycjaW][pozycjaK] = '.';
            pozycjaW++;
            ileRuchow++;
        } else {
            /// Nie ma dozwolonego ruchu, wiec wracamy na poczatek
            pozycjaK = startK;
            pozycjaW = startW;
            ileRuchow = 0;
        }

        /// Czyscimy ekran konsoli
        system("cls");

        /// Wyswietlamy labirynt na ekranie
        for(int w = 0; w < n; w++)
        {
            for(int k = 0; k < n; k++)
            {
                /// Jezeli w i k sa pozycjami robota, to wypisz @
                /// W przeciwnym przypadku wypisz znak z labiryntu
                if(w == pozycjaW && k == pozycjaK)
                {
                    cout << "@";
                }
                else
                {
                    cout << labirynt[w][k];
                }
            }

            cout << endl;
        }
        cout << "Liczba ruchow: " << ileRuchow << endl;

        /// Czekamy chwile, np. 1 sekunde
        Sleep(1000);
    }

    cout << "Liczba ruchow: " << ileRuchow << endl;
    //cout << "Spacja: " << int(' ') << endl;
    return 0;
}
```

### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/SimplePath#main.cpp" %}

### Opis implementacji

TODO

{% hint style="warning" %}
Pod systemem Linux zamiast polecenia **cls** używamy polecenia **clear** do wyczyszczenia ekranu terminala.
{% endhint %}

{% hint style="warning" %}
Pod systemem Linux polecenie **Sleep** należy zastąpić poleceniem **usleep**, które jako parametr przyjmuje mikrosekundy, a nie milisekundy. Trzeba także zmienić bibliotekę "**windows.h**" na "**unistd.h**".
{% endhint %}
