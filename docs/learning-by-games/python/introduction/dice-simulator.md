# Symulacja rzutu kością

## Wstęp

Losowość w grach jest bardzo ważna, to dzięki niej różne mechaniki gry i jej postaci mogą zachowywać się w nieprzewidywalny sposób. Dlatego, zanim przejdziemy dalej, potrzebujemy zrozumieć, jak możemy skorzystać z losowości w Pythonie. 

Jako przykład losowości często podaje się rzut kością: aby wylosować liczbę od $$1$$ do $$6$$, rzuć kością. To właśnie zrobimy. Napiszemy symulator rzutu kością, a dokładniej program, który będzie losował liczbę od $$1$$ do $$6$$ i wypisywał ją na ekranie.

### Czego się nauczysz

* Losowania liczby z zadanego przedziału.
* Wykorzystania pętli iteracyjnej do powtarzania operacji.
* Zliczania liczby "udanych" rzutów.

## Pojedynczy rzut

Zaczniemy od pojedynczego rzutu kością. Zamysł jest prosty: program losuje liczbę od $$1$$ do $$6$$, a następnie wypisuje ją na ekranie z odpowiednim komunikatem.

{% hint style="info" %}
Nową grę możesz utworzyć w nowym projekcie, albo możesz dodać nowy plik do swojego poprzedniego projektu.
{% endhint %}

### Losujemy liczbę

Na początku, żeby móc skorzystać z losowości w Pythonie, musimy zaimportować odpowiednią **bibliotekę**. Na bibliotekę w programowaniu można patrzeć jak na zbiór narzędzi. W Pythonie część z takich narzędzi dostępna jest _od ręki_, jak np. polecenie `input` do wczytania wejścia od użytkownika. Wiele jednak takich poleceń znajduje się właśnie w osobnych bibliotekach.

Do liczb losowych potrzebna będzie nam biblioteka `random`, którą importujemy poleceniem:

```python
import random
```

Teraz możemy już skorzystać z polecenia losującego liczbę z zadanego przedziału. Polecenie nazywa się `randint` (losowa liczba całkowita), żeby jednak z niego skorzystać, należy je poprzedzić nazwą biblioteki i kropką, tzn. `random.randint`.

{% hint style="info" %}
Sposób korzystania z bibliotek i zawartych w nich poleceń/funkcji zależy od tego, jak bibliotekę zaimportujemy.
{% endhint %}

Polecenie randint przyjmuje dwa parametry: początek i koniec przedziału, z jakiego chcemy wylosować liczbę. Innymi słowy musimy podać zakres **od do**. W naszym przypadku będzie to odpowiednio $$1$$ i $$6$$.

```python
random.randint(1, 6)
```

Nie wystarczy jednak tylko wywołać polecenie losujące liczbę z zadanego przedziału, trzeba jeszcze gdzieś zapisać wynik tego polecenia, tzn. **wylosowaną liczbę**. Zapiszemy ją w zmiennej `wynik`:

```python
wynik = random.randint(1, 6)
```

### Wypisujemy wynik

Teraz pozostało nam wypisać `wynik`, korzystając z polecenia `print`:

```python
print("Kości zostały rzucone. Wynik to:", wynik)
```

### Pełen program z komentarzami

```python
# Importujemy bibliotekę, która pozwoli nam generować losowe liczby
import random

# Symulujemy rzut kością losując liczbę całkowitą z przedziału od 1 do 6
wynik = random.randint(1, 6)

# Wypisujemy wylosowaną wartość na ekranie
print("Kości zostały rzucone. Wynik to:", wynik)
```

### Testujemy działanie

Czas przetestować nasz program.
Warto uruchomić go kilkukrotnie.
Czy za każdym razem uzyskamy inny wynik?
A może wyniki będą się powtarzać?

Wybierz jakąś liczbę od $$1$$ do $$6$$. Za którym uruchomieniem program ją wylosował?

Spróbuj także zmienić zakres losowanych wartości i sprawdzić, jak to wpłynie na działanie programu.

Poniżej także możesz sprawdzić, jakie liczby zostaną wylosowane.

{% embed url="https://replit.com/@damiankurpiewski/Kosci1" %}

## Wielokrotny rzut

Wiemy już jak symulować pojedynczy rzut kością. Czasem jednak potrzebujemy rzucić kilkoma kośćmi naraz, np. dwiema. Możemy oczywiście wielokrotnie uruchomić powyższy program, ale nie jest to zbyt wygodne. Zmodyfikujmy go więc tak, byśmy mogli podać, ile rzutów kością ma zostać wykonanych.

### Wczytujemy dane

Do powtórzenia rzutu kością skorzystamy z **pętli iteracyjnej**. Zanim jednak do tego przejdziemy, musimy się dowiedzieć od użytkownika, ile rzutów kością mamy wykonać:

```python
input("Podaj liczbę rzutów kością:")
```

Oczekujemy od użytkownika liczby naturalnej, więc musimy skorzystać z polecenia `int`, aby zamienić wczytaną wartość na liczbę. Możemy to zrobić w jednej linii, bez korzystania z pomocniczej zmiennej, tak jak to robiliśmy wcześniej:

```python
int(input("Podaj liczbę rzutów kością: "))
```

Wynik polecenia zapiszemy w zmiennej `ile_razy`:

```python
ile_razy = int(input("Podaj liczbę rzutów kością: "))
```

### Powtarzamy rzuty kością

Teraz już wiemy, ile rzutów kością mamy wykonać. Wiemy też, z poprzedniego ćwiczenia, jak wykonać pojedynczy rzut kością. W celu powtórzenia tej operacji zadaną liczbę razy, skorzystamy z **pętli iteracyjnej** `for`:

```python
for i in range(ile_razy):
```

Teraz w pętli wykonujemy rzut kością z poprzedniego ćwiczenia:

```python
for i in range(ile_razy):
    wynik = random.randint(1, 6)
```

Aby było wiadomo, że ta operacja ma zostać wykonana **wewnątrz pętli** (czyli ma zostać powtórzona zadaną liczbę razy), to zapisujemy ją z pojedynczym **wcięciem** (tabulacją).

{% hint style="warning" %}
Wcięcia są bardzo ważne w języku Python, więc zwracaj na nie uwagę!
Często sprawdzaj, czy kolejne linijki są poprawnie wyrównane i nie ma jakiejś dodatkowej, niechcianej spacji.

Jeżeli gdzieś zastosujemy nieprawidłowe wcięcia, to przy próbie uruchomienia naszego programu Python wyświetli nam w konsoli napis "**IndentationError**".
{% endhint %}

Nie wystarczy jednak samo wylosowanie liczby, przydałoby się ją także wypisać na ekranie. To także musimy wykonać **wewnątrz pętli**, dlatego pamiętamy o **wcięciu**.

```python
for i in range(ile_razy):
    wynik = random.randint(1, 6)
    print("Kości zostały rzucone. Wynik to:", wynik)
```

Na koniec łączymy wszystko w całość, pamiętając o zaimportowaniu biblioteki `random` do liczb losowych.

### Pełen program z komentarzami

```python
# Importujemy bibliotekę, która pozwoli nam generować losowe liczby
import random

# Wczytujemy od użytkownika liczbę rzutów kością, które mamy zasymulować
ile_razy = int(input("Podaj liczbę rzutów kością: "))

# W pętli od 0 do liczby rzutów minus 1
for i in range(ile_razy):
    # Symulujemy rzut kością losując liczbę całkowitą z przedziału od 1 do 6
    wynik = random.randint(1, 6)

    # Wypisujemy wylosowaną wartość na ekranie
    print("Kości zostały rzucone. Wynik to:", wynik)
```

### Testujemy działanie

Uruchamiamy swój program i sprawdzamy, jakie wyniki tym razem dostaniemy.

Możesz także sprawdzić działanie programu poniżej.

{% embed url="https://replit.com/@damiankurpiewski/Kosci2" %}

## Wielokrotny rzut ze zliczaniem

Wiemy już, jak symulować zarówno pojedynczy jak i wielokrotny rzut kością. Powiedzmy jednak, że chcemy sprawdzić swoje szczęście: interesuje nas, ile razy uda nam się wylosować szóstkę. W tym celu będziemy tak jak wcześniej wielokrotnie rzucać kością, a po drodze będziemy także zliczać, ile razy wypadła nam szóstka.

### Dodajemy zliczanie szóstek

Zmodyfikujemy program z poprzedniego ćwiczenia. W celu zliczania, ile razy udało nam się wyrzucić szóstkę, będziemy potrzebowali nowej zmiennej, którą nazwiemy `szostki` (do nazw zmiennych nie używamy polskich znaków). Powinniśmy ją utworzyć **przed pętlą**, zanim przystąpimy do zliczania. Musimy jej oczywiście nadać jakąś wartość początkową. Tak jak to bywa w zliczaniu rzeczy, zaczynamy liczyć od zera:

```python
szostki = 0
```

{% hint style="info" %}
Być może pomyślisz sobie: "_Przecież liczenie zaczynamy zawsze od jedynki!_". Masz tutaj po części rację. Gdy liczymy jakieś przedmioty to rzeczywiście zaczynami liczyć od jedynki. Ale to dlatego, że na samym początku już zliczamy **pierwszy przedmiot**!

W naszym przypadku (i w przypadku większości programów) liczenie zaczynamy jeszcze **przed rzutami kością**, czyli przed policzeniem chociażby jednej szóstki. W takim razie w tym momencie nie wyrzuciliśmy jeszcze żadnej szóstki, co znaczy, że wyrzuciliśmy ich dokładnie zero!
{% endhint %}

Teraz zastanówmy się, jak i w którym miejscu w naszym kodzie powinniśmy zliczać wylosowane szóstki. Oczywiście musimy to robić po każdym rzucie. Za każdą wylosowaną szóstkę będziemy zwiększać nasz licznik `szostki` o $$1$$. Jak jednak sprawdzić, czy wylosowaliśmy właśnie szóstkę? Do tego będzie nam potrzebna **instrukcja warunkowa**. 

{% hint style="info" %}
**Instrukcja warunkowa** pozwala nam wykonać dany fragment kodu tylko wtedy, gdy jest spełniony zadany warunek. Można to pokazać na przykładzie świateł drogowych: **jeżeli** _światło jest zielone_, **to** idź.
{% endhint %}

Najpierw, korzystając z instrukcji warunkowej sprawdzamy, czy udało nam się wylosować szóstkę. W tym celu przyrównujemy `wynik` do liczby $$6$$ :

```python
    if wynik == 6:
```

Jeżeli faktycznie udało nam się wylosować szóstkę, to powinniśmy zwiększyć nasz licznik szóstek, czyli zmienną `szostki`:

```python
    if wynik == 6:
        szostki += 1
```

Podobnie jak w przypadku pętli, instrukcje wewnątrz **instrukcji warunkowej** muszą mieć dodatkowe wcięcie. Pamiętajmy, że tę operację musimy wykonać **po każdym rzucie kością**, tzn. **wewnątrz pętli**. Pamiętajmy więc o **wcięciu**. 

{% hint style="warning" %}
**Uwaga**

Zauważ, że instrukcja `szostki += 1` ma **podwójne** wcięcie, ponieważ znajduje się wewnątrz pętli i wewnątrz instrukcji warunkowej.
{% endhint %}

### Wypisujemy liczbę wylosowanych szóstek

Na koniec, po wszystkich rzutach,  czyli już **po wyjściu z pętli** (a więc bez wcięcia), wypisujemy liczbę wylosowanych szóstek:

```python
print("Szóstka wypadła", szostki, "razy")
```

### Pełen program z komentarzami

```python
# Importujemy bibliotekę, która pozwoli nam generować losowe liczby
import random

# Wczytujemy od użytkownika liczbę rzutów kością, które mamy zasymulować
ile_razy = int(input("Podaj liczbę rzutów kością: "))

# Będziemy zliczać, ile razy wypadła wartość 6
# Zliczanie zaczynamy od zera
szostki = 0

# W pętli od 0 do liczby rzutów minus 1
for i in range(ile_razy):
    # Symulujemy rzut kością losując liczbę całkowitą z przedziału od 1 do 6
    wynik = random.randint(1, 6)

    # Wypisujemy wylosowaną wartość na ekranie
    print("Kości zostały rzucone. Wynik to:", wynik)

    # Jeżeli wylosowaliśmy wartość 6
    if wynik == 6:
        # To zwiększamy licznik wylosowanych szóstek
        szostki += 1

# Wypisujemy, ile razy wypadła szóstka
print("Szóstka wypadła", szostki, "razy")
```

### Testujemy działanie

Czas uruchomić finalną wersję naszego symulatora rzutu kością!
Ile szóstek Tobie uda się wylosować?

Poniżej możesz także przetestować działanie programu.

{% embed url="https://replit.com/@damiankurpiewski/Kosci3" %}

{% hint style="info" %}
Spróbuj uruchomić program kilka razy, aby zobaczyć, ile szóstek uda Ci się wylosować!
{% endhint %}

## Zadania dodatkowe

1. Spróbuj zmodyfikować program ze zliczaniem tak, aby zliczał nie wystąpienia szóstki, a zadanej przez użytkownika wartości.
2. Spróbuj zmodyfikować powyższe programy tak, aby umożliwić rzut kością o dowolnej, wybranej przez użytkownika, liczbie ścian.