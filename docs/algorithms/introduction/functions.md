# Funkcje

Wyobraźmy sobie czarne magiczne pudełko. Takie pudełko, do którego coś wrzucamy i coś innego z niego wypada. Wkładamy do niego **wejście**, a wychodzi **wyjście**:

![](<../../.gitbook/assets/image (32).png>)

Inaczej mówiąc, wkładamy do pudełka pewne **dane**, a wyciągamy z niego **wynik**:

![](<../../.gitbook/assets/image (33).png>)

Takie pudełko reprezentuje nam właśnie **funkcję**.

## Czym jest funkcja?

W programowaniu pojęcie funkcji możemy rozumieć wielorako. Najłatwiej myśleć o tym jak o pewnym **fragmencie** programu, który ma konkretne zadanie i swoją własną nazwę. Do funkcji przekazujemy dane w postaci **parametrów**, a w odpowiedzi dostajemy wynik zgodny ze **specyfikacją** funkcji.

{% hint style="danger" %}
Nie należy mylić funkcji w programowaniu i funkcji w matematyce, to dwa zupełnie różne twory!
{% endhint %}

Schematyczny zapis funkcji przedstawia się następująco:

```
funkcja NazwaFunkcji(parametr1, parametr2, ...):
    Operacja1
    Operacja2
    ...
    Zwróć wynik
```

## Przykład - automat do kawy

Wyobraźmy sobie automat do kawy, taki jaki stoi na korytarzach wielu biur, szkół i dworców kolejowych. Możemy powiedzieć, że reprezentuje ona pewną funkcję, zgodną z poniższą specyfikacją:

### Specyfikacja

#### Dane

* **wybór** - wybrany napój
* **pieniądze** - należna kwota

#### Wynik

* Wybrany napój.

{% hint style="info" %}
Oczywiście jest to bardzo uproszczona specyfikacja. W rzeczywistości taki automat nie wyda nam napoju, jeśli nie uiścimy odpowiedniej opłaty. Czasem oprócz napoju dostaniemy też resztę. Taka specyfikacja wystarczy nam jednak do przykładu.
{% endhint %}

Spróbujmy zapisać fragment funkcji realizowanej przez taki automat w postaci pseudokodu:

```
funkcja AutomatDoKawy(wybór, pieniądze):
    1. Jeżeli wybór = "latte" i pieniądze = 3.0, to:
        2. Zwróć Latte i zakończ   
```

## Procedura

W przeciwieństwie do funkcji procedura **nie zwraca konkretnego wyniku**. Jaki więc może być jej cel? Procedurę możemy zastosować, by np. zmienić wartości zmiennych przekazanych jako parametry (jeżeli je odpowiednio przekażemy), zmienić wartości zmiennych globalnych, albo wypisać komunikat na ekranie. Możemy łatwo wyobrazić sobie procedurę powitanie, która przyjmuje imię użytkownika i wyświetla na ekranie stosowny komunikat:

```
procedura Powitanie(imie):
    1. Wypisz "Witaj "
    2. Wypisz imie
    3. Wypisz "!"
    4. Wypisz znak nowej liniii
    5. Zakończ
```

{% hint style="warning" %}
Współcześnie już praktycznie nie rozróżniamy pomiędzy funkcją a procedurą. W wielu językach programowania występują tylko funkcje, w tym też takie, które nie zwracają wyniku (albo których wynik ignorujemy).
{% endhint %}

## Prezentacja

{% file src="../../.gitbook/assets/Funkcje - wprowadzenie.pdf" %}
Funkcje - wprowadzenie
{% endfile %}
