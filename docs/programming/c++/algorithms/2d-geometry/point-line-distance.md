# Odległość punktu od prostej

## [Opis problemu](../../../../algorithms/2d-geometry/point-line-distance.md)


## Implementacja

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

