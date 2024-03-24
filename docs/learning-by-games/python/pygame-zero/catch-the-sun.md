# Złap słońce

## Wstęp

Każdy potrzebuje witaminy D, złapmy więc trochę słońca! Nie jest to jednak tak proste, jakby się mogło wydawać! Słońce nagle znika i pojawia się w losowych miejscach. Za każde celne kliknięcie w słońce dostajemy punkt, a za każde pudło tracimy punkt! Im więcej mamy punktów, tym słońce szybciej się porusza! Ile punktów uda Ci się zdobyć?

### Czego się nauczysz

* Jak dodać i narysować postać w grze: aktora.
* Jak zmieniać pozycję aktora na ekranie.
* Jak odczytywać kliknięcia myszy i wykrywać ich kolizję z aktorem.
* Jak wyświetlać i zliczać punkty.

### Materiały do pobrania

#### Grafiki

Pobieramy poniższą grafikę: klikamy prawym przyciskiem myszy i wybieramy *Zapisz obraz jako*. Zapisujemy obraz w wybranym przez siebie miejscu i nazywamy **sun.png**.
Grafikę umieszczamy w katalogu **images** w naszym projekcie. W celu utworzenia katalogu klikamy prawym przyciskiem myszy na główny katalog projektu, a następnie wybieramy *New -> Directory*. Teraz wystarczy przeciągnąć nasze słońce do katalogu images i zatwierdzić zmiany klikając niebieski przycisk z napisem *Refactor*.

![Źródło: [kenney.nl](https://www.kenney.nl/)](../../../.gitbook/assets/sun.png)

{% hint style="warning" %}
Wszystkie grafiki, z których będziemy korzystać w naszej grze, powinny znaleźć się w katalogu *images*, inaczej biblioteka nie znajdzie tych grafik. 
Ponadto nazwy grafik nie mogą zawierać wielkich liter.
{% endhint %}

## Podstawowy szablon

Zaczynamy od utworzenia podstawowego szablonu naszej gry.
Jeśli jeszcze tego nie zrobiliśmy, jest to także dobry moment na utworzenie nowego **projektu**. 
Możemy go nazwać np. *ZlapSlonce* (bez polskich znaków). 
Instalujemy także bibliotekę *pgzero* i tworzymy plik *main.py* (jeżeli nie został utworzony automatycznie).
Pobieramy także pokazaną wyżej grafikę słońca i umieszczamy ją w katalogu *images* wewnątrz naszego projektu.
### Importujemy biblioteki

Zastanówmy się, jakich "narzędzi" będziemy potrzebować. Podstawowym elementem będzie oczywiście nasza biblioteka do tworzenia gier. Docelowo nasze słońce będzie się pojawiało w **losowych** miejscach na ekranie, przyda nam się także biblioteka do liczb losowych. 

Dodajemy więc odpowiednie polecenia na samym początku pliku **main.py** w edytorze:

```python
import pgzrun
import random
```

### Określamy wymiary okna gry

Nasza gra nie musi mieć dużego okna. Co więcej, im mniejsze będzie okno gry, tym gra będzie łatwiejsza! Dlaczego? Słońce będzie miało mniej miejsca do ucieczki, łatwiej więc będzie je złapać. Zacznijmy więc od niewielkiego, dość standardowego wymiaru $$800\times600$$. W każdej chwili możemy te wymiary zmienić.

```python
WIDTH = 800
HEIGHT = 600
```

### Tworzymy tło

Nasza gra, jak i każda inna, powinna mieć jakieś tło. To będzie prosta gra, więc i niech tło będzie proste: wypełnimy je wybranym przez siebie kolorem. Wypełnienie kolorem umieścimy w części rysującej, tzn. w części `draw`. Ponieważ słońce zazwyczaj możemy zaobserwować na niebieskim niebie, takiego też koloru użyjemy. W celu wypełnienia tła wybranym kolorem skorzystamy z metody `screen.fill`, do której jako **argument** przekażemy wybrany kolor za pomocą jego angielskiej nazwy *skyblue*, podanej w formie tekstu:

```python
screen.fill("skyblue")
```

Listę dostępnych (nazwanych) kolorów można znaleźć tutaj: [https://pygame-zero.readthedocs.io/en/latest/colors_ref.html](https://pygame-zero.readthedocs.io/en/latest/colors_ref.html).
Zachęcam do sprawdzenia innych kolorów i wybrania takiego, który Tobie odpowiada. Pamiętaj: to Twoja gra!

Pełna implementacja funkcji rysującej wygląda więc następująco:

```python
def draw():
    screen.fill("skyblue")
```

### Pozostałe elementy szablonu

Na koniec pozostało nam uzupełnić nasz program o pozostałe wymagane elementy szablonu, czyli funkcję aktualizującą i polecenie uruchamiające grę.

```python
def update():
    pass


pgzrun.go()
```

### Pełny program z komentarzami

Nasza pełna gra powinna wyglądać teraz podobnie, jak pokazano poniżej.
Komentarze oczywiście są opcjonalne, ale pozwalają lepiej zrozumieć, co się dzieje w danym miejscu w kodzie.

```python
# Importujemy bibliotekę Pygame Zero do tworzenia gier
import pgzrun
# Imporujemy bibliotekę do liczb losowych
import random

# Określamy szerokość i wysokość okna gry
WIDTH = 800
HEIGHT = 600


# Funkcja rysująca stan gry na ekranie
def draw():
    # Wypełniamy tło wybranym kolorem
    screen.fill("skyblue")


# Funkcja aktualizująca stan gry
def update():
    pass


# Uruchamiamy grę
pgzrun.go()
```

### Testujemy działanie

W tym momencie warto już uruchomić naszą "grę" i sprawdzić, czy wszystko działa. Na razie powinniśmy zobaczyć jedynie okno gry wypełnione jasnoniebieskim kolorem, ale od czegoś trzeba zacząć! 

## Rysowanie słońca

Teraz zajmiemy się dodaniem do gry naszej głównej postaci: słońca. Postacie w *Pygame Zero* reprezentować będziemy jako **aktorów**. Każdy aktor ma swoje właściwości, takie jak grafika czy położenie na ekranie. Aktorzy mogą też wchodzić w interakcję z innymi postaciami (także aktorami) i pozostałymi elementami gry.

### Tworzymy nowego aktora gry

Zaczniemy od utworzenia naszego nowego aktora: słońca. W tym celu potrzebna nam będzie nowa zmienna, w której zapamiętamy informacje o aktorze. Zmienną nazwiemy *sun*, czyli słońce po angielsku. Naszego aktora utworzymy zaraz na początku naszego programu, zaraz pod zdefiniowaniem rozmiarów okna gry, a przed częścią rysującą *draw*. W celu utworzenia nowego aktora skorzystamy z polecenia `Actor`, a jako argument podamy nazwę grafiki reprezentującej nasze słońce. Pamiętaj, że grafika musi się znajdować w katalogu **images**.

```python
sun = Actor("sun")
```

{% hint style="info" %}
W nazwie grafiki możemy, ale nie musimy podawać rozszerzenia, tzn. moglibyśmy równie dobrze napisać:

```
sun = Actor("sun.png")
```
{% endhint %}

### Rysujemy słońce na ekranie

Gdy już utworzyliśmy naszego aktora, czas go narysować na ekranie. W tym celu dodajemy instrukcję `sun.draw()` na **końcu** części rysującej (`draw`).

```python
def draw():
    screen.fill("skyblue")
    sun.draw()
```

{% hint style="info" %}
Kolejność, w jakiej rysujemy kolejne elementy na ekranie, ma znaczenie. Możemy je sobie wyobrazić jak kolejne obrazki, które kładziemy jeden na drugim. Gdybyśmy najpierw narysowali słońce, a dopiero potem tło, to niebieski kolor przykryłby naszego aktora.
{% endhint %}

### Pełny program

Kod naszej gry prezentuje się dotąd tak, jak pokazano poniżej.

```python
import pgzrun
import random


WIDTH = 800
HEIGHT = 600

# Tworzymy aktora słońca
sun = Actor("sun")


def draw():
    screen.fill("skyblue")
    # Rysujemy słońce
    sun.draw()


def update():
    pass


pgzrun.go()
```

### Testujemy działanie

Uruchamiamy i testujemy! Naszym oczom powinno ukazać się słońce, umieszczone w lewym górnym rogu okna gry.

## Uciekające słońce

W tym momencie nasze słońce jest dość statyczne. Chcemy jednak, by zaznało trochę ruchu i "skakało" po ekranie w losowych miejscach.

### Przemieszczamy słońce w losowe miejsce

Zacznijmy od przemieszczenia słońca w losowe miejsce. Będziemy teraz pracować w części **aktualizującej** (`update`), ponieważ nasze słońce powinno się przemieszczać przez cały czas trwania gry. Aby przemieścić słońce w inne miejsce na ekranie, powinniśmy zmienić jego **współrzędne**, tzn. parametry `sun.x` oraz `sun.y`. Przypiszemy im losowe wartości korzystając z metody `random.randint`, do której jako parametry przekażemy przedział, z którego chcemy wylosować wartość. Musimy pamiętać, że współrzędna $$x$$ powinna się mieścić w szerokości (**WIDTH**) ekranu, a współrzędna $$y$$ powinna się mieścić w wysokości (**HEIGHT**) ekranu. Dodatkowo warto dodać niewielki **margines**, powiedzmy $$80$$ pikseli, tak aby nasze słońce nie wychodziło poza brzegi okna gry.

W części aktualizującej (`update`) usuwamy więc instrukcję `pass` i dopisujemy losowanie nowych współrzędnych naszego słońca (pamiętając o wcięciach).

```python
def update():
    sun.x = random.randint(80, WIDTH - 80)
    sun.y = random.randint(80, HEIGHT - 80)
```

{% hint style="info" %}
Domyślnie współrzędne $$x, y$$ aktora oznaczają położenie jego lewego górnego rogu na ekranie.
{% endhint %}

Gdy teraz uruchomimy naszą grę zobaczymy, że słońce faktycznie skacze po ekranie w losowych miejscach. Jest jednak zbyt szybkie, byśmy dali radę je złapać. Musimy je spowolnić.

### Odliczamy czas

Aby spowolnić nasze słońce dodamy do niego swego rodzaju **timer**. Jego zadaniem będzie odliczanie w dół, aż do zera. Gdy timer dojdzie do zera, to dopiero wtedy przemieścimy nasze słońce w inne, losowe miejsce i ponownie ustawimy timer. Na początku dopisujemy timer do naszego słońca, zaraz pod linijką w której tworzymy aktora. Zaczniemy od wartości zero, tak aby już na samym początku słońce przemieściło się w losowe miejsce.

```python
sun = Actor("sun")
sun.timer = 0
```

Teraz, w części aktualizującej, powinniśmy zmniejszać nasz timer o jeden w każdej **klatce** gry. Następnie sprawdzimy, czy timer osiągnął wartość mniejszą lub równą zero, a jeżeli tak, to ustawimy słońce w losowym miejscu (tak jak poprzednio) i ustawimy timer na jakąś ustaloną z góry wartość, np $$60$$. Zakładając, że nasza gra będzie działać w sześćdziesięciu klatkach na sekundę, to wartość $$60$$ będzie odpowiadać jednej sekundzie.

```python
def update():
    sun.timer -= 1

    if sun.timer <= 0:
        sun.x = random.randint(80, WIDTH - 80)
        sun.y = random.randint(80, HEIGHT - 80)
        sun.timer = 60
```

### Pełny kod

Dotychczasowy kod naszej gry zaprezentowany jest poniżej.

```python
import pgzrun
import random

WIDTH = 800
HEIGHT = 600

sun = Actor("sun")
# Licznik czasu
sun.timer = 0


def draw():
    screen.fill("skyblue")
    sun.draw()


def update():
    # Zmiejszamy licznik czasu
    sun.timer -= 1

    # Jeżeli licznik czasu spadł do zera
    if sun.timer <= 0:
        # Wybieramy nowe, losowe współrzędne położenia słońca na ekranie
        sun.x = random.randint(80, WIDTH - 80)
        sun.y = random.randint(80, HEIGHT - 80)
        # Ustalamy początkową wartość licznika czasu
        sun.timer = 60


pgzrun.go()
```

### Testujemy działanie

Uruchamiamy ponownie i sprawdzamy, czy nasze słońce porusza się już w bardziej sensowny sposób.

## Zliczanie punktów

Czas na zliczanie punktów. W tym celu będziemy potrzebowali miejsca (zmienną), gdzie zapamiętamy punkty. Wyświetlimy je na ekranie i będziemy dodawać (lub odejmować) za każde kliknięcie.

### Wyświetlamy punkty

Na początku dopiszemy punkty do naszego aktora, podobnie jak zrobiliśmy z parametrem *timer*. Punkty zaczynamy zliczać od zera, a nazwiemy je **points**, czyli punkty z angielskiego.

```python
sun = Actor("sun")
sun.timer = 0
sun.points = 0
```

Teraz czas wyświetlić punkty na ekranie, tak abyśmy mogli sprawdzać, czy naliczają się poprawnie. W tym celu skorzystamy z metody `screen.draw.text`, którą umieścimy na samym końcu części rysującej (`draw`). Do tej metody musimy przekazać kilka parametrów. W celu ułatwienia sobie pracy, przed wartością każdego parametru dopiszemy jego nazwę i znak przypisania $$=$$.
Parametry, jakie przekażemy, to:

- **text** - Tekst do wyświetlenia na ekranie, czyli nasza liczba punktów. Ponieważ musimy podać tekst, a nie liczbę, to punkty zamieniamy na tekst za pomocą funkcji **str**: `str(sun.points)`.
- **center** - Współrzędne miejsca, w którym ma się znaleźć **środek** wyświetlanego tekstu. Chcemy, aby punkty były wyświetlane na środku ekranu (czyli w połowie szerokości), u góry (np. $$50$$ pikseli od góry). W takim razie podajemy parę współrzędnych zapisaną w nawiasach okrągłych: `(WIDTH / 2, 50)`.
- **color** - Kolor wyświetlanego tekstu. Podobnie jak przy tle możemy wybrać własny kolor, np. czerwony (**red**).
- **fontsize** - Rozmiar czcionki. Jeżeli chcemy, by punkty były dobrze widoczne, warto podać jakąś dużą wartość, np. $$100$$.

Pełne wywołanie metody `screen.draw.text` będzie więc wyglądało następująco:

```python
def draw():
    ...
    screen.draw.text(text=str(sun.points), center=(WIDTH / 2, 50), color="red", fontsize=100)
```

Pełna implementacja funkcji rysującej wygląda natomiast tak:

```python
def draw():
    screen.fill("skyblue")
    sun.draw()
    screen.draw.text(text=str(sun.points), center=(WIDTH / 2, 50), color="red", fontsize=100)
```

Teraz możemy uruchomić naszą grę i zobaczyć, czy podoba nam się sposób wyświetlania punktów. Jeżeli nie, to zawsze możemy go poprawić.

### Zliczanie punktów

W celu zliczania punktów skorzystamy z funkcji odczytującej kliknięcia na ekranie.
Funkcja ta nazywa się `on_mouse_down` i przyjmuje parametr `pos` określający **pozycję**, czyli współrzędne kliknięcia myszy na ekranie.

Naszą nową funkcję dopisujemy na końcu naszego kodu, zaraz pod częścią aktualizującą (**update**), ale **przed** wywołaniem `pgzrun.go()`.

```python
def on_mouse_down(pos):
```

Wewnątrz funkcji sprawdzamy, czy kliknęliśmy w słońce, czy też nie. Sprawdzimy to za pomocą **instrukcji warunkowej** (*if*), a także skorzystamy z metody **collidepoint**, która pozwala sprawdzić, czy zadany aktor (w naszym przypadku słońce) jest w **kolizji** z punktem na ekranie (w naszym przypadku z miejscem kliknięcia myszy). Metodę tą wywołamy na naszym aktorze **sun**, a przekażemy do niej jako paramter współrzędne kliknięcia myszy (**pos**).

Nasza instrukcja będzie więc wyglądała następująco:

```python
def on_mouse_down(pos):
    if sun.collidepoint(pos):
```

Jeżeli faktycznie udało nam się kliknąć w słońce, to powinniśmy zrobić dwie rzeczy: zwiększyć liczbę punktów o jeden (`sun.points += 1`) oraz zresetować timer (`sun.timer = 0`). Spróbujmy więc to zapisać.

```python
def on_mouse_down(pos):
    if sun.collidepoint(pos):
        sun.points += 1
        sun.timer = 0
```

Co jednak w przeciwnym przypadku (**else**), gdy nie udało nam się trafić w słońce? Wtedy powinniśmy stracić jeden punkt (`sun.points -= 1`) i także zresetować timer (`sun.timer = 0`). Nasza funkcja będzie więc wyglądała następująco:

```python
def on_mouse_down(pos):
    if sun.collidepoint(pos):
        sun.points += 1
        sun.timer = 0
    else:
        sun.points -= 1
        sun.timer = 0
```

Warto w tym momencie uruchomić naszą grę i sprawdzić, jak zmieniają się punkty wyświetlane na ekranie.

### Zwiększanie poziomu trudności

Aby gra stawała się tym trudniejsza, im więcej mamy punktów, uzależnijmy wartość parametru *timer* od liczby zdobytych punktów. W tym celu zmodyfikujemy linijkę w części aktualizującej, gdzie resetujemy nasz licznik. Możemy to zrobić na kilka sposobów. Jednym z pomysłów jest odjęcie od liczby $$60$$ (reprezentującej jedną sekundę) liczby zdobytych punktów. W ten sposób, im więcej będziemy mieli punktów, tym słońce będzie szybciej przeskakiwać po ekranie. Natomiast jak będzie nam słabo szło i często będziemy tracić punkty, to słońce będzie wolniejsze i łatwiejsze do złapania.

W ostatniej linijce części *update* zamiast `sun.timer = 60` zapisujemy `sun.timer = 60 - sun.points`.

Pełna implementacja funkcji aktualizującej wygląda więc teraz następująco:

```python
def update():
    sun.timer -= 1

    if sun.timer <= 0:
        sun.x = random.randint(80, WIDTH - 80)
        sun.y = random.randint(80, HEIGHT - 80)
        sun.timer = 60 - sun.points
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random

WIDTH = 800
HEIGHT = 600

sun = Actor("sun")
sun.timer = 0
# Zliczamy zdobyte przez gracza punkty
sun.points = 0


def draw():
    screen.fill("skyblue")
    sun.draw()
    # Wypisujemy liczbę punktów
    screen.draw.text(text=str(sun.points), center=(WIDTH / 2, 50), color="red", fontsize=100)


def update():
    sun.timer -= 1

    if sun.timer <= 0:
        sun.x = random.randint(80, WIDTH - 80)
        sun.y = random.randint(80, HEIGHT - 80)
        # Ustalamy początkową wartość licznika czasu
        sun.timer = 60 - sun.points


# Funkcja odczytująca kliknięcia myszy
def on_mouse_down(pos):
    # Jeżeli kliknęliśmy na słońce
    if sun.collidepoint(pos):
        # Zwiększamy liczbę punktów
        sun.points += 1
        # Zerujemy licznik czasu, aby słońce się przemieściło
        sun.timer = 0
    else: # W przeciwnym przypadku, gdy nie udało nam się kliknąć w słońce
        # Zmniejszamy liczbę punktów
        sun.points -= 1
        # Zerujemy licznik czasu, aby słońce się przemieściło
        sun.timer = 0


pgzrun.go()
```

## Pełna gra

```python
# Importujemy potrzebne biblioteki
import pgzrun
import random


# Ustalamy wymiary okna gry
WIDTH = 800
HEIGHT = 600

# Tworzymy aktora słońca
sun = Actor("sun")
# Licznik czasu
sun.timer = 0
# Zliczamy zdobyte przez gracza punkty
sun.points = 0


# Funkcja rysująca stan gry na ekranie
def draw():
    # Wypełniamy tło niebieskim kolorem
    screen.fill("skyblue")
    # Rysujemy słońce
    sun.draw()
    # Wypisujemy liczbę punktów
    screen.draw.text(text=str(sun.points), center=(WIDTH / 2, 50), color="red", fontsize=100)


# Funkcja aktualizująca stan gry
def update():
    # Zmiejszamy licznik czasu
    sun.timer -= 1

    # Jeżeli licznik czasu spadł do zera
    if sun.timer <= 0:
        # Wybieramy nowe, losowe współrzędne położenia słońca na ekranie
        sun.x = random.randint(80, WIDTH - 80)
        sun.y = random.randint(80, HEIGHT - 80)
        # Ustalamy początkową wartość licznika czasu
        sun.timer = 60 - sun.points


# Funkcja odczytująca kliknięcia myszy
def on_mouse_down(pos):
    # Jeżeli kliknęliśmy na słońce
    if sun.collidepoint(pos):
        # Zwiększamy liczbę punktów
        sun.points += 1
        # Zerujemy licznik czasu, aby słońce się przemieściło
        sun.timer = 0
    else: # W przeciwnym przypadku, gdy nie udało nam się kliknąć w słońce
        # Zmniejszamy liczbę punktów
        sun.points -= 1
        # Zerujemy licznik czasu, aby słońce się przemieściło
        sun.timer = 0


# Uruchamiamy grę
pgzrun.go()
```

Pełna implementacja dostępna jest również poniżej.

{% embed url="https://github.com/blackbat13/CatchTheSunPgZero" %}
Złap Słońce
{% endembed %}

### Gramy

Czas zagrać w naszą grę! Ile punktów Tobie uda się zdobyć?

## Zadanie dodatkowe

Spróbuj dodać do gry wyświetlanie największej liczby punktów, jakie udało się zdobyć w obecnej rozgrywce. **Podpowiedź**: dopisz nową zmienną do słońca i wyświetl ją na ekranie (podobnie jak punkty), a przy każdym nowym zdobytym punkcie sprawdzaj, czy udało się zdobyć więcej punktów niż dotychczas, a jeżeli tak to zmień wartość nowej zmiennej.