# Nawiasy

Dany jest ciąg złożony z nawiasów okrągłych (), kwadratowych [] oraz klamrowych {}. Ciąg nawiasów nazwiemy **poprawnym**, gdy:

* jest pustym ciągiem,
* jeżeli $$A$$ i $$B$$ są poprawne, to $$AB$$ także jest poprawne,
* jeżeli $$A$$ jest poprawne, to $$(A)$$, $$[A]$$ oraz $$\{A\}$$ także są poprawne.

W pliku *parentheses.txt* znajduje się $$100$$ ciągów nawiasów, jak opisano powyżej, każdy zapisany w osobnym wierszu.

{% file src="../../../../.gitbook/assets/parentheses.txt" %}
parentheses.txt
{% endfile %}

W pliku *parentheses_test.txt* znajduje się $$10$$ ciągów nawiasów, jak opisano powyżej, każdy zapisany w osobnym wierszu.

{% file src="../../../../.gitbook/assets/parentheses_test.txt" %}
parentheses_test.txt
{% endfile %}

Napisz program/programy rozwiązujące poniższe zadania.

## Zadanie 1

Podaj, ile ciągów nawiasów w pliku *parentheses.txt* jest **poprawnych**. Dla pliku *parentheses_test.txt* poprawny wynik to $$8$$.

## Zadanie 2

Wypisz ciągi nawiasów z pliku *parentheses.txt* posortowane niemalejąco pod względem trzech kryteriów (jednocześnie, priorytet kryterium zgodny z kolejnością): liczby nawiasów okrągłych, liczby nawiasów kwadratowych oraz liczby nawiasów klamrowych. Dla pliku *parentheses_test.txt* poprawny wynik to:

{% code overflow="wrap" lineNumbers="true" %}
```
[()]{[]}{[]}[]
[{[]}[()][]][]
({[]}[{}]()){{{{}}[{}][]}{}}{}
([{()}]}]{})()
({}){{[{()}{}]()}{}}[]
[[]]([()]{()}())()
{{}}((({})[])[{}]{[]}())()
{[]}(()){{}}{{{[]}([[]][])()}{}}()
(({}){[]}{[([])[]]()}{[]}{[)()
({[]}[])[()]({[()][[]]{}}{})()
```
{% endcode %}

## Zadanie 3

Dla każdego ciągu nawiasów w pliku *parentheses.txt*, podaj długość najdłuższego spójnego podciągu nawiasów otwierających oraz długość najdłuższego spójnego podciągu nawiasów zamykających. Dla pliku *parentheses_test.txt* poprawny wynik to:

{% code overflow="wrap" lineNumbers="true" %}
```
4 2
3 2
4 5
5 2
4 2
4 2
4 2
4 2
3 2
2 2
```
{% endcode %}
