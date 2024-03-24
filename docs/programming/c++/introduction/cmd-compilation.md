# Kompilacja z linii poleceń

Kto potrzebuje zaawansowanego środowiska programistycznego, z kolorowaniem składni, automatycznymi podpowiedziami, rozbudowanym debuggerem, gdy można pisać w notatniku i kompilować ręcznie z linii poleceń? Mam nadzieję, że to pytanie retoryczne. Niemniej pokażę, jak kompilować programy napisane w języku C++ z poziomu terminala.

## Zaprzyjaźnij się z terminalem

Załóżmy, że mamy gotowy program zapisany w pliku main.cpp. Aby go skompilować z linii poleceń wystarczy napisać:

{% tabs %}
{% tab title="Linux" %}
```
g++ main.cpp
```
{% endtab %}

{% tab title="Windows" %}
```
g++ main.cpp
```
{% endtab %}
{% endtabs %}

Proste, prawda? Teraz, aby uruchomić program, należy wykonać polecenie:

{% tabs %}
{% tab title="Linux" %}
```
./a.out
```
{% endtab %}

{% tab title="Windows" %}
```
.\a.exe
```
{% endtab %}
{% endtabs %}

I to by było na tyle. Do zobaczenia w innym temacie!

Ale zaraz, zaraz... Są jeszcze **opcje**, które możemy podać do kompilacji. Przedstawię kilka z nich, po pełną listę odsyłam do dokumentacji: [https://gcc.gnu.org/onlinedocs/gcc-11.2.0/gcc/#toc-GCC-Command-Options](https://gcc.gnu.org/onlinedocs/gcc-11.2.0/gcc/#toc-GCC-Command-Options).

## Opcje

Tak jak i w przypadku wielu innych poleceń wywoływanych z terminala, opcje podajemy po myślnikach, czasem podwójnych.

### Nazwa pliku wykonywalnego

Jeżeli chcemy podać nazwę docelowego wyniku kompilacji, możemy to zrobić za pomocą opcji `-o`.

{% tabs %}
{% tab title="Linux" %}
```
g++ -o main.out main.cpp
./main.out
```
{% endtab %}

{% tab title="Windows" %}
```
g++ -o main.exe main.cpp
.\main.exe
```
{% endtab %}
{% endtabs %}

### Więcej warningów!

Jeżeli chcemy zobaczyć w konsoli więcej warningów (masochiści), możemy skorzystać z opcji `-Wall.`

{% tabs %}
{% tab title="Linux" %}
```
g++ -Wall main.cpp
```
{% endtab %}

{% tab title="Windows" %}
```
g++ -Wall main.cpp
```
{% endtab %}
{% endtabs %}

### Optymalizacja

Potężna opcja. W niektórych przypadkach może poprawić osiągi naszego programu.

{% tabs %}
{% tab title="Linux" %}
```
g++ -O2 main.cpp
```
{% endtab %}

{% tab title="Windows" %}
```
g++ -O2 main.cpp
```
{% endtab %}
{% endtabs %}

### Debugowanie

Aby włączyć debugowanie użyjemy opcji `-g`.

{% tabs %}
{% tab title="Linux" %}
```
g++ -g main.cpp
```
{% endtab %}

{% tab title="Windows" %}
```
g++ -g main.cpp
```
{% endtab %}
{% endtabs %}

## Przekierowanie wejścia/wyjścia

Uruchamianie skompilowanego programu z terminala ma swoje zalety. Jedną z nich jest łatwe przekierowanie wejścia i wyjścia naszego programu, np. z i do pliku.

### Wejście z pliku

Aby przekierować wejście z pliku tekstowego należy skorzystać z operatora `<`.

{% tabs %}
{% tab title="Linux" %}
```
./main.out < dane_wej.txt
```
{% endtab %}

{% tab title="Windows" %}
```
.\main.exe < dane_wyj.txt
```
{% endtab %}
{% endtabs %}

### Wyjście do pliku

W celu utworzenia pliku i przekierowania do niego wyjścia z naszego programu użyjemy operatora `>`.

{% tabs %}
{% tab title="Linux" %}
```
./main.out > dane_wyj.txt
```
{% endtab %}

{% tab title="Windows" %}
```
.\main.exe > dane_wyj.txt
```
{% endtab %}
{% endtabs %}

Jeżeli nie chcemy nadpisywać pliku, a jedynie dopisać do niego nowe dane, użyjemy operatora `>>`.

{% tabs %}
{% tab title="Linux" %}
```
./main.out >> dane_wyj.txt
```
{% endtab %}

{% tab title="Windows" %}
```
.\main.exe > dane_wyj.txt
```
{% endtab %}
{% endtabs %}

### Jedno i drugie naraz

Powyższe metody możemy ze sobą łączyć, w dowolnej kolejności.

{% tabs %}
{% tab title="Linux" %}
```
./main.out < dane_wej.txt > dane_wyj.txt
```
{% endtab %}

{% tab title="Windows" %}
```
.\main.exe < dane_wej.txt > dane_wyj.txt
```
{% endtab %}
{% endtabs %}
