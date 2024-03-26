# Gry 2D - Pygame Zero

Poznaliśmy już niezbędne podstawy programowania w języku Python, pora więc przejść do tworzenia bardziej interaktywnych gier dwuwymiarowych. W tym kursie wykorzystamy jedną z bibliotek do tworzenia takich gier: **PyGame Zero**.

Ci z Was, którzy interesują się tworzeniem gier mogli już wcześniej słyszeć o bibliotece **PyGame**, jednej z najpopularniejszych do tworzenia gier w języku Python. **PyGame Zero** jest "uproszczoną" wersją tej biblioteki, idealną do rozpoczęcia nauki tego pięknego języka. Nie jest ona częścią domyślnej instalacji języka Python, musimy więc ją samodzielnie zainstalować.

## Pygame Zero

Pygame Zero to biblioteka dla Pythona, przeznaczona do tworzenia gier. Jest to "zerowy wysiłek" dla użytkowników, co oznacza, że jest prosta w użyciu i nie wymaga instalacji dodatkowych narzędzi. Pygame Zero jest nakładką na bibliotekę Pygame, ale jest prostsza i bardziej dostępna dla początkujących.

[Pygame Zero](https://pygame-zero.readthedocs.io/en/stable/index.html)

### Kluczowe cechy

1. **Łatwość użycia**: Pygame Zero zostało zaprojektowane z myślą o prostocie. Jest doskonałym narzędziem dla początkujących programistów i osób uczących się programowania gier.

2. **Prosta instalacja**: Pygame Zero jest dostępne jako pakiet Pythona, co oznacza, że można go łatwo zainstalować za pomocą narzędzi do zarządzania pakietami Pythona, takich jak pip.

3. **Wsparcie dla wielu rodzajów gier**: Pygame Zero obsługuje wiele rodzajów gier, w tym gry 2D i gry zręcznościowe. Oferuje podstawowe narzędzia do obsługi grafiki, dźwięku i interakcji z użytkownikiem.

4. **Bezpośrednie mapowanie z Pygame**: Pygame Zero jest nakładką na Pygame, co oznacza, że jeśli użytkownik chce zrobić coś bardziej zaawansowanego, może łatwo przejść do korzystania z funkcji Pygame.

Pygame Zero jest doskonałym narzędziem do nauki programowania gier dla początkujących, a także dla nauczycieli, którzy chcą wprowadzić swoich uczniów w świat tworzenia gier. Jest łatwy w użyciu, a jednocześnie oferuje wystarczająco dużo możliwości, aby umożliwić tworzenie interesujących i zabawnych gier.

## Czego się nauczysz

* Instalacji bibliotek.
* Zasady działania podstawowego szablonu PygameZero.
* Podziału kodu na części/podprogramy (funkcje).

## Instalacja biblioteki

Na dole ekranu programu PyCharm szukamy zakładki **Terminal.** Otwieramy ją i w oknie, które się pojawi wpisujemy następujące polecenie:

`pip install pgzero`

Zatwierdzamy je przyciskiem _Enter_ i czekamy aż biblioteka się zainstaluje.

## Szablon

Na samym początku utworzymy bardzo prosty szablon. Będziemy z niego wielokrotnie korzystać przy tworzeniu naszych gier. Tak naprawdę, praktycznie zawsze będziemy od tego właśnie zaczynać.

Tworzymy nowy plik o nazwie `szablon.py`, który zaraz wypełnimy treścią.

### Importujemy bibliotekę

Na początku importujemy zainstalowaną bibliotekę, a dokładnie jej konkretny moduł: _pgzrun_.
Pozwoli on nam uruchamiać tworzone gry.

```python
import pgzrun
```

### Określamy wymiary okna gry

Na początek określamy wymiary okna naszej gry. Zacznijmy klasycznie od wymiarów $800\times600$.
W zależności od zapotrzebowania będziemy te wymiary dostosowywać do konkretnych gier.

Wymiary określamy podając szerokość (ang. *width*) i wysokość (ang. *height*) okna gry.
Ważne jest, żeby nazwy zmiennych były w tym wypadku napisane **drukowanymi literami**.

```python
WIDTH = 800
HEIGHT = 600
```

### Tworzymy część rysującą

Jedną z najważniejszych części każdej gry jest część rysująca, w której będziemy określać, co ma zostać wyświetlone na ekranie.
Dopiero zaczynamy i nie mamy jeszcze nic do narysowania, dlatego dodajemy polecenie _pass_, które określa, że mamy *spasować*, czyli nic nie robić.

```python
def draw():
    pass
```

### Tworzymy część aktualizującą

Drugą kluczową częścią każdej gry jest część aktualizująca (ang. *update*).
Podobnie jak wcześniej, nie mamy jeszcze nic do aktualizacji, więc tutaj także dodajemy _pass_.

```python
def update():
    pass
```

### Dodajemy polecenie uruchamiające grę

Na samym końcu naszego kodu dodajemy polecenie, które uruchomi naszą grę.
To polecenie powinno **zawsze** znajdować się **na końcu** kodu.

```python
pgzrun.go()
```

I to wszystko! Teraz możemy przejść do testowania.

### Pełen program z komentarzami

```python
# Korzystamy z biblioteki do tworzenia gier: PyGame Zero
import pgzrun

# Określamy szerokość i wysokość okna gry
WIDTH = 800
HEIGHT = 600


# Tutaj będziemy rysować wszystko na ekranie
def draw():
    pass


# Tutaj będziemy aktualizować stan gry: przyznawać punkty, poruszać postaciami itd.
def update():
    pass


# Uruchamiamy grę
pgzrun.go()
```

### Testujemy działanie

Teraz czas uruchomić naszą "grę". Postępujemy standardowo: prawy przycisk myszy w edytorze -> _Run 'szablon'_. Naszym oczom powinien ukazać się piękny, czarny ekran o wymiarach $800$ na $600$ pikseli. Świetnie!

Efekt może nie jest bardzo satysfakcjonujący, ale to oznacza, że biblioteka zainstalowana została poprawnie i możemy przejść do tworzenia naszych gier!

## Pętla gry

Gra działa w nieskończonej, ukrytej pętli. Przez cały czas, od uruchomienia aż do zakończenia gry wykonywane są dwie główne akcje: rysowanie i aktualizacja.
Nazywamy to **pętlą gry**. Co każdą klatkę animacji aktualizowane są pozycje graczy, ich interakcja z graczem i sobą nawzajem, życia przeciwników, punkty itp.
Ogólnie aktualizowany jest **stan gry**. Wszystkie te zmiany są także nanoszone na ekran, czyli rysowane w oknie gry.

## Dla zaawansowanych: plik .exe

Standardowo do uruchomienia naszych gier potrzebny będzie Python, wraz z zainstalowaną biblioteką pgzero.
Naturalnym jednak jest, że chcemy się pochwalić innym naszymi grami!
Nie wszystkim będzie jednak łatwo wytłumaczyć, jak zainstalować Pythona i uruchomić naszą grę.
Dlatego potrzebny nam jest plik **wykonywalny**: taki, który wystarczy uruchomić na innym komputerze i wszystko będzie działać, nawet bez Pythona!
Pytanie brzmi: jak taki plik utworzyć? 
Potrzebne będą nam dwie rzeczy: biblioteka **pyinstaller** oraz krótki skrypt.

### Instalacja biblioteki

Na dole ekranu programu PyCharm szukamy zakładki **Terminal.** Otwieramy ją i w oknie, które się pojawi wpisujemy następujące polecenie:

`pip install pyinstaller`

Zatwierdzamy je przyciskiem _Enter_ i czekamy aż biblioteka się zainstaluje.

### Skrypt

W katalogu głównym naszego projektu tworzymy nowy plik o nazwie **setup.bat** (prawy przycisk na główny katalog projektu, a następnie *New -> File*).
W pliku wpisujemy:

```
pyinstaller --collect-all pgzero main.py --distpath . --add-data "images;images" --add-data "fonts;fonts" --add-data "sounds;sounds" --add-data "music;music" --onefile --noconfirm --windowed --clean
```

!!! warning
	Skrypt należy dostosować do naszego projektu, a konkretnie do katalogów, jakich używamy. Powyższy skrypt będzie działał, jeżeli nasza gra używa:
	- grafik (`--add-data "images;images"`),
	- czcionek (`--add-data "fonts;fonts"`),
	- efektów dźwiękowych (`--add-data "sounds;sounds"`),
	- muzyki (`--add-data "music;music"`).
	
	Jeżeli nie mamy któregoś z katalogów w naszym projekcie, to ze skryptu należy usunąć odpowiednie polecenie. Np. jeżeli nasza gra korzysta **tylko** z grafik, to skrypt powinien wyglądać tak:
	```
	pyinstaller --collect-all pgzero main.py --distpath . --add-data "images;images" --onefile --noconfirm --windowed --clean
	```

### Tworzymy plik wykonywalny

W zakładce **Terminal** uruchamiamy plik __setup.bat__ wpisując `.\setup.bat` i zatwierdzając przyciskiem _Enter_.
Teraz wystarczy poczekać, aż operacje się zakończą. 
Po wszystkim zostanie utworzony w głównym katalogu naszej gry plik **main.exe**, który możemy uruchomić, a także przekazać znajomym, by i oni mogli zagrać w naszą grę!