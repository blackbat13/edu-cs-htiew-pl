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

#### Czcionki

Umieszczamy w katalogu **fonts**.

{% file src="../../.gitbook/assets/hungry_pig_fonts.zip" %}
Czcionki do gry Głodna Świnia
{% endfile %}

#### Struktura projektu

Po dodaniu potrzebnych materiałów, struktura projektu powinna wyglądać mniej więcej tak jak na grafice poniżej.

![Struktura projektu](../../.gitbook/assets/hungry_pig_structure.png)

### Źródła

- [https://kenney.nl/](https://kenney.nl/)
- [https://comigo.itch.io/farm-puzzle-animals](https://comigo.itch.io/farm-puzzle-animals)
- [https://www.zapsplat.com/music/pig-squeal-close-up/](https://www.zapsplat.com/music/pig-squeal-close-up/)

## Nasz cel

![Głodna świnia - animacja](../../.gitbook/assets/hungry_pig.gif)

## Tworzymy okno gry

Zaczynamy od utworzenia okna gry i podstawowej konfiguracji projektu. Wymiary okna ustawimy na $$800\times800$$, ponieważ tak mamy przygotowaną grafikę tła (__bg.png__). Grafikę tła najpierw musimy załadować z pliku za pomocą funkcji `love.graphics.newImage`. Tło wyświetlimy na ekranie w części rysującej za pomocą polecenia `love.graphics.draw`. Przed wyświetleniem tła resetujemy ustawienia kolorów wyświetlania za pomocą polecenia `love.graphics.setColor(1,1,1,1)`.

```lua
function love.load()
    math.randomseed(os.time())

    Const = {width = 800, height = 800, margin = 50, framerate = 60}

    Background = love.graphics.newImage("images/bg.png")
end

function love.draw()
    love.graphics.setColor(1,1,1,1)
    love.graphics.draw(Background)
end

function love.update(dt)
end
```

## Świnia

Zacznijmy od naszej głównej postaci: świni. 

### Dodajemy aktora

Jak przyjrzymy się grafikom, to zobaczymy, że mamy kilka grafik reprezentujących świnię w zależności od kierunku, w którym jest obrócona. Wykorzystamy to przy poruszaniu się świni. Na początku jednak skorzystamy z grafiki __pig_down.png__. Na górze naszego programu, w części inicjalizującej (`love.load`), zaraz pod załadowaniem grafiki tła, tworzymy naszego nowego aktora, którego nazwiemy **Pig**. Naszą postać umieścimy na początku na środku ekranu, czyli pod współrzędnymi $$(400, 400)$$.

```lua
Pig = {
    x = Const.width / 2,
    y = Const.height / 2,
    images = {
        left = love.graphics.newImage("images/pig_left.png"),
        right = love.graphics.newImage("images/pig_right.png"),
        up = love.graphics.newImage("images/pig_up.png"),
        down = love.graphics.newImage("images/pig_down.png")
    }
}

Pig.drawable = Pig.images.down
```

### Rysujemy świnię na ekranie

W części rysującej dopisujemy instrukcję, która wyświetli naszego nowego aktora na ekranie:

```lua
function love.draw()
    love.graphics.setColor(1,1,1,1)
    love.graphics.draw(Background)
    love.graphics.draw(Pig.drawable, Pig.x, Pig.y, 0, 1, 1, Pig.drawable.getWidth(Pig.drawable) / 2, Pig.drawable.getHeight(Pig.drawable) / 2)
end
```

### Sterowanie świnią

Naszą świnią będziemy sterować za pomocą klawiatury. Strzałkami będziemy wybierać kierunek, w którym świnia ma podążać. Nasza świnia będzie jednak poruszać się przez cały czas, podążając w ostatnio wybranym kierunku zgodnie ze swoją prędkością. Do tego będą nam potrzebne nowe zmienne, które dopiszemy do naszego aktora: 
- prędkość pozioma: **vx**,
- prędkość pionowa: **vy**,
- ogólna prędkość: **v**.

Ogólna prędkość posłuży nam do wyznaczania, jak szybko świnia ma się poruszać w wybranym kierunku. Tę wartość będziemy także zwiększać po każdym zjedzonym warzywie.

Dopisujemy więc nowe parametry do naszej świni. Aby na początku świnia stała w miejscu, prędkość poziomą i pionową ustawimy na $$0$$. Natomiast prędkość ogólną ustawimy na $$3$$, co wydaje się być dobrym poziomem startowym dla naszej gry. Oczywiście zachęcam do eksperymentowania!

```lua
Pig = {
    x = Const.width / 2,
    y = Const.height / 2,
    vx = 0,
    vy = 0,
    v = 3,
    images = {
        left = love.graphics.newImage("images/pig_left.png"),
        right = love.graphics.newImage("images/pig_right.png"),
        up = love.graphics.newImage("images/pig_up.png"),
        down = love.graphics.newImage("images/pig_down.png")
    }
}
```

Teraz czas zastosować prędkość do pozycji świni, tak aby mogła poruszać się po ekranie. W części aktualizującej dopisujemy dwie linijki aktualizujące pozycję świni na ekranie, poprzez dodanie prędkości do współrzędnych położenia naszego aktora. W celu zapewnienia płynności ruchu i stałej liczby klatek, dodawane wartości przemnożymy przez `dt` oraz `Const.framerate`.

```lua
function love.update(dt)
    Pig.x = Pig.x + Pig.vx * dt * Const.framerate
    Pig.y = Pig.y + Pig.vy * dt * Const.framerate
end
```

Oczywiście w tym momencie świnia nie będzie się jeszcze poruszać, ponieważ ustawiliśmy jej prędkości na $$0$$. Warto dla testów tymczasowo zmienić prędkości **vx** i **vy**, a następnie uruchomić grę by sprawdzić, czy wszystko działa poprawnie.

Teraz czas wreszcie dodać obsługę sterowania. W tym celu będziemy potrzebowali nowej funkcji, która pozwoli nam reagować na zdarzenia wciśnięcia klawisza na klawiaturze: `love.keypressed(key, scancode, isrepeat)`. Dopiszemy ją na dole naszego programu, pod funkcją `love.update`. Wewnątrz funkcji będziemy reagować na kliknięcia przycisków na klawiaturze. W zależności od klikniętego przycisku, będziemy wykonywać inne operacje. Jeżeli kliknięta zostanie np. strzałka w lewo, to ustawimy prędkość poziomą **vx** świni na **-v**, wyzerujemy prędkość pionową i zmienimy grafikę na `Pig.images.left`.

```lua
function love.keypressed(key, scancode, isrepeat)
    if key == "left" then
        Pig.vx = -Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.left
    end
end
```

Podobnie postępujemy z pozostałymi kierunkami, odpowiednio zmieniając prędkości świni i jej grafikę.

```lua
function love.keypressed(key, scancode, isrepeat)
    if key == "left" then
        Pig.vx = -Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.left
    end

    if key == "right" then
        Pig.vx = Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.right
    end

    if key == "up" then
        Pig.vx = 0
        Pig.vy = -Pig.v
        Pig.drawable = Pig.images.up
    end

    if key == "down" then
        Pig.vx = 0
        Pig.vy = Pig.v
        Pig.drawable = Pig.images.down
    end
end
```

### Pełny kod

```lua
function love.load()
    math.randomseed(os.time())

    Const = {width = 800, height = 800, margin = 50, framerate = 60}

    Background = love.graphics.newImage("images/bg.png")

    Pig = {
        x = Const.width / 2,
        y = Const.height / 2,
        vx = 0,
        vy = 0,
        v = 3,
        images = {
            left = love.graphics.newImage("images/pig_left.png"),
            right = love.graphics.newImage("images/pig_right.png"),
            up = love.graphics.newImage("images/pig_up.png"),
            down = love.graphics.newImage("images/pig_down.png")
        }
    }

    Pig.drawable = Pig.images.down
end

function love.draw()
    love.graphics.setColor(1,1,1,1)
    love.graphics.draw(Background)
    love.graphics.draw(Pig.drawable, Pig.x, Pig.y, 0, 1, 1, Pig.drawable.getWidth(Pig.drawable) / 2, Pig.drawable.getHeight(Pig.drawable) / 2)
end

function love.update(dt)
    Pig.x = Pig.x + Pig.vx * dt * Const.framerate
    Pig.y = Pig.y + Pig.vy * dt * Const.framerate
end

function love.keypressed(key, scancode, isrepeat)
    if key == "left" then
        Pig.vx = -Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.left
    end

    if key == "right" then
        Pig.vx = Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.right
    end

    if key == "up" then
        Pig.vx = 0
        Pig.vy = -Pig.v
        Pig.drawable = Pig.images.up
    end

    if key == "down" then
        Pig.vx = 0
        Pig.vy = Pig.v
        Pig.drawable = Pig.images.down
    end
end
```

## Buraki

Nasza świnia będzie żywić się burakami. Na ekranie zawsze będzie dokładnie jeden burak. Gdy świnia zje buraka, ten pojawi się ponownie w nowym, losowym miejscu na ekranie.

### Dodajemy aktora

Naszego aktora zapiszemy w zmiennej `Beet`. Utworzymy go na podstawie grafiki __beetroot.png__ i początkowo umieścimy w dowolnym miejscu na ekranie, np. pod współrzędnymi $$(200, 200)$$. Nowego aktora definiujemy w części inicjalizującej (`love.load`).

```lua
Beet = {
    x = 200,
    y = 200,
    drawable = love.graphics.newImage("images/beetroot.png")
}
```

### Rysujemy buraka na ekranie

W części rysującej dopisujemy instrukcję, która wyświetli naszego nowego aktora na ekranie. Aby nasz burak wyświetlał się pod świnią, a nie nad nią, nową instrukcję dodamy zaraz przed instrukcją rysującą świnię.

```lua
function love.draw()
    love.graphics.setColor(1,1,1,1)
    love.graphics.draw(Background)
    love.graphics.draw(Beet.drawable, Beet.x, Beet.y, 0, 1, 1, Beet.drawable.getWidth(Beet.drawable) / 2, Beet.drawable.getHeight(Beet.drawable) / 2)
    love.graphics.draw(Pig.drawable, Pig.x, Pig.y, 0, 1, 1, Pig.drawable.getWidth(Pig.drawable) / 2, Pig.drawable.getHeight(Pig.drawable) / 2)
end
```

### Zjadanie buraków

Podczas poruszania się po ekranie, gdy świnia wejdzie w kolizję z burakiem, to go zje. Po zjedzeniu buraka świnia powinna przyspieszyć, wydać odpowiedni odgłos, a sam burak powinien przemieścić się w losowe miejsce na ekranie.

W celu stwierdzenia, że świnia jest w kolizji z burakiem, stworzymy pomocniczą funkcję `Collides(actor1, actor1)`. Nasza funkcja przyjmie dwa parametry: aktorów, dla których sprawdzamy kolizję. Funkcję dopiszemy na samym dole naszego kodu. W celu sprawdzenia, czy dwie postacie są w kolizji, sprawdzimy kolizję prostokątów zdefiniowanych przez ich grafiki.

```lua
function Collides(actor1, actor2)
    return actor1.x + actor1.drawable.getWidth(actor1.drawable) >= actor2.x and
            actor1.x <= actor2.x + actor2.drawable.getWidth(actor2.drawable) and
            actor1.y + actor1.drawable.getHeight(actor1.drawable) >= actor2.y and
            actor1.y <= actor2.y + actor2.drawable.getHeight(actor2.drawable)
end
```

Z naszej pomocniczej funkcji skorzystamy w następujący sposób:

```lua
if Collides(Pig, Beet) then
end
```

Wszystko będziemy teraz zapisywać w części aktualizującej **love.update**, zaraz pod zmianą pozycji świni.

Po wykryciu kolizji zacznijmy od przemieszczenia buraka w losowe miejsce. Osobno wylosujemy nowe wartości dla współrzędnych $$x$$ oraz $$y$$. Aby jednak burak nie pojawił się na brzegu ekranu, warto zadbać o odpowiedni margines, np $$50$$ pikseli. W celu wylosowania wartości skorzystamy z biblioteki **math** oraz funkcji **random**, do której, jako argumenty, przekazujemy przedział, z jakiego chcemy wylosować wartość.

```lua
Beet.x = math.random(Const.margin, Const.width - Const.margin)
Beet.y = math.random(Const.margin, Const.height - Const.margin)
```

Następnie zwiększamy prędkość świni. W tym celu modyfikujemy parametr **v**, dodając do niego jakąś niewielką liczbę, np. $$0.8$$. Warto poeksperymentować z różnymi wartościami by dobrać odpowiedni dla siebie poziom trudności.

```lua
Pig.v = Pig.v + 0.8
```

<!-- Na koniec warto jeszcze dodać efekty dźwiękowe.

```python
sounds.pig.play()
``` -->

Cały kod stwierdzający kolizję z burakiem prezentuje się następująco:

```lua
if Collides(Pig, Beet) then
    Beet.x = math.random(Const.margin, Const.width - Const.margin)
    Beet.y = math.random(Const.margin, Const.height - Const.margin)
    Pig.v = Pig.v + 0.8
end
```

Umieszczamy naszą instrukcję w części aktualizującej.

```lua
function love.update(dt)
    Pig.x = Pig.x + Pig.vx * dt * Const.framerate
    Pig.y = Pig.y + Pig.vy * dt * Const.framerate

    if Collides(Pig, Beet) then
        Beet.x = math.random(Const.margin, Const.width - Const.margin)
        Beet.y = math.random(Const.margin, Const.height - Const.margin)
        Pig.v = Pig.v + 0.8
    end
end
```

### Pełny kod

```lua
function love.load()
    math.randomseed(os.time())

    Const = {width = 800, height = 800, margin = 50, framerate = 60}

    Background = love.graphics.newImage("images/bg.png")

    Pig = {
        x = Const.width / 2,
        y = Const.height / 2,
        vx = 0,
        vy = 0,
        v = 3,
        images = {
            left = love.graphics.newImage("images/pig_left.png"),
            right = love.graphics.newImage("images/pig_right.png"),
            up = love.graphics.newImage("images/pig_up.png"),
            down = love.graphics.newImage("images/pig_down.png")
        },
        sound = love.audio.newSource("sounds/pig.wav", "static")
    }

    Pig.drawable = Pig.images.down

    Beet = {
        x = 200,
        y = 200,
        drawable = love.graphics.newImage("images/beetroot.png")
    }
end

function love.draw()
    love.graphics.setColor(1,1,1,1)
    love.graphics.draw(Background)
    love.graphics.draw(Beet.drawable, Beet.x, Beet.y, 0, 1, 1, Beet.drawable.getWidth(Beet.drawable) / 2, Beet.drawable.getHeight(Beet.drawable) / 2)
    love.graphics.draw(Pig.drawable, Pig.x, Pig.y, 0, 1, 1, Pig.drawable.getWidth(Pig.drawable) / 2, Pig.drawable.getHeight(Pig.drawable) / 2)
end

function love.update(dt)
    Pig.x = Pig.x + Pig.vx * dt * Const.framerate
    Pig.y = Pig.y + Pig.vy * dt * Const.framerate

    if Collides(Pig, Beet) then
        Beet.x = math.random(Const.margin, Const.width - Const.margin)
        Beet.y = math.random(Const.margin, Const.height - Const.margin)
        Pig.v = Pig.v + 0.8
    end
end

function love.keypressed(key, scancode, isrepeat)
    if key == "left" then
        Pig.vx = -Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.left
    end

    if key == "right" then
        Pig.vx = Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.right
    end

    if key == "up" then
        Pig.vx = 0
        Pig.vy = -Pig.v
        Pig.drawable = Pig.images.up
    end

    if key == "down" then
        Pig.vx = 0
        Pig.vy = Pig.v
        Pig.drawable = Pig.images.down
    end
end

function Collides(actor1, actor2)
    return actor1.x + actor1.drawable.getWidth(actor1.drawable) >= actor2.x and
            actor1.x <= actor2.x + actor2.drawable.getWidth(actor2.drawable) and
            actor1.y + actor1.drawable.getHeight(actor1.drawable) >= actor2.y and
            actor1.y <= actor2.y + actor2.drawable.getHeight(actor2.drawable)
end
```

## Punkty

Cóż to za gra bez punktów! Dodanie jednak punktów do naszej gry to żaden problem. Punkty będziemy dostawać za każdego zjedzonego buraka. Na początku dopisujemy punkty w postaci nowej zmiennej **points** do naszej świni. Początkowo punkty ustawiamy na $$0$$. Nasza zmienna `Pig` powinna teraz wyglądać mniej więcej tak:

```lua
Pig = {
    x = Const.width / 2,
    y = Const.height / 2,
    vx = 0,
    vy = 0,
    v = 3,
    points = 0,
    images = {
        left = love.graphics.newImage("images/pig_left.png"),
        right = love.graphics.newImage("images/pig_right.png"),
        up = love.graphics.newImage("images/pig_up.png"),
        down = love.graphics.newImage("images/pig_down.png")
    },
    sound = love.audio.newSource("sounds/pig.wav", "static")
}
```

### Wyświetlamy punkty

Zanim przejdziemy do zliczania punktów, wyświetlmy je na ekranie gry. Aby wyświetlić na ekranie przejrzysty, wycentrowany tekst, przyda nam się pomocnicza funkcja `DrawCenteredText(x, y, text, font)`, która przyjmie cztery parametry: współrzędne środka tekstu (`x, y`), tekst do wyświetlenia (`text`) oraz czcionka do wykorzystania (`font`). Naszą funkcję warto umieścić zaraz pod częścią rysującą (`love.draw`), czyli nad częścią aktualizującą (`love.update`).

```lua
function DrawCenteredText(x, y, text, font)
    local textWidth = font:getWidth(text)
    local textHeight = font:getHeight()
    love.graphics.print(text, font, x, y, 0, 1, 1, textWidth/2, textHeight/2)
end
```

Zanim będziemy mogli wyświetlić tekst na ekranie, potrzebujemy załadować odpowiednią czcionkę i zdefiniować jej rozmiar. W części inicjalizującej (`love.load`), na samym końcu, dopiszemy nowy zbiór `Fonts`, w którym załadujemy sobie czcionkę do wyświetlania punktów:

```lua
Fonts = {
    points = love.graphics.newFont("fonts/kenney_bold.ttf", 60)
}
```

Teraz możemy przystąpić do wyświetlania punktów na ekranie. W tym celu, w części rysującej `love.draw`, dopisujemy wywołanie naszej pomocniczej funkcji `DrawCenteredText`. Jako parametry podamy pozycję tekstu na ekranie (połowa szerokości jako $$x$$ i $$50$$ pikseli jako $$y$$), tekst do wyświetlenia (punkty, czyli `Pig.points`), a także czcionkę do wykorzystania (`Fonts.points`).

```lua
DrawCenteredText(Const.width / 2, 50, Pig.points, Fonts.points)
```

W celu uzyskania ładnego, żółtego koloru, przed wywołaniem funkcji `DrawCenteredText` dopisujemy jeszcze wywołanie polecenia `love.graphics.setColor`. Wybierzemy kolor $$(253, 238, 0)$$.

```lua
love.graphics.setColor(love.math.colorFromBytes(253, 238, 0))
DrawCenteredText(Const.width / 2, 50, Pig.points, Fonts.points)
```

Polecenie dopisujemy na koniec części rysującej.

```lua
function love.draw()
    love.graphics.setColor(1,1,1,1)
    love.graphics.draw(Background)
    love.graphics.draw(Beet.drawable, Beet.x, Beet.y, 0, 1, 1, Beet.drawable.getWidth(Beet.drawable) / 2, Beet.drawable.getHeight(Beet.drawable) / 2)
    love.graphics.draw(Pig.drawable, Pig.x, Pig.y, 0, 1, 1, Pig.drawable.getWidth(Pig.drawable) / 2, Pig.drawable.getHeight(Pig.drawable) / 2)
    love.graphics.setColor(love.math.colorFromBytes(253, 238, 0))
    DrawCenteredText(Const.width / 2, 50, Pig.points, Fonts.points)
end
```

### Zliczamy punkty

Jak już ustaliliśmy, punkty będziemy dostawać za każdego zjedzonego buraka. W takim razie, do części, w której wykrywamy kolizję z burakiem, dopisujemy zwiększanie punktów: `Pig.points = Pig.points + 1`. Warto to dopisać zaraz pod zwiększeniem prędkości świni, tak aby zachować czytelność kodu, ale kolejność nie ma dużego znaczenia.

```lua
if Collides(Pig, Beet) then
    Beet.x = math.random(Const.margin, Const.width - Const.margin)
    Beet.y = math.random(Const.margin, Const.height - Const.margin)
    Pig.v = Pig.v + 0.8
    Pig.points = Pig.points + 1
end
```

### Pełny kod

```lua
function love.load()
    math.randomseed(os.time())

    Const = {width = 800, height = 800, margin = 50, framerate = 60}

    Background = love.graphics.newImage("images/bg.png")

    Pig = {
        x = Const.width / 2,
        y = Const.height / 2,
        vx = 0,
        vy = 0,
        v = 3,
        points = 0,
        images = {
            left = love.graphics.newImage("images/pig_left.png"),
            right = love.graphics.newImage("images/pig_right.png"),
            up = love.graphics.newImage("images/pig_up.png"),
            down = love.graphics.newImage("images/pig_down.png")
        },
        sound = love.audio.newSource("sounds/pig.wav", "static")
    }

    Pig.drawable = Pig.images.down

    Beet = {
        x = 200,
        y = 200,
        drawable = love.graphics.newImage("images/beetroot.png")
    }

    Fonts = {
        points = love.graphics.newFont("fonts/kenney_bold.ttf", 60)
    }
end

function love.draw()
    love.graphics.setColor(1,1,1,1)
    love.graphics.draw(Background)
    love.graphics.draw(Beet.drawable, Beet.x, Beet.y, 0, 1, 1, Beet.drawable.getWidth(Beet.drawable) / 2, Beet.drawable.getHeight(Beet.drawable) / 2)
    love.graphics.draw(Pig.drawable, Pig.x, Pig.y, 0, 1, 1, Pig.drawable.getWidth(Pig.drawable) / 2, Pig.drawable.getHeight(Pig.drawable) / 2)
    love.graphics.setColor(love.math.colorFromBytes(253, 238, 0))
    DrawCenteredText(Const.width / 2, 50, Pig.points, Fonts.points)
end

function DrawCenteredText(x, y, text, font)
	local textWidth = font:getWidth(text)
	local textHeight = font:getHeight()
	love.graphics.print(text, font, x, y, 0, 1, 1, textWidth/2, textHeight/2)
end

function love.update(dt)
    Pig.x = Pig.x + Pig.vx * dt * Const.framerate
    Pig.y = Pig.y + Pig.vy * dt * Const.framerate

    if Collides(Pig, Beet) then
        Beet.x = math.random(Const.margin, Const.width - Const.margin)
        Beet.y = math.random(Const.margin, Const.height - Const.margin)
        Pig.v = Pig.v + 0.8
        Pig.points = Pig.points + 1
    end
end

function love.keypressed(key, scancode, isrepeat)
    if key == "left" then
        Pig.vx = -Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.left
    end

    if key == "right" then
        Pig.vx = Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.right
    end

    if key == "up" then
        Pig.vx = 0
        Pig.vy = -Pig.v
        Pig.drawable = Pig.images.up
    end

    if key == "down" then
        Pig.vx = 0
        Pig.vy = Pig.v
        Pig.drawable = Pig.images.down
    end
end

function Collides(actor1, actor2)
    return actor1.x + actor1.drawable.getWidth(actor1.drawable) >= actor2.x and
            actor1.x <= actor2.x + actor2.drawable.getWidth(actor2.drawable) and
            actor1.y + actor1.drawable.getHeight(actor1.drawable) >= actor2.y and
            actor1.y <= actor2.y + actor2.drawable.getHeight(actor2.drawable)
end
```

## Koniec gry

Cóż to za gra, która się nie kończy? Nasza gra będzie kończyć się, gdy świnia wyjdzie poza ekran. W celu zapamiętania, że gra się już zakończyła, dopiszemy do świni nową zmienną **dead**, którą na początku ustawimy na wartość **false**. Do zbioru `images` naszej świni załadujemy także grafikę __pig_dead.png__. Teraz nasza zmienna `Pig` powinna wyglądać mniej więcej tak:

```lua
Pig = {
    x = Const.width / 2,
    y = Const.height / 2,
    vx = 0,
    vy = 0,
    v = 3,
    points = 0,
    dead = false,
    images = {
        left = love.graphics.newImage("images/pig_left.png"),
        right = love.graphics.newImage("images/pig_right.png"),
        up = love.graphics.newImage("images/pig_up.png"),
        down = love.graphics.newImage("images/pig_down.png"),
        dead = love.graphics.newImage("images/pig_dead.png")
    },
    sound = love.audio.newSource("sounds/pig.wav", "static")
}
```

### Wyświetlamy komunikat

Zacznijmy od wyświetlenia na ekranie komunikatu o zakończeniu gry. W części rysującej, gdy gra jest zakończona, tzn. gdy zmienna `Pig.dead` ma wartość **true**, wyświetlimy na ekranie komunikat **GAME OVER**. Kolor komunikatu ustawimy na czerwony, a dokładniej $$(227, 0, 34)$$.

```lua
if Pig.dead then
    love.graphics.setColor(love.math.colorFromBytes(227, 0, 34))
    DrawCenteredText(Const.width / 2, Const.height / 2, "GAME OVER", Fonts.gameover)
end
```

Całość dopisujemy na koniec części rysującej.

```lua
function love.draw()
    love.graphics.setColor(1,1,1,1)
    love.graphics.draw(Background)
    love.graphics.draw(Beet.drawable, Beet.x, Beet.y, 0, 1, 1, Beet.drawable.getWidth(Beet.drawable) / 2, Beet.drawable.getHeight(Beet.drawable) / 2)
    love.graphics.draw(Pig.drawable, Pig.x, Pig.y, 0, 1, 1, Pig.drawable.getWidth(Pig.drawable) / 2, Pig.drawable.getHeight(Pig.drawable) / 2)
    love.graphics.setColor(love.math.colorFromBytes(253, 238, 0))
    DrawCenteredText(Const.width / 2, 50, Pig.points, Fonts.points)
    if Pig.dead then
        love.graphics.setColor(love.math.colorFromBytes(227, 0, 34))
        DrawCenteredText(Const.width / 2, Const.height / 2, "GAME OVER", Fonts.gameover)
    end
end
```

Warto przetestować, czy komunikat wyświetla się poprawnie, tymczasowo zmieniając wartość zmiennej `Pig.dead` na **true**.

### Sprawdzamy wyjście poza ekran

Nasza gra się kończy, gdy świnia wyjdzie poza ekran gry. Aby sprawdzić, czy tak się stało, wystarczy sprawdzić wartości współrzędnych naszej świni. Jeżeli są mniejsze od zera, albo większe od odpowiednio szerokości i wysokości, to znaczy, że świnia wyszła poza ekran. Dopisujemy więc odpowiedni warunek na koniec części aktualizującej.

```lua
if Pig.x < 0 or Pig.x > Const.width or Pig.y < 0 or Pig.y > Const.height then
end
```

Gdy świnia wyjdzie poza ekran to gra się kończy, ustawiamy więc zmienną `Pig.dead` na wartość **true**.

```lua
if Pig.x < 0 or Pig.x > Const.width or Pig.y < 0 or Pig.y > Const.height then
    Pig.dead = true
end
```

Dla lepszego efektu możemy także przemieścić świnię zaraz nad napis **GAME OVER** i zmienić jej grafikę na `Pig.images.dead`.

```lua
if Pig.x < 0 or Pig.x > Const.width or Pig.y < 0 or Pig.y > Const.height then
    Pig.dead = true
    Pig.x = Const.width / 2
    Pig.y = Const.height / 3
    Pig.drawable = Pig.images.dead
end
```

Tak teraz powinna wyglądać nasza część aktualizująca:

```lua
function love.update(dt)
    Pig.x = Pig.x + Pig.vx * dt * Const.framerate
    Pig.y = Pig.y + Pig.vy * dt * Const.framerate

    if Collides(Pig, Beet) then
        Beet.x = math.random(Const.margin, Const.width - Const.margin)
        Beet.y = math.random(Const.margin, Const.height - Const.margin)
        Pig.v = Pig.v + 0.8
        Pig.points = Pig.points + 1
    end

    if Pig.x < 0 or Pig.x > Const.width or Pig.y < 0 or Pig.y > Const.height then
        Pig.dead = true
        Pig.x = Const.width / 2
        Pig.y = Const.height / 3
        Pig.drawable = Pig.images.dead
    end
end
```

### Zamrożenie rozgrywki

Gdy teraz przetestujemy naszą grę, to zauważymy, że rozgrywka dalej się toczy po zakończeniu gry, tzn. dalej można poruszać świnią i zjadać buraki. Oczywiście nie chcemy, by tak się działo. W tym celu należy dopisać prostą instrukcję warunkową na początek części aktualizującej, a także na początek części odpowiedzialnej za odczytywanie klikniętych przycisków z klawiatury.

```lua
if Pig.dead then
    return
end
```

Dzięki temu, jeżeli gra jest już zakończona, to żadne dalsze instrukcje w danej części nie będą już wykonywane.

### Pełny kod

```lua
function love.load()
    math.randomseed(os.time())

    Const = {width = 800, height = 800, margin = 50, framerate = 60}

    Background = love.graphics.newImage("images/bg.png")

    Pig = {
        x = Const.width / 2,
        y = Const.height / 2,
        vx = 0,
        vy = 0,
        v = 3,
        points = 0,
        dead = false,
        images = {
            left = love.graphics.newImage("images/pig_left.png"),
            right = love.graphics.newImage("images/pig_right.png"),
            up = love.graphics.newImage("images/pig_up.png"),
            down = love.graphics.newImage("images/pig_down.png"),
            dead = love.graphics.newImage("images/pig_dead.png")
        },
        sound = love.audio.newSource("sounds/pig.wav", "static")
    }

    Pig.drawable = Pig.images.down

    Beet = {
        x = 200,
        y = 200,
        drawable = love.graphics.newImage("images/beetroot.png")
    }

    Fonts = {
        points = love.graphics.newFont("fonts/kenney_bold.ttf", 60),
        gameover = love.graphics.newFont("fonts/kenney_bold.ttf", 70)
    }
end

function love.draw()
    love.graphics.setColor(1,1,1,1)
    love.graphics.draw(Background)
    love.graphics.draw(Beet.drawable, Beet.x, Beet.y, 0, 1, 1, Beet.drawable.getWidth(Beet.drawable) / 2, Beet.drawable.getHeight(Beet.drawable) / 2)
    love.graphics.draw(Pig.drawable, Pig.x, Pig.y, 0, 1, 1, Pig.drawable.getWidth(Pig.drawable) / 2, Pig.drawable.getHeight(Pig.drawable) / 2)
    love.graphics.setColor(love.math.colorFromBytes(253, 238, 0))
    DrawCenteredText(Const.width / 2, 50, Pig.points, Fonts.points)
    if Pig.dead then
        love.graphics.setColor(love.math.colorFromBytes(227, 0, 34))
        DrawCenteredText(Const.width / 2, Const.height / 2, "GAME OVER", Fonts.gameover)
    end
end

function DrawCenteredText(x, y, text, font)
	local textWidth = font:getWidth(text)
	local textHeight = font:getHeight()
	love.graphics.print(text, font, x, y, 0, 1, 1, textWidth/2, textHeight/2)
end

function love.update(dt)
    if Pig.dead then
        return
    end

    Pig.x = Pig.x + Pig.vx * dt * Const.framerate
    Pig.y = Pig.y + Pig.vy * dt * Const.framerate

    if Collides(Pig, Beet) then
        Beet.x = math.random(Const.margin, Const.width - Const.margin)
        Beet.y = math.random(Const.margin, Const.height - Const.margin)
        Pig.v = Pig.v + 0.8
        Pig.points = Pig.points + 1
    end

    if Pig.x < 0 or Pig.x > Const.width or Pig.y < 0 or Pig.y > Const.height then
        Pig.dead = true
        Pig.x = Const.width / 2
        Pig.y = Const.height / 3
        Pig.drawable = Pig.images.dead
    end
end

function love.keypressed(key, scancode, isrepeat)
    if Pig.dead then
        return
    end

    if key == "left" then
        Pig.vx = -Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.left
    end

    if key == "right" then
        Pig.vx = Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.right
    end

    if key == "up" then
        Pig.vx = 0
        Pig.vy = -Pig.v
        Pig.drawable = Pig.images.up
    end

    if key == "down" then
        Pig.vx = 0
        Pig.vy = Pig.v
        Pig.drawable = Pig.images.down
    end
end

function Collides(actor1, actor2)
    return actor1.x + actor1.drawable.getWidth(actor1.drawable) >= actor2.x and
            actor1.x <= actor2.x + actor2.drawable.getWidth(actor2.drawable) and
            actor1.y + actor1.drawable.getHeight(actor1.drawable) >= actor2.y and
            actor1.y <= actor2.y + actor2.drawable.getHeight(actor2.drawable)
end
```

## Restart gry

Warto dodać do naszej gry możliwość rozpoczęcia ponownej rozgrywki, gdy gra już się zakończy. W ten sposób nie będziemy musieli wyłączać i ponownie włączać okna gry. Zacznijmy od dodania pomocniczej funkcji **restart**, za pomocą której przywrócimy początkowe ustawienia, takie jak: grafikę świni, pozycję świni, prędkość świni, punkty oraz stan gry. Funkcję dopisujemy na samym dole naszego kodu.

```lua
function Restart()
    Pig.drawable = Pig.images.down
    Pig.x = Const.width / 2
    Pig.y = Const.height / 2
    Pig.vx = 0
    Pig.vy = 0
    Pig.v = 3
    Pig.points = 0
    Pig.dead = false
    Pig.bot = false
end
```

Teraz pozostaje pytanie: kiedy i w jaki sposób restartować grę? Chcemy, aby gracz mógł zrestartować rozgrywkę zaraz po jej zakończeniu. Powiedzmy, że jak gra się już zakończyła i gracz naciśnie **spację**, to rozpocznie się kolejna rozgrywka. Dopiszmy więc stosowną instrukcję do funkcji `love.keypressed`.

```lua
function love.keypressed(key, scancode, isrepeat)
    if Pig.dead then
        if key == "space" then
            Restart()
        end
        
        return
    end

    ...
```

Teraz możemy już restartować naszą rozgrywkę. Warto jeszcze wyświetlić dodatkowy komunikat po zakończeniu gry. Najpierw dodajmy nową czcionkę o rozmiarze $$30$$ do naszego zbioru `Fonts`. Nazwiemy ją `tryagain`.

```lua
tryagain = love.graphics.newFont("fonts/kenney_bold.ttf", 30)
```

Powinniśmy otrzymać coś takiego:

```lua
Fonts = {
        points = love.graphics.newFont("fonts/kenney_bold.ttf", 60),
        gameover = love.graphics.newFont("fonts/kenney_bold.ttf", 70),
        tryagain = love.graphics.newFont("fonts/kenney_bold.ttf", 30)
    }
```

Teraz możemy wyświetlić komunikat. W części rysującej, zaraz pod komunikatem "GAME OVER", dopisujemy:

```lua
DrawCenteredText(Const.width / 2, 2 * Const.height / 3, "Press SPACE to try again", Fonts.tryagain)
```

### Pełny kod

```lua
function love.load()
    math.randomseed(os.time())

    Const = {width = 800, height = 800, margin = 50, framerate = 60}

    Background = love.graphics.newImage("images/bg.png")

    Pig = {
        x = Const.width / 2,
        y = Const.height / 2,
        vx = 0,
        vy = 0,
        v = 3,
        points = 0,
        dead = false,
        images = {
            left = love.graphics.newImage("images/pig_left.png"),
            right = love.graphics.newImage("images/pig_right.png"),
            up = love.graphics.newImage("images/pig_up.png"),
            down = love.graphics.newImage("images/pig_down.png"),
            dead = love.graphics.newImage("images/pig_dead.png")
        },
        sound = love.audio.newSource("sounds/pig.wav", "static")
    }

    Pig.drawable = Pig.images.down

    Beet = {
        x = 200,
        y = 200,
        drawable = love.graphics.newImage("images/beetroot.png")
    }

    Fonts = {
        points = love.graphics.newFont("fonts/kenney_bold.ttf", 60),
        gameover = love.graphics.newFont("fonts/kenney_bold.ttf", 70),
        tryagain = love.graphics.newFont("fonts/kenney_bold.ttf", 30)
    }
end

function love.draw()
    love.graphics.setColor(1,1,1,1)
    love.graphics.draw(Background)
    love.graphics.draw(Beet.drawable, Beet.x, Beet.y, 0, 1, 1, Beet.drawable.getWidth(Beet.drawable) / 2, Beet.drawable.getHeight(Beet.drawable) / 2)
    love.graphics.draw(Pig.drawable, Pig.x, Pig.y, 0, 1, 1, Pig.drawable.getWidth(Pig.drawable) / 2, Pig.drawable.getHeight(Pig.drawable) / 2)
    love.graphics.setColor(love.math.colorFromBytes(253, 238, 0))
    DrawCenteredText(Const.width / 2, 50, Pig.points, Fonts.points)
    if Pig.dead then
        love.graphics.setColor(love.math.colorFromBytes(227, 0, 34))
        DrawCenteredText(Const.width / 2, Const.height / 2, "GAME OVER", Fonts.gameover)
        DrawCenteredText(Const.width / 2, 2 * Const.height / 3, "Press SPACE to try again", Fonts.tryagain)
    end
end

function DrawCenteredText(x, y, text, font)
	local textWidth = font:getWidth(text)
	local textHeight = font:getHeight()
	love.graphics.print(text, font, x, y, 0, 1, 1, textWidth/2, textHeight/2)
end

function love.update(dt)
    if Pig.dead then
        return
    end

    Pig.x = Pig.x + Pig.vx * dt * Const.framerate
    Pig.y = Pig.y + Pig.vy * dt * Const.framerate

    if Collides(Pig, Beet) then
        Beet.x = math.random(Const.margin, Const.width - Const.margin)
        Beet.y = math.random(Const.margin, Const.height - Const.margin)
        Pig.v = Pig.v + 0.8
        Pig.points = Pig.points + 1
    end

    if Pig.x < 0 or Pig.x > Const.width or Pig.y < 0 or Pig.y > Const.height then
        Pig.dead = true
        Pig.x = Const.width / 2
        Pig.y = Const.height / 3
        Pig.drawable = Pig.images.dead
    end
end

function love.keypressed(key, scancode, isrepeat)
    if Pig.dead then
        if key == "space" then
            Restart()
        end
        
        return
    end

    if key == "left" then
        Pig.vx = -Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.left
    end

    if key == "right" then
        Pig.vx = Pig.v
        Pig.vy = 0
        Pig.drawable = Pig.images.right
    end

    if key == "up" then
        Pig.vx = 0
        Pig.vy = -Pig.v
        Pig.drawable = Pig.images.up
    end

    if key == "down" then
        Pig.vx = 0
        Pig.vy = Pig.v
        Pig.drawable = Pig.images.down
    end
end

function Restart()
    Pig.drawable = Pig.images.down
    Pig.x = Const.width / 2
    Pig.y = Const.height / 2
    Pig.vx = 0
    Pig.vy = 0
    Pig.v = 3
    Pig.points = 0
    Pig.dead = false
    Pig.bot = false
end

function Collides(actor1, actor2)
    return actor1.x + actor1.drawable.getWidth(actor1.drawable) >= actor2.x and
            actor1.x <= actor2.x + actor2.drawable.getWidth(actor2.drawable) and
            actor1.y + actor1.drawable.getHeight(actor1.drawable) >= actor2.y and
            actor1.y <= actor2.y + actor2.drawable.getHeight(actor2.drawable)
end
``` 

## Pełna gra

Pełna implementacja dostępna jest poniżej.

{% embed url="https://github.com/blackbat13/hungrypiglualove" %}
Głodna świnia
{% endembed %}
