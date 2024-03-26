# TCP i UDP

Protokoły UPD i TCP są wykorzystywane do przesyłania danych - czyli pakietów informacji - przez Internet, korzystając z protokołu IP.

## TCP

**Transmission Control Protocol** jest protokołem połączeniowym. Gdy maszyna A wysyła dane do maszyny B, maszyna B jest informowana o nadchodzących danych, po czym przesyła potwierdzenie ich odbioru.

**Przykładowe zastosowania**: e-mail, przeglądanie sieci.

## UDP

**User Datagram Protocol** to protokół bezpołączeniowy. Mówiąc najprościej, gdy maszyna A wysyła pakiety do maszyny B, strumień jest niekierowany. Oznacza to, że transmisja danych odbywa się bez informowania odbiorcy (maszyny B), a odbiorca otrzymuje dane bez konieczności wysyłania potwierdzenia do nadawcy danych (maszyny A).

**Przykładowe zastosowania**: rozmowy wideo, strumieniowanie muzyki.

## TCP vs UDP

|            **TCP**            |             **UDP**            |
| :---------------------------: | :----------------------------: |
|          Połączeniowy         |         Bezpołączeniowy        |
|        Strumień bajtów        |       Strumień wiadomości      |
|            Unicast            |  Unicast, Multicast, Broadcast |
|  Kontrola przepływu i błędów  |          Brak kontroli         |
| Pakiet nazywany **segmentem** | Pakiet nazywany **datagramem** |

![Źródło: https://i.redd.it/duv11av99nm11.png](../../assets/tcp_udp_meme.png)

## Schematy przesyłania danych

Wiadomości w sieci mogą być przesyłane na wiele sposobów. Poniżej omówione są najważniejsze z nich.

### Unicast

Komunikacja typu jeden-do-jeden. Z jednego miejsca w sieci do innego, to znaczy jeden nadawca i jeden odbiorca. Można to porównać do prywatnej rozmowy dwóch osób.

![Public Domain, https://commons.wikimedia.org/w/index.php?curid=909335](../../assets/Unicast.svg)

### Multicast

Komunikacja grupowa typu jeden-do-wielu. Wiadomość jest wysyłana do grupy urządzeń w sieci jednocześnie. Można to przyrównać do rozmowy z grupą znajomych.

![Public Domain, https://commons.wikimedia.org/w/index.php?curid=909339](../../assets/Multicast.svg)

### Broadcast

Komunikacja typu jeden-do-wszystkich. Wiadomość wysyłana jest do wszystkich urządzeń w sieci. Można to porównać do wygłoszenia przemówienia na środku placu.

![Public Domain, https://commons.wikimedia.org/w/index.php?curid=909337](../../assets/Broadcast.svg)
