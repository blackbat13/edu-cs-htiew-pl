# Rozwiązania

## Zadanie 1

### 1.1

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        string data;
        ifstream file("mecz.txt");
        file >> data;
        file.close();

        int result = 0;
        for (int i = 1; i < data.length(); i++)
        {
            if (data[i] != data[i - 1])
            {
                result++;
            }
        }

        cout << "Zadanie 1.1" << endl;
        cout << "Wynik: " << result << endl;

        return 0;
    }
    ```


    Zaczynamy od wczytania zawartości pliku do zmiennej typu string. Następnie przechodzimy przez kolejne elementy ciągu, poczynając od drugiego znaku. W pętli porównujemy obecny znak z poprzednim i zwiększamy wynik o 1, jeśli znaki są różne.

=== "Python"

    ```python linenums="1"
    with open("mecz.txt") as file:
        data = file.read().strip()

    result = 0
    for i in range(1, len(data)):
        if data[i] != data[i - 1]:
            result += 1

    print("Zadanie 1.1")
    print("Wynik:", result)
    ```


    Zaczynamy od wczytania zawartości pliku do zmiennej. Dane będą wczytane w postaci tekstu (typ `str`). Na wszelki wypadek usuwamy białe znaki z początku i końca poleceniem `strip`.

    Następnie przechodzimy przez kolejne elementy ciągu, poczynając od drugiego znaku. W pętli porównujemy obecny znak z poprzednim i zwiększamy wynik o 1, jeśli znaki są różne.


### 1.2

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        string data;
        ifstream file("mecz.txt");
        file >> data;
        file.close();

        int win_a = 0, win_b = 0, i = 0;
        while (win_a < 1000 || win_b < 1000 || abs(win_a - win_b) < 3)
        {
            if (data[i] == 'A')
            {
                win_a++;
            }
            else
            {
                win_b++;
            }

            i++;
        }

        cout << "Zadanie 1.2" << endl;
        if (win_a > win_b)
        {
            cout << "Wygrala druzyna A" << endl;
        }
        else
        {
            cout << "Wygrala druzyna B" << endl;
        }

        cout << "Wynik A: " << win_a << endl;
        cout << "Wynik B: " << win_b << endl;

        return 0;
    }
    ```

=== "Python"

    ```python linenums="1"
    with open("mecz.txt") as file:
        data = file.read().strip()

    win_a = 0
    win_b = 0
    i = 0
    while win_a < 1000 or win_b < 1000 or abs(win_a - win_b) < 3:
        if data[i] == "A":
            win_a += 1
        else:
            win_b += 1

        i += 1

    print("Zadanie 1.2")
    if win_a > win_b:
        print("Wygrała drużyna A")
    else:
        print("Wygrała drużyna B")
    print("Wynik A:", win_a)
    print("Wynik B:", win_b)
    ```

### 1.3

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        string data;
        ifstream file("mecz.txt");
        file >> data;
        file.close();

        int result = 0, current_length = 0, max_length = 0;
        char current_symbol = ' ', max_symbol = ' ';

        for (auto el : data)
        {
            if (el == current_symbol)
            {
                current_length++;
            }
            else
            {
                current_symbol = el;
                current_length = 1;
            }

            if (current_length > max_length)
            {
                max_length = current_length;
                max_symbol = current_symbol;
            }

            if (current_length == 10)
            {
                result++;
            }
        }

        cout << "Zadanie 1.3" << endl;
        cout << "Laczna liczba dobrych pass: " << result << endl;
        cout << "Najdluzsza dobra passa: " << max_length;
        cout << ", Druzyna: " << max_symbol << endl;

        return 0;
    }
    ```

=== "Python"

    ```python linenums="1"
    with open("mecz.txt") as file:
        data = file.read().strip()    

    result = 0
    current_symbol = ""
    current_length = 0
    max_length = 0
    max_symbol = ""

    for el in data:
        if current_symbol == el:
            current_length += 1
        else:
            current_length = 1
            current_symbol = el

        if current_length > max_length:
            max_length = current_length
            max_symbol = el
        
        if current_length == 10:
            result += 1

    print("Zadanie 1.3")
    print("Łączna liczba dobrych pass:", result)
    print("Najdłuższa dobra passa:", max_length, "Drużyna:", max_symbol)
    ```

## Zadanie 3

### 3.2

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    bool is_prime(int n) {
        if (n < 2) {
            return false;
        }

        for(int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    int main() {
    ifstream file("liczby.txt");
    int data[100];
    for(int i = 0; i < 100; i++) {
        file >> data[i];
    }

    file.close();

    int result = 0;

    for(auto number : data) {
        if(is_prime(number - 1)) {
            result++;
        } 
    }

    cout << "Zadanie 3.2" << endl;
    cout << result << endl;
    return 0;
    }
    ```

=== "Python"

    ```python linenums="1"
    def is_prime(n):
        if n < 2:
            return False
        
        i = 2
        while i * i <= n:
            if n % i == 0:
                return False
            
            i += 1

        return True


    with open("liczby.txt") as file:
        data = [int(line) for line in file]

    result = 0
    for number in data:
        if is_prime(number - 1):
            result += 1

    print("Zadanie 3.2")
    print(result)
    ```

### 3.3

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    bool is_prime(int n) {
        if (n < 2) {
            return false;
        }

        for(int i = 2; i * i <= n; i++) {
            if (n % i == 0) {
                return false;
            }
        }

        return true;
    }

    int main() {
    ifstream file("liczby.txt");
    int data[100];
    for(int i = 0; i < 100; i++) {
        file >> data[i];
    }

    file.close();

    int min_number = 0, min_value = 1000000, max_number = 0, max_value = 0;

    bool primes[1000001] = {};
    for(int i = 2; i < 1000001; i++) {
        primes[i] = is_prime(i);
    }

    for(auto number : data) {
        int counter = 0;
        for(int i = 2; i <= number / 2; i++) {
            if(primes[i] && primes[number - i]) {
                counter++;
            }
        }

        if(counter > max_value) {
            max_value = counter;
            max_number = number;
        } else if(counter < min_value) {
            min_value = counter;
            min_number = number;
        }
    }

    cout << "Zadanie 3.3" << endl;
    cout << max_number << " " << max_value << endl;
    cout << min_number << " " << min_value << endl;
    return 0;
    }
    ```

=== "Python"

    ```python linenums="1"
    def is_prime(n):
        if n < 2:
            return False
        
        i = 2
        while i * i <= n:
            if n % i == 0:
                return False
            
            i += 1

        return True


    with open("liczby.txt") as file:
        data = [int(line) for line in file]

    min_number = 0
    min_value = 1000000
    max_number = 0
    max_value = 0

    primes = [is_prime(i) for i in range(1000001)]

    for number in data:
        counter = 0
        for i in range(2, number // 2 + 1):
            if primes[i] and primes[number - i]:
                counter += 1

        if counter < min_value:
            min_value = counter
            min_number = number
        elif counter > max_value:
            max_value = counter
            max_number = number

    print("Zadanie 3.3")
    print(max_number, max_value)
    print(min_number, min_value)
    ```

### 3.4

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <map>
    #include <iomanip>
    #include <sstream>

    using namespace std;

    int main() {
    ifstream file("liczby.txt");
    int data[100];
    for(int i = 0; i < 100; i++) {
        file >> data[i];
    }

    file.close();

    map<char, int> hex_map;

    for(auto number : data) {
        stringstream stream;
        stream << hex << number;
        string hex_str(stream.str());
        for(auto el : hex_str) {
            hex_map[el]++;
        }
    }

    cout << "Zadanie 3.4" << endl;
    for(char c = '0'; c <= '9'; c++) {
        cout << c << ": " << hex_map[c] << endl;
    }

    for(char c = 'a'; c <= 'f'; c++) {
        cout << c << ": " << hex_map[c] << endl;
    }

    return 0;
    }
    ```

=== "Python"

    ```python linenums="1"
    with open("liczby.txt") as file:
        data = [int(line) for line in file]

    hex_dict = {hex(i)[2:]:0 for i in range(16)}

    for number in data:
        hex_str = hex(number)[2:]
        for el in hex_str:
            hex_dict[el] += 1

    print("Zadanie 3.4")
    for el in hex_dict:
        print(f"{el}: {hex_dict[el]}")
    ```
