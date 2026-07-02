# Patrol inteligentnego przeciwnika

Sztuczna inteligencja towarzyszy grom komputerowym praktycznie od samego początku. Na przestrzeni lat algorytmy SI przeciwników ewoluowały w różnych kierunkach. W ramach tego tutorialu dowiesz się, jak można zaimplementować "inteligentnego" przeciwnika.

Pomysł na grę jest prosty: mamy gracza, strażnika oraz skarb. Naszym celem jest dotarcie do skarbu omijając strażnika, a celem strażnika jest nam w tym przeszkodzić. I to właśnie zachowaniem strażnika będziemy sterować poprzez różne algorytmy.

## Grafiki do pobrania

[:material-folder-zip: Grafiki do gry Patrol AI](../../../assets/images_patrol_ai.zip)

Grafiki umieszczamy w katalogu **images** w katalogu projektu naszej gry.

Grafiki pochodzą ze strony [https://kenney.nl/](https://kenney.nl/) i są udostępniane na licencji [Creative Commons CC0](https://creativecommons.org/publicdomain/zero/1.0/).

## Instalacja zależności

Do naszej gry potrzebujemy biblioteki *pygame-zero*. Ponieważ bazuje ona na bibliotece *pygame*, która rozwija się wolniej niż Python i może nie wspierać najnowszych wersji tego języka, zainstalujemy wersję społeczności tej biblioteki, *pygame-ce*. Do działania potrzebna jest także biblioteka *numpy* do obliczeń arytmetycznych.

```
pip install pygame-ce numpy
pip install pgzero --no-deps
```

## Konfiguracja wstępna

Jak zwykle zaczynamy od utworzenia pliku `main.py` oraz zaimportowania potrzebnych bibliotek.

```python
import math
import pgzrun
```

Poniżej ustalmy wymiary naszego okna na $900\times600$.

```python
WIDTH = 900
HEIGHT = 600
```

Teraz czas na pętlę rysującą w naszej grze. Tworzymy funkcję `draw` w której wypełnimy ekran czarnym tłem.

```python
def draw():
    screen.fill("black")
```

Potrzebna będzie nam także pętla aktualizująca, w której na ten moment nie będziemy nic robić. Tworzymy więc funkcję `update` z jedną instrukcją: `pass`.

```python
def update():
    pass
```

Na końcu pliku dajemy polecenie uruchamiające naszą grę.

```python
pgzrun.go()
```

Możemy teraz uruchomić naszą grę i przetestować. Powinniśmy zobaczyć czarny ekran.

### Pełen kod

```python
import math
import pgzrun


WIDTH = 900
HEIGHT = 600


def draw():
    screen.fill("black")


def update():
    pass


pgzrun.go()
```

## Dodajemy gracza

Mamy podstawowy szablon, przyszedł więc czas na dodanie naszego gracza. Na początek, pod wymiarami ekranu a przed funkcją rysującą dodajemy nowego aktora.

```python
player = Actor("player")
```

Umieśćmy go z lewej strony ekranu.

```python
player.x = 70
player.y = HEIGHT // 2
```

Mamy gracza, możemy więc go wyświetlić na ekranie. Dodajemy nową instrukcję na koniec funkcji `draw`.

```python
def draw():
    screen.fill("black")
    player.draw()
```

### Sterowanie

Naszym graczem będziemy sterować za pomocą klawiszy strzałek: lewo, prawo, góra, dół. Gdy przytrzymamy odpowiedni klawisz, gracz będzie poruszać się w odpowiednim kierunku z ustaloną prędkością. Ale właśnie, z jaką prędkością? To musimy ustalić. Potraktujemy to jako ustawienie naszej gry, które będziemy mogli potem modyfikować, aby dobrać odpowiednią wartość.
Dodajemy nową *stałą* na początku naszego programu, zaraz pod ustaleniem wymiarów okna. Nazwiemy ją po angielsku `PLAYER_SPEED`. Ja przyjmę wartość $4$, ale zachęcam do eksperymentowania i wybrania własnej wartości.

```python
PLAYER_SPEED = 4
```

Mamy już prędkość, możemy przejść do ruchu. Obsługę sterowania zapisujemy wewnątrz funkcji aktualizującej `update`, z której **usuwamy** instrukcję `pass`. Na początek musimy sprawdzić, jaki klawisz został wciśnięty. Zrobimy to za pomocą instrukcji warunkowej i odwołania do zmiennej `keyboard` z pygame-zero. Zacznijmy od sprawdzenia, czy został wciśnięty klawisz strzałka w lewo (`left`).

```python
def update():
    if keyboard.left:
```

Jeżeli wcisnęliśmy klawisz w lewo, to **zmniejszymy** pozycję `x` gracza zgodnie z jego prędkością.

```python
def update():
    if keyboard.left:
        player.x -= PLAYER_SPEED
```

Pozostałe klawisze obsługujemy w podobny sposób, za pomocą kolejnych instrukcji warunkowych

```python
def update():
    if keyboard.left:
        player.x -= PLAYER_SPEED
    if keyboard.right:
        player.x += PLAYER_SPEED
    if keyboard.up:
        player.y -= PLAYER_SPEED
    if keyboard.down:
        player.y += PLAYER_SPEED
```

Czas przetestować nasze rozwiązanie. Po uruchomieniu powinniśmy móc poruszać naszym graczem.

### Pełen kod

```python
import math
import pgzrun


WIDTH = 900
HEIGHT = 600

PLAYER_SPEED = 4

player = Actor("player")
player.x = 70
player.y = HEIGHT // 2


def draw():
    screen.fill("black")
    player.draw()


def update():
    if keyboard.left:
        player.x -= PLAYER_SPEED
    if keyboard.right:
        player.x += PLAYER_SPEED
    if keyboard.up:
        player.y -= PLAYER_SPEED
    if keyboard.down:
        player.y += PLAYER_SPEED


pgzrun.go()
```

## Skarb

Celem naszej gry będzie dotarcie do skarbu. Potrzebny więc nam skarb. Dodajemy nowego aktora na początku naszego kodu, zaraz przed funkcją rysującą `draw`.

```python
treasure = Actor("treasure")
```

Skarb umieścimy po przeciwnej stronie ekranu niż znajduje się gracz, czyli z prawej strony.

```python
treasure.x = WIDTH - 80
treasure.y = HEIGHT // 2
```

Umieściliśmy skarb, czas go narysować. Ponieważ chcemy, żeby gracz wyświetlał się *nad* skarbem, gdy na niego najedzie, to najpierw rysujemy skarb, a dopiero potem gracza. Dopisujemy nową instrukcję wewnątrz funkcji `draw`, zaraz przed rysowaniem gracza.

```python
def draw():
    ...
    treasure.draw()
    player.draw()
```

### Zebranie skarbu i stany gry

Po zebraniu skarbu gra powinna się zakończyć. Żeby móc łatwo rozróżniać stany gry, tzn. czy akturalnie gramy, czy wygraliśmy, czy przegraliśmy, to dodamy nową wartość do naszego gracza: `game_state`. Na początku kodu, zaraz pod przypisaniem pozycji gracza, dopiszemy do niego `game_state` z wartością *playing*, oznaczającą, że gra się właśnie toczy.

```python
player = Actor("player")
...
player.game_state = "playing"
```

Teraz możemy przejść do zbierania skarbu. Gdy gracz wejdzie w kolizję ze skarbem, zmienimy stan gry na *win*. Sprawdzanie kolizji dodamy na końcu funkcji `update`. Skorzystamy z wbudowanej w pygame-zero metody `colliderect` która sprawdza, czy dwóch aktorów jest w kolizji.

```python
def update():
    ...
    if player.colliderect(treasure):
        player.game_state = "win"
```

Aby zobaczyć jakiś efekt, wyświetlimy napis na ekranie, gdy gracz zbierze skarb, tzn. gdy stan gry będzie miał wartość *win*. Na końcu funkcji `draw` sprawdzimy, czy wartość stanu gry to *win* a jeżeli tak, to wyświetlimy odpowiedni napis na ekranie.

```python
def draw():
    ...
    if player.game_state == "win":
        screen.draw.text("You got the treasure!", center=(WIDTH / 2, HEIGHT / 2), color="yellow", fontsize=60)
```

Teraz możemy przetestować grę. Gdy zbierzemy skarb, na ekranie powinien wyświetlić się stosowny komunikat.

### Koniec gry i restart

W obecnym stanie gry, gdy zbierzemy skarb, możemy dalej się poruszać. Nie ma to większego sensu, lepiej gdyby gra się zatrzymała i czekała na restart. W tym celu, na początku funkcji `update` sprawdzimy, czy stan gry jest **różny** od *playing*. Jeżeli tak, to zakończymy działanie funkcji i nie będziemy dalej aktualizować stanu gry.

```python
def update():
    if player.game_state != "playing":
        return
    ...
```

Teraz, po zebraniu skarbu, gra powinna się zatrzymać. Czas więc przejść do restartu. Restart gry zrobimy po wciśnięciu przyciusku **R** przez gracza. Aby obsłużyć wciśnięcie przycisku, dodamy nową funkcję, którą zapisujemy na końcu kodu, przed instrukcją `pgzrun.go()`.

```python
def on_key_down(key):
```

Wewnątrz sprawdzimy, czy został wciśnięty klawisz **R**. Jeżeli tak, ustawimy ponownie pozycję gracza i stan gry.

```python
def on_key_down(key):
    if key == keys.R:
        player.x = 70
        player.y = HEIGHT // 2
        player.game_state = "playing"
```

Teraz możemy przetestować naszą grę. Jak dotrzemy do skarbu, gra się zatrzyma, a jak wciśniemy **R** to gra się zrestartuje, pozwalając nam na łatwą, powtarzalną rozgrywkę.

### Pełen kod

```python
import math
import pgzrun


WIDTH = 900
HEIGHT = 600

PLAYER_SPEED = 4

player = Actor("player")
player.x = 70
player.y = HEIGHT // 2
player.game_state = "playing"

treasure = Actor("treasure")
treasure.x = WIDTH - 80
treasure.y = HEIGHT // 2


def draw():
    screen.fill("black")

    treasure.draw()
    player.draw()

    if player.game_state == "win":
        screen.draw.text("You got the treasure!", center=(WIDTH / 2, HEIGHT / 2), color="yellow", fontsize=60)


def update():
    if player.game_state != "playing":
        return

    if keyboard.left:
        player.x -= PLAYER_SPEED
    if keyboard.right:
        player.x += PLAYER_SPEED
    if keyboard.up:
        player.y -= PLAYER_SPEED
    if keyboard.down:
        player.y += PLAYER_SPEED

    if player.colliderect(treasure):
        player.game_state = "win"


def on_key_down(key):
    if key == keys.R:
        player.x = 70
        player.y = HEIGHT // 2
        player.game_state = "playing"


pgzrun.go()
```

## Strażnik

Przysła wreszcie pora na strażnika. Na początek dodajmy nowego aktora, zaraz przed funkcją `draw`.
Naszego strażnika ustawimy na środku ekranu.

```python
guard = Actor("guard1")
guard.x = WIDTH // 2
guard.y = HEIGHT // 2
```

Mamy aktora, narysujmy go na ekranie. Dodajmy nową instrukcję wewnątrz funkcji `draw`, zaraz po narysowaniu gracza.

```python
def draw():
    ...
    player.draw()
    guard.draw()
    ...
```

Teraz, jak uruchomimy naszą grę, powinniśmy zauważyć strażnika.

Żeby uniknąć późniejszych problemów, dodamy także ustalanie początkowych współrzędnych strażnika do funkcji obsługującej restart gry.

```python
def on_key_down(key):
    if key == keys.R:
        ...
        guard.x = WIDTH // 2
        guard.y = HEIGHT // 2
```

### Kolizja z graczem i koniec gry

Podobnie jak w przypadku skarbu, gdy gracz wejdzie w kolizję ze strażnikiem, gra powinna się zakończyć, tym razem przegraną gracza. Na końcu funkcji `update` dodamy instrukcję sprawdzającą, czy gracz jest w kolizji ze strażnikiem, a jeżeli tak, to zmienimy wartość stanu gry na *lose*.

```python
def update():
    ...
    if player.colliderect(guard):
        player.game_state = "lose"
```

Teraz pozostało nam wyświetlić odpowiedni komunikat na ekranie, gdy przegramy. Dodajemy nową instrukcję na końcu funkcji `draw`.

```python
def draw():
    ...
    if player.game_state == "lose":
        screen.draw.text("Caught!", center=(WIDTH / 2, HEIGHT / 2), color="red", fontsize=60)
```

Teraz możemy przetestować rozgrywkę. Jak najedziemy na strażnika, to gra powinna się zakończyć z komunikatem o przegranej.

### Zasięg widzenia

Nasz strażnik nie miałby sensu, gdyby nie potrafił zobaczyć gracza z pewnej odległości i zacząć go ścigać. Dodamy strażnikowi na początek pewien promień zasięgu wzroku. Ustawimy to jak stałą, podobnie jak prędkość gracza. Nową linijkę dopisujemy na początku kodu, zaraz pod prędkością gracza (`PLAYER_SPEED`).

```python
VISION_RADIUS = 180
```

Żeby zobaczyć, jaki obszar strażnik obserwuje, wyświetlimy go w postaci okręgu na ekranie. Okrąg narysujemy wewnątrz funkcji rysującej `draw`, zaraz po wypełnieniu ekranu kolorem tła. Wykorzystamy metodę `screen.draw.circle`. Najpierw podajemy współrzędnedne środka okręgu, czyli współrzędne strażnika (`guard.pos`), następnie promień (`VISION_RADIUS`), a na koniec kolor, np. jasnoniebieski (`lightblue`).

```python
def draw():
    screen.fill("black")
    screen.draw.circle(guard.pos, VISION_RADIUS, "lightblue")
    ...
```

### Ściganie

Gdy gracz znajdzię się w zasięgu wzroku strażnika, ten powinien go ścigać. Ściganie to nic innego jak poruszanie się w kierunku gracza z określoną prędkością. Na początek potrzebna nam jest prędkość strażnika, którą dodamy jako kolejną stałą, zaraz pod zasięgiem wzroku.

```python
GUARD_SPEED = 2.5
```

Teraz przejdziemy do napisania pomocniczej funkcji, która przemieści strażnika w kierunku określonego punktu na ekranie. Taka funkcja przyda nam się później do rozwijania zachowania strażnika.

Naszą pomocniczą funkcję umieśćmy na końcu kodu, przed instrukcją `pgzrun.go()`. Nazwijmy ją `move_towards`. Nasza funkcja przyjmie dwa argumenty: współrzędne miejsca, do którego chcemy przemieścić strażnika.

```python
def move_towards(x, y):
```

Na początku obliczenia wyliczymy różnice pomiędzy miejscem docelowym a obecną pozycją strażnika.

```python
def move_towards(x, y):
    dx = x - guard.x
    dy = y - guard.y
```

Następnie, na podstawie tych różnic, obliczymy odległość za pomocą funkcji `hypot` z modułu `math`.

```python
def move_towards(x, y):
    dx = x - guard.x
    dy = y - guard.y
    dist = math.hypot(dx, dy)
```

Jeżeli ta odległość będzie większa od zera, to przemieścimy strażnika w zadanym kierunku, zgodnie z jego prędkością.

```python
def move_towards(x, y):
    dx = x - guard.x
    dy = y - guard.y
    dist = math.hypot(dx, dy)
    if dist > 0:
        guard.x += (dx / dist) * GUARD_SPEED
        guard.y += (dy / dist) * GUARD_SPEED
```

Mamy już gotową funkcję pomocniczą, czas ją wywołać. Na końcu funkcji `update` będziemy sprawdzać, czy odległość pomiędzy graczem a strażnikiem jest mniejsza od zasięgu wzroku strażnika. Jeżeli tak, wywołamy funkcję `move_towards` jako współrzędne celu podając współrzędne gracza.

```python
def update():
    ...
    if guard.distance_to(player) <= VISION_RADIUS:
        move_towards(player.x, player.y)
```

Teraz możemy przetestować naszą rozgrywkę. Gdy wejdziemy w zasięg wzroku strażnika, zacznie on nas ścigać. Gdy uda nam się uciec, strażnik powinien się zatrzymać.

### Pełen kod

```python
import math
import pgzrun


WIDTH = 900
HEIGHT = 600

PLAYER_SPEED = 4
VISION_RADIUS = 180
GUARD_SPEED = 2.5

player = Actor("player")
player.x = 70
player.y = HEIGHT // 2
player.game_state = "playing"

treasure = Actor("treasure")
treasure.x = WIDTH - 80
treasure.y = HEIGHT // 2

guard = Actor("guard1")
guard.x = WIDTH // 2
guard.y = HEIGHT // 2


def draw():
    screen.fill("black")

    screen.draw.circle(guard.pos, VISION_RADIUS, "lightblue")

    treasure.draw()
    player.draw()
    guard.draw()

    if player.game_state == "win":
        screen.draw.text("You got the treasure!", center=(WIDTH / 2, HEIGHT / 2), color="yellow", fontsize=60)
    if player.game_state == "lose":
        screen.draw.text("Caught!", center=(WIDTH / 2, HEIGHT / 2), color="red", fontsize=60)


def update():
    if player.game_state != "playing":
        return

    if keyboard.left:
        player.x -= PLAYER_SPEED
    if keyboard.right:
        player.x += PLAYER_SPEED
    if keyboard.up:
        player.y -= PLAYER_SPEED
    if keyboard.down:
        player.y += PLAYER_SPEED

    if player.colliderect(treasure):
        player.game_state = "win"
    if player.colliderect(guard):
        player.game_state = "lose"

    if guard.distance_to(player) <= VISION_RADIUS:
        move_towards(player.x, player.y)


def on_key_down(key):
    if key == keys.R:
        player.x = 70
        player.y = HEIGHT // 2
        player.game_state = "playing"
        guard.x = WIDTH // 2
        guard.y = HEIGHT // 2


def move_towards(x, y):
    dx = x - guard.x
    dy = y - guard.y
    dist = math.hypot(dx, dy)
    if dist > 0:
        guard.x += (dx / dist) * GUARD_SPEED
        guard.y += (dy / dist) * GUARD_SPEED


pgzrun.go()
```

## Zachowanie strażnika

W tym momencie mamy już prostego, działającego strażnika. Jego zachowanie można nawet przyrównać do "inteligentnych" przeciwników we wczesnych grach. Teraz dopiszemy zachowanie strażnika, gdy nie widzi gracza. To jest kluczowe miejsce, które pozwoli nam na eksperymentowanie z różnymi zachowaniami przeciwnika.

Zaczniemy od bardzo prostego zachowania. Celem strażnika jest strzec skarbu. W takim razie strażnik będzie stał przy tym skarbie, albo przemieszczał się w jego kierunku, gdy nie ściga gracza. Nową funkcję dodamy na końco naszego programu, przed instrukcją `pgzrun.go()`.

```python
def guard_behaviour():
```

Wewnątrz funkcji dodamy jedną instrukcję dla naszego strażnika: idź w kierunku skarbu.

```python
def guard_behaviour():
    move_towards(treasure.x, treasure.y)
```

Teraz pozostało nam wywołać tę funkcję. Zrobimy to na końcu `update`, jeżeli strażnik **nie widzi** gracza.

```python
def update():
    ...
    if guard.distance_to(player) <= VISION_RADIUS:
        ...
    else:
        guard_behaviour()
```

I to wszytko. Mamy działającego, *inteligentnego* strażnika.

## Pełen kod

```python
import math
import pgzrun


WIDTH = 900
HEIGHT = 600

PLAYER_SPEED = 4
VISION_RADIUS = 180
GUARD_SPEED = 2.5

player = Actor("player")
player.x = 70
player.y = HEIGHT // 2
player.game_state = "playing"

treasure = Actor("treasure")
treasure.x = WIDTH - 80
treasure.y = HEIGHT // 2

guard = Actor("guard1")
guard.x = WIDTH // 2
guard.y = HEIGHT // 2


def draw():
    screen.fill("black")

    screen.draw.circle(guard.pos, VISION_RADIUS, "lightblue")

    treasure.draw()
    player.draw()
    guard.draw()

    if player.game_state == "win":
        screen.draw.text("You got the treasure!", center=(WIDTH / 2, HEIGHT / 2), color="yellow", fontsize=60)
    if player.game_state == "lose":
        screen.draw.text("Caught!", center=(WIDTH / 2, HEIGHT / 2), color="red", fontsize=60)


def update():
    if player.game_state != "playing":
        return

    if keyboard.left:
        player.x -= PLAYER_SPEED
    if keyboard.right:
        player.x += PLAYER_SPEED
    if keyboard.up:
        player.y -= PLAYER_SPEED
    if keyboard.down:
        player.y += PLAYER_SPEED

    if player.colliderect(treasure):
        player.game_state = "win"
    if player.colliderect(guard):
        player.game_state = "lose"

    if guard.distance_to(player) <= VISION_RADIUS:
        move_towards(player.x, player.y)
    else:
        guard_behaviour()


def on_key_down(key):
    if key == keys.R:
        player.x = 70
        player.y = HEIGHT // 2
        player.game_state = "playing"
        guard.x = WIDTH // 2
        guard.y = HEIGHT // 2


def move_towards(x, y):
    dx = x - guard.x
    dy = y - guard.y
    dist = math.hypot(dx, dy)
    if dist > 0:
        guard.x += (dx / dist) * GUARD_SPEED
        guard.y += (dy / dist) * GUARD_SPEED


def guard_behaviour():
    move_towards(treasure.x, treasure.y)
    

pgzrun.go()
```

## Co dalej

Funkcja `guard_behaviour` to **mózg** naszego strażnika. Innymi słowy to skrypt, który definiuje jego zachowanie. Poniżej przedstawiam kilka różnych wersji tej funkcji, które diametralnie zmieniają zachowanie strażnika.

**Uwaga:** większość z tych funkcji wymaga dodania nowych wartości do strażnika, a czasem także zaimportowania dodatkowej biblioteki.

### Patrol

Strażnik jak to strażnik, mógłby patrolować pewien obszar na ekranie.

```python
guard.patrol_target = 0

def guard_behaviour():
    left = (WIDTH // 2, HEIGHT // 2)
    right = (treasure.x, treasure.y)
    targets = [left, right]
    tx, ty = targets[guard.patrol_target]
    move_towards(tx, ty)

    if math.hypot(guard.x - tx, guard.y - ty) < 8:
        guard.patrol_target = 1 - guard.patrol_target
```

### Aktywne ściganie z przewidywaniem ruchu

Na podstawie obecnej pozycji gracza a także informacji o jego porzedniej pozycji, strażnik może przewidywać, gdzie gracz się znajdzie, i przemieścić się w tym kierunku.

```python
player.prev_x = player.x
player.prev_y = player.y

def guard_behaviour():
    vx = player.x - player.prev_x
    vy = player.y - player.prev_y
    lead_time = 14
    pred_x = player.x + vx * lead_time
    pred_y = player.y + vy * lead_time
    pred_x = max(0, min(WIDTH, pred_x))
    pred_y = max(0, min(HEIGHT, pred_y))
    move_towards(pred_x, pred_y)
    player.prev_x = player.x
    player.prev_y = player.y
```

### Mała "sieć neuronowa"

Żeby lepiej zrozumieć jak działają sieci neuronowe, a także wielkie modele językowe (LLM), możemy zaimplementować zachowanie strażnika, które połączy nasze wcześniejsze przykłady. Ustaliliśmy do tej pory trzy różne zachowania strażnika: obrona skarbu, patrolowanie oraz aktywne ściganie gracza. Możemy zaprojektować strażnika, który będzie wybierał jedno z tych zachowań na podstawie tego, co się dzieje w grze. Na podstawie obserwacji wyliczymy proste "wagi", które pozwolą nam losowo wybrać zachowanie strażnika.

```python
import random


player.prev_x = player.x
player.prev_y = player.y
guard.patrol_target = 0
guard.action = "patrol"
guard.frames_to_change_action = random.randint(60 * 5, 60 * 10)

def guard_behaviour():
    player_vx = player.x - player.prev_x
    player_vy = player.y - player.prev_y
    player_speed = math.hypot(player_vx, player_vy)
    dist_treasure = guard.distance_to(treasure)

    if dist_treasure < 120:
        p_intercept = 0.20
        p_defend = 0.60
    else:
        p_intercept = 0.55 if player_speed > 1.2 else 0.35
        p_defend = 0.20

    guard.frames_to_change_action -= 1
    if guard.frames_to_change_action <= 0:
        guard.frames_to_change_action = random.randint(60 * 5, 60 * 10)
        roll = random.random()
        if roll < p_intercept:
            guard.action = "intercept"
        elif roll < p_intercept + p_defend:
            guard.action = "defend"
        else:
            guard.action = "patrol"

    if guard.action == "intercept":
        lead_time = 14
        pred_x = player.x + player_vx * lead_time
        pred_y = player.y + player_vy * lead_time
        pred_x = max(0, min(WIDTH, pred_x))
        pred_y = max(0, min(HEIGHT, pred_y))
        move_towards(pred_x, pred_y)
    elif guard.action == "defend":
        move_towards(treasure.x, treasure.y)
    else:
        left = (WIDTH // 2, HEIGHT // 2)
        right = (treasure.x, treasure.y)
        targets = [left, right]
        tx, ty = targets[guard.patrol_target]
        move_towards(tx, ty)
        if math.hypot(guard.x - tx, guard.y - ty) < 8:
            guard.patrol_target = 1 - guard.patrol_target

    player.prev_x = player.x
    player.prev_y = player.y
```
