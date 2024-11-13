# Rozwiązania - Python

## Zadanie 1

=== "Python"

    ```python linenums="1"
    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    min_val = min(numbers)
    max_val = max(numbers)

    print("Minimum:", min_val, "Pozycja:", numbers.index(min_val) + 1)
    print("Maksimum:", max_val, "Pozycja:", numbers.index(max_val) + 1)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        auto min_val = *min_element(numbers.begin(), numbers.end());
        auto max_val = *max_element(numbers.begin(), numbers.end());

        cout << "Minimum: " << min_val << " Pozycja: " << (find(numbers.begin(), numbers.end(), min_val) - numbers.begin() + 1) << endl;
        cout << "Maksimum: " << max_val << " Pozycja: " << (find(numbers.begin(), numbers.end(), max_val) - numbers.begin() + 1) << endl;

        return 0;
    }
    ```
    

## Zadanie 2

=== "Python"

    ```python linenums="1"
    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    sum_val = sum(numbers)
    avg_val = sum_val / len(numbers)

    print("Suma:", sum_val)
    print(f"Średnia: {avg_val:.2f}")
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <numeric>

    using namespace std;

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        int sum_val = accumulate(numbers.begin(), numbers.end(), 0);
        double avg_val = static_cast<double>(sum_val) / numbers.size();

        cout << "Suma: " << sum_val << endl;
        cout << "Srednia: " << fixed << setprecision(2) << avg_val << endl;

        return 0;
    }
    ```

## Zadanie 3

=== "Python

    ```python linenums="1"
    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    counter = 0

    for num in numbers:
        if num % 2 == 0:
            counter += 1

    print(counter)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>

    using namespace std;

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        int counter = 0;

        for (int num : numbers) {
            if (num % 2 == 0) {
                counter += 1;
            }
        }

        cout << counter << endl;

        return 0;
    }
    ```

## Zadanie 4

=== "Python"

    ```python linenums="1"
    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    even = [num for num in numbers if num % 2 == 0]

    print("Minimum parzyste:", min(even))
    print("Maksimum parzyste:", max(even))
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        vector<int> even;
        for (int num : numbers) {
            if (num % 2 == 0) {
                even.push_back(num);
            }
        }

        cout << "Minimum parzyste: " << *min_element(even.begin(), even.end()) << endl;
        cout << "Maksimum parzyste: " << *max_element(even.begin(), even.end()) << endl;

        return 0;
    }
    ```

## Zadanie 5

=== "Python"

    ```python linenums="1"
    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    counter = 0

    for num in numbers:
        if num % 3 == 0 and num % 5 == 0:
            counter += 1

    print(counter)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>

    using namespace std;

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        int counter = 0;

        for (int num : numbers) {
            if (num % 3 == 0 && num % 5 == 0) {
                counter += 1;
            }
        }

        cout << counter << endl;

        return 0;
    }
    ```

## Zadanie 6

=== "Python"

    ```python linenums="1"
    from math import gcd

    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    gcd_list = [gcd(numbers[i - 1], numbers[i]) for i in range(1, len(numbers))]

    print("Maksimum NWD:", max(gcd_list))
    print("Minimum NWD:", min(gcd_list))
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <numeric>
    #include <algorithm>

    using namespace std;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        vector<int> gcd_list;
        for (size_t i = 1; i < numbers.size(); ++i) {
            gcd_list.push_back(gcd(numbers[i - 1], numbers[i]));
        }

        cout << "Maksimum NWD: " << *max_element(gcd_list.begin(), gcd_list.end()) << endl;
        cout << "Minimum NWD: " << *min_element(gcd_list.begin(), gcd_list.end()) << endl;

        return 0;
    }
    ```

## Zadanie 7

=== "Python"

    ```python linenums="1"
    from math import gcd

    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    current_lcm = 1

    for i in range(1, len(numbers)):
        if numbers[i] < 20:
            current_lcm = (current_lcm * numbers[i]) // gcd(current_lcm, numbers[i])

    print("NWW:", current_lcm)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <numeric>

    using namespace std;

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        int current_lcm = 1;

        for (size_t i = 1; i < numbers.size(); ++i) {
            if (numbers[i] < 20) {
                current_lcm = lcm(current_lcm, numbers[i]);
            }
        }

        cout << "NWW: " << current_lcm << endl;

        return 0;
    }
    ```

## Zadanie 8

=== "Python"

    ```python linenums="1"
    def is_prime(num):
        if num <= 1:
            return False

        i = 2
        while i * i <= num:
            if num % i == 0:
                return False
            
            i += 1

        return True

    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    counter = 0

    for num in numbers:
        if is_prime(num):
            counter += 1

    print(counter)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>

    using namespace std;

    bool is_prime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        int counter = 0;

        for (int num : numbers) {
            if (is_prime(num)) {
                counter += 1;
            }
        }

        cout << counter << endl;

        return 0;
    }
    ```

## Zadanie 9

=== "Python"

    ```python linenums="1"
    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    numbers_sum = []

    for num in numbers:
        digit_sum = 0
        while num > 0:
            digit_sum += num % 10
            num //= 10
        
        numbers_sum.append(digit_sum)

    min_sum = min(numbers_sum)
    max_sum = max(numbers_sum)

    print("Minimalna suma cyfr:", min_sum, "Liczba:", numbers[numbers_sum.index(min_sum)])
    print("Maksymalna suma cyfr:", max_sum, "Liczba:", numbers[numbers_sum.index(max_sum)])
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int digit_sum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        vector<int> numbers_sum;
        for (int num : numbers) {
            numbers_sum.push_back(digit_sum(num));
        }

        int min_sum = *min_element(numbers_sum.begin(), numbers_sum.end());
        int max_sum = *max_element(numbers_sum.begin(), numbers_sum.end());

        cout << "Minimalna suma cyfr: " << min_sum << " Liczba: " << numbers[distance(numbers_sum.begin(), find(numbers_sum.begin(), numbers_sum.end(), min_sum))] << endl;
        cout << "Maksymalna suma cyfr: " << max_sum << " Liczba: " << numbers[distance(numbers_sum.begin(), find(numbers_sum.begin(), numbers_sum.end(), max_sum))] << endl;

        return 0;
    }
    ```

## Zadanie 10

=== "Python"

    ```python linenums="1"
    from math import gcd

    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    min_pair = (0,0)
    max_pair = (0,0)
    min_sum = 500
    max_sum = 0

    for i in range(len(numbers)):
        for j in range(i + 1, len(numbers)):
            if gcd(numbers[i], numbers[j]) == 1:
                sum_pair = numbers[i] + numbers[j]
                if sum_pair < min_sum:
                    min_pair = (numbers[i], numbers[j])
                    min_sum = sum_pair
                elif sum_pair > max_sum:
                    max_pair = (numbers[i], numbers[j])
                    max_sum = sum_pair

    print("Para o największej sumie:", max_pair)
    print("Para o najmniejszej sumie:", min_pair)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <numeric>

    using namespace std;

    int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        pair<int, int> min_pair = {0, 0};
        pair<int, int> max_pair = {0, 0};
        int min_sum = 500;
        int max_sum = 0;

        for (size_t i = 0; i < numbers.size(); ++i) {
            for (size_t j = i + 1; j < numbers.size(); ++j) {
                if (gcd(numbers[i], numbers[j]) == 1) {
                    int sum_pair = numbers[i] + numbers[j];
                    if (sum_pair < min_sum) {
                        min_pair = {numbers[i], numbers[j]};
                        min_sum = sum_pair;
                    } else if (sum_pair > max_sum) {
                        max_pair = {numbers[i], numbers[j]};
                        max_sum = sum_pair;
                    }
                }
            }
        }

        cout << "Para o największej sumie: (" << max_pair.first << ", " << max_pair.second << ")" << endl;
        cout << "Para o najmniejszej sumie: (" << min_pair.first << ", " << min_pair.second << ")" << endl;

        return 0;
    }
    ```

## Zadanie 11

=== "Python"

    ```python linenums="1"
    def is_perfect(num):
        factors_sum = 1
        i = 2
        while i * i <= num:
            if num % i == 0:
                factors_sum += i
                if num // i != i:
                    factors_sum += num // i
            i += 1

        return factors_sum == num

    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    for num in numbers:
        if is_perfect(num):
            print(num)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>

    using namespace std;

    bool is_perfect(int num) {
        int factors_sum = 1;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                factors_sum += i;
                if (num / i != i) {
                    factors_sum += num / i;
                }
            }
        }
        return factors_sum == num;
    }

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        for (int num : numbers) {
            if (is_perfect(num)) {
                cout << num << endl;
            }
        }

        return 0;
    }
    ```

## Zadanie 12

=== "Python"

    ```python linenums="1"
    from statistics import median

    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    print(median(numbers))
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <algorithm>

    using namespace std;

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        sort(numbers.begin(), numbers.end());

        double median;
        size_t size = numbers.size();
        if (size % 2 == 0) {
            median = (numbers[size / 2 - 1] + numbers[size / 2]) / 2.0;
        } else {
            median = numbers[size / 2];
        }

        cout << median << endl;

        return 0;
    }
    ```

## Zadanie 13

=== "Python"

    ```python linenums="1"
    from collections import Counter

    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    counters = Counter(sorted(numbers))
    most_common = counters.most_common(1)[0]

    print("Najpopularniejsza liczba:", most_common[0])
    print("Liczba wystąpień:", most_common[1])
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <algorithm>
    #include <unordered_map>

    using namespace std;

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        unordered_map<int, int> counters;
        for (int num : numbers) {
            counters[num]++;
        }

        auto most_common = max_element(counters.begin(), counters.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.second < b.second;
        });

        cout << "Najpopularniejsza liczba: " << most_common->first << endl;
        cout << "Liczba wystąpień: " << most_common->second << endl;

        return 0;
    }
    ```

## Zadanie 14

### Wersja 1

Sprawdzenie, czy liczba jest potęgą dwójki, możemy wykonać za pomocą wielokrotnego dzielenia liczby przez dwa. Jeżeli w trakcie dzielenia natrafimy na liczbę nieparzystą, to liczba nie jest potęgą dwójki. Jeżeli natomiast dotrzemy do wartości 1, to liczba jest potęgą dwójki.

=== "Python"

    ```python linenums="1"
    def is_power_of_two(num):
        while num > 1:
            if num % 2 != 0:
                return False

            num //= 2
        
        return True
    ```

=== "C++"

    ```cpp linenums="1"
    bool is_power_of_two(int num) {
        while (num > 1) {
            if (num % 2 != 0) {
                return false;
            }
            num /= 2;
        }
        return true;
    }
    ```

### Wersja 2

Sprawdzenie, czy liczba jest potęgą dwójki, możemy także oprzeć na zapisie binarnym liczby. Jeżeli liczba jest potęgą dwójki, to w jej zapisie binarnym znajduje się dokładnie jedna jedynka. W takim razie, jeżeli wykonamy operację bitową **AND** na sprawdzanej liczbie i jej wartości pomniejszonej o jeden (zakładając, że liczba jest większa od zera), to dostaniemy jako wynik zero wtedy i tylko wtedy, gdy sprawdzana liczba jest potęgą dwójki..

=== "Python"

    ```python linenums="1"
    def is_power_of_two(num):
        return num > 0 and num & (num - 1) == 0
    ```

=== "C++"

    ```cpp linenums="1"
    bool is_power_of_two(int num) {
        return num > 0 && (num & (num - 1)) == 0;
    }
    ```

### Rozwiązanie

=== "Python"

    ```python linenums="1"
    def is_power_of_two(num):
        return num > 0 and num & (num - 1) == 0


    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    counter = 0

    for num in numbers:
        if is_power_of_two(num):
            counter += 1

    print(counter)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>

    using namespace std;

    bool is_power_of_two(int num) {
        return num > 0 && (num & (num - 1)) == 0;
    }

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        int counter = 0;

        for (int num : numbers) {
            if (is_power_of_two(num)) {
                counter += 1;
            }
        }

        cout << counter << endl;

        return 0;
    }
    ```

## Zadanie 15

=== "Python"

    ```python linenums="1"
    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    more_zeros = 0
    more_ones = 0
    zeros_eq_ones = 0

    for num in numbers:
        binary = str(bin(num))[2:]
        zero_count = binary.count("0")
        one_count = binary.count("1")
        if zero_count > one_count:
            more_zeros += 1
        elif zero_count < one_count:
            more_ones += 1
        else:
            zeros_eq_ones += 1

    print("Więcej zer:", more_zeros)
    print("Mniej zer:", more_ones)
    print("Tyle samo:", zeros_eq_ones)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <bitset>

    using namespace std;

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        int more_zeros = 0;
        int more_ones = 0;
        int zeros_eq_ones = 0;

        for (int num : numbers) {
            bitset<32> binary(num);
            int zero_count = binary.size() - binary.count();
            int one_count = binary.count();
            if (zero_count > one_count) {
                more_zeros += 1;
            } else if (zero_count < one_count) {
                more_ones += 1;
            } else {
                zeros_eq_ones += 1;
            }
        }

        cout << "Więcej zer: " << more_zeros << endl;
        cout << "Mniej zer: " << more_ones << endl;
        cout << "Tyle samo: " << zeros_eq_ones << endl;

        return 0;
    }
    ```

## Zadanie 16

=== "Python"

    ```python linenums="1"
    def is_prime(num):
        if num <= 1:
            return False

        i = 2
        while i * i <= num:
            if num % i == 0:
                return False
            
            i += 1

        return True

    with open("integers.txt") as file:
        numbers = list(map(int, file.read().split()))

    counter = 0

    for num in numbers:
        i = 2
        while num % i != 0:
            i += 1

        if is_prime(num // i):
            counter += 1

    print(counter)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>

    using namespace std;

    bool is_prime(int num) {
        if (num <= 1) {
            return false;
        }
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                return false;
            }
        }
        return true;
    }

    int main() {
        ifstream file("integers.txt");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        int counter = 0;

        for (int num : numbers) {
            int i = 2;
            while (num % i != 0) {
                i += 1;
            }

            if (is_prime(num / i)) {
                counter += 1;
            }
        }

        cout << counter << endl;

        return 0;
    }
    ```

## Zadanie 17

=== "Python"

    ```python linenums="1"
    with open(file_name) as file:
        numbers = list(map(int, file.read().split()))

    factorials = [1]
    i = 2
    while factorials[-1] <= 200:
        factorials.append(factorials[-1] * i)
        i += 1

    counter = 0

    for num in numbers:
        if num in factorials:
            counter += 1

    print(counter)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>

    using namespace std;

    int main() {
        ifstream file("file_name");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        vector<int> factorials = {1};
        int i = 2;
        while (factorials.back() <= 200) {
            factorials.push_back(factorials.back() * i);
            i += 1;
        }

        int counter = 0;

        for (int num : numbers) {
            if (find(factorials.begin(), factorials.end(), num) != factorials.end()) {
                counter += 1;
            }
        }

        cout << counter << endl;

        return 0;
    }
    ```

## Zadanie 18

=== "Python"

    ```python linenums="1"
    with open(file_name) as file:
        numbers = list(map(int, file.read().split()))

    for num in numbers:
        sq = int(math.sqrt(num))
        if sq**2 == num:
            print(num)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <cmath>

    using namespace std;

    int main() {
        ifstream file("file_name");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        for (int num : numbers) {
            int sq = static_cast<int>(sqrt(num));
            if (sq * sq == num) {
                cout << num << endl;
            }
        }

        return 0;
    }
    ```

## Zadanie 19

=== "Python"

    ```python linenums="1"
    with open(file_name) as file:
        numbers = list(map(int, file.read().split()))

    counter = 0

    for i in range(len(numbers)):
        for j in range(i + 1, len(numbers)):
            for k in range(j + 1, len(numbers)):
                a, b, c = numbers[i], numbers[j], numbers[k]
                if a + b + c - max(a, b, c) > max(a, b, c):
                    counter += 1
        
    print(counter)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>

    using namespace std;

    int main() {
        ifstream file("file_name");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        int counter = 0;

        for (size_t i = 0; i < numbers.size(); ++i) {
            for (size_t j = i + 1; j < numbers.size(); ++j) {
                for (size_t k = j + 1; k < numbers.size(); ++k) {
                    int a = numbers[i], b = numbers[j], c = numbers[k];
                    if (a + b + c - max({a, b, c}) > max({a, b, c})) {
                        counter += 1;
                    }
                }
            }
        }

        cout << counter << endl;

        return 0;
    }
    ```

## Zadanie 20

=== "Python"

    ```python linenums="1"
    with open(file_name) as file:
        numbers = list(map(int, file.read().split()))

    for num in numbers:
        if num % 10 == (num**2) % 10:
            print(num)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>

    using namespace std;

    int main() {
        ifstream file("file_name");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        for (int num : numbers) {
            if (num % 10 == (num * num) % 10) {
                cout << num << endl;
            }
        }

        return 0;
    }
    ```

## Zadanie 21

=== "Python"

    ```python linenums="1"
    with open(file_name) as file:
        numbers = list(map(int, file.read().split()))

    for num in numbers:
        sq = str(num ** 2)
        for i in range(1, len(sq)):
            left = int(sq[:i])
            right = int(sq[i:])
            if left + right == num and right != 0:
                print(num)
                break
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>

    using namespace std;

    int main() {
        ifstream file("file_name");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        for (int num : numbers) {
            string sq = to_string(num * num);
            for (size_t i = 1; i < sq.size(); ++i) {
                int left = stoi(sq.substr(0, i));
                int right = stoi(sq.substr(i));
                if (left + right == num && right != 0) {
                    cout << num << endl;
                    break;
                }
            }
        }

        return 0;
    }
    ```

## Zadanie 22

=== "Python"

    ```python linenums="1"
    with open(file_name) as file:
        numbers = list(map(int, file.read().split()))

    for num in numbers:
        binary = str(bin(num))[2:]
        if binary.count("10") == 1 and binary.count("01") == 0:
            print(num, binary)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <bitset>

    using namespace std;

    int main() {
        ifstream file("file_name");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        for (int num : numbers) {
            bitset<32> binary(num);
            string binary_str = binary.to_string();
            if (binary_str.find("10") != string::npos && binary_str.find("01") == string::npos) {
                cout << num << " " << binary_str << endl;
            }
        }

        return 0;
    }
    ```

## Zadanie 23

=== "Python"

    ```python linenums="1"
    with open(file_name) as file:
        numbers = list(map(int, file.read().split()))

    for num in numbers:
        sm = 0
        for i, digit in enumerate(str(num)):
            sm += int(digit) ** (i + 1)
        
        if sm == num:
            print(num)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <string>

    using namespace std;

    int main() {
        ifstream file("file_name");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        for (int num : numbers) {
            string num_str = to_string(num);
            vector<int> seq;
            for (char digit : num_str) {
                seq.push_back(digit - '0');
            }
            int n = seq.size();
            while (seq.back() < num) {
                int sum = 0;
                for (int i = seq.size() - n; i < seq.size(); ++i) {
                    sum += seq[i];
                }
                seq.push_back(sum);
            }

            if (seq.back() == num) {
                cout << num << endl;
            }
        }

        return 0;
    }
    ```

## Zadanie 24

=== "Python"

    ```python linenums="1"
    with open(file_name) as file:
        numbers = list(map(int, file.read().split()))

    for num in numbers:
        seq = list(map(int,str(num)))
        n = len(seq)
        while seq[-1] < num:
            seq.append(sum(seq[-n:]))

        if seq[-1] == num:
            print(num)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <vector>
    #include <string>

    using namespace std;

    int main() {
        ifstream file("file_name");
        vector<int> numbers;
        int num;

        while (file >> num) {
            numbers.push_back(num);
        }

        for (int num : numbers) {
            string num_str = to_string(num);
            vector<int> seq;
            for (char digit : num_str) {
                seq.push_back(digit - '0');
            }
            int n = seq.size();
            while (seq.back() < num) {
                int sum = 0;
                for (int i = seq.size() - n; i < seq.size(); ++i) {
                    sum += seq[i];
                }
                seq.push_back(sum);
            }

            if (seq.back() == num) {
                cout << num << endl;
            }
        }

        return 0;
    }
    ```