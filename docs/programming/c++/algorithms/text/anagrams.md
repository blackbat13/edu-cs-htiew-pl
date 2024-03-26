# Anagramy

## [Opis problemu](../../../../algorithms/text/anagrams.md)


## Implementacja

```cpp linenums="1"
#include <iostream>
#include <algorithm>

using namespace std;

bool areAnagrams(string a, string b) {
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    return a == b;
}

int main() {
    string a = "rokowanie";
    string b = "korowanie";

    bool result = areAnagrams(a, b); 

    if (result) {
        cout << a << " and " << b << " are anagrams." << endl;
    } else {
        cout << a << " and " << b << " aren't anagrams." << endl;
    }

    return 0;
}
```


### Opis implementacji

Funkcja `areAnagrams` (**linia 6**) sprawdza, czy dwa podane ciągi znaków są anagramami. Procedura jest prosta: najpierw sortujemy oba ciągi, wykorzystując do tego funkcję `sort` z biblioteki `algorithm` (**linie 7 i 8**). Następnie porównujemy posortowane ciągi znaków, zwracając w ten sposób wynik (**linia 9**).

W części głównej na początku definiujemy dane wejściowe (**linie 13-14**), a następnie wywołujemy funkcję `areAnagrams` (**linia 16**). W zależności od jej wyniku wypisujemy właściwy komunikat (**linie 18-22**). Na końcu kończymy działanie programu (**linia 24**).
