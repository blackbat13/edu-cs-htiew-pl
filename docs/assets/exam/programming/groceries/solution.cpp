#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void exercise1() {
    ifstream file("groceries.txt");
    string name;
    int quantity;
    double price, result = 0;
    while (file >> name >> quantity >> price) {
        result += quantity * price;
    }

    cout << "Zadanie 1: " << fixed << setprecision(2) << result << endl;
    file.close();
}

int main() {
    exercise1();
    return 0;
}