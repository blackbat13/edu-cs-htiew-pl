# Punkt na odcinku

## [:link: Opis problemu](../../../../algorithms/2d-geometry/point-on-segment.md)

## Implementacja

```cpp linenums="1"
#include <iostream>

using namespace std;

struct Point2D {
    int x;
    int y;
};

int det3(int matrix[3][3]) {
    return matrix[0][0] * matrix[1][1] * matrix[2][2]
        + matrix[1][0] * matrix[2][1] * matrix[0][2]
        + matrix[2][0] * matrix[0][1] * matrix[1][2]
        - matrix[0][2] * matrix[1][1] * matrix[2][0]
        - matrix[0][1] * matrix[1][0] * matrix[2][2]
        - matrix[0][0] * matrix[1][2] * matrix[2][1];
}

bool pointOnSegment(Point2D a, Point2D b, Point2D c) {
    int matrix[3][3] = {{a.x, a.y, 1}, {b.x, b.y, 1}, {c.x, c.y, 1}};

    if (det3(matrix) != 0) {
        return false;
    }

    return min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x) 
        && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y);
}

int main() {
    Point2D a = {1, 1};
    Point2D b = {5, 5};
    Point2D c = {2, 2};

    bool result = pointOnSegment(a, b, c);

    if (result) {
        cout << "Point (" << c.x << ", " << c.y << ") on segment [(" 
                  << a.x << ", " << a.y << "), (" << b.x << ", " << b.y << ")]" << endl;
    } else {
        cout << "Point (" << c.x << ", " << c.y << ") not on segment [(" 
                  << a.x << ", " << a.y << "), (" << b.x << ", " << b.y << ")]" << endl;
    }

    return 0;
}
```
