# Grafy

Graf jest strukturą danych, która składa się z wierzchołków (lub węzłów) połączonych krawędziami. Każda krawędź łączy parę wierzchołków. Grafy mogą być skierowane (krawędzie mają kierunek) lub nieskierowane (krawędzie nie mają określonego kierunku).

Grafy są niezwykle użyteczne w wielu dziedzinach, takich jak sieci komputerowe, algorytmy przeszukiwania ścieżek, przetwarzanie obrazów, sieci społecznościowe i wiele innych.

## Typy grafów

Istnieje kilka podstawowych typów grafów, a każdy ma swoje zastosowania.

- **Graf nieskierowany**: Graf, w którym krawędzie **nie mają kierunku**. Jeśli istnieje krawędź między wierzchołkami $$A$$ i $$B$$, to można poruszać się z $$A$$ do $$B$$ i z $$B$$ do $$A$$.
- **Graf skierowany**: Graf, w którym krawędzie **mają kierunek**. Jeśli istnieje krawędź z $$A$$ do $$B$$, to nie można poruszać się z $$B$$ do $$A$$, chyba że istnieje tam osobna krawędź.
- **Graf ważony**: Graf, w którym krawędzie mają **wartość (wagę)** przypisaną. Te wagi mogą reprezentować różne rzeczy, takie jak koszt, długość, pojemność itp., w zależności od problemu, który próbujemy rozwiązać.
- **Graf nieważony**: Graf, w którym krawędzie **nie mają przypisanej wartości**.

## Reprezentacje grafu

Aby móc efektywnie pracować z grafami i wykorzystywać je w algorytmice, potrzebne nam są struktury do ich efektywnej reprezentacji i przechowywania w pamięci programu/komputera. Zazwyczaj rozważamy trzy podstawowe sposoby reprezentacji grafu:

- **Macierz sąsiedztwa**: Jest to kwadratowa macierz o wymiarach $$N\times N$$, gdzie $$N$$ to liczba wierzchołków w grafie. Element macierzy $$M[i][j]$$ jest równy $$1$$, jeśli istnieje krawędź między wierzchołkami $$i$$ oraz $$j$$, a w przeciwnym razie jest równy $$0$$. W przypadku grafów ważonych wartości te zastępuje waga krawędzi. Macierz sąsiedztwa jest prosta do zrozumienia i implementacji, ale jest nieefektywna dla grafów rzadkich (tzn. z małą liczbą krawędzi), ponieważ wymaga przechowywania $$N^2$$ wartości.
- **Lista sąsiedztwa**: Jest to alternatywna reprezentacja grafu, która jest bardziej efektywna dla grafów rzadkich. Dla każdego wierzchołka przechowuje listę wierzchołków, do których prowadzi krawędź. W praktyce lista sąsiedztwa może być reprezentowana jako tablica list lub jako słownik, gdzie klucze to wierzchołki, a wartości to listy sąsiednich wierzchołków.
- **Lista krawędzi**: Lista krawędzi to inna forma reprezentacji grafu, w której graf jest reprezentowany jako jedna lista wszystkich krawędzi. Każda krawędź jest reprezentowana jako para wierzchołków $$(i, j)$$. Lista krawędzi jest szczególnie przydatna, gdy chcemy przejść przez wszystkie krawędzie grafu.

## Operacje na grafach

Podstawowe operacje, które można wykonać na grafach, to:

- dodawanie wierzchołków, 
- dodawanie krawędzi, 
- usuwanie wierzchołków, 
- usuwanie krawędzi, 
- sprawdzanie, czy istnieje krawędź między dwoma wierzchołkami, 
- sprawdzanie sąsiadów danego wierzchołka.

## Podsumowanie

Grafy są kluczową strukturą danych wykorzystywaną w wielu dziedzinach informatyki, a różne sposoby reprezentacji grafów pozwalają na optymalizację różnych operacji. Wybór odpowiedniego typu grafu i reprezentacji zależy od specyfiki problemu, który próbujemy rozwiązać i często jest kluczowym elementem wydajnego algorytmu.
