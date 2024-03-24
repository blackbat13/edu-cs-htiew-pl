# Funkcje printf i scanf

## Znaki specjalne

* &#x20;\- znak nowej linii
* &#x20;\- tabulacja pozioma
* `\v` - tabulacja pionowa
* `\b` - backspace
* `\a` - alarm
* `\\` - backslash
* `\?` - znak
* `` \` `` - apostrof
* `\"` - cudzysłów

## Formaty typów

| Typ                      | Format     |
| ------------------------ | ---------- |
| `char`                   | `%c`       |
| `unsigned char`          | `%c`       |
| `short`                  | `%h`       |
| `unsigned short`         | `%uh`      |
| `int`                    | `%d`, `%i` |
| `unsigned int`           | `%u`       |
| `long int`               | `%ld`      |
| `unsigned long int`      | `%lu`      |
| `long long int`          | `%lld`     |
| `unsigned long long int` | `%llu`     |
| `float`                  | `%f`, `%F` |
| `double`                 | `%lf`      |
| `long double`            | `%Lf`      |
| `char*`                  | `%s`       |

### Formaty specjalne

| Opis                                                              | Format     |
| ----------------------------------------------------------------- | ---------- |
| notacja naukowa                                                   | `%e`, `%E` |
| notacja standardowa lub naukowa, w zależności od wielkości liczby | `%g`, `%G` |
| `unsigned int `w formacie oktalnym (ósemkowym)                    | `%o`       |
| `unsigned int` w formacie heksadecymalnym (szesnastkowym)         | `%x`, `%X` |
| `double `w formacie heksadecymalnym (szesnastkowym)               | `%a`, `%A` |

## Biblioteka

Funkcje `printf` oraz `scanf` znajdują się w standardowej bibliotece wejścia/wyjścia (standard input/output):

```cpp
#include <cstdio>
```

## Printf

Funkcja `printf` przyjmuje dwa argumenty:

* format wypisywanego komunikatu,
* listę oddzielonych przecinkami wartości do podstawienia.

Format jest standardowym tekstem, który może zawierać specjalne symbole określające, że w tym miejscu komunikatu ma zostać podstawiona kolejna wartość, przekazana jako drugi argument.

Funkcji `printf` możemy także użyć do wypisania komunikatu bez podawania wartości do podstawienia.

```cpp
printf("Hello World!");
```

Każdy symbol specjalny składający się ze znaku `%` i litery oznacza, że w to miejsce należy wstawić odpowiednią wartość. Np. `%d` w formacie zostanie zastąpiony wartością typu `int` podaną jako kolejny argument funkcji `printf`.

```cpp
printf("%d", 68); // 68
printf("Wynik to %d", 24); // Wynik to 24
```

### String

Najprostszym sposobem na wypisanie zmiennej typu `string `za pomocą funkcji `printf`, jest przekonwertowanie zmiennej na ciąg znaków z języka **C** (`const char*`) z użyciem funkcji `c_str()`.

```cpp
string txt = "Hello World!";
printf("%s", txt.c_str()); // Hello World!
```

### Formatowanie szerokości

Możemy wypisać wartość w polu o zadanej minimalnej szerokości. Aby to zrobić, bezpośrednio po znaku % podajemy liczbę określającą szerokość pola. Domyślnie wartości będą wyrównywane do prawej.

```cpp
printf("%3d", 0); 
printf("%3d", 123456789); 
printf("%8d", -10);
```

Aby wyrównać wartości do lewej, należy podać szerokość pola jako liczbę ujemną.

```cpp
printf("%-3d", 0);
printf("%-3d", 123456789);
printf("%-8d", -10);
```

### Uzupełnienie do szerokości pola

Wypisywaną wartość liczbową możemy uzupełnić zerami z lewej strony do wymaganej szerokości pola. W tym celu piszemy %0, zadaną szerokość pola i znak formatu.

```cpp
printf("%03d", 0); // 000
printf("%08d", 12); // 00000012
printf("%02d:%02d", 14, 5); // 14:05
```

### Liczby rzeczywiste

Domyślnie przy wypisywaniu liczb rzeczywistych zostaną one wypisane z dokładnością do 6 miejsc po przecinku. Możemy to jednak zmienić, pisząc %. i zadaną dokładność. Wartość zostanie zaokrąglona do zadanej liczby miejsc po przecinku.

```cpp
printf("%f", 12.85); // 12.850000
printf("%.2f", 12.85); // 12.85
printf("%.1f", 12.85); // 12.9
```

Możemy także połączyć określenie szerokości pola z dokładnością do zadanej liczby miejsc po przecinku. Należy pamiętać, że szerokość uwzględnia całą liczbę, łącznie ze znakiem kropki.

```cpp
printf("%6.2f", 12.85); // 12.85
printf("%06.2f", 12.85); // 012.85
printf("%-6.2f", 12.85);
```

### Notacja naukowa

W celu wypisania liczby rzeczywistej w formacie naukowym używamy formatu `%e`.

```cpp
printf("%e", 5.65); // 5.650000e+00
printf("%e", 5.653745343438343); // 5.653745e+00
printf("%e", 4342342343245.0); // 4.342342e+12
```

### Znak liczby

Aby zawsze wypisywać znak liczby, a nie tylko przy wartościach ujemnych, możemy podać znak $$+$$ przed literą formatu.

```cpp
printf("%+d", 5); // +5
printf("%+d", -5); // -5
```

### Inne systemy liczbowe

Za pomocą `printf` możemy w łatwy sposób wypisać liczbę naturalną w systemie oktalnym lub heksadecymalnym. Służą do tego odpowiednio formaty `%o` i `%x`.

```cpp
printf("%o", 127); // 177
printf("%x", 127); // 7f
printf("%X", 127); // 7F
```

### Link do przykładów

{% embed url="https://ideone.com/eMuOgx" %}
Printf - przykłady
{% endembed %}

## Scanf

Funkcja `scanf` pozwala nam wczytać dane od użytkownika. Jej użycie wygląda podobnie do `printf`. Najpierw podajemy format, a następnie zmienne, do których chcemy wczytać poszczególne wartości. W formacie zazwyczaj ograniczamy się do podania formatów wczytywanych wartości. Zmienne natomiast muszą być podane jako adres w pamięci, pod którym należy zapisać wczytaną wartość. Dlatego zazwyczaj zmienne poprzedzamy symbolem `&`.

```cpp
int a;
scanf("%d", &a);
```

### Ignorowanie znaku %

Możemy zignorować znak % podany na wejściu.

```cpp
int a;
scanf("%d%%", &a);
```

### Inne systemy liczbowe

Podobnie jak w przypadku `printf`, `scanf` możemy użyć do wczytania liczb w formatach oktalnym i heksadecymalnym.

```cpp
int a, b;
scanf("%o", &a); // 012
scanf("%x", &b); // Af
printf("a = %d, b = %d", a, b); // a = 10, b = 175
```

### Wczytywanie tekstów

Podobnie jak `printf`, `scanf` także nie obsługuje typu string. Możemy zamiast tego wczytać tekst do tablicy typu char. W przypadku tablic nie podajemy znaku `&`, ponieważ nazwa zmiennej tablicowej zwraca adres w pamięci, gdzie znajduje się początek tablicy.

```cpp
char txt[100];
scanf("%s", txt);
```

Alternatywnie:

```cpp
char txt[100];
scanf("%s", &txt[0]);
```

### Ignorowanie wejścia

Aby wczytać i zignorować wejście (lub jego fragment), czyli nie przypisywać wartości do zmiennej, możemy po znaku `%` dać `*`.

```cpp
int a;
scanf("%*s %d", &a);  // Age : 29
printf("a = %d", a);  // a = 29
```

### Maksymalna długość wejścia

Możemy określić, ile maksymalnie znaków ma zostać wczytanych. Reszta danych zostanie zignorowana.

```cpp
int a;
scanf("%2d", &a);     // 1234
printf("a = %d", a);  // a = 12
```

Możemy też nie ignorować reszty wejścia i przypisać je do kolejnej zmiennej.

```cpp
int a, b;
scanf("%2d%d", &a, &b);          // 1234
printf("a = %d, b = %d", a, b);  // a = 12, b = 34
```

### Koniec wejścia

W momencie napotkania końca wejścia, funkcja `scanf` zwróci stałą `EOF`. W celu wczytywania wejścia aż do jego końca możemy więc np. zastosować taką pętlę:

```cpp
int a;
while(scanf("%d", &a) != EOF) {
}
```

## Prezentacja

{% file src="../../../.gitbook/assets/Printf i Scanf (1).pdf" %}
Prezentacja
{% endfile %}
