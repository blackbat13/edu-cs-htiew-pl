# Rozwiązania

## Zadanie 1

=== "Python"

    ```python linenums="1"
    with open("dates.txt") as file:
        dates = [list(map(int, line.split())) for line in file.read().strip().split("\n")]

    result = 0
    for date in dates:
        year = max(date)
        if (year % 4 == 0 and year % 100 != 0) or (year % 400 == 0):
            result += 1

    print(result)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        ifstream file("dates.txt");
        int result = 0, a, b, c, year;
        for(int i = 0; i < 1000; i++) {
            file >> a >> b >> c;
            year = max(a, max(b, c));
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                result++;
            }
        }

        file.close();
        
        cout << result << endl;

        return 0;
    }
    ```

## Zadanie 2

=== "Python"

    ```python linenums="1"
    with open("dates.txt") as file:
        dates = [list(map(int, line.split())) for line in file.read().strip().split("\n")]

    result = 0
    for date in dates:
        year = max(date)
        date.remove(year)
        day = max(date)
        if day > 12:
            result += 1

    print(result)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        ifstream file("dates.txt");
        int result = 0, a, b, c, year, month, day;
        for(int i = 0; i < 1000; i++) {
            file >> a >> b >> c;
            year = max(a, max(b, c));
            month = min(a, min(b, c));
            day = a + b + c - year - month;
            if (day > 12) {
                result++;
            }
        }

        file.close();
        
        cout << result << endl;
        
        return 0;
    }
    ```

## Zadanie 3

=== "Python"

    ```python linenums="1"
    with open("dates.txt") as file:
        dates = [list(map(int, line.split())) for line in file.read().strip().split("\n")]

    result = 0
    ordered_dates = []
    for date in dates:
        month, day, year = sorted(date)
        ordered_dates.append((year, month, day))

    ordered_dates.sort()
    print("Najstarsza:", ordered_dates[0])
    print("Najmłodsza:", ordered_dates[-1])
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <algorithm>
    #include <tuple>

    using namespace std;

    int main() {
        ifstream file("dates.txt");
        int a, b, c, year, month, day;
        tuple<int, int, int> dates[1000];
        for(int i = 0; i < 1000; i++) {
            file >> a >> b >> c;
            year = max(a, max(b, c));
            month = min(a, min(b, c));
            day = a + b + c - year - month;
            dates[i] = make_tuple(year, month, day);
        }

        file.close();

        sort(dates, dates + 1000);

        cout << "Najstarsza: " << get<0>(dates[0]) << " " << get<1>(dates[0]) << " " << get<2>(dates[0]) << endl;
        cout << "Najmlodsza: " << get<0>(dates[999]) << " " << get<1>(dates[999]) << " " << get<2>(dates[999]) << endl;
        
        return 0;
    }
    ```

## Zadanie 4

=== "Python"

    ```python linenums="1"
    with open("dates.txt") as file:
        dates = [list(map(int, line.split())) for line in file.read().strip().split("\n")]

    result = 0
    months = [min(date) for date in dates]
    months_count = Counter(months)
    print(months_count)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        ifstream file("dates.txt");
        int a, b, c, month;
        int months_count[13] = {};
        for(int i = 0; i < 1000; i++) {
            file >> a >> b >> c;
            month = min(a, min(b, c));
            months_count[month]++;
        }

        file.close();

        for(int i = 1; i <= 12; i++) {
            cout << i << ": " << months_count[i] << endl;
        }

        return 0;
    }

## Zadanie 5

=== "Python"

    ```python linenums="1"
    with open("dates.txt") as file:
        dates = [list(map(int, line.split())) for line in file.read().strip().split("\n")]

    result = 0
    years = [max(date) for date in dates]
    current_length = 1
    current_start_year = years[0]
    max_start_year = years[0]
    max_end_year = years[0]
    max_length = 1
    for i, year in enumerate(years[1:], 1):
        if year > years[i - 1]:
            current_length += 1
            if current_length > max_length:
                max_length = current_length
                max_start_year = current_start_year
                max_end_year = year
        else:
            current_start_year = year
            current_length = 1

    print("Długość:", max_length)
    print("Rok startowy:", max_start_year)
    print("Rok końcowy:", max_end_year)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        ifstream file("dates.txt");
        int a, b, c, current_year, previous_year, result = 0;
        int current_length = 1, max_length = 1, current_start_year, max_start_year, max_end_year;
        file >> a >> b >> c;
        current_year = max(a, max(b, c));
        current_start_year = current_year;
        max_start_year = current_year;
        max_end_year = current_year;
        for(int i = 1; i < 1000; i++) {
            previous_year = current_year;
            file >> a >> b >> c;
            current_year = max(a, max(b, c));
            if(current_year > previous_year) {
                current_length += 1;
                if(current_length > max_length) {
                    max_length = current_length;
                    max_start_year = current_start_year;
                    max_end_year = current_year;
                }
            } else {
                current_start_year = current_year;
                current_length = 1;
            }
        }

        file.close();

        cout << "Dlugosc: " << max_length << endl;
        cout << "Rok startowy: " << max_start_year << endl;
        cout << "Rok koncowy: " << max_end_year << endl;

        return 0;
    }

## Zadanie 6

=== "Python"

    ```python linenums="1"
    with open("dates.txt") as file:
        dates = [list(map(int, line.split())) for line in file.read().strip().split("\n")]

    result = 0
    ordered_dates = []
    for date in dates:
        month, day, year = sorted(date)
        ordered_dates.append((year, month, day))

    result = 0
    for i, date1 in enumerate(ordered_dates):
        for date2 in ordered_dates[i + 1:]:
            year1, month1, day1 = date1
            year2, month2, day2 = date2
            if month1 + month2 <= 12 and day1 + day2 <= 31:
                result += 1

    print(result)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <algorithm>
    #include <tuple>

    using namespace std;

    int main() {
        ifstream file("dates.txt");
        int a, b, c, year, month, day, result = 0;
        tuple<int, int, int> dates[1000];
        for(int i = 0; i < 1000; i++) {
            file >> a >> b >> c;
            year = max(a, max(b, c));
            month = min(a, min(b, c));
            day = a + b + c - year - month;
            dates[i] = make_tuple(year, month, day);
        }

        file.close();

        for(int i = 0; i < 1000; i++) {
            for(int j = i + 1; j < 1000; j++) {
                if (get<1>(dates[i]) + get<1>(dates[j]) <= 12 && get<2>(dates[i]) + get<2>(dates[j]) <= 31)
                    result++;
            }
        }

        cout << result << endl;
        
        return 0;
    }
    ```