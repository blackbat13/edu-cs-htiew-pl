# Odwrotna Notacja Polska

**Odwrotna notacja polska** (ang. *Reverse Polish Notation*, *RPN*) jest formą notacji, która jest używana w matematyce, informatyce i niektórych modelach kalkulatorów. Nazwa odnosi się do narodowości logika, Jana Łukasiewicza, który pierwotnie zaproponował ten styl notacji. W przeciwieństwie do notacji w której operator jest pomiędzy operandami (infix), w odwrotnej notacji polskiej operator jest umieszczany po operandach.

Na przykład, zamiast pisać `2 + 3`, używając odwrotnej notacji polskiej, napisalibyśmy `2 3 +`.

Odwrotna notacja polska eliminuje konieczność używania nawiasów do wskazania kolejności operacji i ułatwia obliczenia dla maszyn, szczególnie kalkulatorów i komputerów.

## Algorytm ewaluacji wyrażeń zapisanych w Odwrotnej Notacji Polskiej

1. Przejrzyj wyrażenie od lewej do prawej.
2. Gdy napotkasz liczbę, dodaj ją do stosu.
3. Gdy napotkasz operator, zdejmij z góry stosu tyle liczb ile jest argumentów operatora, wykonaj operację, a wynik wrzuć na stos.
4. Gdy przejrzysz całe wyrażenie, na stosie powinna zostać jedna liczba - wynik całego wyrażenia.

## Przykład

Weźmy na przykład wyrażenie matematyczne `2 * (3 + 4)`. W odwrotnej notacji polskiej wyrażenie to staje się `2 3 4 + *`. Prześledźmy, jak możemy obliczyć jego wartość.

### Ewaluacja wyrażenia

1. Przejrzyj wyrażenie od lewej do prawej. Na początku stos jest pusty.
2. Pierwsze dwie liczby to $2$ i $3$, które są dodawane do stosu.
3. Kolejna liczba to $4$, która jest dodawana do stosu.
4. Napotykamy operator $+$. Zdejmujemy dwie ostatnie liczby ze stosu, dodajemy je do siebie $(3 + 4 = 7)$, a wynik wrzucamy na stos.
5. Ostatecznie napotykamy operator $*$. Zdejmujemy dwie ostatnie liczby ze stosu, mnożymy je przez siebie $(2 * 7 = 14)$, a wynik wrzucamy na stos.
6. Przejrzeliśmy całe wyrażenie. Na stosie pozostała jedna liczba - $14$, co jest wynikiem całego wyrażenia.

Z powyższego przykładu widać, że korzystanie z Odwrotnej Notacji Polskiej może znacznie uprościć obliczenia, szczególnie dla komputerów i kalkulatorów.

## Specyfikacja

### Dane

* **onp** - ciąg znaków reprezentujący poprawne wyrażenie w Odwrotnej Notacji Polskiej

### Wynik

* Wartość wyrażenia **onp**

## Przykład

### Dane

```
onp := "27+3/13-4*+2/"
```

**Wynik**: $-2.5$

!!! info
	**Wyjaśnienie**
	
	Przedstawione wyrażenie ONP odpowiada następującemu wyrażeniu arytmetycznemu:
	
	$(((2 + 7) / 3) + (1 - 3) * 4) / 2$

## Implementacja

### C++


[rpn.md](../../programming/c++/algorithms/text/rpn.md)


### Python


[rpn.md](../../programming/python/algorithms/text/rpn.md)

