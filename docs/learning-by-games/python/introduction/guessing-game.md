# Gra w zgadywanie

## Wstęp

Stworzymy kolejną, prostą grę tekstową: grę w zgadywanie! Reguły są proste: najpierw komputer losuje liczbę z pewnego przedziału, a następnie użytkownik próbuje ją odgadnąć.

### Czego się nauczysz

* Wybierania losowej liczby.
* Korzystania z pętli warunkowej.
* Korzystania z instrukcji warunkowych.
* Zliczania liczby przebiegów pętli.

## Proste zgadywanie

Zaczynamy od prostego zgadywania. Komputer losuje liczbę od $$1$$ do $$10$$, a użytkownik próbuje ją odgadnąć. Gra będzie się toczyć dopóki użytkownik nie odgadnie wylosowanej liczby. 

### Losujemy ukrytą liczbę

Ponieważ będziemy losować liczbę, potrzebna nam jest biblioteka do liczb losowych, którą importujemy:

```python
import random
```

Teraz możemy wylosować liczbę od $$1$$ do $$10$$, którą zapiszemy w zmiennej `ukryta`:

```python
ukryta = random.randint(1, 10)
```

### Interakcja z użytkownikiem

Przyszedł czas na komunikację z użytkownikiem. Najpierw użytkownik wprowadzi jakąś liczbę, następnie komputer sprawdzi, czy jest ona taka sama, jak wylosowana na początku wartość. Jeżeli nie, to użytkownik będzie miał kolejną próbę. I tak w kółko, aż nie odgadnie.

Można się domyśleć, że będziemy potrzebowali pętli. Nie wiemy jednak, ile prób będzie potrzebował wykonać użytkownik, zanim uda mu się odgadnąć. Może wystarczy jedna próba, a może będzie potrzeba ich $$10$$. Jak więc zastosować pętlę?

### Wczytujemy liczbę od użytkownika

Zastanowimy się nad tym za chwilę. Na razie wczytajmy pierwszą próbę użytkownika:

```python
liczba = int(input("Podaj liczbę: "))
```

{% hint style="warning" %}
Pamiętamy, żeby skorzystać z polecenia `int`, ponieważ potrzebujemy liczbę, a nie tekst!
{% endhint %}

### Zgadujemy aż do skutku

Teraz chcielibyśmy sprawdzić, czy użytkownik odgadł, a jeżeli nie, to powtórzyć operację wczytania liczby. Spróbujmy to sformułować inaczej: chcemy wczytywać liczby od użytkownika, **dopóki** ten nie odgadnie ukrytej wartości. Innymi słowy, dopóki wartości zmiennych `liczba` i `ukryta` będą różne, to będziemy powtarzać operację wczytania liczby od użytkownika.

Do zrealizowania tego zadania posłuży nam pętla **warunkowa** `while`:

```python
while liczba != ukryta:
```

{% hint style="info" %}
Do sprawdzenia, czy dwie wartości są od siebie **różne**, używamy `!=`
{% endhint %}

Dopóki użytkownik nie odgadł poprawnie, będziemy wykonywać dwie operacje: wypiszemy stosowny komunikat i poprosimy użytkownika o podanie kolejnej liczby. Te dwie operacje wykonamy **w pętli**, pamiętamy więc o wcięciach.

```python
while liczba != ukryta:
    print("Nie")
    liczba = int(input("Podaj liczbę: "))
```

### Powiadamiamy użytkownika o sukcesie

Teraz pozostało nam wypisać stosowny komunikat, gdy użytkownik odgadnie ukrytą wartość. Jak sprawdzić, że użytkownikowi się udało? Moglibyśmy porównać ze sobą wartości zmiennych `liczba` i `ukryta`. Nie ma jednak takiej potrzeby. Z naszej pętli możemy wyjść tylko wtedy, gdy jej **warunek przestanie być prawdziwy**, tzn. gdy `liczba` i `ukryta` będą sobie równe. To znaczy, że gdy wyjdziemy z pętli, użytkownik odgadł poprawnie. W takim razie, po wyjściu z pętli (czyli bez wcięcia) wypisujemy stosowny komunikat:

```python
print("Tak!")
```

### Pełna gra z komentarzami

```python
# Importujemy bibliotekę, która pozwoli nam generować losowe liczby
import random

# Losujemy liczbę całkowitą z przedziału od 1 do 10
ukryta = random.randint(1, 10)

# Wczytujemy liczbę od użytkownika
liczba = int(input("Podaj liczbę: "))

# Dopóki użytkownik nie odgadł, jaką liczbę wylosował komputer
while liczba != ukryta:
    # Wypisujemy stosowny komunikat na ekranie
    print("Nie")

    # Ponownie prosimy użytkownika o podanie liczby
    liczba = int(input("Podaj liczbę: "))

# Skoro wyszliśmy z pętli, to znaczy, że użytkownik odgadł wylosowaną przez komputer liczbę
# Wypisujemy więc stosowny komunikat
print("Tak!")
```

### Testujemy działanie

Uruchom swoją grę.
Ile prób zajęło Ci odgadnięcie liczby?
Uruchom ją ponownie.
Za którym razem teraz udało Ci się odgadnąć?

Możesz także przetestować działanie gry poniżej.

{% embed url="https://replit.com/@damiankurpiewski/Zgadywanie1#main.py" %}

## Zgadywanie ciepło-zimno

Zgadywanie w "ciemno" nie jest wcale takie proste. Oczywiście, gdy mamy odgadnąć liczbę od $$1$$ do $$10$$ to w najgorszym przypadku będziemy potrzebowali dziesięciu prób, żeby w końcu odgadnąć prawidłowo. Co jednak, gdy chcielibyśmy pytać o liczby z większego przedziału, np. od $$1$$ do $$100$$, albo od $$1$$ do $$1000$$? Bez żadnych wskazówek odgadnięcie wylosowanej wartości będzie bardzo trudne.

Dlatego zmodyfikujemy naszą grę, by dać graczowi większe szanse na szybkie odgadnięcie liczby. Dodamy coś w rodzaju podpowiedzi jakie występują w grze "**ciepło-zimno**". Dla tych, którzy nie znają tej gry, krótkie wyjaśnienie. Jeden z graczy chowa jakiś przedmiot w pomieszczeniu, a drugi próbuje go odnaleźć. Gdy zbliża się do schowanego przedmiotu dostaje podpowiedź "**ciepło**", a gdy idzie w złym kierunku: "**zimno**".

Podobnie w naszej grze damy graczowi jedną z dwóch podpowiedzi: "**mniejsza**" lub "**większa**". W ten sposób, po nieudanej próbie odgadnięcia wartości gracz będzie wiedział, czy powinien szukać liczby większej, czy też mniejszej, co pomoże mu szybciej podać prawidłową odpowiedź. 

### Wyświetlanie podpowiedzi

Zabierzmy się za modyfikację naszej gry. Naszym zadaniem, jak już ustaliliśmy, jest dodanie wyświetlania podpowiedzi dla gracza. Aby to zrealizować, musimy odpowiedzieć na dwa pytania:

1. Kiedy wyświetlać podpowiedź?
2. Od czego będzie zależna treść podpowiedzi?

Zacznijmy od pierwszego pytania. Aby cała zabawa miała sens, gracz powinien dostawać podpowiedź po każdej nieudanej próbie. To znaczy, że podpowiedź będziemy wyświetlać **w pętli**.

Nasza podpowiedź będzie uzależniona od liczby podanej przez gracza i ukrytej wartości. Mówiąc precyzyjniej, musimy porównać te dwie liczby ze sobą i wyświetlić odpowiedni komunikat:

* Jeżeli ukryta wartość jest **mniejsza** od podanej przez gracza liczby, wyświetlimy podpowiedź "**Mniejsza!**"
* Jeżeli ukryta wartość jest **większa** od podanej przez gracza liczby, wyświetlimy podpowiedź "**Większa!**"

### Sprawdzamy, czy ukryta jest mniejsza

Zacznijmy od pierwszego komunikatu. Musimy porównać ze sobą wartości zmiennych `ukryta` i `liczba`. Jeżeli `ukryta` jest mniejsza od `liczba`, to wyświetlamy komunikat "Mniejsza!".

Tworzymy więc odpowiednią **instrukcję warunkową** i dopisujemy ją do naszej gry. Pamiętajmy, że tę instrukcję musimy dodać **wewnątrz pętli**, ponieważ podpowiedzi będziemy wyświetlać po każdej nieudanej próbie gracza. Pamiętamy więc o wcięciach i dopisujemy, zaraz na początku naszej pętli:

```python
    if ukryta < liczba:
        print("Mniejsza!")
```

### Sprawdzamy, czy ukryta jest większa

Teraz pozostało nam sprawdzić drugi przypadek, gdy ukryta wartość jest większa od podanej przez gracza liczby. Postępujemy podobnie jak wcześniej i dopisujemy, zaraz pod poprzednią instrukcją:

```python
    if ukryta > liczba:
        print("Większa!")
```

### Zwiększamy zakres

Aby urozmaicić i utrudnić naszą grę **zmieńmy** zakres, z którego losowana jest ukryta wartość:

```python
ukryta = random.randint(1, 100)
```

To wszystko. Pozostało nam uruchomić naszą grę i ją przetestować!

### Pełna gra z komentarzami

```python
# Importujemy bibliotekę, która pozwoli nam generować losowe liczby
import random

# Losujemy liczbę całkowitą z przedziału od 1 do 100
ukryta = random.randint(1, 100)

# Wczytujemy liczbę od użytkownika
liczba = int(input("Podaj liczbę: "))

# Dopóki użytkownik nie odgadł, jaką liczbę wylosował komputer
while liczba != ukryta:
    # Jeżeli wylosowana wartość jest mniejsza od tej podanej przez użytkownika
    if ukryta < liczba:
        # Informujemy użytkownika o tym, że wartość, której szuka, jest mniejsza
        print("Mniejsza!")
        
    # Jeżeli wylosowana wartość jest większa od tej podanej przez użytkownika
    if ukryta > liczba:
        # Informujemy użytkownika o tym, że wartość, której szuka, jest większa
        print("Większa!")

    # Ponownie prosimy użytkownika o podanie liczby
    liczba = int(input("Podaj liczbę: "))

# Skoro wyszliśmy z pętli, to znaczy, że użytkownik odgadł wylosowaną przez komputer liczbę
# Wypisujemy więc stosowny komunikat
print("Trafiona!")
```

### Testujemy działanie

Uruchom grę i spróbuj odgadnąć liczbę.
Czy potrafisz wymyśleć **strategię**, która pozwoli Ci odgadnąć w jak najmniejszej liczbie prób?

Poniżej możesz także przetestować działanie gry.

{% embed url="https://replit.com/@damiankurpiewski/Zgadywanie2" %}

## Zgadywanie ze zliczeniem prób

Nasza modyfikacja "ciepło-zimno" powinna ułatwić zgadywanie. Ile jednak prób zazwyczaj potrzebujemy, żeby odgadnąć? Policzmy to!

### Dodajemy licznik

Na początku dodajemy do programu licznik prób. Nazwijmy tę zmienną `ile_prob`. Na początku przypiszemy jej wartość $$1$$, ponieważ zawsze zaczynamy od pierwszej próby (mniej nie możemy mieć!).

Naszą nową zmienną dopisujemy **na początku** całego programu, np. po wylosowaniu ukrytej wartości.

```python
ile_prob = 1
```

### Zliczanie prób

Kiedy zliczać próby? Powinniśmy zwiększać nasz licznik **po każdej** nieudanej próbie, a więc **wewnątrz pętli**, np. po wyświetleniu podpowiedzi.

```python
    ile_prob += 1
```

### Wyświetlamy liczbę prób

Na końcu naszego programu, gdy już wyświetlimy komunikat o trafieniu, wypiszemy także liczbę prób.

```python
print("Liczba prób:", ile_prob)
```

To wszystko! Testujemy i gramy!

{% hint style="info" %}
Zastanów się, jaką **strategię** należy obrać, by za każdym razem mieć jak najmniej prób.

Spróbuj także zwiększyć zakres, z którego losowana jest ukryta wartość.
{% endhint %}

### Pełna gra z komentarzami

```python
# Importujemy bibliotekę, która pozwoli nam generować losowe liczby
import random

# Losujemy liczbę całkowitą z przedziału od 1 do 100
ukryta = random.randint(1, 100)

# Będziemy zliczać liczbę prób, które potrzebował użytkownik, żeby odgadnąć wartość
# Zaczynamy liczyć od 1
ile_prob = 1

# Wczytujemy liczbę od użytkownika
liczba = int(input("Podaj liczbę: "))

# Dopóki użytkownik nie odgadł, jaką liczbę wylosował komputer
while liczba != ukryta:
    # Jeżeli wylosowana wartość jest mniejsza od tej podanej przez użytkownika
    if ukryta < liczba:
        # Informujemy użytkownika o tym, że wartość, której szuka, jest mniejsza
        print("Mniejsza!")

    # Jeżeli wylosowana wartość jest większa od tej podanej przez użytkownika
    if ukryta > liczba:
        # Informujemy użytkownika o tym, że wartość, której szuka, jest większa
        print("Większa!")

    # Zliczamy kolejną próbę zwiększając wartość licznika ile_prob
    ile_prob += 1
    
    # Ponownie prosimy użytkownika o podanie liczby
    liczba = int(input("Podaj liczbę: "))

# Skoro wyszliśmy z pętli, to znaczy, że użytkownik odgadł wylosowaną przez komputer liczbę
# Wypisujemy więc stosowny komunikat
print("Trafiona!")

# Wypisujemy także liczbę prób podjętych przez użytkownika
print("Liczba prób:", ile_prob)
```

### Testujemy działanie

Uruchom grę kilkukrotnie.
Jaka była najmniejsza liczba prób potrzebna do odgadnięcia liczby?
A jaka była największa?

Poniżej także możesz przetestować działanie gry.

{% embed url="https://replit.com/@damiankurpiewski/Zgadywanie3" %}

## Zgadywanie z własnego zakresu

Dodajmy ostatnią modyfikację do naszej gry, a mianowicie zakres podawany przez gracza.

### Wczytujemy zakres

Na samym początku (zaraz po zaimportowaniu biblioteki random) prosimy użytkownika o podanie zakresu, z którego ma zostać wylosowana ukryta wartość.

```python
print("Podaj zakres")

od = int(input("Od: "))

do = int(input("Do: "))
```

### Stosujemy zakres

Gdy już wczytaliśmy od gracza zakres, należy go wykorzystać przy losowaniu wartości. W tym celu modyfikujemy instrukcję losowania ukrytej wartości, podając nowy zakres.

```python
ukryta = random.randint(od, do)
```

### Testujemy

Uruchamiamy grę i sprawdzamy, czy działa poprawnie. Czy dla każdego zakresu nasza gra działa prawidłowo?

### Sprawdzamy poprawność zakresu

Ponieważ nie mamy wpływu na to, co poda użytkownik, należy zweryfikować to, co wpisał. Sprawdzamy więc, czy zakres podany przez gracza jest poprawny. Jak sprawdzić poprawność zakresu? To proste. Jego początek musi być mniejszy od końca. Jeśli tak nie jest, to zakres nie jest poprawny.

Zaraz po wczytaniu zakresu dodajemy sprawdzenie jego poprawności. Jeżeli nie jest poprawny, to wyświetlamy stosowny komunikat i kończymy działanie gry za pomocą polecenia `exit()`.

```python
if od > do:
    print("Błędny zakres!")
    exit()
```

### Testujemy po raz drugi

Ponownie uruchamiamy grę i sprawdzamy jej działanie. Czy teraz wszystko działa poprawnie?

{% hint style="warning" %}
**Uwaga**

Dla ułatwienia zakładamy, że gracz podaje do programu prawidłowe liczby **całkowite**. Nie zajmujemy się przypadkami, gdy gracz poda liczbę ułamkową, albo zamiast liczby wpisze jakiś tekst.
{% endhint %}

### Pełna gra z komentarzami

```python
# Importujemy bibliotekę, która pozwoli nam generować losowe liczby
import random

# Prosimy użytkownika o podanie zakresu, z którego ma być wylosowana liczba
print("Podaj zakres")

# Wczytujemy początek zakresu i zamieniamy na liczbę całkowitą
od = int(input("Od: "))

# Wczytujemy koniec zakresu i zamieniamy na liczbę całkowitą
do = int(input("Do: "))

# Jeżeli początek zakresu jest większy od jego końca
if od > do:
    # To znaczy, że zakres jest błędny, informujemy więc o tym użytkownika
    print("Błędny zakres!")
    # A następnie kończymy działanie programu
    exit()

# Losujemy liczbę całkowitą z przedziału podanego przez użytkownika
ukryta = random.randint(od, do)

# Będziemy zliczać liczbę prób, które potrzebował użytkownik, żeby odgadnąć wartość
# Zaczynamy liczyć od 1
ile_prob = 1

# Wczytujemy liczbę od użytkownika
liczba = int(input("Podaj liczbę: "))

# Dopóki użytkownik nie odgadł, jaką liczbę wylosował komputer
while liczba != ukryta:
    # Jeżeli wylosowana wartość jest mniejsza od tej podanej przez użytkownika
    if ukryta < liczba:
        # Informujemy użytkownika o tym, że wartość, której szuka, jest mniejsza
        print("Mniejsza!")

    # Jeżeli wylosowana wartość jest większa od tej podanej przez użytkownika
    if ukryta > liczba:
        # Informujemy użytkownika o tym, że wartość, której szuka, jest większa
        print("Większa!")

    # Zliczamy kolejną próbę zwiększając wartość licznika ile_prob
    ile_prob += 1

    # Ponownie prosimy użytkownika o podanie liczby
    liczba = int(input("Podaj liczbę: "))

# Skoro wyszliśmy z pętli, to znaczy, że użytkownik odgadł wylosowaną przez komputer liczbę
# Wypisujemy więc stosowny komunikat
print("Trafiona!")

# Wypisujemy także liczbę prób podjętych przez użytkownika
print("Liczba prób:", ile_prob)
```

### Testujemy działanie

Uruchom swoją skończoną grę.
Spróbuj zgadywać dla różnych przedziałów.
Jaki jest największy przedział, w którym uda Ci się odgadnąć liczbę?

Poniżej także możesz przetestować działanie gry.

{% embed url="https://replit.com/@damiankurpiewski/Zgadywanie4" %}