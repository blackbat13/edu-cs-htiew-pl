# Tablice statyczne

## Zadanie 1

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$a_1,a_2,\dots,a_n$$ - $$n$$ liczb całkowitych

#### Wynik

* $$a_n,a_{n-1},\dots,a_2,a_1$$ - podane liczby w odwrotnej kolejności

### Przykład

#### Dane

```
n := 5
a1 := 1
a2 := 2
a3 := 3
a4 := 4
a5 := 5
```

**Wynik**: $$5, 4, 3, 2, 1$$ 

## Zadanie 2

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$a_1,a_2,\dots,a_n$$ - $$n$$ liczb całkowitych
* $$k$$ - liczba naturalna, $$1<=k<=n$$

#### Wynik

* $$a_k$$ - $$k$$-ta podana liczba

### Przykład

#### Dane

```
n := 5

a1 := 8
a2 := 3
a3 := 9
a4 := 1
a5 := 2

k := 3
```

**Wynik**: $$9$$ 

{% hint style="info" %}
**Wyjaśnienie**

$$k := 3$$, a trzecia podana wartość wynosi $$9$$ (a3 := 9). 
{% endhint %}

## Zadanie 3

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$a_1,a_2,\dots,a_n$$ - $$n$$ liczb całkowitych
* $$p, k$$ - dwie liczby naturalna, $$1<=p,k<=n$$, $$p <= k$$

#### Wynik

* $$a_p+a_{p+1}+a_{p+2}+...+a_{k}$$ - suma wartości na pozycjach od $$p$$ do $$k$$

### Przykład

#### Dane

```
n := 5

a1 := 8
a2 := 3
a3 := 9
a4 := 1
a5 := 2

p := 3
k := 5
```

**Wynik**: $$12$$ 

{% hint style="info" %}
**Wyjaśnienie**

$$a_3+a_4+a_5=9+1+2=12$$
{% endhint %}

## Zadanie 4

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$t1[n],\ t2[n]$$ - dwie tablice liczb całkowitych

#### Wynik

* Tablica powstała poprzez dodanie do siebie wartości z tablic $$t1$$ i $$t2$$ 

### Przykład

#### Dane

```
n := 5
t1 := [4, 1, 7, 0, 2]
t2 := [2, 3, 1, 9, 6]
```

**Wynik**: $$6, 4, 8, 9, 8$$ 

{% hint style="info" %}
**Wyjaśnienie**

$$[4+2,\ 1+3,\ 7+1,\ 0+9,\ 2+6]$$ 
{% endhint %}

## Zadanie 5

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* $$fib[n]$$ - tablica zawierająca $$n$$ kolejnych liczb Fibonacciego

### Przykład

#### Dane

```
n := 6
```

**Wynik**: $$1, 1, 2, 3, 5, 8$$ 

## Zadanie 6

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna

#### Wynik

* $$mno[n][n]$$ - dwuwymiarowa tablica reprezentująca tabliczkę mnożenia liczb z zakresu $$[0,n-1]$$, gdzie $$mno[i][j]=i*j$$

### Przykład

#### Dane

```
n := 3
```

#### Wynik

```
mno := [[0, 0, 0],
        [0, 1, 2],
        [0, 2, 4]]
```

## Zadanie 7

Napisz program zgodny z poniższą specyfikacją.

### Specyfikacja

#### Dane

* $$n$$ - liczba naturalna
* $$tab[n]$$ - tablica liczb całkowitych

#### Wynik

* Komunikat "niemalejaco" jeżeli elementy tablicy posortowane są niemalejąco
* Komunikat "nierosnaco" jeżeli elementy tablicy posortowane są nierosnąco
* Komunikat "nieposortowane" jeżeli elementy tablicy nie są posortowane

### Przykład 1

#### Dane

```
n := 5
tab := [1, 1, 5, 6, 8]
```

**Wynik**: "niemalejąco"

### Przykład 2

#### Dane

```
n := 5
tab := [8, 5, 5, 3, 1]
```

**Wynik**: "nierosnąco"

### Przykład 3

#### Dane

```
n := 5
tab := [1, 2, 3, 1, 5]
```

**Wynik**: "nieposortowane"