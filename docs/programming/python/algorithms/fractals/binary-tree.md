# Drzewo binarne

## Opis problemu

{% content-ref url="../../../../algorithms/fractals/binary-tree.md" %}
[binary-tree.md](../../../../algorithms/fractals/binary-tree.md)
{% endcontent-ref %}

## Implementacja

{% code overflow="wrap" lineNumbers="true" %}
```python
import turtle


def binary_tree(rank: int, length: float):
    turtle.forward(length)
    
    if rank > 0:
        turtle.left(45)
        binary_tree(rank - 1, length / 2)
        turtle.right(90)
        binary_tree(rank - 1, length / 2)
        turtle.left(45)
        
    turtle.back(length)


turtle.speed(0)
turtle.penup()
turtle.left(90)
turtle.back(350)
turtle.pendown()
turtle.pensize(3)

binary_tree(5, 400)

turtle.done()
```
{% endcode %}

### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/Binary-Tree#main.py" %}
Drzewo binarne
{% endembed %}

### Opis implementacji

Funkcja `binary_tree` (**linia 4**) przyjmuje dwa argumenty: stopień drzewa i początkową długość gałęzi (pnia). Na początku przemieszczamy żółwia do przodu o zadaną długość (**linia 5**), rysując w ten sposób gałąź. Następnie, jeżeli stopień jest większy od zera (**linia 7**), to znaczy, że musimy narysować kolejne gałęzie. W tym celu obracamy najpierw żółwia w lewo o $$45\degree$$ (**linia 8**) i wywołaniem rekurencyjnym (**linia 9**) rysujemy gałęzie. Podobnie postępujemy z drugim rozgałęzieniem. Najpierw musimy obrócić żółwia w prawo o $$90\degree$$ (**linia 10**), czyli $$2*45\degree$$. Następnie stosujemy wywołanie rekurencyjne (**linia 11**), a potem obracamy żółwia w lewo o $$45\degree$$ (**linia 12**), w ten sposób wracając do początkowego ustawienia.

Na koniec, po ewentualnym narysowaniu rozgałęzień, cofamy żółwia o zadaną długość (**linia 14**), tym samym wracając do ustawienia z początku wywołania funkcji.

W kodzie głównym ustawiamy żółwia tak, aby rysowane drzewo mieściło się na ekranie (**linie 17-22**). Następnie rysujemy drzewo binarne za pomocą naszej funkcji `binary_tree` (**linia 24**), a na koniec kończymy działanie żółwia (**linia 26**).