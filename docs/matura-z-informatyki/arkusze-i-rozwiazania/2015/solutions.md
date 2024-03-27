# Rozwiązania

## Część II

### Zadanie 4

#### Rozwiązanie C++

```cpp
#include <iostream>
#include <fstream>

using namespace std;

const int N = 1000;

int zliczZnak(string txt, char znak) {
    int wynik = 0;
    for(int i = 0; i < txt.size(); i++) {
        if(txt[i] == znak) {
            wynik++;
        }
    }

    return wynik;
}

int zad1(string dane[]) {
    int wynik = 0;
    for(int i = 0; i < N; i++) {
        if(zliczZnak(dane[i], '0') > (dane[i].size() / 2)) {
            wynik++;
        }
    }

    return wynik;
}

void wczytajDane(string dane[]) {
    ifstream danePlik("liczby.txt");

    for(int i = 0; i < N; i++) {
        danePlik >> dane[i];
    }

    danePlik.close();
}

int zad2PodzielnePrzez2(string dane[]) {
    int wynik = 0;
    for(int i = 0; i < N; i++) {
        if(dane[i][dane[i].size() - 1] == '0') {
            wynik++;
        }
    }

    return wynik;
}

int zad2PodzielnePrzez8(string dane[]) {
    int wynik = 0;
    for(int i = 0; i < N; i++) {
        if(dane[i].size() > 3 && dane[i].substr(dane[i].size() - 3, 3) == "000") {
            wynik++;
        }
        
    }

    return wynik;
}

int zad3Najmniejsza(string dane[]) {
    string minLiczba = dane[0];
    int minIndeks = 0;

    for(int i = 1; i < N; i++) {
        if((dane[i].size() < minLiczba.size()) || (dane[i].size() == minLiczba.size() && dane[i] < minLiczba)) {
            minLiczba = dane[i];
            minIndeks = i;
        }
    }

    return minIndeks + 1;
}

int zad3Najwieksza(string dane[]) {
    string maksLiczba = dane[0];
    int maksIndeks = 0;

    for(int i = 1; i < N; i++) {
        if((dane[i].size() > maksLiczba.size()) || (dane[i].size() == maksLiczba.size() && dane[i] > maksLiczba)) {
            maksLiczba = dane[i];
            maksIndeks = i;
        }
    }

    return maksIndeks + 1;
}

int main() {
    string binarna;
    string dane[N];
    ofstream wynikPlik("wynik4.txt");

    wczytajDane(dane);

    wynikPlik << "Zad 4.1" << endl;
    wynikPlik << zad1(dane) << endl << endl;

    wynikPlik << "Zad 4.2" << endl;
    wynikPlik << "Podzielne przez 2: " << zad2PodzielnePrzez2(dane) << endl;
    wynikPlik << "Podzielne przez 8: " << zad2PodzielnePrzez8(dane) << endl << endl;

    wynikPlik << "Zad4.3" << endl;
    wynikPlik << "Najmniejsza: " << zad3Najmniejsza(dane) << endl;
    wynikPlik << "Najwieksza: " << zad3Najwieksza(dane) << endl;
    
    wynikPlik.close();
    return 0;
} 
```

### Zadanie 5

[:material-microsoft-excel: Excel](../../../assets/2015_5.xlsx)

### Zadanie 6

[:material-microsoft-access: Access](../../../assets/2015_6.accdb)
