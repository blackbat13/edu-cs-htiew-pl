# C++ - rozwiązania

## Wczytanie danych

Zacznijmy od wczytania danych z pliku. Liczby są zapisane osobno w każdej linii, więc ich wczytanie jest proste. Wczytane liczby binarne w postaci tekstowej zapiszemy w liście nazwanej `binaryNumbersTab`.

```cpp
#include <iostream>
#include <fstream>

using namespace std;

void readData(string binaryNumbersTab[]) {
    ifstream dataFile("liczby.txt");

    for (int i = 0; i < 1000; i++) {
        dataFile >> binaryNumbersTab[i];
    }
    
    dataFile.close();
}

int main() {
    string binaryNumbersTab[1000];

    readData(binaryNumbersTab);

    return 0;
}
```

## Zadanie 1

Aby sprawdzić, czy liczba binarna jest parzysta, wystarczy spojrzeć na jej **ostatnią** (najmniej znaczącą) cyfrę.

```cpp
int countEven(string binaryNumbersTab[]) {
    int count = 0;  // Licznik liczb parzystych
    for (int i = 0; i < 1000; i++) {
        string binary = binaryNumbersTab[i];
        if (binary[binary.size() - 1] == '0') {  // Jeżeli ostatni znak liczby binarnej to 0
            count++;  // zwiększamy licznik liczb parzystych
        }
    }
    
    return count;
}
```

## Zadanie 2

Aby sprawdzić, czy liczba binarna jest podzielna przez $4$ wystarczy sprawdzić jej **dwie ostatnie** (najmniej znaczące) cyfry. Jeżeli są równe $0$, to liczba jest podzielna przez $4$.

```cpp
int countDivisibleBy4(string binaryNumbersTab[]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        string binary = binaryNumbersTab[i];
        if (binary[binary.size() - 1] == '0' && binary[binary.size() - 2] == '0') {
            count++;
        }
    }

    return count;
}
```

## Zadanie 3

Zamieniamy liczbę binarną na system dziesiętny i sprawdzamy podzielność przez 10 za pomocą operatora modulo (reszty z dzielenia).

```cpp
int binaryToDecimal(string binary) {  // Funkcja konwertująca liczbę binarną reprezentowaną jako tekst na liczbę naturalną w systemie dziesiętnym
    int decimal = 0;  // Wartość w systemie 10
    int power = 1;  // Potęga 2
    // Idziemy pętlą od końca
    for (int i = binary.size() - 1; i >= 0; i--) {
        decimal += (binary[i] - '0') * power;  // Przemnażamy cyfrę przez potęgę dwójki
        power *= 2;  // Zwiększamy potęgę dwójki
    }
    
    return decimal;
}

int countDivisibleBy10(string binaryNumbersTab[]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        string binary = binaryNumbersTab[i];
        int decimal = binaryToDecimal(binary)
        if (decimal % 10 == 0) {
            count++;
        }
    }

    return count;
}
```

## Zadanie 4

Liczba binarna jest potęgą dwójki, jeżeli w jej zapisie występuje dokładnie jedna jedynka.
 
```cpp
#include <map>

int countPowerOf2(string binaryNumbersTab[]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        string binary = binaryNumbersTab[i];
        map<char, int> digitCounter;  // Słownik do zliczania cyfr 0 i 1
        digitCounter['0'] = 0;  // Inicjalizujemy liczniki zer i jedynek
        digitCounter['1'] = 0;
        for (int pos = 0; pos < binary.size(); pos++) {  // Dla każdej cyfry w zapisie liczby binarnej
            char digit = binary[pos];
            digitCounter[digit]++;  // Zwiększamy licznik dla danej cyfry
        }

        if (digitCounter['1'] == 1) {
            count++;
        }
    }

    return count;
}
```

## Zadanie 5

```cpp
#include <map>

int countMoreZeroes(string binaryNumbersTab[]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        string binary = binaryNumbersTab[i];
        map<char, int> digitCounter;  // Słownik do zliczania cyfr 0 i 1
        digitCounter['0'] = 0;  // Inicjalizujemy liczniki zer i jedynek
        digitCounter['1'] = 0;
        for (int pos = 0; pos < binary.size(); pos++) {  // Dla każdej cyfry w zapisie liczby binarnej
            char digit = binary[pos];
            digitCounter[digit]++;  // Zwiększamy licznik dla danej cyfry
        }

        if (digitCounter['0'] > digitCounter['1']) {
            count++;
        }
    }

    return count;
}
```

## Zadanie 6

```cpp
#include <map>

int countMoreOnes(string binaryNumbersTab[]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        string binary = binaryNumbersTab[i];
        map<char, int> digitCounter;  // Słownik do zliczania cyfr 0 i 1
        digitCounter['0'] = 0;  // Inicjalizujemy liczniki zer i jedynek
        digitCounter['1'] = 0;
        for (int pos = 0; pos < binary.size(); pos++) {  // Dla każdej cyfry w zapisie liczby binarnej
            char digit = binary[pos];
            digitCounter[digit]++;  // Zwiększamy licznik dla danej cyfry
        }

        if (digitCounter['1'] > digitCounter['0']) {
            count++;
        }
    }

    return count;
}
```

## Zadanie 7

```cpp
#include <map>

int countEqualZeroesAndOnes(string binaryNumbersTab[]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        string binary = binaryNumbersTab[i];
        map<char, int> digitCounter;  // Słownik do zliczania cyfr 0 i 1
        digitCounter['0'] = 0;  // Inicjalizujemy liczniki zer i jedynek
        digitCounter['1'] = 0;
        for (int pos = 0; pos < binary.size(); pos++) {  // Dla każdej cyfry w zapisie liczby binarnej
            char digit = binary[pos];
            digitCounter[digit]++;  // Zwiększamy licznik dla danej cyfry
        }

        if (digitCounter['1'] == digitCounter['0']) {
            count++;
        }
    }

    return count;
}
```

## Zadanie 8

```cpp
int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 1;
    for (int i = binary.size() - 1; i >= 0; i--) {
        decimal += (binary[i] - '0') * power;
        power *= 2;
    }
    
    return decimal;
}

void findMinMax(string binaryNumbersTab[]) {
    int minDec = binaryToDecimal(binaryNumbersTab[0]);
    string minBin = binaryNumbersTab[0];
    int maxDec = minDec;
    string maxBin = binaryNumbersTab[0];
    for (int i = 1; i < 1000; i++) {
        string binary = binaryNumbersTab[i];
        decimal = binaryToDecimal(binary);

        if (decimal < minDec) {
            minDec = decimal;
            minBin = binary;
        }

        if (decimal > maxDec) {
            maxDec = decimal;
            maxBin = binary;
        }
    }

    cout << minBin << endl;
    cout << maxBin << endl;
}
```

## Zadanie 9

```cpp
#include <set>

int countUnique(string binaryNumbersTab[]) {
    set<string> binaryNumbersSet;
    for (int i = 0; i < 1000; i++) {
        string binary = binaryNumbersTab[i];
        binaryNumbersSet.insert(binary);
    }

    return binaryNumbersSet.size(); 
}
```

## Zadanie 10

```cpp
#include <map>

void count4Rest(string binaryNumbersTab[]) {
    map <string, int> dictCounter;
    // Tworzymy słownik liczników, który inicjalizujemy różnymi końcówkami liczb binarnych, które odpowiadają kolejnym resztom z dzielenia przez 4
    dictCounter["00"] = 0;
    dictCounter["01"] = 0;
    dictCounter["10"] = 0;
    dictCounter["11"] = 0;
    for (int i = 0; i < 1000; i++) {
        string binary = binaryNumbersTab[i];
        string lastTwo = "" + binary[binary.size() - 2] + binary[binary.size() - 1];  // Zwiększamy odpowiedni licznik
    }

    cout << restCounter["00"] << endl;
    cout << restCounter["01"] << endl;
    cout << restCounter["10"] << endl;
    cout << restCounter["11"] << endl;
}
```

## Zadanie 11

```cpp
int count1OnOdds(string binaryNumbersTab[]) {
    int count = 0;
    for (int i = 0; i < 1000; i++) {
        string binary = binaryNumbersTab[i];
        bool correct = true;
        for (int pos = 0; pos < binary.size(); pos++) {
            if ((pos + 1) % 2 == 0 && binary[pos] == '1') {  // Sprawdzamy, czy jedynka pojawiła się na parzystej pozycji
                correct = false;
                break;
            }
        }

        if (correct) {
            count++;
        }
    }

    return count;
}
```

## Zadanie 12

```cpp
int binaryToDecimal(string binary) {
    int decimal = 0;
    int power = 1;
    for (int i = binary.size() - 1; i >= 0; i--) {
        decimal += (binary[i] - '0') * power;
        power *= 2;
    }
    
    return decimal;
}

void findLongestGrowingSubstring(string binaryNumbersTab[]) {
    int maxLength = 1;  // Długość najdłuższego podciągu rosnącego
    int maxFirstIndex = 0;  // Indeks pierwszej wartości w najdłuższym podciągu rosnącym

    int currentLength = 1;  // Długość obecnie obliczanego ciągu
    int currentFirstIndex = 0;  // Indeks pierwszej wartości w obecnie obliczanym ciągu

    for (int i = 1; index < 1000; i++) {
        // Porównujemy obecną wartość z poprzednią
        if (binaryToDecimal(binaryNumbersTab[i]) > binaryToDecimal(binaryNumbersTab[i - 1])) {
            currentLength++;
        } else {
            currentLength = 1;
            currentFirstIndex = i;
        }

        if currentLength > maxLength {
            maxLength = currentLength;
            maxFirstIndex = currentFirstIndex;
        }
    }

    cout << "Długość: " << maxLength << endl;
    cout << "Indeks pierwszego el. :" << maxFirstIndex << endl;
    cout << "Indeks ostatniego el.: " << maxFirstIndex + maxLength - 1 << endl;
    maxLastIndex = maxFirstIndex + maxLength;
    for(int i = 0; i < 1000; i++) {
        cout << binaryNumbersTab(maxFirstIndex + i);
    }

    cout << endl;
}
```
