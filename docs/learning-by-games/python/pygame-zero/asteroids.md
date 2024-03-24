# Asteroidy

## Wstęp

Kosmos, statki kosmiczne, asteroidy, lasery: tym się właśnie dziś zajmiemy!
Stworzymy naszą pierwszą grę kosmiczną!

### Czego się nauczysz

- Pracy z listami.
- Dodawania nowych elementów do gry w trakcie jej działania.
- Usuwania elementów gry w trakcie jej działania.
- Odczytywania pozycji myszki.
- Planowania wykonania akcji z opóźnieniem.

### Grafiki do pobrania

{% file src="../../../.gitbook/assets/images_asteroids.zip" %}
Grafiki do gry Asteroidy
{% endfile %}

### Dźwięki do pobrania

{% file src="../../../.gitbook/assets/sounds_asteroids.zip" %}
Dźwięki do gry Asteroidy
{% endfile %}

### Muzyka do pobrania

{% file src="../../../.gitbook/assets/music_asteroids.zip" %}
Muzyka do gry Asteroidy
{% endfile %}

### Źródła

- [https://kenney.nl/](https://kenney.nl/)

## Nasz cel

![Asteroidy](../../../.gitbook/assets/asteroidsGame.gif)

Założenie gry jest proste: poruszamy statkiem u dołu ekranu, omijamy asteroidy, strzelamy do nich i zdobywamy punkty!
Powyższa animacja pokazuje, jak będzie wyglądać nasza gra.

# Wstępna konfiguracja

Zaczynamy standardowo: tworzymy nowy projekt, instalujemy bibliotekę, pobieramy materiały i umieszczamy je w odpowiednich miejscach.
Nasz projekt możemy nazwać np. "Asteroids" albo "Asteroidy". Gdy już utworzymy projekt, tworzymy w nim nowe katalogi *images*, *sounds* oraz *music*. Następnie pobieramy wyżej wymienione materiały, rozpakowujemy je, a zawartość przerzucamy do odpowiednich katalogów. Pozostało nam jeszcze zainstalować bibliotekę: w okienku terminala wypisujemy standardowo polecenie `pip install pgzero`.

## Podstawowy szablon

### Biblioteki

Na początek dopisujemy odpowiednie biblioteki do naszej gry.
Tym razem, poza standardowymi, będziemy jeszcze potrzebowali biblioteki **pygame**, żeby móc odczytać pozycję myszy na ekranie, a także żeby móc ukryć wskaźnik myszy.

```python
import pgzrun
import pygame
import random
```

### Przygotowujemy ekran gry

Na początek ustalamy rozmiar okna i wyświetlamy tło naszej gry z grafiki *bg.png* za pomocą funkcji `screen.blit` w części rysującej *draw*.
Rozmiar okna powinien być zgodny z rozmiarem grafiki tła, tzn. $$600\times900$$.

```python
WIDTH = 600
HEIGHT = 900


def draw():
    screen.blit("bg", (0, 0))
```

### Aktualizacja

Potrzebna jest nam jeszcze funkcja *update*, którą standardowo umieszczamy pod funkcją *draw* i wpisujemy w niej jedną instrukcję: **pass**.

```python
def update():
    pass
```

### Uruchomienie gry

Na końcu naszego kodu dopisujemy instrukcję `pgzrun.go()` uruchamiającą naszą grę.

### Pełny kod

```python
import pgzrun
import pygame
import random  # Biblioteka do liczb losowych


WIDTH = 600  # Ustawiamy szerokość okna gry
HEIGHT = 900  # Ustawiamy wysokość okna gry


def draw():  # Funkcja rysująca elementy gry
    screen.blit("bg", (0, 0))  # Rysujemy tło gry


def update():  # Funkcja aktualizująca elementy gry
    pass


pgzrun.go()  # Uruchamiamy grę
```

## Statek

Głównym aktorem naszej gry, w którego wcieli się gracz, będzie statek kosmiczny. Będziemy go wyświetlać na dole ekranu i poruszać na boki za pomocą myszy.

### Tworzymy statek

Naszego aktora tworzymy na górze, zaraz przed funkcją *draw*. Utworzymy go na podstawie grafiki *ship.png* i zapiszemy w zmiennej *ship*.

```python
ship = Actor("ship")
```

Statek umieścimy na środku ekranu ($$WIDTH / 2$$), na samym dole z zachowaniem marginesu $$60$$ pikseli ($$HEIGHT - 60$$).

```python
ship = Actor("ship")
ship.x = WIDTH / 2
ship.y = HEIGHT - 60
```

### Rysujemy statek

Gdy już mamy utworzonego aktora, możemy go wyświetlić na ekranie. Dopisujemy instrukcję rysującą statek (`ship.draw()`) na końcu funkcji *draw*.

```python
def draw():
    ...
    ship.draw()
```

### Poruszamy statkiem

Statkiem będziemy poruszać w lewo/prawo.
Nasza postać będzie sterowana za pomocą myszki: statek będzie leciał w kierunku, w którym znajduje się wskaźnik myszy. W tym celu musimy nadać naszemu statkowi jakąś prędkość poziomą. Dopiszemy więc do naszego statku zmienną **vx** z początkową wartością np. $$5$$, zaraz pod ustaleniem pozycji statku na ekranie.

```python
ship.vx = 5
```

W części aktualizującej usuwamy instrukcję *pass*. Na początku odczytamy aktualną pozycję wskaźnika myszy za pomocą funkcji `pygame.mouse.get_pos()` z biblioteki *pygame*. Ponieważ funkcja ta zwraca nam współrzędne wskaźnika myszy ($$x$$ oraz $$y$$), to jej wynik zapiszemy w dwóch zmiennych: **mouse_x** oraz **mouse_y**.

```python
def update():
    mouse_x, mouse_y = pygame.mouse.get_pos()
```

Teraz pozostało nam sprawdzić, z której strony znajduje się wskaźnik myszy względem statku: z lewej czy z prawej. Jeżeli współrzędna $$x$$ myszy jest mniejsza od współrzędnej $$x$$ statku, to znaczy, że mysz znajduje się z lewej strony statku. Dopisujemy więc instrukcję warunkową ze wspomnianym warunkiem na koniec funkcji *update*.

```python
def update():
    ...
    if mouse_x < ship.x:
```

Jeżeli tak jest, to powinniśmy statek przesunąć w lewo zgodnie z jego prędkością. W tym celu odejmujemy prędkość statku (**vx**) od jego współrzędnej $$x$$.

```python
def update():
    ...
    if mouse_x < ship.x:
        ship.x -= ship.vx
```

Podobnie postępujemy przy ruchu w prawą stronę. Zaczynamy od warunku: sprawdzamy, czy współrzędna $$x$$ myszy jest większa od współrzędnej $$x$$ statku.

```python
def update():
    ...
    if mouse_x > ship.x:
```

Poruszamy statkiem w prawo, tzn. dodajemy jego prędkość do pozycji $$x$$.

```python
def update():
    ...
    if mouse_x > ship.x:
        ship.x += ship.vx
```

Pełna funkcja *update* będzie więc wyglądała tak jak poniżej.

```python
def update():
    mouse_x, mouse_y = pygame.mouse.get_pos()
    if mouse_x < ship.x:
        ship.x -= ship.vx
    if mouse_x > ship.x:
        ship.x += ship.vx
```

### Pełny kod

```python
import pgzrun
import pygame
import random


WIDTH = 600
HEIGHT = 900

ship = Actor("ship")  # Tworzymy nowego aktora reprezentującego statek
ship.x = WIDTH / 2  # Ustawiamy pozycję poziomą statku na połowę szerokości ekranu
ship.y = HEIGHT - 60  # Ustawiamy statek na dole ekranu, z niewielkim marginesem
ship.vx = 5  # Zapamiętujemy prędkość poziomą statku


def draw():
    screen.blit("bg", (0, 0))
    ship.draw()  # Rysujemy statek na ekranie


def update():
    mouse_x, mouse_y = pygame.mouse.get_pos()  # Odczytujemy obecną pozycję wskaźnika myszy
    if mouse_x < ship.x:  # Jeżeli wskaźnik myszy jest z lewej strony statku
        ship.x -= ship.vx  # Przemieszczamy statek w lewo zgodnie z jego prędkością

    if mouse_x > ship.x:  # Jeżeli wskaźnik myszy jest z prawej strony statku
        ship.x += ship.vx  # Przemieszczamy statek w prawo zgodnie z jego prędkością


pgzrun.go()
```

## Asteroidy

Główne zagrożenie w naszej grze będą stanowić asteroidy "spadające" z góry ekranu.

### Przygotowujemy asteroidy

Czas przygotować asteroidy.
Chcemy, aby było w grze wyświetlało się kilka asteroid naraz. 
W tym celu potrzebna nam będzie **lista**. Lista pozwala nam przechowywać wiele elementów jeden po drugim, zapisanych w jednej zmiennej o typie listy właśnie.
Na początku tworzymy pustą listę, którą przechowamy w zmiennej **asteroids_list**. W celu utworzenia pustej listy do naszej zmiennej przypiszemy puste nawiasy kwadratowe: **[]**. Nową zmienną utworzymy pod statkiem, czyli zaraz nad funkcją *draw*.

```python
asteroids_list = []
```

Teraz utworzymy funkcję, za pomocą której będziemy dodawać losowe asteroidy w trakcie trwania gry.
Na początku asteroid będzie znajdował się nad ekranem, tak by efekt "spadania" wyglądał naturalniej. Na końcu naszego kodu, zaraz przed instrukcją *pgzrun.go()* tworzymy nową funkcję **add_asteroid**.

```python
def add_asteroid():
```

Na początku utworzymy nowego aktora z grafiki *asteroid1.png* i zapiszemy go w zmiennej **asteroid**.

```python
def add_asteroid():
    asteroid = Actor("asteroid1")
```

Przypiszmy teraz naszej asteroidzie właściwe współrzędne. Jako współrzędną $$x$$ przyjmiemy losową wartość z przedziału $$<20, WIDTH-20>$$ wylosowaną za pomocą funkcji `random.randint` z biblioteki *random*.


```python
def add_asteroid():
    ...
    asteroid.x = random.randint(20, WIDTH-20)
```

Do współrzędnej $$y$$ przypiszemy wartość $$-10$$, tak by nowa asteroida znalazła się ponad górną krawędzią ekranu.

```python
def add_asteroid():
    ...
    asteroid.y = -10
```

Teraz pozostało nam wylosować prędkość pionową, którą zapiszemy w asteroidzie w zmiennej $$vy$$. Wartość prędkości pionowej wylosujemy z przedziału $$<2, 10>$$, ponownie korzystając z funkcji `random.randint`.

```python
def add_asteroid():
    ...
    asteroid.vy = random.randint(2, 10)
```

Pozostało nam dopisać naszą nową asteroidę do listy asteroid. W tym celu skorzystamy z metody **append**, która dodaje nowy element do listy. Metodę tę wywołamy pisząc `asteroids_list.append` w nawiasach podając naszą nową asteroidę.

```python
def add_asteroid():
    ...
    asteroids_list.append(asteroid)
```

Nasza pełna funkcja *add_asteroid* przedstawiona jest poniżej.


```python
def add_asteroid():
    asteroid = Actor("asteroid1")
    asteroid.x = random.randint(20, WIDTH-20)
    asteroid.y = -10
    asteroid.vy = random.randint(2, 10)
    asteroids_list.append(asteroid)
```

### Dodajemy losowo asteroidy

W części aktualizującej (*update*) będziemy losowo dodawać asteroidy w każdej klatce, z odpowiednio małym prawdopodobieństwem. W tym celu sprawdzimy, czy wylosowana liczba rzeczywista z przedziału $$<0, 1)$$ jest mniejsza od jakiejś ustalonej wartości, np. $$0.02$$. Liczbę rzeczywistą wylosujemy za pomocą funkcji `random.random()`. Instrukcję warunkową z wspomnianym warunkiem dopisujemy na końcu funkcji *update*.

```python
def update():
    ...
    if random.random() < 0.02:
```

Jeżeli warunek jet spełniony to dodamy nową asteroidę wywołując naszą funkcję *add_asteroid*.

```python
def update():
    ...
    if random.random() < 0.02:
        add_asteroid()
```

### Rysujemy asteroidy

Teraz zajmiemy się rysowaniem asteroid na ekranie. W tym celu w części rysującej (*draw*) musimy ponownie przejść przez całą listę i narysować każdą asteroidę osobno. Wewnątrz funkcji *draw*, zaraz po wypełnieniu ekranu grafiką tła, a przed narysowaniem statku (tak żeby statek był zawsze na wierzchu), dopisujemy pętlę przechodzącą przez każdą asteroidę z listy asteroid.

```python
def draw():
    ...
    for asteroid in asteroids_list:
    ...
```

Wewnątrz pętli rysujemy asteroidy wywołując metodę *draw* na zmiennej *asteroid*.

```python
def draw():
    ...
    for asteroid in asteroids_list:
        asteroid.draw()
    ...
```

Pełna funkcja rysująca pokazana jest poniżej.

```python
def draw():
    screen.blit("bg", (0, 0))
    for asteroid in asteroids_list:
        asteroid.draw()
        
    ship.draw()
```

### Przemieszczamy asteroidy

Teraz czas na aktualizację pozycji asteroid. W tym celu musimy przejść przez wszystkie elementy naszej listy i dla każdego wykonać odpowiednie operacje. Robimy to w części aktualizującej. 

Ponieważ będziemy usuwać asteroidy, które wyleciały poza ekran, to w pętli musimy przejść przez **kopię** listy asteroid, którą tworzymy pisząc dwukropek w nawiasach kwadratowych po nazwie listy: `asteroids_list[:]`.

Dla zachowania porządku aktualizację asteroid zapiszemy w nowej funkcji **update_asteroids**, którą utworzymy zaraz pod funkcją *update*.

```python
def update_asteroids():
```

Zaczynamy od napisania pętli przechodzącej przez wszystkie asteroidy w kopii listy.

```python
def update_asteroids():
    for asteroid in asteroids_list[:]:
```

Dla każdej asteroidy będziemy przemieszczać ją zgodnie z jej prędkością, więc do jej współrzędnej $$y$$ dodajemy jej prędkość *vy*.

```python
def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
```

Żeby nasza gra nie spowalniała po pewnym czasie, powinniśmy na bieżąco usuwać asteroidy, których już nie widać na ekranie. Dlatego dopisujemy w pętli instrukcję warunkową sprawdzającą, czy asteroida wyleciała poza ekran, tzn. czy jej współrzędna $$y$$ jest większa od $$HEIGHT + 50$$ (dodajemy $$50$$ tak by cała asteroida zdążyła wylecieć poza ekran).

```python
def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
```

Jeżeli asteroida opuściła ekran gry to usuwamy ją z listy za pomocą metody **remove**, jako argument podając asteroidę do usunięcia, podobnie jak robiliśmy przy dodawaniu asteroidy do listy.

```python
def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)
```

Pozostało nam wywołać naszą nową funkcję na końcu funkcji *update*.

```python
def update():
    ...
    update_asteroids()
```

### Pełny kod

```python
import pgzrun
import pygame
import random


WIDTH = 600
HEIGHT = 900

ship = Actor("ship")
ship.x = WIDTH / 2
ship.y = HEIGHT - 60
ship.vx = 5

asteroids_list = []  # Lista, w której zapisujemy wszystkie asteroidy


def draw():
    screen.blit("bg", (0, 0))
    for asteroid in asteroids_list:  # Przechodzimy pętlą przez wszystkie asteroidy
        asteroid.draw()  # Rysujemy asteroidę na ekranie gry

    ship.draw()


def update():
    mouse_x, mouse_y = pygame.mouse.get_pos()
    if mouse_x < ship.x:
        ship.x -= ship.vx

    if mouse_x > ship.x:
        ship.x += ship.vx

    if random.random() < 0.02:  # Jeżeli wylosowaliśmy odpowiednio małą liczbę
        add_asteroid()  # Dodajemy nową asteroidę do gry

    update_asteroids()  # Aktualizujemy pozycje asteroid
    

def update_asteroids():  # Pomocnicza funkcja aktualizująca pozycję asteroid
    for asteroid in asteroids_list[:]:  # Przechodzimy przez kopię listy asteroid
        asteroid.y += asteroid.vy  # Przemieszczamy asteroidę zgodnie z jej prędkością
        if asteroid.y > HEIGHT + 50:  # Jeżeli asteroida wyleciała poza ekran
            asteroids_list.remove(asteroid)  # Usuwamy ją z listy asteroid


def add_asteroid():  # Pomocnicza funkcja dodająca nową asteroidę do gry
    asteroid = Actor("asteroid1")  # Tworzymy nowego aktora reprezentującego asteroidę
    asteroid.x = random.randint(20, WIDTH-20)  # Ustawiamy losową pozycję poziomą asteroidy
    asteroid.y = -10  # Ustawiamy pionową pozycję asteroidy tak, by była poza ekranem gry
    asteroid.vy = random.randint(2, 10)  # Ustawiamy losową pozycję asteroidy
    asteroids_list.append(asteroid)  # Dodajemy nową asteroidę do listy asteroid


pgzrun.go()
```

## Lasery

Nasz statek będzie strzelał laserami. To one będą pozwalały zniszczyć asteroidy, które stanowią zagrożenie.

### Przygotowujemy lasery

Podobnie jak asteroidy, także lasery będziemy przechowywać w liście. Tworzymy więc nową pustą listę, którą nazwiemy **lasers_list** i umieścimy zaraz pod listą asteroid.

```python
lasers_list = []
```

Teraz przyda nam się funkcja, która posłuży nam do dodawania nowych laserów do listy. Stworzymy więc pomocniczą funkcję **add_laser**, którą umieścimy zaraz pod funkcją *add_asteroid*.

```python
def add_laser():
```

Na początku funkcji utworzymy nowego aktora z grafiki *laser.png* i zapiszemy go w zmiennej o nazwie **laser**.

```python
def add_laser():
    laser = Actor("laser")
```

Teraz ustalimy początkową pozycję naszego lasera. Chcemy, żeby była taka sama jak pozycja statku, ponieważ to za jego pomocą strzelamy. W związku z tym do pozycji lasera (*laser.pos*) przypiszemy pozycję statku (*ship.pos*).

```python
def add_laser():
    ...
    laser.pos = ship.pos
```

Naszemu laserowi powinniśmy także nadać jakąś prędkość pionową (*laser.vy*), np. $$-8$$, by laser poruszał się do góry.

```python
def add_laser():
    ...
    laser.vy = -8
```

Wreszcie na końcu dodajemy nasz nowy laser do listy laserów (*lasers_list*) za pomocą metody *append*.

```python
def add_laser():
    ...
    lasers_list.append(laser)
```

Pełna funkcja dodająca nowy laser przedstawiona jest poniżej.

```python
def add_laser():
    laser = Actor("laser")
    laser.pos = ship.pos
    laser.vy = -8
    lasers_list.append(laser)
```

### Rysujemy lasery

Zanim przejdziemy do strzelania, narysujmy nasze lasery na ekranie. Oczywiście jeszcze nie mamy laserów do narysowania, ale gdy już będziemy mogli strzelać, to je zobaczymy. Wewnątrz funkcji `draw`, zaraz przed narysowaniem statku, a pod narysowaniem asteroid, dopisujemy pętlę przechodzącą przez wszystkie lasery na liście *lasers_list*.

```python
def draw():
    ...
    for laser in lasers_list:
    ...
```

Wewnątrz pętli będziemy rysować nasze lasery.

```python
def draw():
    ...
    for laser in lasers_list:
        laser.draw()
    ...
```

Pełna funkcja rysująca pokazana jest poniżej.

```python
def draw():
    screen.blit("bg", (0, 0))
    for asteroid in asteroids_list:
        asteroid.draw()

    for laser in lasers_list:
        laser.draw()

    ship.draw()
```

### Strzelamy

Czas na strzelanie laserami! Strzały będziemy oddawać po każdym kliknięciu myszy. Kliknięcia myszy odczytujemy za pomocą funkcji *on_mouse_down* z biblioteki *Pygame Zero*. Dopisujemy więc nową funkcję, na końcu naszego kodu, zaraz przed instrukcją `pgzrun.go()`.

```python
def on_mouse_down(pos):
```

Wewnątrz funkcji wywołamy naszą funkcję *add_laser*, aby dodać nowy laser do gry.

```python
def on_mouse_down(pos):
    add_laser()
```

Warto także skorzystać z dźwięku *laser* pisząc instrukcję `sounds.laser.play()`.

```python
def on_mouse_down(pos):
    add_laser()
    sounds.laser.play()
```

### Przemieszczamy lasery

W tym momencie nasze lasery są dość statyczne. Chcielibyśmy, żeby się poruszały, jak to lasery mają w zwyczaju, a przynajmniej tak przedstawiają to filmy science-fiction. Z laserami postąpimy podobnie jak z asteroidami i dodamy nową funkcję **update_lasers**, którą dla zachowania porządku dopiszemy zaraz pod funkcją *update_asteroids*.

```python
def update_lasers():
```

Chcemy aktualizować pozycję wszystkich laserów, potrzebna nam więc pętla przechodząca przez wszystkie lasery na liście *lasers_list*. Nasze lasery będziemy jednak usuwać, gdy wylecą poza ekran, więc potrzebna nam **kopia** listy, którą tworzymy pisząc **lasers_list[:]**, podobnie jak w przypadku asteroid.

```python
def update_lasers():
    for laser in lasers_list[:]:
```

Wewnątrz pętli przemieszczamy nasz laser zgodnie z jego prędkością, więc do współrzędnej $$y$$ dodajemy prędkość pionową lasera (*laser.vy*).

```python
def update_lasers():
    for laser in lasers_list[:]:
        laser.y += laser.vy
```

Teraz pora sprawdzić, czy laser wyleciał poza ekran. W tym celu sprawdzimy, czy jego pozycja $$y$$ jest mniejsza od ujemnej wartości jego wysokości. W ten sposób upewnimy się, że cały laser wyleciał poza ekran, a nie tylko jego część. Wysokość lasera możemy odczytać pisząc `laser.height`. Dopisujemy więc instrukcję warunkową.

```python
def update_lasers():
    for laser in lasers_list[:]:
        laser.y += laser.vy
        if laser.y < -laser.height:
```

Jeżeli laser wyleci poza ekran, to chcemy go usunąć z listy laserów i tym samym z naszej gry. Korzystamy więc z metody **remove**, tak jak wcześniej przy asteroidach.

```python
def update_lasers():
    for laser in lasers_list[:]:
        laser.y += laser.vy
        if laser.y < -laser.height:
            lasers_list.remove(laser)
```

Pozostało nam wywołać naszą nową funkcję na końcu funkcji *update*, tak by nasze lasery były aktualizowane.

```python
def update():
    ...
    update_lasers()
```

### Niszczymy asteroidy

Cóż to za lasery, które nie niszczą asteroid? Można powiedzieć, że są to całkowicie normalne lasery, ale nie w naszej grze! Czas zniszczyć kilka asteroid. W tym celu utworzymy nową funkcję **update_lasers_hits**, którą dopiszemy zaraz pod naszą poprzednią funkcją *update_lasers*.

```python
def update_lasers_hits():
```

Dla każdego laseru będziemy sprawdzać, czy trafił on w którąś z asteroid. Jeżeli tak, to usuniemy zarówno laser jak i asteroidę. Dopisujemy więc pętlę, która przejdzie przez wszystkie lasery w **kopii** listy *lasers_list*.

```python
def update_lasers_hits():
    for laser in lasers_list[:]:
```

Asteroid mamy wiele, jak więc sprawdzić, czy w którąś trafił laser? Potrzebna nam kolejna pętla, która przejdzie przez wszystkie asteroidy w **kopii** listy *asteroids_list*.

```python
def update_lasers_hits():
    for laser in lasers_list[:]:
        for asteroid in asteroids_list[:]:
```

Mamy już zarówno laser jak i asteroidę. Sprawdźmy więc, czy są w kolizji! W tym celu skorzystamy ze znanej nam funkcji *colliderect*.

```python
def update_lasers_hits():
    for laser in lasers_list[:]:
        for asteroid in asteroids_list[:]:
            if laser.colliderect(asteroid):
```

Jeżeli laser trafił w asteroidę, to usuwamy zarówno laser jak i asteroidę z odpowiednich list za pomocą metody *remove*.

```python
def update_lasers_hits():
    for laser in lasers_list[:]:
        for asteroid in asteroids_list[:]:
            if laser.colliderect(asteroid):
                lasers_list.remove(laser)
                asteroids_list.remove(asteroid)
```

Dopiszmy teraz wywołanie naszej nowej funkcji na koniec funkcji *update*.

```python
def update():
    ...
    update_lasers_hits()
```

Gdybyśmy teraz przetestowali naszą grę, to może się zdarzyć, że czasem wyłączy się z komunikatem błędu w konsoli. Dzieje się tak, gdy laser trafi w jedną asteroidę, usuniemy go z listy, ale jest także jednocześnie w kolizji z jeszcze inną asteroidą. Wówczas spróbujemy usunąć ten sam laser drugi raz, ale przecież już go wcześniej usunęliśmy, więc próba usunięcia usuniętego lasera zakończy się błędem. Możemy jednak temu zapobiec w bardzo prosty sposób. Wystarczy że dopiszemy do naszej funkcji *update_lasers_hits* instrukcję **break** zaraz po usunięciu lasera i asteroidy. Instrukcja **break** sprawi, że wyjdziemy z pętli przechodzącej po wszystkich asteroidach i przejdziemy do kolejnego lasera.

```python
def update_lasers_hits():
    for laser in lasers_list[:]:
        for asteroid in asteroids_list[:]:
            if laser.colliderect(asteroid):
                lasers_list.remove(laser)
                asteroids_list.remove(asteroid)
                break
```

### Pełny kod

```python
import pgzrun
import pygame
import random


WIDTH = 600
HEIGHT = 900

ship = Actor("ship")
ship.x = WIDTH / 2
ship.y = HEIGHT - 60
ship.vx = 5

asteroids_list = []
lasers_list = []  # Lista, w której zapisujemy wszystkie lasery


def draw():
    screen.blit("bg", (0, 0))
    for asteroid in asteroids_list:
        asteroid.draw()

    for laser in lasers_list:  # Przechodzimy przez wszystkie lasery na liście
        laser.draw()  # Rysujemy laser na ekranie gry

    ship.draw()
    

def update():
    mouse_x, mouse_y = pygame.mouse.get_pos()
    if mouse_x < ship.x:
        ship.x -= ship.vx

    if mouse_x > ship.x:
        ship.x += ship.vx

    if random.random() < 0.02:
        add_asteroid()

    update_asteroids()
    update_lasers()  # Aktualizujemy pozycje laserów
    update_lasers_hits()  # Aktualizujemy trafienia laserów w asteroidy
    

def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)


def update_lasers():  # Pomocnicza funkcja aktualizująca pozycje laserów
    for laser in lasers_list[:]:  # Przechodzimy przez wszystkie lasery na liście
        laser.y += laser.vy  # Przemieszczamy laser zgodnie z jego prędkością
        if laser.y < -laser.height:  # Jeżeli laser wyleciał poza ekran
            lasers_list.remove(laser)  # Usuwamy laser z gry


def update_lasers_hits():  # Pomocnicza funkcja sprawdzająca uderzenia laserów w asteroidy
    for laser in lasers_list[:]:  # Przechodzimy przez wszystkie lasery na liście
        for asteroid in asteroids_list[:]:  # Przechodzimy przez wszystkie asteroidy na liście
            if laser.colliderect(asteroid):  # Sprawdzamy, czy laser trafił w asteroidę
                lasers_list.remove(laser)  # Usuwamy laser z gry
                asteroids_list.remove(asteroid)  # Usuwamy asteroidę z gry
                break  # Kończymy pętlę przechodzącą po asteroidach i przechodzimy do kolejnego lasera


def add_asteroid():
    asteroid = Actor("asteroid1")
    asteroid.x = random.randint(20, WIDTH-20)
    asteroid.y = -10
    asteroid.vy = random.randint(2, 10)
    asteroids_list.append(asteroid)


def add_laser():  # Pomocnicza funkcja dodająca nowy laser do gry
    laser = Actor("laser")  # Tworzymy nowego aktora reprezentującego laser
    laser.pos = ship.pos  # Ustawiamy pozycję lasera na pozycję statku
    laser.vy = -8  # Ustawiamy prędkość lasera
    lasers_list.append(laser)  # Dodajemy laser do listy laserów


def on_mouse_down(pos):  # Funkcja odczytująca kliknięcia myszy
    add_laser()  # Dodajemy nowy laser do gry
    sounds.laser.play()  # Odtwarzamy dźwięk oddania strzału


pgzrun.go()
```

## Punkty

Czas na zdobywanie i zliczanie punktów! Punkty zapamiętamy w naszym statku w zmiennej *points*, dopisujemy więc nową zmienną do statku zaraz pod instrukcją przypisującą prędkość poziomą statkowi (`ship.vx = 5`).

```python
ship.points = 0
```

Zanim przejdziemy do zliczania punktów, wyświetlmy je na ekranie. Dopiszemy więc instrukcję *screen.draw.text* na końcu funkcji *draw*. 

```python
def draw():
    ...
    screen.draw.text()
```

Punkty zapisane w statku są liczbą, zamieniamy je więc na tekst za pomocą funkcji **str**.

```python
def draw():
    ...
    screen.draw.text(str(ship.points))
```

Środek (*center*) naszych punktów umieścimy w połowie szerokości ekranu ($$WIDTH / 2$$) na samej górze, zachowując niewielki margines ($$20$$).

```python
def draw():
    ...
    screen.draw.text(str(ship.points), center=(WIDTH / 2, 20))
```

Rozmiar czcionki (*fontsize*) ustawimy na $$50$$.

```python
def draw():
    ...
    screen.draw.text(str(ship.points), center=(WIDTH / 2, 20), fontsize=50)
```

Pozostało nam ustawić kolor (*color*) na żółty (*yellow*).

```python
def draw():
    ...
    screen.draw.text(str(ship.points), center=(WIDTH / 2, 20), fontsize=50, color="yellow")
```

Teraz punkty powinny być widoczne na ekranie. Możemy przejść do ich zliczania. Będziemy dostawać po jednym punkcie za każdą zniszczoną asteroidę. Asteroidy niszczymy w naszej funkcji *update_laser_hits*. Dlatego jak już usuniemy asteroidę z listy, zaraz przed instrukcją *break*, dodamy jeden punkt do *ship.points*.

```python
def update_lasers_hits():
    for laser in lasers_list[:]:
        for asteroid in asteroids_list[:]:
            if laser.colliderect(asteroid):
                ...
                ship.points += 1
                break
```

### Pełny kod

```python
import pgzrun
import pygame
import random


WIDTH = 600
HEIGHT = 900

ship = Actor("ship")
ship.x = WIDTH / 2
ship.y = HEIGHT - 60
ship.vx = 5
ship.points = 0  # Zapamiętujemy liczbę zdobytych punktów

asteroids_list = []
lasers_list = []


def draw():
    screen.blit("bg", (0, 0))
    for asteroid in asteroids_list:
        asteroid.draw()

    for laser in lasers_list:
        laser.draw()

    ship.draw()
    screen.draw.text(str(ship.points), center=(WIDTH / 2, 20), fontsize=50, color="yellow")  # Wyświetlamy liczbę zdoboytych punktów na ekranie gry
    

def update():
    mouse_x, mouse_y = pygame.mouse.get_pos()
    if mouse_x < ship.x:
        ship.x -= ship.vx

    if mouse_x > ship.x:
        ship.x += ship.vx

    if random.random() < 0.02:
        add_asteroid()

    update_asteroids()
    update_lasers()
    update_lasers_hits()
    

def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)


def update_lasers():
    for laser in lasers_list[:]:
        laser.y += laser.vy
        if laser.y < -laser.height:
            lasers_list.remove(laser)


def update_lasers_hits():
    for laser in lasers_list[:]:
        for asteroid in asteroids_list[:]:
            if laser.colliderect(asteroid):
                lasers_list.remove(laser)
                asteroids_list.remove(asteroid)
                ship.points += 1  # Zwiększamy liczbę punktów po zestrzeleniu asteroidy
                break


def add_asteroid():
    asteroid = Actor("asteroid1")
    asteroid.x = random.randint(20, WIDTH-20)
    asteroid.y = -10
    asteroid.vy = random.randint(2, 10)
    asteroids_list.append(asteroid)


def add_laser():
    laser = Actor("laser")
    laser.pos = ship.pos
    laser.vy = -8
    lasers_list.append(laser)


def on_mouse_down(pos):
    add_laser()
    sounds.laser.play()


pgzrun.go()
```

## Życia

Czas dodać życia do naszej gry. Te będziemy reprezentować za pomocą grafik małego statku, umieszczonych w lewym górnym rogu.

Na początku dopiszmy liczbę żyć do naszego statku. Zaraz pod punktami statku dopiszemy jego życia zapisane w zmiennej *lifes*. Początkowo będziemy mieć trzy życia.

```python
ship.lifes = 3
```

### Rysujemy życia

Jak już wspomnieliśmy, życia narysujemy w lewym górnym rogu ekranu za pomocą grafik małego statku. Grafika, której użyjemy, nazywa się *life.png*. Do rysowania żyć stworzymy pomocniczą funkcję *draw_lifes*, którą umieścimy zaraz pod funkcją *draw*.

```python
def draw_lifes():
```

Będziemy rysować tyle żyć, na ile wskazuje zmienna *ship.lifes*. W związku z tym potrzebna nam pętla. Użyjemy pętli *for* z licznikiem *life_id*, który będzie oznaczał numer obecnie rysowanego życia, a jako zakres przejdziemy od $$1$$ do liczby żyć statku włącznie, czyli  `range(1, ship.lifes + 1)`.

```python
def draw_lifes():
    for life_id in range(1, ship.lifes + 1):
```

Wewnątrz pętli zaczniemy od utworzenia nowego aktora na podstawie grafiki *life.png*. Zapiszemy go w zmiennej **life**.

```python
def draw_lifes():
    for life_id in range(1, ship.lifes + 1):
        life = Actor("life")
```

Teraz czas wyznaczyć współrzędne naszego życia. Ponieważ chcemy, by były ułożone obok siebie w jednej linii, to współrzędna $$x$$ będzie zależna od numeru aktualnie rysowanego życia. Narysujemy życia tak, aby były obok siebie, ale na siebie nie nachodziły. Dlatego wartość współrzędnej poziomej to nic innego jak numer życia przemnożony przez szerokość grafiki życia. Szerokość grafiki aktora możemy łatwo poznać pisząc **life.width**.

```python
def draw_lifes():
    for life_id in range(1, ship.lifes + 1):
        life = Actor("life")
        life.x = life_id * life.width
```

Jeżeli chodzi o położenie w pionie, to nasze życia będą dotykać górnego brzegu ekranu, ale nie powinny poza niego wychodzić. W tym celu do współrzędnej $$y$$ przypiszemy połowę wysokości grafiki życia. Wysokość grafiki aktora możemy pobrać podobnie jak szerokość: **life.height**.

```python
def draw_lifes():
    for life_id in range(1, ship.lifes + 1):
        life = Actor("life")
        life.x = life_id * life.width
        life.y = life.height / 2
```

Pozostało nam narysować naszego aktora na ekranie korzystając z metody *draw*.

```python
def draw_lifes():
    for life_id in range(1, ship.lifes + 1):
        life = Actor("life")
        life.x = life_id * life.width
        life.y = life.height / 2
        life.draw()
```

Na koniec wywołamy naszą nową funkcję pomocniczą wewnątrz funkcji rysującej *draw*, by zobaczyć zmiany na ekranie. Życia narysujemy na samym końcu funkcji *draw*, tak by były zawsze na wierzchu.

```python
def draw():
    ...
    draw_lifes()
```

### Tracimy życia

Życia będziemy tracić za każdą kolizję z asteroidą, najpierw jednak musimy te kolizje wykrywać. W tym celu zmodyfikujemy naszą funkcję *update_asteroids*, w której przemieszczamy asteroidy. Na końcu tej funkcji mamy instrukcję warunkową sprawdzającą, czy asteroida wyleciała poza ekran. Dopiszemy do niej kolejny warunek korzystając z instrukcji **elif**.

```python
def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)
        elif
```

Jako warunek sprawdzimy, czy asteroida jest w kolizji ze statkiem, korzystając z metody **colliderect**.

```python
def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)
        elif asteroid.colliderect(ship):
```

Jeżeli asteroida uderzyła w statek, to stracimy jedno życie.

```python
def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)
        elif asteroid.colliderect(ship):
            ship.lifes -= 1
```

Usuniemy także asteroidę, tak by nie stanowiła już zagrożenia.

```python
def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)
        elif asteroid.colliderect(ship):
            ship.lifes -= 1
            asteroids_list.remove(asteroid)
```

Dopiszemy także użycie odpowiedniego dźwięku po uderzeniu asteroidy w statek. Do dyspozycji mamy dwa dźwięki: odgłos tarczy (*shield*) oraz odgłos wybuchu (*explosion*). Pierwszego użyjemy, gdy statek ma jeszcze jakieś życia. Będzie to symulować uderzenie asteroidy w tarcze ochronne statku. W tym celu dopisujemy instrukcję warunkową (*if*) sprawdzającą, czy statek ma więcej żyć niż zero (*ship.lifes > 0*).

```python
def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)
        elif asteroid.colliderect(ship):
            ship.lifes -= 1
            asteroids_list.remove(asteroid)
            if ship.lifes > 0:
```

Jeżeli tak, to odtwarzamy dźwięk tarczy: `sounds.shield.play()`.

```python
def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)
        elif asteroid.colliderect(ship):
            ship.lifes -= 1
            asteroids_list.remove(asteroid)
            if ship.lifes > 0:
                sounds.shield.play()
```

W przeciwnym przypadku (*else*), tzn. gdy życia się już skończyły, odtworzymy odgłos wybuchu: `sounds.explosion.play()`.

```python
def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)
        elif asteroid.colliderect(ship):
            ship.lifes -= 1
            asteroids_list.remove(asteroid)
            if ship.lifes > 0:
                sounds.shield.play()
            else:
                sounds.explosion.play()
```

### Koniec gry

Nasza gra zakończy się, gdy stracimy wszystkie życia. Wówczas powinniśmy wyświetlić komunikat **GAME OVER** oraz zakończyć aktualizację naszej gry. Zaczniemy od wyświetlenia komunikatu.

Na końcu funkcji rysującej *draw* sprawdzimy, korzystając z instrukcji warunkowej, czy straciliśmy wczystkie życia, czli czy wartość żyć jest mniejsza bądź równa zero.

```python
def draw():
    ...
    if ship.lifes <= 0:
```

Wówczas wyświetlimy stosowny komunikat na środku ekranu. Możemy go wyświetlić w żółtym kolorze z czcionką o rozmiarze $$90$$.

```python
def draw():
    ...
    if ship.lifes <= 0:
        screen.draw.text("GAME OVER", center=(WIDTH / 2, HEIGHT / 2), fontsize=90, color="yellow")
```

Przejdźmy teraz do zatrzymania naszej gry. W tym celu na początku funkcji *update* sprawdzimy, podobnie jak to zrobiliśmy przed chwilą, czy starciliśmy wszystkie życia.

```python
def update():
    if ship.lifes <= 0:

    ...
```

Jeżeli tak, to zakończymy działanie naszej funkcji korzystając z instrukcji **return**, tak by pozostałe akcje w niej zawarte nie zostały wykonane.

```python
def update():
    if ship.lifes <= 0:
        return

    ...
```

### Pełny kod

```python
import pgzrun
import pygame
import random


WIDTH = 600
HEIGHT = 900

ship = Actor("ship")
ship.x = WIDTH / 2
ship.y = HEIGHT - 60
ship.vx = 5
ship.points = 0
ship.lifes = 3  # Zapamiętujemy liczbę dostępnych żyć

asteroids_list = []
lasers_list = []


def draw():
    screen.blit("bg", (0, 0))
    for asteroid in asteroids_list:
        asteroid.draw()

    for laser in lasers_list:
        laser.draw()

    ship.draw()
    screen.draw.text(str(ship.points), center=(WIDTH / 2, 20), fontsize=50, color="yellow")
    draw_lifes()  # Rysujemy życia na ekranie
    if ship.lifes <= 0:  # Jeżeli skończyły nam się życia
        screen.draw.text("GAME OVER", center=(WIDTH / 2, HEIGHT / 2), fontsize=90, color="yellow")  # Wyświetlamy napis "GAME OVER" na środku ekranu gry
    

def draw_lifes():  # Pomocnicza funkcja rysująca życia
    for life_id in range(1, ship.lifes + 1):  # Przechodzimy pętlą od jeden do liczby dostępnych żyć włącznie
        life = Actor("life")  # Tworzymy aktora reprezentującego życie
        life.x = life_id * life.width  # Ustawiamy pozycję poziomą aktora
        life.y = life.height / 2  # Ustawiamy pozycję aktora w pionie
        life.draw()  # Rysujemy życie na ekranie


def update():
    if ship.lifes <= 0:  # Jeżeli skończyły nam się życia
        return  # Kończymy działanie funkcji

    mouse_x, mouse_y = pygame.mouse.get_pos()
    if mouse_x < ship.x:
        ship.x -= ship.vx

    if mouse_x > ship.x:
        ship.x += ship.vx

    if random.random() < 0.02:
        add_asteroid()

    update_asteroids()
    update_lasers()
    update_lasers_hits()
    

def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)
        elif asteroid.colliderect(ship):  # Sprawdzamy, czy asteroida zderzyła się ze statkiem
            ship.lifes -= 1  # Zmniejszamy liczbę pozostałych żyć
            asteroids_list.remove(asteroid)  # Usuwamy asteroidę z gry
            if ship.lifes > 0:  # Jeżeli pozostały jeszcze jakieś życia
                sounds.shield.play()  # Odtwarzamy dźwięk tarczy
            else:  # W przeciwnym przypadku, gdy życia się już skończyły
                sounds.explosion.play()  # Odtwarzamy dźwięk wybuchu


def update_lasers():
    for laser in lasers_list[:]:
        laser.y += laser.vy
        if laser.y < -laser.height:
            lasers_list.remove(laser)


def update_lasers_hits():
    for laser in lasers_list[:]:
        for asteroid in asteroids_list[:]:
            if laser.colliderect(asteroid):
                lasers_list.remove(laser)
                asteroids_list.remove(asteroid)
                ship.points += 1
                break


def add_asteroid():
    asteroid = Actor("asteroid1")
    asteroid.x = random.randint(20, WIDTH-20)
    asteroid.y = -10
    asteroid.vy = random.randint(2, 10)
    asteroids_list.append(asteroid)


def add_laser():
    laser = Actor("laser")
    laser.pos = ship.pos
    laser.vy = -8
    lasers_list.append(laser)


def on_mouse_down(pos):
    add_laser()
    sounds.laser.play()


pgzrun.go()
```

## Amunicja

Obecnie w naszej grze możemy strzelać praktycznie w nieskończoność, co znacząco ułatwia rozgrywkę. Pora to zmienić, ograniczając amunicję statku. W tym celu dopiszemy do statku nową zmienną **ammunition** o wartości $$5$$. Dopiszemy ją zaraz pod liczbą żyć.

```python
ship.ammunition = 5
```

### Zużywamy amunicję

Każdy oddany strzał będzie nas kosztował jedną jednostkę amunicji. W tym celu, po każdym strzale zmniejszymy wartość zmiennej *ammunition* przypisanej do statku. Strzelanie realizujemy wewnątrz funkcji *on_mouse_down* i właśnie tam dopiszemy zmniejszanie liczby amunicji, na samym końcu funkcji.

```python
def on_mouse_down(pos):
    ...
    ship.ammunition -= 1
```

### Ograniczamy strzelanie

Gdy amunicja się skończy, nie powinniśmy móc już oddawać kolejnych strzałów. Dlatego na początku naszej odpowiedzialnej za oddawanie strzałów funkcji *on_mouse_down* dopiszemy instrukcję warunkową sprawdzającą, czy amunicja jest mniejsza bądź równa zero.

```python
def on_mouse_down(pos):
    if ship.ammunition <= 0:

    ...
```

Jeżeli tak, to zakończymy działanie funkcji korzystając z instrukcji **return**, podobnie jak zrobiliśmy to w funkcji *update*.

```python
def on_mouse_down(pos):
    if ship.ammunition <= 0:
        return

    ...
```

### Odzyskujemy amunicję

Cóż to za gra, w której można oddać tylko $$5$$ strzałów? Powinniśmy jakoś odzyskiwać naszą straconą amunicję. Ponieważ nasz statek wystrzeliwuje lasery, to można sobie wyobrazić, że zużywa to energię, którą z czasem możemy zregenerować. Dlatego amunicję będziemy odzyskiwać po jednej sekundzie od każdego oddanego strzału. Zanim jednak do tego przejdziemy, będziemy potrzebować nowej pomocniczej funkcji, którą nazwiemy **regenerate_ammo** i dopiszemy ją na samym końcu, zaraz przed instrukcją `pgzrun.go()`.

```python
def regenerate_ammo():
```

Nasza funkcja ma tylko jeden cel: zwiększać amunicję statku o jedną jednostkę.

```python
def regenerate_ammo():
    ship.ammunition += 1
```

Teraz możemy przejść do właściwej regeneracji. Do tego skorzystamy z wbudowanego w bibliotekę *Pygame Zero* mechanizmu **zegara** (*clock*). Mechanizm ten pozwala nam ustawić (*schedule*) wywołanie wybranej funkcji po okreśonej liczbie sekund. Zapiszemy to w następujący sposób: `clock.schedule(regenerate_ammo, 1)`. Pierwszy parametr oznacza nazwę funkcji do wywołania (zauważ, że nie podajemy nawiasów po jej nazwie), drugi to natomiast liczba sekund, po której funkcja ma zostać wywołana.

Ustawienie wywołania funkcji regenerującej amunicję dopiszemy na koniec funkcji *on_mouse_down*, tak by regeneracja następowała po każdym oddanym strzale. Dzięki temu zawsze będziemy mieć co najwyżej pięć jednostek amunicji.

```python
def on_mouse_down(pos):
    ...
    clock.schedule(regenerate_ammo, 1)
```

### Pełny kod

```python
import pgzrun
import pygame
import random


WIDTH = 600
HEIGHT = 900

ship = Actor("ship")
ship.x = WIDTH / 2
ship.y = HEIGHT - 60
ship.vx = 5
ship.points = 0
ship.lifes = 3
ship.ammunition = 5  # Liczba dostępnej amunicji

asteroids_list = []
lasers_list = []


def draw():
    screen.blit("bg", (0, 0))
    for asteroid in asteroids_list:
        asteroid.draw()

    for laser in lasers_list:
        laser.draw()

    ship.draw()
    screen.draw.text(str(ship.points), center=(WIDTH / 2, 20), fontsize=50, color="yellow")
    draw_lifes()
    if ship.lifes <= 0:
        screen.draw.text("GAME OVER", center=(WIDTH / 2, HEIGHT / 2), fontsize=90, color="yellow")
    

def draw_lifes():
    for life_id in range(1, ship.lifes + 1):
        life = Actor("life")
        life.x = life_id * life.width
        life.y = life.height / 2
        life.draw()


def update():
    if ship.lifes <= 0:
        return

    mouse_x, mouse_y = pygame.mouse.get_pos()
    if mouse_x < ship.x:
        ship.x -= ship.vx

    if mouse_x > ship.x:
        ship.x += ship.vx

    if random.random() < 0.02:
        add_asteroid()

    update_asteroids()
    update_lasers()
    update_lasers_hits()
    

def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)
        elif asteroid.colliderect(ship):
            ship.lifes -= 1
            asteroids_list.remove(asteroid)
            if ship.lifes > 0:
                sounds.shield.play()
            else:
                sounds.explosion.play()


def update_lasers():
    for laser in lasers_list[:]:
        laser.y += laser.vy
        if laser.y < -laser.height:
            lasers_list.remove(laser)


def update_lasers_hits():
    for laser in lasers_list[:]:
        for asteroid in asteroids_list[:]:
            if laser.colliderect(asteroid):
                lasers_list.remove(laser)
                asteroids_list.remove(asteroid)
                ship.points += 1
                break


def add_asteroid():
    asteroid = Actor("asteroid1")
    asteroid.x = random.randint(20, WIDTH-20)
    asteroid.y = -10
    asteroid.vy = random.randint(2, 10)
    asteroids_list.append(asteroid)


def add_laser():
    laser = Actor("laser")
    laser.pos = ship.pos
    laser.vy = -8
    lasers_list.append(laser)


def on_mouse_down(pos):
    if ship.ammunition <= 0:  # Jeżeli nie mamy już amunicji
        return  # Kończymy działanie funkcji, w ten sposób nie oddając już strzału

    add_laser()
    sounds.laser.play()
    ship.ammunition -= 1  # Zmniejszamy liczbę pozostałej amunicji o jeden
    clock.schedule(regenerate_ammo, 1)  # Ustawiamy wywołanie regeneracji amunicji po upłynięciu jednej sekundy


def regenerate_ammo():  # Pomocnicza funkcja regenerująca amunicję
    ship.ammunition += 1  # Regenerujemy amunicję dodając wartość 1 do zmiennej ammunition zapisanej w statku


pgzrun.go()
```

## Końcowe poprawki

Na koniec zrobimy jeszcze kilka rzeczy: ukryjemy wskaźnik myszy, odtworzymy muzykę w tle i wybierzemy losową grafikę dla asteroid.

### Ukrywamy wskaźnik myszy

Ukrycie wskaźnika myszy zapiszemy na samym końcu naszego kodu, zaraz przed instrukcją `pgzrun.go()`. Aby ukryć wskaźnik skorzystamy z metody **pygame.mouse.set_visible** z biblioteki *Pygame*. Jako parametr, w okrągłych nawiasach, podamy wartość **False**, która oznacza, że wskaźnik myszy nie ma być widoczny.

```python
pygame.mouse.set_visible(False)
```

### Odtwarzamy muzykę

Odtworzenie muzyki również zapiszemy na końcu kody, zaraz przed instrukcją `pgzrun.go()`. Zrobimy to korzystając z metody **music.play**, jako parametr podając nazwę pliku dźwiękowego z katalogu *music*. Nasza muzyka będzie odtwarzana w pętli przez cały czas trwania rozgrywki.

```python
music.play("space")
```

Ponieważ muzyka może być dość głośna, to warto ustawić jej głośność na wartość $$0.3$$, korzystając zmetody **music.set_volume**.

```python
music.play("space")
music.set_volume(0.3)
```

### Losowa grafika dla asteroid

Gdy przyjrzymy się naszym grafikom to zobaczymy, że mamy kilka grafik przedstawiających asteroidy. Grafiki ponumerowane są od $$1$$ do $$4$$. My natomiast używamy tylko pierwszej grafiki. CZas to zmienić! W tym celu zmodyfikujemy naszą funkcję *add_asteroid* dodającą nową asteroidę do gry. Na samym jej początku wylosujemy losową liczbę z przedziału od $$1$$ do $$4$$ za pomocą metody **random.randint** i zapiszemy ją w zmiennej **image_id**.

```python
def add_asteroid():
    image_id = random.randint(1, 4)
    ...
```

Teraz pozostało nam zmodyfikować linijkę tworzącą nowego aktora reprezentującego asteroidę. Z nazwy grafiki usuniemy liczbę $$1$$ pozostawiając sam wyraz *asteroid*, do którego dopiszemy naszą liczbę *image_id* zamienioną na tekst (*str(image_id)*).

```python
def add_asteroid():
    image_id = random.randint(1, 4)
    asteroid = Actor("asteroid" + str(image_id))
    ...
```

### Pełny kod

```python
import pgzrun
import pygame
import random


WIDTH = 600
HEIGHT = 900

ship = Actor("ship")
ship.x = WIDTH / 2
ship.y = HEIGHT - 60
ship.vx = 5
ship.points = 0
ship.lifes = 3
ship.ammunition = 5

asteroids_list = []
lasers_list = []


def draw():
    screen.blit("bg", (0, 0))
    for asteroid in asteroids_list:
        asteroid.draw()

    for laser in lasers_list:
        laser.draw()

    ship.draw()
    screen.draw.text(str(ship.points), center=(WIDTH / 2, 20), fontsize=50, color="yellow")
    draw_lifes()
    if ship.lifes <= 0:
        screen.draw.text("GAME OVER", center=(WIDTH / 2, HEIGHT / 2), fontsize=90, color="yellow")
    

def draw_lifes():
    for life_id in range(1, ship.lifes + 1):
        life = Actor("life")
        life.x = life_id * life.width
        life.y = life.height / 2
        life.draw()


def update():
    if ship.lifes <= 0:
        return

    mouse_x, mouse_y = pygame.mouse.get_pos()
    if mouse_x < ship.x:
        ship.x -= ship.vx

    if mouse_x > ship.x:
        ship.x += ship.vx

    if random.random() < 0.02:
        add_asteroid()

    update_asteroids()
    update_lasers()
    update_lasers_hits()
    

def update_asteroids():
    for asteroid in asteroids_list[:]:
        asteroid.y += asteroid.vy
        if asteroid.y > HEIGHT + 50:
            asteroids_list.remove(asteroid)
        elif asteroid.colliderect(ship):
            ship.lifes -= 1
            asteroids_list.remove(asteroid)
            if ship.lifes > 0:
                sounds.shield.play()
            else:
                sounds.explosion.play()


def update_lasers():
    for laser in lasers_list[:]:
        laser.y += laser.vy
        if laser.y < -laser.height:
            lasers_list.remove(laser)


def update_lasers_hits():
    for laser in lasers_list[:]:
        for asteroid in asteroids_list[:]:
            if laser.colliderect(asteroid):
                lasers_list.remove(laser)
                asteroids_list.remove(asteroid)
                ship.points += 1
                break


def add_asteroid():
    image_id = random.randint(1, 4)  # Losujemy numer grafiki asteroidy
    asteroid = Actor("asteroid" + str(image_id))  # Tworzymy nowego aktora na podstawie losowej grafiki asteroidy
    asteroid.x = random.randint(20, WIDTH-20)
    asteroid.y = -10
    asteroid.vy = random.randint(2, 10)
    asteroids_list.append(asteroid)


def add_laser():
    laser = Actor("laser")
    laser.pos = ship.pos
    laser.vy = -8
    lasers_list.append(laser)


def on_mouse_down(pos):
    if ship.ammunition <= 0:
        return

    add_laser()
    sounds.laser.play()
    ship.ammunition -= 1
    clock.schedule(regenerate_ammo, 1)


def regenerate_ammo():
    ship.ammunition += 1


pygame.mouse.set_visible(False)  # Ukrywamy wskaźnik myszy

music.play("space")  # Odtwarzamy muzykę w grze
music.set_volume(0.3)  # Ustawiamy głośność muzyki

pgzrun.go()
```

## Pełna gra

Nasza gra jest już gotowa, a jej pełen kod pokazany jest poniżej.

### Pełny kod

```python
import pgzrun
import pygame
import random # Biblioteka do liczb losowych


WIDTH = 600  # Ustawiamy szerokość okna gry
HEIGHT = 900  # Ustawiamy wysokość okna gry

ship = Actor("ship")  # Tworzymy nowego aktora reprezentującego statek
ship.x = WIDTH / 2  # Ustawiamy pozycję poziomą statku na połowę szerokości ekranu
ship.y = HEIGHT - 60  # Ustawiamy statek na dole ekranu, z niewielkim marginesem
ship.vx = 5  # Zapamiętujemy prędkość poziomą statku
ship.points = 0  # Zapamiętujemy liczbę zdobytych punktów
ship.lifes = 3  # Zapamiętujemy liczbę dostępnych żyć
ship.ammunition = 5  # Liczba dostępnej amunicji

asteroids_list = []  # Lista, w której zapisujemy wszystkie asteroidy
lasers_list = []  # Lista, w której zapisujemy wszystkie lasery


def draw():  # Funkcja rysująca elementy gry
    screen.blit("bg", (0, 0))  # Rysujemy tło gry
    for asteroid in asteroids_list:  # Przechodzimy pętlą przez wszystkie asteroidy
        asteroid.draw()  # Rysujemy asteroidę na ekranie gry

    for laser in lasers_list:  # Przechodzimy przez wszystkie lasery na liście
        laser.draw()  # Rysujemy laser na ekranie gry

    ship.draw()  # Rysujemy statek na ekranie
    screen.draw.text(str(ship.points), center=(WIDTH / 2, 20), fontsize=50, color="yellow")  # Wyświetlamy liczbę zdoboytych punktów na ekranie gry
    draw_lifes()  # Rysujemy życia na ekranie
    if ship.lifes <= 0:  # Jeżeli skończyły nam się życia
        screen.draw.text("GAME OVER", center=(WIDTH / 2, HEIGHT / 2), fontsize=90, color="yellow")  # Wyświetlamy napis "GAME OVER" na środku ekranu gry
    

def draw_lifes():  # Pomocnicza funkcja rysująca życia
    for life_id in range(1, ship.lifes + 1):  # Przechodzimy pętlą od jeden do liczby dostępnych żyć włącznie
        life = Actor("life")  # Tworzymy aktora reprezentującego życie
        life.x = life_id * life.width  # Ustawiamy pozycję poziomą aktora
        life.y = life.height / 2  # Ustawiamy pozycję aktora w pionie
        life.draw()  # Rysujemy życie na ekranie


def update():  # Funkcja aktualizująca elementy gry
    if ship.lifes <= 0:  # Jeżeli skończyły nam się życia
        return  # Kończymy działanie funkcji

    mouse_x, mouse_y = pygame.mouse.get_pos()  # Odczytujemy obecną pozycję wskaźnika myszy
    if mouse_x < ship.x:  # Jeżeli wskaźnik myszy jest z lewej strony statku
        ship.x -= ship.vx  # Przemieszczamy statek w lewo zgodnie z jego prędkością

    if mouse_x > ship.x:  # Jeżeli wskaźnik myszy jest z prawej strony statku
        ship.x += ship.vx  # Przemieszczamy statek w prawo zgodnie z jego prędkością

    if random.random() < 0.02:  # Jeżeli wylosowaliśmy odpowiednio małą liczbę
        add_asteroid()  # Dodajemy nową asteroidę do gry

    update_asteroids()  # Aktualizujemy pozycje asteroid
    update_lasers()  # Aktualizujemy pozycje laserów
    update_lasers_hits()  # Aktualizujemy trafienia laserów w asteroidy
    

def update_asteroids():  # Pomocnicza funkcja aktualizująca pozycję asteroid
    for asteroid in asteroids_list[:]:  # Przechodzimy przez kopię listy asteroid
        asteroid.y += asteroid.vy  # Przemieszczamy asteroidę zgodnie z jej prędkością
        if asteroid.y > HEIGHT + 50:   # Jeżeli asteroida wyleciała poza ekran
            asteroids_list.remove(asteroid)  # Usuwamy ją z listy asteroid
        elif asteroid.colliderect(ship):  # Sprawdzamy, czy asteroida zderzyła się ze statkiem
            ship.lifes -= 1  # Zmniejszamy liczbę pozostałych żyć
            asteroids_list.remove(asteroid)  # Usuwamy asteroidę z gry
            if ship.lifes > 0:  # Jeżeli pozostały jeszcze jakieś życia
                sounds.shield.play()  # Odtwarzamy dźwięk tarczy
            else:  # W przeciwnym przypadku, gdy życia się już skończyły
                sounds.explosion.play()  # Odtwarzamy dźwięk wybuchu


def update_lasers():  # Pomocnicza funkcja aktualizująca pozycje laserów
    for laser in lasers_list[:]:  # Przechodzimy przez wszystkie lasery na liście
        laser.y += laser.vy  # Przemieszczamy laser zgodnie z jego prędkością
        if laser.y < -laser.height:  # Jeżeli laser wyleciał poza ekran
            lasers_list.remove(laser)  # Usuwamy laser z gry


def update_lasers_hits():  # Pomocnicza funkcja sprawdzająca uderzenia laserów w asteroidy
    for laser in lasers_list[:]:  # Przechodzimy przez wszystkie lasery na liście
        for asteroid in asteroids_list[:]:  # Przechodzimy przez wszystkie asteroidy na liście
            if laser.colliderect(asteroid):  # Sprawdzamy, czy laser trafił w asteroidę
                lasers_list.remove(laser)  # Usuwamy laser z gry
                asteroids_list.remove(asteroid)  # Usuwamy asteroidę z gry
                ship.points += 1  # Zwiększamy liczbę punktów po zestrzeleniu asteroidy
                break  # Kończymy pętlę przechodzącą po asteroidach i przechodzimy do kolejnego lasera


def add_asteroid():   # Pomocnicza funkcja dodająca nową asteroidę do gry
    image_id = random.randint(1, 4)  # Losujemy numer grafiki asteroidy
    asteroid = Actor("asteroid" + str(image_id))  # Tworzymy nowego aktora na podstawie losowej grafiki asteroidy
    asteroid.x = random.randint(20, WIDTH - 20)  # Ustawiamy losową pozycję poziomą asteroidy
    asteroid.y = -10  # Ustawiamy pionową pozycję asteroidy tak, by była poza ekranem gry
    asteroid.vy = random.randint(2, 10)  # Ustawiamy losową pozycję asteroidy
    asteroids_list.append(asteroid)  # Dodajemy nową asteroidę do listy asteroid


def add_laser():  # Pomocnicza funkcja dodająca nowy laser do gry
    laser = Actor("laser")  # Tworzymy nowego aktora reprezentującego laser
    laser.pos = ship.pos  # Ustawiamy pozycję lasera na pozycję statku
    laser.vy = -8  # Ustawiamy prędkość lasera
    lasers_list.append(laser)  # Dodajemy laser do listy laserów


def on_mouse_down(pos):  # Funkcja odczytująca kliknięcia myszy
    if ship.ammunition <= 0:  # Jeżeli nie mamy już amunicji
        return  # Kończymy działanie funkcji, w ten sposób nie oddając już strzału

    add_laser()  # Dodajemy nowy laser do gry
    sounds.laser.play()  # Odtwarzamy dźwięk oddania strzału
    ship.ammunition -= 1  # Zmniejszamy liczbę pozostałej amunicji o jeden
    clock.schedule(regenerate_ammo, 1)  # Ustawiamy wywołanie regeneracji amunicji po upłynięciu jednej sekundy


def regenerate_ammo():  # Pomocnicza funkcja regenerująca amunicję
    ship.ammunition += 1  # Regenerujemy amunicję dodając wartość 1 do zmiennej ammunition zapisanej w statku


pygame.mouse.set_visible(False)  # Ukrywamy wskaźnik myszy

music.play("space")  # Odtwarzamy muzykę w grze
music.set_volume(0.3)  # Ustawiamy głośność muzyki

pgzrun.go()  # Uruchamiamy grę
```

Pełna implementacja dostępna jest również poniżej.

{% embed url="https://github.com/blackbat13/AsteroidsPygameZero" %}
Asteroidy
{% endembed %}

## Zadanie dodatkowe

Spróbuj dodać do gry zwiększanie liczby żyć, gdy zdobędziemy odpowiednią liczbę punktów. Np. każde $$100$$ punktów daje nam kolejne życie. Podobnie możesz zrobić z amunicją.