# Labirynt - szablon

{% tabs %}
{% tab title="C++" %}
```cpp
#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream> // Biblioteka do obslugi plikow
using namespace std;

/// Funkcja wyswietla labirynt na ekranie
void wyswietlLabirynt(string labirynt[], int n, int m)
{
    for(int w = 0; w < n; w++)
    {
        for(int k = 0; k < m; k++)
        {
            cout << labirynt[w][k];
        }

        cout << endl;
    }

    cout << endl;
}

int main()
{
    ifstream plik("labirynt.txt");

    int n, m;  /// Wysokosc - n, Szerokosc - m
    int startK, startW, stopK, stopW;

    plik >> n >> m;   /// Wczytujemy dane z pliku podobnie jak przy pomocy operatora cin

    string labirynt[n], tmp;

    /// Uzywamy raz polecenia getline, ignorujac to co wczyta
    getline(plik, tmp);

    /// Wczytujemy n wierszy labiryntu z pliku
    for(int i = 0; i < n; i++)
    {
        /// plik >> labirynt[i]; // To nie zadziala poprawnie
        /// Musimy wczytac cala linie
        getline(plik, labirynt[i]);
    }

    plik >> startK >> startW >> stopK >> stopW;

    /// Pamietamy o zamknieciu pliku
    plik.close();


    /// Wysiwetlamy wczytane dane na ekranie

    cout << "Wysokosc: " << n << endl;
    cout << "Szerokosc: " << m << endl;

    wyswietlLabirynt(labirynt, n, m);

    cout << "StartK: " << startK << ", StartW: " << startW << endl;
    cout << "StopK: " << stopK << ", StopW: " << stopW << endl;

    return 0;
}
```
{% endtab %}

{% tab title="labirynt.txt" %}
```
10 10
##########
#       ##
##  ######
##  ######
##  ######
##  ######
###     ##
####### ##
####    ##
##########
1 1
8 4
```
{% endtab %}
{% endtabs %}
