# Pętla warunkowa

W języku C++ mamy dwa rodzaje pętli warunkowych: **while** oraz **do while**.

## While

Pętla warunkowa w C++ ma standardową konstrukcję:

```cpp
while (warunek) {
    instrukcje
}
```

### Przykład

```cpp
int x = 1;

while (x < 10) {
    cout << x << endl;
    x++;
}
```

## Do while

Jest też druga forma tej pętli, w której warunek jest sprawdzany zawsze **po** wykonaniu instrukcji w pętli.

### Przykład

```cpp
int x = 1;

do {
    cout << x << endl;
    x++;
} while (x < 10);
```

## Różnice

Główna różnica pomiędzy pętlami `while` i `do while` dotyczy momentu, w którym sprawdzany jest warunek. Najlepiej można to zobaczyć na przykładzie, w którym warunek pętli nie jest spełniony już na samym początku:

```cpp
int x = 1;

while (x < 1) {
    cout << "while" << endl;
    x++;
}

do {
    cout << "do while" << endl;
    x++;
} while (x < 1);
```
