# Wstęp

Programowanie to sztuka. Programista jest niczym artysta, który bierze puste płótno a zostawia na nim arcydzieło.

Zanim zaczniemy przygodę z programowaniem, przyjrzyjmy się dostępnym "narzędziom", tzn. **językom programowania**. Oczywiście nie omówimy wszystkich, nie miałoby to większego sensu. Skupimy się na pewnych _klasykach_.

Poszczególne języki porównamy ze sobą, przyglądając się implementacji prostego programu: **symulatora rzutu monetą**. Nie będziemy tutaj skupiać się na dokładnym omówieniu implementacji i poszczególnych instrukcji. Celem jest spojrzenie na różne języki z _lotu ptaka_.

Idea działania programu jest prosta. Na początku losujemy liczbę całkowitą: **0** lub **1**, ma to symulować nasz rzut monetą. Następnie, w zależności od wylosowanej wartości, wypisujemy stosowny komunikat na ekran. Jeżeli wylosowaliśmy **0**, to znaczy, że wypadł **Orzeł**. W przeciwnym przypadku (tzn., gdy wylosowaliśmy **1**) wypadła **Reszka**.

Zachęcamy do przetestowania poniższych programów. Pod każdą implementacją znajduje się link do tejże implementacji na serwisie _Ideone_. Tam można uruchomić dany program, co najlepiej zrobić kilkukrotnie by zobaczyć, jakie wartości (**Orzeł** czy **Reszka**) będą drukowane na ekranie.

## Python 3

```python
import random

moneta = random.randint(0, 1)

if moneta == 0:
    print("Orzel")
else:
    print("Reszka")
```

{% embed url="https://ideone.com/uMTxg9" %}
Symulator rzutu monetą - Python
{% endembed %}

## C++

```cpp
#include <iostream>
#include <ctime>
#include <random>
using namespace std;

int main() {
    srand(time(NULL));
    
    int moneta;
    moneta = rand() % 2;
    
    if(moneta == 0) {
        cout << "Orzel" << endl;
    } else {
        cout << "Reszka" << endl;
    }
    
    return 0;
}
```

{% embed url="https://ideone.com/ewTF4L" %}
Symulator rzutu monetą - C++
{% endembed %}

## Java

```java
import java.util.*;
import java.lang.*;
import java.io.*;

class Main {
    public static void main (String[] args) throws java.lang.Exception {
        Random rd = new Random();

        int moneta = rd.nextInt(2);
    
        if(moneta == 0) {
            System.out.println("Orzel");
        } else {
                System.out.println("Reszka");
        }
    }
}
```

{% embed url="https://ideone.com/gLqkST" %}
Symulator rzutu monetą - Java
{% endembed %}

## Pascal

```pascal
program rzut;
	var moneta : integer;
begin
	randomize();
	
	moneta := random(2);
	
	if moneta = 0 then write('Orzel')
	else write ('Reszka')
end.
```

{% embed url="https://ideone.com/w7bHvU" %}
Symulator rzutu monetą - Pascal
{% endembed %}

## Blockly

![Symulator rzutu monetą](<../.gitbook/assets/image (8).png>)

{% embed url="https://blockly-demo.appspot.com/static/demos/code/index.html?lang=pl#gsq3of" %}
Symulator rzutu monetą - Blockly
{% endembed %}
