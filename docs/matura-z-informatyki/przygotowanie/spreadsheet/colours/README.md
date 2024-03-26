# Kolory

W pliku *kolory.txt* znajduje się $100$ kolorów zapisanych w formacie szesnastkowym. Każda linia zawiera jeden kolor, którego zapis zaczyna się od znaku #, po którym następuje $6$ znaków alfanumerycznych: cyfr od $0$ do $9$ oraz liter od $a$ do $f$. Pierwszy wiersz zawiera nagłówek kolumny.

Kolor zapisany w formacie szesnastkowym interpretujemy następująco:

- pierwsze dwa znaki szesnastkowe oznaczają składową czerwoną (**R**ed),
- kolejne dwa znaki szesnastkowe oznaczają składową zieloną (**G**reen),
- ostatnie dwa znaki szesnastkowe oznaczają składową niebieską (**B**lue).

Każda z omówionych par znaków szesnastkowych reprezentuje liczbę w systemie szesnastkowym, której wartość w systemie dziesiętnym mieści się w przedziale $<0, 255>$.

[:material-note-text: kolory.txt](../../../../assets/kolory.txt)

## Zadanie 1

Każdy z kolorów przedstaw w postaci trzech wartości w systemie dziesiętnym w zapisie RGB.

## Zadanie 2

Dla każdego koloru policz, która ze składowych RGB ma największą wartość. Jeżeli więcej niż jedna składowa mają największą wartość, to wypisz tę, która jest pierwsza w kolejności RGB. Dla każdej składowej policz, ile razy jej wartość była największa. Wyniki przedstaw na wykresie kołowym. Zadbaj o czytelność wykresu i przedstawienie procentowych wartości. Dobierz kolory wykresu tak, by odpowiadały kolorom składowych.

## Zadanie 3

Korzystając z poniższych równań przedstaw każdy kolor w formacie CMYK.

$
Black(K)=1-(max(R,G,B)/255)\\
Cyan=(1-(R/255)-K)/(1-K)\\
Magenta=(1-(G/255)-K)/(1-K)\\
Yellow=(1-(B/255)-K)/(1-K)
$

## Zadanie 4

Dla każdego znaku szesnastkowego policz, ile razy łącznie wystąpił w zapisach wszystkich kolorów. Wyniki przedstaw na wykresie kolumnowym. Zadbaj o czytelność wykresu.
