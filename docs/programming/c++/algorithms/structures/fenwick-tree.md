# Drzewo Fenwicka

## [:link: Opis problemu](../../../../algorithms/structures/fenwick-tree.md)

## Implementacja

```cpp linenums="1"
#include <iostream>
#include <vector>

using namespace std;

class FenwickTree {
    private:
        vector<int> tree;
        int n;

    public:
        FenwickTree(int n) {
            this->n = n;
            tree.assign(n, 0);
        }

        FenwickTree(vector<int> a) : FenwickTree(a.size()) {
            for(int i = 0; i < a.size(); i++) {
                tree[i] += a[i];
                int r = i | (i + 1);
                if (r < n) {
                    tree[r] += tree[i];
                }
            }
        }

        int sum(int r) {
            int result = 0;

            while (r >= 0) {
                result += tree[r];
                r = (r & (r + 1)) - 1;
            }

            return result;
        }

        int sum(int l, int r) {
            return sum(r) - sum(l - 1);
        }

        void add(int idx, int delta) {
            while (idx < n) {
                tree[idx] += delta;
                idx = idx | (idx + 1);
            }
        }

        void set(int idx, int value) {
            add(idx, value - sum(idx, idx));
        }
};

int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    FenwickTree tree(a);

    cout << tree.sum(0, 2) << endl;
    cout << tree.sum(0, 4) << endl;

    tree.add(3, 6);

    cout << tree.sum(0, 4) << endl;

    tree.set(4, 0);

    cout << tree.sum(0, 4) << endl;

    return 0;
}
```
