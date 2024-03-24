# Algorytmy liniowe

Czym jest algorytm? Instrukcja, przepis, schemat postępowania... Algorytm opisuje rozwiązanie pewnego problemu. Istnieje wiele rodzajów algorytmów, a my zaczniemy od najprostszego z nich - algorytmów liniowych.

## Algorytm liniowy

Algorytm liniowy to sekwencyjna instrukcja, której kroki wykonujemy jeden po drugim, linijka po linijce, operacja po operacji.

W trakcie konstruowania algorytmu pojawia się szereg pytań. Jak bardzo szczegółowy powinien być algorytm? Jakie operacje musimy w nim zawrzeć, a które możemy pominąć? Jakie operacje są dostępne? W jakiej formie powinniśmy przedstawić nasz algorytm? To tylko część z ważnych kwestii, które należy rozważyć.

Rozważmy poniższy przykład.

### Przykład 1

Wyobraźmy sobie, że mamy przygotować kanapkę z dżemem. To jest nasz problem. Dla tego problemu, zaproponujemy przykładowe rozwiązanie w postaci **algorytmu**.

```
1. Weź kromkę chleba
2. Weź masło
3. Weź dżem
4. Weź nóż
5. Posmaruj chleb masłem
6. Posmaruj chleb dżemem
```

Jak widać, powyższy przykład jest algorytmem przygotowania kanapki z dżemem. Zastanówmy się jednak nad jego poprawnością i dokładnością. Czy wszystkie niezbędne operacje zostały uwzględnione? Czy może któreś z nich można pominąć? Czy powinniśmy dodać instrukcję odkręcenia słoika? A może otwarcie lodówki, żeby wyciągnąć dżem, a potem zamknięcie jej? Co jeśli nie ma dżemu i trzeba iść do sklepu? A jeśli jest niedziela i sklepy są zamknięte? A jeśli...

Takie rozważania możemy kontynuować w nieskończoność, ale musimy ustalić pewne granice.

## Specyfikacja problemu

Przede wszystkim zaczynamy od **specyfikacji**. Specyfikacja określa, jakie dane wejściowe przyjmuje algorytm i co powinno być jego wynikiem. Innymi słowy, jest to formalne zdefiniowanie problemu. Wróćmy do naszego przykładu.

### Przykład 2

Zacznijmy od sformalizowania naszego problemu przygotowania kanapki z dżemem za pomocą specyfikacji.

#### Specyfikacja

**Dane**:

* Kromka chleba
* Masło
* Dżem

**Wynik**:

* Kanapka z dżemem

Teraz możemy przejść do algorytmu. Jak widać, mamy trzy dane wejściowe: kromkę chleba, masło oraz dżem. Nie musimy więc martwić się o przygotowanie tych składników. Zazwyczaj w zapisie algorytmu pomijamy etap wczytywania danych, co oznacza, że w tym przypadku opuszczamy instrukcje opisujące wzięcie chleba, masła i dżemu. Po prostu zakładamy, zgodnie ze specyfikacją, że te elementy są nam już dane i dostępne dla naszego algorytmu.

#### Algorytm

```
1. Weź nóż
2. Posmaruj chleb masłem
3. Posmaruj chleb dżemem
```

W tym przypadku ograniczyliśmy się do pewnego zbioru operacji i do pewnego poziomu szczegółowości. Gdy przejdziemy do bardziej technicznych algorytmów, stanie się jasne, które operacje możemy wykonywać, a które nie.
