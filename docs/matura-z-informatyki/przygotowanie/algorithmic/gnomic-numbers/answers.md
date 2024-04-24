# Rozwiązania

## Zadanie 1

| **k** | **Liczba gnomiczna** |
|:-----:|:-----------------:|
|   9   |        TAK        |
|  10  |        NIE        |
|   15  |        TAK           |
|  24  |         NIE          |
|  121  |         TAK          |

## Zadanie 2

```
funkcja czy_gnomiczna(k):
    1. Jeżeli k mod 2 == 1:
        2. Zwróć PRAWDA
    3. Zwróć FAŁSZ
```

## Zadanie 3

### Odpowiedź

$42$

### Rozwiązanie

=== "Python"

    ```python linenums="1"
    with open("gnomiczne.txt") as file:
        binary = file.read().strip().split("\n")

    for num in binary:
        if num[-1] == '1':
            result += 1

    print(result)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        ifstream file("gnomiczne.txt");
        string binary;
        int result = 0;

        for(int i = 0; i < 100; i++) {
            file >> binary;
            if (binary[binary.length() - 1] == '1') {
                result++;
            }
        }

        cout << result << endl;
        file.close();

        return 0;
    }
    ```
