# Zmienne

Czym jest zmienna? Można powiedzieć, że to pewnego rodzaju pudełko na dane. Na zmiennych możemy wykonywać różnego rodzaju operacje: możemy "wkładać" (**przypisywać**) do nich różne wartości, wykonywać na nich operacje, wykorzystywać w obliczeniach, a także odczytywać ich wartości. 

Zmienne stanowią niezbędny element praktycznie każdego algorytmu. W związku z tym ich poprawne i dogłębne zrozumienie jest wymagane, by móc konstruować i implementować zaawansowane algorytmy.

## Typy zmiennych

Wyobraźmy sobie dwa pudełka: jedno plastikowe i jedno metalowe. Do plastikowego pudełka możemy wkładać tylko owoce, a do metalowego tylko gwoździe. Każde z pudełek ma swoje przeznaczenie. Swój **typ** przechowywanych przedmiotów.

Podobnie jest ze zmiennymi. Każda zmienna może przechowywać tylko określony typ wartości. Mówimy wtedy, że zmienna ma swój typ. Dla przykładu, możemy utworzyć zmienną do przechowywania liczb całkowitych. Do takiej zmiennej nie przypiszemy już wartości innego typu, np. tekstu.

!!! warning
	 W niektórych językach programowania jednoznacznie określamy typ zmiennej przy jej tworzeniu, w innych nie. Podobnie, są języki, w których próba przypisania innego typu wartości do zmiennej zakończy się błędem. Są też takie, w których tego typu operacja będzie dozwolona. Nie oznacza to jednak, że powinniśmy to robić! Bardzo ważne jest przestrzeganie typu zmiennych. Jest to istotne z punktu widzenia czytelności kodu programu, ale także z poziomu mechanik, które kryją się pod spodem.

## Wartości zmiennych

Wiemy już, że do zmiennych możemy przypisywać wartości. Czy oznacza to jednak, że raz przypisana wartość do zmiennej pozostaje niezmienna? Jak można się domyślić po nazwie **zmienna,** tak nie jest. Bardzo ważne jest by zrozumieć, że wartość zmiennej określamy w czasie, tzn. w danym punkcie działania programu. By lepiej to zrozumieć, spójrzmy na poniższe przykłady.

### Przykład 1

```
1. a := 10
2. Wypisz a
3. a := 2 * a
4. Wypisz a
5. a := a + 5
6. Wypisz a
```

Spójrz na powyższy pseudokod. Czy potrafisz powiedzieć, jakie wartości zostaną wypisane w instrukcji 2, 4 i 6? Spróbuj odpowiedzieć na to pytanie, zanim przejdziesz dalej.

Najlepszym sposobem jest przeprowadzenie **symulacji** danego pseudokodu. Bierzemy kartkę i długopis i wykonujemy kolejne operacje, zapisując wartości zmiennych w każdym punkcie. Można to zrobić na wiele sposobów, jeden z nich prezentujemy poniżej.

```
1. [a = 10]
2. Wypisz 10
3. [a = 2 * 10 = 20]
4. Wypisz 20
5. [a = 20 + 5 = 25]
6. Wypisz 25
```

Jak widać, przedstawiony wcześniej algorytm wpisze kolejno liczby: $10,\ 20,\ 25$.

### Przykład 2

```
1. a := 0
2. Dopóki a < 10, wykonuj:
    3. a := a + 2
    4. Wypisz a
```

Ponownie, zanim przejdziesz dalej spróbuj się zastanowić nad tym, jakie kolejne wartości wypisze powyższy algorytm.

W tym przykładzie bardzo ważne jest poprawne zrozumienie działania pętli. Pętla powtarza pewne operacje wielokrotnie, co oznacza, że te same instrukcje będziemy wykonywać kilka razy. Spróbujmy to rozpisać.

```
1. [a = 0]

2. Dopóki 0 < 10 - OK
    3. [a = 0 + 2 = 2]
    4. Wypisz 2
    
2. Dopóki 2 < 10 - OK
    3. [a = 2 + 2 = 4]
    4. Wypisz 4
    
 2. Dopóki 4 < 10 - OK
     3. [a = 4 + 2 = 6]
     4. Wypisz 6
     
 2. Dopóki 6 < 10 - OK
     3. [a = 6 + 2 = 8]
     4. Wypisz 8
     
 2. Dopóki 8 < 10 - OK
     3. [a = 8 + 2 = 10]
     4. Wypisz 10
     
 2. Dopóki 10 < 10 - NIE (koniec pętli)
```

## Prezentacja

[:fontawesome-solid-file-pdf: Wprowadzenie](../../assets/Zmienne - wprowadzenie.pdf)

[:fontawesome-solid-file-pdf: Ćwiczenia](../../assets/Zmienne - ćwiczenia.pdf)

[:fontawesome-solid-file-pdf: Zmienne w pamięci](../../assets/Zmienne w Pamięci - Ćwiczenia.pdf)