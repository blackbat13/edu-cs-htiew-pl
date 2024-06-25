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

