# C++

## Implementacja

```cpp
#include <iostream>
#include "maja.h"

void resetuj(bool kandydaci[]) {
    for(int i = 0; i <= 1000000; i++) {
        kandydaci[i] = true;
    }
}

void odznaczNiep(bool kandydaci[], int wiel) {
    for(int i = wiel; i <= 1000000; i += wiel) {
        kandydaci[i] = false;
    }
}

void odznaczPodz(bool kandydaci[], int wiel) {
    for(int i = 1; i <= 1000000; i++) {
        if(i % wiel != 0) {
            kandydaci[i] = false;
        } 
    }
}

int main() {
    int n;
    bool kandydaci[1000001];

    n = gramy_dalej();
    
    while(n != 0) {
        resetuj(kandydaci);

        for(int i = 2; i <= n; i++) {
            if(kandydaci[i]) {
                if(!czy_podzielna_przez(i)) {
                    odznaczNiep(kandydaci, i);
                } else {
                    odznaczPodz(kandydaci, i);
                }
            }
        }
        
        for(int i = 1; i <= n; i++) {
            if(kandydaci[i]) {
                zgaduj(i);
                break;
            }
        }
        

        n = gramy_dalej();
    }

    
    return 0;
}
```

## Opis

Funkcja `resetuj` wypełnia tablicę `kandydaci` wartościami `true`.

Funkcja `odznaczNiep` skreśla z tablicy wszystkie wielokrotności podanej wartości `wiel`.

Funkcja `odznaczPodz` skreśla z tablicy wszystkie liczby, które nie są wielokrotnością podanej wartości `wiel`.

W tablicy `kandydaci` przechowujemy informacje na temat potencjalnych wartości, o których mogła pomyśleć Maja.
Jeżeli pod indeksem $i$ w tablicy znajduje się wartość `true`, to znaczy że liczba $i$ może wciąż być prawidłową odpowiedzią.
Jeżeli natomiast pod indeksem $i$ znajduje się wartość `false`, oznacza to, że liczba $i$ została skreślona, więc wiemy już, że nie jest prawidłową odpowiedzią.

Na początku działania programu wywołujemy funkcję `gramy_dalej`, której wynik zapisujemy w zmiennej `n`, w ten sposób poznając górne ograniczenie dla zgadywanej wartości. Następnie w pętli powtarzamy operacje tak długo, aż otrzymamy $n=0$, co oznacza koniec danych wejściowych.
Na początku pętli, przed przystąpieniem do odpytywania o podzielność, resetujemy tablicę kandydatów (**linia 31**), korzystając z pomocniczej funkcji `resetuj`. Następnie przechodzimy przez wszystkie wartości od $2$ do górnego ograniczenia przedziału $n$ włącznie (**linia 33**).
Dla każdej wartości sprawdzamy, czy nie została ona jeszcze skreślona w tablicy kandydatów, to znaczy czy może być poprawną odpowiedzią (**linia 34**).
Jeżeli tak jest, to odpytujemy o podzielność przez tę właśnie liczbę za pomocą funkcji `czy_podzielna_przez` (**linia 35**). 
Jeżeli szukana liczba nie jest podzielna przez $i$ to w tablicy kandydatów skreślamy wszystkie wielokrotności $i$ (**linia 36**) korzystając z pomocniczej funkcji `odznaczNiep`.
W przeciwnym przypadku, tzn. gdy szukana wartość jest podzielna przez $i$ to skreślamy wszystkie wartości niepodzielne przez $i$ (**linia 38**) za pomocą pomocniczej funkcji `odznaczPodz`.

Gdy już przejdziemy przez wszystkie wartości ze sprawdzanego zakresu i zadamy wszystkie sensowne pytania o podzielność, możemy przystąpić do odgadnięcia szukanej liczby. W tym celu musimy znaleźć w tablicy kandydatów wartość, która nie została jeszcze skreślona. Przechodzimy więc pętlą przez wszystkie potencjalne wartości od $1$ do $n$ włącznie (**linia 43**) i dla każdej sprawdzamy, czy nie została ona skreślona (**linia 44**).
Gdy znajdziemy taką wartość, dokonujemy próby odgadnięcia (**linia 45**) i wychodzimy z pętli (** linia 46**).

Na koniec rozpoczynamy kolejną rozgrywkę za pomocą funkcji `gramy_dalej` pobierając górne ograniczenie przedziału (**linia 51**).