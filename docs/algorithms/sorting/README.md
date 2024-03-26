# Sortowanie

Zdarza się, że czasem musimy coś ułożyć w zadanej kolejności. Mówiąc inaczej, musimy coś **posortować**. Powodów może być wiele. Być może potrzebujemy uporządkowanego ciągu danych, aby móc na nim wykonywać efektywne algorytmy, np. wyszukiwania? A może po chcemy ułatwić życie klientowi i zaprezentować mu posortowaną pod względem ceny listę produktów na stronie? A może po prostu lubimy z dumą patrzeć na naszą kolekcję książek uporządkowaną po nazwiskach autorów? Bez względu na to, jaki jest nasz powód, warto jest znać kilka algorytmów/metod sortowania, aby móc je zastosować, nie tylko na komputerze, ale także i w życiu codziennym.

Zapoznając się z algorytmami sortowania zawartymi w tej sekcji przekonasz się, że przynajmniej kilka z nich swoją intuicję ma silnie powiązaną z otaczającym nas światem. Zastanawiałeś się kiedyś, drogi czytelniku, jak poruszają się bąbelki w napojach gazowanych? A może zwróciłeś uwagę na to, jak układać sobie karty na ręce podczas rozgrywki w brydża? A może zdarzyło Ci się porządkować stos książek na półce? To wszystko, jak się przekonasz, ma swoje odzwierciedlenie w algorytmice.

Istnieje wiele algorytmów sortowania. Jedne prostsze, inne trudniejsze. Jedne wolniejsze, inne wydajniejsze. Omówimy tylko wybrane i, być może, popularniejsze z tych algorytmów. Poniższa animacja w ciekawy sposób pokazuje porównanie kilku algorytmów sortowania pod względem wydajności. Warto do niej zajrzeć i poświęcić chwilę, na prześledzenie przebiegu poszczególnych metod, zanim przejdziesz dalej.

[Porównanie algorytmów sortowania](https://www.toptal.com/developers/sorting-algorithms)

## Specyfikacja

W naszych algorytmach sortowania będziemy trzymać się poniższej specyfikacji danych wejściowych i wyniku. Niektóre algorytmy, np. ze względu na swoją rekurencyjną naturę, będą potrzebowały jeszcze dodatkowych parametrów, ale ogólny schemat pozostaje ten sam, nie będziemy więc go powielać przy omawianiu każdego algorytmu.

### Dane

* $n$ — liczba naturalna, ilość elementów w tablicy
* $A[1..n]$ — tablica $n$ wartości całkowitych

### Wynik

* Posortowana niemalejąco tablica $A$
