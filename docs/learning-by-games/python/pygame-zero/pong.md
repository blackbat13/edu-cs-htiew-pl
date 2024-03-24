# Pong

## Wstęp

Klasyczną grę Pong stworzoną przez firmę Atari zna chyba każdy. Dwie paletki po przeciwległych brzegach ekranu, piłka odbijająca się od paletek - ta prosta w swoich założeniach gra była jednak czymś przełomowym w swoich czasach.

Dzisiaj spróbujemy tę grę odtworzyć w trochę bardziej współczesnym środowisku i z odświeżoną grafiką. Do dzieła!

### Czego się nauczysz

* Obsługi dwóch graczy jednocześnie.
* Symulacji prostej fizyki odbijania się piłki.
* Obsługi zakończenia gry i wyświetlenia wyniku.

### Grafiki do pobrania

Umieszczamy w katalogu **images**.

{% file src="../../../.gitbook/assets/pong_images.zip" %}
Grafiki do gry Pong
{% endfile %}

### Źródła

- [https://kenney.nl/](https://kenney.nl/)

## Nasz cel

![Pong](../../../.gitbook/assets/pongGame.gif)

Spróbujmy przeanalizować powyższą animację. Wyróżnijmy elementy graficzne, co pomoże nam zaimplementować naszą grę:

* szare tło,
* żółta linia po środku dzieląca planszę na dwie części,
* punkty wyświetlane na górze ekranu,
* dwie paletki - jedna przy lewym brzegu, druga przy prawym,
* piłka.

## Wstępna konfiguracja

Zaczynamy standardowo: tworzymy nowy projekt, instalujemy bibliotekę, pobieramy materiały i umieszczamy je w odpowiednich miejscach.
Nasz projekt możemy nazwać np. "Pong". Gdy już utworzymy projekt, tworzymy w nim nowy katalog: *images*. Następnie pobieramy wyżej wymienione materiały, rozpakowujemy je, a zawartość przerzucamy do katalogu *images*. Pozostało nam jeszcze zainstalować bibliotekę: w okienku terminala wypisujemy standardowo polecenie `pip install pgzero`.

## Podstawowy szablon

Jako wymiary gry przyjmiemy $$800\times600$$ (szerokość $$800$$ i wysokość $$600$$).

Ustalmy także tytuł naszej gry: "Pong".

```python
import pgzrun
import random


# Wymiary okna
WIDTH = 800
HEIGHT = 600

# Tytuł gry
TITLE = "PONG"


def draw():
    pass
    
    
def update():
    pass
    
    
pgzrun.go()
```

## Tło gry

Na początek rzecz prosta - tło gry. Jak już ustaliliśmy na tło składa się szary kolor i żółta linia na środku ekranu. Zacznijmy od szarego koloru. 

### Szare tło

Dla ułatwienia kolor tła zapamiętamy w zmiennej `bg_color`, którą dodamy zaraz pod tytułem gry. Chcemy mieć lekki odcień szarości.
W tym celu ustalamy kolor za pomocą trzech wartości: **(R, G, B)**.
W celu uzyskania odcienia szarości wystarczy podać trzy takie same liczby, np. $$64$$.

```python
bg_color = (64, 64, 64)
```

Jak już mamy kolor, to wypełnijmy nim całe tło. Dodajemy instrukcję `screen.fill` w części rysującej.

```python
def draw():
    screen.fill(bg_color)
```

### Żółta linia

Mamy kolor tła, teraz dodajmy żółtą linię. W tym celu użyjemy polecenia screen.draw.line do narysowania linii. 
Żeby narysować linię musimy podać jej początek i koniec, a także kolor. 
Gdybyśmy chcieli narysować żółtą linię przez cały ekran, wyglądałoby to tak:

```python
screen.draw.line((WIDTH / 2, 0), (WIDTH / 2, HEIGHT), color = "yellow")
```

Teraz dostosujmy naszą linię, dodając niewielkie marginesy: $$40$$ pikseli z góry i z dołu.

```python
screen.draw.line((WIDTH / 2, 40), (WIDTH / 2, HEIGHT - 40), color = "yellow")
```

Oczywiście, żeby narysować linię na ekranie, musimy dopisać powyższe polecenie w części rysującej, zaraz pod wypełnieniem ekranu kolorem tła.

```python
def draw():
    screen.fill(bg_color)
    screen.draw.line((WIDTH / 2, 40), (WIDTH / 2, HEIGHT - 40), color = "yellow")
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 800
HEIGHT = 600

TITLE = "PONG"

# Kolor tła
bg_color = (64, 64, 64)


def draw():
    # Wypełniamy ekran kolorem tła
    screen.fill(bg_color)
    # Rysujemy linię dzielącą pole gry
    screen.draw.line((WIDTH / 2, 40), (WIDTH / 2, HEIGHT - 40), color = "yellow")
    
    
def update():
    pass
    
    
pgzrun.go()
```

## Aktorzy

W naszej grze występują trzy postacie (aktorzy):
* lewa paletka,
* prawa paletka,
* piłka.

Dodamy je po kolei do naszej gry i wyświetlimy na ekranie.

## Lewa paletka

Naszych aktorów dodamy zaraz pod kolorem tła, czyli na górze programu.

### Tworzymy aktora

Najpierw musimy utworzyć aktora i zapisać go w nowej zmiennej, którą nazwiemy `left`.
Naszego aktora tworzymy na podstawie grafiki *left.png*.

```python
left = Actor("left")
```

### Ustalamy pozycję lewej paletki

Nasza lewa paletka będzie znajdować się z lewej strony ekranu.
Nie chcemy jednak, by dotykała krawędzi, damy jej więc pewien niewielki margines, np. $$20$$ pikseli.
Dzięki temu nasza gra będzie wyglądała estetyczniej.
Ustalamy więc współrzędną $$x$$ lewej paletki.

```python
left.x = 20
```

Trzeba jeszcze pomyśleć o drugiej współrzędnej: $$y$$.
Początkowo umieśćmy paletkę na środku, czyli w połowie wysokości ekranu gry.

```python
left.y = HEIGHT / 2
```

### Rysujemy paletkę

Skoro już umieściliśmy naszą lewą paletkę w jej początkowej pozycji, możemy ją narysować na ekranie.
Do części rysującej, zaraz pod poleceniem rysującym żółtą linię, dopisujemy polecenie rysujące lewą paletkę: `left.draw()`.

```python
def draw():
    screen.fill(bg_color)
    screen.draw.line((WIDTH / 2, 40), (WIDTH / 2, HEIGHT - 40), color = "yellow")
    left.draw()
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 800
HEIGHT = 600

TITLE = "PONG"

bg_color = (64, 64, 64)

# Tworzymy aktora lewej paletki
left = Actor("left")
# Określamy początkowe współrzędne lewej paletki na ekranie
left.x = 20
left.y = HEIGHT / 2


def draw():
    screen.fill(bg_color)
    screen.draw.line((WIDTH / 2, 40), (WIDTH / 2, HEIGHT - 40), color = "yellow")
    # Rysujemy lewą paletkę
    left.draw()

    
def update():
    pass
    
    
pgzrun.go()
```

## Prawa paletka

Prawą paletkę tworzymy bardzo podobnie do lewej.
Najważniejszą różnicą będzie oczywiście jej grafika i początkowe położenie.

### Tworzymy aktora

Najpierw musimy utworzyć aktora i zapisać go w nowej zmiennej, którą nazwiemy `right`.
Naszego aktora tworzymy na podstawie grafiki *right.png*.

```python
right = Actor("right")
```

### Ustalamy pozycję prawej paletki

Nasza prawa paletka będzie znajdować się z prawej strony ekranu.
Nie chcemy jednak, by dotykała krawędzi, damy jej więc pewien niewielki margines, taki jak dla lewej paletki, czyli $$20$$ pikseli.
Dzięki temu nasza gra będzie wyglądała estetyczniej.
Ustalamy więc współrzędną $$x$$ prawej paletki.
Ponieważ umieszczamy ją z prawej strony ekranu, to aby obliczyć jej pozycję, od szerokości ekranu (**WIDTH**) odejmujemy ustalony wcześniej margines.

```python
right.x = WIDTH - 20
```

Trzeba jeszcze pomyśleć o drugiej współrzędnej: $$y$$.
Początkowo umieśćmy paletkę na środku, czyli w połowie wysokości ekranu gry, tak samo jak lewą paletkę.

```python
right.y = HEIGHT / 2
```

### Rysujemy paletkę

Skoro już umieściliśmy naszą prawą paletkę w jej początkowej pozycji, możemy ją narysować na ekranie.
Do części rysującej, zaraz pod poleceniem rysującym lewą paletkę, dopisujemy polecenie rysujące prawą paletkę: `right.draw()`.

```python
def draw():
    ...

    left.draw()
    right.draw()
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 800
HEIGHT = 600

TITLE = "PONG"

bg_color = (64, 64, 64)

left = Actor("left")
left.x = 20
left.y = HEIGHT / 2

# Tworzymy aktora prawej paletki
right = Actor("right")
# Określamy początkowe współrzędne prawej paletki na ekranie
right.x = WIDTH - 20
right.y = HEIGHT / 2


def draw():
    screen.fill(bg_color)
    screen.draw.line((WIDTH / 2, 40), (WIDTH / 2, HEIGHT - 40), color = "yellow")
    left.draw()
    # Rysujemy prawą paletkę
    right.draw()
    
    
def update():
    pass
    
    
pgzrun.go()
```

## Piłka

Piłkę dodamy podobnie jak paletki, ale umieścimy ją na środku ekranu.

### Tworzymy aktora

Najpierw musimy utworzyć aktora i zapisać go w nowej zmiennej, którą nazwiemy `ball`.
Naszego aktora tworzymy na podstawie grafiki *ball.png*.

```python
ball = Actor("ball")
```

### Ustalamy pozycję piłki

Nasza piłka będzie początkowo znajdować się na środku ekranu.
Dlatego do współrzędnej $$x$$ przypisujemy połowę szerokości (**WIDTH**) ekranu, a do współrzędnej $$y$$ przypisujemy połowę wysokości (**HEIGHT**) ekranu.

```python
ball.x = WIDTH / 2
ball.y = HEIGHT / 2
```

### Rysujemy piłkę

Skoro już umieściliśmy naszą piłkę w jej początkowej pozycji, możemy ją narysować na ekranie.
Do części rysującej, zaraz pod poleceniem rysującym prawą paletkę, dopisujemy polecenie rysujące piłkę: *ball.draw()*.

```python
def draw():
    ...

    ball.draw()
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 800
HEIGHT = 600

TITLE = "PONG"

bg_color = (64, 64, 64)

left = Actor("left")
left.x = 20
left.y = HEIGHT / 2

right = Actor("right")
right.x = WIDTH - 20
right.y = HEIGHT / 2

# Tworzymy aktora piłki
ball = Actor("ball")
# Określamy początkowe współrzędne piłki
ball.x = WIDTH / 2
ball.y = HEIGHT / 2


def draw():
    screen.fill(bg_color)
    screen.draw.line((WIDTH / 2, 40), (WIDTH / 2, HEIGHT - 40), color = "yellow")
    left.draw()
    right.draw()
    # Rysujemy piłkę
    ball.draw()
    
    
def update():
    pass
    
    
pgzrun.go()
```

## Ruch graczy

Paletki chcemy poruszać jedynie w dwóch kierunkach: w górę i w dół.
Obie paletki będziemy sterować za pomocą klawiatury.
Lewą paletkę obsłużymy klawiszami **W** i **S**, a prawą paletkę obsłużymy **strzałkami w górę i w dół**.

### Prędkość graczy

Musimy dopisać do naszych paletek ich prędkość pionową: **vy**. W tym celu pod lewą i prawą paletką dopisujemy odpowiednio `left.vy = 5` oraz `right.vy = 5`. 

### Funkcja odczytująca ruchy

W celu zachowania czytelności naszego kodu, napiszemy sobie nową **funkcję**, tzn. wydzielony fragment kodu, który będzie realizował konkretne zadanie.
To zadanie będzie polegało na odczytaniu wciśniętych klawiszy z klawiatury i wykonaniu odpowiedniego ruchu paletek.
Nazwiemy naszą funkcję `move_players`.
Wewnątrz funkcji będziemy sprawdzać, czy dany klawisz na klawiaturze jest wciśnięty, a jeżeli tak, to wykonamy stosowny ruch paletki, tzn. zmienimy jej współrzędne.

```python
def move_players():
    if keyboard.w:
        left.y -= left.vy

    if keybaord.s:
        left.y += left.vy

    if keyboard.up:
        right.y -= right.vy

    if keyboard.down:
        right.y += right.vy
```

### Wywołujemy funkcję w części aktualizującej

Aby zobaczyć rezultaty naszego działania, potrzebujemy jeszcze **użyć** naszej funkcji.
Ruch graczy to **aktualizacja** pozycji graczy na ekranie, dlatego naszą nową funkcję *move_players* **wywołujemy** w części aktualizującej (**update**), zastępując jej dotychczasową zawartość (*pass*).

```python
def update():
    move_players()
```

### Ograniczenie ruchu graczy

Nie chcemy, by paletki mogły wychodzić poza ekran, dlatego dodajemy dodatkowe warunki do naszych instrukcji.
Przed wykonaniem danego ruchu sprawdzimy, czy paletka znajduje się wystarczająco daleko od brzegu ekranu, aby ten ruch móc wykonać.

```python
def move_players():
    if keyboard.w and left.top > 40:
        left.y -= left.vy

    if keyboard.s and left.bottom < HEIGHT - 40:
        left.y += left.vy

    if keyboard.up and right.top > 40:
        right.y -= right.vy

    if keyboard.down and right.bottom < HEIGHT - 40:
        right.y += right.vy
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 800
HEIGHT = 600

TITLE = "PONG"

bg_color = (64, 64, 64)

left = Actor("left")
left.x = 20
left.y = HEIGHT / 2
left.vy = 5

right = Actor("right")
right.x = WIDTH - 20
right.y = HEIGHT / 2
right.vy = 5

ball = Actor("ball")
ball.x = WIDTH / 2
ball.y = HEIGHT / 2


def draw():
    screen.fill(bg_color)
    screen.draw.line((WIDTH / 2, 40), (WIDTH / 2, HEIGHT - 40), color = "yellow")
    left.draw()
    right.draw()
    ball.draw()
    
    
def update():
    # Odczytujemy ruchy graczy
    move_players()


# Pomocnicza funkcja odczytująca ruchy graczy
def move_players():
    # Lewy gracz porusza się za pomocą klawiszy w oraz s
    if keyboard.w and left.top > 40:
        left.y -= left.vy

    if keyboard.s and left.bottom < HEIGHT - 40:
        left.y += left.vy

    # Prawy gracz porusza się za pomocą strzałek góra i dół
    if keyboard.up and right.top > 40:
        right.y -= right.vy

    if keyboard.down and right.bottom < HEIGHT - 40:
        right.y += right.vy
    
    
pgzrun.go()
```

## Ruch piłki

Teraz zajmiemy się ruchem piłki i jej odbijaniem od ścian i paletek.

### Prędkość piłki

Najpierw dopiszemy do piłki jej początkową prędkość. Ponieważ piłka będzie się poruszać po całym ekranie w dowolnym kierunku, to zdefiniujemy zarówno jej prędkość pionową (**vy**) jak i poziomą (**vx**). Zaraz pod ustaleniem początkowej pozycji piłki na ekranie dopisujemy:

```python
ball.vx = 5
ball.vy = 5
```

### Przemieszczanie piłki

Podobnie jak w przypadku paletek, do obsługi ruchu piłki także stworzymy nową funkcję, którą nazwiemy `move_ball`. Naszą funkcję dopiszemy na końcu kodu, zaraz przed poleceniem `pgzrun.go()`.

```python
def move_ball():
```

Wewnątrz naszej funkcji będziemy przemieszczać piłkę zgodnie z jej prędkością. W tym celu dodajemy prędkości piłki do jej współrzędnych.

```python
def move_ball():
    ball.x += ball.vx
    ball.y += ball.vy
```

Aby nasza funkcja działała, musimy wywołać ją w części aktualizującej (*update*), zaraz pod wywołaniem ruchu graczy.

```python
def update():
    move_players()
    move_ball()    
```

### Odbijanie od ścian

Chcemy, aby nasza piłka odbijała się od górnej i dolnej ściany. W tym celu, po przemieszczeniu piłki musimy sprawdzić, czy nie wyszła ona z góry lub z dołu ekranu. Porównujemy więc pozycję piłki z odpowiednimi wartościami. Dla lepszego efektu zachowamy niewielki margines, np. $$40$$ pikseli.

#### Górna ściana

Zacznijmy od odbicia od górnej ściany. Całość zapisujemy w części aktualizującej ruch piłki (*move_ball*), zaraz pod zmianą pozycji piłki. Sprawdzimy, czy odległość piłki od góry ekranu (**ball.top**) jest mniejsza bądź równa naszemu marginesowi.

```python
def move_ball():
    ...

    if ball.top <= 40:
```

Aby zasymulować odbicie się piłki od góry ekranu wystarczy **odwrócić** jej prędkość pionową (*vy*). To znaczy, zmienić znak jej prędkości na przeciwny: z minusa na plus, z plusa na minus. W tym celu przemnożymy prędkość pionową piłki przez $$-1$$.

```python
def move_ball():
    ...

    if ball.top <= 40:
        ball.vy *= -1
```

#### Dolna ściana

Podobnie postępujemy z odbiciem od dolnej ściany. Najpierw sprawdzimy, czy odległość piłki od dołu ekranu (**ball.bottom**) jest większa bądź równa wysokości ekranu minus nasz margines.

```python
def move_ball():
    ...

    if ball.top <= 40:
        ball.vy *= -1

    if ball.bottom >= HEIGHT - 40:
```

Następnie symulujemy odbicie piłki poprzez odwrócenie jej prędkości pionowej.

```python
def move_ball():
    ...

    if ball.top <= 40:
        ball.vy *= -1

    if ball.bottom >= HEIGHT - 40:
        ball.vy *= -1
```

### Odbijanie od paletek

Odbijanie od paletek zrealizujemy podobnie, jak odbijanie od ścian. Najpierw sprawdzamy, czy piłka uderzyła w paletkę, a następnie odwracamy jej prędkość **poziomą** (*vx*). Całość ponownie zapisujemy na końcu naszej funkcji *move_ball*.

#### Lewa paletka

Zacznijmy od lewej paletki. W celu sprawdzenia, czy piłka uderzyła w lewą paletkę sprawdzimy, czy piłka jest w **kolizji** z lewą paletką. Skorzystamy z funkcji *colliderect*.

```python
def move_ball():
    ...

    if left.colliderect(ball):
```

Teraz pozostało nam zasymulować odbicie poprzez przemnożenie prędkości poziomej (*vx*) naszej piłki przez wartość $$-1$$.

```python
def move_ball():
    ...

    if left.colliderect(ball):
        ball.vx *= -1
```

#### Prawa paletka

Przy prawej paletce postępujemy podobnie. Najpierw sprawdzamy kolizję piłki i prawej paletki.

```python
def move_ball():
    ...

    if left.colliderect(ball):
        ball.vx *= -1

    if right.colliderect(ball):
```

Następnie odwracamy prędkość poziomą piłki.

```python
def move_ball():
    ...

    if left.colliderect(ball):
        ball.vx *= -1

    if right.colliderect(ball):
        ball.vx *= -1
```

### Naprawienie "wpadania" piłki w paletkę

Gdy teraz uruchomimy grę i spróbujemy odbić piłkę, to czasami możemy zauważyć, że piłka na chwilę utknie w paletce i będzie się jakby odbijać wewnątrz niej. Dzieje się tak ze względu na to, jak działa wykrywanie kolizji pomiędzy elementami, a także ze względu na nasz sposób odbijania się piłki od paletki. Możemy to jednak bardzo łatwo naprawić. Wystarczy, że przy kolizji piłki z paletką sprawdzimy dodatkowo, czy piłka porusza się we właściwym kierunku. Jeżeli piłka uderzyła w lewą paletkę, to znaczy, że powinna była poruszać się w lewo. Jeżeli podczas kolizji piłka poruszałaby się w prawo, to znaczy, że już wcześniej odbiliśmy piłkę od tej paletki i utknęła ona wewnątrz niej.

Dodajemy więc dodatkowy warunek do sprawdzenia przy wykryciu kolizji z lewą paletką. Musimy sprawdzić, czy piłka porusza się w lewo, czyli czy jej prędkość *vx* jest **ujemna**, tzn. mniejsza od zera.

```python
def move_ball():
    ...

    if left.colliderect(ball) and ball.vx < 0:
        ball.vx *= -1

    if right.colliderect(ball):
        ball.vx *= -1
```

Podobnie postąpimy przy kolizji z prawą paletką. Tym razem jednak musimy sprawdzić, czy piłka poruszała się w prawą stronę, tzn. czy prędkość piłki jest dodatnia (większa od zera).

```python
def move_ball():
    ...

    if left.colliderect(ball) and ball.vx < 0:
        ball.vx *= -1

    if right.colliderect(ball) and ball.vx > 0:
        ball.vx *= -1
```


### Wypadnięcie poza ekran

Pozostało nam obsłużyć przypadek, gdy jedna z paletek nie zdąży odbić piłki i ta *wyleci* z lewej lub prawej strony ekranu.

Zacznijmy od pytania: co powinno stać się z piłką w takiej sytuacji? Najprościej będzie zresetować jej pozycję, tzn. przywrócić ją na środek ekranu. W tym celu utworzymy nową funkcję `reset_ball`, którą dopiszemy na końcu naszego kodu, zaraz przed `pgzrun.go()`.

```python
def reset_ball():
```

W naszej funkcji przywrócimy piłce jej początkową pozycję.

```python
def reset_ball():
    ball.x = WIDTH / 2
    ball.y = HEIGHT / 2
```

Teraz pozostało nam sprawdzić, czy piłka wyleciała poza ekran z lewej lub prawej strony i zresetować jej pozycję. Zapiszemy to w części aktualizującej pozycję piłki (*move_ball*).

#### Lewa strona

Zaczniemy od wypadnięcia z lewej strony ekranu. W tym celu sprawdzimy, czy odległość piłki od lewej strony (**ball.left**) jest mniejsza bądź równa zero.

```python
def move_ball():
    ...
    if ball.left <= 0:
```

Jeżeli tak jest, to resetujemy pozycję naszej piłki wywołując funkcję `reset_ball`.

```python
def move_ball():
    ...
    if ball.left <= 0:
        reset_ball()
```

#### Prawa strona

W przypadku prawej strony ekranu postępujemy podobnie. Najpierw sprawdzimy, czy odległość piłki od prawej strony (**ball.right**) jest większa bądź równa szerokości ekranu.

```python
def move_ball():
    ...
    if ball.left <= 0:
        reset_ball()

    if ball.right >= WIDTH:
```

Jeżeli tak, to resetujemy pozycję piłki.

```python
def move_ball():
    ...
    if ball.left <= 0:
        reset_ball()

    if ball.right >= WIDTH:
        reset_ball()
```

### Ruch piłki po resecie

Obecnie, gdy nasza piłka wyleci z jednej strony ekranu, to wróci na środek i będzie się dalej poruszać w tym samym kierunku co wcześniej. Może to sprawić, że gracz, który właśnie nie zdołał odbić piłki będzie miał utrudnioną sytuację. W tym celu warto sprawić, by piłka po powrocie na środek poruszała się w losowo wybranym kierunku. Zmodyfikujemy więc naszą funkcję *reset_ball* dopisując do niej dwie linijki zmieniające prędkość piłki.

Ponieważ chcemy, by piłka poruszała się cały czas tak samo szybko, to dla każdej z prędkości (poziomej i pionowej) mamy do wyboru dwie wartości: $$-5$$ lub $$5$$. Aby wylosować pomiędzy tymi dwiema wartościami skorzystamy z funkcji `random.choice`, do której podamy dwie wartości zamknięte w nawiasie kwadratowym i oddzielone przecinkiem (w ten sposób tworzymy **listę**, ale o listach powiemy sobie więcej w późniejszym temacie). Nasze losowanie będzie więc wyglądało następująco: `random.choice([-5, 5])`. Pozostało nam przypisać wyniki losowania do prędkości piłki.

```python
def reset_ball():
    ...

    ball.vx = random.choice([-5, 5])
    ball.vy = random.choice([-5, 5])
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 800
HEIGHT = 600

TITLE = "PONG"

bg_color = (64, 64, 64)

left = Actor("left")
left.x = 20
left.y = HEIGHT / 2
left.vy = 5

right = Actor("right")
right.x = WIDTH - 20
right.y = HEIGHT / 2
right.vy = 5

ball = Actor("ball")
ball.x = WIDTH / 2
ball.y = HEIGHT / 2
# Definiujemy początkową prędkość piłki
ball.vx = 5
ball.vy = 5


def draw():
    screen.fill(bg_color)
    screen.draw.line((WIDTH / 2, 40), (WIDTH / 2, HEIGHT - 40), color = "yellow")
    left.draw()
    right.draw()
    ball.draw()
    
    
def update():
    move_players()
    # Poruszamy piłkę
    move_ball()


def move_players():
    if keyboard.w and left.top > 40:
        left.y -= left.vy

    if keyboard.s and left.bottom < HEIGHT - 40:
        left.y += left.vy

    if keyboard.up and right.top > 40:
        right.y -= right.vy

    if keyboard.down and right.bottom < HEIGHT - 40:
        right.y += right.vy
    

# Pomocnicza funkcja obliczająca ruch piłki i przemieszczająca ją
def move_ball():
    # Przemieszczamy piłkę zgodnie z jej prędkością
    ball.x += ball.vx
    ball.y += ball.vy

    # Odbijamy piłkę od górnej ściany
    if ball.top <= 40:
        ball.vy *= -1

    # Odbijamy piłkę od dolnej ściany
    if ball.bottom >= HEIGHT - 40:
        ball.vy *= -1

    # Odbijamy piłkę od lewej paletki
    if left.colliderect(ball) and ball.vx < 0:
        ball.vx *= -1

    # Odpijamy piłkę od prawej paletki
    if right.colliderect(ball) and ball.vx > 0:
        ball.vx *= -1

    # Jeżeli piłka wypadła z lewej strony
    if ball.left <= 0:
        # Resetujemy pozycję piłki
        reset_ball()

    # Jeżeli piłka wypadła z prawej strony
    if ball.right >= WIDTH:
        # Resetujemy pozycję piłki
        reset_ball()
    

# Pomocnicza funkcja resetująca pozycję piłki
def reset_ball():
    # Określamy początkowe współrzędne piłki
    ball.x = WIDTH / 2
    ball.y = HEIGHT / 2
    # Losowo wybieramy początkową prędkość piłki
    ball.vx = random.choice([-5, 5])
    ball.vy = random.choice([-5, 5])


pgzrun.go()
```

## Punkty

Przyszedł czas na zliczanie punktów!

### Zapamiętujemy punkty

Punkty zdobyte przez graczy zapamiętamy w paletkach. W tym celu dopisujemy do lewej i prawej paletki (zaraz pod ustaleniem ich prędkości) zmienną **points** z początkową wartością $$0$$: `left.points = 0` oraz `right.points = 0`.

### Wyświetlamy punkty

Zanim przejdziemy do zliczania punktów wyświetlimy je na ekranie. By zachować porządek i czytelność kodu dodamy nową funkcję: `draw_points`. Dopiszemy ją zaraz pod częścią rysującą (*draw*).

```python
def draw_points():
```

#### Punkty lewego gracza

Zacznijmy od wypisania punktów lewego gracza. Skorzystamy z funkcji `screen.draw.text`. Jako tekst podamy punkty lewego gracza (*left.points*) z dopiskiem "Lewy: ": `f"Lewy: {left.points}"`. Kolor tekstu (*color*) ustawimy na żółty (*yellow*): `color="yellow"`. Środek tekstu (*center*) umieścimy z lewej strony ekranu, u góry: `center=(WIDTH / 4 - 20, 20)`. Jako rozmiar czcionki (*fontsize*) przyjmiemy wartość $$48$$: `fontsize=48`.

```python
def draw_points():
    screen.draw.text(f"Lewy: {left.points}",
                     color="yellow",
                     center=(WIDTH / 4 - 20, 20),
                     fontsize=48)
```

#### Punkty prawego gracza

Teraz wypiszmy punkty prawego gracza. Postępujmy podobnie, tylko jako pozycję środka tekstu przyjmiemy prawą, górną stronę ekranu: `center=(WIDTH / 2 + WIDTH / 4 - 20, 20)`.

```python
def draw_points():
    screen.draw.text(f"Lewy: {left.points}",
                     color="yellow",
                     center=(WIDTH / 4 - 20, 20),
                     fontsize=48)

    screen.draw.text(f"Prawy: {right.points}",
                     color="yellow",
                     center=(WIDTH / 2 + WIDTH / 4 - 20, 20),
                     fontsize=48)
```

#### Wywołujemy rysowanie punktów

Pozostało nam wywołać naszą funkcję *draw_points* na końcu części rysującej *draw*.

```python
def draw():
    ...

    draw_points()
```

### Zliczamy punkty

Gdy już widzimy punkty na ekranie to możemy przejść do ich zliczania. Punkty będziemy zwiększać, gdy piłka wypadnie z lewej lub prawej strony ekranu. Lewy gracz dostanie punkt, gdy piłka wypadnie z prawej strony, natomiast prawy gracz dostanie punkt, gdy piłka wypadnie z lewej strony.

Zwiększanie punktów dopiszemy w części odpowiadającej za ruch piłki (*move_ball*), zaraz pod instrukcjami sprawdzającymi, czy piłka wypadła poza ekran.

```python
def move_ball():
    ...

    if ball.left <= 0:
        reset_ball()
        right.points += 1

    if ball.right >= WIDTH:
        reset_ball()
        left.points += 1 
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 800
HEIGHT = 600

TITLE = "PONG"

bg_color = (64, 64, 64)

left = Actor("left")
left.x = 20
left.y = HEIGHT / 2
left.vy = 5
# Definiujemy punkty lewej paletki
left.points = 0

right = Actor("right")
right.x = WIDTH - 20
right.y = HEIGHT / 2
right.vy = 5
# Definiujemy punkty prawej paletki
right.points = 0

ball = Actor("ball")
ball.x = WIDTH / 2
ball.y = HEIGHT / 2
ball.vx = 5
ball.vy = 5


def draw():
    screen.fill(bg_color)
    screen.draw.line((WIDTH / 2, 40), (WIDTH / 2, HEIGHT - 40), color = "yellow")
    left.draw()
    right.draw()
    ball.draw()
    # Wypisujemy punkty
    draw_points()


# Pomocnicza funkcja wypisująca na ekranie punkty graczy
def draw_points():
    # Wypisujemy wynik lewego gracza
    screen.draw.text(f"Lewy: {left.points}",
                     color="yellow",
                     center=(WIDTH / 4 - 20, 20),
                     fontsize=48)

    # Wypisujemy wynik prawego gracza
    screen.draw.text(f"Prawy: {right.points}",
                     color="yellow",
                     center=(WIDTH / 2 + WIDTH / 4 - 20, 20),
                     fontsize=48)
    
    
def update():
    move_players()
    move_ball()


def move_players():
    if keyboard.w and left.top > 40:
        left.y -= left.vy

    if keyboard.s and left.bottom < HEIGHT - 40:
        left.y += left.vy

    if keyboard.up and right.top > 40:
        right.y -= right.vy

    if keyboard.down and right.bottom < HEIGHT - 40:
        right.y += right.vy
    

def move_ball():
    ball.x += ball.vx
    ball.y += ball.vy

    if ball.top <= 40:
        ball.vy *= -1

    if ball.bottom >= HEIGHT - 40:
        ball.vy *= -1

    if left.colliderect(ball) and ball.vx < 0:
        ball.vx *= -1

    if right.colliderect(ball) and ball.vx > 0:
        ball.vx *= -1

    if ball.left <= 0:
        reset_ball()
        # Prawy gracz dostaje punkt
        right.points += 1

    if ball.right >= WIDTH:
        reset_ball()
        # Lewy gracz dostaje punkt
        left.points += 1
    

def reset_ball():
    ball.x = WIDTH / 2
    ball.y = HEIGHT / 2
    ball.vx = random.choice([-5, 5])
    ball.vy = random.choice([-5, 5])


pgzrun.go()
```

## Koniec gry

Czas zająć się zakończeniem gry. Gra się zakończy, gdy któryś z graczy uzyska $$11$$ punktów. 

### Zapamiętujemy zwycięzcę 

Zaczniemy od zapamiętania, która z paletek wygrała. W tym celu dopiszemy do lewej i prawej paletki zmienną **win** z początkową wartością **False**. Zmienne dopisujemy odpowiednio pod punktami lewej i prawej paletki: `left.win = False` oraz `right.win = False`.

### Wyświetlamy zwycięzcę

Do wyświetlenia zwycięzcy na ekranie dopiszemy nową funkcję **draw_result**. Dopiszemy ją zaraz pod funkcją *draw_points*.

```python
def draw_result():
```

Najpierw sprawdzimy, czy to lewy gracz jest zwycięzcą.

```python
def draw_result():
    if left.win:
```

Jeżeli tak, to wypisujemy stosowny komunikat na ekranie.

```python
def draw_result():
    if left.win:
        screen.draw.text("LEWY WYGRYWA!!!",
                            color="yellow",
                            center=(WIDTH / 2, HEIGHT / 2),
                            fontsize=96)
```

Teraz sprawdzamy, czy to prawa paletka wygrała.

```python
def draw_result():
    if left.win:
        screen.draw.text("LEWY WYGRYWA!!!",
                            color="yellow",
                            center=(WIDTH / 2, HEIGHT / 2),
                            fontsize=96)
    
    if right.win:
```

Wypisujemy więc stosowny komunikat na ekranie.

```python
def draw_result():
    if left.win:
        screen.draw.text("LEWY WYGRYWA!!!",
                            color="yellow",
                            center=(WIDTH / 2, HEIGHT / 2),
                            fontsize=96)
    
    if right.win:
        screen.draw.text("PRAWY WYGRYWA!!!",
                            color="yellow",
                            center=(WIDTH / 2, HEIGHT / 2),
                            fontsize=96)
```

Teraz przyszła pora na wykorzystanie naszej funkcji. Dopisujemy wywołanie naszej funkcji na końcu części rysującej (*draw*).

```python
def draw():
    ...

    draw_result()
```

### Ustalamy zwycięzcę

Zwycięzcę ustalimy w części przemieszczającej piłkę (*move_ball*) sprawdzając, czy któryś z graczy zdobył $$11$$ punktów. 

Najpierw sprawdzimy, czy prawa paletka uzyskała $$11$$ punktów.

```python
def move_ball():
    ...

    if right.points == 11:
```

Jeżeli tak, to zmieniamy wartość jej zmiennej *win* na **True**.

```python
def move_ball():
    ...

    if right.points == 11:
        right.win = True
```

Podobnie postępujemy z lewą paletką.

```python
def move_ball():
    ...

    if right.points == 11:
        right.win = True

    if left.points == 11:
        left.win = True
```

### Zatrzymanie gry

Gdy któryś z graczy uzyska $$11$$ punktów gra powinna się zatrzymać. W tym celu, w części aktualizującej (*update*) będziemy aktualizować grę tylko wtedy, gdy żaden z graczy jeszcze nie wygrał. Zmieniamy więc implementację funkcji *update*.

W celu sprawdzenia, czy gra wciąż trwa, sprawdzimy, czy nieprawdą jest (**not**), że wygrał gracz lewy (**left.win**) lub (**or**) wygrał gracz prawy (**right.win**).

```python
def update():
    if not (left.win or right.win):
```

Teraz dopisujemy wywołania naszych funkcji.

```python
def update():
    if not (left.win or right.win):
        move_players()
        move_ball()
```

### Pełny kod

Dotychczasowy pełny kod naszej gry przedstawiony jest poniżej.

```python
import pgzrun
import random


WIDTH = 800
HEIGHT = 600

TITLE = "PONG"

bg_color = (64, 64, 64)

left = Actor("left")
left.x = 20
left.y = HEIGHT / 2
left.vy = 5
left.points = 0
# Zapamiętujemy, czy lewa paletka jest zwycięzcą
left.win = False

right = Actor("right")
right.x = WIDTH - 20
right.y = HEIGHT / 2
right.vy = 5
right.points = 0
# Zapamiętujemy, czy prawa paletka jest zwycięzcą
right.win = False

ball = Actor("ball")
ball.x = WIDTH / 2
ball.y = HEIGHT / 2
ball.vx = 5
ball.vy = 5


def draw():
    screen.fill(bg_color)
    screen.draw.line((WIDTH / 2, 40), (WIDTH / 2, HEIGHT - 40), color = "yellow")
    left.draw()
    right.draw()
    ball.draw()
    draw_points()
    # Wypisujemy wynik gry
    draw_result()


def draw_points():
    screen.draw.text(f"Lewy: {left.points}",
                     color="yellow",
                     center=(WIDTH / 4 - 20, 20),
                     fontsize=48)

    screen.draw.text(f"Prawy: {right.points}",
                     color="yellow",
                     center=(WIDTH / 2 + WIDTH / 4 - 20, 20),
                     fontsize=48)


# Pomocnicza funkcja wypisująca na ekranie wynik końca gry
def draw_result():
    # Jeżeli to lewy gracz wygrał
    if left.win:
        screen.draw.text("LEWY WYGRYWA!!!",
                            color="yellow",
                            center=(WIDTH / 2, HEIGHT / 2),
                            fontsize=96)

    # Jeżeli prawy gracz jest zwycięzcą
    if right.win:
        screen.draw.text("PRAWY WYGRYWA!!!",
                            color="yellow",
                            center=(WIDTH / 2, HEIGHT / 2),
                            fontsize=96) 
    

def update():
    # Jeżeli gra nie została jeszcze zakończona
    if not (left.win or right.win):
        move_players()
        move_ball()


def move_players():
    if keyboard.w and left.top > 40:
        left.y -= left.vy

    if keyboard.s and left.bottom < HEIGHT - 40:
        left.y += left.vy

    if keyboard.up and right.top > 40:
        right.y -= right.vy

    if keyboard.down and right.bottom < HEIGHT - 40:
        right.y += right.vy
    

def move_ball():
    ball.x += ball.vx
    ball.y += ball.vy

    if ball.top <= 40:
        ball.vy *= -1

    if ball.bottom >= HEIGHT - 40:
        ball.vy *= -1

    if left.colliderect(ball) and ball.vx < 0:
        ball.vx *= -1

    if right.colliderect(ball) and ball.vx > 0:
        ball.vx *= -1

    if ball.left <= 0:
        reset_ball()
        right.points += 1

    if ball.right >= WIDTH:
        reset_ball()
        left.points += 1

    # Jeżeli prawa paletka uzyskała 11 punktów to wygrywa i gra się kończy
    if right.points == 11:
        right.win = True

    # Jeżeli lewa paletka uzyskała 11 punktów to wygrywa i gra się kończy
    if left.points == 11:
        left.win = True
    

def reset_ball():
    ball.x = WIDTH / 2
    ball.y = HEIGHT / 2
    ball.vx = random.choice([-5, 5])
    ball.vy = random.choice([-5, 5])


pgzrun.go()
```

## Pełna gra

```python
import pgzrun
import random


# Wymiary okna
WIDTH = 800
HEIGHT = 600

# Tytuł gry
TITLE = 'Pong'

# Kolor tła
bg_color = (64, 64, 64)

# Tworzymy aktora lewej paletki
left = Actor("left")
# Określamy początkowe współrzędne lewej paletki na ekranie
left.x = 20
left.y = HEIGHT / 2
# Definiujemy prędkość lewej paletki
left.vy = 5
# Definiujemy punkty lewej paletki
left.points = 0
# Zapamiętujemy, czy lewa paletka jest zwycięzcą
left.win = False

# Tworzymy aktora prawej paletki
right = Actor("right")
# Określamy początkowe współrzędne prawej paletki na ekranie
right.x = WIDTH - 20
right.y = HEIGHT / 2
# Definiujemy prędkość prawej paletki
right.vy = 5
# Definiujemy punkty prawej paletki
right.points = 0
# Zapamiętujemy, czy prawa paletka jest zwycięzcą
right.win = False

# Tworzymy aktora piłki
ball = Actor("ball")
# Określamy początkowe współrzędne piłki
ball.x = WIDTH / 2
ball.y = HEIGHT / 2
# Definiujemy początkową prędkość piłki
ball.vx = 5
ball.vy = 5


def draw():
    # Wypełniamy ekran kolorem tła
    screen.fill(bg_color)
    # Rysujemy linię dzielącą pole gry
    screen.draw.line((WIDTH / 2, 40), (WIDTH / 2, HEIGHT - 40), color="yellow")
    # Rysujemy lewą paletkę
    left.draw()
    # Rysujemy prawą paletkę
    right.draw()
    # Rysujemy piłkę
    ball.draw()
    # Wypisujemy punkty
    draw_points()
    # Wypisujemy wynik gry
    draw_result()


# Pomocnicza funkcja wypisująca na ekranie punkty graczy
def draw_points():
    # Wypisujemy wynik lewego gracza
    screen.draw.text(f"Lewy: {left.points}",
                     color="yellow",
                     center=(WIDTH / 4 - 20, 20),
                     fontsize=48)

    # Wypisujemy wynik prawego gracza
    screen.draw.text(f"Prawy: {right.points}",
                     color="yellow",
                     center=(WIDTH / 2 + WIDTH / 4 - 20, 20),
                     fontsize=48)


# Pomocnicza funkcja wypisująca na ekranie wynik końca gry
def draw_result():
    # Jeżeli to lewy gracz wygrał
    if left.win:
        screen.draw.text("LEWY WYGRYWA!!!",
                            color="yellow",
                            center=(WIDTH / 2, HEIGHT / 2),
                            fontsize=96)

    # Jeżeli prawy gracz jest zwycięzcą
    if right.win: 
        screen.draw.text("PRAWY WYGRYWA!!!",
                            color="yellow",
                            center=(WIDTH / 2, HEIGHT / 2),
                            fontsize=96)


# Aktualizujemy stan gry - ruchy graczy i piłki
def update():
    # Jeżeli gra nie została jeszcze zakończona
    if not (left.win or right.win):
        # Odczytujemy ruchy graczy
        move_players()
        # Poruszamy piłkę
        move_ball()


# Pomocnicza funkcja odczytująca ruchy graczy
def move_players():
    # Lewy gracz porusza się za pomocą klawiszy w i s
    if keyboard.w and left.top > 40:
        left.y -= left.vy

    if keyboard.s and left.bottom < HEIGHT - 40:
        left.y += left.vy

    # Prawy gracz porusza się za pomocą strzałek góra i dół
    if keyboard.up and right.top > 40:
        right.y -= right.vy

    if keyboard.down and right.bottom < HEIGHT - 40:
        right.y += right.vy


# Pomocnicza funkcja obliczająca ruch piłki i przemieszczająca ją
def move_ball():
    # Przemieszczamy piłkę zgodnie z jej prędkością
    ball.x += ball.vx
    ball.y += ball.vy

    # Odbijamy piłkę od górnej ściany
    if ball.top <= 40:
        ball.vy *= -1

    # Odbijamy piłkę od dolnej ściany
    if ball.bottom >= HEIGHT - 40:
        ball.vy *= -1

    # Odbijamy piłkę od lewej paletki
    if left.colliderect(ball) and ball.vx < 0:
        ball.vx *= -1

    # Odpijamy piłkę od prawej paletki
    if right.colliderect(ball) and ball.vx > 0:
        ball.vx *= -1

    # Jeżeli piłka wypadła z lewej strony
    if ball.left <= 0:
        # Resetujemy pozycję piłki
        reset_ball()
        # Prawy gracz dostaje punkt
        right.points += 1

    # Jeżeli piłka wypadła z prawej strony
    if ball.right >= WIDTH:
        # Resetujemy pozycję piłki
        reset_ball()
        # Lewy gracz dostaje punkt
        left.points += 1

    # Jeżeli prawa paletka uzyskała 11 punktów to wygrywa i gra się kończy
    if right.points == 11:
        right.win = True

    # Jeżeli lewa paletka uzyskała 11 punktów to wygrywa i gra się kończy
    if left.points == 11:
        left.win = True


# Pomocnicza funkcja resetująca pozycję piłki
def reset_ball():
    # Określamy początkowe współrzędne piłki
    ball.x = WIDTH / 2
    ball.y = HEIGHT / 2
    # Losowo wybieramy początkową prędkość piłki
    ball.vx = random.choice([-5, 5])
    ball.vy = random.choice([-5, 5])


pgzrun.go()
```

Pełna implementacja dostępna jest również poniżej.

{% embed url="https://github.com/blackbat13/PongPygameZero" %}
Pong
{% endembed %}

<!-- ## Wersja z bonusami

### Pełna gra - wersja z bonusami

```python
import random
import pgzrun
import pygame

WIDTH = 800
HEIGHT = 600

# Tytuł gry
TITLE = 'Pong'

# Główny kolor elementów gry
kolor = 'yellow'
kolor_tla = (64, 64, 64)

# Tworzymy aktorów - lewą paletkę, prawą paletkę i piłkę
# Paletki mają początkową pozycję i wynik
lewa = Actor("lewa.png")
lewa.left = 10
lewa.top = HEIGHT / 2
lewa.wynik = 0

prawa = Actor("prawa.png")
prawa.right = WIDTH - 10
prawa.top = HEIGHT / 2
prawa.wynik = 0

# Piłka ma jeszcze określoną prędkość poruszania się
# A także informację o tym, czy gra została zakończona
pilka = Actor("pilka.png")
pilka.left = WIDTH / 2
pilka.top = HEIGHT / 2
pilka.px = 5
pilka.py = 5
pilka.koniec_gry = False
pilka.czas = 0

bonus = Actor("bonus.png")
bonus.aktywny = False


def draw():
    screen.fill(kolor_tla)

    if lewa.wynik == 11:
        screen.draw.text(
            "LEWY WYGRYWA!!!",
            color=kolor,
            center=(WIDTH / 2, HEIGHT / 2),
            fontsize=96
        )
        pilka.koniec_gry = True
    elif prawa.wynik == 11:
        screen.draw.text(
            "PRAWY WYGRYWA!!!",
            color=kolor,
            center=(WIDTH / 2, HEIGHT / 2),
            fontsize=96
        )
        pilka.koniec_gry = True
    else:
        lewa.draw()
        prawa.draw()
        pilka.draw()

    # Wypisujemy wynik lewego gracza
    screen.draw.text(
        "Lewy: " + str(lewa.wynik),
        color=kolor,
        center=(WIDTH / 4 - 20, 20),
        fontsize=48
    )

    # Wypisujemy wynik prawego gracza
    screen.draw.text(
        'Prawy: ' + str(prawa.wynik),
        color=kolor,
        center=(WIDTH / 2 + WIDTH / 4 - 20, 20),
        fontsize=48
    )

    # Rysujemy linię dzielącą pole gry
    screen.draw.line(
        (WIDTH / 2, 40),
        (WIDTH / 2, HEIGHT - 40),
        color=kolor)

    # Wypisujemy czas gry na ekranie
    screen.draw.text(
        str(pilka.czas),
        color=kolor,
        center=(WIDTH / 2, HEIGHT - 20),
        fontsize=30
    )

    if bonus.aktywny:
        bonus.draw()


# Aktualizujemy stan gry - ruchy graczy i piłki
def update():
    # Jeżeli gra nie została jeszcze zakończona
    if not pilka.koniec_gry:
        # Odczytujemy ruchy graczy
        ruch_graczy()

        # Poruszamy piłkę
        ruch_pilki()


# Odczytujemy ruchy graczy
def ruch_graczy():
    # Prawy gracz porusza się za pomocą strzałek góra i dół
    if keyboard.up:
        if prawa.top - 5 > 40:
            prawa.top -= 5
    elif keyboard.down:
        if prawa.bottom + 5 < HEIGHT - 40:
            prawa.top += 5

    # Lewy gracz porusza się za pomocą klawiszy w i s
    if keyboard.w:
        if lewa.top - 5 > 40:
            lewa.top -= 5
    elif keyboard.s:
        if lewa.bottom + 5 < HEIGHT - 40:
            lewa.top += 5


# Resetujemy pozycję piłki
def resetuj_pilke():
    pilka.left = WIDTH // 2
    pilka.top = HEIGHT // 2
    pilka.px = random.choice([-5, 5])
    pilka.py = random.choice([-5, 5])


# Obliczamy ruch piłki i ją przemieszczamy
def ruch_pilki():
    # Przemieszczamy piłkę zgodnie z jej prędkością
    pilka.left += pilka.px
    pilka.top += pilka.py

    # Odbijamy od ścian - góra i dół
    if pilka.top <= 40:
        pilka.py *= -1

    if pilka.bottom >= HEIGHT - 40:
        pilka.py *= -1

    # Odbijamy od paletek
    if lewa.colliderect(pilka):
        # Aby zapobiec "gliczowaniu" się piłki w paletce, sprawdzamy, czy piłka przekroczyła granicę paletki
        # Jeżeli tak, to ją resetujemy i przyznajemy punkt
        if pilka.x < lewa.x + 12:
            resetuj_pilke()
            prawa.wynik += 1
            return

        # Jeżeli piłka dotyka brzegu paletki, to odbijamy ją ze zwiększoną prędkością
        if abs(pilka.y - (lewa.y - 52)) < 30 or abs(pilka.y - (lewa.y + 52)) < 30:
            pilka.px *= -1.2
        else:
            pilka.px *= -1

    if prawa.colliderect(pilka):
        if pilka.x > prawa.x - 12:
            resetuj_pilke()
            lewa.wynik += 1
            return
        if abs(pilka.y - (prawa.y - 52)) < 30 or abs(pilka.y - (prawa.y + 52)) < 30:
            pilka.px *= -1.2
        else:
            pilka.px *= -1

    # Jeżeli piłka wypadła poza ekran, to jeden z graczy dostaje punkt
    if pilka.left <= 0:
        resetuj_pilke()
        prawa.wynik += 1

    if pilka.right >= WIDTH:
        resetuj_pilke()
        lewa.wynik += 1

    # Jeżeli piłka wpadła na bonus i bonus jest aktywny
    if pilka.colliderect(bonus) and bonus.aktywny:
        # Jeżeli piłka jest po lewej stronie planszy, to lewy gracz dostaje punkt
        if pilka.x < WIDTH / 2:
            lewa.wynik += 1
        else:
            # W przeciwnym wypadku, piłka jest po prawej stronie ekranu i prawy gracz dostaje punkt
            prawa.wynik += 1

        # Dezaktywujemy bonus
        bonus.aktywny = False
        skaluj(pilka, 50, 50)
        clock.schedule(przywroc_pilke, 5.0)


# Aktualizujemy czas przypisany do piłki
def aktualizuj_czas():
    pilka.czas += 1


# Aktualizujemy bonus
def aktualizuj_bonus():
    bonus.x = random.randint(40, WIDTH - 40)
    bonus.y = random.randint(30, HEIGHT - 30)
    bonus.aktywny = True
    clock.schedule(aktualizuj_bonus, random.uniform(3.0, 10.0))


# Skalujemy aktora do nowych wymiarów
def skaluj(aktor, szerokosc, wysokosc):
    aktor._surf = pygame.transform.scale(aktor._surf, (szerokosc, wysokosc))
    aktor._update_pos()


# Przywracamy normalny rozmiar piłki
def przywroc_pilke():
    skaluj(pilka, 22, 22)


# Uruchamiamy aktualizację czasu co jedną sekundę
clock.schedule_interval(aktualizuj_czas, 1.0)
# Pierwszy bonus pojawi się po 5 sekundach
clock.schedule(aktualizuj_bonus, 5.0)
pgzrun.go()

```

## Przeciwko komputerowi

### Pełna gra - wersja gry przeciwko komputerowi

```python
import random
import pgzrun

WIDTH = 800
HEIGHT = 600

# Tytuł gry
TITLE = 'Pong'

# Główny kolor elementów gry
kolor = 'yellow'
kolor_tla = (64, 64, 64)

# Tworzymy aktorów - lewą paletkę, prawą paletkę i piłkę
# Paletki mają początkową pozycję i wynik
lewa = Actor("lewa.png")
lewa.left = 10
lewa.top = HEIGHT / 2
lewa.wynik = 0

prawa = Actor("prawa.png")
prawa.right = WIDTH - 10
prawa.top = HEIGHT / 2
prawa.wynik = 0

# Piłka ma jeszcze określoną prędkość poruszania się
# A także informację o tym, czy gra została zakończona
pilka = Actor("pilka.png")
pilka.left = WIDTH / 2
pilka.top = HEIGHT / 2
pilka.px = 5
pilka.py = 5
pilka.koniec_gry = False


def draw():
    screen.fill(kolor_tla)

    if lewa.wynik == 11:
        screen.draw.text(
            "LEWY WYGRYWA!!!",
            color=kolor,
            center=(WIDTH / 2, HEIGHT / 2),
            fontsize=96
        )
        pilka.koniec_gry = True
    elif prawa.wynik == 11:
        screen.draw.text(
            "PRAWY WYGRYWA!!!",
            color=kolor,
            center=(WIDTH / 2, HEIGHT / 2),
            fontsize=96
        )
        pilka.koniec_gry = True
    else:
        lewa.draw()
        prawa.draw()
        pilka.draw()

    # Wypisujemy wynik lewego gracza
    screen.draw.text(
        "Lewy: " + str(lewa.wynik),
        color=kolor,
        center=(WIDTH / 4 - 20, 20),
        fontsize=48
    )

    # Wypisujemy wynik prawego gracza
    screen.draw.text(
        'Prawy: ' + str(prawa.wynik),
        color=kolor,
        center=(WIDTH / 2 + WIDTH / 4 - 20, 20),
        fontsize=48
    )

    # Eysujemy linię dzielącą pole gry
    screen.draw.line(
        (WIDTH / 2, 40),
        (WIDTH / 2, HEIGHT - 40),
        color=kolor)


# Aktualizujemy stan gry - ruchy graczy i piłki
def update():
    # Jeżeli gra nie została jeszcze zakończona
    if not pilka.koniec_gry:
        # Odczytujemy ruchy graczy
        ruch_graczy()

        # Poruszamy piłkę
        ruch_pilki()


# Odczytujemy ruchy graczy
def ruch_graczy():
    # Prawy gracz porusza się za pomocą strzałek góra i dół
    if keyboard.up:
        if prawa.top - 5 > 40:
            prawa.top -= 5
    elif keyboard.down:
        if prawa.bottom + 5 < HEIGHT - 40:
            prawa.top += 5

    # Lewy gracz porusza się automatycznie
    if lewa.y > pilka.y:
        if lewa.top - 5 > 40:
            lewa.top -= 5
    elif lewa.y < pilka.y:
        if lewa.bottom + 5 < HEIGHT - 40:
            lewa.top += 5


# Resetujemy pozycję piłki
def resetuj_pilke():
    pilka.left = WIDTH // 2
    pilka.top = HEIGHT // 2
    pilka.px = random.choice([-5, 5])
    pilka.py = random.choice([-5, 5])


# Obliczamy ruch piłki i ją przemieszczamy
def ruch_pilki():
    # Przemieszczamy piłkę zgodnie z jej prędkością
    pilka.left += pilka.px
    pilka.top += pilka.py

    # Odbijamy od ścian - góra i dół
    if pilka.top <= 40:
        pilka.py *= -1

    if pilka.bottom >= HEIGHT - 40:
        pilka.py *= -1

    # Odbijamy od paletek
    if lewa.colliderect(pilka):
        pilka.px *= -1

    if prawa.colliderect(pilka):
        pilka.px *= -1

    # Jeżeli piłka wypadła poza ekran, to jeden z graczy dostaje punkt
    if pilka.left <= 0:
        resetuj_pilke()
        prawa.wynik += 1

    if pilka.right >= WIDTH:
        resetuj_pilke()
        lewa.wynik += 1


pgzrun.go()
``` -->