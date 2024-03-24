# Robot w labiryncie

Prosta symulacja robota poruszającego się po labiryncie.

Użytkownik wydaje polecenia `W`, `S`, `A`lub `D`, a robot przemieszcza się po labiryncie zgodnie z wybranym kierunkiem ruchu.

```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    int n = 5; /// Labirynt ma wymiar n x n
	  char polecenie;
	  int robotW, robotK; /// Wiersz i kolumna robota - jego pozycja
    string labirynt[5];

    labirynt[0] = "#####";
    labirynt[1] = "#   #";
    labirynt[2] = "# # #";
    labirynt[3] = "# # #";
    labirynt[4] = "#####";

    robotW = 3;
    robotK = 1;

    while(true)
    {
        system("cls");

        /// Wyswietlamy labirynt na ekranie
        for(int w = 0; w < n; w++)
        {
            for(int k = 0; k < n; k++)
            {
                /// Jezeli w i k sa pozycjami robota, to wypisz @
                /// W przeciwnym przypadku wypisz znak z labiryntu
                if(w == robotW && k == robotK)
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

        cin >> polecenie;

        switch(polecenie)
        {
        case 'a':
            if(labirynt[robotW][robotK - 1] != '#')   /// Jezeli pod nowym miejscem nie ma sciany
            {
                robotK--; /// Przemieszczamy robota w lewo
            }

            break;
        case 'd':
            if(labirynt[robotW][robotK + 1] != '#')   /// Jezeli pod nowym miejscem nie ma sciany
            {
                robotK++; /// Przemieszczamy robota w lewo
            }

            break;
        case 'w':
            if(labirynt[robotW-1][robotK] != '#')   /// Jezeli pod nowym miejscem nie ma sciany
            {
                robotW--; /// Przemieszczamy robota w lewo
            }

            break;
        case 's':
            if(labirynt[robotW+1][robotK] != '#')   /// Jezeli pod nowym miejscem nie ma sciany
            {
                robotW++; /// Przemieszczamy robota w lewo
            }

            break;
        case 'q':
            return 0;
        }
    }
	
    return 0;
}
```

### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/Robot#main.cpp" %}

### Opis implementacji

TODO

{% hint style="warning" %}
Pod systemem Linux zamiast polecenia **cls** używamy polecenia **clear** do wyczyszczenia ekranu terminala.
{% endhint %}
