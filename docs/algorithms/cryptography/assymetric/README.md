# Szyfrowanie asymetryczne

Kryptografia asymetryczna, nazywana także kryptografią z kluczem publicznym, jest metodą szyfrowania, która używa dwóch kluczy: jednego publicznego do szyfrowania informacji i jednego prywatnego do jej deszyfrowania. Ze względu na tę dwukluczową naturę, kryptografia asymetryczna ma wiele zastosowań, takich jak podpisy cyfrowe czy wymiana kluczy.

## Podstawowe zasady

1. **Dwa klucze**: istnieją dwa klucze – publiczny i prywatny. Klucz publiczny jest udostępniany otwarcie, podczas gdy klucz prywatny jest trzymany w tajemnicy przez jego właściciela.
2. **Bezpieczeństwo**: nawet jeśli atakujący ma dostęp do klucza publicznego i szyfrogramu, nie powinien być w stanie odszyfrować wiadomości bez klucza prywatnego.
3. **Nieodwracalność**: wiadomość zaszyfrowaną kluczem publicznym można odszyfrować tylko odpowiednim kluczem prywatnym, i odwrotnie.

## Zastosowania

1. **Szyfrowanie**: dowolna osoba może zaszyfrować wiadomość przy użyciu klucza publicznego odbiorcy. Tylko odbiorca, posiadający odpowiedni klucz prywatny, może odszyfrować wiadomość.
2. **Podpisy cyfrowe**: za pomocą swojego klucza prywatnego nadawca może stworzyć podpis cyfrowy, który może być weryfikowany przez każdego, kto ma dostęp do sparowanego klucza publicznego.
3. **Wymiana kluczy**: protokoły takie jak *Diffie-Hellman* umożliwiają dwóm stronom wygenerowanie wspólnego tajnego klucza na podstawie ich par kluczy publicznych/prywatnych, bez konieczności bezpośredniego przekazywania informacji.

## Popularne algorytmy

1. **RSA**: jeden z pierwszych i najczęściej stosowanych algorytmów kryptografii asymetrycznej. Stosowany zarówno do szyfrowania, jak i podpisów cyfrowych.
2. **Diffie-Hellman**: używany głównie do wymiany kluczy.
3. **Elliptic Curve Cryptography (ECC)**: oferuje podobny poziom bezpieczeństwa jak RSA, ale przy znacznie krótszych kluczach.

## Bezpieczeństwo

1. **Długość Klucza**: bezpieczeństwo kryptografii asymetrycznej jest często uzależnione od długości klucza. Dłuższe klucze są zazwyczaj bardziej bezpieczne, ale wymagają więcej zasobów do przetwarzania.
2. **Ataki**: kryptografia asymetryczna nie jest odporna na wszystkie ataki. Istnieją metody atakowania kryptosystemów, takie jak ataki przez faktoryzację dla RSA.
3. **Prywatność klucza**: bezpieczne przechowywanie klucza prywatnego jest kluczowe. Jeśli klucz prywatny zostanie skompromitowany, bezpieczeństwo wszystkich operacji przeprowadzanych przy jego użyciu jest narażone.

## Wnioski

Kryptografia asymetryczna przyniosła rewolucję w dziedzinie bezpieczeństwa cyfrowego, umożliwiając bezpieczną wymianę informacji w otwartych sieciach, takich jak Internet. Jest podstawą wielu aspektów współczesnego bezpieczeństwa cyfrowego, w tym certyfikatów SSL/TLS, podpisów cyfrowych i wielu systemów uwierzytelniania. O ile, gdy prawidłowo zaimplementowana i stosowana, oferuje wysoki poziom bezpieczeństwa, to jak każda technologia wymaga świadomości jej ograniczeń i potencjalnych zagrożeń.

## Prezentacja

Poniżej znajduje się krótka prezentacja pokazująca istotę kryptografii asymetrycznej.

{% file src="../../../.gitbook/assets/Szyfrowanie asymetryczne.pdf" %}
Prezentacja
{% endfile %}
