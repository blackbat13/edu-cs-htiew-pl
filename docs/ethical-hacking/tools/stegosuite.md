# Stegosuite

Stegosuite to otwartoźródłowe narzędzie do steganografii napisane w Javie, które umożliwia ukrywanie informacji w różnych typach plików obrazów, takich jak GIF, JPG, BMP i PNG. Interfejs graficzny Stegosuite'u czyni go przyjaznym dla użytkownika i łatwym w obsłudze.

Stegosuite ukrywa informacje w plikach obrazów poprzez subtelne modyfikacje pikseli, które nie są zauważalne dla ludzkiego oka. Dzięki temu osoba przeglądająca obraz nie jest w stanie zauważyć ukrytych informacji bez użycia odpowiednich narzędzi steganograficznych. Stegosuite obsługuje także szyfrowanie ukrytych danych, zwiększając poziom ich bezpieczeństwa.

{% embed url="https://github.com/osde8info/stegosuite" %}
Stegosuite
{% endembed %}

## Przykłady użycia

Ponieważ Stegosuite korzysta z graficznego interfejsu użytkownika, jego obsługa jest dość prosta i intuicyjna.

### Ukrywanie informacji w obrazie

1. Wybierz **File -> Open** w menu, a następnie wybierz obraz, w którym chcesz ukryć informacje.
2. Wpisz informacje, które chcesz ukryć, w polu **Message**. Możesz także załadować plik z wiadomością klikając **File -> Load**.
3. Kliknij **Embed** i wprowadź hasło, jeśli chcesz zaszyfrować ukryte informacje. Wybierz miejsce, w którym chcesz zapisać zmodyfikowany obraz.

### Wyodrębnianie ukrytych informacji z obrazu

1. Wybierz **File -> Open**w menu, a następnie wybierz obraz z ukrytymi informacjami.
2. Kliknij **Extract** i wprowadź hasło, jeżeli informacje zostały zaszyfrowane. Ukryte informacje pojawią się w polu **Message**.
