# HTTP

## Odczytanie nagłówka HTTP - przykład

Powiedzmy, że analizujemy przedstawioną poniżej odpowiedź na zapytanie http GET.

![Odpowiedź na zapytanie](../../.gitbook/assets/http1.png)

Program Wireshark pokazuje nam pokazaną poniżesz zawartość pakietu i nagłówka http.

![Podgląd z programu Wireshark](../../.gitbook/assets/http2.png)

Przedstawmy najważniejsze pola nagłówka http w formie uproszczonej tabelki (jeżeli chcielibyśmy być bardzo dokładni, to powinniśmy przepisać wszystkie pola, ale skupimy się tylko na części z nich).

![Pusty nagłówek HTTP](../../.gitbook/assets/http3.png)

Teraz wypełnijmy tabelkę treścią. Pierwsza wartość (*response line*) to odpowiedź serwera, czyli pierwsza linia, jaką pokazuje Wireshark w nagłówku http: **HTTP/1.1 200 OK** (znaki \r oraz \n to kody białych znaków, czyli np. znaku nowej linii, nie trzeba ich przepisywać).
Pozostałe wartości przepisujemy (kopiujemy) bezpośrednio z Wiresharka.

![Wypełniony nagłówek HTTP](../../.gitbook/assets/http4.png)