# Rozwiązanie 1

## Treść zadania

Napisz program zgodny z poniższą specyfikacją. W implementacji wykorzystaj klasę `map`.

### Specyfikacja

#### Dane

* $$txt$$ - Wielolinijkowy tekst składający się ze znaków ze standardowej tablicy ASCII, zakończony znakiem końca wyjścia.

#### Wynik

* Dla każdego znaku, jaki pojawił się na wejściu, liczba jego wystąpień. Znaki uporządkowane alfabetycznie, zgodnie z kolejnością w tablicy ASCII.

## Rozwiązanie

```cpp
#include <iostream>
#include <map>

using namespace std;

int main() {
    string txt;
    map<string, int> charCounter;

    while(getline(cin, txt) && !cin.eof()) {
        for(auto ch : txt) {
            charCounter[ch]++;
        }
    }

    for(auto el : charCounter) {
        cout << el.first << " - " << el.second << endl;
    }

    return 0;
}
```