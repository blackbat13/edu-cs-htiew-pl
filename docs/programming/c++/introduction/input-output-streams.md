# Obsługa wejścia/wyjścia - strumienie

## Biblioteka

Do obsługi wejścia/wyjścia za pomocą strumieni potrzebujemy biblioteki `iostream` (input/output stream). Ponieważ biblioteka ta znajduje się w przestrzeni nazw `std`, dla ułatwienia można także dodać tę przestrzeń.

```cpp
#include <iostream>
using namespace std;
```

## Wyjście

Do wypisania komunikatów w konsoli wykorzystujemy strumień cout. W celu wypisania komunikatu wystarczy podać, co chcemy wypisać:

```cpp
cout << "Hello World!";
```

W podobny sposób możemy wypisać wartości zmiennych:

```cpp
int a = 10;
cout << a;
```

Proces wygląda identycznie w przypadku wszystkich podstawowych typów, np.:

```cpp
string a = "Hello";
cout << a;
```

Możemy także łączyć komunikaty:

```cpp
int a = 10;
cout << "a = " << a;
```

W celu wypisania znaku nowej linii możemy skorzystać z polecenia `endl` (end line):

```cpp
cout << "Hello Wordl!" << endl;
```

## Wejście

Do wczytywania wejścia z konsoli wykorzystujemy strumień `cin`. W celu wczytania wartości do zmiennej wystarczy podać tę zmienną:

```cpp
int a;
cin >> a;
```

Proces wygląda identycznie w przypadku wszystkich podstawowych typów, np.:

```cpp
string a;
cin >> a;
```

Możemy także wczytać wiele wartości za pomocą jednego polecenia:

```cpp
int a;
string b;
double c;

cin >> a >> b >> c;
```

## Manipulacja wejściem/wyjściem

Do zaawansowanej obsługi wejścia/wyjścia potrzebna jest biblioteka:

```cpp
#include <iomanip>
```

#### Dokumentacja

{% embed url="https://www.cplusplus.com/reference/iomanip" %}
iomanip - dokumentacja
{% endembed %}

### Precyzja wyjścia

Jeżeli chcemy wypisać liczbę rzeczywistą z zadaną precyzją, tzn. z zaokrągleniem do wskazanej liczby cyfr po przecinku, to skorzystamy z polecenia `setprecision`:

```cpp
double a = 0.1234567;

cout << setprecision(4) << a << endl;
cout << setprecision(8) << a << endl;
cout << setprecision(10) << a << endl;
```

{% embed url="https://replit.com/@damiankurpiewski/setprecision#main.cpp" %}

Jeżeli chcemy, by liczba była wypisywana zawsze z określoną liczbą miejsc po przecinku (nawet jeżeli od pewnego miejsca są same zera), to należy najpierw użyć polecenia `fixed`:

```cpp
double a = 0.1234567;

cout << fixed;
cout << setprecision(4) << a << endl;
cout << setprecision(8) << a << endl;
cout << setprecision(10) << a << endl;
```

{% embed url="https://replit.com/@damiankurpiewski/setprecisionfixed#main.cpp" %}

### Inne systemy liczbowe

Możemy wypisać liczby w wybranym systemie liczbowym (ósemkowym, dziesiętnym lub szesnastkowym) za pomocą polecenia `setbase`:

```cpp
int a = 110;

cout << setbase(8);
cout << "osemkowy: " << a << endl;

cout << setbase(16);
cout << "szesnastkowy: " << a << endl;

cout << setbase(10);
cout << "dziesietny: " << a << endl;
```

{% embed url="https://replit.com/@damiankurpiewski/coutsetbase#main.cpp" %}

Podobnie możemy zrobić w przypadku wczytywania wartości w innych systemach liczbowych:

```cpp
int a;

cout << "Osemkowy:" << endl;
cin >> setbase(8);
cin >> a; // Np. 156

cout << "Wczytano: " << a << endl;

cout << "Szesnastkowy:" << endl;
cin >> setbase(16);
cin >> a; // Np. 6e

cout << "Wczytano: " << a << endl;
```

{% embed url="https://replit.com/@damiankurpiewski/cinsetbase#main.cpp" %}
