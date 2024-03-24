# Obsługa plików - strumienie

## Biblioteka

Do obsługi plików za pomocą strumieni potrzebujemy biblioteki `fstream` (*file stream*). Ponieważ biblioteka ta znajduje się w przestrzeni nazw `std`, dla ułatwienia można także dodać tę przestrzeń.

```cpp
#include <fstream>
using namespace std;
```

## Wyjście

### Otwarcie pliku

W celu otwarcia pliku do zapisu tworzymy zmienną typu `ofstream` (*output file stream*). Następnie w nawiasach po nazwie zmiennej podajemy ścieżkę do pliku, który chcemy otworzyć, a po przecinku dodatkowe opcje. Jeżeli docelowy plik nie istnieje, to zostanie on utworzony.

#### Otwarcie w trybie nadpisania

Domyślnie, gdy otwieramy plik do zapisu, to jego zawartość zostanie zastąpiona nową zawartością. To tak, jakbyśmy usunęli plik i utworzyli nowy.

```cpp
ofstream outfile("out.txt");
```

#### Otwarcie w trybie dopisywania

Jeżeli chcemy dopisywać dane do pliku, a nie je zastąpić, należy podać odpowiednią opcję przy tworzeniu strumienia do pliku: `fstream::app`.

```cpp
ofstream outfile("out.txt", fstream::app);
```

### Pisanie do pliku

W przypadku zapisywania danych do pliku postępujemy podobnie jak podczas korzystania ze strumienia `cout`. Różnica jest taka, że zamiast używać `cout`, podajemy nazwę utworzonego strumienia typu `ofstream`.

```cpp
outfile << "Hello World!";
```

W podobny sposób możemy wypisać wartości zmiennych:

```cpp
int a = 10;
outfile << a;
```

### Zamknięcie pliku

Po wykonaniu potrzebnych operacji na pliku należy strumień do niego zamknąć metodą `close`. Jeżeli nie zamkniemy strumienia do pliku to dane mogą nie zostać poprawnie zapisane, a sam plik może zostać uszkodzony.

```cpp
outfile.close();
```

<!-- ## Wejście

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

{% embed url="https://replit.com/@damiankurpiewski/cinsetbase#main.cpp" %} -->
