# Kody Huffmana

## [:link: Opis problemu](../../../../algorithms/coding-and-compression/huffman-coding.md)

## Implementacja

```python linenums="1"
class Node:
    def __init__(self, letter = "", value = 0, left = None, right = None):
        self.letter = letter
        self.value = value
        self.left = left
        self.right = right

def create_tree(text):
    nodes_list = []
    letters_set = set(text)
    nodes_list = [Node(letter, text.count(letter)) for letter in letters_set]
    nodes_list.sort(key=lambda el: el.value)
    while len(nodes_list) > 1:
        first = nodes_list.pop(0)
        second = nodes_list.pop(0)
        new_node = Node("", first.value + second.value, first, second)
        nodes_list.append(new_node)
        nodes_list.sort(key=lambda el: el.value)

    return nodes_list[0]

def create_codes(tree, codes, path):
    if tree.left is None and tree.right is None:
        codes[tree.letter] = path
        return

    if tree.left is not None:
        create_codes(tree.left, codes, path + "0")

    if tree.right is not None:
        create_codes(tree.right, codes, path + "1")

def compress(text, codes):
    compressed = ""
    for letter in text:
        compressed += codes[letter]

    return compressed

def decompress(compressed, tree):
    decompressed = ""
    current_node = tree
    for bit in compressed:
        if bit == "0":
            current_node = current_node.left
        elif bit == "1":
            current_node = current_node.right

        if current_node.left is None and current_node.right is None:
            decompressed += current_node.letter
            current_node = tree

    return decompressed

text = "papuga"
tree = create_tree(text)
codes = dict()
create_codes(tree, codes, "")

print("Codes:", codes)

compressed = compress(text, codes)
print("Compressed:", compressed)

decompressed = decompress(compressed, tree)
print("Decompressed:", decompressed)
```

### Opis implementacji

Klasa `Node` reprezentuje węzeł w drzewie **Huffmana**. Każdy węzeł przechowuje literę (`letter`), wartość (`value`), lewe poddrzewo (`left`) i prawe poddrzewo (`right`).

Funkcja `create_tree` tworzy drzewo Huffmana na podstawie podanego tekstu. Na początku tworzona jest pusta lista `nodes_list`, która będzie przechowywać węzły drzewa. Następnie tworzony jest zbiór unikalnych liter z tekstu. Dla każdej litery w zbiorze, tworzony jest węzeł i dodawany do listy `nodes_list`, gdzie wartość węzła to liczba wystąpień danej litery w tekście. Węzły są sortowane rosnąco względem wartości. Następnie, w pętli, dopóki lista `nodes_list` ma więcej niż jeden element, usuwane są dwa pierwsze węzły z najmniejszymi wartościami, a następnie tworzony jest nowy węzeł, który jest sumą wartości tych dwóch węzłów. Nowy węzeł jest dodawany do listy `nodes_list` i lista jest sortowana ponownie. Proces ten jest powtarzany, aż do momentu, gdy w liście `nodes_list` pozostaje tylko jeden węzeł, który jest korzeniem drzewa. Ten korzeń jest zwracany przez funkcję `create_tree`.

Funkcja `create_codes` tworzy kodowanie dla każdej litery na podstawie drzewa Huffmana. Funkcja jest rekurencyjna. Jeśli dany węzeł nie ma dzieci (lewej i prawej gałęzi), oznacza to, że reprezentuje on konkretną literę. W takim przypadku przypisywany jest kod (ścieżka) do tej litery w słowniku `codes`. Jeśli dany węzeł ma lewego potomka, rekurencyjnie wywoływana jest funkcja `create_codes` dla lewego potomka, a do kodu (ścieżki) dodawane jest "0". Jeśli dany węzeł ma prawego potomka, rekurencyjnie wywoływana jest funkcja `create_codes` dla prawego potomka, a do kodu (ścieżki) dodawane jest "1".

Funkcja `compress` kompresuje tekst na podstawie utworzonych kodów dla liter. Przechodząc przez każdą literę w tekście, kod dla danej litery jest dodawany do zmiennej `compressed`.

Funkcja `decompress` przyjmuje skompresowany tekst (`compressed`) oraz korzeń drzewa Huffmana (`tree`). Iteruje po każdym bicie w skompresowanym tekście. Jeśli bit jest równy "0", przechodzi do lewego potomka węzła bieżącego (`current_node`), a jeśli bit jest równy "1", przechodzi do prawego potomka. Gdy osiągnie liść drzewa (czyli węzeł, który nie ma dzieci), dodaje jego literę do dekompresowanego tekstu (`decompressed`) i przechodzi z powrotem do korzenia drzewa. Proces ten powtarza się, aż do przetworzenia wszystkich bitów skompresowanego tekstu.

W przykładzie, tekst "papuga" jest kompresowany. Na początku tworzone jest drzewo Huffmana za pomocą funkcji `create_tree`. Następnie za pomocą funkcji `create_codes` tworzone są kody dla liter, które są przechowywane w słowniku `codes`. Następnie tekst jest kompresowany funkcją `compress` i wynikowy skompresowany tekst jest wyświetlany. Na końcu skompresowany tekst jest dekompresowany funkcją `decompress` i wynikowy zdekompresowany tekst jest wyświetlany.
