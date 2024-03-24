# Funkcje

Funkcja w C++ składa się z nagłówka i ciała. Nagłówek definiuje nazwę funkcji, jej typ zwracany oraz parametry (jeśli takie istnieją), a ciało zawiera kod, który jest wykonywany, gdy funkcja jest wywoływana.

```cpp
typ_zwracany nazwa_funkcji(parametry) {
    // Ciało funkcji
}
```

Ze względu na typ zwracanej wartości możemy wyróżnić dwa rodzaje funkcji:

1. **Funkcje nie zwracające wartości (funkcje typu void):**
   ```cpp
   void hello() {
       std::cout << "Hello, World!" << std::endl;
   }
   ```
2. **Funkcje zwracające wartość określonego typu:**
   ```cpp
   int add(int a, int b) {
       return a + b;
   }
   ```

## Wywoływanie funkcji

Funkcję wywołuje się, podając jej nazwę i przekazując argumenty (jeśli są wymagane).

```cpp
hello();
```

```cpp
int result = add(5, 3);
```
