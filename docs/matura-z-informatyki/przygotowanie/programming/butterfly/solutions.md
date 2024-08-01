# Rozwiązania

## Zadanie 1

=== "Python"

    ```python linenums="1"
    movement = {"L": (-1, 0, 0),
                "R": (1, 0, 0),
                "U": (0, 1, 0),
                "D": (0, -1, 0),
                "F": (0, 0, 1),
                "B": (0, 0, -1)}
    side = 8
    with open("motylek.txt", "r") as file:
        x, y, z = (0, 0, 0)
        moves = file.read().split()
        for num, move in enumerate(moves):
            xm, ym, zm = movement[move]
            x += xm
            y += ym
            z += zm
            if not (-side <= x <= side and -side <= y <= side and -side <= z <= side):
                print(num + 1)
                print(x - xm, y - ym, z - zm)
                break
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <map>

    using namespace std;

    int main() {
        map<string, tuple<int, int, int>> movement = {
            {"L", {-1, 0, 0}},
            {"R", {1, 0, 0}},
            {"U", {0, 1, 0}},
            {"D", {0, -1, 0}},
            {"F", {0, 0, 1}},
            {"B", {0, 0, -1}}
        };

        int side = 8;
        ifstream file("motylek.txt");

        int x = 0, y = 0, z = 0;
        string move;

        while(file >> move && !file.eof()) {
            auto [xm, ym, zm] = movement[move];
            x += xm;
            y += ym;
            z += zm;

            if (!( -side <= x && x <= side && -side <= y && y <= side && -side <= z && z <= side)) {
                cout << num + 1 << endl;
                cout << x - xm << " " << y - ym << " " << z - zm << endl;
                break;
            }
        }

        file.close();

        return 0;
    }
    ```

## Zadanie 2

=== "Python"

    ```python linenums="1"
    movement = {"L": (-1, 0, 0),
                "R": (1, 0, 0),
                "U": (0, 1, 0),
                "D": (0, -1, 0),
                "F": (0, 0, 1),
                "B": (0, 0, -1)}
    side = 8
    result = 0
    with open("motylek.txt") as file:
        x, y, z = (0, 0, 0)
        moves = file.read().split()
        for num, move in enumerate(moves):
            xm, ym, zm = movement[move]
            x += xm
            y += ym
            z += zm
            if not (-side <= x <= side and -side <= y <= side and -side <= z <= side):
                x -= xm
                y -= ym
                z -= zm
            else:
                result += 1

        print(result)
        print(x, y, z)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <map>

    using namespace std;

    int main() {
        map<string, tuple<int, int, int>> movement = {
            {"L", {-1, 0, 0}},
            {"R", {1, 0, 0}},
            {"U", {0, 1, 0}},
            {"D", {0, -1, 0}},
            {"F", {0, 0, 1}},
            {"B", {0, 0, -1}}
        };

        int side = 8;
        ifstream file("motylek.txt");

        int x = 0, y = 0, z = 0, result = 0;
        string move;

        while(file >> move && !file.eof()) {
            auto [xm, ym, zm] = movement[move];
            x += xm;
            y += ym;
            z += zm;

            if (!( -side <= x && x <= side && -side <= y && y <= side && -side <= z && z <= side)) {
                x -= xm;
                y -= ym;
                z -= zm;
            } else {
                ++result;
            }
        }

        file.close();

        cout << result << endl;
        cout << x << " " << y << " " << z << endl;

        return 0;
    }
    ```

## Zadanie 3

=== "Python"

    ```python linenums="1"
    movement = {"L": (-1, 0, 0),
                "R": (1, 0, 0),
                "U": (0, 1, 0),
                "D": (0, -1, 0),
                "F": (0, 0, 1),
                "B": (0, 0, -1)}
    side = 8
    min_num = 0
    max_num = 0
    current_length = 1
    max_length = 1
    with open("motylek.txt") as file:
        x, y, z = (0, 0, 0)
        moves = file.read().split()
        for num, move in enumerate(moves):
            xm, ym, zm = movement[move]
            x += xm
            y += ym
            z += zm
            if not (-side <= x <= side and -side <= y <= side and -side <= z <= side):
                x -= xm
                y -= ym
                z -= zm
                
                current_length = 1
            else:
                current_length += 1

            if current_length > max_length:
                max_length = current_length
                max_num = num + 1
                min_num = max_num - max_length + 1

        print(max_length)
        print(min_num, max_num)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <map>

    using namespace std;

    int main() {
        map<string, tuple<int, int, int>> movement = {
            {"L", {-1, 0, 0}},
            {"R", {1, 0, 0}},
            {"U", {0, 1, 0}},
            {"D", {0, -1, 0}},
            {"F", {0, 0, 1}},
            {"B", {0, 0, -1}}
        };

        int side = 8;
        ifstream file("motylek.txt");

        int x = 0, y = 0, z = 0;
        int num = 0, min_num = 0, max_num = 0, current_length = 1, max_length = 1;
        string move;

        while(file >> move && !file.eof()) {
            ++num;
            auto [xm, ym, zm] = movement[move];
            x += xm;
            y += ym;
            z += zm;

            if (!( -side <= x && x <= side && -side <= y && y <= side && -side <= z && z <= side)) {
                x -= xm;
                y -= ym;
                z -= zm;
                
                current_length = 1;
            } else {
                current_length += 1;
            }

            if (current_length > max_length) {
                    max_length = current_length;
                    max_num = num;
                    min_num = max_num - max_length + 1;
                }
        }

        file.close();

        cout << max_length << endl;
        cout << min_num << " " << max_num << endl;

        return 0;
    }
    ```

## Zadanie 4

=== "Python"

    ```python linenums="1"
    movement = {"L": (-1, 0, 0),
                "R": (1, 0, 0),
                "U": (0, 1, 0),
                "D": (0, -1, 0),
                "F": (0, 0, 1),
                "B": (0, 0, -1)}
    side = 8
    result = 0
    with open("motylek.txt") as file:
        x, y, z = (0, 0, 0)
        moves = file.read().split()
        for num, move in enumerate(moves):
            xm, ym, zm = movement[move]
            x += xm
            y += ym
            z += zm
            if not (-side <= x <= side and -side <= y <= side and -side <= z <= side):
                x = xm
                y = ym
                z = zm
                result += 1

        print(result)
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <fstream>
    #include <map>

    using namespace std;

    int main() {
        map<string, tuple<int, int, int>> movement = {
            {"L", {-1, 0, 0}},
            {"R", {1, 0, 0}},
            {"U", {0, 1, 0}},
            {"D", {0, -1, 0}},
            {"F", {0, 0, 1}},
            {"B", {0, 0, -1}}
        };

        int side = 8;
        ifstream file("motylek.txt");

        int x = 0, y = 0, z = 0, result = 0;
        string move;

        while(file >> move && !file.eof()) {
            auto [xm, ym, zm] = movement[move];
            x += xm;
            y += ym;
            z += zm;

            if (!( -side <= x && x <= side && -side <= y && y <= side && -side <= z && z <= side)) {
                x = xm;
                y = ym;
                z = zm;
                ++result;
            }
        }

        file.close();
        
        cout << result << endl;

        return 0;
    }
    ```

## Zadanie 5

=== "Python"

    ```python linenums="1"
    movement = {"L": (-1, 0, 0),
                "R": (1, 0, 0),
                "U": (0, 1, 0),
                "D": (0, -1, 0),
                "F": (0, 0, 1),
                "B": (0, 0, -1)}
    positions = [(0, 0, 0)]
    with open("motylek.txt") as file:
        x, y, z = (0, 0, 0)
        moves = file.read().split()
        for num, move in enumerate(moves):
            xm, ym, zm = movement[move]
            x += xm
            y += ym
            z += zm
            positions.append((x, y, z))

    max_dist = 0
    p1 = (0,0,0)
    p2 = (0,0,0)
    for i in range(len(positions)):
        for j in range(i + 1, len(positions)):
            x1, y1, z1 = positions[i]
            x2, y2, z2 = positions[j]
            dist = (x1-x2)**2 + (y1-y2)**2 + (z1-z2)**2
            if dist > max_dist:
                max_dist = dist
                p1 = positions[i]
                p2 = positions[j]

    print(p1, p2)
    print(f"{(max_dist**0.5):.2f}")
    ```

=== "C++"

    ```cpp linenums="1"
    #include <iostream>
    #include <iomanip>
    #include <fstream>
    #include <vector>
    #include <map>
    #include <cmath>

    using namespace std;

    int main() {
        map<string, tuple<int, int, int>> movement = {
            {"L", {-1, 0, 0}},
            {"R", {1, 0, 0}},
            {"U", {0, 1, 0}},
            {"D", {0, -1, 0}},
            {"F", {0, 0, 1}},
            {"B", {0, 0, -1}}
        };

        ifstream file("motylek.txt");

        int x = 0, y = 0, z = 0;
        string move;
        vector<tuple<int, int, int>> positions;
        positions.push_back({0, 0, 0});

        while(file >> move && !file.eof()) {
            auto [xm, ym, zm] = movement[move];
            x += xm;
            y += ym;
            z += zm;
            positions.push_back({x, y, z});
        }

        file.close();

        int max_dist = 0;
        tuple<int, int, int> p1 = {0, 0, 0}, p2 = {0, 0, 0};

        for(int i = 0; i < positions.size(); ++i) {
            for(int j = i + 1; j < positions.size(); ++j) {
                auto [x1, y1, z1] = positions[i];
                auto [x2, y2, z2] = positions[j];
                int dist = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2);
                if (dist > max_dist) {
                    max_dist = dist;
                    p1 = positions[i];
                    p2 = positions[j];
                }
            }
        }

        cout << get<0>(p1) << " " << get<1>(p1) << " " << get<2>(p1) << endl;
        cout << get<0>(p2) << " " << get<1>(p2) << " " << get<2>(p2) << endl;
        cout << fixed << setprecision(2) << sqrt(max_dist) << endl;

        return 0;
    }
    ```
