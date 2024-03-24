# C++

## Implementacja

```cpp
#include <cstdio>
#include <iostream>

using namespace std;

int compute(int n, int k, int c[]) {
    int left = 0, right = 0, current_cost = 0, mx = 0;
    while(right < n) {
        if(current_cost + c[right] <= k) {
            current_cost += c[right];
            right++;
        } else {
            current_cost -= c[left];
            left++;
        }

        if(right < left) {
            right = left;
            current_cost = 0;
        }

        if(right - left + 1 > mx) {
            mx = right - left + 1;
        }
    }

    return mx;
}

int main() {
    int n, k, result;

    scanf("%d %d", &n, &k);

    int h[n], h_r[n];
    int c[n - 1], c_r[n - 1];

    for (int i = 0; i < n; i++) {
        scanf("%d", &h[i]);
        h_r[n - i - 1] = h[i];
    }

    for(int i = 1; i < n; i++) {
        if(h[i] < h[i - 1]) {
            c[i - 1] = 0;
        } else {
            c[i - 1] = h[i] - h[i - 1];
        }

        if(h_r[i] < h_r[i - 1]) {
            c_r[i - 1] = 0;
        } else {
            c_r[i - 1] = h_r[i] - h_r[i - 1];
        }
    }

    result = compute(n - 1, k, c);
    result = max(result, compute(n - 1, k, c_r));
    
    printf("%d", result);

    return 0;
}
```
