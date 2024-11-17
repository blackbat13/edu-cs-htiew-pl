# Znajdowanie lidera w zbiorze

## [:link: Opis problemu](../../../../algorithms/searching/majority.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

int countOccurences(int number, int array[], int length) {
    int result = 0;

    for (int i = 0; i < length; i++) {
        if (array[i] == number) {
            result++;
        }
    }

    return result;
}

int findMajority(int array[], int length) {
    int counter = 1;
    int currentCandidate = array[0];
    
    for (int i = 1; i < length; i++) {
        if (counter == 0) {
            currentCandidate = array[i];
            counter = 1;
        } else if (array[i] == currentCandidate) {
            counter++;
        } else {
            counter--;
        }
    }

    counter = countOccurences(currentCandidate, array, length);

    if (counter > length / 2) {
        return currentCandidate;
    } else {
        return -1;
    }
}

int main() {
    int array[10] = {1, 2, 5, 5, 7, 5, 5, 10, 5, 5};

    int majority = findMajority(array, 10);

    cout << majority << endl;

    return 0;
}
```

### Opis implementacji

#### Funkcja `countOccurences`

- **Parametry**: 
  - `number` (liczba, której wystąpienia liczymy),
  - `array` (tablica, w której szukamy),
  - `length` (długość tablicy).
- **Działanie**: Przechodzi przez tablicę i liczy, ile razy `number` występuje w tablicy.
- **Zwraca**: Liczbę wystąpień `number` w tablicy.

#### Funkcja `findMajority`

- **Parametry**: 
  - `array` (tablica, w której szukamy elementu większościowego,
  - `length` (długość tablicy).
- **Działanie**:
  - Używa algorytmu Boyera-Moore'a do znalezienia potencjalnego elementu większościowego.
  - Przechodzi przez tablicę, aktualizując `currentCandidate` (obecny kandydat na element większościowy) i `counter` (licznik wystąpień kandydata).
  - Po przejściu przez tablicę, sprawdza, czy `currentCandidate` faktycznie jest elementem większościowym, licząc jego wystąpienia za pomocą `countOccurences`.
- **Zwraca**: Element większościowy, jeśli istnieje, w przeciwnym razie $-1$.

#### Funkcja `main`

- Tworzy tablicę array z $10$ elementami.
- Wywołuje funkcję `findMajority`, aby znaleźć element większościowy w tablicy.
- Wypisuje wynik na standardowe wyjście.
- Przykładowe dane wejściowe: $[1, 2, 5, 5, 7, 5, 5, 10, 5, 5]$. 
- Oczekiwany wynik: $5$, ponieważ liczba $5$ występuje $6$ razy, co jest więcej niż połowa długości tablicy ($5$).
