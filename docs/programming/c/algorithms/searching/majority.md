# Znajdowanie lidera w zbiorze

## [Opis problemu](../../../../algorithms/searching/majority.md)


## Implementacja

```c linenums="1"
#include <stdio.h>

int countOccurences(int number, int array[], int length) {
    int result = 0;

    for (int i = 0; i < length; i++) {
        if (array[i] == number) {
            result++;
        }
    }

    return result;
}

int findMajority(int array[], int length) {
    int counter = 1;
    int currentCandidate = array[0];
    
    for (int i = 1; i < length; i++) {
        if (counter == 0) {
            currentCandidate = array[i];
            counter = 1;
        } else if (array[i] == currentCandidate) {
            counter++;
        } else {
            counter--;
        }
    }

    counter = countOccurences(currentCandidate, array, length);

    if (counter > length / 2) {
        return currentCandidate;
    } else {
        return -1;
    }
}

int main() {
    int array[10] = {1, 2, 5, 5, 7, 5, 5, 10, 5, 5};

    int majority = findMajority(array, 10);

    if (majority == -1) {
      printf("Majority element not found\n");
    } else {
      printf("Majority element: %d\n", majority);
    }

    return 0;
}
```

