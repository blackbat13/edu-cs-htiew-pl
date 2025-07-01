# Skacząca piłka

## Wstęp

Stworzymy prostą animację, w której piłka spada pod wpływem grawitacji i odbija się od podłogi. Nauczymy się symulować fizykę ruchu, wykrywać kolizję z podłogą oraz dodawać efekty wizualne i interaktywne rozszerzenia.

### Czego się nauczysz

- Jak zastosować grawitację do obiektu.
- Jak symulować ruch z wykorzystaniem prędkości i przyspieszenia.
- Jak wykrywać i obsługiwać kolizję z podłogą.
- Jak dodawać rozszerzenia: wiele piłek, interakcję z myszą, zmianę koloru przy odbiciu.

## Podstawowa konfiguracja

Zaczniemy od podstawowej konfiguracji naszego projektu. Dodamy potrzebne zmienne i narysujemy naszą piłkę.

### Zmienne i ustawienia początkowe

Na początku deklarujemy zmienne do kontroli pozycji, prędkości, grawitacji i promienia piłki. Dodajemy je na samej górze naszego projektu.

```javascript
let y = 0;       // Początkowa pozycja pionowa
let speed = 0;   // Początkowa prędkość
let gravity = 0.5; // Wartość przyspieszenia grawitacyjnego
let radius = 50; // Promień piłki
```

Następnie, wewnątrz funkcji `setup`, tworzymy płótno o wymiarach $400\times400$ pikseli.

```javascript
function setup() {
    createCanvas(400, 400); // Tworzymy płótno o rozmiarze 400x400 pikseli
}
```

### Rysowanie piłki

Przejdźmy teraz do narysowania naszej piłki na ekranie. Zanim to jednak zrobimy, musimy wypełnić tło kolorem. Robimy to wewnątrz funkcji rysującej `draw` za pomocą funkcji `background`. Funkcja `background` wypełnia tło kolorem podanym jako parametr. Kolor możemy podać na różne sposoby, np. za pomocą trzech wartości **RGB**, tzn. składowych koloru: czerwony (*red*), zielony (*green*), niebieski (*blue*). Jeżeli chcemy uzyskać szary kolor, wystarczy że podamy jedną wartość, ponieważ w przypadku odcieni szarości wartości składowych muszą być sobie równe.

```javascript
function draw() {
    background(220);  // Wypełniamy tło kolorem
}
```

Teraz możemy narysować piłkę. Najpierw ustalmy jej kolor. Zrobimy to za pomocą funkcji `fill`, która, podobnie jak funkcja `background`, przyjmuje jako parametr wartość koloru, którym zostanie wypełniony rysowany przez nas kształt.

```javascript
function draw() {
    background(220);  

    fill(255, 0, 100); // Ustawiamy kolor piłki
}
```

Aby narysować samą piłkę użyjemy funkcji `circle` do narysowania koła. Funkcja przyjmuje trzy parametry: pozycję `x`, pozycję `y` oraz średnicę rysowanego koła, tzn. promień (`radius`) razy dwa. Chcemy, aby nasza piłka znajdowała się na środku ekranu w poziomie, więc jako pozycję `x` przyjmiemy połowę szerokości ekranu: `width/2`. Pozycja pionowa piłki określona jest przez utworzoną przez nas wcześniej zmienną `y`.

W pętli `draw()` aktualizujemy pozycję piłki i rysujemy ją:

```javascript
function draw() {
    background(220);  

    fill(255, 0, 100);
    circle(width/2, y, radius * 2); // Rysujemy koło na środku, na aktualnej wysokości
}
```

## Symulacja fizyki

Teraz, gdy mamy już piłkę na ekranie, możemy wprawić ją w ruch.

### Grawitacja i ruch

Aby nasza piłka się poruszała, musimy zmieniać jej położenie, a konkretnie zmienną `y`. Położenie piłki powinno zmieniać się wraz z prędkością. Prędkość natomiast modyfikowana jest przez grawitację. Założenie jest proste: w każdej klatce animacji najpierw zwiększamy prędkość o wartość grawitacji, a następnie aktualizujemy pozycję piłki zgodnie z obecną prędkością.

Nasze obliczenia dodamy wewnątrz funkcji `draw`, zaraz po wypełnieniu tła kolorem, a przed rysowaniem piłki. Zaczynamy od zwiększenia prędkości (`speed`) o wartość grawitacji (`gravity`).

```javascript
function draw() {
    background(220); 
    
    speed += gravity; // Dodajemy przyspieszenie do prędkości
    
    fill(255, 0, 100); 
    circle(width/2, y, radius * 2); 
}
```

Teraz możemy zmienić pozycję piłki zgodnie z jej prędkością.

```javascript
function draw() {
    background(220); 
    
    speed += gravity;
    y += speed;       // Aktualizujemy pozycję pionową
    
    fill(255, 0, 100); 
    circle(width/2, y, radius * 2); 
}
```

Teraz nasza piłka powinna zacząć spadać z coraz większą prędkością.

## Kolizja z podłogą

Aby nasza piłka odbijała się od podłogi, musimy wykryć, kiedy się z podłogą zderzy. W tym celu, zaraz po zmianie pozycji piłki, sprawdzimy czy piłka nie *wypadła* poza ekran, tzn. czy jej pozycja `y` nie przekroczyła wysokości ekranu pomniejszonej o promień piłki.

Dodajemy odpowiedni warunek wewnątrz funkcji `draw`, zaraz po zmianie zmiennej `y`.

```javascript
function draw() {
    background(220); 
    
    speed += gravity;
    y += speed;

    if (y > height - radius) { // Wykrywamy kolizję z podłogą
    }
    
    fill(255, 0, 100); 
    circle(width/2, y, radius * 2); 
}
```

Jeżeli kolizja z podłogą nastąpiła to piłka powinna zacząć się poruszać w przeciwnym przypadku. W tym celu wystarczy, że zmienimy prędkość na przeciwną, tzn. przemnożymy przez wartość ujemną. Chcemy także, aby piłka powoli zwalniała, dlatego za każdym razem będziemy zmniejszać prędkość. Możemy to zrobić przemnażająć prędkość piłki przez ułamek mniejszy od $1$.

```javascript
function draw() {
    background(220); 
    
    speed += gravity;
    y += speed;

    if (y > height - radius) { 
        speed *= -0.8; // Odwracamy kierunek ruchu z utratą energii
    }
    
    fill(255, 0, 100); 
    circle(width/2, y, radius * 2); 
}
```

Teraz nasza piłka powinna odbijać się od podłogi. Zobaczymy jednak, że po pewnym czasie piłka wypadnie poza ekran. Dzieje się tak ponieważ przy małych prędkościach piłka nie zdąży się odbić, zanim ponownie nie zmienimy kierunku ruchu. Dlatego po każdym odbiciu przywrócimy także piłkę na pozycję zaraz przy podłodze, tak aby nie wystawała poza ekran. 

```javascript
function draw() {
    background(220); 
    
    speed += gravity;
    y += speed;

    if (y > height - radius) { 
        speed *= -0.8;
        y = height - radius; // Zapobiegamy przejściu piłki przez podłogę
    }
    
    fill(255, 0, 100); 
    circle(width/2, y, radius * 2); 
}
```

## Pełny kod (wersja podstawowa)

```javascript
let y = 0;       // Pozycja pionowa
let speed = 0;   // Prędkość ruchu
let gravity = 0.5; // Wartość grawitacji
let radius = 25; // Promień piłki

function setup() {
    createCanvas(400, 400); // Ustawiamy rozmiar płótna
}

function draw() {
    background(220); // Tło
    
    // Symulacja fizyki
    speed += gravity; // Dodajemy grawitację do prędkości
    y += speed;       // Aktualizujemy pozycję
    
    // Kolizja z podłogą
    if (y > height - radius) {
        speed *= -0.8; // Odbicie z tłumieniem
        y = height - radius; // Poprawiamy pozycję
    }
    
    // Rysowanie piłki
    fill(255, 0, 100); // Kolor czerwony
    circle(width/2, y, radius * 2); // Rysujemy koło
}
```

## Rozszerzenia

Tutaj pokażemy jak możemy rozszerzyć naszą animację o nowe funkcjonalności.

### Wiele piłek

W celu dodania wielu piłek potrzebna nam będzie tablica, w której będziemy te piłki trzymać. Pozbędziemy się pojedyńczych zmiennych, zamiast tego będziemy wartości dodawać do tablicy.

#### Piłki dodawane ręcznie

```javascript
let balls = [];

let gravity = 0.5; // Wartość grawitacji

function setup() {
    createCanvas(400, 400); // Ustawiamy rozmiar płótna
  
    balls.push({ // Dodajemy piłkę do tablicy
      x: width / 2, // Początkowa pozycja pozioma piłki
      y: 0, // Początkowa pozycja pionowa piłki
      speed: 0, // Początkowa prędkość piłki
      radius: 25, // Promień piłki
      color: color(255, 0, 100) // Kolor piłki
    });
  
    balls.push({ // Dodajemy piłkę do tablicy
      x: width / 4, // Początkowa pozycja pozioma piłki
      y: 0, // Początkowa pozycja pionowa piłki
      speed: 0, // Początkowa prędkość piłki
      radius: 30, // Promień piłki
      color: color(0, 255, 100) // Kolor piłki
    });
}

function draw() {
    background(220); // Tło
  
    for(let b of balls) {
      b.speed += gravity;
      b.y += b.speed;
      if (b.y > height - b.radius) {
        b.speed *= -0.8;
        b.y = height - b.radius;
      }
      
      fill(b.color);
      circle(b.x, b.y, b.radius * 2);
    }
}
```

#### Losowane piłki

```javascript
let balls = [];

let gravity = 0.5; // Wartość grawitacji

function setup() {
    createCanvas(400, 400); // Ustawiamy rozmiar płótna
  
    for(let i = 0; i < 50; i++) {
      let radius = random(5, 50);
      balls.push({ // Dodajemy piłkę do tablicy
        x: random(radius, width - radius), // Początkowa pozycja pozioma piłki
        y: random(radius, height - radius), // Początkowa pozycja pionowa piłki
        speed: 0, // Początkowa prędkość piłki
        radius: radius, // Promień piłki
        color: color(random(0,255), random(0,255), random(0, 255)) // Kolor piłki
      });
    }
}

function draw() {
    background(220); // Tło
  
    for(let b of balls) {
      b.speed += gravity;
      b.y += b.speed;
      if (b.y > height - b.radius) {
        b.speed *= -0.8;
        b.y = height - b.radius;
      }
      
      fill(b.color);
      circle(b.x, b.y, b.radius * 2);
    }
}
```

### Interakcja z myszą

Dodajemy nową funkcję `mousePressed()` do tworzenia nowych piłek:

```javascript
function mousePressed() {
  balls.push({ // Dodajemy piłkę do tablicy
        x: mouseX, // Początkowa pozycja pozioma piłki
        y: mouseY, // Początkowa pozycja pionowa piłki
        speed: 0, // Początkowa prędkość piłki
        radius: random(5, 50), // Promień piłki
        color: color(random(0,255), random(0,255), random(0, 255)) // Kolor piłki
      });
}
```

### Wiecznie odbijające się piłki

Sprawimy, aby piłka, gdy już skończy się odbijać, to zaczęła się odbijać ponownie. W tym celu sprawdzimy, czy prędkość piłki jest blizka zeru. Dokładniej, czy jej wartość bezwzględna jest mniejsza od jednej dziesiątej. Jeżeli tak jest, to ustawimy nową, losową wartość prędkości dla naszej piłki. Nową instrukcję dodajemy wewnątrz funkcji `draw`, zaraz przed rysowaniem piłki.

```javascript
function draw() {
    background(220); // Tło
  
    for(let b of balls) {
      b.speed += gravity;
      b.y += b.speed;
      if (b.y > height - b.radius) {
        b.speed *= -0.8;
        b.y = height - b.radius;
      }
      
      if (abs(b.speed) < 0.1) { // Sprawdzamy, czy piłka praktycznie przestała się ruszać
        b.speed = random(5, 20); // Jeżeli tak, nadajemy jej nową prędkość by wznowić jej ruch
      }
      
      fill(b.color);
      circle(b.x, b.y, b.radius * 2);
    }
}
```

### Odbijanie się na boki

```javascript
let balls = [];

let gravity = 0.5; // Wartość grawitacji

function setup() {
    createCanvas(400, 400); // Ustawiamy rozmiar płótna
  
    for(let i = 0; i < 50; i++) {
      let radius = random(5, 50);
      balls.push({ // Dodajemy piłkę do tablicy
        x: random(radius, width - radius), // Początkowa pozycja pozioma piłki
        y: random(radius, height - radius), // Początkowa pozycja pionowa piłki
        speedX: random(-10, 10), // Początkowa prędkość pozioma piłki
        speedY: 0, // Początkowa prędkość pionowa piłki
        radius: radius, // Promień piłki
        color: color(random(0,255), random(0,255), random(0, 255)) // Kolor piłki
      });
    }
}

function draw() {
    background(220); // Tło
  
    for(let b of balls) {
      b.speedY += gravity;
      b.x += b.speedX;
      b.y += b.speedY;
      if (b.y > height - b.radius) {
        b.speedY *= -0.8;
        b.y = height - b.radius;
      }
      
      if(b.x > width - b.radius || b.x < b.radius) {
        b.speedX *= -1;
      }
      
      if (abs(b.speedY) < 0.1) {
        b.speedY = random(5, 20);
      }
      
      fill(b.color);
      circle(b.x, b.y, b.radius * 2);
    }
}

function mousePressed() {
  balls.push({ // Dodajemy piłkę do tablicy
        x: mouseX, // Początkowa pozycja pozioma piłki
        y: mouseY, // Początkowa pozycja pionowa piłki
        speedX: random(-10, 10), // Początkowa prędkość pozioma piłki
        speedY: 0, // Początkowa prędkość pionowa piłki
        radius: random(5, 50), // Promień piłki
        color: color(random(0,255), random(0,255), random(0, 255)) // Kolor piłki
      });
}
```

## Podsumowanie

Udało Ci się stworzyć dynamiczną animację piłki odbijającej się od podłogi! Możesz teraz eksperymentować z wartościami grawitacji, tłumieniem odbicia lub dodawać kolejne rozszerzenia, np. kolizje między piłkami, różne kształty, dźwięki czy zapis wyników. Kod jest gotowy do modyfikacji i rozwoju!