# Podstawowe typy zmiennych

## Liczby całkowite

### Ze znakiem

<table><thead><tr><th>Typ</th><th data-type="number">Ilość bajtów</th><th>Zakres</th></tr></thead><tbody><tr><td><code>char</code></td><td>1</td><td><span class="math">[-2^{7},2^{7}-1]</span> </td></tr><tr><td><code>short</code></td><td>2</td><td><span class="math">[-2^{15},2^{15}-1]</span> </td></tr><tr><td><code>int</code></td><td>4</td><td><span class="math">[-2^{31},2^{31}-1]</span> </td></tr><tr><td><code>long int</code></td><td>4</td><td><span class="math">[-2^{31},2^{31}-1]</span> </td></tr><tr><td><code>long long int</code></td><td>8</td><td><span class="math">[-2^{63},2^{63}-1]</span> </td></tr></tbody></table>

### Bez znaku

<table><thead><tr><th>Typ</th><th data-type="number">Ilość bajtów</th><th>Zakres</th></tr></thead><tbody><tr><td><code>unsigned char</code></td><td>1</td><td><span class="math">[0,2^{8}-1]</span> </td></tr><tr><td><code>unsigned short</code></td><td>2</td><td><span class="math">[0,2^{16}-1]</span> </td></tr><tr><td><code>unsigned int</code></td><td>4</td><td><span class="math">[0,2^{32}-1]</span> </td></tr><tr><td><code>unsigned long int</code></td><td>4</td><td><span class="math">[0,2^{32}-1]</span> </td></tr><tr><td><code>unsigned long long int</code></td><td>8</td><td><span class="math">[0,2^{64}-1]</span> </td></tr></tbody></table>

## Liczby zmiennoprzecinkowe

<table><thead><tr><th>Typ</th><th data-type="number">Ilość bajtów</th><th>Zakres</th></tr></thead><tbody><tr><td><code>float</code></td><td>4</td><td><span class="math">\pm3.4e \pm 38</span> (~ 7 znaków)</td></tr><tr><td><code>double</code></td><td>8</td><td><span class="math">\pm1.7e \pm 308</span> (~ 15 znaków)</td></tr><tr><td><code>long double</code></td><td>10</td><td><span class="math">[3.4e-4932,1.1e+4932]</span> </td></tr></tbody></table>

