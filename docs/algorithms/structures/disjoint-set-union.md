# Struktura zbiorów 

Zbiory rozłączne, nazywane też strukturą *union-find*, są zaawansowaną strukturą danych, która składa się z pewnej liczby elementów podzielonych na jeden lub więcej zbiorów nierozłącznych. Innymi słowy, dla każdych dwóch elementów z tych samych zbiorów, nie ma **żadnej** drogi prowadzącej od jednego do drugiego przez elementy z innych zbiorów.

## Właściwości

W tej strukturze danych zawsze mamy jednego reprezentanta (korzeń) dla każdego zbioru. Reprezentant jest jednym z elementów zbioru, który jest wykorzystywany jako "identyfikator" dla całego zbioru. Każdy zbiór jest przedstawiany jako drzewo, w którym każdy węzeł przechowuje element i wskaźnik do swojego rodzica.

## Operacje

Zbiory rozłączne obsługują trzy podstawowe operacje:

- **Find**: sprawdza, do którego zbioru należy dany element. Wykonuje to przez odnalezienie reprezentanta zbioru, do którego element należy. Można to osiągnąć, śledząc wskaźniki do rodzica od danego elementu, aż dotrzemy do elementu, który jest swoim własnym rodzicem (reprezentantem).
- **Union**: łączy dwa zbiory w jeden. Wykonuje to, lokalizując reprezentantów obu zbiorów i przypisując jednego z nich jako rodzica drugiego, w efekcie tworząc jedno drzewo (zbiór).
- **MakeSet**: tworzy nowy zbiór z pojedynczego elementu. Nowy element staje się reprezentantem nowego zbioru.

## Zastosowania

Zbiory rozłączne są używane w wielu algorytmach i strukturach danych związanych z teorią grafów, na przykład:

- **Algorytm Kruskala**: jest to algorytm znajdowania minimalnego drzewa rozpinającego w grafie. Algorytm ten używa struktury zbiorów rozłącznych do sprawdzania, czy dodanie krawędzi do drzewa nie utworzy cyklu.
- **Algorytm detekcji cykli w grafie nieskierowanym**: ta sama koncepcja stosowana w algorytmie Kruskala może być również użyta do detekcji cykli.
- **Rozwiązanie problemu połączenia**: problem polega na tym, aby szybko odpowiedzieć na pytanie, czy dwa elementy należą do tego samego zbioru. Może to być rozwiązane za pomocą struktury zbiorów rozłącznych z operacjami find i union.
- 
Te algorytmy i wiele innych korzystają z efektywności operacji oferowanych przez strukturę zbiorów rozłącznych. Operacje takie jak *find* i *union* są bardzo szybkie dzięki zastosowaniu technik takich jak łączenie według rangi (*union by rank*) i kompresja ścieżki (*path compression*), które pomagają utrzymać wysokość drzewa na minimalnym poziomie.

## Implementacja

### [C++](../../programming/c++/algorithms/structures/disjoint-set-union.md)

### [Python](../../programming/python/algorithms/structures/disjoint-set-union.md)
