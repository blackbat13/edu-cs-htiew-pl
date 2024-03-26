---
description: '"This game is silly!"'
---

# Prosta (naiwna) gra

## Wstęp

Na początku pisałem, że tworzenie aplikacji konsolowym jest nudne. Od czegoś jednak trzeba zacząć! Zanim wskoczymy do świata gier dwuwymiarowych, stworzymy naszą pierwszą grę "tekstową". Nauczymy się w ten sposób zupełnych podstaw programowania, takich jak interakcja z użytkownikiem (graczem), tworzenie zmiennych, modyfikowanie ich i wypisywanie komunikatów na ekranie.

### Czego się nauczysz

* Tworzenia zmiennych i prostych operacji na nich.
* Komunikacji z użytkownikiem.

## Gra

Jak wskazuje tytuł, nasza gra będzie prosta, a nawet można powiedzieć, że naiwna! Będzie to gra dla dwóch graczy: człowiek kontra komputer. Przebieg gry jest prosty: najpierw pierwszy gracz podaje swoją liczbę, a następnie drugi podaje swoją. Celem jest podanie liczby większej od przeciwnika. Wygrywa ten, kto poda większą wartość!

#### Przykład

* **Gracz**: 14
* **Komputer**: 15, wygrałem!

Prosta gra, prawda? Jest jednak pewien problem. Jeżeli zaczynamy jako pierwsi, to nie mamy szansy wygrać! Wystarczy, że przeciwnik poda wartość o jeden większą od naszej i w ten sposób wygrywa. Dlatego na wstępie wspomniałem, że ta gra jest nie tylko prosta, ale wręcz naiwna!

Jest to jednak idealna gra na początek. Przejdźmy więc do działania!

### Tworzymy nowy projekt

[https://youtu.be/WxS5iz4bNxM](https://youtu.be/WxS5iz4bNxM)

!!! info
	 W naszym projekcie będziemy mogli stworzyć wiele różnych aplikacji i gier. Czasem jednak wygodniej będzie utworzyć nowy projekt do kolejnej gry, aby zachować lepszy porządek. Wszystko zależy od Ciebie!

### Tworzymy nowy plik

Klikamy prawym przyciskiem myszy na główny katalog naszej gry, następnie wybieramy **New->Python file**. Nazwijmy nasz plik _naiwna\_gra_. Utworzony przez Ciebie plik powinien mieć **rozszerzenie .py**. Oznacza to, że cała nazwa pliku będzie wyglądała następująco: _naiwna\_gra.py_.

!!! info
	 Rozszerzenie **.py** to format skryptów zapisanych w języku Python.

### Wczytujemy liczbę od gracza

Zaczynamy od wczytania liczby od użytkownika. W tym celu skorzystamy z polecenia `input`. Jako **parametr** tego polecenia, który zapisujemy w nawiasach okrągłych, podajemy komunikat, który ma zostać wyświetlony na ekranie. W Pythonie komunikaty i teksty podajemy w cudzysłowie:

```python
input("Podaj liczbę: ")
```

Nie wystarczy jednak tylko wywołać odpowiednie polecenie. Musimy jeszcze gdzieś **zapisać** jego wynik, a konkretnie w nowej **zmiennej**, którą nazwiemy `liczba_tekst`:

```python
liczba_tekst = input("Podaj liczbę: ")
```

!!! info
	**Zmienne** możemy traktować jak "pudełka na dane". Możemy w nich przechowywać różne wartości, jednak każde pudełko może przechowywać tylko jedną wartość naraz i tylko jednego **typu**.
	
	W języku Python zmienne nazywamy zwyczajowo z małych liter alfabetu angielskiego, a kolejne wyrazy w nazwie zmiennej oddzielamy znakiem podłogi (`_`).

!!! warning
	 W nazwach zmiennych nie możemy używać spacji ani innych białych znaków, takich jak tabulacje. Powinniśmy także unikać polskich znaków czy liter innych niż litery alfabetu angielskiego. Ponadto nazwa zmiennej nie może zaczynać się od cyfry i nie powinna zawierać większości znaków specjalnych takich jak dolar (`$`) czy ampersant (`&`).

Gdy używamy polecenia `input`, to wartość wpisana przez użytkownika będzie zawsze wczytana jako **tekst**. My jednak potrzebujemy liczbę. W tym celu skorzystamy z kolejnego polecenia: `int` (ang. **integer** czyli liczba całkowita). Posłuży nam ono do zamiany tekstu na liczbę całkowitą. Jako parametr tego polecenia podajemy tekst do zamiany na liczbę, w naszym przypadku ten tekst zapisany jest w zmiennej `liczba_tekst`:

```python
int(liczba_tekst)
```

!!! info
	 W celu zamiany wprowadzonego tekstu na liczbę rzeczywistą skorzystalibyśmy z polecenia `float`.

Oczywiście wynik polecenia musimy gdzieś zapisać. Zapamiętamy go w nowej zmiennej o nazwie `liczba`:

```python
liczba = int(liczba_tekst)
```

Jak dotąd mamy w naszym programie dwa polecenia: wczytanie wartości od użytkownika i zamianę jej na liczbę.

```python
liczba_tekst = input("Podaj liczbę: ")
liczba = int(liczba_tekst)
```

Już teraz warto uruchomić program i sprawdzić, czy wszystko działa.

W celu uruchomienia naszej gry klikamy **prawym przyciskiem myszy** gdzieś w edytorze i wybieramy zieloną strzałkę z napisem **Run 'naiwna\_gra'**.

!!! warning
	 Pamiętaj, żeby testować swoje gry i programy jak najczęściej! Pozwoli to na bieżąco rozwiązywać wszelkie błędy i uniknąć późniejszej frustracji.

!!! info
	 Pycharm na bieżąco zapisuje zmiany w plikach, więc nie musisz się martwić, że utracisz swoje dane.

### Tworzymy nową, większą liczbę

Przejdźmy teraz do roli komputera. Jego zadaniem jest wypisanie liczby o jeden większej od tej, którą podał użytkownik. W tym celu utworzymy nową liczbę, o jeden większą od tej wczytanej od użytkownika. Tworzymy nową zmienną `nowa_liczba` i przypisujemy do niej wynik dodania liczby $1$ do wartości wczytanej od użytkownika zapisanej w zmiennej `liczba`:

```python
nowa_liczba = liczba + 1
```

### Wypisujemy nową liczbę

Teraz pozostało nam wypisać nowo utworzoną liczbę, a następnie komunikat o wygranej. W tym celu skorzystamy z polecenia `print`, które jako parametr przyjmuje zmienną, lub komunikat do wypisania. Zaczniemy od wypisania naszej nowej liczby:

```python
print(nowa_liczba)
```

Nie oczekujemy, że polecenie `print` zwróci nam jakąś wartość, jego zadaniem jest tylko wypisanie komunikatu na ekranie.

### Wypisujemy komunikat o wygranej

Na koniec wypiszemy jeszcze komunikat _Wygrałem_. Pamiętamy, że komunikaty i teksty podajemy w cudzysłowie.

```python
print("Wygrałem!")
```

Składamy wszystko w całość i mamy gotową grę!

### Gotowa gra z komentarzami

```python
# Wczytujemy od użytkownika wartość w formie tekstu
liczba_tekst = input("Podaj liczbę: ")

# Zamieniamy wczytaną wcześniej wartość na liczbę całkowitą
liczba = int(liczba_tekst)

# Tworzymy nową liczbę większą o 1 od tej, którą podał użytkownik
nowa_liczba = liczba + 1

# Wypisujemy nową liczbę w konsoli
print(nowa_liczba)

# A następnie wypisujemy informację o wygranej komputera
print("Wygrałem!")
```

!!! info
	#### Komentarze
	
	Komentarze to fragmenty naszego kodu, które **nie wpływają** na działanie programu. Można je traktować jak notatki na marginesie. W tym kursie będziemy używać komentarzy, aby wytłumaczyć działanie wybranych fragmentów kodu. Często używa się komentarzy także do tego, aby zakomentować wybrane instrukcje, których nie chcemy usuwać, ale nie chcemy też, by były aktywne.
	
	W języku Python komentarze zaczynamy od znaku hash (`#`). Wszystko po tym znaku w danej linijce traktowane jest jako komentarz.

### Uruchamiamy grę

Teraz czas, aby uruchomić swoją pierwszą grę! Spróbuj uruchomić ją kilka razy i podać różne wartości. Czy komputer zawsze wygra?

Możesz także przetestować naszą grę w poniższym okienku. Kliknij zielony przycisk z napisem **Run**, aby ją uruchomić.

[https://replit.com/@damiankurpiewski/NaiwnaGra](https://replit.com/@damiankurpiewski/NaiwnaGra)

!!! info
	#### Błędy
	
	Podczas tworzenia kolejnych gier i programów popełnianie błędów stanie się chlebem powszednim. Nie należy się nimi przejmować, wręcz przeciwnie! Niektóre błędy mogą wręcz przynieść nieoczekiwane i zaskakujące rezultaty. Oczywiście czasami zdarzy nam się także popełnić błąd, który uniemożliwi uruchomienie naszego programu. W takim przypadku, przy próbie uruchomienia, w konsoli pojawią się stosowne komunikaty zaznaczone czerwonym kolorem. Warto się przyjrzeć tym komunikatom! Często będą wskazywać linijkę, w której wystąpił błąd, a także opiszą przyczynę samego błędu. Na początku w większości błędy będą ograniczać się do braku jakiegoś znaku, np. nawiasu końcowego, albo literówki w nazwie zmiennej czy polecenia.
