# Flood Fill

## Opis problemu

{% content-ref url="../../../../algorithms/graphs/flood-fill.md" %}
[flood-fill.md](../../../../algorithms/graphs/flood-fill.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>

using namespace std;

void floodFill(string image[], int row, int column, char symbol='*') {
    if (image[row][column] != ' ') {
        return;
    }

    image[row][column] = symbol;
    int directionsRow[] = {1, -1, 0, 0};
    int directionsColumn[] = {0, 0, 1, -1};

    for (int i = 0; i < 4; i++) {
        floodFill(image, row + directionsRow[i], column + directionsColumn[i]);
    }
}

void printImage(string image[], int height) {
    for (int i = 0; i < height; i++) {
        cout << image[i] << endl;
    }
}

int main() {
    string image[] = {
        "########",
        "#  #   #",
        "#  #   #",
        "#  #   #",
        "### ####",
        "#  #   #",
        "#  #   #",
        "########"
    };

    printImage(image, 8);
    cout << endl;

    floodFill(image, 1, 1);

    printImage(image, 8);

    return 0;
}
```
{% endcode %}
