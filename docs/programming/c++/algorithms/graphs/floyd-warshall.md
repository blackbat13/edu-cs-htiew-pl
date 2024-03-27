---
description: Najkrótsze ścieżki pomiędzy wszystkimi wierzchołkami
---

# Floyd-Warshall

## [Opis problemu](../../../../algorithms/graphs/floyd-warshall.md)

## Implementacja

```cpp linenums="1"
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

void floydWarshall(vector<vector<edge> > &graph, vector<vector<int> > &distances) {
    distances = vector<vector<int> >(graph.size(), vector<int>(graph.size(), INT_MAX / 2));
    for(int node = 0; node < graph.size(); node++) {
        distances[node][node] = 0;
        for(int i = 0; i < graph[node].size(); i++) {
            distances[node][graph[node][i].to] = graph[node][i].distance;
        }
    }

    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph.size(); j++) {
            for(int k = 0; k < graph.size(); k++) {
                if(distances[i][j] > distances[i][k] + distances[k][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
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
	
	vector<vector<int> > distances;

    floydWarshall(graph, distances);
    
    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph.size(); j++) {
            cout << distances[i][j] << " ";
        }
        
        cout << endl;
    }

    return 0;
}
```

### Opis implementacji

![Przykładowy graf wykorzystany w implementacji](../../../../assets/example_graph_weighted.png)

[http://graphonline.ru/en/?graph=DZlFqSBPNgdHwNXK](http://graphonline.ru/en/?graph=DZlFqSBPNgdHwNXK)