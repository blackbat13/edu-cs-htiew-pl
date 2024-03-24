# Labirynt

## Opis problemu

TODO

### Specyfikacja

#### Dane

* $$n$$ - wymiar kwadratowego labiryntu
* $$labirynt[n][n]$$ - dwuwymiarowa tablica definiująca labirynt, w którym spacja oznacza wolne miejsce, a znak hasz oznacza ścianę
* $$startK, startW$$ - współrzędne punktu startowego (kolumna i wiersz)
* $$stopK, stopW$$ - współrzędne punktu docelowego (kolumna i wiersz)

#### Wynik

* Dotarcie z punktu startowego do końcowego.

## Opis pomysłu

Każdemu polu w labiryncie przypisujemy wartość liczbową, która będzie służyła za licznik odwiedzin. Na początku każdemu polu przypisujemy wartość 0. Gdy w trakcie poruszania się po labiryncie odwiedzimy dane pole, to zwiększymy wartość jego licznika o 1. W każdym kolejnym kroku wybieramy jedno z sąsiednich pól o najmniejszej wartości licznika.

## Implementacja

```cpp
#include <iostream>
#include <cstdlib>
#include <windows.h>

using namespace std;

int main() {
    int n = 10; /// Labirynt ma wymiar n x n
    string labirynt[10];

    labirynt[0] = "##########";
    labirynt[1] = "#       ##";
    labirynt[2] = "##  ######";
    labirynt[3] = "##  ######";
    labirynt[4] = "##  ######";
    labirynt[5] = "#       ##";
    labirynt[6] = "###### ###";
    labirynt[7] = "###### ###";
    labirynt[8] = "######  ##";
    labirynt[9] = "##########";

    int startK = 1; /// Kolumna
    int startW = 1; /// Wiersz

    int stopK = 7; /// Kolumna
    int stopW = 8; /// Wiersz

    /*
        Pomysl 1:
            - Poruszamy sie tak jak wczesniej
            - Odwiedzone pola odznaczamy, np. kropka
            - Gdy natrafimy na rozgalezienie, to zapamietujemy jego wspolrzedne
            - Gdy dotrzemy do slepego zaulka, to wracamy do rozgalezienia i idziemy dalej
            - problem: pamietac kilka rozgalezien

        Pomysl 2:
            - losowe wybieranie drogi na rozgalezieniu
            - w petli zaczynamy droge od punktu startowego
            - gdy dojdziemy do slepego zaulka, to zaczynamy od nowa
            - pomysl: zapamietywanie drog, przez ktore przeszlismy, zeby wybierac inne

        Pomysl 3:
            - Algorytm/zasada prawej/lewej reki

        Pomysl 4:
            - Kazdemu polu przypisujemy wartosc liczbowa, zaczynamy od 0
            - Gdy odwiedzamy pole, to zwiekszamy jego wartosc o 1
            - W kazdym kroku wybieramy pole z najmniejsza wartoscia jako kolejny ruch

        Pomysl 5:
            - Przedstawic labirynt jako graf
            - Skrzyzowania jako wierzcholki
            - Krawedzie wazone z waga proporcjonalna do dlugosci krawedzi
    */



    /// Implementujemy pomysl 4

    /// Tworzymy tablice do zapamietania licznikow dla pol
    int odwiedziny[n][n];

    /// Wypelniamy tablice odwiedzin
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(labirynt[i][j] == ' ') {
                odwiedziny[i][j] = 0;
            } else {
                /// W miejsce scian wpisujemy duza liczbe,
                /// zeby te pola nie zostaly wybrane przez algorytm
                odwiedziny[i][j] = 10000000;
            }
        }
    }

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

        /// Zapamietujemy liczby przypisane do pol naokolo
        int lewo, prawo, gora, dol;

        lewo = odwiedziny[pozycjaW][pozycjaK - 1];
        prawo = odwiedziny[pozycjaW][pozycjaK + 1];
        dol = odwiedziny[pozycjaW + 1][pozycjaK];
        gora = odwiedziny[pozycjaW - 1][pozycjaK];

        /// Zwiekszamy licznik obecnego pola
        odwiedziny[pozycjaW][pozycjaK]++;

        if(lewo <= prawo && lewo <= dol && lewo <= gora) {
            /// Idziemy w lewo
            pozycjaK--; /// Poruszamy sie w lewo
            ileRuchow++; /// Zwiekszamy licznik krokow
        } else if(prawo <= lewo && prawo <= dol && prawo <= gora) {
            /// Idziemy w prawo
            pozycjaK++;
            ileRuchow++;
        } else if(gora <= lewo && gora <= dol && gora <= prawo) {
            /// Idziemy w gore
            pozycjaW--;
            ileRuchow++;
        } else {
            /// Idziemy w dol
            pozycjaW++;
            ileRuchow++;
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

        cout << endl << endl;

        /// Wyswietlamy labirynt na ekranie
        for(int w = 0; w < n; w++)
        {
            for(int k = 0; k < n; k++)
            {
                if(odwiedziny[w][k] == 10000000) {
                    cout << "- ";
                }
                 else {
                    cout << odwiedziny[w][k] << " ";
                 }
            }

            cout << endl;
        }

        cout << "Liczba ruchow: " << ileRuchow << endl;

        /// Czekamy chwile, np. 1 sekunde
        Sleep(1000);
    }

    cout << "Liczba ruchow: " << ileRuchow << endl;
    
    return 0;
}
```

### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/Maze#main.cpp" %}

### Opis implementacji

TODO

{% hint style="warning" %}
Pod systemem Linux zamiast polecenia **cls** używamy polecenia **clear** do wyczyszczenia ekranu terminala.
{% endhint %}

{% hint style="warning" %}
Pod systemem Linux polecenie **Sleep** należy zastąpić poleceniem **usleep**, które jako parametr przyjmuje mikrosekundy, a nie milisekundy. Trzeba także zmienić bibliotekę "**windows.h**" na "**unistd.h**".
{% endhint %}
