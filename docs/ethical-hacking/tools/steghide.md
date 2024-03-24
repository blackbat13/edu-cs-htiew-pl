# Steghide

Steghide to narzędzie do steganografii, które umożliwia ukrywanie danych w różnego rodzaju plikach multimedialnych, takich jak obrazy i pliki audio. Narzędzie to jest dostępne na platformach Linux i Windows. Steghide wspiera wiele formatów plików, w tym JPEG, BMP, WAV i AU. Dane są ukrywane w taki sposób, że nie wpływają na jakość pliku multimedialnego, co czyni je trudnymi do wykrycia bez odpowiednich narzędzi. Dodatkowo, Steghide obsługuje silne szyfrowanie i hashowanie, co zabezpiecza ukryte dane przed nieautoryzowanym dostępem.

{% embed url="https://steghide.sourceforge.net" %}
Steghide
{% endembed %}

## Przykłady użycia

### Ukrywanie pliku w obrazie

Aby ukryć plik *secret.txt* w obrazie *image.jpg*, można użyć poniższego polecenia:

```bash
steghide embed -cf image.jpg -ef secret.txt
```

Steghide poprosi o hasło, które będzie potrzebne do wyodrębnienia pliku w przyszłości.

### Wyodrębnianie ukrytego pliku

Aby wyodrębnić ukryty plik z obrazu, można użyć poniższego polecenia:

```bash
steghide extract -sf image.jpg
```

Steghide poprosi o hasło, które zostało użyte podczas ukrywania pliku. Po wprowadzeniu prawidłowego hasła, ukryty plik zostanie wyodrębniony.
