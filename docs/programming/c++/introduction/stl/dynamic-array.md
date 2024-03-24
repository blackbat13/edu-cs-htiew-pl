# Tablice dynamiczne

## Opis

Co oznacza, że tablica jest **dynamiczna**? To znaczy, że w dowolnym momencie działania programu możemy zmieniać jej rozmiar, tzn. dodawać i usuwać elementy (w przeciwieństwie do tablic **statycznych**). Jest to przydatne np. w sytuacji gdy nie wiemy, ile wartości będziemy musieli w takiej tablicy przechować.

W STL mamy dwie podstawowe klasy implementujące tablice dynamiczne: `vector` oraz `deque`. W założeniach są do siebie bardzo zbliżone. Podstawowa różnica jest taka, że `vector` jest jednokierunkowy, a `deque` dwukierunkowy. Co to oznacza w praktyce? Do tablic typu `vector` możemy _tanio_ dodawać i usuwać elementy od końca. Do `deque` możemy natomiast dodawać i usuwać elementy zarówno z końca jak i z początku.

W poniższych przykładach wykorzystujemy `vector`, jednak można go spokojnie zastąpić klasą `deque` i wszystko będzie działać tak samo.

### Biblioteka

Do klasy `vector` potrzebujemy biblioteki `vector`, a do klasy `deque` potrzebujemy biblioteki `deque`.

```cpp
#include <vector>
#include <deque>

using namespace std;
```

### Dokumentacja

#### Vector

{% embed url="https://www.cplusplus.com/reference/vector/vector/" %}
Vector Reference
{% endembed %}

#### Deque

{% embed url="https://www.cplusplus.com/reference/deque/deque/" %}
Deque Reference
{% endembed %}

## Implementacja: przykłady

### Utworzenie pustej tablicy

```cpp
vector<int> array;
```

### Utworzenie tablicy o zadanej długości

```cpp
vector<int> array(10);
```

Tablica zostanie wypełniona wartościami domyślnymi dla danego typu, np. dla typu `int` jest to $$0$$.

### Utworzenie tablicy wypełnionej zadaną wartością

```cpp
vector<int> array(10, -1);
```

Tablica zostanie wypełniona wartościami $$-1$$.

### Wypisanie wybranego elementu tablicy

```cpp
cout << "4-th element of the array is: " << array[3] << endl;
```

Tak jak i w przypadku tablic statycznych, elementy indeksujemy od $$0$$.

### Wypisanie długości tablicy

```cpp
cout << "Size of the array is: " << array.size() << endl;
```

### Dodanie nowego elementu na koniec tablicy

```cpp
array.push_back(55);
```

### Dodanie nowego elementu na początek tablicy (tylko deque)

```cpp
array.push_front(55);
```

### Usunięcie ostatniego elementu tablicy

```cpp
array.pop_back();
```

### Usunięcie pierwszego elementu tablicy (tylko deque)

```cpp
array.pop_front();
```

### Usunięcie elementu pod zadanym indeksem

```cpp
array.erase(array.begin() + 5);
```

### Usunięcie fragmentu tablicy

```cpp
array.erase(array.begin() + 5, array.begin() + 7);
```

Po wykonaniu powyższej operacji zostaną usunięte elementy pod indeksami $$5$$ oraz $$6$$ (bez elementu na pozycji $$7$$).

### Zmiana rozmiaru tablicy

```cpp
array.resize(20);
```

Jeżeli tablica była mniejsza, to nowe pozycje zostaną wypełnione domyślnymi wartościami.

### Zmiana rozmiaru tablicy i wybrana wartość

```cpp
array.resize(30, -1);
```

Jeżeli tablica była mniejsza, to nowe pozycje zostaną wypełnione wartością $$-1$$.

### Sprawdzenie, czy tablica jest pusta

```cpp
if(array.empty()) {
    cout << "Array is empty" << endl;
} else {
    cout << "Array is not empty" << endl;
}
```

### Wyczyszczenie tablicy

```cpp
array.clear();
```

### Wypisanie wszystkich elementów tablicy

```cpp
for(auto el: array) {
    cout << el << endl;
}
```

## Przykładowa implementacja

```cpp
#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Creating empty vector containing integers
    vector<int> array;
    // Creating vector containing 10 elements of type integer with default value for that type - 0
    vector<int> array2(10);

    cout << "Element 0 of array2 is: " << array2[0] << endl;

    // Creating vector containing 10 elements of type integer with value 23
    vector<int> array3(10, 23);

    cout << "Element 0 of array3 is: " << array3[0] << endl;

    // We can also achieve similar behaviour by setting value for existing variable
    array = vector<int>(10, 23);
    cout << "Element 0 of array is: " << array[0] << endl;

    // Checking size of the array
    cout << "Size of the array is: " << array.size() << endl;

    // Adding new element to the end of the array
    array.push_back(55);
    cout << "Last element of array is: " << array[array.size() - 1] << endl;
    cout << "Size of the array is: " << array.size() << endl;

    // Adding new element at the position 5 in the array
    array.insert(array.begin() + 5, 60);
    cout << "Element 5 of array is: " << array[5] << endl;
    cout << "Size of the array is: " << array.size() << endl;

    // Deleting last element in the array
    array.pop_back();
    cout << "Size of the array is: " << array.size() << endl;

    // Deleting element at the position 5
    array.erase(array.begin() + 5);
    cout << "Element 5 of array is: " << array[5] << endl;
    cout << "Size of the array is: " << array.size() << endl;

    // Deleting elements in the array from index 5 to 7, not including 7
    array.erase(array.begin() + 5, array.begin() + 7);
    cout << "Size of the array is: " << array.size() << endl;

    // Resizing array to size 20, filling new elements with default value
    array.resize(20);
    cout << "Element 19 of the array is: " << array[19] << endl;
    cout << "Size of the array is: " << array.size() << endl;

    // Resizing array to size 30, filling new elements with the value 41
    array.resize(30, 41);
    cout << "Element 29 of the array is: " << array[29] << endl;
    cout << "Size of the array is: " << array.size() << endl;

    // Checking if the array is empty
    if(array.empty()) {
        cout << "Array is empty" << endl;
    } else {
        cout << "Array is not empty" << endl;
    }
    
    cout << "Content of the array: ";
    // Printing content of the array
    for(auto el: array) {
        cout << el << " ";
    }
    
    cout << endl;

    // Clearing array removing all of its content
    array.clear();
    cout << "Size of the array is: " << array.size() << endl;

    return 0;
}
```

### Link do implementacji

{% embed url="https://ideone.com/6qwyfQ" %}
vector - przykłady
{% endembed %}
