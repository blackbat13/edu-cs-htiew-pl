# Kółko i kwadrat

W pliku **kik.txt** znajduje się $$10000$$ par liczb rzeczywistych z zakresu od $$-1$$ do $$1$$. Każda linia w pliku zawiera dwie liczby oddzielone spacją. Liczby są zapisane w formacie angielskim, tzn. część całkowitą od ułamkowej oddziela kropka. Każdą parę interpretujemy jako współrzędne punktu w układzie współrzędnych.

W środku układu współrzędnych narysowano koło o promieniu $$1$$. Środek koła znajduje się w punkcie $$(0,0)$$.

{% file src="../../../../.gitbook/assets/kik.txt" %}
kik.txt
{% endfile %}

## Zadanie 1

Oblicz, ile punktów z pliku znajduje się wewnątrz koła (wliczamy w to także punkty leżące na okręgu), a ile poza nim.

## Zadanie 2

Znajdź długość najdłuższej sekwencji kolejnych, sąsiednich punktów, z których każdy znajduje się wewnątrz koła (lub na jego okręgu).

## Zadanie 3

Podaj dowolną wartość $$k$$ taką, że dokładnie $$5000$$ punktów ma współrzędną $$x$$ **mniejszą** od $$k$$, a pozostałe punkty mają współrzędną $$x$$ **większą** od $$k$$.

## Zadanie 4

Weź pierwsze $$100$$ punktów z pliku. Każdą współrzędną pomnóż przez $$1000$$ i zaokrąglij $$w dół$$ do najbliższej liczby całkowitej. Zapisz tak otrzymane punkty w pliku **kik_posortowane.txt**, każdy w osobnej linii, uporządkowane zgodnie z poniższymi regułami:

- załóżmy, że ustalamy porządek dwóch punktów o współrzędnych $$(x_1,y_1)$$ i $$(x_2,y_2)$$,
- punkt $$(x_1,y_1)$$ znajduje się w porządku **przed** punktem $$(x_2,y_2)$$ wtedy i tylko wtedy gdy:
  - $$x_1<x_2$$ lub
  - $$x_1=x_2$$ oraz $$y_1<=y_2$$.
