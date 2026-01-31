# Odległość punktu od prostej

## [:link: Opis problemu](../../../../algorithms/2d-geometry/point-line-distance.md)

## Implementacja bez struktury

```cpp linenums="1"
#include <iostream>
#include <cmath>

using namespace std;

double pointLineDistance(double line1X, double line1Y, double line2X, double line2Y, double pointX, double pointY) {
    double xDiff = line2X - line1X;
    double yDiff = line2Y - line1Y;
    
    double result = abs(yDiff * (line1X - pointX) + xDiff * (pointY - line1Y)) / sqrt(yDiff * yDiff + xDiff * xDiff);

    return result;
}

int main() {
    double line1X = -3;
    double line1Y = -4;
    double line2X = 7;
    double line2Y = 6;
    double pointX = -5;
    double pointY = -8;

    double distance = pointLineDistance(line1X, line1Y, line2X, line2Y, pointX, pointY);
    
    cout << distance << endl;
    
    return 0;
}
```

## Implementacja ze strukturą

```cpp linenums="1"
#include <iostream>
#include <cmath>

using namespace std;

struct Point2D {
    double x, y;
};

double pointLineDistance(Point2D linePoint1, Point2D linePoint2, Point2D point) {
    Point2D diff = {linePoint2.x - linePoint1.x, linePoint2.y - linePoint1.y};
    
    double result = abs(diff.y * (linePoint1.x - point.x) + diff.x * (point.y - linePoint1.y)) / sqrt(diff.y * diff.y + diff.x * diff.x);

    return result;
}

int main() {
    Point2D linePoint1 = {-3, -4};
    Point2D linePoint2 = {7, 6};
    Point2D point = {-5, -8};

    double distance = pointLineDistance(linePoint1, linePoint2, point);
    
    cout << distance << endl;
    
    return 0;
}
```