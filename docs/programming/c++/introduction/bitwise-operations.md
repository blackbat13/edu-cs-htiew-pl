# Operacje bitowe

## Opis zagadnienia

[bitwise-operations.md](../../../algorithms/numeral-systems/bitwise-operations.md)

### Przesunięcie bitowe

Do przesunięcia w lewo stosujemy operator `<<`.

Do przesunięcia w prawo stosujemy operator `>>`.

```cpp
int x = 1 << 10;
cout << x << endl;

x = x >> 10;
cout << x << endl;
```

### Bitowy AND

```cpp
int a = 25;
int b = 30;

int c = a & b;

cout << c << endl;
```

### Bitowy OR

```cpp
int a = 25;
int b = 30;

int c = a | b;

cout << c << endl;
```

### Bitowy XOR

```cpp
int a = 25;
int b = 30;

int c = a ^ b;

cout << c << endl;
```

## Przykładowa implementacja

[https://replit.com/@damiankurpiewski/BitOperations](https://replit.com/@damiankurpiewski/BitOperations)
