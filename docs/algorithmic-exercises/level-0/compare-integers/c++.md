# C++

```cpp linenums="1"
#include <iostream>

using namespace std;

int main() {
    int a, b;
    
    cout << "Podaj a:" << endl;
    cin >> a;
    
    cout << "Podaj b:" << endl;
    cin >> b;
    
    if (a == b) {
        cout << "=" << endl;
    } else if (a < b) {
        cout << "<" << endl;
    } else {
        cout << ">" << endl;
    }

    return 0;
}
```

## Opis implementacji

Na początku deklarujemy dwie zmienne całkowite `a` i `b` do przechowywania danych wejściowych (**linia 5**). Następnie wczytujemy dwie wartości od użytkownika (**linie 7-11**), podając przy tym stosowane komunikaty.

Następnie, korzystając z instrukcji warunkowej, sprawdzamy relację pomiędzy wczytanymi wartościami. Jeżeli wartości zmiennych `a` i `b` są sobie równe (**linia 13**) to wypisujemy znak równości (**linia 14**). W przeciwnym przypadku, jeżeli wartość zmiennej `a` jest mniejsza od wartości zmiennej `b` (**linia 15**), to wypisujemy znak mniejszości (**linia 16**). W przeciwnym przypadku (**linia 17**) wypisujemy znak większości (**linia 18**).

Zwróć uwagę na to, że w ostatniej części instrukcji warunkowej (**linia 17**), nie musimy już sprawdzać, czy wartość zmiennej `a` jest większa od wartości zmiennej `b`. Wynika to z poprzednich warunków. Jeżeli wartości zmiennych nie są sobie równe ani też `a` nie jest mniejsze od `b`, to wiemy, że `a` jest większe od `b`.
