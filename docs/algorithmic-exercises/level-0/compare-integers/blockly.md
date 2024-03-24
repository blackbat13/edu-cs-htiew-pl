# Blockly

![Porównywanie liczb - Blockly](<../../../.gitbook/assets/image (9).png>)

## Link do implementacji

{% embed url="https://blockly-demo.appspot.com/static/demos/code/index.html?lang=pl#qv4ea5" %}
Porównywanie liczb - Blockly
{% endembed %}

## Opis

Na początku wczytujemy dwie liczby od użytkownika, podając przy tym stosowane komunikaty i zapisując je w zmiennych `a` i `b`.

Następnie, korzystając z instrukcji warunkowej, sprawdzamy relację pomiędzy wczytanymi wartościami. Jeżeli wartości zmiennych `a` i `b` są sobie równe to wypisujemy znak równości. W przeciwnym przypadku, jeżeli wartość zmiennej `a` jest mniejsza od wartości zmiennej `b` , to wypisujemy znak mniejszości. W przeciwnym przypadku wypisujemy znak większości.

Zwróć uwagę na to, że w ostatniej części instrukcji warunkowej, nie musimy już sprawdzać, czy wartość zmiennej `a` jest większa od wartości zmiennej `b`. Wynika to z poprzednich warunków. Jeżeli wartości zmiennych nie są sobie równe ani też `a` nie jest mniejsze od `b`, to wiemy, że `a` jest większe od `b`.
