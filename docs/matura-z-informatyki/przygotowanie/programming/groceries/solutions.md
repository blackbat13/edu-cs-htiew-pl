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

    print(f"Zadanie 1: {result:.2f}")
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
    def transform(line):
        name, quantity, price = line.split()
        return (name, int(quantity), float(price))


    def is_prime(n):
        if n < 2:
            return False

        i = 2

        while i * i <= n:
            if n % i == 0:
                return False

            i += 1

        return True


    with open("groceries.txt") as file:
        data = [transform(line) for line in file]

    result = 0

    for name, quantity, price in data:
        if is_prime(len(name)):
            result += quantity * price * 0.5
        else:
            result += quantity * price

    print(f"Zadanie 2: {result:.2f}")
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    bool isPrime(int n)
    {
        if (n <= 1)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

    int main() {
        ifstream file("groceries.txt");
        string name;
        int quantity;
        double price, result = 0;
        while (file >> name >> quantity >> price)
        {
            if (isPrime(name.size()))
            {
                result += quantity * price * 0.5;
            }
            else
            {
                result += quantity * price;
            }
        }
        cout << "Zadanie 2: " << fixed << setprecision(2) << result << endl;
        file.close();
        return 0;
    }
    ```

## Zadanie 3

=== "Python"

    ```python linenums="1"
    def transform(line):
        name, quantity, price = line.split()
        return (name, int(quantity), float(price))


    with open("groceries.txt") as file:
        data = [transform(line) for line in file]

    quantity_sum = 0
    price_sum = 0

    for name, quantity, price in data:
        quantity_sum += quantity
        price_sum += price * quantity

    print(f"Zadanie 3: {price_sum / quantity_sum:.2f}")
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        ifstream file("groceries.txt");
        string name;
        int quantity, quantitySum = 0;
        double price, priceSum = 0, result;
        while (file >> name >> quantity >> price)
        {
            quantitySum += quantity;
            priceSum += quantity * price;
        }
        result = priceSum / quantitySum;
        cout << "Zadanie 3: " << fixed << setprecision(2) << result << endl;
        file.close();
        return 0;
    }
    ```

## Zadanie 4

=== "Python"

    ```python linenums="1"
    def transform(line):
        name, quantity, price = line.split()
        return (name, int(quantity), float(price))


    with open("groceries.txt") as file:
        data = [transform(line) for line in file]

    groceries_dict = dict()

    for name, quantity, price in data:
        if name in groceries_dict:
            groceries_dict[name] += quantity
        else:
            groceries_dict[name] = quantity

    print("Zadanie 4:")

    for name in sorted(groceries_dict):
        print(f"{name}: {groceries_dict[name]}")
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <map>

    using namespace std;

    int main() {
        ifstream file("groceries.txt");
        string name;
        int quantity;
        double price;
        map<string, int> groceries;
        while (file >> name >> quantity >> price)
        {
            groceries[name] += quantity;
        }

        cout << "Zadanie 4: " << endl;
        
        for(auto item : groceries) {
            cout << item.first << ": " << item.second << endl;
        }
        
        file.close();
        return 0;
    }
    ```

## Zadanie 5

=== "Python"

    ```python linenums="1"
    def transform(line):
        name, quantity, price = line.split()
        return (name, int(quantity), float(price))


    with open("groceries.txt") as file:
        data = [transform(line) for line in file]

    groceries_dict = dict()

    for name, quantity, price in data:
        if name in groceries_dict:
            groceries_dict[name][0] += quantity
            groceries_dict[name][1] += price * quantity
        else:
            groceries_dict[name] = [quantity, price * quantity]

    print("Zadanie 5:")

    for name in sorted(groceries_dict):
        print(f"{name}: {groceries_dict[name][1] / groceries_dict[name][0]:.2f}")

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
    def transform(line):
        name, quantity, price = line.split()
        return (name, int(quantity), float(price))


    with open("groceries.txt") as file:
        data = [transform(line) for line in file]

    groceries_dict = dict()

    for name, quantity, price in data:
        if name in groceries_dict:
            groceries_dict[name][0] = min(price, groceries_dict[name][0])
            groceries_dict[name][1] = max(price, groceries_dict[name][1])
        else:
            groceries_dict[name] = [price, price]

    dif_list = [
        groceries_dict[name][1] - groceries_dict[name][0] for name in groceries_dict
    ]
    max_dif = max(dif_list)

    print("Zadanie 6:")

    for name in sorted(groceries_dict):
        if groceries_dict[name][1] - groceries_dict[name][0] == max_dif:
            print(
                f"{name}: min: {groceries_dict[name][0]}, max: {groceries_dict[name][1]}"
            )
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
    def transform(line):
        name, quantity, price = line.split()
        return (name, int(quantity), float(price))


    with open("groceries.txt") as file:
        data = [transform(line) for line in file]

    groceries_dict = dict()

    for name, quantity, price in data:
        if name in groceries_dict:
            groceries_dict[name].append(price)
        else:
            groceries_dict[name] = [price]

    print("Zadanie 7:")
    for name in sorted(groceries_dict):
        prices = sorted(groceries_dict[name])
        print(f"{name}: {', '.join(map(str, prices))}")

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
    def transform(line):
        name, quantity, price = line.split()
        return (name, int(quantity), float(price))


    with open("groceries.txt") as file:
        data = [transform(line) for line in file]

    groceries_dict = dict()
    result = 0

    for name, quantity, price in data:
        if name not in groceries_dict:
            groceries_dict[name] = 0

        if groceries_dict[name] + quantity <= 100:
            result += quantity * price
            groceries_dict[name] += quantity
        else:
            result += (100 - groceries_dict[name]) * price
            groceries_dict[name] = 100

    print(f"Zadanie 8: {result:.2f}")
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