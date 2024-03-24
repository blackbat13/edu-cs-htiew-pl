# Sortowanie

## Opis

Sortowanie danych jest operacją, z której korzystamy praktycznie na co dzień. 
Jest to także operacja, która jest wymagana w wielu algorytmach. 
Nie od dziś wiadomo, że na danych posortowanych pewne działania można wykonać znacznie efektywniej. 
Od wydajności algorytmu sortowania może więc zależeć wydajność całej implementacji. 
Oczywiście możemy za każdym razem implementować sortowanie samodzielnie (tak czasem będzie wydajniej), ale zazwyczaj wystarczy skorzystać z gotowej implementacji zawartej w STL, a konkretnie w bibliotece `algorithm`. 

### Biblioteka

Funkcja sortująca (a także wiele innych) znajduje się w bibliotece `algorithm`.

```cpp
#include <algorithm>
```

## Przykład

Poniższa implementacja pokazuje przykładowe wykorzystanie funkcji `sort` z biblioteki `algorithm`.

### Implementacja

```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/// Prints content of the vector
/// \param array - vector to prints content of
void printVector(vector<int> array) {
    for (int el : array) {
        cout << el << " ";
    }

    cout << endl;
}

/// Compute absolute value of given integer
/// \param a - integer to compute an absolute value of
/// \return Absolute value of a
int abs(int a) {
    if (a < 0) {
        return -a;
    } else {
        return a;
    }
}

/// Compare two elements using their absolute values
/// \param a - first value
/// \param b - second value
/// \result true if absolute value of a is lower than absolute value of b, false otherwise
bool compare(int a, int b) {
    return abs(a) < abs(b);
}

int main() {
    vector<int> array;
    array.push_back(5);
    array.push_back(-2);
    array.push_back(-6);
    array.push_back(12);
    array.push_back(0);

    cout << "Sorting array in ascending order" << endl;
    sort(array.begin(), array.end());
    printVector(array);

    cout << "Sorting array in descending order" << endl;
    sort(array.rbegin(), array.rend());
    printVector(array);

    cout << "Sorting array using custom comparing function" << endl;
    sort(array.begin(), array.end(), compare);
    printVector(array);

    return 0;
}
```

### Link do implementacji

{% embed url="https://ideone.com/X1NpNn" %}
Sortowanie z STL - przykład
{% endembed %}

### Opis implementacji

Na początku tworzymy nowy `vector` o nazwie `array` (**linia 37**), który służy nam za tablicę do posortowania. Następnie sortujemy tablicę rosnąco, wykorzystując do tego funkcję `sort` zawartą w bibliotece `algorithm`. Jako argumenty do funkcji podajemy wskaźniki na początek i koniec sortowanego zakresu (**linia 45**). Podany przedział jest prawostronnie otwarty. Po posortowaniu tablicy wypisujemy ją korzystając z pomocniczej funkcji `printVector`.

W celu posortowania tablicy malejąco, możemy skorzystać z odwróconych wskaźników (_reverse iterator_) (**linia 49**).

Możemy także skorzystać z własnej funkcji porównującej. Funkcja ta powinna przyjmować dwa argumenty o typie zgodnym z typem elementów przechowywanych w tablicy. Funkcja powinna zwracać wynik typu `bool` określający, czy elementy podane jako argumenty znajdują się we właściwym porządku (wynik `true`), czy też nie (wynik `false`). Przykład takiej funkcji porównującej stanowi powyższa funkcja `compare` (**linia 32**), która porównuje elementy po ich wartości bezwzględnej.

W celu skorzystania z własnej funkcji porównującej, podajemy ją jako trzeci argument przy wywołaniu funkcji `sort` (**linia 53**).
