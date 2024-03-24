# Wskaźniki

W języku C++ wskaźniki pozwalają na przechowywanie adresów zmiennych. Wskaźnik to typ danych, który przechowuje adres pamięci, gdzie zapisane są jakieś dane, np. inna zmienna. Wskaźnik może być użyty do przechowywania adresu zmiennej, aby móc na nim wykonywać operacje takie jak odczytanie lub zapisanie wartości.

## Wskaźniki do zmiennych

Zacznijmy od prostego przykładu, w którym wskaźnik będzie wskazywał na inną zmienną.

```cpp
#include <iostream>

using namespace std;

int main() {
    int x = 10;
    int *ptr = &x;
    
    cout << "Wartosc zmiennej x: " << x << endl;
    cout << "Wartosc zmiennej x, przechowywana w wskazniku: " << *ptr << endl;

    cout << "Adres zmiennej x: " << &x << endl;
    cout << "Adres zmiennej x, przechowywany w wskazniku: " << ptr << endl;
    
    return 0;
}
```

Jak widać w powyższym przykładzie, w celu utworzenia wskaźnika typu `int`, należy przed nazwą zmiennej wskaźnikowej postawić gwiazdkę (`*`). Aby wskaźnik wskazywał na daną zmienną, musimy do niego przypisać adres tej zmiennej. Adres zmiennej pobieramy za pomocą operatora adresowego (`&`).

Warto zauważyć, że wskaźnik przechowuje adres zmiennej, a nie jej wartość. Aby odczytać wartość zmiennej, należy użyć operatora dereferencji (`*`).

## Wskaźniki do tablic

W C++, wskaźniki można użyć do przechowywania adresów elementów tablic. Nie musimy jednak tworzyć wskaźników dla każdego elementu tablicy, ponieważ możemy użyć jednego wskaźnika dla całej tablicy. W tym celu ustawiamy wskaźnik na adres pierwszego elementu w tablicy.

```cpp
#include <iostream>

using namespace std;

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int *ptr = arr;

    for (int i = 0; i < 5; i++) {
        cout << *ptr << " ";
        ptr++; 
    }

    return 0;
}
```

W powyższym przykładzie, wskaźnik `ptr` przechowuje adres pierwszego elementu tablicy `arr`. Następnie, za pomocą pętli, wypisujemy wartości zmiennej, która jest adresem elementu tablicy. Na końcu każdego obrotu pętli wskaźnik przechodzi do następnego elementu tablicy.

Wskaźnika do tablicy możemy także użyć w celu przekazania tablicy do funkcji. W tym celu należy przekazać adres pierwszego elementu tablicy do funkcji.

```cpp
#include <iostream>

using namespace std;

void printNumbers(int *ptr, int size) {
    for (int i = 0; i < size; i++) {
        cout << *ptr << " ";
        ptr++;
    }
}

int main() {
    int numbers[] = {1, 2, 3, 4, 5};
    int *ptr = numbers; // Ustawienie wskaźnika na pierwszy element tablicy

    printNumbers(ptr, 5);

    return 0;
}
```

W tym przykładzie, wskaźnik `ptr` przechowuje adres pierwszego elementu tablicy `numbers`. Funkcja `printNumbers` używa tego wskaźnika do wypisywania wartości z tablicy.

## Dynamiczna alokacja pamięci

W C++, dynamiczna alokacja pamięci pozwala na dynamiczne zarządzanie pamięcią w czasie działania programu. Możemy za pomocą funkcji `new` alokować nowe bloki pamięci, a następnie za pomocą operatora `delete` zwolnić pamięć.

```cpp
int *ptr = new int; // Alokacja nowego bloku pamięci o rozmiarze int
*ptr = 10; // Przypisanie wartości do zmiennej, która jest adresem pierwszego elementu bloku pamięci

delete ptr; // Zwolnienie bloku pamięci
ptr = nullptr; // Przypisanie wskaźnikowi null, aby upewnić się, że nie będzie wykorzystywany
```

W tym przykładzie, za pomocą operatora `new` alokujemy nowy blok pamięci o rozmiarze `int`, a następnie przypisujemy wartość 10 do zmiennej, która jest adresem pierwszego elementu bloku pamięci. Na koniec, za pomocą operatora `delete` zwalniamy blok pamięci i przypisujemy do wskaźnika wartość pustą, co jest dobrą praktyką w kontekście bardziej rozbudowanych programów, ponieważ później możemy łatwo sprawdzić za pomocą prostego warunku, czy wskaźnik jest zainicjowany.

## Wyciek pamięci

Gdy sami alokujemy nowy blok pamięci, należy pamiętać, że powinniśmy ten blok także sami zwolnić. Jeżeli tego nie zrobimy, a przypiszemy wskaźnik do nowego bloku pamięci, to zostawiamy w pamięci stary blok, do którego nie mamy już odwołania i nie mamy możliwości go zwolnić. W ten sposób nasz program może zużywać znacznie więcej pamięci, niż powinien. Dlatego bardzo ważne jest zwalnianie dynamicznie alokowanej pamięci.

Poniższy przykład pokazuje, co może się wydarzyć, gdy będziemy alokować nowe bloki w pamięci bez zwalniania poprzednich. 

{% hint style="warning" %}
**Uwaga**

Przed uruchomieniem programu na swoim komputerze upewnij się, że nie utracisz danych, jeżeli będzie potrzeba zrestartować system.
{% endhint %}

```cpp
#include <iostream>

using namespace std;

int main() {
    int *ptr;
    while(true) {
        ptr = new int;
    }
}
```

## Tablice dynamiczne

W C++, tablice dynamiczne są tablicami, które mogą rozszerzać się w czasie działania programu. Możemy za pomocą funkcji `new` alokować nowe bloki pamięci, a następnie za pomocą operatora `delete` zwolnić pamięć.

```cpp
int *ptr = new int[5]; // Alokacja nowej tablicy o rozmiarze 5

delete[] ptr; // Zwolnienie tablicy
ptr = nullptr; // Przypisanie wskaźnikowi null, aby upewnić się, że nie będzie wykorzystywany
```

W tym przykładzie, za pomocą operatora `new` alokujemy nową tablicę o rozmiarze 5, a następnie za pomocą operatora `delete[]` zwalniamy tablicę i podobnie jak wcześniej przypisujemy do wskaźnika wartość null.

Jeżeli chcielibyśmy zwiększyć rozmiar naszej tablicy, należy najpierw zaalokować tablicę o większym rozmiarze, a następnie skopiować zawartość tablicy do nowej tablicy. Na koniec możemy zwolnić poprzednią tablicę i zapamiętać wskaźnik do nowej tablicy.

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int *ptr = new int[5]; // Alokacja tablicy o rozmiarze 5
    int *tmp = new int[10]; // Alokacja tablicy o rozmiarze 10

    copy(ptr, ptr + 5, tmp); // Skopiowanie zawartości tablicy do nowej tablicy

    delete[] ptr; // Zwolnienie poprzedniej tablicy

    ptr = tmp; // Zapamiętanie wskaźnika do nowej tablicy

    return 0;
}
```

W tym przykładzie, najpierw alokujemy tablicę o rozmiarze 5, a następnie większą tablicę o rozmiarze 10. W kolejnym kroku kopiujemy zawartość tablicy o rozmiarze 5 do nowej tablicy o rozmiarze 10 korzystając z funkcji `copy` znajdującej się w bibliotece *algorithm*. Na końcu zwalniamy tablicę o rozmiarze 5 i zapamiętujemy wskaźnik do nowej tablicy. Zwróćmy uwagę na to, że nie możemy zwolnić wskaźnika kryjącego się pod zmienną `tmp`, ponieważ pod tym adresem kryje się już nowa tablica, wskazywana także przez wskaźnik `ptr`.

## Wskaźniki do wskaźników

W C++, wskaźniki do wskaźników pozwalają na tworzenie hierarchii wskaźników. Wskaźnik do wskaźnika to specialny wskaźnik, który przechowuje adres innego wskaźnika. Wskaźnik do wskaźnika może być użyty do przechowywania wskaźników do innych struktur danych, takich jak tablice, kontenery czy listy.

```cpp
int **ptr_to_ptr = new int*; // Alokacja nowego bloku pamięci o rozmiarze int*
int *ptr = new int; // Alokacja nowego bloku pamięci o rozmiarze int

*ptr = 10; // Przypisanie wartości do zmiennej, która jest adresem pierwsego elementu bloku pamięci
*ptr_to_ptr = ptr; // Przypisanie adresu do wskaźnika do wskaźnika

delete ptr; // Zwolnienie bloku pamięci
ptr = nullptr; // Ustawienie wskaźnika na nullptr

delete ptr_to_ptr; // Zwolnienie bloku pamięci
ptr_to_ptr = nullptr; // Ustawienie wskaźnika do wskaźnika na nullptr
```

W tym przykładzie, za pomocą operatora `new` alokujemy nowy blok pamięci o rozmiarze int*, a następnie alokujemy nowy blok pamięci o rozmiarze int. Następnie przypisujemy wartość 10 do zmiennej, która jest adresem pierwszego elementu bloku pamięci. Na koniec, przypisujemy adres tej zmiennej do wskaźnika do wskaźnika.

Wywołanie funkcji `delete` na wskaźniku do wskaźnika zwolni wszystkie bloki pamięci, które były alokowane za pomocą operatora `new`.

W ten sposób, wskaźnik do wskaźnika pozwala na tworzenie hierarchii wskaźników, co może być użyte do przechowywania wskaźników do innych struktur danych.

## Wskaźniki do funkcji

W C++, wskaźniki do funkcji mogą być używane do przechowywania adresów funkcji. Niektóre funkcje mogą być przekazywane do innych funkcji jako parametry, a następnie wywoływane z użyciem wskaźników do funkcji.

```cpp
#include <iostream>

using namespace std;

void print(int value) {
    cout << "Wartość: " << value << endl;
}

int main() {
    int num = 10;
    void (*ptr_to_func)(int) = &print; // Przechowanie adresu funkcji print we wskaźniku do funkcji
    (*ptr_to_func)(num); // Wywołanie funkcji print z użyciem wskaźnika do funkcji
    return 0;
}
```

W tym przykładzie, wskaźnik `ptr_to_func` przechowuje adres funkcji `print`. Następnie, wywołujemy funkcję `print` z użyciem wskaźnika do funkcji, przekazując mu wartość `num`.

## Wskaźniki do struktur danych

W C++, wskaźniki do struktur danych mogą być używane do przechowywania adresów do struktur danych. Niektóre funkcje, takie jak operacje na plikach, mogą wymagać przekazania wskaźnika do struktury danych, aby móc dokonać operacji na pliku.

```cpp
#include <iostream>

using namespace std;

struct MyStruct {
    int value;
    string name;
};

void print_struct(const MyStruct* ptr) {
    cout << "Wartość: " << ptr->value << endl;
    cout << "Nazwa: " << ptr->name << endl;
}

int main() {
    MyStruct my_struct = {10, "ten"};
    print_struct(&my_struct); // Przekazanie wskaźnika do struktury danych
    return 0;
}
```

W tym przykładzie, wskaźnik `ptr` przechowuje adres do struktury `my_struct`. Następnie, wywołujemy funkcję `print_struct`, przekazując wskaźnik do `my_struct`. Należy zauważyć, że w celu odczytania wartości kryjących się pod wskaźnikiem, zamiast operatora kropki korzystamy z operatora `->`. Alternatywnie moglibyśmy także zapisać `(*ptr).value`.
