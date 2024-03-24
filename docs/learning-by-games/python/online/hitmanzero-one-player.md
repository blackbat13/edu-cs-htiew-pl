# HitmanZero - jeden gracz

## Wstęp

Twój cel jest prosty: dostać się na drugą stronę. Po drodze jednak czekają na Ciebie wynajęci zabójcy, którzy wystrzeliwują w Twoim kierunku grad pocisków. Nie cofaj się, idź pewnie przed siebie!

![Gra HimanZero napisana w Pygame Zero](../../../.gitbook/assets/hitmanGame.gif)

Grafiki zostały pobrane ze strony [https://kenney.nl/](https://kenney.nl)

{% file src="../../../.gitbook/assets/hitman_grafiki.zip" %}
Grafiki do gry
{% endfile %}

## Serwer

TODO

### Pełen program

```python
import random
import socket
import time
from _thread import *

WIDTH = 800
HEIGHT = 1000
block_size = 50

def threaded_client(user1):  # Obsługa graczy i ich gry
    # Pobieramy nicki od rozmówców
    user1_name = user1.recv(2048).decode()

    # Następnie wysyłamy te nicki do rozmówców, zapoznając ich ze sobą
    user1.send(str.encode("server"))

    # Wysyłamy rozmówcom ich kolejność
    time.sleep(0.2)
    user1.send(str.encode("1"))

    hitmans_count = random.randint(5, 15)

    hitmans = [{"y": block_size / 2} for i in range(hitmans_count + 1)]

    time.sleep(0.2)
    user1.send(str.encode(str(hitmans_count + 1)))

    user1.setblocking(False)

    start = time.perf_counter()


    # Obsługujemy rozmowę przez cał czas
    while True:

        stop = time.perf_counter()
        if stop - start > 0.05:
            start = stop
            type = random.randint(0, hitmans_count)
            move = random.randint(-1, 1)

            new_y = hitmans[type]["y"]
            new_y += move * block_size
            if 0 < new_y < HEIGHT:
                hitmans[type]["y"] = new_y
                message = (type, move, random.randint(5, 20))
                user1.send(str.encode(str(message)))
            # print(message)


# Podajemy adres IP, na którym będzie działał serwer
server = "192.168.1.39"
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

    # Uruchamiamy wątek do obsługi komunikacji pomiędzy użytkownikami
    start_new_thread(threaded_client, (user1, ))
```

## Klient

TODO

### Pełen program

```python
import pgzrun
import socket
import ast

WIDTH = 800
HEIGHT = 1000

# Podajemy adres IP serwera
server = "127.0.0.1"
# A także port, na którym serwer nasłuchuje
port = 5555

# Tworzymy gniazdo do połączeń
connection = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
# Ustanawiamy połączenie z serwerem
connection.connect((server, port))

# Podajemy nick użytkownika
user_name = "blackbat"

# Wysyłamy nasz nick do serwera
connection.send(str.encode(user_name))

# Odbieramy nick drugiego rozmówcy od serwera
opponent_name = connection.recv(2048).decode()

# Odbieramy numer naszej kolejności od serwera
order = int(connection.recv(2048).decode())

hitmans_count = int(connection.recv(2048).decode())
print(hitmans_count)

# Ustawiamy gniazdo w trybie nieblokowania, tak żaby gra się nie zawieszała podczas czekania na wiadomość od serwera
connection.setblocking(False)

block_size = 50

man = Actor("man")
man.x = WIDTH / 2
man.y = HEIGHT - block_size / 2
man.angle = 90

hitmans = []
bullets = []


def generate_hitmans():
    for i in range(hitmans_count):
        hitman = Actor("hitman")
        if i % 2 == 0:
            hitman.x = block_size / 2
        else:
            hitman.x = WIDTH - block_size / 2
            hitman.angle = 180
        hitman.y = block_size / 2
        hitman.can_shoot = True
        hitmans.append(hitman)


def draw():
    screen.fill("black")
    man.draw()
    for hit in hitmans:
        hit.draw()

    for bul in bullets:
        bul.draw()


def update():
    try:
        type, move, speed = ast.literal_eval(connection.recv(2048).decode())

        if type == -1:
            man.y += block_size * move
            if man.y < 0:
                man.y = HEIGHT - block_size / 2
        else:
            if move == 0:
                bul = Actor("bullet")
                bul.x = hitmans[type].x
                bul.y = hitmans[type].y
                if type % 2 == 0:
                    bul.angle = -90
                    bul.vx = speed
                else:
                    bul.angle = 90
                    bul.vx = -speed
                bullets.append(bul)
            else:
                hitmans[type].y += move * block_size
    except:
        pass

    for bul in bullets[:]:
        bul.x += bul.vx

        if bul.colliderect(man):
            man.y = HEIGHT - block_size / 2

        if bul.x > WIDTH:
            bullets.remove(bul)


def on_key_down(key):
    if order == 1:
        if key == keys.UP:
            man.y -= block_size
            move = (-1, -1, 0)
            connection.send(str.encode(str(move)))
            if man.y < 0:
                man.y = HEIGHT - block_size / 2


generate_hitmans()
pgzrun.go()
```

