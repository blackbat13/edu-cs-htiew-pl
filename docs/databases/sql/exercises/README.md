# Ćwiczenia

Przed przystąpieniem do rozwiązywania zadań zapoznaj się z poniższym opisem.

Poświęć czas na rozwiązanie każdego zadania. Zastanów się nad różnymi sposobami podejścia i rozwiązania problemu.

Zadania podzielone są ze względu na tematy. Tematy ułożone są w sugerowanej kolejności poznawania zagadnień. Każdy temat zawiera od kilku do kilkunastu zadań. Po rozwinięciu tematu pojawią się przykładowe rozwiązania poszczególnych zadań, każde na osobnej stronie. Pamiętaj, że każde zadanie można rozwiązać na kilka sposobów. 

{% hint style="danger" %}
**Zajrzyj do przykładowego rozwiązania dopiero, jak samodzielnie wykonasz zadanie.**
{% endhint %}

## Przygotowanie

W ramach ćwiczeń będziemy pracować z plikową bazą danych **SQLite**. Zanim przystąpisz do ćwiczeń przygotuj sobie środowisko pracy i zapoznaj się z bazą danych, na której będziesz pracować.

### Narzędzie

Narzędzie, z którym będziemy pracować to poniższa aplikacja webowa: 

{% embed url="https://sqliteonline.com/" %}
SQLite Online
{% endembed %}

{% hint style="info" %}
Możesz oczywiście skorzystać z innego narzędzia, pod warunkiem, że wiesz jak je samodzielnie skonfigurować.
{% endhint %}

### Baza danych

Do ćwiczeń wykorzystamy bazę danych *Chinook*. Jest to przykładowa baza danych, jaką mógłby posiadać sklep online sprzedający utwory muzyczne. 

W celu załadowania bazy *Chinook* w narzędziu *SQLite Online* wystarczy w okienku po lewej stronie (z napisem *syntax*) znaleźć linijkę "Example: Chinook | NorthWind | cnf.db | BasketBall | Sakila" i kliknąć na nazwę **Chinook**. Wówczas baza danych będzie już załadowana, po lewej zobaczymy spis tabel, a po środku będziemy mogli pisać i wykonywać zapytania.

Bazę *Chinook* można także pobrać z poniższego linku:

{% embed url="https://github.com/lerocha/chinook-database/raw/master/ChinookDatabase/DataSources/Chinook_Sqlite.sqlite" %}
Baza Chinook
{% endembed %}

Pobrany plik należy rozpakować. Jeżeli chcemy załadować bazę do naszego narzędzia online to wybieramy z menu **File->Open DB** i wybieramy wypakowany plik *chinook.sqlite*.

### Struktura bazy danych

Baza składa się z 11 tabel:

- **Employee** - tabela przechowująca informacje o pracownikach, takie jak:
  - id pracownika (*EmployeeId*), 
  - nazwisko (*LastName*), 
  - imię (*FirstName*),
  - itp.
- **Customer** - tabela przechowująca informacje o klientach.
- **Invoice** oraz **InvoiceLine**: dwie tabele przechowujące informacje o fakturach. Pierwsza przechowuje nagłówki faktur, a druga zakupione utwory.
- **Artist** - tabela przechowująca informacje o zespołach. Zawiera jedynie nazwę zespołu oraz jego identyfikator.
- **Album** - tabela przechowująca informacje o albumach, czyli listach utworów. Każdy album należy do jednego artysty, ale jeden artysta może mieć wiele albumów.
- **MediaType** - tabela przechowująca informacje o typach plików audio, takie jak MPEG czy AAC.
- **Genre** - tabele przechowująca informacje o gatunkach, np. rock, jazz, metal.
- **Track** - tabela przechowująca informacje o utworach. Każdy utwór należy do jednego albumu.
- **Playlist** oraz **PlaylistTrack** - tabele przechowujące informacje o playlistach. Każda playlista zawiera listę utworów, a każdy utwór może należeć do kilku playlist. Relacja pomiędzy tabelami *playlists* oraz tracks to relacja typu **wiele-do-wielu**, która zrealizowana jest za pomocą tabeli *playlist_track*.

Struktura bazy przedstawiona jest na poniższej grafice:

```mermaid
erDiagram
  Album ||--o{ Artist : ""
  Customer ||--o{ Employee : ""
  Employee }o--o{ Employee : ""
  Invoice ||--o{ Customer : ""
  InvoiceLine ||--o{ Invoice : ""
  Playlist }o--o{ PlaylistTrack : ""
  PlaylistTrack }o--o{ Track : ""
  Track ||--o{ Album : ""
  Track ||--o{ Genre : ""
  Track ||--o{ MediaType : ""
  InvoiceLine ||--o{ Track : ""
  Album {
    INTEGER AlbumId
    TEXT Title
    INTEGER ArtistId
  }
  Artist {
    INTEGER ArtistId
    TEXT Name
  }
  Customer {
    INTEGER CustomerId
    TEXT FirstName
    TEXT LastName
    TEXT Company
    TEXT Address
    TEXT City
    TEXT Country
    TEXT PostalCode
    TEXT Phone
    TEXT Fax
    TEXT Email
    INTEGER SupportRepId
  }
  Employee {
    INTEGER EmployeeId
    TEXT LastName
    TEXT FirstName
    TEXT Title
    INTEGER ReportsTo
    NUMERIC BirthDate
    NUMERIC HireDate
    TEXT Address
    TEXT City
    TEXT State
    TEXT Country
    TEXT PostalCode
    TEXT Phone
    TEXT Fax
    TEXT Email
  }
  Genre {
    INTEGER GenreId
    TEXT Name
  }
  Invoice {
    INTEGER InvoiceId
    TEXT CustomerId
    NUMERIC InvoiceDate
    TEXT BillingAddress
    TEXT BillingCity
    TEXT BillingState
    TEXT BillingCountry
    TEXT BillingPostalCode
    REAL Total
  }
  InvoiceLine {
    INTEGER InvoiceLineId
    INTEGER InvoiceId
    INTEGER TrackId
    REAL UnitPrice
    INTEGER Quantity
  }
  MediaType {
    INTEGER MediaTypeId
    TEXT Name
  }
  Playlist {
    INTEGER PlaylistId
    TEXT Name
  }
  PlaylistTrack {
    INTEGER PlaylistId
    INTEGER TrackId
  }
  Track {
    INTEGER TrackId
    TEXT Name
    INTEGER AlbumId
    INTEGER MediaTypeId
    INTEGER GenreId
    TEXT Composer
    INTEGER Milliseconds
    INTEGER Bytes
    REAL UnitPrice
  }
```