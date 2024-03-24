# Motylek

Wyobraź sobie małego motylka, zamkniętego w sześcianie o wymiarach $$16\times 16\times 16$$. Motylek początkowo znajduje się w punkcie o współrzędnych $$(0,0,0)$$. Punkt ten stanowi także środek sześcianu. Krawędzie sześcianu są równoległe do poszczególnych osi współrzędnych. Motylek może poruszać się w dowolnym z sześciu kierunków: do przodu, do tyłu, w górę, w dół, w lewo, w prawo. Każdy ruch przemieszcza motylka o $$1$$ w zadanym kierunku. Dokładniej mówiąc, jeżeli motylek znajduje się w punkcie $$(0,0,0)$$, to po pofrunięciu do przodu znajdzie się w punkcie $$(0,0,1)$$. Podobnie, gdyby z nowej pozycji pofrunął do tyłu, to ponownie znajdzie się na pozycji $$(0,0,0)$$. Podczas swojego lotu motylek nie obraca się, co oznacza, że zawsze jest skierowany w tym samym kierunku.

W pliku **motylek.txt** znajduje się $$1000$$ poleceń dla motylka. Każde polecenie znajduje się w osobnej linii i składa się dokładnie z jednej wielkiej litery alfabetu angielskiego. W zadaniach polecenia numerujemy od jedynki. Polecenia interpretujemy zgodnie z poniższym schematem:

- **L** - pofruń w lewo,
- **R** - pofruń w prawo,
- **U** - pofruń do góry,
- **D** - pofruń w dół,
- **F** - pofruń naprzód,
- **B** - pofruń do tyłu.

{% file src="../../../../.gitbook/assets/motylek.txt" %}
motylek.txt
{% endfile %}

## Zadanie 1

Podaj numer polecenia, którego wykonanie spowoduje, że motylek wyleci poza sześcian (dopuszczamy wlecenie w bok sześcianu). Podaj pozycję, na której znajdował się motylek przed wykonaniem tego polecenia.

## Zadanie 2

Załóżmy, że gdy motylek miałby wykonać polecenie, które poprowadziłoby go poza sześcian, to takie polecenie zignoruje (nie zmieni swojej pozycji) i przejdzie do kolejnego. Jaką łączną odległość motylek pokona w trakcie swojej podróży? Na jakiej pozycji znajdzie się na końcu wędrówki?

## Zadanie 3

Podaj długość najdłuższej sekwencji kolejnych poleceń, w trakcie wykonywania których motylek **nie wyleci z sześcianu** (podobnie jak wcześniej, ignorujemy polecenia, które miałyby wyprowadzić motylka poza sześcian, ale **przerywają one sekwencję**). Podaj numer pierwszego i ostatniego polecenia z tej sekwencji. Jeżeli jest kilka takich sekwencji, odwołaj się do pierwszej z nich.

## Zadanie 4

Załóżmy, że gdy motylek miałby wykonać polecenie przenoszące go poza sześcian, to zamiast tego "teleportuje" się do punktu $$(0,0,0)$$ i kontynuuje wykonywanie poleceń z tej pozycji, poczynając od polecenia, które wyprowadziłoby go poza sześcian. Oblicz, ile razy motylek będzie "teleportował" się do środka sześcianu.

## Zadanie 5

Ignorując sześcian i zakładając, że motylek wykonuje **każde** polecenie, podaj współrzędne dwóch pozycji motylka, które są od siebie najbardziej oddalone w linii prostej. Podaj odległość między tymi punktami z zaokrągleniem do dwóch miejsc po przecinku. Jeżeli jest kilka takich par, wypisz wszystkie.
