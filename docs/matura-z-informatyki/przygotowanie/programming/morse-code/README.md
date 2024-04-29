# Kod Morse'a

W pliku *morse_alphabet.txt* znajduje się alfabet kodu Morse'a: 36 linii, każda zawierająca znak (wielką literę alfabetu angielskiego lub cyfrę) oraz, po spacji, jego kodowanie w alfabecie kodu Morse'a, tzn. ciąg myślników i/lub kropek.

[:material-note-text: morse_alphabet.txt](../../../../assets/morse-code/morse_alphabet.txt)

W pliku *morse.txt* znajduje się 100 linii, każda zawierająca jeden wyraz zakodowany w alfabecie kodu Morse'a. Wiadomość może składać się z wielu znaków, a każdy kolejny kod znaku jest oddzielony znakiem spacji.

[:material-note-text: morse.txt](../../../../assets/morse-code/morse.txt)

W pliku *morse_test.txt* znajduje się 10 linii jak opisano powyżej.

[:material-note-text: morse_test.txt](../../../../assets/morse-code/morse_test.txt)

## Zadanie 1

Odkoduj wiadomości z pliku *morse.txt* i zapisz je do pliku *morse_decoded.txt* w postaci tekstu.

Odpowiedź dla pliku *morse_test.txt*:

```
DRAW
INSIDE
FORCE
PARTNER
CAMERA
ADD
MOM
LEVEL
MMO
OCCUR
```

## Zadanie 2

Palindrom to wyraz, który jest taki sam czytany od lewej do prawej i od prawej do lewej. Policz, ile palindromów jest zakodowanych w pliku *morse.txt*.

Odpowiedź dla pliku *morse_test.txt*: 2.

## Zadanie 3

Podaj długość najdłuższego i długość najkrótszego wyrazu z pliku *morse.txt*.

Odpowiedź dla pliku *morse_test.txt*:

- najdłuższy: 7
- najkrótszy: 3

## Zadanie 4

Anagramy to wyrazy, które składają się z dokładnie tych samych znaków, ale niekoniecznie w tej samej kolejności. Policz, ile jest **par** anagramów w pliku *morse.txt*.

Odpowiedź dla pliku *morse_test.txt*: 1.