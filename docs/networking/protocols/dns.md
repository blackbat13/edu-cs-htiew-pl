# DNS (Domain Name System)

DNS to jeden z najważniejszych protokołów w Internecie, który umożliwia przekładanie nazw domenowych na adresy IP. Bez DNS użytkownicy musieliby pamiętać numeryczne adresy IP stron internetowych, zamiast łatwiej zapadających w pamięć nazw domenowych.

DNS działa na zasadzie hierarchicznej struktury. Na samym szczycie tej hierarchii są tzw. serwery główne (ang. root servers), które znają lokalizacje wszystkich serwerów obsługujących poszczególne domeny najwyższego poziomu (takie jak .com, .org, .pl, itp.).

Gdy użytkownik wprowadza adres URL w przeglądarce internetowej, zapytanie to jest najpierw przekierowywane do serwera DNS skonfigurowanego dla sieci tego użytkownika (często jest to serwer DNS dostawcy usług internetowych). Jeśli ten serwer DNS nie ma informacji o adresie IP dla tej domeny, przekazuje zapytanie do wyższego serwera DNS. Proces ten kontynuuje się aż do serwera głównego, który zna serwery obsługujące domenę najwyższego poziomu, i tak dalej, aż osiągnięty zostanie serwer obsługujący konkretną domenę.

Podczas tego procesu każdy serwer DNS, który otrzymuje odpowiedź, zapisuje ją na pewien czas (tzw. **TTL** - Time to Live), dzięki czemu w przyszłości może odpowiadać na zapytania dotyczące tej samej domeny bez potrzeby ponownego odpytywania całego łańcucha serwerów DNS.

DNS jest niezwykle istotnym elementem Internetu, ponieważ bez niego nawigowanie po sieci byłoby znacznie bardziej skomplikowane i mniej intuicyjne. Ponadto, DNS zapewnia wiele innych usług, takich jak przekierowywanie poczty e-mail do odpowiednich serwerów lub obsługa poddomen.
