---
description: Przeszukiwanie grafu wszerz
---

# BFS

## [:link: Opis problemu](../../../../algorithms/graphs/bfs.md)

## Implementacja

```cpp linenums="1"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void bfs(vector<vector<int> > &graph, vector<bool> &visited, int node) {
    queue<int> nodes;

    nodes.push(node);

    while (!nodes.empty()) {
        node = nodes.front();
        nodes.pop();
        
        if (visited[node]) {
            continue;
        }

        visited[node] = true;
        
        cout << "Visited node: " << node << endl;

        for (int i = 0; i < graph[node].size(); i++) {
            int nextNode = graph[node][i];
            if (!visited[nextNode]) {
                nodes.push(nextNode);
            }
        }
    }
}

int main() {
    vector<vector<int> > graph = {
		{1 ,6}, 
		{0, 6, 3, 2},
		{1, 3},
		{2, 1, 6, 4, 5},
		{3, 5},
		{4, 3, 6},
		{0, 1, 3, 5},
	};

    vector<bool> visited = vector<bool>(graph.size(), false);

    bfs(graph, visited, 0);

    return 0;
}
```

### Opis implementacji

Na początku przygotowujemy przykładowy graf (**linie 34-42**) w formie listy sąsiedztwa zapisanej w dynamicznej tablicy typu `vector`. Przykładowy graf (przedstawiony także na poniższym rysunku) ma 7 wierzchołków (numerowanych od zera) i jest nieskierowany.

Po utworzeniu przykładowego grafu przygotowujemy tablicę `visited` i początkowo wypełniamy ją wartościami `false` (**linia 44**). W tej tablicy zapamiętujemy dla każdego wierzchołka, czy został on już odwiedzony, czy jeszcze nie. W tej implementacji korzystamy z dynamicznej tablicy typu `vector`, można jednak równie dobrze wykorzystać statyczną tablicę (jeżeli z góry znamy liczbę wierzchołków grafu).

Funkcja `bfs` (**linia 7**) przyjmuje trzy parametry: graf, tablicę odwiedzonych wierzchołków oraz numer (identyfikator, indeks) początkowego wierzchołka, od którego chcemy zacząć przeszukiwanie. Na początku tworzymy kolejkę `nodes`, w której będziemy przechowywali kolejne wierzchołki do przetworzenia (**linia 8**). Początkowo do kolejki dodajemy tylko pierwszy wierzchołek, przekazany jako parametr funkcji (**linia 10**).

Następnie przetwarzamy kolejne wierzchołki z kolejki, tak długo jak w tej kolejce jest jeszcze coś do przetworzenia (**linia 12**). W pętli pobieramy pierwszy wierzchołek z kolejki (**linia 13**) i usuwamy go z kolejki (**linia 14**). Następnie sprawdzamy, czy został już wcześniej odwiedzony, odwołując się do tablicy `visited` (**linia 16**). Jeżeli wierzchołek został już wcześniej odwiedzony, to nie chcemy go ponownie przetwarzać, więc przechodzimy do kolejnego obrotu pętli (**linia 17**).

Jeżeli wierzchołek nie został jeszcze odwiedzony, to oznaczamy go jako odwiedzony (**linia 20**) i wypisujemy jego numer (**linia 22**). Następnie przechodzimy przez wszystkich sąsiadów aktualnie przetworzonego wierzchołka (**linia 24**). W pomocniczej zmiennej `nextNode` zapamiętujemy numer przetwarzanego sąsiada, pobranego z listy sąsiedztwa (**linia 25**). Następnie sprawdzamy, czy wierzchołek ten był już odwiedzony (**linia 26**), a jeżeli nie, to dodajemy go do kolejki (**linia 27**).

![Przykładowy graf wykorzystany w implementacji](../../../../assets/example_graph.png)

[http://graphonline.ru/en/?graph=iyeQZmXVpPfZWqYG](http://graphonline.ru/en/?graph=iyeQZmXVpPfZWqYG)
