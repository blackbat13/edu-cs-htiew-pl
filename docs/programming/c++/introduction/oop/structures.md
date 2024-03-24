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
Możemy też skorzystać z pary (`pair`) z STL, ale to także nie jest idealne rozwiązanie.

W takiej sytuacji z pomocą przychodzą **struktury**.
Struktury (w dużym skrócie) pozwalają nam definiować własne typy i przydają się przede wszystkim w sytuacjach, gdy potrzebujemy połączyć grupę wartości w jedną, logiczną całość.
Przyjrzyjmy się poniższym przykładom.

## Przykład 1: punkt 2D

Zacznijmy od prostego przykładu punktu. 
Zdefiniujemy strukturę `Point`, która będzie przechowywać dwie wartości całkowite: współrzędne punktu.

### Implementacja

```cpp
#include <iostream>

using namespace std;

struct Point {
    int x;
    int y;
};

int main() {
    Point point;

    cout << "Creating new point with x = 5 and y = 3" << endl;
    point = {5, 3};

    cout << "Point x: " << point.x << endl;
    cout << "Point y: " << point.y << endl;

    cout << endl << "Assigning new values to the point variable" << endl;
    point.x = 20;
    point.y = 13;
    cout << "Point x: " << point.x << endl;
    cout << "Point y: " << point.y << endl;

    return 0;
}
```

### Link do implementacji

{% embed url="https://ideone.com/YOfvJ9" %}
Struktura Point
{% endembed %}

### Opis implementacji

Zaczynamy od zdefiniowania własnej struktury `Point` (**linia 5**).
Definicję struktury zaczynamy od słowa kluczowego `struct`, następnie podajemy jej nazwę i otwieramy blok kodu.

W ciele struktury definiujemy dwie zmienne całkowite do przechowywania współrzędnych punktu: `x` (**linia 6**) oraz `y` (**linia 7**).
Dla czytelności robimy to w dwóch osobnych liniach, nic nie stoi jednak na przeszkodzie, by zdefiniować obie zmienne jedna po drugiej, po przecinku.

W części głównej programu na samym początku tworzymy zmienną _point_ korzystając z wcześniej zdefiniowanego nowego typu _Point_ (**linia 10**).

W celu przypisania wartości do naszej zmiennej możemy postąpić na dwa sposoby:
* Korzystając z notacji nawiasów klamrowych, podać wartości kolejnych zmiennych po przecinku (**linia 13**),
* Przypisać wartości do każdej zmiennej osobno (**linie 19 i 20**).

Aby dostać się do elementów naszej zmiennej typu `Point` używamy zapisu z kropką, np. `point.x`.
Gdyby nasza zmienna `point` była wskaźnikiem, zamiast kropki użylibyśmy strzałki: `point->x`.

## Przykład 2: punkt 3D

Rozbudujmy poprzedni przykład i stwórzmy strukturę do reprezentacji punktu w przestrzeni 3D.
Tym razem, zamiast wartości całkowitych, użyjemy wartości rzeczywistych.
Dodatkowo, aby ułatwić sobie życie, dopiszemy metodę do wypisywania informacji na temat punktu do konsoli.
Tak, do struktur możemy także dopisywać **metody**: funkcje przypisane do struktury, które mogą korzystać z jej wartości.

### Implementacja

```cpp
#include <iostream>

using namespace std;

// Structure containing three variables of type double and one method
/// Structure representing 3d point
struct Point3D {
    double x;
    double y;
    double z;

    // Custom method (function) assigned to Point3D type
    /// Prints out description of the Point3D
    void describe() {
        cout << "x = " << x << ", ";
        cout << "y = " << y << ", ";
        cout << "z = " << z << endl;
    }
};

int main() {
    Point3D point3D = {5.7, 2.3, 9.0};

    // Our Point3D structure have one method (function): describe
    // To use it we write: variable_name.method_name
    cout << endl << "Calling method describe for point3D" << endl;
    point3D.describe();

    return 0;
}
```

## Przykład 3: prostokąt

```cpp
#include <iostream>

using namespace std;

/// Structure representing the rectangle
struct Rectangle {
    // By default everything in the structure is defined as public
    // That means that it can be accessed from any context in the code

    // But we can override this behaviour
    // We can explicitly say that some fields (or methods) should be defined as private
    // Private fields (or methods) can only be accessed from the inside of the structure

    // Everything defined after the "private" keyword is considered as private
    // Until we reach "public" keyword or the end of the structure
private:
    // Fields width and height can only be accessed in this structure
    double width;
    double height;

    // Everything defined after the "public" keyword is considered as public
    // Until we reach the "private" keyword or the end of the structure
public:
    // This methods can be accessed from outside of this structure

    // Because we defined fields as private, we now don't have the default constructor
    // That means we cannot create new variable of type Rectangle and assign value to it using {} notation
    // To use this default notation we must define our custom constructor
    // Constructor is a special function that is called when we assign new beginning value to our struct variable
    // This function doesn't have a type and shouldn't return any value
    // It can have as many parameters as we want
    // Constructor should assign some values to the fields of our structure

    /// Constructor setting width and height of the rectangle
    /// \param w - width of the rectangle
    /// \param h - height of the rectangle
    Rectangle(double w, double h) {
        width = w;
        height = h;
    }

    /// Compute area of the rectangle
    /// \return Area of the rectangle
    double area() {
        // We can use this private fields because we are still inside the structure
        return width * height;
    }

    /// Scale rectangle by the given scale
    /// \param sc - scale by which the rectangle should be scaled
    void scale(double sc) {
        width *= sc;
        height *= sc;
    }
};

int main() {
    Rectangle rectangle = {4, 2};

    // We cannot access width of this rectangle, because this field is defined as private
    // cout << "Rectangle width: " << rectangle.width << endl;

    // We can use method area of the rectangle, because it is defined as public
    cout << "Rectangle area: " << rectangle.area() << endl;

    cout << "Scale rectangle by 5" << endl;
    rectangle.scale(5);
    cout << "Rectangle area after scaling: " << rectangle.area() << endl;

    return 0;
}
```
