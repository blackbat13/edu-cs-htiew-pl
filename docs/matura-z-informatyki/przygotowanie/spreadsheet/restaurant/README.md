# Restauracja

W pliku *restaurant.txt* znajdują się dane o zamówieniach pewnej restauracji z 2023 roku. Restauracja jest otwierana każdego dnia o 10:00:00, a zamykana o 00:00:00. Każda linia zawiera dane jednego zamówienia:

- numer stolika: liczba naturalna od 1 do 10
- kwota zamówienia: liczba rzeczywista z dokładnością do 2 miejsc po przecinku
- rodzaj zamówienia: liczba naturalna od 1 do 31 opisana poniżej
- data zamówienia
- czas zamówienia

Dane są rodzielone średnikami. Pierwszy wiersz pliku zawiera nazwy kolumn.

{% file src="../../../../.gitbook/assets/restaurant/restaurant.txt" %}
restaurant.txt
{% endfile %}

Rodzaj zamówienia zakodowany jest za pomocą liczby naturalnej. Zapis binarny tej liczby na 5 bitach zawiera informacje o tym, co zostało zamówione. Jedynka na danym miejscu oznacza, że została zamówiona pozycja z menu odpowiadająca danemu miejscu. Idąc od bitu **najmniej znaczącego**, kolejne pozycje odpowiadają następującym kategoriom:

- napój ciepły
- napój zimny
- przystawka
- danie główne
- deser

{% hint style="info" %}
**Przykład**

Liczba $$10$$ zapisana na pięciu bitach to: $$01001$$

Co oznacza to, że zostały zamówione:

- pozycja 1 (napój ciepły)
- pozycja 4 (danie główne)
{% endhint %}

# Zadanie 1

Policz ile łącznie zostało zamówionych dań z poszczególnych kategorii (napój ciepły, napój zimny, przystawka, danie główne, deser).

Dla pierwszych 100 wierszy wynik to:

|      **Rodzaj**     | **Napój ciepły** | **Napój zimny** | **Przystawka** | **Danie główne** | **Deser** |
|:-------------------:|:----------------:|:---------------:|:--------------:|:----------------:|:---------:|
| **Liczba zamówień** |        $$49$$        |        $$59$$       |       $$48$$       |        $$56$$        |     $$50$$    |

## Zadanie 2

Znajdź, które godziny są najbardziej popularne wśród klientów, analizując czas zamówień. Wykonaj wykres prezentujący liczby zamówień dokonanych w każdej godzinie.

O godzinie 10 złożonych zostało 80 zamówień.

## Zadanie 3

Oblicz, ile zamówień zostało dokonanych w weekend (sobota-niedziela), a ile w dni robocze.

Dla pierwszych 10 zamówień z pliku, cztery zostały dokonane w weekend.

## Zadanie 4

Dla każdego miesiąca policz liczbę zamówień w następujących przedziałach cenowych: poniżej 50,00 zł, od 50,00 do 100,00 zł, od 100,01 do 150,00 zł i powyżej 150,00 zł. Dane przedstaw na wykresie.

Wynik dla stycznia:

| **Miesiąc** | **Liczba zamówień poniżej 50,00 zł** | **Liczba zamówień od 50,00 do   100,00 zł** | **Liczba zamówień od 100,01 do   150,00 zł** | **Liczba zamówień powyżej 150,00   zł** |
|:-----------:|:------------------------------------:|:-------------------------------------------:|:--------------------------------------------:|:---------------------------------------:|
|     styczeń     |                  $$20$$                  |                      $$19$$                     |                      $$16$$                      |                    $$17$$                   |

## Zadanie 5

Zbadaj, które kombinacje zamówień (np. napój ciepły + danie główne, przystawka + deser) są najpopularniejsze, tzn. były najczęściej zamawiane. Jeżeli jest kilka takich kombinacji, to podaj wszystkie.

**Najmniej popularne** zamówienie składało się z samego napoju ciepłego.

## Zadanie 6

Klienci restauracji zwyczajowo zostawiają napiwki po każdym zamówieniu. Wysokość napiwków zależy od złożonego zamówienia:

- jeżeli zamówienie zawierało danie główne, przystawkę oraz deser, to napiwki wynoszą 20% z kwoty zamówienia,
- jeżeli zamówienie zawierało dokładnie dwie z następujących pozycji: danie główne, przystawkę, deser (napój nie ma znaczenia), to napiwki wynoszą 10% z kwoty zamówienia,
- jeżeli zamówienie zawierało dokładnie jedno z następujących pozycji: danie główne, przystawkę, deser (napój nie ma znaczenia), to napiwki wynoszą 5% z kwoty zamówienia,
- jeżeli zamówienie zawierało jedynie napój, to napiwki wynoszą 2% z kwoty zamówienia.

Napiwki są zawsze zaokrąglane **w górę** do pełnych groszy.

Oblicz wysokość napiwków dla każdego miesiąca z podziałem na stoliki.

W styczniu wysokość napiwków ze stolika pierwszego wynosiła $$24,14$$ złotych.

## Zadanie 7

Właściciel restauracji postanawia wprowadzić następującą promocję: każde zamówienie składające się z conajmniej dwóch pozycji (danie główne, przystawka, deser) będzie objęte zniżką wynoszącą 15% kwoty całego zamówienia (zaokrąglonej **w dół** do pełnych groszy). Promocja nie ma trwać jednak cały dzień, a w wybranych dwóch pełnych godzinach w ciągu dnia. Przeprowadź analizę, o ile mniejsze byłyby przychody restauracji po wprowadzeniu tej promocji dla każdego przedziału dwugodzinnego w ciągu dnia w godzinach działania restauracji, tzn. od 10:00:00 do 11:59:59, od 11:00:00 do 12:59:59 itd. aż do przedziału od 22:00:00 do 23:59:59.

Wyniki przedstaw na wykresie. Zadbaj o czytelność wykresu.

W przedziale godzinowym od 10:00:00 do 11:59:59 sumy przychody restauracji byłyby mniejsze o $$1210,14$$ zł.