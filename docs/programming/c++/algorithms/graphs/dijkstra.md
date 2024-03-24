---
description: Najkrótsze ścieżki z jednego wierzchołka
---

# Dijkstra

## Opis problemu

{% content-ref url="../../../../algorithms/graphs/dijkstra.md" %}
[dijkstra.md](../../../../algorithms/graphs/dijkstra.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```cpp
#include <iostream>
#include <vector>
#include <queue>
#include <climits>

using namespace std;

struct edge {
	int from;
	int to;
	int distance;
	
	edge(int from, int to, int distance) {
		this->from = from;
		this->to = to;
		this->distance = distance;
	}
};

void dijkstra(vector<vector<edge> > &graph, vector<int> &distances, int node) {
    queue<edge> edges;

    distances = vector<int>(graph.size(), INT_MAX);
    distances[node] = 0;

    for (int i = 0; i < graph[node].size(); i++) {
        edges.push(graph[node][i]);
    }

    while (!edges.empty()) {
    	edge current = edges.front();
        edges.pop();

        int newDistance = distances[current.from] + current.distance;

        if (newDistance >= distances[current.to]) {
            continue;
        }

        distances[current.to] = newDistance;

        for (int i = 0; i < graph[current.to].size(); i++) {
            edges.push(graph[current.to][i]);
        }
    }
}

int main() {
	vector<vector<edge> > graph = {
		{edge(0, 1, 5), edge(0, 6, 5)}, 
		{edge(1, 0, 5), edge(1, 6, 5), edge(1, 3, 3), edge(1, 2, 3)},
		{edge(2, 1, 3), edge(2, 3, 1)},
		{edge(3, 2, 1), edge(3, 1, 3), edge(3, 6, 3), edge(3, 4, 5), edge(3, 5, 4)},
		{edge(4, 3, 5), edge(4, 5, 2)},
		{edge(5, 4, 2), edge(5, 3, 4), edge(5, 6, 5)},
		{edge(6, 0, 5), edge(6, 1, 5), edge(6, 3, 3), edge(6, 5, 5)},
	};
	
	vector<int> distances;

    dijkstra(graph, distances, 0);
    
    for(int dist : distances) {
    	cout << dist << " ";
    }

    cout << endl;

    return 0;
}
```
{% endcode %}

### Opis implementacji

![Przykładowy graf wykorzystany w implementacji](../../../../.gitbook/assets/example_graph_weighted.png)

{% embed url="http://graphonline.ru/en/?graph=DZlFqSBPNgdHwNXK" %}