# Głodna świnia

## Wstęp

Stworzymy prostą grę, w której naszym graczem będzie świnia. Świnie, jak wiadomo, lubią jeść. Naszym celem będzie więc nakarmienie świni, a dokładniej: doprowadzenie jej do jedzenia. Na ekranie będą się pojawiać w losowych miejscach warzywa, a my będziemy tak sterować świnią, żeby zjadła jak najwięcej. Po każdym posiłku świnia będzie przyspieszać, więc gra będzie stawała się coraz trudniejsza. Koniec gry nastąpi, gdy świnia ucieknie poza ekran.

### Czego się nauczysz

* Jak sterować postacią z klawiatury
* Jak wykrywać kolizję pomiędzy postaciami
* Jak obsłużyć koniec gry i jej restart

### Materiały do pobrania

#### Grafiki

Umieszczamy w katalogu **images**.

{% file src="../../.gitbook/assets/hungry_pig_images.zip" %}
Grafiki do gry Głodna Świnia
{% endfile %}

#### Dźwięki

Umieszczamy w katalogu **sounds**.

{% file src="../../.gitbook/assets/hungry_pig_sounds.zip" %}
Dźwięki do gry Głodna Świnia
{% endfile %}

<!-- #### Struktura projektu

Po dodaniu potrzebnych materiałów, struktura projektu powinna wyglądać mniej więcej tak jak na grafice poniżej.

![Struktura projektu](../../.gitbook/assets/hungry_pig_structure.png) -->

### Źródła

- [https://kenney.nl/](https://kenney.nl/)
- [https://comigo.itch.io/farm-puzzle-animals](https://comigo.itch.io/farm-puzzle-animals)
- [https://www.zapsplat.com/music/pig-squeal-close-up/](https://www.zapsplat.com/music/pig-squeal-close-up/)

## Nasz cel

{% embed url="https://blackbat13.github.io/HungryPigKaboomJS/" %}
Głodna świnia
{% endembed %}

## Tworzymy okno gry

Zaczynamy od utworzenia okna gry i podstawowej konfiguracji projektu. Wymiary okna ustawimy na $$800\times800$$, ponieważ tak mamy przygotowaną grafikę tła (__bg.png__). Wszystko umieszczamy w pliku __index.html__. 

```javascript
<script type="module">
    import kaboom from "https://unpkg.com/kaboom/dist/kaboom.mjs";

    kaboom({
        width: 800,
        height: 800,
    });
</script>
```

### Definiujemy scenę

Początkowo stworzymy jedną scenę o nazwie **game**, która będzie główną sceną naszej gry, tzn. sceną, w której będzie się toczyć zasadnicza rozgrywka. Scenę tworzymy za pomocą polecenia `scene`.

```javascript
scene("game", () => {

});
```

Aby nasza gra zaczynała się od sceny **game**, na końcu kodu dopisujemy instrukcję `go("game")`. Nasz kod powinien wyglądać teraz tak:

```javascript
import kaboom from "https://unpkg.com/kaboom/dist/kaboom.mjs";

kaboom({
    width: 800,
    height: 800,
});

scene("game", () => {

});

go("game");
```

### Wyświetlamy tło

Aby dodać tło do naszej gry, najpierw musimy je załadować z pliku __bg.png__ za pomocą polecenia `loadSprite`. Polecenie wywołujemy zaraz pod wywołaniem `kaboom`:

```javascript
import kaboom from "https://unpkg.com/kaboom/dist/kaboom.mjs";

kaboom({
    width: 800,
    height: 800,
});

loadSprite("bg", "images/bg.png");

...
```

Tło wyświetlimy na ekranie dodając nowy element do naszej głównej sceny za pomocą poleceń `add` oraz `sprite`.

```javascript
scene("game", () => {
    add([
        sprite("bg"),
    ]);
});
```

### Pełen kod

```javascript
import kaboom from "https://unpkg.com/kaboom/dist/kaboom.mjs";

kaboom({
    width: 800,
    height: 800,
});

loadSprite("bg", "images/bg.png");

scene("game", () => {
    add([
        sprite("bg"),
    ]);
});

go("game");
```

## Świnia

Zacznijmy od naszej głównej postaci: świni. 

### Ładujemy grafiki

Jak przyjrzymy się grafikom, to zobaczymy, że mamy kilka grafik reprezentujących świnię w zależności od kierunku, w którym jest obrócona. Wykorzystamy to przy poruszaniu się świni. Najpierw musimy załadować grafiki z plików. Nowe instrukcje dopiszemy zaraz pod instrukcją ładującą tło (`loadSprite("bg", "images/bg.png")`).
Warto także od razu załadować dźwięk świni z pliku __pig.wav__, za pomocą polecenia `loadSound`.

```javascript
loadSprite("pig_down", "images/pig_down.png");
loadSprite("pig_up", "images/pig_up.png");
loadSprite("pig_left", "images/pig_left.png");
loadSprite("pig_right", "images/pig_right.png");
loadSprite("pig_dead", "images/pig_dead.png");

loadSound("pig", "sounds/pig.wav");
```

### Dodajemy aktora

Na początku skorzystamy z grafiki __pig_down__. Na górze naszej głównej sceny, zaraz pod poleceniem dodającym tło, tworzymy naszego nowego aktora, którego zapiszemy w zmiennej  **pig**, za pomocą polecenia `add`. Naszą postać umieścimy na początku na środku ekranu, czyli pod współrzędnymi $$(400, 400)$$, które możemy pobrać za pomocą polecenia `center()`. Naszą świnię będziemy ustawiać względem jej środka, dlatego też skorzystamy z polecenia `origin`, jako parametr podając wartość **"center"**. Ponieważ będziemy chcieli wykrywać kolizję świni z innymi elementami gry, dopiszemy do niej także polecenie `area()`. Dobrą praktyką jest dodawanie pomocniczych nazw do naszych aktorów, tzw. tagów, tak więc do naszej świni dodamy tag **"pig"**.

```javascript
const pig = add([
    sprite("pig_down"),
    pos(center()),
    origin("center"),
    area(),
    "pig",
]);
```

### Sterowanie świnią

Naszą świnią będziemy sterować za pomocą klawiatury. Strzałkami będziemy wybierać kierunek, w którym świnia ma podążać. Nasza świnia będzie jednak poruszać się przez cały czas, podążając w ostatnio wybranym kierunku zgodnie ze swoją prędkością. Do tego będą nam potrzebne nowe zmienne, które dopiszemy do naszego aktora: 
- prędkość pozioma: **vx**,
- prędkość pionowa: **vy**,
- ogólna prędkość: **v**.

Ogólna prędkość posłuży nam do wyznaczania, jak szybko świnia ma się poruszać w wybranym kierunku. Tę wartość będziemy także zwiększać po każdym zjedzonym warzywie.

Dopisujemy więc nowe parametry do naszej świni. Aby na początku świnia stała w miejscu, prędkość poziomą i pionową ustawimy na $$0$$. Natomiast prędkość ogólną ustawimy na $$3$$, co wydaje się być dobrym poziomem startowym dla naszej gry. Oczywiście zachęcam do eksperymentowania!

Parametry dopiszemy zaraz pod poleceniem tworzącym naszą świnię.

```javascript
pig.vx = 0;
pig.vy = 0;
pig.v = 3;
```

Teraz czas zastosować prędkość do pozycji świni, tak aby mogła poruszać się po ekranie. W tym celu zdefiniujemy funkcję `onUpdate` w naszej głównej scenie **game**.
Wewnątrz zaktualizujemy pozycję świni na ekranie poprzez dodanie prędkości do współrzędnych położenia naszego aktora.

```javascript
onUpdate("pig", () => {
    pig.pos.x += pig.vx;
    pig.pos.y += pig.vy;
});
```

Oczywiście w tym momencie świnia nie będzie się jeszcze poruszać, ponieważ ustawiliśmy jej prędkości na $$0$$. Warto dla testów tymczasowo zmienić prędkości **vx** i **vy**, a następnie uruchomić grę by sprawdzić, czy wszystko działa poprawnie.

Teraz czas wreszcie dodać obsługę sterowania. W tym celu będziemy potrzebowali nowych funkcji, które pozwolą nam reagować na zdarzenia wciśnięcia klawisza na klawiaturze: `onKeyPress`. Dopiszemy je na dole naszej sceny, pod funkcją `onUpdate`. Wewnątrz funkcji będziemy reagować na kliknięcia przycisków na klawiaturze. W zależności od klikniętego przycisku, będziemy wykonywać inne operacje. Jeżeli kliknięta zostanie np. strzałka w lewo, to ustawimy prędkość poziomą **vx** świni na **-v**, wyzerujemy prędkość pionową i zmienimy grafikę na __pig_left__.

```javascript
onKeyPress("left", () => {
    pig.vx = -pig.v;
    pig.vy = 0;
    pig.use(sprite("pig_left"));
});
```

Podobnie postępujemy z pozostałymi kierunkami, odpowiednio zmieniając prędkości świni i jej grafikę.

```javascript
onKeyPress("right", () => {
    pig.vx = pig.v;
    pig.vy = 0;
    pig.use(sprite("pig_right"));
});

onKeyPress("up", () => {
    pig.vx = 0;
    pig.vy = -pig.v;
    pig.use(sprite("pig_up"));
});

onKeyPress("down", () => {
    pig.vx = 0;
    pig.vy = pig.v;
    pig.use(sprite("pig_down"));
});
```

### Pełny kod

```javascript
import kaboom from "https://unpkg.com/kaboom/dist/kaboom.mjs";

kaboom({
    width: 800,
    height: 800,
});

loadSprite("bg", "images/bg.png");
loadSprite("pig_down", "images/pig_down.png");
loadSprite("pig_up", "images/pig_up.png");
loadSprite("pig_left", "images/pig_left.png");
loadSprite("pig_right", "images/pig_right.png");
loadSprite("pig_dead", "images/pig_dead.png");

loadSound("pig", "sounds/pig.wav");

scene("game", () => {
    add([
        sprite("bg"),
    ]);

    const pig = add([
        sprite("pig_down"),
        pos(center()),
        origin("center"),
        area(),
        "pig",
    ]);

    pig.vx = 0;
    pig.vy = 0;
    pig.v = 3;

    onUpdate("pig", () => {
        pig.pos.x += pig.vx;
        pig.pos.y += pig.vy;

        if (pig.pos.x < 0 || pig.pos.x > width() || pig.pos.y < 0 || pig.pos.y > height()) {
            go("game_over", points);
        }
    });

    onKeyPress("left", () => {
        pig.vx = -pig.v;
        pig.vy = 0;
        pig.use(sprite("pig_left"));
    });

    onKeyPress("right", () => {
        pig.vx = pig.v;
        pig.vy = 0;
        pig.use(sprite("pig_right"));
    });

    onKeyPress("up", () => {
        pig.vx = 0;
        pig.vy = -pig.v;
        pig.use(sprite("pig_up"));
    });

    onKeyPress("down", () => {
        pig.vx = 0;
        pig.vy = pig.v;
        pig.use(sprite("pig_down"));
    });
});

go("game");
```

## Buraki

Nasza świnia będzie żywić się burakami. Na ekranie zawsze będzie dokładnie jeden burak. Gdy świnia zje buraka, ten pojawi się ponownie w nowym, losowym miejscu na ekranie.

### Ładujemy grafikę

Nasz burak będzie reprezentowany przez grafikę __beetroot.png__. Na początku musimy załadować grafikę korzystając z polecenia `loadSprite`. Dopisujemy nowe polecenie na górze naszego programu, zaraz pod poleceniami ładującymi grafiki świni.

```javascript
...
loadSprite("bg", "images/bg.png");
loadSprite("pig_down", "images/pig_down.png");
loadSprite("pig_up", "images/pig_up.png");
loadSprite("pig_left", "images/pig_left.png");
loadSprite("pig_right", "images/pig_right.png");
loadSprite("pig_dead", "images/pig_dead.png");
loadSprite("beet", "images/beetroot.png");
...
```

### Dodajemy aktora

Naszego aktora zapiszemy w zmiennej `beet`. Utworzymy go w scenie **game** i początkowo umieścimy w dowolnym miejscu na ekranie, np. pod współrzędnymi $$(200, 200)$$. Podobnie jak przy świni, do buraka dopiszemy także polecenia `origin` oraz `area`, a także tag **"beet"**.

```javascript
const beet = add([
    sprite("beet"),
    pos(200, 200),
    origin("center"),
    area(),
    "beet",
]);
```

### Zjadanie buraków

Podczas poruszania się po ekranie, gdy świnia wejdzie w kolizję z burakiem, to go zje. Po zjedzeniu buraka świnia powinna przyspieszyć, wydać odpowiedni odgłos, a sam burak powinien przemieścić się w losowe miejsce na ekranie.

W celu stwierdzenia, że świnia jest w kolizji z burakiem, skorzystamy z instrukcji **onCollide**:

```javascript
pig.onCollide("beet", () => {
});
```

Wszystko będziemy zapisywać w naszej głównej scenie **game**, zaraz pod poleceniem dodającym buraka.

Po wykryciu kolizji zacznijmy od przemieszczenia buraka w losowe miejsce. Osobno wylosujemy nowe wartości dla współrzędnych $$x$$ oraz $$y$$. Aby jednak burak nie pojawił się na brzegu ekranu, warto zadbać o odpowiedni margines, np $$50$$ pikseli. W celu wylosowania wartości skorzystamy z funkcji **rand**, do której, jako argumenty, przekazujemy przedział, z jakiego chcemy wylosować wartość.

```javascript
beet.pos.x = rand(50, width() - 50);
beet.pos.y = rand(50, height() - 50);
```

Następnie zwiększamy prędkość świni. W tym celu modyfikujemy parametr **v**, dodając do niego jakąś niewielką liczbę, np. $$0.8$$. Warto poeksperymentować z różnymi wartościami by dobrać odpowiedni dla siebie poziom trudności.

```javascript
pig.v += 0.8;
```

Na koniec warto jeszcze dodać efekty dźwiękowe.

```javascript
play("pig");
```

Cały kod obsługujący kolizję z burakiem prezentuje się następująco:

```javascript
pig.onCollide("beet", () => {
    beet.pos.x = rand(50, width() - 50);
    beet.pos.y = rand(50, height() - 50);
    points += 1;
    pointsLabel.text = points;
    pig.v += 0.8;
    play("pig");
});
```

Umieszczamy naszą instrukcję w scenie **game**.

```javascript
scene("game", () => {
    add([
        sprite("bg"),
    ]);

    const pig = add([
        sprite("pig_down"),
        pos(center()),
        origin("center"),
        area(),
        "pig",
    ]);

    pig.vx = 0;
    pig.vy = 0;
    pig.v = 3;

    onUpdate("pig", () => {
        pig.pos.x += pig.vx;
        pig.pos.y += pig.vy;

        if (pig.pos.x < 0 || pig.pos.x > width() || pig.pos.y < 0 || pig.pos.y > height()) {
            go("game_over", points);
        }
    });

    onKeyPress("left", () => {
        pig.vx = -pig.v;
        pig.vy = 0;
        pig.use(sprite("pig_left"));
    });

    onKeyPress("right", () => {
        pig.vx = pig.v;
        pig.vy = 0;
        pig.use(sprite("pig_right"));
    });

    onKeyPress("up", () => {
        pig.vx = 0;
        pig.vy = -pig.v;
        pig.use(sprite("pig_up"));
    });

    onKeyPress("down", () => {
        pig.vx = 0;
        pig.vy = pig.v;
        pig.use(sprite("pig_down"));
    });

    const beet = add([
        sprite("beet"),
        pos(200, 200),
        origin("center"),
        area(),
        "beet",
    ]);

    pig.onCollide("beet", () => {
        beet.pos.x = rand(50, width() - 50);
        beet.pos.y = rand(50, height() - 50);
        pig.v += 0.8;
        play("pig");
    });
});
```

### Pełny kod

```javascript
import kaboom from "https://unpkg.com/kaboom/dist/kaboom.mjs";

kaboom({
    width: 800,
    height: 800,
});

loadSprite("bg", "images/bg.png");
loadSprite("pig_down", "images/pig_down.png");
loadSprite("pig_up", "images/pig_up.png");
loadSprite("pig_left", "images/pig_left.png");
loadSprite("pig_right", "images/pig_right.png");
loadSprite("pig_dead", "images/pig_dead.png");
loadSprite("beet", "images/beetroot.png");

loadSound("pig", "sounds/pig.wav");

scene("game", () => {
    add([
        sprite("bg"),
    ]);

    const pig = add([
        sprite("pig_down"),
        pos(center()),
        origin("center"),
        area(),
        "pig",
    ]);

    pig.vx = 0;
    pig.vy = 0;
    pig.v = 3;

    onUpdate("pig", () => {
        pig.pos.x += pig.vx;
        pig.pos.y += pig.vy;

        if (pig.pos.x < 0 || pig.pos.x > width() || pig.pos.y < 0 || pig.pos.y > height()) {
            go("game_over", points);
        }
    });

    onKeyPress("left", () => {
        pig.vx = -pig.v;
        pig.vy = 0;
        pig.use(sprite("pig_left"));
    });

    onKeyPress("right", () => {
        pig.vx = pig.v;
        pig.vy = 0;
        pig.use(sprite("pig_right"));
    });

    onKeyPress("up", () => {
        pig.vx = 0;
        pig.vy = -pig.v;
        pig.use(sprite("pig_up"));
    });

    onKeyPress("down", () => {
        pig.vx = 0;
        pig.vy = pig.v;
        pig.use(sprite("pig_down"));
    });

    const beet = add([
        sprite("beet"),
        pos(200, 200),
        origin("center"),
        area(),
        "beet",
    ]);

    pig.onCollide("beet", () => {
        beet.pos.x = rand(50, width() - 50);
        beet.pos.y = rand(50, height() - 50);
        pig.v += 0.8;
        play("pig");
    });
});

go("game");
```

## Punkty

Cóż to za gra bez punktów! Dodanie jednak punktów do naszej gry to żaden problem. Punkty będziemy dostawać za każdego zjedzonego buraka. Na początku dopisujemy punkty w postaci nowej zmiennej **points**. Początkowo punkty ustawiamy na $$0$$. Nową zmienną utworzymy w scenie **game**, zaraz nad funkcją wykrywającą kolizję świni i buraka.

```javascript
let points = 0;
```

### Wyświetlamy punkty

Zanim przejdziemy do zliczania punktów, wyświetlmy je na ekranie gry. W tym celu dodamy nowy element do naszej sceny za pomocą polecenia `add`. Nowe instrukcje dopisujemy zaraz pod zmienną `points`.

```javascript
const pointsLabel = add([
    text(points),
    pos(width() / 2, 50),
    origin("center"),
]);
```

### Zliczamy punkty

Jak już ustaliliśmy, punkty będziemy dostawać za każdego zjedzonego buraka. W takim razie, do części, w której wykrywamy kolizję z burakiem, dopisujemy zwiększanie punktów: `points += 1`. Po zwiększeniu liczby punktów należy także zaktualizować tekst etykiety `pointsLabel` wyświetlającej punkty: `pointsLabel.text = points`.

```javascript
pig.onCollide("beet", () => {
    beet.pos.x = rand(50, width() - 50);
    beet.pos.y = rand(50, height() - 50);
    pig.v += 0.8;
    play("pig");
    points += 1;
    pointsLabel.text = points;
});
```

### Pełny kod

```javascript
import kaboom from "https://unpkg.com/kaboom/dist/kaboom.mjs";

kaboom({
    width: 800,
    height: 800,
});

loadSprite("bg", "images/bg.png");
loadSprite("pig_down", "images/pig_down.png");
loadSprite("pig_up", "images/pig_up.png");
loadSprite("pig_left", "images/pig_left.png");
loadSprite("pig_right", "images/pig_right.png");
loadSprite("pig_dead", "images/pig_dead.png");
loadSprite("beet", "images/beetroot.png");

loadSound("pig", "sounds/pig.wav");

scene("game", () => {
    add([
        sprite("bg"),
    ]);

    const pig = add([
        sprite("pig_down"),
        pos(center()),
        origin("center"),
        area(),
        "pig",
    ]);

    pig.vx = 0;
    pig.vy = 0;
    pig.v = 3;

    onUpdate("pig", () => {
        pig.pos.x += pig.vx;
        pig.pos.y += pig.vy;

        if (pig.pos.x < 0 || pig.pos.x > width() || pig.pos.y < 0 || pig.pos.y > height()) {
            go("game_over", points);
        }
    });

    onKeyPress("left", () => {
        pig.vx = -pig.v;
        pig.vy = 0;
        pig.use(sprite("pig_left"));
    });

    onKeyPress("right", () => {
        pig.vx = pig.v;
        pig.vy = 0;
        pig.use(sprite("pig_right"));
    });

    onKeyPress("up", () => {
        pig.vx = 0;
        pig.vy = -pig.v;
        pig.use(sprite("pig_up"));
    });

    onKeyPress("down", () => {
        pig.vx = 0;
        pig.vy = pig.v;
        pig.use(sprite("pig_down"));
    });

    const beet = add([
        sprite("beet"),
        pos(200, 200),
        origin("center"),
        area(),
        "beet",
    ]);

    let points = 0;

    const pointsLabel = add([
        text(points),
        pos(width() / 2, 50),
        origin("center"),
    ]);

    pig.onCollide("beet", () => {
        beet.pos.x = rand(50, width() - 50);
        beet.pos.y = rand(50, height() - 50);
        pig.v += 0.8;
        play("pig");
        points += 1;
        pointsLabel.text = points;
    });
});

go("game");
```

<!-- ## Koniec gry

Cóż to za gra, która się nie kończy? Nasza gra będzie kończyć się, gdy świnia wyjdzie poza ekran. W celu zapamiętania, że gra się już zakończyła, dopiszemy do świni nową zmienną **dead**, którą na początku ustawimy na wartość **False**.

```python
pig = Actor("pig_down")
pig.x = 400
pig.y = 400
pig.vx = 0
pig.vy = 0
pig.v = 3
pig.points = 0
pig.dead = False
```

### Wyświetlamy komunikat

Zacznijmy od wyświetlenia na ekranie komunikatu o zakończeniu gry. W części rysującej, gdy gra jest zakończona, tzn. gdy zmienna `pig.dead` ma wartość **True**, wyświetlimy na ekranie komunikat **GAME OVER**.

```python
if pig.dead:
    screen.draw.text(f"GAME OVER", center=(WIDTH / 2, HEIGHT / 2), fontsize=70, color="#e30022", fontname="kenney_bold")
```

Całość dopisujemy na koniec części rysującej.

```python
def draw():
    screen.blit("bg", (0, 0))
    pig.draw()
    beet.draw()
    screen.draw.text(f"{pig.points}", center=(WIDTH / 2, 50), fontsize=60, color="#fdee00", fontname="kenney_bold")
    if pig.dead:
        screen.draw.text(f"GAME OVER", center=(WIDTH / 2, HEIGHT / 2), fontsize=70, color="#e30022", fontname="kenney_bold")
```

Warto przetestować, czy komunikat wyświetla się poprawnie, tymczasowo zmieniając wartość zmiennej `pig.dead` na **True**.

### Sprawdzamy wyjście poza ekran

Nasza gra się kończy, gdy świnia wyjdzie poza ekran gry. Aby sprawdzić, czy tak się stało, wystarczy sprawdzić wartości współrzędnych naszej świni. Jeżeli są mniejsze od zera, albo większe od odpowiednio szerokości i wysokości, to znaczy, że świnia wyszła poza ekran. Dopisujemy więc odpowiedni warunek na koniec części aktualizującej.

```python
if pig.x < 0 or pig.x > WIDTH or pig.y < 0 or pig.y > HEIGHT:
```

Gdy świnia wyjdzie poza ekran to gra się kończy, ustawiamy więc zmienną `pig.dead` na wartość **True**.

```python
if pig.x < 0 or pig.x > WIDTH or pig.y < 0 or pig.y > HEIGHT:
    pig.dead = True
```

Dla lepszego efektu możemy także przemieścić świnię zaraz nad napis **GAME OVER** i zmienić jej grafikę na __pig_dead.png__.

```python
if pig.x < 0 or pig.x > WIDTH or pig.y < 0 or pig.y > HEIGHT:
    pig.dead = True
    pig.x = WIDTH / 2
    pig.y = HEIGHT / 3
    pig.image = "pig_dead"
```

Tak teraz powinna wyglądać nasza część aktualizująca:

```python
def update():
    pig.x += pig.vx
    pig.y += pig.vy

    if pig.colliderect(beet):
        beet.x = random.randint(50, WIDTH - 50)
        beet.y = random.randint(50, HEIGHT - 50)
        pig.v += 0.8
        pig.points += 1
        sounds.pig.play()

    if pig.x < 0 or pig.x > WIDTH or pig.y < 0 or pig.y > HEIGHT:
        pig.dead = True
        pig.x = WIDTH / 2
        pig.y = HEIGHT / 3
        pig.image = "pig_dead"
```

### Zamrożenie rozgrywki

Gdy teraz przetestujemy naszą grę, to zauważymy, że rozgrywka dalej się toczy po zakończeniu gry, tzn. dalej można poruszać świnią i zjadać buraki. Oczywiście nie chcemy, by tak się działo. W tym celu należy dopisać prostą instrukcję warunkową na początek części aktualizującej, a także na początek części odpowiedzialnej za odczytywanie klikniętych przycisków z klawiatury.

```python
if pig.dead:
    return
```

Dzięki temu, jeżeli gra jest już zakończona, to żadne dalsze instrukcje w danej części nie będą już wykonywane.

### Pełny kod

```python
import pgzrun
import random

TITLE = "Hungry Pig"
WIDTH = 800
HEIGHT = 800

pig = Actor("pig_down")
pig.x = 400
pig.y = 400
pig.vx = 0
pig.vy = 0
pig.v = 3
pig.points = 0
pig.dead = False

beet = Actor("beetroot")
beet.x = 200
beet.y = 200


def draw():
    screen.blit("bg", (0, 0))
    pig.draw()
    beet.draw()
    screen.draw.text(f"{pig.points}", center=(WIDTH / 2, 50), fontsize=60, color="#fdee00", fontname="kenney_bold")
    if pig.dead:
        screen.draw.text(f"GAME OVER", center=(WIDTH / 2, HEIGHT / 2), fontsize=70, color="#e30022", fontname="kenney_bold")


def update():
    if pig.dead:
        return

    pig.x += pig.vx
    pig.y += pig.vy

    if pig.colliderect(beet):
        beet.x = random.randint(50, WIDTH - 50)
        beet.y = random.randint(50, HEIGHT - 50)
        pig.v += 0.8
        pig.points += 1
        sounds.pig.play()

    if pig.x < 0 or pig.x > WIDTH or pig.y < 0 or pig.y > HEIGHT:
        pig.dead = True
        pig.x = WIDTH / 2
        pig.y = HEIGHT / 3
        pig.image = "pig_dead"


def on_key_down(key):
    if pig.dead:
        return

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

## Restart gry

Warto dodać do naszej gry możliwość rozpoczęcia ponownej rozgrywki, gdy gra już się zakończy. W ten sposób nie będziemy musieli wyłączać i ponownie włączać okna gry. Zacznijmy od dodania pomocniczej funkcji **restart**, za pomocą której przywrócimy początkowe ustawienia, takie jak: grafikę świni, pozycję świni, prędkość świni, punkty oraz stan gry. Funkcję dopisujemy na samym dole, zaraz przed instrukcją `pgzrun.go()`.

```python
def restart():
    pig.image = "pig_down"
    pig.x = 400
    pig.y = 400
    pig.vx = 0
    pig.vy = 0
    pig.v = 3
    pig.points = 0
    pig.dead = False
```

Teraz pozostaje pytanie: kiedy i w jaki sposób restartować grę? Chcemy, aby gracz mógł zrestartować rozgrywkę zaraz po jej zakończeniu. Powiedzmy, że jak gra się już zakończyła i gracz naciśnie **spację**, to rozpocznie się kolejna rozgrywka. Dopiszmy więc stosowną instrukcję do funkcji `on_key_down`.

```python
def on_key_down(key):
    if pig.dead:
        if key == keys.SPACE:
            restart()

        return
```

Teraz możemy już restartować naszą rozgrywkę. Warto jeszcze wyświetlić dodatkowy komunikat po zakończeniu gry. W części rysującej, zaraz pod komunikatem "GAME OVER", dopisujemy:

```python
screen.draw.text(f"Press SPACE to try again", center=(WIDTH / 2, 2 * HEIGHT / 3), fontsize=30, color="#e30022", fontname="kenney_bold")
```

### Pełny kod

```python
import pgzrun
import random

TITLE = "Hungry Pig"
WIDTH = 800
HEIGHT = 800

pig = Actor("pig_down")
pig.x = 400
pig.y = 400
pig.vx = 0
pig.vy = 0
pig.v = 3
pig.points = 0
pig.dead = False

beet = Actor("beetroot")
beet.x = 200
beet.y = 200


def draw():
    screen.blit("bg", (0, 0))
    pig.draw()
    beet.draw()
    screen.draw.text(f"{pig.points}", center=(WIDTH / 2, 50), fontsize=60, color="#fdee00", fontname="kenney_bold")
    if pig.dead:
        screen.draw.text(f"GAME OVER", center=(WIDTH / 2, HEIGHT / 2), fontsize=70, color="#e30022", fontname="kenney_bold")
        screen.draw.text(f"Press SPACE to try again", center=(WIDTH / 2, 2 * HEIGHT / 3), fontsize=30, color="#e30022", fontname="kenney_bold")


def update():
    if pig.dead:
        return

    pig.x += pig.vx
    pig.y += pig.vy

    if pig.colliderect(beet):
        beet.x = random.randint(50, WIDTH - 50)
        beet.y = random.randint(50, HEIGHT - 50)
        pig.v += 0.8
        pig.points += 1
        sounds.pig.play()

    if pig.x < 0 or pig.x > WIDTH or pig.y < 0 or pig.y > HEIGHT:
        pig.dead = True
        pig.x = WIDTH / 2
        pig.y = HEIGHT / 3
        pig.image = "pig_dead"


def on_key_down(key):
    if pig.dead:
        if key == keys.SPACE:
            restart()
			
        return

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
		

def restart():
    pig.image = "pig_down"
    pig.x = 400
    pig.y = 400
    pig.vx = 0
    pig.vy = 0
    pig.v = 3
    pig.points = 0
    pig.dead = False


pgzrun.go()
``` -->

## Pełna gra

Pełna implementacja dostępna jest poniżej.

{% embed url="https://github.com/blackbat13/hungrypigkaboomjs" %}
Głodna świnia
{% endembed %}
