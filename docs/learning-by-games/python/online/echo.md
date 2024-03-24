# Echo

## Wstęp

Serwer, czy też usługa ECHO to jedna z najprostszych usług. Działa tak, jak nazwa wskazuje: na każdą wysłaną wiadomość/komunikat, odpowiada dokładnie tym samym. Jest to świetna usługa do testowania klientów sieciowych, a także do nauki podstaw architektury klient-serwer.

### Czego się nauczysz

* Podstaw komunikacji sieciowej
* Wysyłania i odbierania wiadomości przez gniazda
* Podstaw działania architektury klient-serwer
* Obsługi wielu klientów za pomocą wątków

## Klient

W celu komunikowania się przez sieć będziemy korzystać z tzw. gniazd (ang. _socket_). Do tego przyda nam się biblioteka `socket`, którą musimy zaimportować:

```python
import socket
```

Zanim połączymy się z serwerem musimy wiedzieć, pod jakim **adresem IP** będzie się on znajdował (**nasłuchiwał**). 

**Informacja**: adres IP urządzenia to adres sieciowy, za pomocą którego możemy się połączyć z danym urządzeniem przez sieć. To trochę tak, jak przy zamawianiu przesyłki musimy podać adres, pod który musi zostać dostarczona.

Jako że będziemy testować klienta i serwer na jednym urządzeniu, to skorzystamy z tzw. **lokalnego adresu IP** (ang. `localhost`).

**Informacja**:** **adres lokalny wskazuje to urządzenie, na którym jest używany.

```python
server_ip = "127.0.0.1"
```

Nie wystarczy nam jednak znać adres IP serwera, potrzebujemy także poznać numer **portu**, pod którym będzie działał (nasłuchiwał) serwer. 

{% hint style="info" %}
Na jednym urządzeniu może działać wiele usług sieciowych, każda jednak musi działać na osobnym **porcie**. To trochę tak, jak w jednym budynku może znajdować się wiele mieszkań, ale każde pod innym numerem (inaczej przesyłki nie trafiałyby tam, gdzie trzeba!).
{% endhint %}

{% hint style="warning" %}
Na własne usługi powinniśmy wybierać wysokie numery portów (tysiące, a nawet dziesiątki tysięcy), ponieważ część początkowych numerów jest zarezerwowana na różne usługi systemowe.
{% endhint %}

```python
port = 5555
```

Mając już potrzebne informacje możemy utworzyć nowe gniazdo do naszego połączenia.

```python
connection = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
```

Teraz nawiązujemy połączenie z serwerem, podając jego adres IP i port, pod którym nasłuchuje.

```python
connection.connect((server_ip, port))
```

Po wykonaniu powyższego polecenia powinniśmy być już połączeni z serwerem (jeżeli wszystko poszło zgodnie z planem). Oczywiście, zanim będziemy mogli to przetestować, będziemy musieli jeszcze napisać i uruchomić serwer. 

Po nawiązaniu połączenia warto wypisać stosowny komunikat.

```python
print("Połączono z serwerem")
```

Teraz przechodzimy do głównej części naszego klienta. Będziemy wczytywać wiadomość od użytkownika, wysyłać ją do serwera, odbierać wiadomość od serwera i wyświetlać ją na ekranie. I tak w kółko, w nieskończoność, aż nie wyłączymy programu.

{% hint style="warning" %}
Nie będziemy tutaj zajmować się poprawnym kończeniem komunikacji z serwerem, niemniej należy o tym pamiętać pisząc własne, bardziej zaawansowane programy.
{% endhint %}

Zaczynamy od pętli:

```python
while True:
```

Na początku wczytujemy wiadomość od użytkownika:

```python
    message = input("Wiadomość: ")
```

Następnie wysyłamy ją do serwera. W tym celu musimy ją odpowiednio _zakodować_, by można ją było przesłać przez sieć. Używamy do tego polecenia `str.encode`:

```python
    message_enc = str.encode(message)
```

Taką wiadomość możemy wysłać do serwera:

```python
    connection.send(message_enc)
```

Jak coś wysłaliśmy, to teraz odbieramy to, co do nas przesłano:

```python
    message = connection.recv(2048).decode()
```

I wyświetlamy odebraną wiadomość na ekranie:

```python
    print(message)
```

Pełna pętla:

```python
while True:
    message = input("Wiadomość: ")
    
    message_enc = str.encode(message)
    
    connection.send(message_enc)
    
    message = connection.recv(2048).decode()
    
    print(message)
```

### Pełen program z komentarzami

```python
import socket

# Podajemy adres IP serwera
server_ip = "127.0.0.1"

# A także port, na którym serwer nasłuchuje
port = 5555

# Tworzymy gniazdo do połączeń
connection = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Ustanawiamy połączenie z serwerem
connection.connect((server_ip, port))

print("Połączono z serwerem")

# W nieskończonej pętli
while True:
    # Wczytujemy wiadomość od użytkownika
    message = input("Wiadomość: ")
    
    # Przygotowujemy wiadomość do wysłania przez sieć
    message_enc = str.encode(message)
    
    # A następnie wysyłamy wiadomość do serwera
    connection.send(message_enc)
    
    # Odbieramy wiadomość od serwera
    message = connection.recv(2048).decode()
    
    # Wyświetlamy ją na ekranie
    print(message)
```

## Serwer obsługujący jednego klienta

Podobnie jak w przypadku klienta, będziemy korzystać z **gniazd **do komunikacji przez sieć. Importujemy więc stosowną bibliotekę.

```python
import socket
```

Na początku podajemy adres IP i numer portu, pod którym będzie nasłuchiwał nasz serwer. Ponieważ zarówno klient i serwer będą działać na tym samym urządzeniu, należy podać takie same dane.

```python
server_ip = "127.0.0.1"
port = 5555
```

Teraz tworzymy gniazdo do połączeń:

```python
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
```

Łączymy (ang. bind) je z podanym adresem IP i portem:

```python
s.bind((server_ip, port))
```

I zaczynamy nasłuchiwać na połączenia:

```python
s.listen(2)
```

Po rozpoczęciu nasłuchiwania warto wypisać stosowny komunikat, żebyśmy wiedzieli, że wszystko działa tak jak trzeba:

```python
print("Uruchomiono serwer")
```

Gdy już odbierzemy połączenie, należy je zaakceptować:

```python
user, addr = s.accept()
print("Połączono z:", addr)
```

Gdy już ustanowiliśmy połączenie z klientem, możemy zacząć go obsługiwać. Zadanie serwera jest proste: odebrać wiadomość od klienta i odesłać ją z powrotem w niezmienionej formie. I tak w kółko.

Zaczynamy od pętli:

```python
while True:
```

Odbieramy wiadomość od klienta:

```python
    message = user.recv(2048)
```

I odsyłamy ją z powrotem:

```python
    user.send(message)
```

Pełna pętla:

```python
while True:
    message = user.recv(2048)
    user.send(message)
```

### Pełen program z komentarzami

```python
import socket


# Podajemy adres IP, na którym będzie działał serwer
server_ip = "127.0.0.1"

# A także port, na którym będzie nasłuchiwał na połączenia
port = 5555

# Tworzymy gniazdo
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Lączymy gniazdo ze wskazanym adresem IP i portem
s.bind((server_ip, port))

# Nasłuchujemy na połączenia
s.listen(2)

print("Uruchomiono serwer")

user, addr = s.accept()
print("Połączono z:", addr)

# Obsługujemy klienta przez cały czas
while True:
    # Pobieramy wiadomość od klienta
    message = user.recv(2048)
    
    # I wysyłamy ją z powrotem 
    user.send(message)
```

## Testujemy działanie

TODO - filmik

## Serwer obsługujący wielu klientów

TODO

### Pełen program z komentarzami

```python
import socket
from _thread import *


def threaded_client(user):
    # Obsługujemy klienta przez cały czas
    while True:
        # Pobieramy wiadomość od klienta
        message = user.recv(2048).decode()
        
        # I wysyłamy ją z powrotem 
        user.send(str.encode(message))


# Podajemy adres IP, na którym będzie działał serwer
server = "127.0.0.1"
# A także port, na którym będzie nasłuchiwał na połączenia
port = 5555

# Tworzymy gniazdo
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Lączymy gniazdo ze wskazanym adresem IP i portem
s.bind((server, port))

# Nasłuchujemy na połączenia
s.listen(2)

print("Starting server...")
# Serwer działa cały czas
while True:
    # Czekamy na połączenie
    user, addr = s.accept()
    print("Connected to:", addr)

    # Uruchamiamy wątek do obsługi komunikacji pomiędzy użytkownikami
    start_new_thread(threaded_client, (user))
```

## Testujemy działanie

TODO - filmik
