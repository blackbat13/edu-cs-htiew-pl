# DHCP (Dynamic Host Configuration Protocol)

DHCP to protokół sieciowy używany w sieciach IP, który umożliwia automatyczną konfigurację parametrów sieciowych dla urządzeń klienta. Został zaprojektowany, aby ułatwić zarządzanie i konfigurację urządzeń w sieci, eliminując potrzebę ręcznego przypisywania adresów IP.

Protokół DHCP działa w modelu klient-serwer. Serwer przechowuje pulę dostępnych adresów IP i informacje konfiguracyjne dla klientów. Kiedy urządzenie (klient DHCP) dołącza do sieci, wysyła żądanie do serwera DHCP o przyznanie adresu IP i innych informacji konfiguracyjnych. Serwer odpowiada na to żądanie przypisując urządzeniu unikalny adres IP i dostarczając mu niezbędne informacje konfiguracyjne.

Informacje konfiguracyjne dostarczane przez serwer DHCP mogą obejmować:

- Adres IP.
- Maskę podsieci.
- Adres domyślnej bramy.
- Adresy serwerów DNS.
- Adresy serwerów WINS (Windows Internet Name Service).
- Czas dzierżawy adresu IP.

Czas dzierżawy określa, jak długo urządzenie klienta może korzystać z przypisanego mu adresu IP. Po upływie tego czasu urządzenie musi odnowić swoją dzierżawę lub otrzymać nowy adres IP.

DHCP jest niezbędny w dużych sieciach, gdzie ręczne zarządzanie adresami IP byłoby bardzo czasochłonne i podatne na błędy. Ułatwia zarządzanie adresami IP, automatyzuje proces konfiguracji urządzeń sieciowych, a także pomaga w zapobieganiu **konfliktom adresów IP**.

## Konflikt adresów IP

Konflikt adresów IP występuje, gdy dwa lub więcej urządzeń w tej samej sieci jest skonfigurowanych z tym samym adresem IP. Takie zdarzenie jest problematyczne, ponieważ adresy IP muszą być **unikalne dla każdego urządzenia w sieci**, aby umożliwić prawidłową komunikację.

Gdy do konfliktu dojdzie, może to spowodować różnego rodzaju problemy z komunikacją sieciową. Może zdarzyć się, że urządzenia z tym samym adresem IP nie będą w stanie nawiązać prawidłowego połączenia sieciowego, co prowadzi do błędów i awarii w komunikacji. W najgorszym przypadku wszystkie urządzenia z tym samym adresem IP mogą być niedostępne dla reszty sieci.

Konflikty adresów IP mogą wynikać z różnych sytuacji, takich jak:

- Ręczne przypisanie tego samego adresu IP różnym urządzeniom przez administratora sieci.
- Błąd w konfiguracji serwera DHCP, który przydziela ten sam adres IP różnym klientom.
- Urządzenie, które jest skonfigurowane na stały adres IP, dołącza do sieci, w której serwer DHCP przydzielił już ten adres innemu urządzeniu.
- Urządzenie zaczyna korzystać z adresu IP, który był wcześniej przydzielony innemu urządzeniu, ale nie został prawidłowo zwolniony.

Protokół DHCP jest zaprojektowany tak, aby minimalizować ryzyko konfliktów adresów IP poprzez dynamiczne zarządzanie pulą dostępnych adresów IP i przydzielanie ich urządzeniom na zasadzie dzierżawy.
