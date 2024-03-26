# Wyróżnienie elementu

Opracowano na podstawie: [http://boitblog.blogspot.com/2013/12/reveal-color-of-selected-object-in-image.html](http://boitblog.blogspot.com/2013/12/reveal-color-of-selected-object-in-image.html)

## Wstęp

W dzisiejszym świecie, gdzie jesteśmy zasypywani obrazami z każdej strony, wyjątkowo ważne jest, aby nasze zdjęcia mogły się wyróżnić. Dlatego stosowanie pewnych technik i efektów może okazać się niezwykle przydatne, szczególnie jeśli chodzi o tworzenie efektywnych reklam produktów. Jednym z takich efektów jest technika zwana "selective color" lub "color splash", polegająca na zamianie zdjęcia na czarno-białe, podczas gdy wybrany element zostaje w oryginalnym, kolorowym wydaniu.

Ta technika polega na konwersji większości zdjęcia na czarno-białe, pozostawiając tylko jedną lub kilka części obrazu w kolorze. Może to być konkretny obiekt, osoba, czy choćby fragment tła. W ten sposób kolorowy element staje się centralnym punktem uwagi, przyciągając oko widza i podkreślając szczególną ważność tego elementu.

Efekt ten działa szczególnie dobrze, gdy wybrany element na zdjęciu ma żywe i jaskrawe kolory. Dzięki kontrastowi z resztą obrazu, wyróżniony element zyskuje na intensywności i dynamice, czyniąc całe zdjęcie znacznie bardziej intrygującym.

To, co sprawia, że efekt ten jest tak efektywny, to jego zdolność do skupienia uwagi widza na konkretnej części obrazu. W reklamie produktu możemy na przykład użyć tej techniki, aby skierować uwagę widza na produkt, który chcemy sprzedać, pozostawiając wszystko inne na zdjęciu w odcieniach szarości. Dzięki temu nasz produkt stanie się centralnym punktem całego obrazu, przyciągając uwagę i zapadając w pamięć widza. To pozwala nie tylko na efektywną prezentację produktu, ale także na stworzenie mocnego i pamiętnego obrazu marki.

W tutorialu skorzystamy z następującego zdjęcia:

![Źródło: https://cc0.photo/2021/10/06/apple-impaled-on-a-fence-crown/](https://cc0.photo/download/5049/)

## Tworzymy wersję czarno-białą

Najpierw stworzymy wersję naszego zdjęcia w odcieniach szarości.

### 1. Duplikujemy warstwę

Wybieramy menu **Warstwa->Powiel warstwę** lub używamy skrótu **Shift+Ctrl+D**.
Klikamy prawym przyciskiem myszy na nowej warstwie i wybieramy **Modyfikuj atrybuty warstwy...**.
Zmieniamy nazwę naszej warstwy na *Szara* i zatwierdzamy.

### 2. Desaturacja

Zaznaczamy warstwę *Szara* i wybieramy menu **Kolory->Desaturacja->Desaturacja...**.
Jako tryb wybieramy **Jasność (HSL)** i zatwierdzamy.

### 3. Poprawiamy jasność i kontrast

Dostosowujemy jasność i kontrast czarno-białego zdjęcia tak, by wyglądało na bardziej *wyprane* i *wyblakłe*.
W tym celu wybieramy menu **Kolory->Jasność i kontrast...**.
Zwiększamy jasność, np. do $50$ i zmniejszamy kontrast, np. do $-15$.

## Wyróżniamy element

Mamy już czarno-białe zdjęcie. Teraz pora uwidocznić oryginalny kolor wybranego elementu.
Elementem, który wyróżnimy, będzie jabłko.

### Zaznaczamy element

Korzystając z narzędzi zaznaczania, np. **Odręczne zaznaczanie obszarów**, zaznaczamy element zdjęcia, który chcemy wyróżnić.
Im dokładniej to zrobimy, tym lepszy efekt uzyskamy.

!!! info
	 Dla ułatwienia pracy możemy tymczasowo ukryć warstwę *Szara* klikając przy niej ikonkę oka.

### Zmiękczamy zaznaczenie

Gdy już jesteśmy zadowoleni z naszego zaznaczenia, warto je delikatnie zmiękczyć.
W tym celu wybieramy menu **Zaznaczenie->Zmiękcz...** i ustawiamy np. $2 px$.

### Dodajemy kanał alfa

Zanim będziemy mogli wyciąć nasze zaznaczenie i tym samym zrobić *dziurę* w warstwie, musimy najpierw dodać kanał alfa do naszej warstwy.
Zaznaczamy warstwę *Szara* i wybieramy **Warstwa->Przezroczystość->Dodaj kanał alfa**.

### Wycinamy zaznaczenie

Teraz przyszła pora na użycie hipotetycznych nożyczek.
Wybieramy menu **Edycja->Wyczyść** albo używamy przycisku **Delete**.
Następnie czyścimy zaznaczenie (menu **Zaznaczenie->Brak** lub skrót **Shift+Ctrl+A**).

### Poprawiamy kolory

Na koniec warto jeszcze bardziej podkreślić wyróżniony element.
W tym celu wybieramy menu **Kolory->Barwa i nasycenie...** i zmniejszamy jasność, np. na $-15$.

## Efekt końcowy

![](../../../assets/color_reveal.png)

