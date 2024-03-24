# Rzeka

W pliku *Rzeka.txt* znajdują się dane odczytów zanieczyszczenia rzeki Bug na terenie Ukrainy w latach 1996-2019. Każda linia zawiera następujące informacje:

- identyfikator stacji wykonującej odczyt,
- data odczytu,
- wartość odczytu,
- odległość stacji od źródła rzeki.

Dane oddzielone są średnikami. Pierwszy wiersz zawiera nagłówki kolumn.

{% file src="../../../../.gitbook/assets/Rzeka.txt" %}
Rzeka.txt
{% endfile %}

Źródło danych: [https://www.kaggle.com/datasets/vbmokin/ammonium-prediction-in-river-water](https://www.kaggle.com/datasets/vbmokin/ammonium-prediction-in-river-water)

## Zadanie 1

Dla każdej stacji oblicz minimalny, maksymalny i średni odczyt dla każdego roku, w którym były dokonywane pomiary z tej stacji,

## Zadanie 2

Dla każdej odległości stacji od źródła rzeki oblicz średni odczyt oraz odchylenie standardowe odczytu. Wyniki zaokrąglij do trzech miejsc po przecinku i przedstaw na wykresie liniowym. Zadbaj o czytelność wykresu.

## Zadanie 3

Dla każdej stacji podaj datę i wartość pierwszego i ostatniego (pod względem daty) odczytu, a następnie oblicz wartość bezwzględną różnicy pomiędzy tymi odczytami. Wyniki obliczonej różnicy dla każdej stacji przedstaw na wykresie kolumnowym. Zadbaj o czytelność wykresu.

## Zadanie 4

Przedstaw na wykresie kołowym procentowy udział każdej stacji w odczytach zawartych w zestawieniu.

## Zadanie 5

Dla każdej stacji oblicz wartość bezwzględną różnicy pomiędzy maksymalnym a minimalnych odczytem z tej stacji. Wyniki zaokrąglij do dwóch miejsc po przecinku i przedstaw na wykresie. Zadbaj o czytelność wykresu.

## Zadanie 6

Dla każdej daty odczytu (dokonanego z dowolnej stacji) oblicz średni odczyt dokonany tego dnia. Wyniki uporządkuj rosnąco po dacie. Następnie, poczynając od drugiego odczytu, oblicz różnice pomiędzy kolejnymi odczytami, tzn. odczyt z obecnego dnia minus poprzedni odczyt. Wartości różnic odczytów z lat 1993-1994 przedstaw na wykresie liniowym. Zadbaj o czytelność wykresu.

## Zadanie 7

Ignorując powtórzenia odczytów z tego samego dnia, oblicz odstęp w dniach pomiędzy kolejnymi odczytami (bez względu na stację, z której dokonano pomiaru). Dla pierwszego dokonanego odczytu przyjmij wartość zero jako odstęp w dniach. 

Podaj maksymalną liczbę dni pomiędzy kolejnymi odczytami (jest tylko jedna taka wartość), a także daty tych odczytów.

Dla każdego odstępu w dniach występującego w wynikach policz, ile razy taki odstęp wystąpił. Dane uporządkuj rosnąco po liczbie dni i przedstaw na wykresie. Zadbaj o czytelność wykresu.
