# Rozwiązania

## Zadanie 1

=== "Python"

    ```python linenums="1"
    with open("kik.txt") as file:
        points = [list(map(float, str.split(" "))) for str in file.read().split("\n")]

    inside = 0
    outside = 0
    for point in points:
        x = point[0]
        y = point[1]
        dist = x * x + y * y
        if dist <= 1:
            inside += 1
        else:
            outside += 1

    print(f"inside: {inside}, outside: {outside}")
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        ifstream file("kik.txt");
        double x, y, dist;
        int inside = 0, outside = 0;
        for(int i = 0; i < 10000; i++) {
            file >> x >> y;
            dist = x * x + y * y;
            if(dist <= 1) {
                inside++;
            } else {
                outside++;
            }
        }
        
        cout << "inside: " << inside << endl;
        cout << "outside: " << outside << endl;
        
        file.close();

        return 0;
    }
    ```

## Zadanie 2

=== "Python"

    ```python linenums="1"
    with open("kik.txt") as file:
        points = [list(map(float, str.split(" "))) for str in file.read().split("\n")]

    max_length = 0
    current_length = 0
    for point in points:
        x = point[0]
        y = point[1]
        dist = x * x + y * y
        if dist <= 1:
            current_length += 1
            max_length = max(current_length, max_length)
        else:
            current_length = 0

    print(max_length)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>

    using namespace std;

    int main() {
        ifstream file("kik.txt");
        double x, y, dist;
        int max_length = 0, current_length = 0;
        for(int i = 0; i < 10000; i++) {
            file >> x >> y;
            dist = x * x + y * y;
            if(dist <= 1) {
                current_length++;
                if(current_length > max_length) {
                    max_length = current_length;
                }
            } else {
                current_length = 0;
            }
        }
        
        cout << max_length << endl;
        
        file.close();

        return 0;
    }
    ```

## Zadanie 3

=== "Python"

    ```python linenums="1"
    with open("kik.txt") as file:
        points = [list(map(float, str.split(" "))) for str in file.read().split("\n")]

    xs = [point[0] for point in points]
    xs.sort()
    print(((xs[len(xs) // 2] - xs[len(xs) // 2 - 1]) / 2) + xs[len(xs) // 2 - 1])
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <algorithm>

    using namespace std;

    int main() {
        ifstream file("kik.txt");
        double x, y;
        double xs[10000];
        for(int i = 0; i < 10000; i++) {
            file >> x >> y;
            xs[i] = x;
        }
        
        file.close();

        sort(xs, xs + 10000);
        
        cout << ((xs[5000] - xs[4999]) / 2) + xs[4999] << endl;

        return 0;
    }
    ```

## Zadanie 4

=== "Python"

    ```python linenums="1"
    with open("kik.txt") as file:
        points = [list(map(float, str.split(" "))) for str in file.read().split("\n")]

    points = points[:100]
    points = [[int(point[0] * 1000), int(point[1] * 1000)] for point in points]
    for i in range(len(points)):
        for j in range(1, len(points) - i):
            x1 = points[j][0]
            y1 = points[j][1]
            x2 = points[j - 1][0]
            y2 = points[j - 1][1]
            if x1 < x2 or (x1 == x2 and y1 < y2):
                points[j - 1][0], points[j][0] = points[j][0], points[j - 1][0]
                points[j - 1][1], points[j][1] = points[j][1], points[j - 1][1]

    with open("kik_posortowane.txt", "w") as out_file:
        for point in points:
            print(point[0], point[1], file=out_file)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <cmath>

    using namespace std;

    int main() {
        ifstream file("kik.txt");
        double x, y;
        int points[100][2];
        for(int i = 0; i < 100; i++) {
            file >> x >> y;
            points[i][0] = x * 1000;
            points[i][1] = y * 1000;
        }
        
        file.close();

        for(int i = 0; i < 100; i++) {
            for(int j = 1; j < 100 - i; j++) {
                if(points[j][0] < points[j - 1][0] || (points[j][0] == points[j - 1][0] && points[j][1] < points[j - 1][1])) {
                    swap(points[j - 1][0], points[j][0]);
                    swap(points[j - 1][1], points[j][1]);
                }
            }
        }

        ofstream out_file("kik_posortowane.txt");
        for(int i = 0; i < 100; i++) {
            out_file << points[i][0] << " " << points[i][1] << endl;
        }
        
        out_file.close();

        return 0;
    }
    ```
