# Model OSI

Model OSI (Open Systems Interconnection) to koncepcyjny model, który opisuje, jak różne protokoły sieciowe współpracują, aby umożliwić komunikację między urządzeniami sieciowymi. Model składa się z siedmiu warstw. Każda warstwa modelu OSI komunikuje się tylko z warstwą bezpośrednio poniżej lub powyżej. Wszystkie warstwy łącznie zapewniają pełne funkcje sieciowe.

## 1. Warstwa fizyczna (Physical Layer)

Na najniższym poziomie mamy warstwę fizyczną, która jest odpowiedzialna za przesyłanie surowych bitów danych przez medium sieciowe. Usługi i protokoły związane z tą warstwą obejmują Ethernet, USB, Bluetooth, 802.11 (Wi-Fi) i inne.

## 2. Warstwa łącza danych (Data Link Layer)

Warstwa łącza danych zajmuje się ramkowaniem danych, wykrywaniem i naprawą błędów, które mogą wystąpić na warstwie fizycznej. Znane protokoły tej warstwy to Ethernet i PPP (Point-to-Point Protocol).

## 3. Warstwa sieci (Network Layer)

Warstwa sieci jest odpowiedzialna za dostarczenie pakietów danych od punktu A do punktu B. To tutaj działają adresowanie IP i routery. IP (Internet Protocol) to kluczowy protokół tej warstwy.

## 4. Warstwa transportu (Transport Layer)

Warstwa transportu ma na celu zapewnienie bezpiecznego przesyłania danych pomiędzy systemami. Odpowiada za kontrolę przepływu, wielokrotne łączenie, wykrywanie błędów i naprawę. Kluczowe protokoły to TCP (Transmission Control Protocol) i UDP (User Datagram Protocol).

## 5. Warstwa sesji (Session Layer)

Warstwa sesji zarządza sesjami między komputerami. Jest odpowiedzialna za nawiązywanie, zarządzanie i kończenie połączeń między lokalnymi i zdalnymi aplikacjami.

## 6. Warstwa prezentacji (Presentation Layer)

Warstwa prezentacji jest odpowiedzialna za formowanie danych dla aplikacji. Obejmuje to takie zadania, jak kodowanie i dekodowanie, kompresję danych i szyfrowanie.

## 7. Warstwa aplikacji (Application Layer)

Na najwyższym poziomie, warstwa aplikacji jest warstwą, z którą najczęściej mają do czynienia użytkownicy końcowi. To tutaj działają protokoły takie jak HTTP (do przeglądania stron internetowych), SMTP (do wysyłania poczty e-mail), FTP (do przesyłania plików), DNS (do mapowania nazw domen na adresy IP) i wiele innych.

## Kapsułkowanie danych według modelu odniesienia OSI

![Autorstwa ToAr - Praca własna, CC BY-SA 4.0, https://commons.wikimedia.org/w/index.php?curid=4223068](../assets/Kapsułkowanie_danych_wg_modelu_odniesienia_OSI.svg)