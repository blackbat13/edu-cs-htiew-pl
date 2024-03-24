# Struktury

## Wstęp

Z czasem, gdy zaczynamy tworzyć coraz bardziej zaawansowane projekty programistyczne, zaczyna się okazywać, że podstawowe typy przestają wystarczać.
Nasz kod staje się coraz mniej czytelny i coraz trudniej się w nim zorientować, ponieważ mamy grupy zmiennych, które dotyczą tak naprawdę jednego "obiektu".
Dla przykładu wyobraźmy sobie, że piszemy program, który wykonuje obliczenia geometryczne i pracuje na punktach.
Każdy punkt jest reprezentowany przez dwie współrzędne: $$x$$ i $$y$$.
Potrzebujemy więc dwóch zmiennych do reprezentacji każdego punktu.
To już samo w sobie może okazać się problematyczne, w szczególności, gdy będziemy potrzebowali tablicy takich punktów.
Co wtedy zrobić? Stworzyć dwie tablice, jedną do współrzędnych $$x$$, drugą do współrzędnych $$y$$ i na nich pracować?
Trzeba wtedy pamiętać o tym, że wartości z dwóch tablic są ze sobą powiązane, więc jak np. chcemy zmienić ich kolejność, to powinniśmy to zrobić w dwóch tablicach.

W takiej sytuacji z pomocą przychodzą **struktury**.
Struktury (w dużym skrócie) pozwalają nam definiować własne typy i przydają się przede wszystkim w sytuacjach, gdy potrzebujemy połączyć grupę wartości w jedną, logiczną całość.
Przyjrzyjmy się poniższym przykładom.

## Przykład 1: punkt 2D

Zacznijmy od prostego przykładu punktu. 
Zdefiniujemy strukturę `Point`, która będzie przechowywać dwie wartości całkowite: współrzędne punktu.

### Implementacja

```c
#include <stdio.h>

typedef struct Point {
    int x;
    int y;
} Point;

int main() {
    Point point;

    printf("Creating new point with x = 5 and y = 3\n");
    point = (Point){5, 3};

    printf("Point x: %d\n", point.x);
    printf("Point y: %d\n", point.y);

    printf("\nAssigning new values to the point variable\n");

    point.x = 20;
    point.y = 13;
    printf("Point x: %d\n", point.x);
    printf("Point y: %d\n", point.y);

    return 0;
}
```

### Opis implementacji

Zaczynamy od zdefiniowania własnej struktury `Point` (**linia 3**).
Definicję struktury zaczynamy od słowa kluczowego `struct`, następnie podajemy jej nazwę i otwieramy blok kodu.
Aby używać skróconej nazwy nowego typu definiujemy ją za pomocą polecenia `typedef`, po definicji struktury podając nazwę naszego typu, w tym przypadku `Point` (**linia 6**).

W ciele struktury definiujemy dwie zmienne całkowite do przechowywania współrzędnych punktu: `x` (**linia 4**) oraz `y` (**linia 5**).
Dla czytelności robimy to w dwóch osobnych liniach, nic nie stoi jednak na przeszkodzie, by zdefiniować obie zmienne jedna po drugiej, po przecinku.

W części głównej programu na samym początku tworzymy zmienną _point_ korzystając z wcześniej zdefiniowanego nowego typu _Point_ (**linia 9**).

W celu przypisania wartości do naszej zmiennej możemy postąpić na dwa sposoby:
* Korzystając z notacji nawiasów klamrowych, podać wartości kolejnych zmiennych po przecinku (**linia 12**),
* Przypisać wartości do każdej zmiennej osobno (**linie 19 i 20**).

Aby dostać się do elementów naszej zmiennej typu `Point` używamy zapisu z kropką, np. `point.x`.
Gdyby nasza zmienna `point` była wskaźnikiem, zamiast kropki użylibyśmy strzałki: `point->x`.