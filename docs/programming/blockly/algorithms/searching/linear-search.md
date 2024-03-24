# Wyszukiwanie liniowe

## Opis problemu

{% content-ref url="../../../../algorithms/searching/linear-search.md" %}
[linear-search.md](../../../../algorithms/searching/linear-search.md)
{% endcontent-ref %}

## Istnienie elementu

### Wyszukiwanie

![Funkcja sprawdzająca, czy element znajduje się w tablicy](<../../../../.gitbook/assets/image (26).png>)

### Kod główny

![Przykładowe zastosowanie funkcji](<../../../../.gitbook/assets/image (27).png>)

### Link do implementacji

{% embed url="https://blockly-demo.appspot.com/static/demos/code/index.html?lang=pl#sofcb5" %}
Wyszukiwanie liniowe - istnienie elementu
{% endembed %}

### Opis implementacji

Funkcja **SzukajLiniowo** zwraca jako wynik wartość prawda/fałsz i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przypisujemy do zmiennej **wynik** wartość _fałsz_ oznaczającą, że nie znaleźliśmy poszukiwanego elementu. W tym momencie jest to zrozumiałe, jako że jeszcze nie zaczęliśmy poszukiwań. Następnie przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$1$$ do długości tablicy włącznie. Długość tablicy pobieramy korzystając z polecenia/bloku **długość**. Dla każdego indeksu (zapisanego w zmiennej **i**) sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość. Jeżeli tak, to przypisujemy do zmiennej **wynik** wartość _prawda_ i przerywamy działanie pętli. Po wyjściu z pętli (tzn. gdy przeszliśmy przez wszystkie indeksy, lub zakończyliśmy działanie pętli wcześniej) zwracamy jako wynik funkcji wartość zmiennej **wynik**.

W części głównej programu na początku przygotowujemy dane do problemu: tablicę oraz wartość poszukiwanego elementu. Następnie wywołujemy funkcję **SzukajLiniowo** z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w zmiennej **wynik**. W zależności od wyniku wypisujemy odpowiedni komunikat.

## Pozycja elementu

### Wyszukiwanie

![Funkcja znajdująca pozycję elementu w tablicy](<../../../../.gitbook/assets/image (28).png>)

### Kod główny

![Przykładowe zastosowanie funkcji](<../../../../.gitbook/assets/image (29).png>)

### Link do implementacji

{% embed url="https://blockly-demo.appspot.com/static/demos/code/index.html?lang=pl#sdj7gu" %}
Wyszukiwanie liniowe - pozycja elementu
{% endembed %}

### Opis implementacji

Funkcja **SzukajLiniowo** zwraca jako wynik liczbę całkowitą i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przypisujemy do zmiennej **wynik** wartość $$-1$$_ _oznaczającą, że nie znaleźliśmy poszukiwanego elementu. W tym momencie jest to zrozumiałe, jako że jeszcze nie zaczęliśmy poszukiwań. Następnie przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$1$$ do długości tablicy włącznie. Długość tablicy pobieramy korzystając z polecenia/bloku **długość**. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość. Jeżeli tak, to przypisujemy do zmiennej **wynik** wartość indeksu zapisaną w zmiennej **i**, a następnie przerywamy działanie pętli. Po wyjściu z pętli (tzn. gdy przeszliśmy przez wszystkie indeksy, lub zakończyliśmy działanie pętli wcześniej) zwracamy jako wynik funkcji wartość zmiennej **wynik**.

W części głównej programu na początku przygotowujemy dane do problemu: tablicę oraz wartość poszukiwanego elementu. Następnie wywołujemy funkcję **SzukajLiniowo** z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w zmiennej **pozycja**. W zależności od wyniku wypisujemy odpowiedni komunikat.

## Wszystkie pozycje elementu

### Wyszukiwanie

![Funkcja wypisująca wszystkie wystąpienia elementu w tablicy](<../../../../.gitbook/assets/image (30).png>)

### Kod główny

![Przykładowe zastosowanie funkcji](<../../../../.gitbook/assets/image (31).png>)

### Link do implementacji

{% embed url="https://blockly-demo.appspot.com/static/demos/code/index.html?lang=pl#3aupgb" %}
Wyszukiwanie liniowe - wszystkie pozycje elementu
{% endembed %}

### Opis implementacji

Funkcja **SzukajLiniowo** nie zwraca wyniku i przyjmuje dwa argumenty: tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy od $$1$$ do długości tablicy włącznie. Długość tablicy pobieramy korzystając z polecenia/bloku **długość**. Dla każdego indeksu sprawdzamy, czy pod tym indeksem w tablicy znajduje się poszukiwana wartość. Jeżeli tak, to wypisujemy wartość indeksu zapisaną w zmiennej **i**.

W części głównej programu na początku przygotowujemy dane do problemu: tablicę oraz wartość poszukiwanego elementu. Następnie wypisujemy stosowny komunikat i wywołujemy funkcję **SzukajLiniowo** z wcześniej przygotowanymi parametrami.
