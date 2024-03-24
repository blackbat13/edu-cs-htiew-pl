# Kolejka

## Opis

Kolejka to jedna z klasycznych struktur danych. 
Wykorzystywana jest w wielu algorytmach, nic dziwnego więc, że jej implementacja znajduje się także w STL.

### Biblioteka

Kolejka znajduje się w bibliotece `queue`.

```cpp
#include <queue>
```

### Dokumentacja

{% embed url="https://www.cplusplus.com/reference/queue/queue/" %}
Queue Reference
{% endembed %}

## Implementacja: przykłady

Kilka przykładów pokazujących, jak korzystać z klasy `stack`.

### Utworzenie pustej kolejki

```cpp
queue<int> qu;
```

### Dodanie elementu na koniec kolejki

```cpp
qu.push(5);
```

### Pobranie elementu z początku kolejki

```cpp
int el;

el = qu.front();
```

### Usunięcie elementu z początku kolejki

```cpp
qu.pop();
```

### Wypisanie rozmiaru kolejki

```cpp
cout << "Size of the queue: " << qu.size() << endl;
```

### Wyczyszczenie kolejki

```cpp
qu = queue<int>();
```

### Sprawdzenie, czy kolejka jest pusta

```cpp
if (qu.empty()) {
    cout << "Queue is empty" << endl;
} else {
    cout << "Queue is not empty" << endl;
}
```

## Przykładowa implementacja

```cpp
#include <iostream>
#include <queue>

using namespace std;

int main() {
    cout << "Create queue containing values of type int" << endl;
    // We can create empty queue writing: queue<elements_type> variable_name;
    queue<int> qu;

    // To get current size of the queue (number of elements in it) we use "size" method
    cout << "Size of the queue: " << qu.size() << endl;

    cout << endl << "Add new elements to the end of the queue" << endl;
    // To add new elements to the queue we use "push" method
    // This places new element passed as a parameter at the end of the queue
    qu.push(5);
    qu.push(-50);
    qu.push(25);
    qu.push(120);

    cout << "Size of the queue: " << qu.size() << endl;

    // To get value of the first element in the queue we use "front" method
    // This method does not remove element from the queue
    cout << endl << "First element of the queue: " << qu.front() << endl;
    cout << "Removing top element from the queue" << endl;
    // To remove top element of the queue (from the first position) we use "pop" method
    // This method only removes the first element without returning its value
    qu.pop();
    cout << "First element of the queue: " << qu.front() << endl;
    cout << "Size of the queue: " << qu.size() << endl;

    // To get value of the last element in the queue we use "back" method
    // This method does not remove element from the queue
    cout << endl << "Last element of the queue: " << qu.back() << endl;

    cout << endl << "Clearing queue by assigning new value to it" << endl;
    qu = queue<int>();

    cout << "Size of the queue: " << qu.size() << endl;

    cout << endl << "Checking if queue is empty" << endl;
    // To check if queue is empty (its size is equal to zero) we can use "empty" method
    // This method returns true if queue is empty, false otherwise
    if (qu.empty()) {
        cout << "Queue is empty" << endl;
    } else {
        cout << "Queue is not empty" << endl;
    }

    return 0;
}
```

### Link do implementacji

{% embed url="https://ideone.com/xR1i8c" %}
queue - przykłady
{% endembed %}

## Kolejka priorytetowa

Poza standardową kolejką w STL znajdziemy także kolejkę priorytetową.
Korzystamy z niej praktycznie tak samo jak ze zwykłej kolejki.
Różnica oczywiście tkwi w kolejności elementów pobieranych z kolejki, a także w nazwie klasy.

### Biblioteka

Aby korzystać z kolejki priorytetowej potrzebujemy biblioteki `priority_queue`.

```cpp
#include <priority_queue>
```

### Dokumentacja

{% embed url="https://www.cplusplus.com/reference/queue/priority_queue/" %}
Priority Queue Reference
{% endembed %}