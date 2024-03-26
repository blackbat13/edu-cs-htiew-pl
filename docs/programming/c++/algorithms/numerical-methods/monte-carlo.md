# Metoda Monte Carlo

## [Opis problemu](../../../../algorithms/numerical-methods/monte-carlo.md)


## Implementacja

```cpp linenums="1"
#include <iostream>
#include <random>
#include <ctime>

using namespace std;

double monteCarloPi(int pointsCount) {
    int numPointsInCircle = 0;
    double centerX = 1;
    double centerY = 1;
    double radius = 1;
    double x, y, distance;
    
    for (int i = 0; i < pointsCount; i++) {
        x = (double) rand() / RAND_MAX * 2.0;
        y = (double) rand() / RAND_MAX * 2.0;
        distance = ((x - centerX) * (x - centerX)) + ((y - centerY) * (y - centerY));
        
        if (distance <= radius * radius) {
            numPointsInCircle += 1;
        }
    }
    
    return (4.0 * numPointsInCircle) / (double) pointsCount;
}

int main() {
    srand(time(NULL));
    
    int pointsCount = 10000;

    double estimatedPi = monteCarloPi(pointsCount);
    
    cout << "PI ~= " << estimatedPi << endl;
    
    return 0;
}
```

