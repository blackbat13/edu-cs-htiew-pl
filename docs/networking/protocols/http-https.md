# HTTP i HTTPS

## HTTP (Hypertext Transfer Protocol)

HTTP, czyli protokół przesyłania hipertekstu, to zestaw reguł komunikacyjnych używanych do przesyłania informacji w sieciach komputerowych, zwłaszcza w Internecie. Jest protokołem nieszyfrowanym, co oznacza, że przesyłane informacje **mogą być odczytane**, jeśli zostaną przechwycone.

HTTP jest protokołem bezstanowym. Oznacza to, że nie zachowuje on żadnych informacji między żądaniami. Każde żądanie jest niezależne i nie ma świadomości poprzednich żądań. Protokół HTTP działa na podstawie modelu ***żądanie-odpowiedź***. Klient (zazwyczaj przeglądarka internetowa) wysyła żądanie do serwera, a serwer zwraca odpowiedź.

### Podstawowe typy zapytań HTTP

- **GET**: żądanie pobrania informacji.
- **POST**: przesłanie danych do serwera.
- **PUT**: aktualizacja danych na serwerze.
- **DELETE**: usunięcie danych na serwerze.

### Kody odpowiedzi HTTP

Kody odpowiedzi HTTP to trzycyfrowe numery wysyłane przez serwer jako odpowiedź na żądanie klienta. Pomagają w identyfikacji rezultatu żądania i wskazują, czy żądanie zakończyło się sukcesem, czy też nie.

Kody odpowiedzi HTTP są podzielone na pięć klas, zidentyfikowanych przez pierwszą cyfrę:

- 1xx (**Informatywne**): Rzadko używane. Informują, że żądanie zostało odebrane i proces kontynuowany.
- 2xx (**Sukces**): Oznaczają, że żądanie zostało pomyślnie otrzymane, zrozumiane i przyjęte.
  - **200 OK**: Standardowa odpowiedź na prawidłowe żądania.
  - **201 Created**: Żądanie zostało spełnione, a w wyniku tego utworzono nowy zasób.
  - **204 No Content**: Żądanie zostało pomyślnie przetworzone, ale nie ma dodatkowych informacji do wysłania.
- 3xx (**Przekierowanie**): Informują klienta, że musi podjąć dodatkową akcję, aby zakończyć żądanie.
  - **301 Moved Permanently**: Ta i wszystkie przyszłe prośby powinny być kierowane do podanego URI.
  - **302 Found**: Ta odpowiedź mówi, że żądane zasoby znajdują się tymczasowo pod innym URI.
- 4xx (**Błąd klienta**): Zwracane, gdy żądanie nie może być zakończone z powodu błędu po stronie klienta.
  - **400 Bad Request**: Serwer nie był w stanie zrozumieć żądania z powodu niepoprawnej składni.
  - **403 Forbidden**: Klient nie ma uprawnień do dostępu do żądanego zasobu.
  - **404 Not Found**: Serwer nie może odnaleźć żądanego zasobu.
- 5xx (**Błąd serwera**): Zwracane, gdy serwer napotkał problem, ale nie może go precyzyjnie zidentyfikować.
  - **500 Internal Server Error**: Niespecyficzny błąd serwera.
  - **502 Bad Gateway**: Serwer działa jako brama lub proxy i otrzymał niepoprawną odpowiedź od górnego serwera.
  - **503 Service Unavailable**: Serwer nie jest w stanie obsłużyć żądania z powodu przeciążenia lub konserwacji.

Powyższe kody to tylko niektóre z wielu kodów odpowiedzi HTTP. Każdy kod przekazuje ważne informacje o statusie żądania i pomaga identyfikować problemy, które mogą wystąpić podczas komunikacji między klientem a serwerem.

## HTTPS (Hypertext Transfer Protocol Secure)

HTTPS to rozszerzenie protokołu HTTP, które dodaje warstwę bezpieczeństwa do transmisji danych. HTTPS używa protokołu **SSL** (Secure Sockets Layer) lub **TLS** (Transport Layer Security) do szyfrowania komunikacji, co zapewnia bezpieczeństwo transmisji danych.

Głównym celem HTTPS jest zapewnienie prywatności i bezpieczeństwa w komunikacji sieciowej. Szyfrowanie danych zapobiega przechwyceniu i modyfikacji danych przez osoby trzecie. Dzięki temu protokołowi, informacje takie jak dane logowania, dane kart kredytowych czy inne poufne dane mogą być bezpiecznie przesyłane przez Internet. W związku z tym HTTPS jest szczególnie ważny na stronach internetowych, które obsługują transakcje finansowe, logowanie lub przetwarzanie innych wrażliwych danych.

W przeglądarkach internetowych, strony korzystające z protokołu HTTPS są zazwyczaj oznaczone ikoną kłódki obok adresu URL, co sygnalizuje użytkownikom, że ich połączenie jest bezpieczne.

{% hint style="warning" %}
Pamiętaj, że nawet jeśli strona korzysta z protokołu HTTPS, to nie oznacza, że jest ona całkowicie bezpieczna. Zawsze warto korzystać z najnowszych wersji przeglądarek internetowych, oprogramowania antywirusowego i **dwuskładnikowego uwierzytelniania**, aby zapewnić sobie najwyższy poziom ochrony.
{% endhint %}
