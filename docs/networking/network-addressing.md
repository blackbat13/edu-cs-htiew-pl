# Adresowanie sieciowe

Adresowanie sieciowe odnosi się do schematu przypisania adresów do urządzeń w sieci komputerowej. Jest to kluczowy element komunikacji w sieciach, umożliwiający identyfikację i lokalizację urządzeń.

## Podstawowe pojęcia

- **IP (Internet Protocol) Address**: unikalny adres numeryczny przypisany do każdego urządzenia w sieci.
- **Subnet**: podsegment sieci, który ma własny, odrębny zakres adresów.
- **Maska podsieci**: wskazuje, które części adresu IP odnoszą się do sieci, a które do hosta.

## Typy adresów IP

- **IPv4**: adres składający się z czterech bajtów (np. `192.168.0.1`). Jest to obecnie najczęściej używana wersja, ale zaczyna brakować dostępnych adresów.
- **IPv6**: nowsza wersja adresu IP składająca się z 128 bitów (np. `1200:0000:AB00:1234:0000:2552:7777:1313`). Wprowadzona w odpowiedzi na wyczerpywanie się adresów IPv4.

## Klasy adresów IPv4

- **Klasa A (`1.0.0.0` do `126.0.0.0`)**: wspiera 16 milionów hostów na każdej z 128 sieci.
- **Klasa B (`128.0.0.0` do `191.255.0.0`)**: wspiera 65 tysięcy hostów na każdej z 16 tysięcy sieci.
- **Klasa C (`192.0.0.0` do `223.255.255.0`)**: wspiera 254 hosty na każdej z 2 milionów sieci.

## Adresy specjalne

- **Adres sieci**: najniższy adres w sieci.
- **Adres broadcast**: najwyższy adres w sieci; wysyłanie do tego adresu oznacza wysłanie pakietu do wszystkich urządzeń w sieci.
- **Adresy prywatne**: adresy zarezerwowane dla prywatnych sieci, które nie są routowane w globalnym Internecie. Przykłady to `192.168.0.0/16`, `10.0.0.0/8` i `172.16.0.0/12`.

## Subnetting i VLSM (Variable Length Subnet Masking)

- **Subnetting**: proces dzielenia większej sieci na mniejsze podsieci.
- **VLSM**: technika pozwalająca na dzielenie sieci na podsieci o różnych rozmiarach.

## Protokoły adresowania

- **DHCP (Dynamic Host Configuration Protocol)**: protokół automatycznie przypisujący adresy IP urządzeniom w sieci.
- **ARP (Address Resolution Protocol)**: umożliwia znalezienie adresu MAC na podstawie adresu IP.

## Routowanie

- **Router**: urządzenie, które łączy sieci i przekierowuje pakiety między nimi na podstawie adresów IP.
- **Tabela routingu**: lista w routerze pokazująca, jak kierować pakiety w oparciu o ich adresy docelowe.

## Prezentacja

Krótka prezentacja na temat adresowania w sieci.

{% file src="../.gitbook/assets/Adresy sieciowe.pdf" %}
Adresy sieciowe
{% endfile %}
