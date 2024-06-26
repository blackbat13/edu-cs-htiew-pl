# Fruit Ninja

Tym razem stworzymy grę typu *Fruit Ninja*. Cel gry jest prosty. Z brzegu ekranu będą wyskakiwać owoce, a naszym zadaniem będzie je złapać, zanim spadną.

Grę, którą będziemy tworzyć, możemy zobaczyć poniżej.

<iframe id="pixelpad-embed" title="Fruit Ninja" style="border: none;" src="https://pixelpad.io/app/pcsoedfirjh/?emb=1" width="640" height="360"></iframe>

## Tło

Zacznijmy od dodania tła do naszej gry. Proponuję jasne tło, np. niebo. 

### Grafika

Klikamy na plusik koło **Sprites** w menu z lewej strony ekranu i szukamy grafiki o nazwie *Sky Background*, jak pokazano poniżej. Wybieramy ją i zatwierdzamy przyciskiem **Select Asset**. Następnie podajemy nazwę naszej nowej grafiki: *background* i zatwierdzamy przyciskiem **OK**.

![Grafika tła z pixelpad.io](https://s3.us-west-1.amazonaws.com/media.pixelpad.io/__ASSET__.1.341906.1646735302.skybackground.png)

### Klasa

Jak już mamy grafikę, to czas utworzyć klasę do reprezentacji tła. W tym celu klikamy na plusik przy **Classes** i dodajemy klasę o nazwie *Bg*.

Wewnątrz klasy, w części inicjalizacyjnej (zakładka **Start**), musimy przypisać grafikę do obiektu naszej nowej klasy. W tym celu odwołamy się do zmiennej `sprite` wewnątrz naszego obiektu (`self`) i przypiszemy do niej nowy *sprite* utworzony za pomocą funkcji `sprite`. Do funkcji przekażemy jeden parametr: nazwę naszej grafiki.

```python
self.sprite = sprite("background.png")
```

### Gra

Teraz czas dodać nasze nowe tło do gry. W tym celu przechodzimy do klasy **Game**. Wewnątrz utworzymy nowy obiekt klasy *Bg* i przypiszemy go do zmiennej `bg` w naszej grze.

Wszystko to robimy w części inicjalizacyjnej, czyli zakładce **Start**.

```python
self.bg = Bg()
```

Po uruchomieniu gry powinniśmy już zobaczyć nasze nowe tło na ekranie. Świetna robota!

## Owoce

Tło dodaje naszej grze charakteru, ale to owoce będą odgrywały główną rolę, dlatego teraz się nimi zajmiemy.

### Grafika

Zaczynamy standardowo od grafiki. Klikamy na plusik przy **Sprites** i szukamy grafiki pomarańczy (*orange*), takiej jak poniżej. Dodajemy ją i nazywamy *orange*.

![Grafika pomarańczy z pixelpad.io](https://s3.us-west-1.amazonaws.com/media.pixelpad.io/__ASSET__.1.288651.1646737376.orange.png)

### Klasa

Nasze owoce potrzebują klasy, byśmy mogli z nimi pracować. Ponieważ wystarczy nam jedna klasa do reprezentacji wielu owoców, nazwiemy ją **Fruit**. Klikamy na plusik przy **Classes** i dodajemy klasę *Fruit*.

Wewnątrz klasy, w części inicjalizacyjnej (zakładka **Start**), zaczniemy od przypisania grafiki do obiektu owoca. Początkowo zaczniemy od jednej grafiki, ale później będziemy wybierać losowo z większego zestawu. Podobnie jak w przypadku tła przypisujemy do zmiennej `sprite` w obiekcie klasy (`self`) nową grafikę utworzoną za pomocą funkcji `sprite`. Do funkcji przekazujemy nazwę grafiki.

```python
self.sprite = sprite("orange.png")
```

### Gra

Teraz czas dodać nasz nowy owoc do gry. W tym celu przechodzimy do klasy **Game**. Początkowo, tylko dla testów, utworzymy nowy obiekt klasy *Fruit*. Zrobimy to w części inicjalizującej (zakładka *Start*). Nie musimy przypisywać naszego nowego obiektu do żadnej zmiennej, nie będziemy się do niej odwoływać z poziomu obiektu gry.

Nowy owoc tworzymy zaraz pod linijką tworzącą tło, na końcu kodu.

```python
Fruit()
```

Po uruchomieniu gry powinniśmy zobaczyć na ekranie jedną, statyczną pomarańczkę.

### Ruch

Nasz owoc jest dość statyczny. Nawet bardzo statyczny. Dodajmy trochę dynamizmu do naszej gry. Do tego potrzebna nam będzie prędkość. Ponieważ nasze owoce będą się poruszać zarówno w poziomie ($x$) jak i w pionie ($y$) to będziemy potrzebować dwóch zmiennych prędkości. Nazwiemy je `velocityX` oraz `velocityY`.

Utworzymy te dwie zmienne w klasie *Fruit* w części inicjalizacyjnej (zakładka **Start**). Ponieważ będziemy się do nich odwoływać aktualizując pozycję owoca na ekranie, przypiszemy je do obiektu klasy owoca (*self*). Nowe zmienne dopisujemy na dole kodu. Początkowo nadamy im wartości $0$.

```python
self.velocityX = 0
self.velocityY = 0
```

Mamy prędkość, ale brakuje nam ruchu. Prędkość powinna oddziaływać na pozycję owoca na ekranie. Aktualizację pozycji będziemy wykonywać w **każdej klatce animacji**. W tym celu przechodzimy do części aktualizacyjnej w kodzie klasy owoca (zakładka **Loop**).

Na początku pustego kodu dopiszemy dwie linijki dodające wartości prędkości do współrzędnych obiektu na ekranie. Współrzędne zapisane są w zmiennych w obiekcie klasy o nazwach `x` oraz `y`.

```python
self.x += self.velocityX
self.y += self.velocityY
```

Teraz nasze owoce będą się poruszać. Albo i nie będą. Po uruchomieniu gry zobaczymy, że nasza pomarańcza wciąż jest statyczna. Dlaczego? Wyjaśnienie jest proste. Ustaliliśmy obie prędkości na wartości $0$. W związku z tym owoc wciąż *wisi* w jednym miejscu na ekranie. Dla testów spróbuj przypisać jakieś wartości liczbowe do naszych prędkości. Sprawdź jak różne liczby wpływają na ruch pomarańczy. Na koniec przywróć wartości $0$, jeszcze nam się przydadzą.

### Grawitacja

Nasze owoce mają z założenia być wystrzeliwane a potem spadać powoli w dół ekranu. Zaczniemy od części związanej ze spadaniem. Można powiedzieć, że zasymulujemy działanie grawitacji. Grawitacja będzie wpływać na położenie owoca na ekranie, ale pośrednio. Bezpośrednio będzie wpływać na jego prędkość pionową ($y$). W każdej klatce animacji prędkość pionowa owocu będzie zmniejszana o wartość siły grawitacji.

Zmiana jest prosta. W klasie owocu (*Fruit*) w części aktualizacyjnej (zakładka *Loop*) dopisujemy na koniec kodu jedną linijkę:

```python
self.velocityY -= 0.4
```

Po uruchomieniu gry nasz owoc powinien zacząć spadać. Poeksperymentuj z różnymi wartościami siły grawitacji. Wybierz taką, która Tobie odpowiada.

Mamy grawitację, świetnie. Ale co, jeżeli później będziemy chcieli ją zmienić? Musielibyśmy pamiętać, gdzie ją zapisaliśmy. A co jeżeli chcielibyśmy dodać do gry innego typu elementy, na które także będzie oddziaływać grawitacja? Musielibyśmy wówczas dokonywać zmian w kilku miejscach w kodzie. Nie jest to najlepsza praktyka. Dlatego naszą wartość grawitacji przypiszemy do obiektu gry. Przechodzimy do części inicjalizującej w klasie *Game* i na koniec dopisujemy:

```python
self.gravity = 0.4
```

Teraz nasza wartość grawitacji jest dostępna w całej grze. Wszystkie elementy, które będą oddziaływać z grawitacją, będą mogły używać tej wartości. Żeby tak było, wracamy do owoców (klasa *Fruit*). Przechodzimy do części aktualizującej i zmieniamy linijkę, w której stosujemy siłę grawitacji do prędkości owoca:

```python
self.velocityY -= game.gravity
```

Teraz nasze owoce będą spadać zgodnie z wartością grawitacji zdefiniowaną dla całej gry. Jak będziemy chcieli zmienić grawitację, zmienimy ją w kodzie klasy *Game*.

### Wystrzeliwanie

Nasz owoc już spada, to teraz czas, by był także *wystrzeliwany*. Jak uzyskać taki efekt? To stosunkowo proste. Wystarczy, że nadamy owocowi odpowiednią początkową prędkość. Chcielibyśmy, by nasze owoce poruszały się na różne sposoby, dlatego skorzystamy z losowości.

Będziemy potrzebować funkcji `randint` z modułu `random`, która pozwoli nam losować wartości całkowite z zadanego przedziału. Aby móc korzystać z tej funkcji musimy jąnajpierw zaimportować. Przechodzimy do części inicjalizującej (zakładka *Start*) w klasie *Fruit* i **na samym początku kodu**, przed wszystkimi innymi instrukcjami, dopisujemy:

```python
from random import randint
```

Teraz mamy dostęp do funkcji `randint`. W klasie *Fruit* w części aktualizacyjnej (zakładka *Loop*) dopisujemy:

```python
self.velocityX = randint(-3, 3)
```
    
Teraz możemy przejść do losowania początkowej prędkości owoców. Modyfikujemy dwie linijki, w których przypisywaliśmy do zmiennych określających prędkość wartości $0$. Teraz przypiszemy do nich losowe wartości z wybranego przedziału.

```python
self.velocityX = randint(5, 10)
self.velocityY = randint(15, 25)
```

W moich eksperymentach takie przedziały dają najlepsze efekty, ale zachęcam do ekperymentowania i poszukania własnego rozwiązania.

Jak teraz uruchomimy grę, to zobaczymy pomarańczę wystrzeliwującą ze środka ekranu w losowym kierunku w prawo i do góry. Warto grę uruchomić kilkukrotnie by zobaczyć działanie naszej losowości. Dla lepszego jednak efektu zmienimy początkowe położenie owoca tak, by był *wystrzeliwany* z poza brzegu ekranu. W tym celu wybierzemy odpowiednio niską pozycję pionową ($y$), np. $-400$, oraz losową, położoną z lewej strony, pozycję poziomą ($y$), np. z przedziału $<-600, -200>$. W ten sposób uzyskamy efekt *wystrzeliwania* owoców z lewej strony ekranu.

Do części inicjalizującej (zakładka *Start*) w klasie *Fruit* dopisujemy na końcu kodu:

```python
self.x = randint(-600, -200)
self.y = -400
```

Teraz nasze owoce będą wystrzeliwane z lewej strony ekranu.

### Wiele owoców

Do tej pory mamy w grze tylko jedną pomarańczę. To trochę za mało na pełnoprawną rozgrywkę. W naszej grze owoce powinny pojawiać się losowo. Tym się teraz zajmiemy. Ponieważ owoce będziemy dodawać z poziomu gry, przechodzimy do klasy *Game*.

W części inicjalizującej usuwamy linijkę tworzącą owoc (`Fruit()`). Nie będzie już nam potrzebna, służyła tylko do testów.

Owoce będziemy dodawać losowo w trakcie trwania rozgrywki, dlatego przechodzimy do części aktualizującej (zakładka *Loop*). Potrzebna nam będzie losowość, więc na górze kodu importujemy odpowiednią funkcję. Tym razem skorzystamy z losowych liczb **rzeczywistych**, które uzyskamy za pomocą funkcji `random`:

```python
from random import random
```

Jak widać, funkcja nazywa się tak samo jak biblioteka. Skorzystamy z wartości losowych zwracanych przez funkcję `random` aby zadecydować, czy dodać nowy owoc do gry w danej klatce animacji. Funkcja random zwraca liczbę rzeczywistą z przedziału $<0, 1)$.

Założenie jest proste: w każdej klatce animacji losujemy liczbę rzeczywistą. Jeśli wartość tej liczby jest mniejsza niż jakaś mała wartość, np. $0.02$, to dodajemy nowy owoc do gry. 

W klasie *Game* w części aktualizacyjnej (zakładka *Loop*) dopisujemy na końcu kodu:

```python
if random() <= 0.02:
    Fruit()
```

Podobnie jak wcześniej, nie musimy zapisywać nowych owoców do zmiennej. Wystarczy, że będziemy je tworzyć.

Teraz warto uruchomić grę i zobaczyć, jak nowe owoce pojawiają się na ekranie. Warto dostosować wartość w naszym warunku tak, by odpowiadała naszym oczekiwaniu. Im większa wartość, tym owoce będą się częściej pojawiać. A im mniejsza, tym rzadziej będą się pojawiać.

Warto pamiętać, że nie jest to najlepszy sposób na losowe dodawanie nowych elementów do gry, ale jest bardzo prosty i na tym poprzestaniemy.

### Obracanie

Wiele owoców latających po ekranie to ładny widok. Wciąż są one jednak dość *statyczne*. Owoc lecący w powietrzu zazwyczaj się w jakiś sposób *obraca*. Możemy to z łatwością zasymulować.

W klasie *Fruit* w części aktualizującej (zakładka *Loop*), będziemy zmieniać obrót owocu (`self.angle`) o jakąś niewielką wartość. Aby owoc obracał się zgodnie z ruchem wskazówek zegara, będziemy **zmniejszać** zwartość zmiennej `angle`. Dopisujemy na końcu kodu:

```python
self.angle -= 0.5
```

Teraz nasze owoce będą obracać się w trakcie swojej podróży.

### Usuwanie owoców

Gdy nasze owoce wypadną poza ekran, to już ich więcej nie zobaczymy. To nie oznacza jednak, że nie ma ich w grze! Będą sobie spadać i spadać w dół, *w nieskończoność*. Przy dłuższej rozgrywce może to okazać się problematyczne, ponieważ komputer wciąż będzie musiał wyliczać i aktualizować ich pozycję, chociaż nawet nie będziemy ich już widzieć. Dlatego warto posprzątać po sobie. Gdy owoc wypadnie poza ekran gry, to go skasujemy.

Przechodzimy do klasy *Fruit*. W części aktualizacyjnej (zakładka *Loop*) sprawdzimy, czy pozycja pionowa ($y$) owocu jest odpowiednio mała, np. mniejsza niż $-500$. Jeżeli tak, to usuniemy owoc z gry za pomocą funkcji `destroy` do której przekazujemy jeden parametr: obiekt z gry do usunięcią. W naszym przypadku będzie to obecny owoc, czyli `self`. Dopisujemy więc na końcu kodu:

```python
if self.y < -500:
    destroy(self)
```

Teraz gdy nasze owoce wypadną poza ekran, to zostaną skasowane. Nie zobaczymy tego bezpośrednio po uruchomieniu gry, ale jest to ważny element całego procesu.

## Łapanie owoców

Cóż to za *Fruit Ninja*, w którym nie możemy łapać naszych owoców. Teraz zajmiemy się dodaniem głównej funkcjonalności w naszej grze.

### Grafika

Owoce będziemy *łapać* za pomocą myszki. Niemniej przyda nam się grafika do reprezentowania naszej pozycji na ekranie. Skorzystamy z grafiki o nazwie *slicer*: małej białej kropki. Klikamy na plusik przy *Sprites* w menu po lewej stronie, szukamy grafiki, dodajemy ją i zapisujemy pod nazwą *slicer*.

### Klasa

Tak jak i wcześniej, potrzebujemy mieć nową klasę. Klikamy plusik przy *Classes* i dodajemy klasę o nazwie **Slicer**.

W naszej nowej klasie, w części inicjalizującej (zakładka *Start*), przypisujemy grafikę do nowego obiektu, podobnie jak poprzednio:

```python
self.sprite = sprite("slicer.png")
```

### Gra

Aby nasz *slicer* pojawił się w grze, musimy utworzyć jego obiekt. Przechodzimy do klasy *Game* i w części inicjalizacyjnej (zakładka *Start*) tworzymy nowy obiekt `Slicer()` i zapisujemy go w zmiennej w grze o nazwie `slicer`. Całość dopisujemy na końcu kodu.

```python
self.slicer = Slicer()
```

### Poruszanie

Naszym nowym elementem będziemy sterować za pomocą myszki. Jego pozycja powinna zawsze znajdować się tam, gdzie sama myszka. W tym celu przechodzimy do klasy *Slicer*. W części aktualizującej (zakładka *Loop*) będziemy przypisywać obecną pozycję myszki do pozycji obiektu. Współrzędne myszki uzyskamy za pomocą funkcji `mouse_x()` oraz `mouse_y()`. Funkcje nie przyjmują żadnych parametrów.

Dopisujemy więc do naszego kodu dwie linijki:

```python
self.x = mouse_x()
self.y = mouse_y()
```

Teraz nasz *slicer* będzie tam, gdzie wskaźnik naszej myszy w trakcie gry.

### Łapanie owoców

Gdy będziemy trzymać lewy przycisk myszy i najedziemy kursorem na owoc, to ten powinien zostać uznany za *złapany* i w efekcie zniknąć z ekranu. Tę funkcjonalność zaimplementujemy w klasie *Slicer* w części aktualizującej.

Na początku sprawdzimy, czy wciśnięty jest lewy przycisk myszy. Do tego skorzystamy z funkcji `mouse_is_pressed`, która jako parametr przyjmuje nazwę przycisku, który chcemy sprawdzić. Dopisujemy więc do naszego kodu, na końcu:

```python
if is_mouse_is_pressed("left"):
```

Teraz sprawdzimy, czy jesteśmy **w kolizji** z jakimś owocem. Możemy to zrobić za pomocą funkcji `get_collision`, która zwróci nam obiekt, w którym jesteśmy w kolizji, lub wartość *pustą*, jeżeli nie jesteśmy w kolizji. Do funkcji przekazujemy dwa elementy, których kolizję chcemy zbadać. Pierwszy to będzie nasz obecny obiekt (`self`), a drugim będzie nazwa klasy *Fruit*, ponieważ chcemy sprawdzić, czy jesteśmy w kolizji z *jakimkolwiek* owocem.

Dopisujemy więc, wewnątrz bloku naszej instrukcji warunkowej:

```python
if is_mouse_is_pressed("left"):
    fruit = get_collision(self, "Fruit")
```

Teraz pozostało nam sprawdzić, czy jakiś owoc został zwrócony.

```python
if is_mouse_is_pressed("left"):
    fruit = get_collision(self, "Fruit")
    if fruit:
```

Jeżeli tak, to go usuniemy z gry za pomocą funkcji `destroy`.

```python
if is_mouse_is_pressed("left"):
    fruit = get_collision(self, "Fruit")
    if fruit:
        destroy(fruit)
```

Jeżeli teraz przetestujemy grę, to powinniśmy móc *łapać* nasze owoce. Świetnie!

## Punkty

Cóż to za gra bez punktów. W naszej grze będziemy dostawać punkty za każdy trafiony owoc, a tracić, za każdy który wypadnie poza ekran.

### Tekst

Zaczniemy do dodania do naszej gry napisu wyświetlającego punkty na ekranie. W tym celu przechodzimy do klasy *Game*. W części inicjalizującej (zakładka *Start*) utworzymy nowy tekst za pomocą funkcji `text` i zapiszemy go w zmiennej w grze o nazwie `points_text`. Funkcja `text` przyjmuje trzy parametry: tekst do wyświetlenia oraz jego współrzędne na ekranie. Punkty umieścimy w lewym górnym rogu naszej gry. Dopisujemy więc na końcu kodu.

```python
self.points_text = text("Punkty: 0", -600, 350)
```

Teraz powinniśmy już zobaczyć nasze punkty po uruchomieniu gry. Oczywiście nie będą się jeszcze zmieniać.

Dla lepszego efektu zmienimy kolor dodanego tesktu, odwołując się do własności `color` w zmiennej `points_text`. Kolor możemy podać za pomocą angielskiej nazwy, albo w kodzie szesnastkowym.

```python
self.points_text.color = "#F18805"
```

Zmieńmy także rozmiar tekstu. Powinien być odpowiednio duży i czytelny. To zrobimy odwołując się do własności `fontSize`.

```python
self.points_text.fontSize = 80
```

### Zliczanie

Mamy już sposób na wyświetlanie punktów, możemy przejść do ich zliczania. Punkty będziemy pamiętać w zmiennej `points` w klasie *Game*. Dopisujemy więc w części inicjalizującej:

```python
self.points = 0
```

Zmienimy także jego wartość na ekranie. W tym celu zmienimy tekst, który wyświetla nam punkty. Dopisujemy więc w części aktualizującej (zakładka *Loop*):

```python
self.points_text.text = "Punkty: " + str(self.points)
```

Teraz pozostało dodawać i odejmować punkty. Przechodzimy więc najpierw do klasy *Slicer*. W części aktualizującej, gdzie wykrywamy kolizję z owocem i go usuwamy, dopiszemy zwiększanie liczby punktów. Dopisujemy, zaraz pod instrukcją `destroy(fruit)`, zachowując odpowiednie wcięcie:

```python
game.points += 1
```

Podobnie zrobimy, gdy owoc zniknie poza ekranem. Przechodzimy do części aktualizującej w klasie `Fruit`. Zaraz pod instrukcją `destroy(self)`, za pomocą której usuwamy owoce, które wypadły poza ekran, dopisujemy, zachowując odpowiednie wcięcie:

```python
game.points -= 1
```

Całość powinna wyglądać tak:

```python
if is_mouse_is_pressed("left"):
    fruit = get_collision(self, "Fruit")
    if fruit:
        destroy(fruit)
        game.points -= 1
```

Teraz, gdy uruchomimy grę, powinniśmy widzieć, jak nasze punkty się zmieniają. Możemy już konkurować z innymi o najlepszy wynik!

## Animacja trafienia

Nasza gra będzie wyglądała znacznie lepiej, gdy po trafieniu owoc efektownie się *rozpadnie*. W tym celu dodamy odpowiednią animację.

### Grafika

Zaczynamy od znalezienia odpowiedniej grafiki, a dokładniej animacji utworzonej z kilku grafik. Klikamy plusik przy *Sprites* i szukamy *Orange Splash*, jak pokazano piniżej. Dodajemy i zapisujemy pod nazwą *orangesplash*.

![Animacja z pixelpad.io](https://s3.us-west-1.amazonaws.com/media.pixelpad.io/__ASSET__.1.288651.1646741545.orangesplashanim.gif)

### Klasa

Do wyświetlania naszej animacji potrzebna nam będzie nowa klasa. Klikamy plusik przy *Classes* i tworzymy klasę o nazwie *Splash*. Wykorzystamy ją do animacji także dla innych owoców, nie tylko pomarańczy.

Klasa będzie bardzo prosta. Nie będziemy w niej inicjalizować samej animacji, zrobimy to z innego miejsca. Tutaj przechowamy wyłącznie licznik, który posłuży nam do usunięcia animacji po odpowiednim czasie. W części inicjalizującej dopisujemy więc zmienną do obiektu klasy. Nazwiemy ją *timer* i przypiszemy początkową wartość równą $16$. Będzie to liczba klatek, po której animacja zostanie usunięta.

```python
self.timer = 16
```

W części aktualizującej będziemy zmniejszać ten licznik, a gdy dojdzie do zera, to usuniemy nasz obiekt animacji. Żeby uniezależnić się od liczby klatek na sekundę, będziemy odejmować w każdej klatce nie wartość $1$, ale wartość $60$ podzieloną przez aktualną liczbę klatek na sekundę. Dlaczego $60$? W takiej liczbie klatek powinna działać nasza gra. Liczbę klatek na sekundę otrzymamy za pomocą funkcji `get_fps()`. Dopisujemy więc w części aktualizującej (zakładka *Loop*):

```python
self.timer -= 60 / game.get_fps()
```

Teraz, gdy licznik osiągnie wartość $0$, usuniemy nasz obiekt animacji.

```python
if self.timer <= 0:
    destroy(self)
```
    
### Przygotowanie animacji

Teraz czas wczytać grafiki i utworzyć z nich animację. Będziemy ją przechowywać w klasie *Fruit*. Jest to ważne z tego względu, że gdy będziemy mieli różne owoce, to trzeba do nich dopasować także animacje. Przechodzimy więc do klasy *Fruit* i części inicjalizacyjnej (zakładka *Start*).

Najpierw utworzymy zmienną, w której przechowamy grafiki animacji. Będzie to zwykła, **lokalna** zmienna, którą nazwiemy *splash*. Przypiszemy do niej wczytaną grafikę korzystając z funkcji `sprite`, do której przekażemy trzy parametry: nazwę pliku grafiki, liczbę wierszy oraz liczbę kolumn. Gdy otworzymy naszą załadowaną wcześniej grafikę *orangesplash.png*, to zobaczymy, że składa się ona z kilku obrazków: kolejnych **klatek animacji**. Są one ułożone w dwa wiersze i cztery kolumny. Dopisujemy więc na koniec kodu:

```python
splash = sprite("orangesplash.png", 2, 4)
```

Teraz możemy na podstawie załadowanej grafiki utworzyć właściwą animację. Utworzymy zmienną przypisaną już do obiektu naszego owoca, ponieważ będzie nam później potrzebna w innym miejscu. Zmienną nazwiemy `splash_animation`. Przypiszemy do niej wynik działania funkcji `animation`, do której przekażemy cztery parametry: załadowaną grafikę (`splash`), liczbę klatek na sekundę do wyświetlenia animacji ($16$), indeks początkowej klatki z załadowanych grafik ($0$), indeks końcowej klatki z załadowanych grafik ($7$). Animację wyświetlimy w szesnastu klatkach na sekundę, ponieważ jest krótka i nie chcemy, by tylko *mignęła*, ale była dobrze widoczna. Jak można zauważyć, klatki indeksujemy od zera. Dopisujemy więc na koniec kodu:

```python
self.splash_animation = animation(splash, 16, 0, 7)
```

### Uruchomienie animacji

Teraz, jak już mamy wszystko przygotowane, czas przejść do uruchomienia animacji w odpowiednim momencie. Chcemy to zrobić wtedy, gdy złapiemy owoc na ekranie. Za łapanie owoców odpowiada *Slicer*, do niego więc przechodzimy. Otwieramy zakładkę z kodem aktualizacyjnym (*Loop*) i szukamy miejsca, w którym usuwamy złapany owoc. Fragment kodu, który nas interesuje, powinien wyglądać mniej więcej tak:

```python
if is_mouse_is_pressed("left"):
    fruit = get_collision(self, "Fruit")
    if fruit:
        destroy(fruit)
        game.points -= 1
```

Teraz, **przed** instrukcją usuwającą owoc, utworzymy nową animację i zapiszemy ją w zmiennej lokalnej *splash*.

```python hl_lines="4"
if is_mouse_is_pressed("left"):
    fruit = get_collision(self, "Fruit")
    if fruit:
        splash = Splash()
        destroy(fruit)
        game.points -= 1
```

Po utworzeniu zmiennej `splash` musimy przypisać do niej załadowaną wcześniej animację ze zmiennej `fruit`. To utworzymy korzystając z funkcji `set_animation` do której podajemy dwa parametry: obiekt, do którego chcemy przypisać animację (`splash`), oraz animację, którą chcemy przypisać (`fruit.splash_animation`):

```python hl_lines="5"
if is_mouse_is_pressed("left"):
    fruit = get_collision(self, "Fruit")
    if fruit:
        splash = Splash()
        set_animation(splash, self.splash_animation)
        destroy(fruit)
        game.points -= 1
```

Gdy teraz uruchomimy grę i złapiemy owoc to zobaczymy, że animacja się tworzy, ale nie we właściwym miejscu, tylko na środku ekranu. Oznacza to, że musimy jeszcze do zmiennej `splash` przypisać odpowiednie współrzędne. Ponieważ chcemy, by animacja pojawiła się w miejscu, w którym znajduje się owoc, przepiszemy współrzędne ze zmiennej `fruit`:

```python hl_lines="6 7"
if is_mouse_is_pressed("left"):
    fruit = get_collision(self, "Fruit")
    if fruit:
        splash = Splash()
        set_animation(splash, self.splash_animation)
        splash.x = fruit.x
        splash.y = fruit.y
        destroy(fruit)
        game.points -= 1
```
            
Teraz już jest dużo lepiej, ale animacja będzie dość duża w stosunku do rozmiaru owoca. Możemy to zmienić modyfikując jej skalę. Zmienimy wartości dwóch zmiennych: `splash.scaleX` oraz `splash.scaleY`. Są to odpowiednio wartości skali w poziomie i w pionie. Przypiszemy do nich połowę odpowiednich wartości skali ze zmiennej `fruit`:

```python hl_lines="8 9"
if is_mouse_is_pressed("left"):
    fruit = get_collision(self, "Fruit")
    if fruit:
        splash = Splash()
        set_animation(splash, self.splash_animation)
        splash.x = fruit.x
        splash.y = fruit.y
        splash.scaleX = fruit.scaleX/2
        splash.scaleY = fruit.scaleY/2
        destroy(fruit)
        game.points -= 1
```

Teraz animacja jest już gotowa.

## Czas i koniec gry

Nasza gra powinna się kiedyś zakończyć, nie tylko wtedy, gdy się nią znudzimy. Dodamy licznik czasu, po którego upłynięciu gra się zakończy.

### Czas

Wyświetlanie i zliczanie czasu zrobimy z poziomu klasy `Game`. Najpierw zaczniemy od zapamiętania czasu, który nam pozostał. W części inicjalizującej (zakładka *Start*) tworzymy nową zmienną przypisaną do obiektu gry. Nazwiemy ją *time* i ustawimy jej początkową wartość na $61$. W ten sposób będziemy mieli $60$ sekund na rozgrywkę. Dlaczego więc ustawiamy $61$ a nie $60$? Ponieważ ta jedna sekunda zdąży upłynąć, zanim gra właściwie wystartuje. Dodajemy nową zmienną na końcu kodu.

```python
self.time = 61
```

Teraz czas wyświetlić czas na ekranie. Do tego utworzymy kolejną zmienną zapisaną w obiekcie gry, tym razem o nazwie *time_text*. Przypiszemy do niej tekst utworzony za pomocą funkcji `text`, podobnie jak zrobiliśmy z punktami. Licznik czasu umieścimy w prawym górnym rogu. Nadamy mu także odpowiedni kolor (`color`) i rozmiar (`fontSize`).

```python hl_lines="2-4"
self.time = 61
self.time_text = text(self.time, 500, 350)
self.time_text.color = "#0E1428"
self.time_text.fontSize = 80
```

Po uruchomieniu powinniśmy już widzieć czas w prawym górnym rogu ekranu gry. Oczywiście nie będzie się jeszcze zmieniał. Tym się teraz zajmiemy. Przechodzimy do części aktualizującej (zakładka *Loop*). Na koniec kodu dopiszemy instrukcję zmniejszającą naszą zmienną `time` o liczbę sekund, które upłynęły od ostatniej klatki animacji. W tym celu musimy znowu skorzystać z funkcji `get_fps()`. Najpierw dzielimy $60$ przez liczbę klatek, a następnie wynik znowy dzielimy na $60$, by uzyskać sekudny. Całość odejmujemy od zmiennej `time`.

```python
self.time -= (60/get_fps()) / 60
```

Teraz pozostało nam zaktualizować wyświetlany czas. Ponieważ czas będzie teraz liczbą rzeczywistą, a my chcemy wyświetlać tylko pełne sekundy, to musimy go zamienić na liczbę całkowitą za pomocą funkcji `int` przypisując go do tekstu.

```python hl_lines="2"
self.time -= (60/get_fps()) / 60
self.time_text.text = int(self.time)
```

Teraz powinniśmy widzieć zmieniający się czas na ekranie.

### Koniec gry

Gdy licznik czasu dobiegnie końca gra powinna się zatrzymać. Do tego będziemy potrzebowali jednej dodatkowej zmiennej do pamiętania, czy gra się już zakończyła. Dodamy nową zmienną do naszego obiektu gry. Nazwiemy ją `game_over` i przypiszemy jej początkową wartość `False`. Nową zmienną dopisujemy na końcu w części inicjalizującej (zakładka *Start*).

```python
self.game_over = False
```

Teraz musimy zmienić nasz kod, aby sprawdzał, czy gra się zakończyła. Wracamy do zakładki *Loop*. Najpierw, **na samym początku kodu**, sprawdzimy, czy gra się już zakończyła. Jeżeli tak, to użyjemy instrukcji `return` by nie wykonywać już żadnych więcej operacji.

```python
if self.game_over:
    return
```

Teraz czas zakończyć grę, gdy licznik czasu spadnie do zera. W tym celu wracamy do miejsca, gdzie aktualizowaliśmy nasz czas.

```python
self.time -= (60/get_fps()) / 60
self.time_text.text = int(self.time)
```

**Pomiędzy** te dwie linijki kodu dodamy instrukcję sprawdzającą, czy czas spadł **poniżej** zera. Tak będzie łatwiej, niż sprawdzać czy czas wynosi równe zero, ponieważ pracujemy na liczbach rzeczywistych.

```python hl_lines="3"
self.time -= (60/get_fps()) / 60

if self.time < 0:

self.time_text.text = int(self.time)
```

Jeżeli tak się wydarzy, to zrobimy dwie rzeczy: zapamiętamy, że gra się zakończyła zmieniając wartość zmiennej `game_over` na `True` i ustawimy czas na $0$, aby nie wyświetlać ujemnych wartości.

```python hl_lines="3-5"
self.time -= (60/get_fps()) / 60

if self.time < 0:
    self.game_over = True
    self.time = 0

self.time_text.text = int(self.time)
```

Teraz gra powinna się kończyć wraz z upływem czasu.

### Napis końca gry

Warto poinformować gracza stosownym komunikatem, że gra się zakończyła. W tym celu utworzymy napis *GAME OVER*, który wyświetli się na środku ekranu po zakończeniu gry. Napis początkowo powinien być niewidoczny, dlatego ustawimy jego własność `visible` na `False`. Poza tym wyrównamy go także w poziomie (`halign`) oraz w pionie (`valign`). Wszystko zapiszemy w zmiennej `game_over_text` w obiekcie gry. Dopisujemy nowy fragment na końcu części inicjalizującej (zakładka *Start*).

```python
self.game_over_text = text("GAME OVER", 0, 0)
self.game_over_text.color = "#FF4365"
self.game_over_text.fontSize = 120
self.game_over_text.halign = "center"
self.game_over_text.valign = "middle"
self.game_over_text.visible = False
```

Tekst powinniśmy wyświetlić, jak gra się zakończy. Przechodzimy więc do zakładki *Loop* i szukamy fragmentu, w którym ustawiamy wartość zmiennej `game_over` na `True`.

```python
if self.time < 0:
    self.game_over = True
    self.time = 0
```

Pod spodem, wewnątrz instrukcji warunkowej, zmieniamy widoczność tekstu końca gry.

```python hl_lines="4"
if self.time < 0:
    self.game_over = True
    self.time = 0
    self.game_over_text.visible = True
```

Teraz powinniśmy zobaczyć napis *GAME OVER* na ekranie po zakończeniu gry.

### Restart

Grę możemy restartować *ręcznie*, uruchamiając ją ponownie, ale dobrze byłoby móc to także zrobić z poziomu gry. Dlatego dodamy możliwość restartu gry po jej zakończeniu, gdy gracz wciśnie **prawy** przycisk myszy. Dlaczego prawy? Ponieważ lewy jest używany w rozgrywce.

Przechodzimy do zakładki *Loop* w klasie `Game`. Na samym początku kodu mamy instrukcję, która sprawdza, czy gra się zakończyła.

```python
if self.game_over:
    return
```

Wewnątrz tej instrukcji, **przed** wykonaniem `return`, sprawdzimy, czy naciśnięty został prawy przycisk myszy.

```python hl_lines="2"
if self.game_over:
    if mouse_is_pressed("right"):
    return
```

Jeżeli tak jest, to ustawimy wartość `game_over` na `False`, ukryjemy tekst końca gry, wyzerujemy punkty oraz przywrócimy początkową wartość licznika czasu.

```python hl_lines="2"
if self.game_over:
    if mouse_is_pressed("right"):
        self.time = 61
        self.points = 0
        self.game_over_text.visible = False
        self.game_over = False
    return
```

Teraz powinniśmy móc ponownie uruchomić rozgrywkę po jej zakończeniu za pomocą prawego przycisku myszy.

## Skończona gra

Pełen kod gry można znaleźć pod adresem [https://pixelpad.io/app/pcsoedfirjh/?edit=1](https://pixelpad.io/app/pcsoedfirjh/?edit=1).