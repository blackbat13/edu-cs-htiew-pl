# Kosmos

## Wstęp

Dzisiaj spróbujemy zasymulować bardziej naturalny ruch w kosmosie.
Zamiast asteroid będziemy walczyć z wrogimi statkami przeciwników, którzy będą za nami podążać i do nas strzelać!
Jak długo uda nam się przetrwać?

### Czego się nauczysz

- Poruszania postacią zgodnie z kierunkiem obrotu.
- Kierowania przeciwników w stronę gracza.
- Śledzenia kolizji wielu elementów gry.
- Podziału kodu na czytelne części.
- Śledzenia czasu gry.

### Grafiki do pobrania

{% file src="../../../.gitbook/assets/grafiki_kosmos.zip" %}
Grafiki do gry Kosmos
{% endfile %}

### Dźwięki do pobrania

{% file src="../../../.gitbook/assets/dzwieki_kosmos.zip" %}
Dźwięki do gry Kosmos
{% endfile %}

### Źródła

- [https://kenney.nl/](https://kenney.nl/)

## Nasz cel

![Kosmos](../../../.gitbook/assets/cosmos.gif)

## Szablon

Tym razem zaczniemy od bardziej rozbudowanego niż zwykle szablonu gry.
Przygotujemy sobie kilka funkcji, które później będziemy uzupełniać właściwą zawartością.
Dzięki temu nasz kod stanie się czytelniejszy, a nasza praca prostsza.

### Biblioteki

Oprócz podstawowych bibliotek *pgzrun* do obsługi gry oraz *random* do liczb losowych, przyda nam się także biblioteka *math* do obliczeń matematycznych, które będą nam potrzebne przy ruchach postaci.

```python
import pgzrun
import random
import math
```

### Konfiguracja

Utworzymy ekran o wymiarach $$1200\times 1200$$. Do tego w opcjach konfiguracyjnych zapamiętamy sobie także margines (**MARGIN**) o wartości $$20$$, którego będziemy używać przy elementach interfejsu.

```python
...

WIDTH = 1200
HEIGHT = 1200
MARGIN = 20
```

### Listy elementów

W naszej grze znajdzie się kilka rodzajów elementów, nie licząc samego gracza. Będą to:

- przeciwnicy (*enemies_list*),
- lasery wystrzelone przez gracza (*player_lasers_list*),
- lasery wystrzelone przez przeciwnika (*enemy_lasers_list*).

Ponieważ tych elementów może być wiele jednocześnie na ekranie, to każdy z typów zapamiętamy w osobnej liście. Na początku do naszych zmiennych przypiszemy pustą listę, czyli puste nawiasy kwadratowe (`[]`).

```python
...

player_lasers_list = []
enemy_lasers_list = []
enemies_list = []
```

### Rysowanie

Jak zwykle będzie nam potrzebna funkcja rysująca zmiany na ekranie (*draw*). Wewnątrz niej wypełnimy ekran czarnym (*black*) kolorem za pomocą funkcji *screen.fill*.

```python
...

def draw():
    screen.fill("black")
```

Poza główną funkcją rysującą przyda nam się także pomocnicza funkcja rysująca wszystkie elementy z podanej listy, ponieważ w naszej grze większość elementów będziemy przechowywać w listach. Stworzymy więc funkcję *draw_list*, która przyjmie jeden parametr: listę elementów do narysowania. Parametr nazwiemy *list* i podamy go w okrągłych nawiasach po nazwie funkcji: *draw_list(list)*.

```python
...

def draw_list(list):
```

Naszą funkcję uzupełnimy później, teraz tworzymy tylko jej szablon, więc dopiszemy do niej instrukcję *pass*.

```python
...

def draw_list(list):
    pass
```

W podobny sposób utworzymy funkcję do rysowania żyć na ekranie, którą nazwiemy *draw_lifes*. Nie będzie ona przyjmować żadnych parametrów. Dopiszemy ją zaraz pod naszą poprzednią funkcją *draw_list*, a wypełnimy jedną instrukcją: *pass*.

```python
...

def draw_lifes():
    pass
```

Możemy też od razu dopisać wywołanie nowej funkcji na końcu funkcji *draw*.

```python
def draw():
    ...
    draw_lifes()
```

### Aktualizacja

Ponieważ w naszej grze będzie wiele elementów, to będziemy musieli wiele rzeczy aktualizować. Aby zapobiec bałaganowi w kodzie, podzielimy sobie aktualizację na następujące funkcje:

- aktualizacja gracza (*update_player*),
- aktualizacja laserów gracza (*update_player_lasers*),
- aktualizacja przeciwników (*update_enemies*),
- aktualizacja laserów przeciwników (*update_enemy_lasers*),
- aktualizacja kolizji (*update_collisions*).

Wszystkie te funkcje wywołamy po kolei w funkcji *update*:

```python
...

def update():
    update_player()
    update_player_lasers()
    update_enemies()
    update_enemy_lasers()
    update_collisions()
```

Teraz pozostało nam stworzyć szablony tych funkcji, zaraz pod funkcją *update*, wszystkie z jedną instrukcją: *pass*.

```python
...

def update_player():
    pass


def update_player_lasers():
    pass


def update_enemies():
    pass


def update_enemy_lasers():
    pass


def update_collisions():
    pass
```

### Zdarzenia

Potrzebna nam będzie także funkcja odczytująca wciśnięcie klawisza na klawiaturze, z której skorzystamy w przypadku strzelania. W tym celu dopisujemy funkcję `on_key_down(key)`, podobnie jak wcześniej z instrukcją *pass*.

```python
...

def on_key_down(key):
    pass
```

### Funkcje pomocnicze

Przydadzą nam się jeszcze trzy funkcje pomocnicze:

- dodanie nowego przeciwnika (*add_enemy*),
- wybranie pozycji startowej dla przeciwnika i asteroidy (*choose_position*),
- zwiększenie licznika czas (*add_time*).

Podobnie jak wcześniej, funkcje stworzymy jako szablony i wypełnimy jedynie instrukcją *pass*.

```python
...
def add_enemy():
    pass


def choose_position():
    pass


def add_time():
    pass
```

### Uruchomienie gry

Pozostało nam na samym dole naszego kodu dopisać instrukcję uruchamiającą grę.

```python
...

pgzrun.go()
```

### Pełny kod

```python
import pgzrun
import random
import math

WIDTH = 1200
HEIGHT = 1200
MARGIN = 20

player_lasers_list = []
enemy_lasers_list = []
enemies_list = []


def draw():
    screen.fill("black")
    draw_lifes()


def draw_list(list):
    pass


def draw_lifes():
    pass


def update():
    update_player()
    update_player_lasers()
    update_enemies()
    update_enemy_lasers()
    update_collisions()


def update_player():
    pass


def update_player_lasers():
    pass


def update_enemies():
    pass


def update_enemy_lasers():
    pass


def update_collisions():
    pass


def on_key_down(key):
    pass


def add_enemy():
    pass


def choose_position():
    pass


def add_time():
    pass


pgzrun.go()
```

## Gracz

Naszym graczem będzie statek kosmiczny, podobnie jak w poprzedniej grze *Asteroidy*. Tym razem zapiszemy go w zmiennej *player* i utworzymy na podstawie grafiki *player.png*. Naszego nowego aktora dopisujemy zaraz pod wymiarami okna i marginesem.

```python
player = Actor("player")
```

Początkowo umieścimy gracza na środku ekranu.

```python
...
player.x = WIDTH / 2
player.y = HEIGHT / 2
``` 

Teraz możemy narysować naszego gracza na ekranie. Instrukcję rysującą dopiszemy w funkcji *draw* zaraz pod wypełnieniem ekranu kolorem tła, a przed wywołaniem funkcji rysującej życia, tak by były one zawsze widoczne.

```python
def draw():
    ...
    player.draw()
    ...
```

### Poruszamy statkiem

Przejdźmy teraz do ruchu gracza. Będziemy go przemieszczać zgodnie z jego kierunkiem obrotu proporcjonalnie do prędkości. Na początku dopiszmy prędkość (*v*) do naszego gracza, z początkową wartością $$2$$, zaraz pod jego współrzędnymi.

```python
player.v = 2
```

Ruch gracza zrealizujemy wewnątrz naszej funkcji *update_player*, dlatego usuwamy z niej instrukcję *pass*.

```python
def update_player():
```

Do obliczenia ruchu gracza wykorzystamy matematyczną formułę opartą na trygonometrii:

$$
x += \sin(angle) * v
y += \cos(angle) * v
$$

Gdzie *angle* to kąt obrotu gracza, a *v* to jego prędkość. Musimy jednak dostosować funkcję do naszych warunków. Do obliczenia sinusa i cosinusa wykorzystamy odpowiednie funkcji z biblioteki *math*: `math.sin` oraz `math.cos`. Funkcje te jednak przyjmują kąt w **radianach**, a nie stopniach. Kąt obrotu gracza zapisany jest w zmiennej *player.angle* i podany jest w stopniach. Dlatego musimy zamienić stopnie na radiany za pomocą funkcji `math.radians`. Zanim to jednak zrobimy, musimy odpowiednio zmodyfikować ten kąt, ponieważ na naszej grafice statek skierowany jest do góry, a *Pygame Zero* domyślnie traktuje aktorów tak, jakby byli skierowani w prawo. Dlatego od kąta obrotu gracza odejmiemy połowę pełnego obrotu, czyli $$180$$.

```python
def update_player():
    player.x += math.sin(math.radians(player.angle - 180)) * player.v
    player.y += math.cos(math.radians(player.angle - 180)) * player.v
```

### Obracamy statek

Czas zająć się obrotem gracza. Obracać będziemy go na klawisze **A** oraz **D** zgodnie z prędkością obrotu, którą najpierw musimy do gracza dopisać. Dopisujemy więc nową zmienną do gracza, zaraz pod jego prędkością. Nazwiemy ją **va** (*a* od *angle*) i ustawimy jej początkową wartość $$2$$.

```python
player.va = 2
```

Przejdźmy teraz do obsługi samego obrotu. Nowe instrukcje dopiszemy na końcu funkcji *update_player*. Zacznijmy od obrotu w lewo. Jeżeli wciśnięty jest klawisz **A** (*if keyboard.A*), to obracamy gracza przeciwnie do ruchu wskazówek zegara zgodnie z jego prędkością obrotu (*player.va*). W tym celu dodajemy prędkość obrotu do kąta gracza (*player.angle*).

```python
def update_player():
    ...

    if keyboard.A:
        player.angle += player.va
```

Podobnie postępujemy przy obrocie zgodnie ze wskazówkami zegara, gdy naciśnięty jest klawisz **D**. Tym razem odejmujemy prędkość obrotu od kąta gracza.

```python
def update_player():
    ...

    if keyboard.D:
        player.angle -= player.va
```

### Przyspieszamy statek

Nasz statek powinien mieć jakieś przyspieszenie, żeby gra była ciekawsza. W tym celu dopiszemy do gracza zmienną *ac* (*acceleration*), która będzie oznaczała wartość przyspieszenia. Nową zmienną dopisujemy pod prędkością obrotu i nadajemy jej wartość $$0.2$$.

```python
player.ac = 0.2
```

Dopiszemy jeszcze prędkość maksymalną, którą zapiszemy w graczu w zmiennej *maxv* z początkową wartością $$8$$.

```python
player.ac = 0.2
player.maxv = 8
```

Wracamy teraz do funkcji *update_player* i dopisujemy instrukcje na jej końcu. Gdy naciśnięty będzie klawisz **W**, to gracz powinien przyspieszać, nie przekraczając jednak swojej maksymalnej prędkości. Aby zwiększyć prędkość gracza (*player.v*) dodamy do niej jego przyspieszenie (*player.ac*).

```python
def update_player():
    ...

    if keyboard.W:
        player.v += player.ac
```

Następnie powinniśmy sprawdzić, czy prędkość nie przekroczyła prędkości maksymalnej (*player.maxv*). Jeżeli tak się stanie, to powinniśmy przywrócić prędkość maksymalną, tzn. do prędkości przypisać prędkość maksymalną.

```python
def update_player():
    ...

    if keyboard.W:
        player.v += player.ac
        if player.v > player.maxv:
            player.v = player.maxv
```

Podobnie postąpimy w przypadku zwalniania, gdy wciśnięty jest klawisz **S**. Najpierw zmniejszymy prędkość gracza odejmując od niej przyspieszenie.

```python
def update_player():
    ...

    if keyboard.S:
        player.v -= player.ac
```

Następnie sprawdzimy, czy prędkość spadła poniżej zera. Jeżeli tak, to przywrócimy prędkości wartość zero.

```python
def update_player():
    ...

    if keyboard.S:
        player.v -= player.ac
        if player.v < 0:
            player.v = 0
```

### Przechodzimy przez krawędzie ekranu

```python
def update_player():
    ...

    if player.x > WIDTH + MARGIN:
        player.x = -MARGIN
```

```python
def update_player():
    ...

    if player.x < -MARGIN:
        player.x = WIDTH + MARGIN
```

```python
def update_player():
    ...

    if player.y < -MARGIN:
        player.y = HEIGHT + MARGIN
```

```python
def update_player():
    ...

    if player.y > HEIGHT + MARGIN:
        player.y = -MARGIN
```

Pełny fragment odpowiedzialny za przechodzenie przez krawędzie ekranu przedstawiony jest poniżej.

```python
def update_player():
    ...
    
    if player.x > WIDTH + MARGIN:
        player.x = -MARGIN

    if player.x < -MARGIN:
        player.x = WIDTH + MARGIN

    if player.y < -MARGIN:
        player.y = HEIGHT + MARGIN

    if player.y > HEIGHT + MARGIN:
        player.y = -MARGIN
```

### Pełny kod

```python
import pgzrun
import random
import math

WIDTH = 1200
HEIGHT = 1200
MARGIN = 20

player = Actor("player")
player.x = WIDTH / 2
player.y = HEIGHT / 2
player.v = 2
player.va = 2
player.ac = 0.2
player.maxv = 8

player_lasers_list = []
enemy_lasers_list = []
enemies_list = []


def draw():
    screen.fill("black")
    player.draw()
    draw_lifes()


def draw_list(list):
    pass


def draw_lifes():
    pass


def update():
    update_player()
    update_player_lasers()
    update_enemies()
    update_enemy_lasers()
    update_collisions()


def update_player():
    player.x += math.sin(math.radians(player.angle - 180)) * player.v
    player.y += math.cos(math.radians(player.angle - 180)) * player.v

    if keyboard.A:
        player.angle += player.va

    if keyboard.D:
        player.angle -= player.va
    
    if keyboard.W:
        player.v += player.ac
        if player.v > player.maxv:
            player.v = player.maxv

    if keyboard.S:
        player.v -= player.ac
        if player.v < 0:
            player.v = 0

    if player.x > WIDTH + MARGIN:
        player.x = -MARGIN

    if player.x < -MARGIN:
        player.x = WIDTH + MARGIN

    if player.y < -MARGIN:
        player.y = HEIGHT + MARGIN

    if player.y > HEIGHT + MARGIN:
        player.y = -MARGIN


def update_player_lasers():
    pass


def update_enemies():
    pass


def update_enemy_lasers():
    pass


def update_collisions():
    pass


def on_key_down(key):
    pass


def add_enemy():
    pass


def choose_position():
    pass


def add_time():
    pass


pgzrun.go()
```

## Strzelamy

Czas zająć się strzelaniem, które zrealizujemy podobnie, jak w przypadku naszej poprzedniej gry *Asteroidy*.

### Dodajemy laser

Strzały będziemy oddawać po naciśnięciu spacji. Dlatego zajmiemy się teraz naszą funkcją *on_key_down*, z której usuwamy instrukcję *pass*. Na początku sprawdzimy, czy został wciśnięty klawisz spacji porównując zmienną *key* z wartością `keys.SPACE`.

```python
def on_key_down(key):
    if key == keys.SPACE:
```

Jeżeli rzeczywiście kliknęliśmy spację, to czas utworzyć nowego aktora na podstawie grafiki *laser1.png*. Zapiszemy go w zmiennej *laser*.

```python
def on_key_down(key):
    if key == keys.SPACE:
        laser = Actor("laser1")
```

Jego pozycję ustawimy na taką samą, jak pozycja gracza (*player.pos*).

```python
def on_key_down(key):
    if key == keys.SPACE:
        laser = Actor("laser1")
        laser.pos = player.pos
```

Podobnie postąpimy z kątem obrotu (*angle*).

```python
def on_key_down(key):
    if key == keys.SPACE:
        laser = Actor("laser1")
        laser.pos = player.pos
        laser.angle = player.angle
```

Zdefiniujemy także prędkość (*v*) i ustawimy ją na $$10$$, tak by zawsze laser był szybszy od statku.

```python
def on_key_down(key):
    if key == keys.SPACE:
        laser = Actor("laser1")
        laser.pos = player.pos
        laser.angle = player.angle
        laser.v = 10
```

Nasz laser jest gotowy, dopisujemy go więc do listy laserów gracza za pomocą metody **append**.

```python
def on_key_down(key):
    if key == keys.SPACE:
        laser = Actor("laser1")
        laser.pos = player.pos
        laser.angle = player.angle
        laser.v = 10
        player_lasers_list.append(laser)
```

Na końcu warto jeszcze odtworzyć dźwięk *laser1*.

```python
def on_key_down(key):
    if key == keys.SPACE:
        laser = Actor("laser1")
        laser.pos = player.pos
        laser.angle = player.angle
        laser.v = 10
        player_lasers_list.append(laser)
        sounds.laser1.play()
```

### Rysujemy lasery

Zacznijmy od uzupełnienia naszej funkcji *draw_list* rysującej wszystkie elementy listy na ekranie.

```python
def draw_list(list):
    for element in list:
        element.draw()
```

Teraz pozostało nam w części rysującej *draw* wywołać naszą funkcję z parametrem *player_lasers_list*, by narysować wszystkie lasery gracza na ekranie. Ponieważ nie chcemy, by lasery przykrywały grafikę gracza, to narysujemy je przed graczem, czyli przed instrukcją *player.draw()*.

```python
def draw():
    ...
    draw_list(player_lasers_list)
    ...
```

### Poruszamy laserami

Poruszanie laserami gracza zrealizujemy w naszej pomocniczej funkcji *update_player_lasers*, z której usuwamy instrukcję *pass*. Ponieważ mamy wiele laserów zapisanych w liście, to zaczniemy od pętli przechodzącej przez **kopię** listy laserów (`player_lasers_list[:]`), ponieważ będziemy je usuwać z listy, gdy wyjdą poza ekran gry.

```python
def update_player_lasers():
    for laser in player_lasers_list[:]:
```

Każdy laser będziemy przemieszczać zgodnie z jego kierunkiem obrotu proporcjonalnie do jego prędkości. Wykorzystamy tę samą formułę, co w przypadku ruchu gracza.

```python
def update_player_lasers():
    for laser in player_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v
```

Teraz pozostało nam sprawdzić, czy laser opuścił już ekran gry. Porównujemy więc jego współrzędne z rozmiarami okna gry zmodyfikowanymi o margines.

```python
def update_player_lasers():
    for laser in player_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v
    if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
```

Jeżeli laser opuści ekran gry, to usuwamy go z listy laserów za pomocą metody **remove**.

```python
def update_player_lasers():
    for laser in player_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            player_lasers_list.remove(laser)
```

### Pełny kod

```python
import pgzrun
import random
import math

WIDTH = 1200
HEIGHT = 1200
MARGIN = 20

player = Actor("player")
player.x = WIDTH / 2
player.y = HEIGHT / 2
player.v = 2
player.va = 2
player.ac = 0.2
player.maxv = 8

player_lasers_list = []
enemy_lasers_list = []
enemies_list = []


def draw():
    screen.fill("black")
    draw_list(player_lasers_list)
    player.draw()
    draw_lifes()


def draw_list(list):
    for element in list:
        element.draw()


def draw_lifes():
    pass


def update():
    update_player()
    update_player_lasers()
    update_enemies()
    update_enemy_lasers()
    update_collisions()


def update_player():
    player.x += math.sin(math.radians(player.angle - 180)) * player.v
    player.y += math.cos(math.radians(player.angle - 180)) * player.v

    if keyboard.A:
        player.angle += player.va

    if keyboard.D:
        player.angle -= player.va
    
    if keyboard.W:
        player.v += player.ac
        if player.v > player.maxv:
            player.v = player.maxv

    if keyboard.S:
        player.v -= player.ac
        if player.v < 0:
            player.v = 0

    if player.x > WIDTH + MARGIN:
        player.x = -MARGIN

    if player.x < -MARGIN:
        player.x = WIDTH + MARGIN

    if player.y < -MARGIN:
        player.y = HEIGHT + MARGIN

    if player.y > HEIGHT + MARGIN:
        player.y = -MARGIN


def update_player_lasers():
    for laser in player_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            player_lasers_list.remove(laser)


def update_enemies():
    pass


def update_enemy_lasers():
    pass


def update_collisions():
    pass


def on_key_down(key):
    if key == keys.SPACE:
        laser = Actor("laser1")
        laser.pos = player.pos
        laser.angle = player.angle
        laser.v = 10
        player_lasers_list.append(laser)
        sounds.laser1.play()


def add_enemy():
    pass


def choose_position():
    pass


def add_time():
    pass


pgzrun.go()
```

## Przeciwnicy

Skoro możemy już strzelać, to czas zająć się przeciwnikami.

### Dodajemy przeciwników

Zacznijmy od dodawania przeciwników. W tym celu będziemy edytować funkcję *update_enemies*, z której usuwamy instrukcję *pass*. Naszych przeciwników będziemy dodawać w sposób losowy. Dlatego skorzystamy z metody **random.random()**, która losuje liczbę rzeczywistą z przedziału $$<0,1)$$. Jeżeli wylosowana wartość będzie mniejsza od jakiejś małej liczby, np. $$0.01$$, to dodamy nowego przeciwnika wywołując funkcję *add_enemy*.

```python
def update_enemies():
    if random.random() < 0.01:
        add_enemy()
```

Oczywiście nasza funkcja *add_enemy* nie została jeszcze zaimplementowana, ale tym się właśnie zajmiemy. Najpierw usuwamy z niej instrukcję *pass*. Na początku stworzymy nowego aktora z grafiki *enemy.png*, którego zapiszemy w zmiennej *enemy*.

```python
def add_enemy():
    enemy = Actor("enemy")
```

Teraz czas ustalić pozycję naszego nowego przeciwnika. W tym celu do jego zmiennej *pos* przypiszemy wartość zwróconą przez funkcję *choose_position* (którą zajmiemy się za chwilę).

```python
def add_enemy():
    enemy = Actor("enemy")
    enemy.pos = choose_position()
```

Pora na prędkość (*v*). Możemy ją ustalić jako losową wartość całkowitą (*random.randint*) z wybranego przedziału, np. $$<2,5>$$.

```python
def add_enemy():
    enemy = Actor("enemy")
    enemy.pos = choose_position()
    enemy.v = random.randint(2, 5)
```

Na koniec dopisujemy naszego przeciwnika do listy przeciwników *enemies_list* korzystając z metody *append*.

```python
def add_enemy():
    enemy = Actor("enemy")
    enemy.pos = choose_position()
    enemy.v = random.randint(2, 5)
    enemies_list.append(enemy)
```

### Losujemy pozycję

Zajmijmy się teraz losowaniem startowej pozycji dla naszych przeciwników, a później także dla asteroid. W tym celu edytujemy funkcję *choose_position* i usuwamy z niej instrukcję *pass*. Pozycję będziemy losować w taki sposób, aby nowy element pojawił się poza granicami ekranu, po lewej, prawej, u góry lub u dołu. Zrobimy to w ten sposób, że najpierw wylosujemy wartość całkowitą z przedziału $$<1,2>$$. Jeżeli wylosujemy $$1$$, to umieścimy przeciwnika z lewej lub prawej strony. W przeciwnym przypadku umieścimy go u góry lub u dołu. Zaczynamy od instrukcji warunkowej sprawdzającej, czy wylosowaliśmy $$1$$.

```python
def choose_position():
    if random.randint(1, 2) == 1:
```

Jeżeli tak, to współrzędna $$x$$ powinna znajdować się z lewej lub prawej strony ekranu, zachowując przy tym odpowiedni margines. Mamy więc do dyspozycji dwie wartości: `-MARGIN` lub `WIDTH + MARGIN`. Aby wybrać pomiędzy nimi skorzystamy z funkcji *random.choice*, do której jako parametr podamy te dwie wartości w postaci listy, czyli zapisane w nawiasach kwadratowych. Wynik przypiszemy do nowej zmiennej **x**.

```python
def choose_position():
    if random.randint(1, 2) == 1:
        x = random.choice([-MARGIN, WIDTH + MARGIN])
```

Teraz czas wylosować drugą współrzędną, *y*. Jej wartość powinna zawierać się w przedziale **<MARGIN, HEIGHT-MARGIN>**, tak aby element po przemieszczeniu się na ekran w prawo lub w lewo znajdować się wewnątrz ekranu gry, a nie poza nim. Tworzymy więc nową zmienną **y** i przypisujemy do niej wylosowaną wartość całkowitą z podanego przedziału.

```python
def choose_position():
    if random.randint(1, 2) == 1:
        x = random.choice([-MARGIN, WIDTH + MARGIN])
        y = random.randint(MARGIN, HEIGHT - MARGIN)
```

Teraz czas zająć się przeciwnym przypadkiem, dopisujemy więc instrukcję *else*.

```python
def choose_position():
    if random.randint(1, 2) == 1:
        x = random.choice([-MARGIN, WIDTH + MARGIN])
        y = random.randint(MARGIN, HEIGHT - MARGIN)
    else:
```

Postąpimy podobnie jak wcześniej. Tym razem jednak to współrzędna *y* będzie losowana z dwóch wartości `-MARGIN` lub `HEIGHT + MARGIN`, a współrzędna *x* z przedziału **<MARGIN, WIDTH-MARGIN>**. Zacznijmy od utworzenia zmiennej **x**.

```python
def choose_position():
    if random.randint(1, 2) == 1:
        x = random.choice([-MARGIN, WIDTH + MARGIN])
        y = random.randint(MARGIN, HEIGHT - MARGIN)
    else:
        x = random.randint(MARGIN, WIDTH - MARGIN)
```

Teraz czas na **y**.

```python
def choose_position():
    if random.randint(1, 2) == 1:
        x = random.choice([-MARGIN, WIDTH + MARGIN])
        y = random.randint(MARGIN, HEIGHT - MARGIN)
    else:
        x = random.randint(MARGIN, WIDTH - MARGIN)
        y = random.choice([-MARGIN, HEIGHT + MARGIN])
```

Na koniec, gdy już wyjdziemy z instrukcji warunkowej z wylosowanymi współrzędnymi, powinniśmy je zwrócić jako wynik działania naszej funkcji. W tym celu dopisujemy instrukcję **return**, a po niej dwie zmienne, oddzielone przecinkiem: para współrzędnych **x** oraz **y**.

```python
def choose_position():
    if random.randint(1, 2) == 1:
        x = random.choice([-MARGIN, WIDTH + MARGIN])
        y = random.randint(MARGIN, HEIGHT - MARGIN)
    else:
        x = random.randint(MARGIN, WIDTH - MARGIN)
        y = random.choice([-MARGIN, HEIGHT + MARGIN])

    return x, y
```

### Rysujemy przeciwników

Mamy już przeciwników, pora więc ich narysować. W funkcji rysującej *draw* dopisujemy instrukcję `draw_list(enemies_list)` zaraz pod narysowaniem listy laserów gracza.

```python
def draw():
    ...
    draw_list(enemies_list)
    ...
```

### Poruszamy przeciwnikami

Nasi przeciwnicy są jeszcze statyczni, więc nie zobaczymy ich na ekranie, ponieważ pojawiają się poza nim i się nie ruszają. Dlatego zajmijmy się ich ruchem. W tym celu edytujemy funkcję *update_enemies*, dopisując nowe instrukcje na koniec. Ponieważ chcemy poruszać **wszystkimi** przeciwnikami, to zaczniemy od pętli iteracyjnej przechodzącej przez draw_list(enemies_list) przeciwnika na liście *enemies_list*.

```python
def update_enemies():
    ...

    for enemy in enemies_list:
```

Przeciwnicy będą się poruszać w kierunku gracza. W tym celu musimy ich najpierw odwrócić we właściwą stronę. Z pomocą przyjdzie nam metoda **enemy.angle_to** do której jako parametr podamy pozycję gracza (*player.pos*), a wynik przypiszemy do zmiennej *angle* przeciwnika.

```python
def update_enemies():
    ...

    for enemy in enemies_list:
        enemy.angle = enemy.angle_to(player.pos)
```

Ze względu na grafikę przeciwników od kąta musimy jeszcze odjąć $$90$$ stopni, by rzeczywiście byli skierowani we właściwą stronę.

```python
def update_enemies():
    ...

    for enemy in enemies_list:
        enemy.angle = enemy.angle_to(player.pos) - 90
```

Teraz czas ich poruszyć zgodnie z ich kątem obrotu proporcjonalnie do prędkości. Korzystamy z tego samego wzoru co przy ruchu gracza i jego laserów.

```python
def update_enemies():
    ...

    for enemy in enemies_list:
        enemy.angle = enemy.angle_to(player.pos) - 90
        enemy.x += math.sin(math.radians(enemy.angle - 180)) * enemy.v
        enemy.y += math.cos(math.radians(enemy.angle - 180)) * enemy.v
```

### Sprawdzamy trafienia w przeciwników

Zajmijmy się teraz kwestią zestrzelenia przeciwnika. Aby sprawdzić, czy trafiliśmy w przeciwnika, musimy sprawdzić, czy laser i przeciwnik są w kolizji. Mamy jednak wiele laserów i wielu przeciwników, jak więc się do tego zabrać? Idea jest prosta: będziemy sprawdzać każdą parę laser-przeciwnik. W ten sposób, jeżeli **którykolwiek** laser trafił w **któregokolwiek** przeciwnika, to będziemy w stanie to wykryć.

Naszymi kolizjami zajmiemy się wewnątrz funkcji *update_collisions*, z której usuwamy instrukcję *pass*. Na początku przejdziemy przez wszystkie lasery na **kopii** listy laserów. Potrzebujemy kopii listy, ponieważ będziemy usuwać lasery po trafieniu.

```python
def update_collisions():
    for laser in player_lasers_list[:]:
```

Teraz czas przejść przez wszystkich przeciwników na **kopii** listy przeciwników, ponieważ ich także będziemy usuwać.

```python
def update_collisions():
    for laser in player_lasers_list[:]:
        for enemy in enemies_list[:]:
```

Mamy więc już parę laser-przeciwnik, możemy więc sprawdzić, czy są w kolizji, korzystając z metody *colliderect*.

```python
def update_collisions():
    for laser in player_lasers_list[:]:
        for enemy in enemies_list[:]:
            if enemy.colliderect(laser):
```

Jeżeli trafiliśmy w przeciwnika, to usuwamy go z listy *enemies_list* za pomocą metody *remove*.

```python
def update_collisions():
    for laser in player_lasers_list[:]:
        for enemy in enemies_list[:]:
            if enemy.colliderect(laser):
                enemies_list.remove(enemy)
```

Podobnie robimy z laserem, usuwając go z listy *player_lasers_list*.

```python
def update_collisions():
    for laser in player_lasers_list[:]:
        for enemy in enemies_list[:]:
            if enemy.colliderect(laser):
                enemies_list.remove(enemy)
                player_lasers_list.remove(laser)
```

Na koniec dodajemy instrukcję **break**, tak by wyjść z pętli przechodzącej przez przeciwników i przejść do kolejnego obrotu pętli z laserami. Dzięki temu raz usunięty laser nie będzie mógł już zlikwidować innych przeciwników.

```python
def update_collisions():
    for laser in player_lasers_list[:]:
        for enemy in enemies_list[:]:
            if enemy.colliderect(laser):
                enemies_list.remove(enemy)
                player_lasers_list.remove(laser)
                break
```

### Sprawdzamy zderzenia z przeciwnikami

Nasi przeciwnicy nie tylko będą strzelać laserami (tym zajmiemy się za chwilę), ale będą stanowić także zagrożenie kolizyjne. Gdy zderzymy się z przeciwnikiem, ten zostanie zniszczony, ale my stracimy życie. Zanim jednak przejdziemy to utraty żyć, musimy je dopisać do naszego gracza. Zapiszemy je w zmiennej *lifes* gracza i nadamy początkową wartość $$3$$. Życia dopisujemy zaraz pod maksymalną prędkością.

```python
player.lifes = 3
```

Przejdźmy teraz do kolizji z przeciwnikami. Nowe instrukcje dopiszemy na **koniec** funkcji *update_collisions*. Na początku przejdziemy pętlą iteracyjną przez wszystkich przeciwników na **kopii** listy (ponieważ będziemy ich usuwać), by sprawdzić, czy któryś się z nami zderzył.

```python
def update_collisions():
    ...

    for enemy in enemies_list[:]:
```

Teraz możemy sprawdzić, czy doszło do kolizji. Aby gra była bardziej grywalna i kolizje nie były wykrywane gdy tylko prostokąty reprezentujące grafiki postaci się dotkną, tym razem skorzystamy z metody **collidepoint**. Wykonamy ją na graczu, a jako parametr podamy pozycję przeciwnika (*enemy.pos*). Dzięki temu kolizja zostanie wykryta tylko wtedy, gdy środek przeciwnika znajdzie się wewnątrz prostokąta reprezentującego grafikę gracza.

```python
def update_collisions():
    ...

    for enemy in enemies_list[:]:
        if player.collidepoint(enemy.pos):
```

W przypadku wykrycia kolizji usuwamy przeciwnika z listy przeciwników.

```python
def update_collisions():
    ...

    for enemy in enemies_list[:]:
        if player.collidepoint(enemy.pos):
            enemies_list.remove(enemy)
```

Zmniejszamy także liczbę żyć gracza o jeden.

```python
def update_collisions():
    ...

    for enemy in enemies_list[:]:
        if player.collidepoint(enemy.pos):
            enemies_list.remove(enemy)
            player.lifes -= 1
```

Jeżeli życia gracza spadną do zera, to gra się zakończy i zostanie odtworzony dźwięk *game_over*. W tym celu sprawdzamy, czy gracz ma już zero żyć.

```python
def update_collisions():
    ...

    for enemy in enemies_list[:]:
        if player.collidepoint(enemy.pos):
            enemies_list.remove(enemy)
            player.lifes -= 1
            if player.lifes == 0:
```

Jeżeli tak, to odtwarzamy dźwięk *game_over*.

```python
def update_collisions():
    ...

    for enemy in enemies_list[:]:
        if player.collidepoint(enemy.pos):
            enemies_list.remove(enemy)
            player.lifes -= 1
            if player.lifes == 0:
                sounds.game_over.play()
```

### Strzelamy laserami

Nasi przeciwnicy także powinni strzelać laserami. Dlatego wewnątrz pętli, którą przed chwilą stworzyliśmy, dopiszemy nowe instrukcje na sam koniec, ponieważ chcemy, by **każdy** przeciwnik mógł strzelać. Strzały będziemy oddawać losowo, podobnie jak zrobiliśmy z dodawaniem nowych przeciwników. Dlatego zaczynamy od instrukcji warunkowej. Jako warunek sprawdzimy, czy wylosowana liczba rzeczywista jest odpowiednio mała, np. mniejsza od $$0.005$$.

```python
def update_enemies():
    ...

    for enemy in enemies:
        ...

        if random.random() < 0.005:
```

Jeżeli tak, do tworzymy nowego aktora z grafiki *laser2.png* i zapisujemy go w zmiennej *laser*.

```python
def update_enemies():
    ...

    for enemy in enemies:
        ...

        if random.random() < 0.005:
            laser = Actor("laser2")
```

Naszemu laserowi nadajemy taką samą pozycję (*laser.pos*) jak pozycja przeciwnika (*enemy.pos*).

```python
def update_enemies():
    ...

    for enemy in enemies:
        ...

        if random.random() < 0.005:
            laser = Actor("laser2")
            laser.pos = enemy.pos
```

Podobnie postępujemy z kątem (*angle*).

```python
def update_enemies():
    ...

    for enemy in enemies:
        ...

        if random.random() < 0.005:
            laser = Actor("laser2")
            laser.pos = enemy.pos
            laser.angle = enemy.angle
```

Jeżeli chodzi o prędkość (*laser.v*), to możemy wylosować liczbę całkowitą z wybranego przedziału, np. $$<5,10>$$.

```python
def update_enemies():
    ...

    for enemy in enemies:
        ...

        if random.random() < 0.005:
            laser = Actor("laser2")
            laser.pos = enemy.pos
            laser.angle = enemy.angle
            laser.v = random.randint(5, 10)
```

Teraz możemy już dodać nasz laser do listy laserów przeciwnika (*enemy_lasers_list*).

```python
def update_enemies():
    ...

    for enemy in enemies:
        ...

        if random.random() < 0.005:
            laser = Actor("laser2")
            laser.pos = enemy.pos
            laser.angle = enemy.angle
            laser.v = random.randint(5, 10)
            enemy_lasers_list.append(laser)
```

Warto także odtworzyć dźwięk *laser2*.

```python
def update_enemies():
    ...

    for enemy in enemies:
        ...

        if random.random() < 0.005:
            laser = Actor("laser2")
            laser.pos = enemy.pos
            laser.angle = enemy.angle
            laser.v = random.randint(5, 10)
            enemy_lasers_list.append(laser)
            sounds.laser2.play()
```

### Rysujemy lasery

Mamy już lasery, czas je więc narysować. Wewnątrz funkcji *draw* dopisujemy instrukcję `draw_list(enemy_lasers_list)` zaraz **przed** narysowaniem przeciwników, aby lasery były pod nimi schowane.

```python
def draw():
    ...
    draw_list(enemy_lasers_list)
    ...
```

### Poruszamy laserami

Nasze lasery są statyczne, pora więc się tym zająć. Będziemy modyfikować funkcję *update_enemy_lasers*, z której usuwamy instrukcję *pass*. Chcemy przemieszczać **wszystkie** lasery Na początku przejdziemy pętlą przez wszystkie lasery na **kopii** listy laserów przeciwnika (*enemy_lasers_list*). Potrzebujemy kopii listy, ponieważ będziemy usuwać lasery po opuszczeniu ekranu gry.

```python
def update_enemy_lasers():
    for laser in enemy_lasers_list[:]:
```

Przemieszczamy laser zgodnie z jego kierunkiem obrotu, identycznie jak to zrobiliśmy z laserami gracza.

```python
def update_enemy_lasers():
    for laser in enemy_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v
```

Teraz pora sprawdzić, czy laser opuścił ekran gry, uwzględniając przy tym margines. Postępujemy tutaj tak samo, jak przy laserach gracza.

```python
def update_enemy_lasers():
    for laser in enemy_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
```

Jeżeli tak się stało, to usuwamy laser z listy laserów przeciwnika.

```python
def update_enemy_lasers():
    for laser in enemy_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            enemy_lasers_list.remove(laser)
```

### Sprawdzamy kolizje

Mamy już lasery przeciwników, czas więc sprawdzić, czy któryś w nas trafi. W tym celu wracamy do naszej funkcji *update_collisions* i dopisujemy nowe instrukcje na jej końcu. Ponieważ chcemy sprawdzić, czy którykolwiek laser w nas trafił, to zaczynamy od pętli przechodzącej przez kopię listy laserów przeciwnika.

```python
def update_collisions():
    ...

    for laser in enemy_lasers_list[:]:
```

Teraz sprawdzamy, czy laser trafił w gracza. Ponownie skorzystamy z metody *collidepoint* wywołanej na graczu, a jako parametr podamy pozycję lasera (*laser.pos*).

```python
def update_collisions():
    ...

    for laser in enemy_lasers_list[:]:
        if player.collidepoint(laser.pos):
```

Jeżeli laser w nas trafił, to usuwamy go z listy laserów przeciwnika.

```python
def update_collisions():
    ...

    for laser in enemy_lasers_list[:]:
        if player.collidepoint(laser.pos):
            enemy_lasers_list.remove(laser)
```

Zmniejszamy także życia gracza o jeden.

```python
def update_collisions():
    ...

    for laser in enemy_lasers_list[:]:
        if player.collidepoint(laser.pos):
            enemy_lasers_list.remove(laser)
            player.lifes -= 1
```

Podobnie jak wcześniej, w przypadku końca gry chcemy odtworzyć odpowiedni dźwięk. Sprawdzamy więc, czy życia gracza spadły do zera.

```python
def update_collisions():
    ...

    for laser in enemy_lasers_list[:]:
        if player.collidepoint(laser.pos):
            enemy_lasers_list.remove(laser)
            player.lifes -= 1
            if player.lifes == 0:
```

Jeżeli tak, to odtwarzamy dźwięk *game_over*.

```python
def update_collisions():
    ...

    for laser in enemy_lasers_list[:]:
        if player.collidepoint(laser.pos):
            enemy_lasers_list.remove(laser)
            player.lifes -= 1
            if player.lifes == 0:
                sounds.game_over.play()
```

### Pełny kod

```python
import pgzrun
import random
import math

WIDTH = 1200
HEIGHT = 1200
MARGIN = 20

player = Actor("player")
player.x = WIDTH / 2
player.y = HEIGHT / 2
player.v = 2
player.va = 2
player.ac = 0.2
player.maxv = 8
player.lifes = 3

player_lasers_list = []
enemy_lasers_list = []
enemies_list = []


def draw():
    screen.fill("black")
    draw_list(player_lasers_list)
    draw_list(enemy_lasers_list)
    draw_list(enemies_list)
    player.draw()
    draw_lifes()


def draw_list(list):
    for element in list:
        element.draw()


def draw_lifes():
    pass


def update():
    update_player()
    update_player_lasers()
    update_enemies()
    update_enemy_lasers()
    update_collisions()


def update_player():
    player.x += math.sin(math.radians(player.angle - 180)) * player.v
    player.y += math.cos(math.radians(player.angle - 180)) * player.v

    if keyboard.A:
        player.angle += player.va

    if keyboard.D:
        player.angle -= player.va
    
    if keyboard.W:
        player.v += player.ac
        if player.v > player.maxv:
            player.v = player.maxv

    if keyboard.S:
        player.v -= player.ac
        if player.v < 0:
            player.v = 0

    if player.x > WIDTH + MARGIN:
        player.x = -MARGIN

    if player.x < -MARGIN:
        player.x = WIDTH + MARGIN

    if player.y < -MARGIN:
        player.y = HEIGHT + MARGIN

    if player.y > HEIGHT + MARGIN:
        player.y = -MARGIN


def update_player_lasers():
    for laser in player_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            player_lasers_list.remove(laser)


def update_enemies():
    if random.random() < 0.01:
        add_enemy()

    for enemy in enemies_list:
        enemy.angle = enemy.angle_to(player.pos) - 90
        enemy.x += math.sin(math.radians(enemy.angle - 180)) * enemy.v
        enemy.y += math.cos(math.radians(enemy.angle - 180)) * enemy.v

        if random.random() < 0.005:
            laser = Actor("laser2")
            laser.pos = enemy.pos
            laser.angle = enemy.angle
            laser.v = random.randint(5, 10)
            enemy_lasers_list.append(laser)
            sounds.laser2.play()


def update_enemy_lasers():
    for laser in enemy_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            enemy_lasers_list.remove(laser)


def update_collisions():
    for laser in player_lasers_list[:]:
        for enemy in enemies_list[:]:
            if enemy.colliderect(laser):
                enemies_list.remove(enemy)
                player_lasers_list.remove(laser)
                break

    for enemy in enemies_list[:]:
        if player.collidepoint(enemy.pos):
            enemies_list.remove(enemy)
            player.lifes -= 1
            if player.lifes == 0:
                sounds.game_over.play()

    for laser in enemy_lasers_list[:]:
        if player.collidepoint(laser.pos):
            enemy_lasers_list.remove(laser)
            player.lifes -= 1
            if player.lifes == 0:
                sounds.game_over.play()


def on_key_down(key):
    if key == keys.SPACE:
        laser = Actor("laser1")
        laser.pos = player.pos
        laser.angle = player.angle
        laser.v = 10
        player_lasers_list.append(laser)
        sounds.laser1.play()


def add_enemy():
    enemy = Actor("enemy")
    enemy.pos = choose_position()
    enemy.v = random.randint(2, 5)
    enemies_list.append(enemy)


def choose_position():
    if random.randint(1, 2) == 1:
        x = random.choice([-MARGIN, WIDTH + MARGIN])
        y = random.randint(MARGIN, HEIGHT - MARGIN)
    else:
        x = random.randint(MARGIN, WIDTH - MARGIN)
        y = random.choice([-MARGIN, HEIGHT + MARGIN])

    return x, y


def add_time():
    pass


pgzrun.go()
```

## Czas

Zajmiemy się teraz czasem, który będzie swoistymi punktami w naszej grze. Im dłużej uda nam się przetrwać, tym lepiej. Musimy jednak mieć jakieś miejsce do przechowywania wartości czasu. Czas będziemy reprezentować w sekundach, wystarczy nam więc zwykła liczba. Do naszego gracza dopiszemy zmienną *time* i nadamy jej wartość $$0$$. Nową zmienną dopisujemy zaraz pod życiami gracza.

```python
player.time = 0
```

### Wyświetlamy czas

Teraz możemy wyświetlić czas na ekranie, zanim przejdziemy do jego upływu. Na końcu funkcji *draw* dopisujemy instrukcję wypisującą tekst na ekranie (*screen.draw.text*). Jako tekst do wyświetlenia podamy tekstową reprezentację czasu przypisanego do gracza (*str(player.time)*). Środek tekstu (*center*) umieścimy na środku ekranu w poziomie (*WIDTH/2*) z niewielkim marginesem od góry ($$40$$). Jako rozmiar czcionki (*fontsize*) przyjmiemy wartość $$80$$, a kolor (*color*) ustawimy na żółty (*yellow*).

```python
def draw():
    ...
    screen.draw.text(str(player.time), center=(WIDTH / 2, 40), fontsize=80, color="yellow")
```

### Aktualizujemy czas

Czas się już wyświetla, czas więc go zaktualizować. Najpierw zajmiemy się naszą funkcją *add_time*, z której usuwamy instrukcję *pass*. Czas będziemy zwiększać tylko wtedy, gdy gracz jest jeszcze żywy, tzn. gdy ma więcej żyć niż $$0$$. Dlatego na początku sprawdzamy, czy tak rzeczywiście jest.

```python
def add_time():
    if player.lifes > 0:
```

Jeżeli gracz wciąż żyje, to zwiększamy czas o jeden.

```python
def add_time():
    if player.lifes > 0:
        player.time += 1
```

Naszą funkcję zwiększającą czas musimy jednak jakoś wywołać. Chcemy zliczać upływ sekund, powinniśmy więc funkcję wywoływać co jedną sekundę. Z pomocą przyjdzie nam funkcja **clock.schedule_interval** z biblioteki *Pygame Zero*. Jako parametry podamy nazwę funkcji *add_time* oraz liczbę sekund określającą odstęp czasowy do kolejnych wywołań funkcji. W naszym przypadku będzie to oczywiście $$1$$. Nową instrukcję dopisujemy na samym końcu naszego kodu, zaraz przed *pgzrun.go()*, tak aby czas zaczął być zliczany jak tylko rozpoczniemy grę.

```python
clock.schedule_interval(add_time, 1)
```

### Pełny kod

```python
import pgzrun
import random
import math

WIDTH = 1200
HEIGHT = 1200
MARGIN = 20

player = Actor("player")
player.x = WIDTH / 2
player.y = HEIGHT / 2
player.v = 2
player.va = 2
player.ac = 0.2
player.maxv = 8
player.lifes = 3
player.time = 0

player_lasers_list = []
enemy_lasers_list = []
enemies_list = []


def draw():
    screen.fill("black")
    draw_list(player_lasers_list)
    draw_list(enemy_lasers_list)
    draw_list(enemies_list)
    player.draw()
    draw_lifes()
    screen.draw.text(str(player.time), center=(WIDTH / 2, 40), fontsize=80, color="yellow")


def draw_list(list):
    for element in list:
        element.draw()


def draw_lifes():
    pass


def update():
    update_player()
    update_player_lasers()
    update_enemies()
    update_enemy_lasers()
    update_collisions()


def update_player():
    player.x += math.sin(math.radians(player.angle - 180)) * player.v
    player.y += math.cos(math.radians(player.angle - 180)) * player.v

    if keyboard.A:
        player.angle += player.va

    if keyboard.D:
        player.angle -= player.va
    
    if keyboard.W:
        player.v += player.ac
        if player.v > player.maxv:
            player.v = player.maxv

    if keyboard.S:
        player.v -= player.ac
        if player.v < 0:
            player.v = 0

    if player.x > WIDTH + MARGIN:
        player.x = -MARGIN

    if player.x < -MARGIN:
        player.x = WIDTH + MARGIN

    if player.y < -MARGIN:
        player.y = HEIGHT + MARGIN

    if player.y > HEIGHT + MARGIN:
        player.y = -MARGIN


def update_player_lasers():
    for laser in player_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            player_lasers_list.remove(laser)


def update_enemies():
    if random.random() < 0.01:
        add_enemy()

    for enemy in enemies_list:
        enemy.angle = enemy.angle_to(player.pos) - 90
        enemy.x += math.sin(math.radians(enemy.angle - 180)) * enemy.v
        enemy.y += math.cos(math.radians(enemy.angle - 180)) * enemy.v

        if random.random() < 0.005:
            laser = Actor("laser2")
            laser.pos = enemy.pos
            laser.angle = enemy.angle
            laser.v = random.randint(5, 10)
            enemy_lasers_list.append(laser)
            sounds.laser2.play()


def update_enemy_lasers():
    for laser in enemy_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            enemy_lasers_list.remove(laser)


def update_collisions():
    for laser in player_lasers_list[:]:
        for enemy in enemies_list[:]:
            if enemy.colliderect(laser):
                enemies_list.remove(enemy)
                player_lasers_list.remove(laser)
                break

    for enemy in enemies_list[:]:
        if player.collidepoint(enemy.pos):
            enemies_list.remove(enemy)
            player.lifes -= 1
            if player.lifes == 0:
                sounds.game_over.play()

    for laser in enemy_lasers_list[:]:
        if player.collidepoint(laser.pos):
            enemy_lasers_list.remove(laser)
            player.lifes -= 1
            if player.lifes == 0:
                sounds.game_over.play()


def on_key_down(key):
    if key == keys.SPACE:
        laser = Actor("laser1")
        laser.pos = player.pos
        laser.angle = player.angle
        laser.v = 10
        player_lasers_list.append(laser)
        sounds.laser1.play()


def add_enemy():
    enemy = Actor("enemy")
    enemy.pos = choose_position()
    enemy.v = random.randint(2, 5)
    enemies_list.append(enemy)


def choose_position():
    if random.randint(1, 2) == 1:
        x = random.choice([-MARGIN, WIDTH + MARGIN])
        y = random.randint(MARGIN, HEIGHT - MARGIN)
    else:
        x = random.randint(MARGIN, WIDTH - MARGIN)
        y = random.choice([-MARGIN, HEIGHT + MARGIN])

    return x, y


def add_time():
    if player.lifes > 0:
        player.time += 1


clock.schedule_interval(add_time, 1)
pgzrun.go()
```

## Życia

Teraz zajmiemy się wyświetleniem żyć gracza na ekranie. Zrobimy to praktycznie tak samo jak w przypadku gry *Asteroidy*. Życia narysujemy w lewym górnym rogu ekranu za pomocą grafik małego statku. Grafika, której użyjemy, nazywa się *life.png*. Do rysowania żyć wykorzystamy naszą funkcję *draw_lifes*, z której usuwamy instrukcję *draw*.

Będziemy rysować tyle żyć, na ile wskazuje zmienna *player.lifes*. W związku z tym potrzebna nam pętla. Użyjemy pętli *for* z licznikiem *life_id*, który będzie oznaczał numer obecnie rysowanego życia, a jako zakres przejdziemy od $$1$$ do liczby żyć statku włącznie, czyli  `range(1, player.lifes + 1)`.

```python
def draw_lifes():
    for life_id in range(1, player.lifes + 1):
```

Wewnątrz pętli zaczniemy od utworzenia nowego aktora na podstawie grafiki *life.png*. Zapiszemy go w zmiennej **life**.

```python
def draw_lifes():
    for life_id in range(1, player.lifes + 1):
        life = Actor("life")
```

Teraz czas wyznaczyć współrzędne naszego życia. Ponieważ chcemy, by były ułożone obok siebie w jednej linii, to współrzędna $$x$$ będzie zależna od numeru aktualnie rysowanego życia. Narysujemy życia tak, aby były obok siebie, ale na siebie nie nachodziły. Dlatego wartość współrzędnej poziomej to nic innego jak numer życia przemnożony przez szerokość grafiki życia. Szerokość grafiki aktora możemy łatwo poznać pisząc **life.width**.

```python
def draw_lifes():
    for life_id in range(1, player.lifes + 1):
        life = Actor("life")
        life.x = life_id * life.width
```

Jeżeli chodzi o położenie w pionie, to nasze życia będą dotykać górnego brzegu ekranu, ale nie powinny poza niego wychodzić. W tym celu do współrzędnej $$y$$ przypiszemy połowę wysokości grafiki życia. Wysokość grafiki aktora możemy pobrać podobnie jak szerokość: **life.height**.

```python
def draw_lifes():
    for life_id in range(1, player.lifes + 1):
        life = Actor("life")
        life.x = life_id * life.width
        life.y = life.height / 2
```

Pozostało nam narysować naszego aktora na ekranie korzystając z metody *draw*.

```python
def draw_lifes():
    for life_id in range(1, player.lifes + 1):
        life = Actor("life")
        life.x = life_id * life.width
        life.y = life.height / 2
        life.draw()
```

### Pełny kod

```python
import pgzrun
import random
import math

WIDTH = 1200
HEIGHT = 1200
MARGIN = 20

player = Actor("player")
player.x = WIDTH / 2
player.y = HEIGHT / 2
player.v = 2
player.va = 2
player.ac = 0.2
player.maxv = 8
player.lifes = 3
player.time = 0

player_lasers_list = []
enemy_lasers_list = []
enemies_list = []


def draw():
    screen.fill("black")
    draw_list(player_lasers_list)
    draw_list(enemy_lasers_list)
    draw_list(enemies_list)
    player.draw()
    draw_lifes()
    screen.draw.text(str(player.time), center=(WIDTH / 2, 40), fontsize=80, color="yellow")


def draw_list(list):
    for element in list:
        element.draw()


def draw_lifes():
    for life_id in range(1, player.lifes + 1):
        life = Actor("life")
        life.x = life_id * life.width
        life.y = life.height / 2
        life.draw()


def update():
    update_player()
    update_player_lasers()
    update_enemies()
    update_enemy_lasers()
    update_collisions()


def update_player():
    player.x += math.sin(math.radians(player.angle - 180)) * player.v
    player.y += math.cos(math.radians(player.angle - 180)) * player.v

    if keyboard.A:
        player.angle += player.va

    if keyboard.D:
        player.angle -= player.va
    
    if keyboard.W:
        player.v += player.ac
        if player.v > player.maxv:
            player.v = player.maxv

    if keyboard.S:
        player.v -= player.ac
        if player.v < 0:
            player.v = 0

    if player.x > WIDTH + MARGIN:
        player.x = -MARGIN

    if player.x < -MARGIN:
        player.x = WIDTH + MARGIN

    if player.y < -MARGIN:
        player.y = HEIGHT + MARGIN

    if player.y > HEIGHT + MARGIN:
        player.y = -MARGIN


def update_player_lasers():
    for laser in player_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            player_lasers_list.remove(laser)


def update_enemies():
    if random.random() < 0.01:
        add_enemy()

    for enemy in enemies_list:
        enemy.angle = enemy.angle_to(player.pos) - 90
        enemy.x += math.sin(math.radians(enemy.angle - 180)) * enemy.v
        enemy.y += math.cos(math.radians(enemy.angle - 180)) * enemy.v

        if random.random() < 0.005:
            laser = Actor("laser2")
            laser.pos = enemy.pos
            laser.angle = enemy.angle
            laser.v = random.randint(5, 10)
            enemy_lasers_list.append(laser)
            sounds.laser2.play()


def update_enemy_lasers():
    for laser in enemy_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            enemy_lasers_list.remove(laser)


def update_collisions():
    for laser in player_lasers_list[:]:
        for enemy in enemies_list[:]:
            if enemy.colliderect(laser):
                enemies_list.remove(enemy)
                player_lasers_list.remove(laser)
                break

    for enemy in enemies_list[:]:
        if player.collidepoint(enemy.pos):
            enemies_list.remove(enemy)
            player.lifes -= 1
            if player.lifes == 0:
                sounds.game_over.play()

    for laser in enemy_lasers_list[:]:
        if player.collidepoint(laser.pos):
            enemy_lasers_list.remove(laser)
            player.lifes -= 1
            if player.lifes == 0:
                sounds.game_over.play()


def on_key_down(key):
    if key == keys.SPACE:
        laser = Actor("laser1")
        laser.pos = player.pos
        laser.angle = player.angle
        laser.v = 10
        player_lasers_list.append(laser)
        sounds.laser1.play()


def add_enemy():
    enemy = Actor("enemy")
    enemy.pos = choose_position()
    enemy.v = random.randint(2, 5)
    enemies_list.append(enemy)


def choose_position():
    if random.randint(1, 2) == 1:
        x = random.choice([-MARGIN, WIDTH + MARGIN])
        y = random.randint(MARGIN, HEIGHT - MARGIN)
    else:
        x = random.randint(MARGIN, WIDTH - MARGIN)
        y = random.choice([-MARGIN, HEIGHT + MARGIN])

    return x, y


def add_time():
    if player.lifes > 0:
        player.time += 1


clock.schedule_interval(add_time, 1)
pgzrun.go()
```

## Koniec gry

Ostatnim elementem będzie zakończenie gry, gdy utracimy wszystkie życia.

### Zatrzymujemy grę

Zacznijmy od zatrzymania gry po utracie wszystkich żyć. W tym celu na samym początku funkcji *update* sprawdzimy, czy gracz ma zero żyć lub mniej.

```python
def update():
    if player.lifes <= 0:

   ...
```

Jeżeli tak, to użyjemy instrukcji *return* by wyjść z funkcji i nie aktualizować już elementów gry.

```python
def update():
    if player.lifes <= 0:
        return

    ...
```

### Wyświetlamy napis GAME OVER

Teraz przejdźmy do poinformowania gracza, że gra się zakończyła. Na końcu funkcji *draw* najpierw sprawdzimy, czy gracz ma zero żyć lub mniej.

```python
def draw():
    ...
    if player.lifes <= 0:
```

Jeżeli tak, to wyświetlimy napis *GAME OVER*. Umieścimy go dokładnie na środku ekranu, z czcionką o rozmiarze $$100$$ i czerwonym (*red*) kolorze.

```python
def draw():
    ...
    if player.lifes <= 0:
        screen.draw.text("GAME OVER", center=(WIDTH / 2, HEIGHT / 2), fontsize=100, color="red")
```

### Pełny kod

```python
import pgzrun
import random
import math

WIDTH = 1200
HEIGHT = 1200
MARGIN = 20

player = Actor("player")
player.x = WIDTH / 2
player.y = HEIGHT / 2
player.v = 2
player.va = 2
player.ac = 0.2
player.maxv = 8
player.lifes = 3
player.time = 0

player_lasers_list = []
enemy_lasers_list = []
enemies_list = []


def draw():
    screen.fill("black")
    draw_list(player_lasers_list)
    draw_list(enemy_lasers_list)
    draw_list(enemies_list)
    player.draw()
    draw_lifes()
    screen.draw.text(str(player.time), center=(WIDTH / 2, 40), fontsize=80, color="yellow")
    if player.lifes <= 0:
        screen.draw.text("GAME OVER", center=(WIDTH / 2, HEIGHT / 2), fontsize=100, color="red")


def draw_list(list):
    for element in list:
        element.draw()


def draw_lifes():
    for life_id in range(1, player.lifes + 1):
        life = Actor("life")
        life.x = life_id * life.width
        life.y = life.height / 2
        life.draw()


def update():
    if player.lifes <= 0:
        return

    update_player()
    update_player_lasers()
    update_enemies()
    update_enemy_lasers()
    update_collisions()


def update_player():
    player.x += math.sin(math.radians(player.angle - 180)) * player.v
    player.y += math.cos(math.radians(player.angle - 180)) * player.v

    if keyboard.A:
        player.angle += player.va

    if keyboard.D:
        player.angle -= player.va
    
    if keyboard.W:
        player.v += player.ac
        if player.v > player.maxv:
            player.v = player.maxv

    if keyboard.S:
        player.v -= player.ac
        if player.v < 0:
            player.v = 0

    if player.x > WIDTH + MARGIN:
        player.x = -MARGIN

    if player.x < -MARGIN:
        player.x = WIDTH + MARGIN

    if player.y < -MARGIN:
        player.y = HEIGHT + MARGIN

    if player.y > HEIGHT + MARGIN:
        player.y = -MARGIN


def update_player_lasers():
    for laser in player_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            player_lasers_list.remove(laser)


def update_enemies():
    if random.random() < 0.01:
        add_enemy()

    for enemy in enemies_list:
        enemy.angle = enemy.angle_to(player.pos) - 90
        enemy.x += math.sin(math.radians(enemy.angle - 180)) * enemy.v
        enemy.y += math.cos(math.radians(enemy.angle - 180)) * enemy.v

        if random.random() < 0.005:
            laser = Actor("laser2")
            laser.pos = enemy.pos
            laser.angle = enemy.angle
            laser.v = random.randint(5, 10)
            enemy_lasers_list.append(laser)
            sounds.laser2.play()


def update_enemy_lasers():
    for laser in enemy_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            enemy_lasers_list.remove(laser)


def update_collisions():
    for laser in player_lasers_list[:]:
        for enemy in enemies_list[:]:
            if enemy.colliderect(laser):
                enemies_list.remove(enemy)
                player_lasers_list.remove(laser)
                break

    for enemy in enemies_list[:]:
        if player.collidepoint(enemy.pos):
            enemies_list.remove(enemy)
            player.lifes -= 1
            if player.lifes == 0:
                sounds.game_over.play()

    for laser in enemy_lasers_list[:]:
        if player.collidepoint(laser.pos):
            enemy_lasers_list.remove(laser)
            player.lifes -= 1
            if player.lifes == 0:
                sounds.game_over.play()


def on_key_down(key):
    if key == keys.SPACE:
        laser = Actor("laser1")
        laser.pos = player.pos
        laser.angle = player.angle
        laser.v = 10
        player_lasers_list.append(laser)
        sounds.laser1.play()


def add_enemy():
    enemy = Actor("enemy")
    enemy.pos = choose_position()
    enemy.v = random.randint(2, 5)
    enemies_list.append(enemy)


def choose_position():
    if random.randint(1, 2) == 1:
        x = random.choice([-MARGIN, WIDTH + MARGIN])
        y = random.randint(MARGIN, HEIGHT - MARGIN)
    else:
        x = random.randint(MARGIN, WIDTH - MARGIN)
        y = random.choice([-MARGIN, HEIGHT + MARGIN])

    return x, y


def add_time():
    if player.lifes > 0:
        player.time += 1


clock.schedule_interval(add_time, 1)
pgzrun.go()
```

## Pełna gra

Nasza gra jest gotowa, a jej pełen kod widoczny jest poniżej.

```python
import pgzrun
import random
import math

WIDTH = 1200
HEIGHT = 1200
MARGIN = 20

player = Actor("player")
player.x = WIDTH / 2
player.y = HEIGHT / 2
player.v = 2
player.va = 2
player.ac = 0.2
player.maxv = 8
player.lifes = 3
player.time = 0

player_lasers_list = []
enemy_lasers_list = []
enemies_list = []


def draw():
    screen.fill("black")
    draw_list(player_lasers_list)
    draw_list(enemy_lasers_list)
    draw_list(enemies_list)
    player.draw()
    draw_lifes()
    screen.draw.text(str(player.time), center=(WIDTH / 2, 40), fontsize=80, color="yellow")
    if player.lifes <= 0:
        screen.draw.text("GAME OVER", center=(WIDTH / 2, HEIGHT / 2), fontsize=100, color="red")


def draw_list(list):
    for element in list:
        element.draw()


def draw_lifes():
    for life_id in range(1, player.lifes + 1):
        life = Actor("life")
        life.x = life_id * life.width
        life.y = life.height / 2
        life.draw()


def update():
    if player.lifes <= 0:
        return

    update_player()
    update_player_lasers()
    update_enemies()
    update_enemy_lasers()
    update_collisions()


def update_player():
    player.x += math.sin(math.radians(player.angle - 180)) * player.v
    player.y += math.cos(math.radians(player.angle - 180)) * player.v

    if keyboard.A:
        player.angle += player.va

    if keyboard.D:
        player.angle -= player.va
    
    if keyboard.W:
        player.v += player.ac
        if player.v > player.maxv:
            player.v = player.maxv

    if keyboard.S:
        player.v -= player.ac
        if player.v < 0:
            player.v = 0

    if player.x > WIDTH + MARGIN:
        player.x = -MARGIN

    if player.x < -MARGIN:
        player.x = WIDTH + MARGIN

    if player.y < -MARGIN:
        player.y = HEIGHT + MARGIN

    if player.y > HEIGHT + MARGIN:
        player.y = -MARGIN


def update_player_lasers():
    for laser in player_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            player_lasers_list.remove(laser)


def update_enemies():
    if random.random() < 0.01:
        add_enemy()

    for enemy in enemies_list:
        enemy.angle = enemy.angle_to(player.pos) - 90
        enemy.x += math.sin(math.radians(enemy.angle - 180)) * enemy.v
        enemy.y += math.cos(math.radians(enemy.angle - 180)) * enemy.v

        if random.random() < 0.005:
            laser = Actor("laser2")
            laser.pos = enemy.pos
            laser.angle = enemy.angle
            laser.v = random.randint(5, 10)
            enemy_lasers_list.append(laser)
            sounds.laser2.play()


def update_enemy_lasers():
    for laser in enemy_lasers_list[:]:
        laser.x += math.sin(math.radians(laser.angle - 180)) * laser.v
        laser.y += math.cos(math.radians(laser.angle - 180)) * laser.v

        if laser.x > WIDTH + MARGIN or laser.x < -MARGIN or laser.y > HEIGHT + MARGIN or laser.y < -MARGIN:
            enemy_lasers_list.remove(laser)


def update_collisions():
    for laser in player_lasers_list[:]:
        for enemy in enemies_list[:]:
            if enemy.colliderect(laser):
                enemies_list.remove(enemy)
                player_lasers_list.remove(laser)
                break

    for enemy in enemies_list[:]:
        if player.collidepoint(enemy.pos):
            enemies_list.remove(enemy)
            player.lifes -= 1
            if player.lifes == 0:
                sounds.game_over.play()

    for laser in enemy_lasers_list[:]:
        if player.collidepoint(laser.pos):
            enemy_lasers_list.remove(laser)
            player.lifes -= 1
            if player.lifes == 0:
                sounds.game_over.play()


def on_key_down(key):
    if key == keys.SPACE:
        laser = Actor("laser1")
        laser.pos = player.pos
        laser.angle = player.angle
        laser.v = 10
        player_lasers_list.append(laser)
        sounds.laser1.play()


def add_enemy():
    enemy = Actor("enemy")
    enemy.pos = choose_position()
    enemy.v = random.randint(2, 5)
    enemies_list.append(enemy)


def choose_position():
    if random.randint(1, 2) == 1:
        x = random.choice([-MARGIN, WIDTH + MARGIN])
        y = random.randint(MARGIN, HEIGHT - MARGIN)
    else:
        x = random.randint(MARGIN, WIDTH - MARGIN)
        y = random.choice([-MARGIN, HEIGHT + MARGIN])

    return x, y


def add_time():
    if player.lifes > 0:
        player.time += 1


clock.schedule_interval(add_time, 1)
pgzrun.go()
```