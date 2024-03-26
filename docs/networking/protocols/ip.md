---
description: Internet Protocol
---

# Protokół IP

Protokół komunikacyjny warstwy sieciowej modelu OSI. Określa format i sposób przesyłania danych przez sieć.

## Nagłówek IPv4

Początkowe dane (bajty) każdego pakietu IPv4 to nagłówek:

![Nagłówek pakietu IPv4](../../assets/IPv4header.png)



* **Wersja** – w tym polu nagłówka znajduje się wersja protokołu IP, w przypadku IPv4 znajduje się tam cyfra 4.
* **Długość nagłówka (IHL)** – długość nagłówka pakietu IP wyrażona w postaci liczby czterobajtowych części.
* **Typ usługi** – określa priorytet pakietu.
* **Długość całkowita** – pole zawiera całkowitą długość pakietu (nagłówek + dane), maksymalna długość pakietu to 65535 bajtów.
* **Numer identyfikacyjny** – pole zawiera unikatowy identyfikator dla każdego pakietu wykorzystywany do połączenia pakietów w strumień danych.
* **Flagi** – określa między innymi czy pakiet może być fragmentowany.
* **Kontrola przesunięcia** – umożliwia złożenie pakietu w całość pakietu, określają miejsce danego fragmentu w całym pakiecie.
* **Czas życia pakietu (TTL – Time To Live)** – ilość przeskoków przez które może pakiet przejść zanim zostanie odrzucony (urządzenia przez które przechodzi dany pakiet zmniejszają tą wartość o 1).
* **Protokół warstwy wyższej**– to pole zawiera informacje jaki protokół warstwy transportowej został wykorzystany (TCP, UDP, ICMP lub inne).
* **Suma kontrolna nagłówka** – gdy odbiorca dostanie pakiet, sprawdza jego poprawność obliczając sumę kontrolną i porównując ją z sumą kontrolną zapisaną w nagłówku.
* **Adres źródłowy i adres docelowy** – zawierają adresy IP urządzeń które przesyłają między sobą dane zapisane w formacie binarnym.
