# Kody Huffmana

## [:link: Opis problemu](../../../../algorithms/coding-and-compression/huffman-coding.md)

## Implementacja

```cpp
#include <iostream>
#include <deque>
#include <algorithm>
#include <map>

using namespace std;

struct node{
    char letter;
    int value;
    node *left;
    node *right;
};

bool compare(node *a, node *b) {
    return a->value < b->value;
}

node* createTree(string text) {
    deque<node*> nodes;
    sort(text.begin(), text.end());
    node *newNode = new node{text[0], 1, NULL, NULL};
    nodes.push_front(newNode);
    for(int i = 1; i < text.length(); i++) {
        if(text[i] == text[i - 1]) {
            nodes[0]->value++;
        } else {
            newNode = new node{text[i], 1, NULL, NULL};
            nodes.push_front(newNode);
        }
    }

    sort(nodes.begin(), nodes.end(), compare);
    while(nodes.size() > 1) {
        node *first, *second;
        first = nodes[0];
        nodes.pop_front();
        second = nodes[0];
        nodes.pop_front();
        newNode = new node{' ', first->value + second->value, first, second};
        nodes.push_back(newNode);
        sort(nodes.begin(), nodes.end(), compare);
    }

    return nodes[0];
}

void createCodes(node *tree, map<char, string> &codes, string path) {
    if(tree->left == NULL && tree->right == NULL) {
        codes[tree->letter] = path;
        return;
    }

    if(tree->left != NULL) {
        createCodes(tree->left, codes, path + "0");
    }

    if(tree->right != NULL) {
        createCodes(tree->right, codes, path + "1");
    }
}

string compress(string text, map<char, string> &codes) {
    string compressed = "";
    for(auto el : text) {
        compressed += codes[el];
    }

    return compressed;
}

int main() {
    string text = "papuga";
    node *tree = createTree(text);
    map<char, string> codes;
    createCodes(tree, codes, "");

    for(auto el : codes) {
        cout << el.first << " - " << el.second << endl;
    }

    string compressed = compress(text, codes);

    cout << compressed << endl;
    
    return 0;
}
```
