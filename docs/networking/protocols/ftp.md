# FTP (File Transfer Protocol)

FTP, czyli **Protokół Przesyłania Plików**, to standardowy protokół komunikacyjny wykorzystywany do przesyłania plików pomiędzy komputerami w sieci internetowej. Jest często wykorzystywany do przesyłania plików na serwery internetowe oraz do udostępniania plików do pobrania przez użytkowników Internetu.

FTP działa na podstawie modelu **klient-serwer**. Klient łączy się z serwerem, a następnie wysyła żądania o przesłanie plików lub pobranie plików z serwera. Serwer odbiera te żądania i wykonuje odpowiednie akcje.

Podstawowe operacje, które można wykonać za pomocą protokołu FTP, to:

- Przesyłanie plików na serwer (upload).
- Pobieranie plików z serwera (download).
- Przeglądanie zawartości katalogów na serwerze.
- Tworzenie i usuwanie katalogów na serwerze.
- Kasowanie plików na serwerze.

FTP posiada dwa tryby pracy: **aktywny** i **pasywny**. W trybie aktywnym to serwer FTP inicjuje połączenie z klientem FTP na porcie danych. W trybie pasywnym to klient FTP inicjuje połączenie z serwerem na porcie danych. Tryb pasywny jest częściej wykorzystywany, ponieważ lepiej współpracuje z zaporami ogniowymi i routerami.

!!! warning
	 Standardowy protokół FTP **nie jest bezpieczny**. Komunikacja odbywa się bez szyfrowania, co oznacza, że nazwy użytkowników, hasła, komendy i przesyłane pliki mogą być przechwycone i odczytane. Dlatego też zaleca się stosowanie **FTPS** (FTP Secure), który dodaje warstwę szyfrowania SSL/TLS do połączenia, lub **SFTP** (SSH File Transfer Protocol), który wykorzystuje bezpieczny protokół SSH do przesyłania plików.
