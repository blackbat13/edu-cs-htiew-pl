# Tablice statyczne

Tablice statyczne charakteryzują się tym, że mają ustalony rozmiar. Gdy raz utworzymy tablicę statyczną, to nie możemy już zmieniać jej rozmiaru.

{% hint style="info" %}
Elementy w tablicy indeksujemy (numerujemy) od $$0$$.
{% endhint %}

## Inicjalizacja tablicy

### Tablica o zadanej długości, bez zdefiniowanych wartości początkowych

```cpp
int tab[10];
```

### Inicjalizacja danymi początkowymi

```cpp
int tab[5] = {1, 2, 3, 4, 5};
```

Gdy podamy mniej wartości, niż wskazuje długość tablicy, to pozostałe miejsca zostaną wypełnione wartością domyślną dla danego typu (np. $$0$$ dla liczb).

```cpp
int tab[10] = {1, 2, 3, 4, 5};
```

### Tablica o długości zadanej przez zmienną

Możemy utworzyć tablicę statyczną podając jej rozmiar za pomocą zmiennej. W takim przypadku nie możemy jednak zainicjalizować tablicy danymi początkowymi tak jak pokazano powyżej.

```cpp
int n = 10;
int tab[n];
```

## Podstawowe operacje

### Odczytanie wartości pod zadanym indeksem

```cpp
cout << tab[2] << endl;
```

### Zmiana wartości pod zadanym indeksem

```cpp
tab[2] = 10;
```

### Iteracja po tablicy

```cpp
int tab[5] = {1, 2, 3, 4, 5};
for (int i = 0; i < 5; i++) {
    cout << tab[i] << endl;
}
```

### Iteracja pętlą for in

```cpp
int tab[5] = {1, 2, 3, 4, 5};
for (int el : tab) {
    cout << el << endl;
}
```
