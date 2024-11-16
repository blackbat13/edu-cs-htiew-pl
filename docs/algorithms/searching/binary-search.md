# Wyszukiwanie binarne

W wielu przypadkach, gdy musimy coś znaleźć, np. książkę na półce w bibliotece, to będziemy mieć do czynienia z konkretnym porządkiem.
Książki mogą być ułożone według tematyki, **posortowane** po nazwisku autora i tytule.
Znacząco ułatwia to znalezienie pożądanej pozycji, ponieważ **wiemy, gdzie szukać**.

Tak samo jest też w świecie algorytmiki. Gdy pracujemy na danych **posortowanych**, to zazwyczaj możemy skonstruować efektywne algorytmy do rozwiązania problemu. 

Zacznijmy od tanecznego wyszukiwania i formalnej specyfikacji, by lepiej zrozumieć problem, z którym będziemy się mierzyć.

## Taneczne wyszukiwanie

[Taneczne wyszukiwanie binarne :material-video:](https://www.youtube.com/watch?v=iP897Z5Nerk){ .md-button }

## Specyfikacja

### Dane:

* $n$ - liczba naturalna, ilość elementów w tablicy
* $A[1..n]$ - $n-elementowa$ tablica liczb całkowitych, posortowana niemalejąco, indeksowana od jedynki
* $k$ - liczba całkowita, szukana wartość

### Wynik:

* Indeks wartości $k$ w tablicy $A$, lub $-1$ jeżeli tej wartości nie ma w tablicy

## Przykład

### Dane

```
n := 5
A := [1, 2, 5, 7, 9]
k := 7 
```

**Wynik**: $4$ 

## Rozwiązanie iteracyjne

Zacznijmy od wersji iteracyjnej. Na początku definiujemy początek i koniec przeszukiwanego przedziału. Jako początek przyjmujemy numer pierwszego elementu (czyli $1$), a jako koniec numer ostatniego elementu (czyli $n$). W pętli będziemy powtarzać przeszukiwanie tak długo, jak długo nasz zdefiniowany przez początek i koniec przedział będzie zawierał co najmniej jeden element. Inaczej mówiąc, powtarzamy tak długo, jak długo początek jest mniejszy od końca.

Wewnątrz pętli najpierw obliczamy środek przeszukiwanego przedziału. Następnie sprawdzamy, jak element znajdujący się na środku ma się do naszego poszukiwanego elementu. Jeżeli poszukiwane element jest większy od elementu, który mamy na środku, to znaczy, że należy szukać po prawej stronie od środka: przesuwamy więc początek naszego przedziału na prawo od środka. W przeciwnym przypadku, czyli gdy poszukiwany element jest mniejszy bądź równy elementowi na środku, oznacza to, że należy szukać po lewej stronie od środka (ale nie możemy wykluczyć też elementu na środku!). W związku z tym przesuwamy koniec przedziału na środek. 

Gdy już wyjdziemy z pętli pozostaje nam sprawdzić, czy znaleźliśmy poszukiwany element. Sprawdzamy, czy pod indeksem wskazującym na zmieniony początek (lub koniec) przedziału znajduje się poszukiwana wartość. Jeżeli tak, to zwracamy jako wynik ten indeks. W przeciwnym przypadku zwracamy $-1$.

### Pseudokod

```
funkcja SzukajBinarnie(n, A, k)
    1. pocz := 1
    2. kon := n
    3. Dopóki pocz < kon, wykonuj:
        4. srodek := (pocz + kon) div 2
        
        5. Jeżeli k > A[srodek], to:
            6. pocz := srodek + 1
        
        7. W przeciwnym przypadku:
            8. kon := srodek

    9. Jeżeli A[pocz] = k, to:
        10. Zwróć pocz, zakończ
    11. W przeciwnym przypadku:
        12. Zwróć -1, zakończ
```

!!! info
	 **div** oznacza dzielenie całkowite

### Schemat blokowy

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
	START(["SzukajBinarnie(n, A, k)"]) --> O1["pocz := 1
	kon := n"]
	O1 --> C1{pocz < kon}
	C1 -- PRAWDA --> O2["srodek := (pocz + kon) div 2"]
	O2 --> C2{"k > A[srodek]"}
	C2 -- PRAWDA --> O3[pocz := srodek + 1]
	O3 --> C1
	C2 -- FAŁSZ --> O4[kon := srodek]
	O4 --> C1
	C1 -- FAŁSZ --> C3{"A[pocz] = k"}
	C3 -- PRAWDA --> R1[/Zwróć pocz/]
	R1 --> STOP([STOP])
	C3 -- FAŁSZ --> R2[/Zwróć -1/]
	R2 --> STOP
```

### Złożoność

$O(\log n)$ - logarytmiczna

## Rozwiązanie rekurencyjne

W rozwiązaniu rekurencyjnym zamiast rozmiaru tablicy podajemy początek i koniec przeszukiwanego przedziału. Zaczynamy od sprawdzenia warunku stopu rekurencji: poprawności przedziału. Następnie postępujemy podobnie jak w wersji iteracyjnej. Obliczamy środek przedziału i porównujemy element znajdujący się na środku z poszukiwaną wartością. W zależności od wyniku porównania wykonujemy wywołanie rekurencyjne odpowiednio modyfikując przeszukiwany przedział.

### Pseudokod

```
funkcja SzukajBinarnie(A, k, pocz, kon)
    1. Jeżeli pocz >= kon, to:
        2. Jeżeli A[pocz] == k, to:
            3. Zwróć pocz, zakończ
        4. W przeciwnym przypadku:
            5. Zwróć -1, zakończ
    
    6. srodek := (pocz + kon) div 2
    
    7. Jeżeli k > A[srodek], to:
        8. Zwróć SzukajBinarnie(A, k, srodek+1, kon)
    
    9. W przeciwnym przypadku:
        10. Zwróć SzukajBinarnie(A, k, pocz, srodek)
```

### Schemat blokowy

```mermaid
%%{init: {"flowchart": {"curve": "linear"}, "theme": "neutral"} }%%
flowchart TD
	START(["SzukajBinarnie(A, k, pocz, kon)"]) --> K1{pocz >= kon}
	K1 -- PRAWDA --> K2{"A[pocz] = k"}
	K2 -- PRAWDA --> K3[/Zwróć pocz/]
	K3 --> STOP([STOP])
	K2 -- FAŁSZ --> K5[/Zwróć -1/]
	K5 --> STOP
	K1 -- FAŁSZ --> K6["srodek := (pocz + kon) div 2"]
	K6 --> K7{"k > A[srodek]"}
	K7 -- PRAWDA --> K8[/"Zwróć SzukajBinarnie(A, k, srodek + 1, kon)"/]
	K8 --> STOP
	K7 -- FAŁSZ --> K9[/"Zwróć SzukajBinarnie(A, k, pocz, srodek)"/]
	K9 --> STOP
```

### Złożoność 

$O(\log n)$ - logarytmiczna

## Implementacje - główne

### [C++ :simple-cplusplus:](../../programming/c++/algorithms/searching/binary-search.md){ .md-button }

### [Python :simple-python:](../../programming/python/algorithms/searching/binary-search.md){ .md-button }

### [Blockly :material-code-block-braces:](../../programming/blockly/algorithms/searching/binary-search.md){ .md-button }

## Implementacje — pozostałe

### [C :simple-c:](../../programming/c/algorithms/searching/binary-search.md){ .md-button }

### [Haskell :simple-haskell:](../../programming/haskell/algorithms/searching/binary-search.md){ .md-button }

### [Julia :simple-julia:](../../programming/julia/algorithms/searching/binary-search.md){ .md-button }

### [Kotlin :simple-kotlin:](../../programming/kotlin/algorithms/searching/binary-search.md){ .md-button }

## Powiązane zagadnienia

- Obliczanie pierwiastka kwadratowego zadanej liczby.
- Znajdowanie najmniejszego i największego indeksu danej liczby w posortowanej tablicy, w której elementy mogą się powtarzać.
- Znajdowanie mediany dwóch posortowanych tablic (gdyby były ze sobą scalone w jedną posortowaną tablicę).
