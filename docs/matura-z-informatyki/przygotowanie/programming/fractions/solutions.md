# Rozwiązania

## Zadanie 1

=== "Python"

    ```python linenums="1"
    from math import gcd

    with open("ulamki.txt", "r") as file:
        fractions = [list(map(int, str.split(" "))) for str in file.read().split("\n")]
        with open("skrocone.txt", "w") as out_file:
            for fraction in fractions:
                divisor = gcd(fraction[0], fraction[1])
                fraction[0] //= divisor
                fraction[1] //= divisor
                print(f"{fraction[0]} {fraction[1]}", file=out_file)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <sstream>
    #include <numeric> // For std::gcd

    using namespace std;

    int main() {
        ifstream file("ulamki.txt");
        ofstream out_file("skrocone.txt");

        int numerator, denumerator;

        while (file >> numerator >> denumerator && !file.eof()) {
            int divisor = gcd(numerator, denumerator);
            numerator /= divisor;
            denumerator /= divisor;
            out_file << numerator << " " << denumerator << endl;
        }

        file.close();
        out_file.close();

        return 0;
    }
    ```

## Zadanie 2

=== "Python"

    ```python linenums="1"
    from math import gcd

    with open("ulamki.txt", "r") as file:
        fractions = [list(map(int, str.split(" "))) for str in file.read().split("\n")]
        numerator = fractions[0][0]
        denumerator = fractions[0][1]
        fractions.pop(0)
        for fraction in fractions:
            m1 = denumerator
            m2 = fraction[1]
            numerator *= m2
            denumerator *= m2
            numerator += fraction[0] * m1

        divisor = gcd(numerator, denumerator)
        numerator //= divisor
        denumerator //= divisor
        print(numerator, denumerator)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <sstream>
    #include <numeric> // For std::gcd

    using namespace std;

    int main() {
        ifstream file("ulamki.txt");

        int numerator, denumerator, num, den;
        file >> numerator >> denumerator;

        while (file >> num >> den && !file.eof()) {
            int tmp = denumerator;
            numerator *= den;
            denumerator *= den;
            numerator += num * tmp;
        }

        file.close();

        int divisor = gcd(numerator, denumerator);
        numerator /= divisor;
        denumerator /= divisor;

        cout << numerator << " " << denumerator << endl;

        return 0;
    }
    ```

## Zadanie 3

=== "Python"

    ```python linenums="1"
    from math import gcd

    with open("ulamki.txt", "r") as file:
        fractions = [list(map(int, str.split(" "))) for str in file.read().split("\n")]
        numerator = fractions[0][0]
        denumerator = fractions[0][1]
        fractions.pop(0)
        for fraction in fractions:
            numerator *= fraction[0]
            denumerator *= fraction[1]

        divisor = gcd(numerator, denumerator)
        numerator //= divisor
        denumerator //= divisor
        print(numerator, denumerator)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <sstream>
    #include <numeric> // For std::gcd

    using namespace std;

    int main() {
        ifstream file("ulamki.txt");

        int numerator, denumerator, num, den;
        file >> numerator >> denumerator;

        while (file >> num >> den && !file.eof()) {
            numerator *= num;
            denumerator *= den;
        }

        file.close();

        int divisor = gcd(numerator, denumerator);
        numerator /= divisor;
        denumerator /= divisor;

        cout << numerator << " " << denumerator << endl;

        return 0;
    }
    ```
