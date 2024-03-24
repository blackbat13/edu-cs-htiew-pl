# Aircrack-ng

Aircrack-ng to kompletne narzędzie do oceny bezpieczeństwa sieci Wi-Fi. Zawiera różne programy do przechwytywania pakietów, monitorowania ruchu sieciowego, ataków typu brute-force na klucze sieci Wi-Fi oraz testowania bezpieczeństwa sieci bezprzewodowych.

{% hint style="warning" %}
Używanie Aircrack-ng, podobnie jak każdego innego narzędzia do testowania penetracji, wymaga uprzedniego uzyskania zgody od właściciela sieci. Bez odpowiednich uprawnień, korzystanie z Aircrack-ng jest nielegalne.
{% endhint %}

{% embed url="https://www.aircrack-ng.org" %}
Aircrack-ng
{% endembed %}

## Podstawowe funkcje i zastosowania

Poniżej przedstawimy kilka różnych funkcji i zastosowań Aircrack-ng.

### Przechwytywanie pakietów

Aby przechwycić pakiety w sieci bezprzewodowej można użyć programu *airmon-ng* do przełączenia karty sieciowej w tryb monitorowania, a następnie *airodump-ng* do przechwytywania pakietów:

```bash
airmon-ng start wlan0
airodump-ng wlan0mon
```

### Atak typu brute-force na hasło sieci Wi-Fi

Gdy pakiety są już przechwytywane, można użyć *aircrack-ng* do ataku typu brute-force na hasło sieci Wi-Fi. Poniżej przykład ataku na sieć z WPA PSK:

```bash
aircrack-ng -w wordlist.txt -b 00:11:22:33:44:55 capture.cap
```

Gdzie:

- `wordlist.txt` to plik z listą haseł do wypróbowania,
- `00:11:22:33:44:55` to adres MAC punktu dostępowego,
- `capture.cap` to plik z przechwyconymi pakietami.

### Atak deautentykacji

Atak deautentykacji, czyli odłączanie użytkowników od sieci, może być przeprowadzony za pomocą *aireplay-ng*:

```bash
aireplay-ng --deauth 100 -a 00:11:22:33:44:55 wlan0mon
```

Gdzie $$100$$ to liczba pakietów deautentykacji do wysłania, a `00:11:22:33:44:55` to adres MAC punktu dostępowego.
