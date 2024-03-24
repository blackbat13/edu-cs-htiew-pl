# Flappy Bird

## Wstęp

Dzisiaj odtworzymy jedną z kultowych gier mobilnych: Flappy Bird.

### Czego się nauczysz

* Jak dodać grawitację i skok/latanie do gry.
* Jak stworzyć i obsłużyć proste menu.
* Jak stworzyć "nieskończoną" grę bazującą na prostych założeniach.
* Jak zaimplementować proste efekty wizualne.

### Grafiki do pobrania

Umieszczamy w katalogu **images**.

{% file src="../../../.gitbook/assets/flappy_images.zip" %}
Grafiki do gry Flappy Bird
{% endfile %}

### Efekty dźwiękowe do pobrania

Umieszczamy w katalogu **sounds**.

{% file src="../../../.gitbook/assets/flappy_sounds.zip" %}
Efekty dźwiękowe do gry Flappy Bird
{% endfile %}

### Źródła

- Grafiki przycisków pochodzą ze strony: [https://kenney.nl/](https://kenney.nl).
- Pozostałe grafiki pochodzą ze strony projektu pgzero: [https://github.com/lordmauve/pgzero/tree/master/examples/flappybird/images](https://github.com/lordmauve/pgzero/tree/master/examples/flappybird/images).
- Efekty dźwiękowe pochodzą ze strony: [https://www.sounds-resource.com/mobile/flappybird/sound/5309/](https://www.sounds-resource.com/mobile/flappybird/sound/5309/).

## Nasz cel

![Flappy Bird - animacja](../../../.gitbook/assets/flappyGame.gif)

## Wstępna konfiguracja

Zaczynamy standardowo: tworzymy nowy projekt, instalujemy bibliotekę, pobieramy materiały i umieszczamy je w odpowiednich miejscach.
Nasz projekt możemy nazwać np. "FlappyBird". Gdy już utworzymy projekt, tworzymy w nim dwa nowe katalogi: *images* oraz *sounds*. Następnie pobieramy wyżej wymienione materiały, rozpakowujemy je, a zawartość przerzucamy do odpowiednich katalogów. Pozostało nam jeszcze zainstalować bibliotekę: w okienku terminala wypisujemy standardowo polecenie `pip install pgzero`.

## Tworzymy okno gry

Jak zwykle zaczynamy od podstaw. Wymiary naszego okna są zależne od wymiarów grafiki tła i wynoszą $$400\times700$$. Ustawiamy więc odpowiednie wymiary i wypełniamy tło grafiką *bg.png* za pomocą polecenia `screen.blit()`. Możemy także skonfigurować tytuł naszej gry.

```python
# Importujemy potrzebne biblioteki
import pgzrun
import random


# Ustalamy wymiary okna gry
WIDTH = 400
HEIGHT = 700

# Ustalamy tytuł okna gry
TITLE = "Pygame Zero Flappy Bird"


# Funkcja rysująca stan gry na ekranie
def draw():
    # Rysujemy tło gry
    screen.blit("bg", (0, 0))


# Funkcja aktualizująca stan gry
def update():
    pass


# Uruchamiamy grę
pgzrun.go()
```

## Ptak

Zacznijmy od naszej głównej postaci: ptaka.

### Dodajemy aktora

Na samym początku dodajemy nowego aktora z grafiki *bird1.png*. Umieścimy go z lewej strony ekranu, na środku, pod współrzędnymi $$(75, 200)$$.

```python
bird = Actor("bird1")
bird.x = 75
bird.y = 200
```

### Rysujemy

Wyświetlmy naszą nową postać na ekranie. Na końcu części rysującej dopisujemy polecenie rysujące ptaka: `bird.draw()`.

```python
def draw():
    screen.blit("bg", (0, 0))
    bird.draw()
```

### Grawitacja

Jak na razie nasza postać jest bardzo statyczna i tkwi w jednym miejscu. Urozmaićmy więc trochę jej życie i dodajmy siłę grawitacji. Grawitacja w naszej grze będzie działać podobnie do tej, którą znamy z codziennego życia: będzie ściągać postać w dół. Zanim jednak będziemy mogli dodać oddziaływanie grawitacji na postać, musimy ustalić siłę grawitacji. Dodajmy więc zmienną **GRAVITY** na początku naszego kodu, zaraz pod wymiarami okna, i przypiszmy jej wartość $$0.3$$. Nazwę zmiennej podamy z wielkich liter, ponieważ możemy ją potraktować jako jedno z **ustawień** naszej gry. Co więcej, wartości grawitacji nie będziemy modyfikować w trakcie rozgrywki, można więc powiedzieć, że jest to wartość **stała**.

```python
GRAVITY = 0.3
```

Teraz czas zaaplikować grawitację do postaci ptaka. Grawitacja powinna wpływać na prędkość pionową postaci, musimy więc tę prędkość dopisać do naszego aktora. Do ptaka, zaraz pod ustaleniem jego pozycji na ekranie, dopisujemy zmienną **vy** i przypisujemy jej początkową wartość $$0$$.

```python
bird.vy = 0
```

W celu zachowania czytelności i przejrzystości kodu stworzymy nową funkcję **update_bird**, zaraz pod funkcją *update*.

```python
def update_bird():
```

Chcemy, aby w każdej klatce animacji prędkość postaci była zwiększana o siłę grawitacji. 

```python
def update_bird():
    bird.vy += GRAVITY
```

Z kolei pozycja aktora powinna się zmieniać zgodnie z jego prędkością. 

```python
def update_bird():
    bird.vy += GRAVITY
    bird.y += bird.vy
```

Pozostało nam wywołać naszą funkcję w części aktualizującej. Z funkcji *update* usuwamy więc polecenie `pass` i dopisujemy wywołanie naszej funkcji *update_bird*.

```python
def update():
    update_bird()
```

### Latanie

Mamy już grawitację, czas więc dodać możliwość próby przezwyciężenia tej wielkiej siły: zdolność latania. W celu zasymulowania unoszenia się postaci do góry wystarczy, że nadamy jej odpowiednią prędkość wzlotową. Prędkość ta, podobnie jak grawitacja, będzie jednym z ustawień naszej gry. W związku z tym tworzymy zmienną **FLAP** zaraz pod zmienną *GRAVITY* i przypisujemy jej wybraną wartość, np. $$7$$.

```python
FLAP = 7
```

Nasza postać będzie podnosić się lekko do góry za każdym razem, gdy wciśniemy jakiś (dowolny) przycisk na myszce. Potrzebna nam więc funkcja `on_mouse_down`, która przyjmuje parametr **pos** oznaczający pozycję myszy na ekranie (teraz nie jest nam to potrzebne, ale później się przyda). Dopisujemy ją na końcu kodu, zaraz przed wywołaniem `pgzrun.go()`. Wewnątrz po prostu przypisujemy do prędkości pionowej (*vy*) ptaka ujemną wartość naszej prędkości wzlotowej (*FLAP*). Przypisujemy ujemną prędkość, ponieważ chcemy, by ptak poleciał do góry.

```python
def on_mouse_down(pos):
    bird.vy = -FLAP
```

Dodajmy także odtworzenie dźwięku machnięcia skrzydełkami (*wing*).

```python
def on_mouse_down(pos):
    bird.vy = -FLAP
    sounds.wing.play()
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 400
HEIGHT = 700

TITLE = "Pygame Zero Flappy Bird"

# Siła grawitacji
GRAVITY = 0.3
# Prędkość wzlotowa
FLAP = 7

# Tworzymy aktora ptaka
bird = Actor("bird1")
# Ustalamy jego pozycję na ekranie
bird.x = 75
bird.y = 200
# Ustalamy początkową prędkość pionową ptaka
bird.vy = 0


def draw():
    screen.blit("bg", (0, 0))
    # Rysujemy ptaka
    bird.draw()


def update():
    # Aktualizujemy ptaka
    update_bird()


# Pomocnicza funkcja aktualizująca ptaka
def update_bird():
    # Zwiększamy prędkość pionową zgodnie z siłą grawitacji
    bird.vy += GRAVITY
    # Przemieszczamy ptaka zgodnie z jego prędkością
    bird.y += bird.vy


# Funkcja odczytująca kliknięcia myszy
def on_mouse_down(pos):
    # Symulujemy wzlot ptaka
    bird.vy = -FLAP
    # Odtwarzamy dźwięk machnięcia skrzydełkami
    sounds.wing.play()


pgzrun.go()
```

## Rury

Czas dodać naszego przeciwnika w grze: rury. Jak zwykle zaczynamy od dodania nowych aktorów. Tym razem będzie ich dwóch: górna rura (`pipe_top`) i dolna rura (`pipe_bottom`). Utworzymy ich tak jak zazwyczaj z niewielką różnicą: ustalimy im odpowiednie **kotwice** (ang. *anchor*). Kotwica pozwala nam wybrać punkt grafiki, według którego będziemy ją umieszczać na ekranie. Można to sobie wyobrazić jako miejsce, w którym "trzymamy" grafikę, gdy ją przemieszczamy. Domyślnie grafikę poruszamy względem jej środka, ale możemy też wybrać inne miejsce zaczepienia. Ze względu na charakter rur w naszej grze jest to duże ułatwienie.

Dla górnej rury ustawimy kotwicę w jej lewym **dolnym** rogu. Dla dolnej rury natomiast ustawimy kotwicę w jej lewym **górnym** rogu.

```python
pipe_top = Actor("top")
pipe_top.anchor = ("left", "bottom")

pipe_bottom = Actor("bottom")
pipe_bottom.anchor = ("left", "top")
```

### Rysujemy rury

Gdy już mamy aktorów, czas ich wyświetlić na ekranie. Dodajemy dwie instrukcje w części rysującej naszej gry. Narysujemy je przed narysowaniem postaci ptaka, żeby go nie zasłaniały.

```python
def draw():
    screen.blit("bg", (0, 0))
    pipe_top.draw()
    pipe_bottom.draw()
    bird.draw()
```

### Ustawiamy pozycję rur

Główną trudnością w naszej grze będzie niewielka przestrzeń pomiędzy rurami, przez którą musimy przelecieć. Rozmiar tej przestrzeni zapiszemy jako **ustawienie** w zmiennej **GAP_SIZE**. Naszą nową zmienną zapisujemy zaraz pod zmienną *FLAP* i nadamy jej wartość $$180$$.

```python
GAP_SIZE = 180
```

Żeby gra nie była zbyt przewidywalna, przestrzeń pomiędzy rurami powinna pojawiać się na losowej wysokości. 
Stworzymy więc funkcję `set_pipes` za pomocą której będziemy losować nową pozycję rur. Naszą funkcję dopiszemy na końcu naszego kodu, zaraz przed wywołaniem *pgzrun.go()*.

```python
def set_pipes():
```

Pierwszą operacją w naszej funkcji będzie wylosowanie pozycji pionowej **środka** naszej dziury. Zapiszemy ją w zmiennej **gap_y**, a do wylosowania wartości skorzystamy z funkcji **random.randint**. Jako przedział losowanej wartości warto podać takie liczby, żeby dziura nie pojawiała się na skraju ekranu, czyli np. $$(200, 500)$$.

```python
def set_pipes():
    gap_y = random.randint(200, 500)
```

Teraz możemy przypisać nowe pozycje naszych rur. Ustawimy je poza prawą stroną ekranu, tak by mogły płynnie "wjechać" na ekran gry. W tym celu do ich współrzędnej *x* przypiszemy szerokość (*WIDTH*) ekranu. Jeżeli chodzi o współrzędną *y* to górna rura powinna być położona **ponad** współrzędną *gap_y*, a dolna **pod** nią. Obie natomiast powinny być oddalone od tego środka dokładnie o połowę rozmiaru przerwy (*GAP_SIZE*).

```python
def set_pipes():
    gap_y = random.randint(200, 500)

    pipe_top.x = WIDTH
    pipe_top.y = gap_y - GAP_SIZE / 2

    pipe_bottom.x = WIDTH
    pipe_bottom.y = gap_y + GAP_SIZE / 2
```

Teraz czas wywołać naszą funkcję. Zrobimy to zaraz przed uruchomieniem gry, czyli tuż przed instrukcją `pgzrun.go()`.

```python
set_pipes()
pgzrun.go()
```

### Przemieszczamy rury

W każdej klatce animacji nasze rury powinny przemieszczać się w lewą stronę. Z jaką prędkością powinny się poruszać? To także możemy zapisać jako **ustawienie** naszej gry. Utwórzmy więc zmienną **SPEED**, którą zapiszemy zaraz pod ustawieniem rozmiaru przerwy. Nadajmy jej początkową wartość $$3$$.

```python
SPEED = 3
```

Teraz możemy przejść do aktualizacji pozycji rur na ekranie zgodnie z ustaloną prędkością. W tym celu utworzymy nową pomocniczą funkcję **update_pipes**, tak by zachować porządek i czytelność naszego kodu. Funkcję zapiszemy zaraz pod funkcją aktualizującą ptaka (*update_bird*).

```python
def update_pipes():
```

Wewnątrz naszej funkcji przesuwamy rury zgodnie z ustaloną prędkością. Chcemy je przesunąć w lewo, więc od ich współrzędnej **x** odejmujemy naszą prędkość **SPEED**.

```python
def update_pipes():
    pipe_top.x -= SPEED
    pipe_bottom.x -= SPEED
```

Gdy rury znikną z lewej strony ekranu, należy ustawić je ponownie. Aby sprawdzić czy zniknęły, możemy sprawdzić, czy współrzędna **x** górnej (lub dolnej) rury jest odpowiednio mała, np. mniejsza od $$-100$$, tak aby mieć pewność, że rura całkowicie zniknęła z ekranu.

```python
def update_pipes():
    pipe_top.x -= SPEED
    pipe_bottom.x -= SPEED

    if pipe_top.x < -100:
```

Teraz pozostało wywołać naszą pomocniczą funkcję ustawiającą rury (*set_pipes*).

```python
def update_pipes():
    pipe_top.x -= SPEED
    pipe_bottom.x -= SPEED

    if pipe_top.x < -100:
        set_pipes()
```

Nasza funkcja jest już gotowa, więc dopiszmy jej wywołanie na końcu funkcji *update*.

```python
def update():
    ...

    update_pipes()
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 400
HEIGHT = 700

TITLE = "Pygame Zero Flappy Bird"

GRAVITY = 0.3
FLAP = 7
GAP_SIZE = 180
SPEED = 3

bird = Actor("bird1")
bird.x = 75
bird.y = 200
bird.vy = 0

# Tworzymy górną rurę
pipe_top = Actor("top")
pipe_top.anchor = ("left", "bottom")

# Tworzymy dolną rurę
pipe_bottom = Actor("bottom")
pipe_bottom.anchor = ("left", "top")


def draw():
    screen.blit("bg", (0, 0))
    # Rysujemy górną rurę
    pipe_top.draw()
    # Rysujemy dolną rurę
    pipe_bottom.draw()
    bird.draw()


def update():
    update_bird()
    # Aktualizujemy rury
    update_pipes()


def update_bird():
    bird.vy += GRAVITY
    bird.y += bird.vy


# Pomocnicza funkcja aktualizująca rury
def update_pipes():
    # Przemieszczamy górną i dolną rurę zgodnie z prędkością przemieszczania się rur
    pipe_top.x -= SPEED
    pipe_bottom.x -= SPEED

    # Jeżeli górna rura schowała się już z lewej strony ekranu
    if pipe_top.x < -100:
        # Ponownie ustawiamy rury
        set_pipes()


def on_mouse_down(pos):
    bird.vy = -FLAP
    sounds.wing.play()


# Pomocnicza funkcja ustawiająca rury
def set_pipes():
    # Losujemy pozycję środka przestrzeni pomiędzy rurami
    gap_y = random.randint(200, 500)

    # Ustawiamy pozycję górnej rury
    pipe_top.x = WIDTH
    pipe_top.y = gap_y - GAP_SIZE / 2

    # Ustawiamy pozycję dolnej rury
    pipe_bottom.x = WIDTH
    pipe_bottom.y = gap_y + GAP_SIZE / 2


# Ustawiamy rury na początku gry
set_pipes()
pgzrun.go()
```

## Koniec gry

Kiedy nasza gra się kończy? Gdy trafimy w rurę, lub wylecimy poza ekran.

### Reset gry

Zacznijmy od zastanowienia się, co chcemy zrobić, gdy gra się skończy, tzn. gdy gracz przegra.
Możemy oczywiście wyświetlić komunikat o przegranej i wyłączyć grę.
Nasza gra ma jednak z założenia wysoki poziom trudności, więc uruchamianie jej raz za razem po każdej przegranej bardzo szybko stałoby się uciążliwe.
Zamiast tego po przegranej **zresetujemy grę**, tzn. zaczniemy ją od nowa.
W tym celu stworzymy nową funkcję **reset**, którą umieścimy na końcu naszego kodu, zaraz przed instrukcją `pgzrun.go()`.

```python
def reset():
```

Co powinniśmy zrobić, aby zresetować grę?
Jakie jej ustawienia musimy przywrócić do początkowych wartości?
Potrzebujemy przywrócić naszego gracza, ptaka, na początkową pozycję i nadać mu właściwą prędkość.

```python
def reset():
    bird.x = 75
    bird.y = 200
    bird.vy = 0
```

Przydałoby się także ponownie ustawić rury, abyśmy przypadkiem nie wylądowali w środku jednej
 z nich.

```python
def reset():
    bird.x = 75
    bird.y = 200
    bird.vy = 0
    set_pipes()
```

### Kolizja z rurą

W jaki sposób wykryć, że ptak uderzył w rurę?
Musimy sprawdzić, czy aktor reprezentujący ptaka i aktor reprezentujący rurę są ze sobą w **kolizji**.
Co to oznacza, że dwaj aktorzy są ze sobą w kolizji?
To znaczy, że prostokąty, które reprezentują ich grafiki, **nachodzą na siebie**.
Można to sprawdzić na wiele sposobów, ale biblioteka Pygame Zero ma do tego wbudowaną funkcję: **colliderect**.

Kolizję ptaka będziemy sprawdzać w funkcji aktualizującej ptaka, czyli *update_bird*.

W celu sprawdzenia, czy ptak jest w kolizji z górną rurą, zapiszemy:

```python
def update_bird():
    ...

    if bird.colliderect(pipe_top):
```

Oczywiście nie interesuje nas tylko uderzenie w górną rurę, ale także i w dolną. W gruncie rzeczy ptak może zahaczyć o górną rurę **lub** dolną. Dodajmy więc to do naszego warunku.

```python
def update_bird():
    ...

    if bird.colliderect(pipe_top) or bird.colliderect(pipe_bottom):
```

Co chcemy zrobić, gdy ptak uderzy w którąś z rur? Najpierw odtwórzmy dźwięk uderzenia: *hit*.

```python
def update_bird():
    ...

    if bird.colliderect(pipe_top) or bird.colliderect(pipe_bottom):
        sounds.hit.play()
```

Chcemy także zresetować grę. Wywołujemy więc naszą funkcję *reset*.

```python
def update_bird():
    ...

    if bird.colliderect(pipe_top) or bird.colliderect(pipe_bottom):
        sounds.hit.play()
        reset()
```

### Ucieczka poza ekran

Gdy wylecimy ptakiem poza ekran, gra ma się zakończyć, tzn. zacząć od nowa, podobnie jak w przypadku uderzenia w rurę. Co to znaczy, że nasz aktor przemieścił się poza ekran? To znaczy, że jego współrzędne znajdują się poza ekranem.

Ponieważ nasza postać porusza się jedynie góra-dół, ograniczymy się do sprawdzenia, czy nie wylecieliśmy z góry albo z dołu ekranu.
Jeżeli wylecieliśmy z góry ekranu, to znaczy, że nasza współrzędna $$y$$ jest mniejsza od $$0$$. Nasz warunek dopiszemy jako kolejną opcję przy sprawdzaniu kolizji z rurami, ponieważ w obu przypadkach zareagujemy tak samo.

```python
def update_bird():
    ...

    if bird.colliderect(pipe_top) or bird.colliderect(pipe_bottom) or bird.y < 0:
        sounds.hit.play()
        reset()
```

Jeżeli natomiast wylecieliśmy z dołu ekranu, to znaczy, że nasza współrzędna $$y$$ jest większa od wysokości (**HEIGHT**) ekranu.

```python
def update_bird():
    ...

    if bird.colliderect(pipe_top) or bird.colliderect(pipe_bottom) or bird.y < 0 or bird.y > HEIGHT:
        sounds.hit.play()
        reset()
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 400
HEIGHT = 700

TITLE = "Pygame Zero Flappy Bird"

GRAVITY = 0.3
FLAP = 7
GAP_SIZE = 180
SPEED = 3

bird = Actor("bird1")
bird.x = 75
bird.y = 200
bird.vy = 0

pipe_top = Actor("top")
pipe_top.anchor = ("left", "bottom")

pipe_bottom = Actor("bottom")
pipe_bottom.anchor = ("left", "top")


def draw():
    screen.blit("bg", (0, 0))
    pipe_top.draw()
    pipe_bottom.draw()
    bird.draw()


def update():
    update_bird()
    update_pipes()
    

def update_bird():
    bird.vy += GRAVITY
    bird.y += bird.vy

    # Jeżeli ptak wpadł na górną lub dolną rurę, lub gdy wyleciał poza ekran z dołu lub z góry
    if bird.colliderect(pipe_top) or bird.colliderect(pipe_bottom) or bird.y > HEIGHT or bird.y < 0:
        # Odtwarzamy dźwięk uderzenia
        sounds.hit.play()
        # Resetujemy grę
        reset()


def update_pipes():
    pipe_top.x -= SPEED
    pipe_bottom.x -= SPEED

    if pipe_top.x < -100:
        set_pipes()


def on_mouse_down(pos):
    bird.vy = -FLAP
    sounds.wing.play()


def set_pipes():
    gap_y = random.randint(200, 500)

    pipe_top.x = WIDTH
    pipe_top.y = gap_y - GAP_SIZE / 2

    pipe_bottom.x = WIDTH
    pipe_bottom.y = gap_y + GAP_SIZE / 2


# Pomocnicza funkcja resetująca stan gry
def reset():
    # Ustalamy początkową pozycję ptaka na ekranie
    bird.x = 75
    bird.y = 200
    # Ustalamy początkową prędkość pionową ptaka
    bird.vy = 0
    # Ustawiamy rury
    set_pipes()


set_pipes()
pgzrun.go()
```

## Punkty

Czas na zdobywanie punktów!

### Zapamiętujemy punkty

W celu zapamiętania punktów dopiszemy nową zmienną do naszego aktora ptaka. Nazwiemy ją **points** i przypiszemy jej początkową wartość $$0$$. Nową zmienną dopisujemy na górze kodu, zaraz pod przypisaniem prędkości pionowej do ptaka.

```python
bird = Actor("bird1")
bird.x = 75
bird.y = 200
bird.vy = 0
bird.points = 0
```

### Wyświetlamy punkty na ekranie

Na końcu części rysującej dopiszemy wyświetlanie punktów za pomocą funkcji `screen.draw.text`.

```python
def draw():
    ...

    screen.draw.text(str(bird.points), center=(WIDTH / 2, 30), fontsize=70)
```

### Zliczamy punkty

Punkty będziemy dostawać za każdą pokonaną przeszkodę. Dlatego, w funkcji aktualizującej rury (*update_pipes*), w miejscu gdzie ponownie ustawiamy rury, gdy te znikną z ekranu, dodamy graczowi jeden punkt.

```python
def update_pipes():
    ...

    if pipe_top.x < -100:
        set_pipes()
        bird.points += 1
```

Po zdobyciu punktu warto także odtworzyć efekt dźwiękowy o nazwie *point*.

```python
def update_pipes():
    ...

    if pipe_top.x < -100:
        set_pipes()
        bird.points += 1
        sounds.point.play()
```

### Resetujemy punkty

Nie chcielibyśmy, żeby gra kontynuowała zliczanie punktów po przegranej, tylko żeby punkty były liczone od nowa. W tym celu, w funkcji resetującej grę (*reset*) dopiszemy wyzerowanie punktów gracza. W celu zachowania porządku kodu dopiszemy to zaraz przed wywołaniem funkcji *set_pipes*, chociaż kolejność nie będzie miała wpływu na działanie gry.

```python
def reset():
    ...

    bird.points = 0
    set_pipes()
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 400
HEIGHT = 700

TITLE = "Pygame Zero Flappy Bird"

GRAVITY = 0.3
FLAP = 7
GAP_SIZE = 180
SPEED = 3

bird = Actor("bird1")
bird.x = 75
bird.y = 200
bird.vy = 0
# Zliczamy zdobyte przez gracza punkty
bird.points = 0

pipe_top = Actor("top")
pipe_top.anchor = ("left", "bottom")

pipe_bottom = Actor("bottom")
pipe_bottom.anchor = ("left", "top")


def draw():
    screen.blit("bg", (0, 0))
    pipe_top.draw()
    pipe_bottom.draw()
    bird.draw()
    # Wypisujemy liczbę punktów na ekranie
    screen.draw.text(str(bird.points), center=(WIDTH / 2, 30), fontsize=70)


def update():
    update_bird()
    update_pipes()
    

def update_bird():
    bird.vy += GRAVITY
    bird.y += bird.vy

    if bird.colliderect(pipe_top) or bird.colliderect(pipe_bottom) or bird.y > HEIGHT or bird.y < 0:
        sounds.hit.play()
        reset()


def update_pipes():
    pipe_top.x -= SPEED
    pipe_bottom.x -= SPEED

    if pipe_top.x < -100:
        set_pipes()
        # Zwiększamy liczbę punktów
        bird.points += 1
        # Odtwarzamy dźwięk zdobycia punktu
        sounds.point.play()


def on_mouse_down(pos):
    bird.vy = -FLAP
    sounds.wing.play()


def set_pipes():
    gap_y = random.randint(200, 500)

    pipe_top.x = WIDTH
    pipe_top.y = gap_y - GAP_SIZE / 2

    pipe_bottom.x = WIDTH
    pipe_bottom.y = gap_y + GAP_SIZE / 2


def reset():
    bird.x = 75
    bird.y = 200
    bird.vy = 0
    # Zapamiętujemy liczbę punktów zdobytych przez gracza
    bird.points = 0
    set_pipes()


set_pipes()
pgzrun.go()
```

## Menu

Przejdźmy teraz do kwestii obsługi menu gry. Nasze menu będzie proste, ponieważ będzie zawierało tylko jeden przycisk do rozpoczęcia gry.

### Tworzymy przycisk

Nasz przycisk będzie kolejnym aktorem, którego utworzymy na podstawie grafiki *start1.png* i zapamiętamy w nowej zmiennej **start**. Aktora utworzymy zaraz pod stworzeniem rur.

```python
start = Actor("start1")
```

Nasz przycisk umieścimy pośrodku ekranu, tzn. w połowie szerokości i wysokości. Przypisujemy mu więc odpowiednie współrzędne.

```python
start = Actor("start1")
start.x = WIDTH / 2
start.y = HEIGHT / 2
```

### Rysujemy przycisk

Przycisk narysujemy wówczas, gdy gra się zakończy. O zakończeniu gry poinformuje nas nowa zmienna *bird.dead*, którą dopiszemy do naszego ptaka, zaraz pod punktami, i nadamy jej początkową wartość *TRUE*. 

```python
bird.dead = True
```

Jeżeli ta zmienna ma wartość *TRUE*, to rysujemy przycisk na końcu części rysującej.

```python
def draw():
    ...

    if bird.dead:
        start.draw()
```

### Klikamy na przycisk

Cóż to za przycisk, który nie reaguje na kliknięcia? Interakcję z przyciskiem obsłużymy wewnątrz funkcji odczytującej kliknięcia myszy, czyli *on_mouse_down*. Najpierw jednak zmodyfikujmy naszą funkcję, tak aby nie można było latać ptakiem, gdy gra się już zakończyła. W tym celu dwie instrukcje, które mamy zapisane w tej funkcji, czyli podfrunięcie i odtworzenie dźwięku, wykonamy tylko wtedy, gdy gra **nie jest** (**not**) zakończona.

```python
def on_mouse_down(pos):
    if not bird.dead:
        bird.vy = -FLAP
        sounds.wing.play()
```

**W przeciwnym przypadku jeżeli** (**elif**) pozycja kliknięcia myszy (**pos**) jest w **kolizji** z przyciskiem **start**: `start.collidepoint(pos)`. Jeżeli tak, to zresetujemy grę wywołując naszą funkcję *reset*.

```python
def on_mouse_down(pos):
    if not bird.dead:
        bird.vy = -FLAP
        sounds.wing.play()
    elif start.collidepoint(pos):
        reset()
```

Teraz jeszcze jednak nasza gra nie wystartuje poprawnie, ponieważ nie zmieniamy wartości zmiennej *bird.dead*, w związku z czym dla programu gra jest cały czas zakończona. Dlatego do naszej funkcji *reset* dopisujemy zmianę wartości wspomnianej zmiennej na *FALSE*. Dla zachowania porządku dopiszemy to zaraz pod wyzerowaniem liczby punktów, a przed ponownym ustawieniem rur.

```python
def reset():
    ...
    
    bird.dead = False
    set_pipes()
```

### Kończymy grę po kolizji

Teraz nasze menu powinno już działać, gdy uruchomimy grę. Gdy jednak uderzymy w przeszkodę, to gra się po prostu zrestartuje. Zmieńmy to! Jeżeli uderzymy w przeszkodę, co sprawdzamy na końcu funkcji *update_bird*, to nie będziemy resetować gry, tylko zmienimy wartość zmiennej na *bird.dead* na *TRUE*.

```python
def update_bird():
    ...

    if bird.colliderect(pipe_top) or bird.colliderect(pipe_bottom) or bird.y > HEIGHT or bird.y < 0:
        sounds.hit.play()
        bird.dead = True
```

### Zatrzymujemy rury

Przydałoby się także zatrzymać rury, gdy gra się zakończy, tak byśmy nie mogli nabijać punktów w nieskończoność! W tym celu, na początku funkcji *update_pipes* sprawdzimy, czy gra się już zakończyła. Jeżeli tak, to wyjdziemy z funkcji bez aktualizacji pozycji rur korzystając z polecenia **return**.

```python
def update_pipes():
    if bird.dead:
        return
    
    ...
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 400
HEIGHT = 700

TITLE = "Pygame Zero Flappy Bird"

GRAVITY = 0.3
FLAP = 7
GAP_SIZE = 180
SPEED = 3

bird = Actor("bird1")
bird.x = 75
bird.y = 200
bird.vy = 0
bird.points = 0
# Zapamiętujemy, czy gra się zakończyła
bird.dead = True

pipe_top = Actor("top")
pipe_top.anchor = ("left", "bottom")

pipe_bottom = Actor("bottom")
pipe_bottom.anchor = ("left", "top")

# Tworzymy przycisk startu
start = Actor("start1")
# Ustalamy pozycję przycisku na ekranie
start.x = WIDTH / 2
start.y = HEIGHT / 2


def draw():
    screen.blit("bg", (0, 0))
    pipe_top.draw()
    pipe_bottom.draw()
    bird.draw()
    screen.draw.text(str(bird.points), center=(WIDTH / 2, 30), fontsize=70)
    # Jeżeli gra się zakończyła
    if bird.dead:
        # Rysujemy przycisk startu gry
        start.draw()


def update():
    update_bird()
    update_pipes()
    

def update_bird():
    bird.vy += GRAVITY
    bird.y += bird.vy

    if bird.colliderect(pipe_top) or bird.colliderect(pipe_bottom) or bird.y > HEIGHT or bird.y < 0:
        sounds.hit.play()
        # Zapamiętujemy, że gra się zakończyła
        bird.dead = True


def update_pipes():
    # Jeżeli gra się zakończyła
    if bird.dead:
        # Kończymy i nie przeprowadzamy już dalszej aktualizacji ptaka
        return

    pipe_top.x -= SPEED
    pipe_bottom.x -= SPEED

    if pipe_top.x < -100:
        set_pipes()
        bird.points += 1
        sounds.point.play()


def on_mouse_down(pos):
    # Jeżeli gra jeszcze trwa
    if not bird.dead:
        bird.vy = -FLAP
        sounds.wing.play()
    elif start.collidepoint(pos): # W przeciwnym przypadku, gdy kliknęliśmy na przycisk start i gra jest już zakończona
        # Resetujemy stan gry
        reset() 


def set_pipes():
    gap_y = random.randint(200, 500)

    pipe_top.x = WIDTH
    pipe_top.y = gap_y - GAP_SIZE / 2

    pipe_bottom.x = WIDTH
    pipe_bottom.y = gap_y + GAP_SIZE / 2


def reset():
    bird.x = 75
    bird.y = 200
    bird.vy = 0
    bird.points = 0
    # Zapamiętujemy, czy gra się już zakończyła
    bird.dead = False
    set_pipes()


set_pipes()
pgzrun.go()
```

## Efekty wizualne

Pora na ostatnie szlify. Teraz dodamy kilka efektów wizualnych, takich jak obrót ptaka, zmiana jego grafiki, czy też efekt najechania wskaźnikiem myszki na przycisk.

### Efekt spadania po kolizji

Po kolizji ptaka z przeszkodą zmienimy jego grafikę (**bird.image**) na *dead*, a także ustawimy mu kąt obrotu (**bird.angle**) na $$-90$$, tak aby był skierowany w dół.

```python
def update_bird():
    ...

    if bird.colliderect(pipe_top) or bird.colliderect(pipe_bottom) or bird.y > HEIGHT or bird.y < 0:
        sounds.hit.play()
        bird.dead = True
        bird.image = "dead"
        bird.angle = -90
```

Teraz jeszcze powinniśmy przywrócić właściwą grafikę ptaka gdy restartujemy grę, aby nie mieć latającego ptaka zombie. Dlatego w funkcji *reset*, zaraz pod zmianą wartości zmiennej *bird.dead*, zmienimy grafikę ptaka na początkową, czyli *bird1*.

```python
def reset():
    ...

    bird.image = "bird1"
    set_pipes()
```

### Obracanie ptaka i machanie skrzydełkami

Obrotem ptaka i zmianą jego grafiki tak, by ptak "machał" skrzydełkami, zajmiemy się **na końcu** funkcji aktualizującej ptaka (*update_bird*). Ponieważ ptaka chcemy obracać tylko wtedy, gdy gra się jeszcze nie zakończyła (ponieważ gdy gra jest zakończona, to ptak spada w dół), to najpierw sprawdzimy, czy **nieprawda że** (**not**) gra jest zakończona (*bird.dead*).

```python
def update_bird():
    ...

    if not bird.dead:
```

Teraz przyszła pora na zajęcie się obrotem ptaka i zmianą jego grafik. Te dwie rzeczy uzależnimy od jego prędkości, a konkretnie od tego, czy leci do góry, czy spada w dół.

Jeżeli prędkość pionowa ptaka jest mniejsza od zera, oznacza to, że ptak wzlatuje do góry. W takim razie zmienimy jego grafikę na *bird2*, a obrót **zwiększymy** o $$3$$, by obrócił się do góry.

```python
def update_bird():
    ...

    if not bird.dead:
        if bird.vy < 0:
            bird.image = "bird2"
            bird.angle += 3
```

W przeciwnym przypadku, tzn. gdy ptak spada w dół, zmienimy jego grafikę na *bird1* i **zmiejszymy** jego kąt obrotu o $$3$$, by obrócił się do dołu.

```python
def update_bird():
    ...

    if not bird.dead:
        if bird.vy < 0:
            bird.image = "bird2"
            bird.angle += 3
        else:
            bird.image = "bird1"
            bird.angle -= 3
```

Aby zapobiec kręceniu się ptaka w kółko powinniśmy ograniczyć jego **maksymalny** i **minimalny** kąt obrotu. Powiedzmy, że chcemy zachować obrót w zakresie od $$-45$$ do $$45$$. W tym celu najpierw sprawdzimy, czy kąt obrotu przekroczył wartość $$45$$, a jeżeli tak, to przywrócimy jego maksymalną wartość, czyli właśnie $$45$$.

```python
def update_bird():
    ...

    if not bird.dead:
        if bird.vy < 0:
            bird.image = "bird2"
            bird.angle += 3
        else:
            bird.image = "bird1"
            bird.angle -= 3

        if bird.angle > 45:
            bird.angle = 45
```

Podobnie robimy w drugą stronę, czyli gdy kąt obrotu jest mniejszy od $$-45$$. Wówczas przywracamy minimalną wartość $$-45$$.

```python
def update_bird():
    ...

    if not bird.dead:
        if bird.vy < 0:
            bird.image = "bird2"
            bird.angle += 3
        else:
            bird.image = "bird1"
            bird.angle -= 3

        if bird.angle > 45:
            bird.angle = 45

        if bird.angle < -45:
            bird.angle = -45
```

### Podświetlenie przycisku

Aby zasymulować efekt "podświetlania" przycisku po najechaniu na niego myszką, będziemy wyświetlać grafikę *start2*, gdy wskaźnik myszy znajduje się na przycisku, a grafikę *start1* w przeciwnym przypadku. W tym celu potrzebujemy znać obecną pozycję wskaźnika myszy na ekranie. Do tego posłuży nam funkcja **on_mouse_down**, która przyjmuje parametr **pos**, w którym zapisana będzie pozycja wskaźnika myszy na ekranie, gdy ten zostanie poruszony.

Naszą funkcję zapiszemy zaraz pod funkcją odczytującą kliknięcia myszy (*on_mouse_down*).

```python
def on_mouse_move(pos):
```

Teraz sprawdzimy, czy wskaźnik myszy znajduje się na przycisku *start*. W tym celu skorzystamy ponownie z metody **collidepoint**, podobnie jak w przypadku odczytywania kliknięć w przycisk.

```python
def on_mouse_move(pos):
    if start.collidepoint(pos):
```

Jeżeli wskaźnik myszy znajduje się na przycisku, to zmieniamy jego grafikę na **start2**.

```python
def on_mouse_move(pos):
    if start.collidepoint(pos):
        start.image = "start2"
```

W przeciwnym przypadku zmieniamy grafikę na **start1**.

```python
def on_mouse_move(pos):
    if start.collidepoint(pos):
        start.image = "start2"
    else:
        start.image = "start1"
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 400
HEIGHT = 700

TITLE = "Pygame Zero Flappy Bird"

GRAVITY = 0.3
FLAP = 7
GAP_SIZE = 180
SPEED = 3

bird = Actor("bird1")
bird.x = 75
bird.y = 200
bird.vy = 0
bird.points = 0
bird.dead = True

pipe_top = Actor("top")
pipe_top.anchor = ("left", "bottom")

pipe_bottom = Actor("bottom")
pipe_bottom.anchor = ("left", "top")

start = Actor("start1")
start.x = WIDTH / 2
start.y = HEIGHT / 2


def draw():
    screen.blit("bg", (0, 0))
    pipe_top.draw()
    pipe_bottom.draw()
    bird.draw()
    screen.draw.text(str(bird.points), center=(WIDTH / 2, 30), fontsize=70)
    if bird.dead:
        start.draw()


def update():
    update_bird()
    update_pipes()
    

def update_bird():
    bird.vy += GRAVITY
    bird.y += bird.vy

    if bird.colliderect(pipe_top) or bird.colliderect(pipe_bottom) or bird.y > HEIGHT or bird.y < 0:
        sounds.hit.play()
        bird.dead = True
        # Zmieniamy grafikę ptaka
        bird.image = "dead"
        # Zmieniamy kąt ptaka, by był skierowany w dół
        bird.angle = -90

    if not bird.dead:
        # Jeżeli prędkość pionowa ptaka jest ujemna, tzn. gdy ptak leci do góry
        if bird.vy < 0:
            # Zmieniamy grafikę ptaka
            bird.image = "bird2"
            # Zwiększamy jego kąt obrotu - obracamy go przeciwnie do ruchu wskazówek zegara
            bird.angle += 3
        else: # W przeciwnym przypadku, gdy prędkość pionowa ptaka jest dodatnia, tzn. gdy ptak leci w dół
            # Zmieniamy grafikę ptaka
            bird.image = "bird1"
            # Zmniejszamy jego kąt obrotu - obracamy go zgodnie z ruchem wskasówek zegara
            bird.angle -= 3

        # Jeżeli kąt obrotu przekroczył 45
        if bird.angle > 45:
            # Przywracamy kąt 45
            bird.angle = 45

        # Jeżeli kąt obrotu jest poniżej -45
        if bird.angle < -45:
            # Przywracamy kąt -45
            bird.angle = -45


def update_pipes():
    if bird.dead:
        return

    pipe_top.x -= SPEED
    pipe_bottom.x -= SPEED

    if pipe_top.x < -100:
        set_pipes()
        bird.points += 1
        sounds.point.play()


def on_mouse_down(pos):
    if not bird.dead:
        bird.vy = -FLAP
        sounds.wing.play()
    elif start.collidepoint(pos):
        reset() 


# Funkcja odczytująca ruch myszy
def on_mouse_move(pos):
    # Jeżeli wskaźnik myszy jest w kolizji z przyciskiem startu
    if start.collidepoint(pos):
        # Zmianiamy grafikę przycisku
        start.image = "start2"
    else: # W przeciwnym przypadku, gdy wskaźnik myszy nie znajduje się na przycisku
        # Ustalamy inną grafikę przycisku
        start.image = "start1"


def set_pipes():
    gap_y = random.randint(200, 500)

    pipe_top.x = WIDTH
    pipe_top.y = gap_y - GAP_SIZE / 2

    pipe_bottom.x = WIDTH
    pipe_bottom.y = gap_y + GAP_SIZE / 2


def reset():
    bird.x = 75
    bird.y = 200
    bird.vy = 0
    bird.points = 0
    bird.dead = False
    # Ustalamy początkową grafikę ptaka
    bird.image = "bird1"
    set_pipes()


set_pipes()
pgzrun.go()
```

## Pełna gra

```python
# Importujemy potrzebne biblioteki
import pgzrun
import random


# Ustalamy wymiary okna gry
WIDTH = 400
HEIGHT = 700

# Ustalamy tytuł okna gry
TITLE = "Pygame Zero Flappy Bird"

# Siła grawitacji
GRAVITY = 0.3
# Prędkość wzlotowa
FLAP = 7
# Rozmiar przestrzeni pomiędzy rurami
GAP_SIZE = 180
# Prędkość przemieszczania się rur
SPEED = 3

# Tworzymy aktora ptaka
bird = Actor("bird1")
# Ustalamy jego pozycję na ekranie
bird.x = 75
bird.y = 200
# Ustalamy początkową prędkość pionową ptaka
bird.vy = 0
# Zliczamy zdobyte przez gracza punkty
bird.points = 0
# Zapamiętujemy, czy gra się zakończyła
bird.dead = True

# Tworzymy górną rurę
pipe_top = Actor("top")
pipe_top.anchor = ("left", "bottom")

# Tworzymy dolną rurę
pipe_bottom = Actor("bottom")
pipe_bottom.anchor = ("left", "top")

# Tworzymy przycisk startu
start = Actor("start1")
# Ustalamy pozycję przycisku na ekranie
start.x = WIDTH / 2
start.y = HEIGHT / 2


# Funkcja rysująca stan gry na ekranie
def draw():
    # Rysujemy tło gry
    screen.blit("bg", (0, 0))
    # Rysujemy górną rurę
    pipe_top.draw()
    # Rysujemy dolną rurę
    pipe_bottom.draw()
    # Rysujemy ptaka
    bird.draw()
    # Wypisujemy liczbę punktów na ekranie
    screen.draw.text(str(bird.points), center=(WIDTH / 2, 30), fontsize=70)
    # Jeżeli gra się zakończyła
    if bird.dead:
        # Rysujemy przycisk startu gry
        start.draw()


# Funkcja aktualizująca stan gry
def update():
    # Aktualizujemy ptaka
    update_bird()
    # Aktualizujemy rury
    update_pipes()


# Pomocnicza funkcja aktualizująca ptaka
def update_bird():
    # Zwiększamy prędkość pionową zgodnie z siłą grawitacji
    bird.vy += GRAVITY
    # Przemieszczamy ptaka zgodnie z jego prędkością
    bird.y += bird.vy

    # Jeżeli ptak wpadł na górną lub dolną rurę, lub gdy wyleciał poza ekran z dołu lub z góry
    if bird.colliderect(pipe_top) or bird.colliderect(pipe_bottom) or bird.y > HEIGHT or bird.y < 0:
        # Odtwarzamy dźwięk uderzenia
        sounds.hit.play()
        # Zapamiętujemy, że gra się zakończyła
        bird.dead = True
        # Zmieniamy grafikę ptaka
        bird.image = "dead"
        # Zmieniamy kąt ptaka, by był skierowany w dół
        bird.angle = -90

    # Jeżeli gra wciąż trwa
    if not bird.dead:
        # Jeżeli prędkość pionowa ptaka jest ujemna, tzn. gdy ptak leci do góry
        if bird.vy < 0:
            # Zmieniamy grafikę ptaka
            bird.image = "bird2"
            # Zwiększamy jego kąt obrotu - obracamy go przeciwnie do ruchu wskazówek zegara
            bird.angle += 3
        else: # W przeciwnym przypadku, gdy prędkość pionowa ptaka jest dodatnia, tzn. gdy ptak leci w dół
            # Zmieniamy grafikę ptaka
            bird.image = "bird1"
            # Zmniejszamy jego kąt obrotu - obracamy go zgodnie z ruchem wskasówek zegara
            bird.angle -= 3

        # Jeżeli kąt obrotu przekroczył 45
        if bird.angle > 45:
            # Przywracamy kąt 45
            bird.angle = 45

        # Jeżeli kąt obrotu jest poniżej -45
        if bird.angle < -45:
            # Przywracamy kąt -45
            bird.angle = -45
        

# Pomocnicza funkcja aktualizująca rury
def update_pipes():
    # Jeżeli gra się zakończyła
    if bird.dead:
        # Kończymy i nie przeprowadzamy już dalszej aktualizacji rur
        return

    # Przemieszczamy górną i dolną rurę zgodnie z prędkością przemieszczania się rur
    pipe_top.x -= SPEED
    pipe_bottom.x -= SPEED

    # Jeżeli górna rura schowała się już z lewej strony ekranu
    if pipe_top.x < -100:
        # Ponownie ustawiamy rury
        set_pipes()
        # Zwiększamy liczbę punktów
        bird.points += 1
        # Odtwarzamy dźwięk zdobycia punktu
        sounds.point.play()


# Funkcja odczytująca kliknięcia myszy
def on_mouse_down(pos):
    # Jeżeli gra jeszcze trwa
    if not bird.dead:
        # Symulujemy wzlot ptaka
        bird.vy = -FLAP
        # Odtwarzamy dźwięk machnięcia skrzydełkami
        sounds.wing.play()
    elif start.collidepoint(pos): # W przeciwnym przypadku, gdy kliknęliśmy na przycisk start i gra jest już zakończona
        # Resetujemy stan gry
        reset() 


# Funkcja odczytująca ruch myszy
def on_mouse_move(pos):
    # Jeżeli wskaźnik myszy jest w kolizji z przyciskiem startu
    if start.collidepoint(pos):
        # Zmianiamy grafikę przycisku
        start.image = "start2"
    else: # W przeciwnym przypadku, gdy wskaźnik myszy nie znajduje się na przycisku
        # Ustalamy inną grafikę przycisku
        start.image = "start1"


# Pomocnicza funkcja resetująca stan gry
def reset():
    # Ustalamy początkową pozycję ptaka na ekranie
    bird.x = 75
    bird.y = 200
    # Ustalamy początkową prędkość pionową ptaka
    bird.vy = 0
    # Zapamiętujemy liczbę punktów zdobytych przez gracza
    bird.points = 0
    # Zapamiętujemy, czy gra się już zakończyła
    bird.dead = False
    # Ustalamy początkową grafikę ptaka
    bird.image = "bird1"
    # Ustawiamy rury
    set_pipes()


# Pomocnicza funkcja ustawiająca rury
def set_pipes():
    # Losujemy pozycję środka przestrzeni pomiędzy rurami
    gap_y = random.randint(200, 500)

    # Ustawiamy pozycję górnej rury
    pipe_top.x = WIDTH
    pipe_top.y = gap_y - GAP_SIZE / 2

    # Ustawiamy pozycję dolnej rury
    pipe_bottom.x = WIDTH
    pipe_bottom.y = gap_y + GAP_SIZE / 2


# Ustawiamy rury na początku gry
set_pipes()
# Uruchamiamy grę
pgzrun.go()
```

Pełna implementacja dostępna jest również poniżej.

{% embed url="https://github.com/blackbat13/flappybirdpygamezero" %}
Flappy Bird PyGameZero
{% endembed %}