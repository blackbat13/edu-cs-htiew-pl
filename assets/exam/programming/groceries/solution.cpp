#include <iostream>
#include <fstream>
#include <iomanip>
#include <map>

using namespace std;

void exercise1()
{
    ifstream file("groceries.txt");
    string name;
    int quantity;
    double price, result = 0;
    while (file >> name >> quantity >> price)
    {
        result += quantity * price;
    }

    cout << "Zadanie 1: " << fixed << setprecision(2) << result << endl;
    file.close();
}

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}

void exercise2()
{
    ifstream file("groceries.txt");
    string name;
    int quantity;
    double price, result = 0;
    while (file >> name >> quantity >> price)
    {
        if (isPrime(name.size()))
        {
            result += quantity * price * 0.5;
        }
        else
        {
            result += quantity * price;
        }
    }
    cout << "Zadanie 2: " << fixed << setprecision(2) << result << endl;
    file.close();
}

void exercise3() {
    ifstream file("groceries.txt");
    string name;
    int quantity, quantitySum = 0;
    double price, priceSum = 0, result;
    while (file >> name >> quantity >> price)
    {
        quantitySum += quantity;
        priceSum += quantity * price;
    }
    result = priceSum / quantitySum;
    cout << "Zadanie 3: " << fixed << setprecision(2) << result << endl;
    file.close();
}

void exercise4() {
    ifstream file("groceries.txt");
    string name;
    int quantity;
    double price;
    map<string, int> groceries;
    while (file >> name >> quantity >> price)
    {
        groceries[name] += quantity;
    }

    cout << "Zadanie 4: " << endl;
    
    for(auto item : groceries) {
        cout << item.first << ": " << item.second << endl;
    }
    
    file.close();
}

int main()
{
    exercise1();
    exercise2();
    exercise3();
    exercise4();
    return 0;
}