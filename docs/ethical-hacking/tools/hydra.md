# Hydra

Hydra jest szybkim i skutecznym narzędziem do ataków typu brute force na wiele różnych protokołów i usług sieciowych. Jest szeroko stosowana w testach penetracyjnych i CTFach do łamania haseł i innych informacji uwierzytelniających.

Hydra przeprowadza ataki przeszukując przestrzeń możliwych haseł w celu znalezienia prawidłowego. Atak siłowy polega na systematycznym sprawdzaniu wszystkich możliwych kombinacji haseł, dopóki nie zostanie znalezione prawidłowe. Hydra potrafi równocześnie atakować wiele hostów i obsługuje wiele protokołów i usług, w tym, między innymi, Telnet, FTP, HTTP, HTTPS, SMB, SNMP, SMTP, POP3, IMAP, Oracle, MySQL i wiele innych.

[Hydra](https://www.kali.org/tools/hydra/)

## Przykłady użycia

### Atak na FTP

Poniższe polecenie wykonuje atak na serwer FTP, używając listy użytkowników *users.txt* i listy haseł *passwords.txt*:

```bash
hydra -L users.txt -P passwords.txt ftp://192.168.1.100
```

### Atak na SSH

Atak na serwer SSH z konkretnym użytkownikiem i listą haseł wygląda następująco:

```bash
hydra -l admin -P passwords.txt ssh://192.168.1.100
```

### Atak na formularz logowania na stronie internetowej

Hydra potrafi także atakować formularze logowania na stronach internetowych. Poniżej przykład ataku na formularz logowania metodą POST:

```bash
hydra -L users.txt -P passwords.txt 192.168.1.100 http-post-form "/login:username=^USER^&password=^PASS^:F=Invalid"
```

W tym przypadku `^USER^` i `^PASS^` to miejsca, w które Hydra wstawia nazwy użytkowników i hasła z list. `F=Invalid` oznacza, że Hydra szuka wyrazu *Invalid* w odpowiedziach HTTP, aby zidentyfikować nieudane próby logowania.
