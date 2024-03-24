# Pętla iteracyjna

W języku C++ pętla iteracyjna składa się z trzech części:

1. Inicjalizacji licznika pętli (np. `int i = 0`).
2. Warunku pętli (np. `i < 10`).
3. Kroku pętli (np. `i++`).

## Przykłady

### Prosta pętla iteracyjna

Dziesięć razy wypisujemy napis `Hello World!`

```cpp
for (int i = 0; i < 10; i++) {
        cout << "Hello World!" << endl;
}
```

### Wypisanie licznika pętli

```cpp
for (int i = 0; i < 10; i++) {
        cout << i << endl;
}
```

### Inne parametry

Parametry pętli możemy dowolnie zmieniać, by dostosować je do naszych potrzeb.

```cpp
for (int i = 2; i <= 5; i++) {
        cout << i << endl;
}
```

### Krok pętli

Często wygodnym rozwiązaniem jest modyfikacja kroku pętli. Np. jeżeli chcemy wypisać tylko liczby parzyste z zakresu \[0,10) to możemy w każdym kroku zwiększać licznik o 2, zamiast standardowo o 1.

```cpp
for (int i = 0; i < 10; i += 2) {
        cout << i << endl;
}
```

### Pętla malejąca

Często korzystamy z pętli rosnącej. Nic nie stoi jednak na przeszkodzie, aby wykorzystać pętlę malejącą. W tym celu zmieniamy parametry pętli, a przede wszystkim jej krok.

```cpp
for (int i = 10; i >= 0; i--) {
        cout << i << endl;
}
```

### Istniejący licznik

Nie musimy deklarować nowej zmiennej w formie licznika pętli. Możemy skorzystać z już istniejącej zmiennej.

```cpp
int i;
for (i = 0; i < 10; i++) {
    cout << i << endl;
}
```

## Pełna implementacja

```cpp
#include <iostream>

using namespace std;

int main() {
    cout << "Prosta petla for wykonujaca 10 powtorzen" << endl;
    for (int i = 0; i < 10; i++) {
        cout << "Hello World!" << endl;
    }

    cout << endl;
    cout << "Idziemy od 0 do 9 wlacznie. Po kazdym kroku petli zwiekszamy licznik petli (i) o 1" << endl;
    cout << "Petla wykonuje sie tak dlugo, jak spelniony jest podany warunekm tzn. dopoki i < 10" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i << endl;
    }

    cout << endl;
    cout << "Mozemy zmienic poczatkowa wartosc licznika, a takze warunek petli" << endl;
    for (int i = 2; i <= 5; i++) {
        cout << i << endl;
    }

    cout << endl;
    cout << "Mozemy takze modyfikowac krok petli" << endl;
    for (int i = 0; i < 10; i += 2) {
        cout << i << endl;
    }

    cout << endl;
    cout << "Iteracja od 10 do 0 takze jest proste. Wystarczy zmniejszac licznik petli po kazdym kroku" << endl;
    for (int i = 10; i >= 0; i--) {
        cout << i << endl;
    }

    int i;
    cout << endl;
    cout << "Mozemy takze wykorzystac istniejaca zmienna w roli licznika petli" << endl;
    for (i = 0; i < 10; i++) {
        cout << i << endl;
    }

    return 0;
}
```
