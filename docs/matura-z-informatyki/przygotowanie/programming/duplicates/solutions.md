# Rozwiązania

## Zadanie 1

=== "Python"

    ```python linenums="1"
    with open("duplicates.txt") as file:
        duplicates = list(map(int, file.read().split()))

    uniques = set(duplicates)

    print(len(uniques))
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <set>

    using namespace std;

    int main() {
        ifstream file("duplicates.txt");
        int num;
        set<int> uniques;
        for(int i = 0; i < 100; i++) {
            file >> num;
            uniques.insert(num);
        }

        file.close();
        
        cout << uniques.size() << endl;

        return 0;
    }
    ```

## Zadanie 2

=== "Python"

    ```python linenums="1"
    with open("duplicates.txt") as file:
        duplicates = list(map(int, file.read().split()))

    counters = [0] * 101
    for num in duplicates:
        counters[num] += 1

    max_count = max(counters)
    for i in range(100, 0, -1):
        if counters[i] == max_count:
            print(i)
            break
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        ifstream file("duplicates.txt");
        int num, max_count, max_count_num;
        int counters[101] = {};
        for(int i = 0; i < 100; i++) {
            file >> num;
            counters[num]++;
        }

        file.close();
        
        max_count = counters[100];
        max_count_num = 100;
        for(int i = 99; i >= 1; i--) {
            if (counters[i] > max_count) {
                max_count = counters[i];
                max_count_num = i;
            }
        }

        cout << max_count_num << endl;

        return 0;
    }
    ```

## Zadanie 3

=== "Python"

    ```python linenums="1"
    with open("duplicates.txt") as file:
        duplicates = list(map(int, file.read().split()))

    counters = [0] * 101
    for num in duplicates:
        counters[num] += 1

    min_count = min(counters)
    for i in range(1, 101):
        if counters[i] == min_count:
            print(i)
            break
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        ifstream file("duplicates.txt");
        int num, min_count, min_count_num;
        int counters[101] = {};
        for(int i = 0; i < 100; i++) {
            file >> num;
            counters[num]++;
        }

        file.close();
        
        min_count = counters[1];
        min_count_num = 1;
        for(int i = 2; i <= 100; i++) {
            if (counters[i] < min_count) {
                min_count = counters[i];
                min_count_num = i;
            }
        }

        cout << min_count_num << endl;

        return 0;
    }
    ```