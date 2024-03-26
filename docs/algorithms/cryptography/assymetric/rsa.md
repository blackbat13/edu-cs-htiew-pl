# RSA

RSA, nazwane od nazwisk twórców (**Rivest**, **Shamir** i **Adleman**), jest jednym z pierwszych praktycznych algorytmów kryptografii asymetrycznej i jest szeroko stosowany w wielu systemach zabezpieczeń do dziś. Algorytm ten pozwala na szyfrowanie danych oraz generowanie podpisów cyfrowych.

## Algorytm

1. **Generowanie kluczy**:
   - Wybierz dwie różne liczby pierwsze $p$ i $q$.
   - Oblicz $n = p \times q$ - będzie to **moduł** dla kluczy publicznego i prywatnego.
   - Oblicz funkcję Eulera $\phi(n) = (p-1) \times (q-1)$.
   - Wybierz liczbę $e$ taką, że $1 < e < \phi(n)$ i $\text{NWD}(e, \phi(n)) = 1$. Liczba $e$ jest kluczem publicznym.
   - Oblicz $d$ jako odwrotność $e$ modulo $\phi(n)$. Liczba $d$ jest kluczem prywatnym.
   
2. **Szyfrowanie**:
   - Dla wiadomości $M$, gdzie $0 \leq M < n$, zaszyfrowana wiadomość $C$ jest dana jako $C = M^e \mod n$.
   
3. **Deszyfrowanie**:
   - Aby uzyskać pierwotną wiadomość $M$ z zaszyfrowanej wiadomości $C$, oblicz $M = C^d \mod n$.

## Bezpieczeństwo

Bezpieczeństwo RSA opiera się na trudności faktoryzacji dużych liczb całkowitych. Dla dostatecznie dużych liczb $n$ i przy braku znajomości $p$ i $q$, trudno jest obliczyć $\phi(n)$ i z tego powodu trudno jest obliczyć klucz prywatny $d$ znając tylko klucz publiczny $e$.

## Podpisy cyfrowe

RSA może być również używane do generowania podpisów cyfrowych.
   - **Generowanie podpisu**: aby podpisać wiadomość $M$, osoba posiadająca klucz prywatny $d$ oblicza $S = M^d \mod n$, gdzie $S$ jest podpisem.
   - **Weryfikacja podpisu**: każdy, kto ma klucz publiczny $e$, może zweryfikować podpis obliczając $M = S^e \mod n$ i porównując go z pierwotną wiadomością.

## Wnioski

Algorytm RSA był rewolucją w dziedzinie kryptografii i odgrywa kluczową rolę w wielu aspektach bezpieczeństwa cyfrowego. Jest używany w protokołach takich jak SSL/TLS, co umożliwia bezpieczną komunikację w Internecie. Chociaż istnieją bardziej zaawansowane metody kryptografii (np. kryptografia krzywych eliptycznych), RSA wciąż pozostaje jednym z najważniejszych i najczęściej stosowanych algorytmów w dziedzinie kryptografii. Jednak ważne jest stosowanie odpowiednio długich kluczy (np. 2048-bitowych lub dłuższych) w celu zapewnienia odpowiedniego poziomu bezpieczeństwa.
