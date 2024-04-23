# Klasy

Definicję klasy zaczynamy od słowa kluczowego `class`, a następnie podajemy nazwę klasy, zazwyczaj zaczynając od wielkiej litery. Jeżeli klasa po czymś dziedziczy, to podajemy to wewnątrz nawiasów okrągłych po nazwie klasy.

## Klasa abstrakcyjna

Aby zdefiniować klasę abstrakcyjną, której obiektu nie możemy utworzyć, ale możemy ją wykorzystywać w dziedziczeniu, skorzystamy z klasy bazowej `ABC` z modułu `abc`. Z tego samego modułu przydatny będzie także dekorator `abstractmethod` za pomocą którego możemy oznaczyć wybraną metodę klasy abstrakcyjnej jako abstrakcyjną, która musi zostać zaimplementowana w klasie pochodnej.

```python linenums="1"
from abc import ABC, abstractmethod

class Figure(ABC):
    """Klasa abstrakcyjna reprezentująca figurę.
    Aby utworzyć klasę abstrakcyjną, dziedziczymy po specjalnej klasie ABC, którą należy zaimportować z pakietu abc.
    """

    @abstractmethod
    def area(self) -> float:
        """Metoda obliczająca pole figury.
        Metoda abstrakcyjna. 
        Metody abstrakcyjne oznaczamy za pomocą dekoratora @abstractmethod z pakietu abc.
        Muszą zostać przeciążone w klasie potomnej.
        """
        pass

    @abstractmethod
    def perimeter(self) -> float:
        """Metoda obliczająca obwód figury.
        Metoda abstrakcyjna.
        """
        pass


if __name__ = "__main__":
    figure = Figure() # BŁĄD! Nie możemy tworzyć obiektu klasy abstrakcyjnej
```

## Dziedziczenie

Standardowe klasy powinny mieć zdefiniowany własny konstruktor/inicjalizator: metodę `__init__`.

Do każdej metody w klasie przekazujemy jako pierwszy parametr `self`, który jest odniesieniem do obiektu klasy, na której pracujemy (podobnie jak `this` w niektórych językach).

```python linenums="1"
from random import randint
from math import pi, sin, radians

class Quad(Figure):
    """Klasa reprezentująca czworokąt. 
    Dziedziczy po klasie Figure.
    """

    def __init__(self, side1: float, side2: float, side3: float, side4: float, diagonal1: float, diagonal2: float, angle: float):
        """Konstruktor klasy.
        
        Argumenty:
            side1, side2, side3, side4 - długości boków
            diagonal1, diagonal2 - długości przekątnych
            alpha - kąt pomiędzy przekątnymi
        """

        # Zmienne zaczynające się od pojedyńczego znaku podłogi traktowane są umownie jako protected.
        self._sides = [side1, side2, side3, side4]

        # Zmienne zaczynające się od podwójnego znaku podłogi traktowane są umownie jako prywatne.
        self.__d1 = diagonal1
        self.__d2 = diagonal2
        self.__angle = angle

    def area(self) -> float:
        """Metoda obliczająca pole czworokąta na podstawie długości przekątnych i kąta alpha pomiędzy nimi.
        Metoda publiczna, dziedziczona przez potomków
        """
        return (self.__d1 * self.__d2 * sin(radians(self.__angle))) / 2

    def perimeter(self) -> float:
        """Metoda obliczająca obwód figury jako sumę długości boków.
        Metoda publiczna, dziedziczona przez potomków.
        """
        return sum(self._sides)
```

## Atrybuty klasy

Zmienne wewnątrz klasy, których nazwa zaczyna się od podwójnego znaku podłogi, uznajemy za prywatne. Zmienne te nie mogą być użyte na zewnątrz klasy.

Pozostałe zmienne są generalnie publiczne, chociaż te, których nazwa zaczyna się od pojedyńczego znaku podłogi uznajemy za protected, tzn. dostępne tylko w klasach pochodnych.

Aby mieć kontrolę nad dostępem do zmiennych w obiekcie, możemy skorzystać z dekoratorów `property` oraz `setter` odpowiednio do tworzenia atrybutów do odczytu i zapisu.

```python linenums="1"
class Rectangle(Quad):
    """Klasa reprezentująca prostokąt.
    Dziedziczy po klasie Quad reprezentującej czworokąt, jako że prostokąt jest czworokątem.
    """

    def __init__(self, height: float, width: float):
        """Konstruktor klasy. 
        Jako że klasa Rectangle dziedziczy po klasie Quad wymagane jest wywołanie konstruktora klasy rodzica.
        Wykonujemy to pisząc super().__init__(argumenty).

        Argumenty:
            height - wysokość prostokąta
            width - szerokość prostokąta
        """
        super().__init__(height, width, height, width, 0, 0, 0)

    @property
    def height(self) -> float:
        """Wysokość prostokąta. Getter.
        Atrybut klasy do odczytu. Działa podobnie jak getter z Javy.
        """
        return self._sides[0]

    @height.setter
    def height(self, value: float):
        """Wysokość prostokąta. Setter.
        Atrybut klasy do zapisu. Działa podobnie jak setter z Javy.
        """
        self._sides[0] = value
        self._sides[2] = value

    @property
    def width(self) -> float:
        """Szerokość prostokąta. Getter."""
        return self._sides[1]

    @width.setter
    def width(self, value: float):
        """Szerokość prostokąta. Setter."""
        self._sides[1] = value
        self._sides[3] = value

    def area(self) -> float:
        """Metoda obliczająca pole prostokąta przemnażając wysokość i szerokość."""
        return self.width * self.height
```

```python linenums="1"
class Square(Rectangle):
    """Klasa reprezentująca kwadrat.
    Dziedziczy po klasie Rectangle reprezentującej prostokąt, jako że kwadrat jest prostokątem.
    """

    def __init__(self, size: float):
        """Konstruktor klasy. 
        Jako że klasa Square dziedziczy po klasie Rectangle wymagane jest wywołanie konstruktora klasy rodzica.
        Wykonujemy to pisząc super().__init__(argumenty).

        Argumenty:
            size - długość boku
        """
        super().__init__(size, size)


class Ellipse(Figure):
    """Klasa reprezentująca elipsę.
    Dziedziczy po klasie Figure.
    """

    def __init__(self, radius1: float, radius2: float):
        """ 
        Konstruktor klasy. 
        Jako że klasa Ellipse dziedziczy po klasie abstrakcyjnej Figure, nie wywołujemy konstruktora klasy rodzica.

        Argumenty:
            radius1 - pierwszy promień elipsy
            radius2 - drugi promień elipsy
        """
        self._radius1 = radius1
        self._radius2 = radius2

    def area(self):
        """Metoda obliczająca pole elipsy. Nie została zaimplementowana."""
        raise NotImplemented

    def perimeter(self):
        """Metoda obliczająca obwód elipsy. Nie została zaimplementowana."""
        raise NotImplemented


class Circle(Ellipse):
    """Klasa reprezentująca koło.
    Dziedziczy po klasie Ellipse reprezentującej elipsę, jako że koło jest też elipsą.
    """

    def __init__(self, radius: float):
        """Konstruktor klasy. 
        Jako że klasa Circle dziedziczy po klasie Ellipse wymagane jest wywołanie konstruktora klasy rodzica.
        Wykonujemy to pisząc super().__init__(argumenty).

        Argumenty:
            radius - promień koła
        """
        super().__init__(radius, radius)

    @classmethod
    def one(cls):
        """Metoda klasowa tworząca koło o promieniu 1. 
        Taki sposób pozwala na utworzenie dodatkowych "konstruktorów".
        """
        return cls(1)

    @property
    def radius(self):
        """Promień koła. Getter.
        Wartość tylko do odczytu, nie ma metody setter.
        """
        return self._radius1

    def area(self) -> float:
        """Metoda obliczająca pole koła."""
        return pi * (self.radius ** 2)

    def perimeter(self) -> float:
        """Metoda obliczająca obwód koła."""
        return 2 * pi * self.radius


if __name__ == "__main__":
    # figure = Figure() - Błąd, nie możemy utworzyć obiektu klasy z abstrakcyjnymi metodami
    quad = Quad(1, 2, 3, 4, 5, 6, 30)
    rectangle = Rectangle(1, 2)
    square = Square(1)
    ellipse = Ellipse(1, 2)
    circle = Circle(5)

    quad.__d1 = 10  # Działa, ale nie jest poprawne, __d1 jest prywatne
    print(f"quad.__d1 = {quad.__d1}")  # Działa, ale nie jest poprawne, __d1 jest prywatne

    quad._sides[0] = 10  # Działa, ale nie jest poprawne, _sides jest protected
    print(f"quad._sides[0] = {quad._sides[0]}")  # Działa, ale nie jest poprawne, _sides jest protected

    rectangle.width = 10  # Działa
    print(f"rectangle.width = {rectangle.width}")  # Działa

    # circle.radius = 10 # Nie działa, nie ma settera
    print(f"circle.radius = {circle.radius}")  # Działa

    circle_one = Circle.one()  # Wywołanie metody klasowej

    print(f"kwadrat jest figurą: {isinstance(square, Figure)}")
    print(f"kwadrat jest czworokątem: {isinstance(square, Quad)}")
    print(f"kwadrat jest prostokątem: {isinstance(square, Rectangle)}")
    print(f"kwadrat jest kwadratem: {isinstance(square, Square)}")
    print(f"kwadrat jest elipsą: {isinstance(square, Ellipse)}")
    print(f"kwadrat jest kołem: {isinstance(square, Circle)}")

    print(f"kwadrat jest typu: {type(square)}")

    selection = randint(1, 5)

    figure = None

    if selection == 1:
        figure = Quad(1, 2, 3, 4, 6, 7, 30)
    elif selection == 2:
        figure = Rectangle(1, 2)
    elif selection == 3:
        figure = Square(1)
    elif selection == 4:
        figure = Ellipse(1, 2)
    elif selection == 5:
        figure = Circle(1)

    print(f"Wylosowana figura jest typu: {type(figure)}")

    if isinstance(figure, Rectangle):
        # Sprawdzamy, czy figure jest prostokątem, a jeśli tak, to wypisujemy jego wysokość.
        # Przy takim podejściu środowisko będzie podpowiadać metody dostępne w klasie Rectangle i traktować figure jako Rectangle.
        print(f"Wysokość: {figure.height}")
```
