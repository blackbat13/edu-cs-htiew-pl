# Zmienne

## Wstęp

Jak i w innych językach, zmienne w języku Python mają swoje typy danych. Przy tworzeniu zmiennej nie podajemy jednak jej typu, jest on wnioskowany z kontekstu, czyli z przypisanej wartości. Co więcej nie tworzymy tutaj osobno deklaracji i definicji zmiennej. Można powiedzieć, że zmienne tworzymy wtedy, kiedy ich potrzebujemy i kiedy wiemy, jaką wartość do nich przypisać.

W języku Python należy odróżnić pomiędzy etykietą zmiennej, a rzeczywistą zmienną zapisaną w pamięci komputera. To co widzimy w kodzie to tak naprawdę **etykiety** zmiennych. Gdy definiujemy nową etykietę i przypisujemy do niej wartość, w pamięci tworzona jest nowa zmienna o typie określonym na podstawie podanej wartości. Jeżeli w którymś momencie do tej samej etykiety przypiszemy wartość innego typu, to **ponownie** zostanie utworzona nowa zmienna, a stara zostanie usunięta (albo też "oznaczona do usunięcia" przez garbage collector). Dlatego, chociaż w Pythonie nie deklarujemy typów zmiennych w sposób jawny, to typy jak najbardziej istnieją i **należy o nich pamiętać**. 

### Sugestie typów

Chociaż, jak już wspomniałem, w języku Python nie określamy jawnie typów tworzonych zmiennych, to możemy je "zasugerować". Oznacza to, że po dwukropku, po nazwie zmiennej podajemy jej oczekiwany typ. Nie wpłynie to jednak na działanie programu, a będzie jedynie sugestią dla programisty, czy też dla środowiska programistycznego. W określonych przypadkach jest to dobra praktyka, która pozwoli pisać bardziej przejrzysty kod i szybciej wyłapywać błędy związane z typowaniem.

## Podstawowe typy zmiennych

Poniższy fragment kodu pokazuje podstawowe typy zmiennych, wraz z ich przykładowymi wartościami, z jakimi mamy do czynienia w języku Python.

```python
liczba_calkowita: int = 0
liczba_rzeczywista: float = 0.25
liczba_zespolona: complex = 1j
tekst: str = "Hello"
bajty: bytes = b"Hello"
prawda_falsz: bool = True
typ_none: NoneType = None
```

## Złożone typy zmiennych

Poniżej znajduje się kilka wybranych złożonych typów/struktur danych z języka Python.

```python
lista: list = ["kot", "pies"]
krotka: tuple = ("kot", "pies")
slownik: dict = {"typ": "kot", "wiek": 2}
zbior: set = {"kot", "pies"}
zakres: range = range(10)
tablica_bajtow: bytearray = bytearray(10)
widok_pamieci: memoryview = memoryview(bytes(10))
```

## Sprawdzenie typu zmiennej

W celu sprawdzenia, jaki typ ma dana zmienna, możemy skorzystać z funkcji *type*.

### Przykład

```python
value = 10
print(type(value))
```
