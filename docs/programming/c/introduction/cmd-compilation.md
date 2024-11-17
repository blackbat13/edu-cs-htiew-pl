# Kompilacja z linii poleceń

Kto potrzebuje zaawansowanego środowiska programistycznego, z kolorowaniem składni, automatycznymi podpowiedziami, rozbudowanym debuggerem, gdy można pisać w notatniku i kompilować ręcznie z linii poleceń? Mam nadzieję, że to pytanie retoryczne. Niemniej pokażę, jak kompilować programy napisane w języku C z poziomu terminala.

## Zaprzyjaźnij się z terminalem

Załóżmy, że mamy gotowy program zapisany w pliku main.cpp. Aby go skompilować z linii poleceń wystarczy napisać:

=== "Linux"

    ```bash
    gcc main.c
    ```

=== "Windows"

    ```bat
    gcc main.c
    ```

Proste, prawda? Teraz, aby uruchomić program, należy wykonać polecenie:

=== "Linux"

    ```bash
    ./a.out
    ```

=== "Windows"

    ```bat
    .\a.exe
    ```

I to by było na tyle. Do zobaczenia w innym temacie!

Ale zaraz, zaraz... Są jeszcze **opcje**, które możemy podać do kompilacji. Przedstawię kilka z nich, po pełną listę odsyłam do dokumentacji: [https://gcc.gnu.org/onlinedocs/gcc-11.2.0/gcc/#toc-GCC-Command-Options](https://gcc.gnu.org/onlinedocs/gcc-11.2.0/gcc/#toc-GCC-Command-Options).

## Opcje

Tak jak i w przypadku wielu innych poleceń wywoływanych z terminala, opcje podajemy po myślnikach, czasem podwójnych.

### Nazwa pliku wykonywalnego

Jeżeli chcemy podać nazwę docelowego wyniku kompilacji, możemy to zrobić za pomocą opcji `-o`.

=== "Linux"

    ```bash
    gcc -o main.out main.c
    ./main.out
    ```

=== "Windows"

    ```bat
    gcc -o main.exe main.c
    .\main.exe
    ```

### Więcej warningów!

Jeżeli chcemy zobaczyć w konsoli więcej warningów (masochiści), możemy skorzystać z opcji `-Wall.`

=== "Linux"

    ```bash
    gcc -Wall main.c
    ```

=== "Windows"

    ```bat
    gcc -Wall main.c
    ```

### Optymalizacja

Potężna opcja. W niektórych przypadkach może poprawić osiągi naszego programu.

=== "Linux"

    ```bash
    gcc -O2 main.c
    ```

=== "Windows"

    ```bat
    gcc -O2 main.c
    ```

### Debugowanie

Aby włączyć debugowanie użyjemy opcji `-g`.

=== "Linux"

    ```bash
    gcc -g main.c
    ```

=== "Windows"

    ```bat
    gcc -g main.c
    ```

## Przekierowanie wejścia/wyjścia

Uruchamianie skompilowanego programu z terminala ma swoje zalety. Jedną z nich jest łatwe przekierowanie wejścia i wyjścia naszego programu, np. z i do pliku.

### Wejście z pliku

Aby przekierować wejście z pliku tekstowego należy skorzystać z operatora `<`.

=== "Linux"

    ```bash
    ./main.out < dane_wej.txt
    ```

=== "Windows"

    ```bat
    .\main.exe < dane_wyj.txt
    ```

### Wyjście do pliku

W celu utworzenia pliku i przekierowania do niego wyjścia z naszego programu użyjemy operatora `>`.

=== "Linux"

    ```bash
    ./main.out > dane_wyj.txt
    ```

=== "Windows"

    ```bat
    .\main.exe > dane_wyj.txt
    ```

Jeżeli nie chcemy nadpisywać pliku, a jedynie dopisać do niego nowe dane, użyjemy operatora `>>`.

=== "Linux"

    ```bash
    ./main.out >> dane_wyj.txt
    ```

=== "Windows"

    ```bat
    .\main.exe > dane_wyj.txt
    ```

### Jedno i drugie naraz

Powyższe metody możemy ze sobą łączyć, w dowolnej kolejności.

=== "Linux"

    ```bash
    ./main.out < dane_wej.txt > dane_wyj.txt
    ```

=== "Windows"

    ```bat
    .\main.exe < dane_wej.txt > dane_wyj.txt
    ```
