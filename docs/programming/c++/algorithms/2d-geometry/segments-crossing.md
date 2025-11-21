# Przecinanie się odcinków

## [:link: Opis problemu](../../../../algorithms/2d-geometry/segments-crossing.md)

## Implementacja

```cpp linenums="1"
#include <iostream>
#include <algorithm>

using namespace std;

struct Point {
    int x;
    int y;
};

int det3(int matrix[3][3]) {
    return (
        matrix[0][0] * matrix[1][1] * matrix[2][2]
        + matrix[1][0] * matrix[2][1] * matrix[0][2]
        + matrix[2][0] * matrix[0][1] * matrix[1][2]
        - matrix[0][2] * matrix[1][1] * matrix[2][0]
        - matrix[0][1] * matrix[1][0] * matrix[2][2]
        - matrix[0][0] * matrix[1][2] * matrix[2][1]
    );
}

bool point_on_segment(Point a, Point b, Point c) {
    int matrix[3][3] = {{a.x, a.y, 1}, {b.x, b.y, 1}, {c.x, c.y, 1}};

    if (det3(matrix) != 0) {
        return false;
    }

    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) && 
           min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

int sgn(int a) {
    if (a < 0) {
        return -1;
    } else if (a > 0) {
        return 1;
    } else {
        return 0;
    }
}

bool segment_crossing(Point a, Point b, Point c, Point d) {
    int matrix1[3][3] = {{a.x, a.y, 1}, {b.x, b.y, 1}, {c.x, c.y, 1}};
    int matrix2[3][3] = {{a.x, a.y, 1}, {b.x, b.y, 1}, {d.x, d.y, 1}};
    
    return (
        point_on_segment(a, b, c)
        || point_on_segment(a, b, d)
        || point_on_segment(c, d, a)
        || point_on_segment(c, d, b)
        || sgn(det3(matrix1)) != sgn(det3(matrix2))
    );
}

int main() {
    Point a = {1, 1};
    Point b = {2, 2};
    Point c = {3, 3};
    Point d = {4, 4};

    bool result = segment_crossing(a, b, c, d);

    if (result) {
        cout << "Segments [(" << a.x << ", " << a.y << "), (" 
             << b.x << ", " << b.y << ")] and [(" << c.x << ", " 
             << c.y << "), (" << d.x << ", " << d.y << ")] cross" << endl;
    } else {
        cout << "Segments [(" << a.x << ", " << a.y << "), (" 
             << b.x << ", " << b.y << ")] and [(" << c.x << ", " 
             << c.y << "), (" << d.x << ", " << d.y << ")] do not cross" << endl;
    }

    return 0;
}
```

