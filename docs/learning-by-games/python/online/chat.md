# Pochatujmy!

## Wstęp

Komunikacja przez sieć to bardzo ciekawe zagadnienie. Możemy rozmawiać z osobami, które znajdują się po drugiej stronie globu, i to w czasie rzeczywistym! Jeszcze kilkadziesiąt lat temu było to nie do wyobrażenia.

Istnieje wiele aplikacji pozwalających komunikować się przez sieć, a dzisiaj napiszemy własną. Nie będzie to gra, ale ten przykład posłuży nam do poznania pewnych bardzo ważnych pojęć, które będą nam niezbędne do stworzenia gry przez sieć.

### Czego się nauczysz

* "Turowej" komunikacji przez sieć.
* Łączenia klientów w pary.

## Serwer

TODO

### Pełen program z komentarzami

```python
import socket
from _thread import *


def threaded_client(user1, user2):
    # Pobieramy nicki od rozmówców
    user1_name = user1.recv(2048).decode()
    user2_name = user2.recv(2048).decode()

    # Następnie wysyłamy te nicki do rozmówców, zapoznając ich ze sobą
    user1.send(str.encode(user2_name))
    user2.send(str.encode(user1_name))

    # Wysyłamy rozmówcom ich kolejność
    user1.send(str.encode("1"))
    user2.send(str.encode("2"))

    # Obsługujemy rozmowę przez cał czas
    while True:
        # Pobieramy wiadomość od pierwszego rozmówcy
        message = user1.recv(2048).decode()
        # I wysyłamy ją do drugiego
        user2.send(str.encode(message))

        # Następnie pobieramy wiadomość od drugiego rozmówcy
        message = user2.recv(2048).decode()
        # I wysyłamy ją do pierwszego
        user1.send(str.encode(message))

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
    # Czekamy na połączenie od pierwszego rozmówcy
    user1, addr1 = s.accept()
    print("Connected to:", addr1)

    # Czekamy na połączenie od drugiego rozmówcy
    user2, addr2 = s.accept()
    print("Connected to:", addr2)

    # Uruchamiamy wątek do obsługi komunikacji pomiędzy użytkownikami
    start_new_thread(threaded_client, (user1, user2))
```

## Klient

TODO

### Pełen program z komentarzami

```python
import socket

# Podajemy adres IP serwera
server = "127.0.0.1"
# A także port, na którym serwer nasłuchuje
port = 5555

# Tworzymy gniazdo do połączeń
connection = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

# Wczytujemy nick użytkownika
user_name = input("Podaj swój nick: ")
print("Wyszukiwanie rozmówcy...")

# Ustanawiamy połączenie z serwerem
connection.connect((server, port))

# Wysyłamy nasz nick do serwera
connection.send(str.encode(user_name))

# Odbieramy nick drugiego rozmówcy od serwera
user2_name = connection.recv(2048).decode()

# Odbieramy numer naszej kolejności od serwera
order = int(connection.recv(2048).decode())

print("Połączono z użytkownikiem", user2_name)

if order == 1:
    print("Przywitaj się!")
else:
    print("Poczekaj na wiadomość")

# W nieskończonej pętli
while True:
    # Sprawdzamy, czy jest nasza kolej
    if order == 1:
        # Jeżeli jest nasza kolej, to wczytujemy wiadomość od użytkownika
        message = input("Wiadomość: ")
        # A następnie wysyłamy wiadomość do serwera
        connection.send(str.encode(message))
        # I teraz jest kolej naszego rozmówcy
        order = 2
    else:
        # Jeżeli to nasz rozmówca ma teraz swoją kolej
        # To odbieramy wiadomość od serwera
        message = connection.recv(2048).decode()
        # Wyświetlamy ją na ekranie
        print(user2_name, ":", message)
        # I przechodzimy do naszej "tury"
        order = 1
```

## Testujemy działanie

TODO - filmik
