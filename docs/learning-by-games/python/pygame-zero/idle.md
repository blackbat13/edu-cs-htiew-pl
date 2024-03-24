# Gra typu idle

## Wstęp

Tym razem stworzymy grę, w której postacie poruszać będą się same. Będzie to gra typu idle, w której będziemy czekać, aż uzbieramy wystarczająco dużo punktów, by móc kupić kolejne ulepszenie. Naszą grę oprzemy na stworzonej już wcześniej grze "Głodna świnia", dzięki czemu będziemy mogli skupić się na nowych elementach rozgrywki.

### Czego się nauczysz

* Jak zaprogramować postać tak, by sama "grała".
* Jak stworzyć grę typu idle.
* Jak stworzyć prosty interfejs z przyciskami.

### Materiały do pobrania

#### Grafiki

Umieszczamy w katalogu **images**.

{% file src="../../../.gitbook/assets/idle_images.zip" %}
Grafiki do gry typu idle
{% endfile %}

### Źródła

- [https://kenney.nl/](https://kenney.nl/)
- [https://comigo.itch.io/farm-puzzle-animals](https://comigo.itch.io/farm-puzzle-animals)

## Nasz cel

![Idle Pig - animacja](../../../.gitbook/assets/IdlePig.gif)

## Wstępna konfiguracja

Zaczynamy standardowo: tworzymy nowy projekt, instalujemy bibliotekę, pobieramy materiały i umieszczamy je w odpowiednich miejscach.
Nasz projekt możemy nazwać np. "IdlePig". Gdy już utworzymy projekt, tworzymy w nim nowy katalog *images*. Następnie pobieramy wyżej wymienione materiały, rozpakowujemy je, a zawartość przerzucamy do nowego katalogu. Pozostało nam jeszcze zainstalować bibliotekę: w okienku terminala wypisujemy standardowo polecenie `pip install pgzero`.

## Podstawowy szablon

Naszą grę oprzemy na grze "Głodna świnia", dlatego zamiast zaczynać od pustego kodu, zaczniemy od gotowej gry, którą już wcześniej stworzyliśmy. Nie wszystko nam jednak będzie potrzebne. Ponieważ nasza gra będzie "nieskończona", to usuniemy elementy związane z zakończeniem gry. Usuniemy także elementy związane z wykorzystaniem czcionki i dźwięków, nie będą nam tutaj potrzebne. Podobnie postąpimy z instrukcją przyspieszającą świnię po zjedzeniu buraka, ponieważ w naszej nowej grze będziemy kupować ulepszenia prędkości świni. Dopiszemy także bibliotekę **pygame**, która przyda nam się później. Kod, od którego zaczniemy, widoczny jest poniżej.

```python
import pgzrun
import random
import pygame

WIDTH = 800
HEIGHT = 800

TITLE = "Idle Pig"

pig = Actor("pig_down")
pig.x = WIDTH / 2
pig.y = HEIGHT / 2
pig.vx = 0
pig.vy = 0
pig.v = 3
pig.points = 0

beet = Actor("beetroot")
beet.x = 200
beet.y = 200


def draw():
    screen.blit("bg", (0, 0))
    pig.draw()
    beet.draw()
    screen.draw.text(f"{pig.points}", center=(WIDTH / 2, 50), fontsize=60, color="#fdee00")


def update():
    pig.x += pig.vx
    pig.y += pig.vy

    if pig.colliderect(beet):
        beet.x = random.randint(50, WIDTH - 50)
        beet.y = random.randint(50, HEIGHT - 50)
        pig.points += 1


def on_key_down(key):
    if key == keys.LEFT:
        pig.vx = -pig.v
        pig.vy = 0
        pig.image = "pig_left"

    if key == keys.RIGHT:
        pig.vx = pig.v
        pig.vy = 0
        pig.image = "pig_right"

    if key == keys.UP:
        pig.vx = 0
        pig.vy = -pig.v
        pig.image = "pig_up"

    if key == keys.DOWN:
        pig.vx = 0
        pig.vy = pig.v
        pig.image = "pig_down"
		

pgzrun.go()
```

## Automatyczna świnia

Naszą świnią nie będziemy już poruszać za pomocą przycisków na klawiaturze, tylko będzie ona poruszać się automatycznie. Dlatego zmienimy nazwę naszej funkcji `on_key_down` na `bot` i usuniemy parametr **key**.

```python
def bot():
    if key == keys.LEFT:
        pig.vx = -pig.v
        pig.vy = 0
        pig.image = "pig_left"

    if key == keys.RIGHT:
        pig.vx = pig.v
        pig.vy = 0
        pig.image = "pig_right"

    if key == keys.UP:
        pig.vx = 0
        pig.vy = -pig.v
        pig.image = "pig_up"

    if key == keys.DOWN:
        pig.vx = 0
        pig.vy = pig.v
        pig.image = "pig_down"
```

Teraz zastanówmy się, kiedy świnia ma się poruszać w danym kierunku. Odpowiedź jest prosta: świnia powinna zawsze podążać w kierunku buraka. W związku z tym będziemy kierować świnię w danym kierunku, jeżeli w tym kierunku znajduje się burak. Musimy jednak wziąć jeszcze pod uwagę prędkość świni, tak aby nie ominęła buraka poruszając się za szybko.

### Ruch w lewo

Świnia poruszy się w lewo, gdy burak znajduje się po jej lewej stronie, a odległość od niego w poziomie jest większa bądź równa prędkości świni. Żeby to sprawdzić policzymy odległość poziomą pomiędzy świnią a burakiem (`pig.x - beet.x`) i porównamy ją z prędkością świni (`pig.v`). Tym porównaniem zastąpimy warunek `key == keys.LEFT` odpowiadający wcześniej za ruch w lewo.

```python
def bot():
    if pig.x - beet.x >= pig.v:
        pig.vx = -pig.v
        pig.vy = 0
        pig.image = "pig_left"    

    ...
```

### Ruch w prawo

Podobnie postąpimy z ruchem w prawo. Tym razem musimy jednak sprawdzić odległość w poziomie buraka od świni. Nowym warunkiem zastępujemy drugi warunek (`key == keys.RIGHT`).

```python
def bot():
    ...

    if beet.x - pig.x >= pig.v:
        pig.vx = pig.v
        pig.vy = 0
        pig.image = "pig_right"

    ...
```

### Ruch w górę

Przy ruchu górę sprawdzimy odległość w pionie pomiędzy świnią a burakiem. Zastępujemy trzeci warunek (`key == keys.UP`).

```python
def bot():
    ...

    if pig.y - beet.y >= pig.v:
        pig.vx = 0
        pig.vy = -pig.v
        pig.image = "pig_up"

    ...
```

### Ruch w dół

Na koniec sprawdzamy odległość w pionie pomiędzy burakiem a świnią. Zastępujemy czwarty, ostatni warunek (`key == keys.DOWN`).

```python
def bot():
    ...

    if beet.y - pig.y >= pig.v:
        pig.vx = 0
        pig.vy = pig.v
        pig.image = "pig_down"
```

### Wywołanie automatycznego ruchu

Pozostało nam wywołać naszą funkcję **bot** na początku funkcji **update**, tak by świnia poruszała się sama.

```python
def update():
    bot()
    ...
```

### Pełny kod

```python
import pgzrun
import random
import pygame

WIDTH = 800
HEIGHT = 800

TITLE = "Idle Pig"

pig = Actor("pig_down")
pig.x = WIDTH / 2
pig.y = HEIGHT / 2
pig.vx = 0
pig.vy = 0
pig.v = 3
pig.points = 0

beet = Actor("beetroot")
beet.x = 200
beet.y = 200


def draw():
    screen.blit("bg", (0, 0))
    pig.draw()
    beet.draw()
    screen.draw.text(f"{pig.points}", center=(WIDTH / 2, 50), fontsize=60, color="#fdee00")


def update():
    bot()
    pig.x += pig.vx
    pig.y += pig.vy

    if pig.colliderect(beet):
        beet.x = random.randint(50, WIDTH - 50)
        beet.y = random.randint(50, HEIGHT - 50)
        pig.points += 1


def bot():
    if pig.x - beet.x >= pig.v:
        pig.vx = -pig.v
        pig.vy = 0
        pig.image = "pig_left"

    if beet.x - pig.x >= pig.v:
        pig.vx = pig.v
        pig.vy = 0
        pig.image = "pig_right"

    if pig.y - beet.y >= pig.v:
        pig.vx = 0
        pig.vy = -pig.v
        pig.image = "pig_up"

    if beet.y - pig.y >= pig.v:
        pig.vx = 0
        pig.vy = pig.v
        pig.image = "pig_down"
		

pgzrun.go()
```

## Poszerzenie ekranu

Przyciski do kupowania ulepszeń w naszej grze umieścimy z prawej strony ekranu. W tym celu musimy poszerzyć nasz ekran, powiedzmy o $$400$$ pikseli. Zwiększamy więc wartość szerokości (**WIDTH**).

```python
WIDTH = 1200
HEIGHT = 800
```

Teraz jednak położenie zarówno punktów jak i świni nie będzie poprawne. Dlatego dopiszemy sobie jeszcze jedną stałą, która będzie przechowywała szerokość naszego panelu z przyciskami. Nazwiemy ją **PANEL** i przypiszemy jej wartość $$400$$. Dopiszemy ją zaraz pod określeniem wymiarów okna gry.

```python
WIDTH = 1200
HEIGHT = 800
PANEL = 400
```

Pozostało nam skorzystać z naszej nowej stałej podczas ustalania pozycji elementów na ekranie. Zacznijmy od świni. Zamiast umieszczać ją na środku całego ekranu w poziomie, to umieścimy ją na środku właściwego pola gry. W tym celu, do współrzędnej $$x$$ świni przypiszemy `(WIDTH - PANEL) / 2`.

```python
pig = Actor("pig_down")
pig.x = (WIDTH - PANEL) / 2
pig.y = HEIGHT / 2
...
```

Podobnie zrobimy w przypadku punktów. Ustalając ich pozycję w poziomie zamiast `WIDTH / 2` napiszemy `(WIDTH - PANEL) / 2`.

```python
def draw():
    ...
    screen.draw.text(f"{pig.points}", center=((WIDTH - PANEL) / 2, 50), fontsize=60, color="#fdee00")
```

### Pełny kod

```python
import pgzrun
import random
import pygame

WIDTH = 1200
HEIGHT = 800
PANEL = 400

TITLE = "Idle Pig"

pig = Actor("pig_down")
pig.x = (WIDTH - PANEL)
pig.y = HEIGHT / 2
pig.vx = 0
pig.vy = 0
pig.v = 3
pig.points = 0

beet = Actor("beetroot")
beet.x = 200
beet.y = 200


def draw():
    screen.blit("bg", (0, 0))
    pig.draw()
    beet.draw()
    screen.draw.text(f"{pig.points}", center=((WIDTH - PANEL), 50), fontsize=60, color="#fdee00")


def update():
    bot()
    pig.x += pig.vx
    pig.y += pig.vy

    if pig.colliderect(beet):
        beet.x = random.randint(50, WIDTH - 50)
        beet.y = random.randint(50, HEIGHT - 50)
        pig.points += 1


def bot():
    if pig.x - beet.x >= pig.v:
        pig.vx = -pig.v
        pig.vy = 0
        pig.image = "pig_left"

    if beet.x - pig.x >= pig.v:
        pig.vx = pig.v
        pig.vy = 0
        pig.image = "pig_right"

    if pig.y - beet.y >= pig.v:
        pig.vx = 0
        pig.vy = -pig.v
        pig.image = "pig_up"

    if beet.y - pig.y >= pig.v:
        pig.vx = 0
        pig.vy = pig.v
        pig.image = "pig_down"
		

pgzrun.go()
```

## Kursor

Zajmijmy się teraz kursorem w naszej grze. Dlaczego jest nam on potrzebny? To on będzie nowym swoistym głównym "graczem" w naszej grze. To nim będziemy przecież sterować! To także w nim będziemy przechowywać najważniejsze informacje, takie jak punkty, prędkości postaci czy też punkty zdobywane za warzywa.

### Tworzymy kursor

Na początku dodajemy nowego aktora. Nazwiemy go **cursor**, utworzymy go z grafiki *cursor.png* i zapiszemy zaraz przed funkcją *draw*.

```python
cursor = Actor("cursor")
```

Teraz pozostało nam wyświetlić go na ekranie. Dopisujemy rysowanie kursora na końcu funkcji *draw*, tak aby wyświetlał się zawsze na wierzchu.

```python
def draw():
    ...
    cursor.draw()
```

### Przemieszczamy kursor

Nasz kursor powinien zawsze znajdować się tam, gdzie aktualnie znajduje się wskaźnik myszy. Do tego przyda nam się nowa funkcja odczytująca ruchy myszy: `on_mouse_move`. Nasza funkcja przyjmie jeden parametr **pos**, który będzie zawierał aktualną pozycję wskaźnika myszy. Jest to jedna z funkcji znajdujących się w bibliotece *Pygame Zero*. Naszą funkcję dopiszemy zaraz przed funkcją *bot*, tak aby zachować pewien porządek kodu.

```python
def on_mouse_move(pos):
```

Wewnątrz funkcji potrzebujemy tylko jednej instrukcji: przypisania obecnej pozycji wskaźnika myszy (**pos**) do pozycji naszego kursora (**cursor.pos**).

```python
def on_mouse_move(pos):
    cursor.pos = pos
```

### Ukrywamy wskaźnik myszy

Ponieważ nasz nowy kursor ma zastąpić wskaźnik myszy, to ukryjemy dotychczasowy wskaźnik za pomocą polecenia `pygame.mouse.set_visible(False)` z biblioteki *pygame*. Instrukcję dopisujemy zaraz przed uruchomieniem gry, czyli przed `pgzrun.go()`.

```python
pygame.mouse.set_visible(False)
pgzrun.go()
```

### Pełny kod

```python
import pgzrun
import random
import pygame

WIDTH = 1200
HEIGHT = 800
PANEL = 400

TITLE = "Idle Pig"

pig = Actor("pig_down")
pig.x = (WIDTH - PANEL)
pig.y = HEIGHT / 2
pig.vx = 0
pig.vy = 0
pig.v = 3
pig.points = 0

beet = Actor("beetroot")
beet.x = 200
beet.y = 200

cursor = Actor("cursor")

def draw():
    screen.blit("bg", (0, 0))
    pig.draw()
    beet.draw()
    screen.draw.text(f"{pig.points}", center=((WIDTH - PANEL), 50), fontsize=60, color="#fdee00")
    cursor.draw()


def update():
    bot()
    pig.x += pig.vx
    pig.y += pig.vy

    if pig.colliderect(beet):
        beet.x = random.randint(50, WIDTH - 50)
        beet.y = random.randint(50, HEIGHT - 50)
        pig.points += 1


def on_mouse_move(pos):
    cursor.pos = pos


def bot():
    if pig.x - beet.x >= pig.v:
        pig.vx = -pig.v
        pig.vy = 0
        pig.image = "pig_left"

    if beet.x - pig.x >= pig.v:
        pig.vx = pig.v
        pig.vy = 0
        pig.image = "pig_right"

    if pig.y - beet.y >= pig.v:
        pig.vx = 0
        pig.vy = -pig.v
        pig.image = "pig_up"

    if beet.y - pig.y >= pig.v:
        pig.vx = 0
        pig.vy = pig.v
        pig.image = "pig_down"
		

pygame.mouse.set_visible(False)
pgzrun.go()
```