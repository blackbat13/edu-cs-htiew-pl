# Labirynt

W pliku *maze.txt* znajduje się opis labiryntu. Pierwsza linia zawiera dwie liczby naturalne oddzielone spacją, oznaczające szerokość i wysokość labiryntu. Kolejne linie opisują labirynt o podanych wymiarach. Każda cyfra opisuje jedno pole labiryntu. Pole o wartości zero oznacza ścianę. Pole o wartości jeden oznacza punkt wejścia, a pole o wartości dziewięć oznacza punkt wyjścia. Pozostałe pola, zawierające cyfry od 2 do 8, opisują korytarze. Jest tylko jedno pole wejścia i jedno pole wyjścia.

Labirynt jest zbudowany w taki sposób, że istnieje **dokładnie jedna** ścieżka prowadząca od wejścia do wyjścia (taka, że każde pole odwiedzamy co najwyżej raz).

[:material-note-text: maze.txt](../../../../assets/maze/maze.txt)

W pliku *maze_test.txt* znajduje się opis labiryntu jak podano wyżej.

[:material-note-text: maze_test.txt](../../../../assets/maze/maze_test.txt)

Napisz program/programy rozwiązujące poniższe zadania.

## Zadanie 1

Po labiryncie możemy poruszać się wykonując ruch o jedno pole w lewo, prawo, do góry lub na dół. Podaj ile **minimalnie** ruchów trzeba wykonać, aby przemieścić się z wejścia do wyjścia pod warunkiem, że nie możemy stawać na polach reprezentujących ściany. Dla danych z pliku *maze_test.txt* wynik to $16$.

## Zadanie 2

Po labiryncie możemy poruszać się wykonując ruch o jedno pole w lewo, prawo, do góry lub na dół. Każde pole ma określony koszt oznaczony liczbą reprezentującą to pole. Podaj jaki będzie **minimalny sumaryczny** koszt przemieszczenia się z pola wejściowego na pole wyjściowe pod warunkiem, że nie możemy stawać na polach reprezentujących ściany. Do kosztu nie wliczamy kosztu pola wejścia i pola wyjścia. Dla danych z pliku *maze_test.txt* wynik to $73$.

## Zadanie 3

Po labiryncie możemy poruszać się wykonując ruch o jedno pole w lewo, prawo, do góry lub na dół. Ile jest takich pól korytarza, które **nie znajdą się** na najkrótszej ścieżce prowadzącej z wejścia do wyjścia, pod warunkiem, że nie możemy stawać na polach reprezentujących ściany? Dla danych z pliku *maze_test.txt* wynik to $32$.

## Zadanie 4

Po labiryncie możemy poruszać się wykonując ruch o jedno pole w lewo, prawo, do góry lub na dół. Każde pole ma określony koszt oznaczony liczbą reprezentującą to pole. Podaj jaki będzie **maksymalny** sumaryczny koszt przemieszczenia się z pola wejściowego na pole wyjściowe pod warunkiem, że **możemy** stawać na polach reprezentujących ściany, a na każdym polu możemy stanąć co najwyżej raz. Do kosztu nie wliczamy kosztu pola wejścia i pola wyjścia. Dla danych z pliku *maze_test.txt* wynik to $241$.

## Zadanie 5

Po labiryncie możemy poruszać się wykonując ruch o jedno pole w prawo lub w dół. Każde pole ma określony koszt oznaczony liczbą reprezentującą to pole. Stosując algorytm **zachłanny** podaj jaki będzie **maksymalny** (możliwy do uzyskania algorytmem zachłannym) sumaryczny koszt przemieszczenia się z pola wejściowego na pole wyjściowe pod warunkiem, że **możemy** stawać na polach reprezentujących ściany, a na każdym polu możemy stanąć co najwyżej raz. Do kosztu nie wliczamy kosztu pola wejścia i pola wyjścia. Dla danych z pliku *maze_test.txt* wynik to $27$.

## Zadanie 6

Po labiryncie możemy poruszać się wykonując ruch o jedno pole w prawo lub w dół. Każde pole ma określony koszt oznaczony liczbą reprezentującą to pole. Podaj jaki będzie **maksymalny** sumaryczny koszt przemieszczenia się z pola wejściowego na pole wyjściowe pod warunkiem, że **możemy** stawać na polach reprezentujących ściany, a na każdym polu możemy stanąć co najwyżej raz. Do kosztu nie wliczamy kosztu pola wejścia i pola wyjścia. Dla danych z pliku *maze_test.txt* wynik to $79$.
