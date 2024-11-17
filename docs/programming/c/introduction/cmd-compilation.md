# Kompilacja z linii poleceń

Kto potrzebuje zaawansowanego środowiska programistycznego, z kolorowaniem składni, automatycznymi podpowiedziami, rozbudowanym debuggerem, gdy można pisać w notatniku i kompilować ręcznie z linii poleceń? Mam nadzieję, że to pytanie retoryczne. Niemniej pokażę, jak kompilować programy napisane w języku C z poziomu terminala.

## Zaprzyjaźnij się z terminalem

Załóżmy, że mamy gotowy program zapisany w pliku main.cpp. Aby go skompilować z linii poleceń wystarczy napisać:

=== "Linux"

    ```
    gcc main.c
    ```

=== "Windows"

    ```
    gcc main.c
    ```

Proste, prawda? Teraz, aby uruchomić program, należy wykonać polecenie:

=== "Linux"

    ```
    ./a.out
    ```

=== "Windows"

    ```
    .\a.exe
    ```

I to by było na tyle. Do zobaczenia w innym temacie!

Ale zaraz, zaraz... Są jeszcze **opcje**, które możemy podać do kompilacji. Przedstawię kilka z nich, po pełną listę odsyłam do dokumentacji: [https://gcc.gnu.org/onlinedocs/gcc-11.2.0/gcc/#toc-GCC-Command-Options](https://gcc.gnu.org/onlinedocs/gcc-11.2.0/gcc/#toc-GCC-Command-Options).

## Opcje

Tak jak i w przypadku wielu innych poleceń wywoływanych z terminala, opcje podajemy po myślnikach, czasem podwójnych.

### Nazwa pliku wykonywalnego

Jeżeli chcemy podać nazwę docelowego wyniku kompilacji, możemy to zrobić za pomocą opcji `-o`.

=== "Linux"
    ```
    gcc -o main.out main.c
    ./main.out
    ```
=== "Windows"
    ```
    gcc -o main.exe main.c
    .\main.exe
    ```

### Więcej warningów!

Jeżeli chcemy zobaczyć w konsoli więcej warningów (masochiści), możemy skorzystać z opcji `-Wall.`

=== "Linux"
    ```
    gcc -Wall main.c
    ```
=== "Windows"
    ```
    gcc -Wall main.c
    ```

### Optymalizacja

Potężna opcja. W niektórych przypadkach może poprawić osiągi naszego programu.

=== "Linux"
    ```
    gcc -O2 main.c
    ```
=== "Windows"
    ```
    gcc -O2 main.c
    ```

### Debugowanie

Aby włączyć debugowanie użyjemy opcji `-g`.

=== "Linux"
    ```
    gcc -g main.c
    ```
=== "Windows"
    ```
    gcc -g main.c
    ```

## Przekierowanie wejścia/wyjścia

Uruchamianie skompilowanego programu z terminala ma swoje zalety. Jedną z nich jest łatwe przekierowanie wejścia i wyjścia naszego programu, np. z i do pliku.

### Wejście z pliku

Aby przekierować wejście z pliku tekstowego należy skorzystać z operatora `<`.

=== "Linux"
    ```
    ./main.out < dane_wej.txt
    ```
=== "Windows"
    ```
    .\main.exe < dane_wyj.txt
    ```

### Wyjście do pliku

W celu utworzenia pliku i przekierowania do niego wyjścia z naszego programu użyjemy operatora `>`.

=== "Linux"
    ```
    ./main.out > dane_wyj.txt
    ```
=== "Windows"
    ```
    .\main.exe > dane_wyj.txt
    ```

Jeżeli nie chcemy nadpisywać pliku, a jedynie dopisać do niego nowe dane, użyjemy operatora `>>`.

=== "Linux"
    ```
    ./main.out >> dane_wyj.txt
    ```
=== "Windows"
    ```
    .\main.exe > dane_wyj.txt
    ```

### Jedno i drugie naraz

Powyższe metody możemy ze sobą łączyć, w dowolnej kolejności.

=== "Linux"
    ```
    ./main.out < dane_wej.txt > dane_wyj.txt
    ```
=== "Windows"
    ```
    .\main.exe < dane_wej.txt > dane_wyj.txt
    ```
