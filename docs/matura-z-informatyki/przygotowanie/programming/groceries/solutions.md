# Rozwiązania

## Zadanie 1

=== "Python"

    ```python linenums="1"
    def transform(line):
        name, quantity, price = line.split()
        return (name, int(quantity), float(price))

    with open("groceries.txt") as file:
        data = [transform(line) for line in file]

    result = 0

    for name, quantity, price in data:
        result += quantity * price

    print(f"{result:.2f}")
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <iomanip>

    using namespace std;

    int main() {
        ifstream file("groceries.txt");
        string name;
        int quantity;
        double price, result = 0;
        while (file >> name >> quantity >> price) {
            result += quantity * price;
        }

        cout << "Zadanie 1: " << fixed << setprecision(2) << result << endl;
        file.close();
        return 0;
    }
    ```

## Zadanie 2

=== "Python"

    ```python linenums="1"
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        
        return 0;
    }
    ```

## Zadanie 3

=== "Python"

    ```python linenums="1"
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        
        return 0;
    }
    ```

## Zadanie 4

=== "Python"

    ```python linenums="1"
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        
        return 0;
    }
    ```

## Zadanie 5

=== "Python"

    ```python linenums="1"
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        
        return 0;
    }
    ```

## Zadanie 6

=== "Python"

    ```python linenums="1"
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        
        return 0;
    }
    ```

## Zadanie 7

=== "Python"

    ```python linenums="1"
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        
        return 0;
    }
    ```

## Zadanie 8

=== "Python"

    ```python linenums="1"
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        
        return 0;
    }
    ```