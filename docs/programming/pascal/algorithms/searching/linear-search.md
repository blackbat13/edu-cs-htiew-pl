# Wyszukiwanie liniowe

## [:link: Opis problemu](../../../../algorithms/searching/linear-search.md)

## Istnienie elementu

### Implementacja

```pascal linenums="1"
program lsearch;
var
	n: integer = 10;
	arr: array [0..9] of integer = (8, 2, 9, 10, 5, 4, 2, 7, 18, 0);
	number: integer = 5;
	result: boolean;
function linear_search(n: integer; arr: array of integer; number: integer): boolean;
var
	i: integer;
	result: boolean;
begin
	result := false;
	for i := 0 to n - 1 do
	begin
		if (arr[i] = number) then
		begin
			result := true;
			break;
		end;
	end;
	linear_search := result;
end;
begin
	result := linear_search(n, arr, number);
	if (result) then
	begin
		writeln('Liczba jest w tablicy');
	end
	else
	begin
		writeln('Liczby nie ma w tablicy');
	end;
	
end.
```

### Opis implementacji

Funkcja `linear_search` (**linia 7**) zwraca jako wynik wartość prawda/fałsz i przyjmuje trzy argumenty: rozmiar tablicy, tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przyjmujemy jako potencjalny wynik wartość `false`, czyli informację, że nie znaleźliśmy elementu w tablicy (**linia 12**). Następnie przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy (**linia 13**). Dla każdego indeksu sprawdzamy, czy element zapisany pod tym indeksem jest równy poszukiwanej wartości (**linia 15**). Jeżeli tak, to zapamiętujemy informację o znalezieniu wartości w zmiennej `result` (**linia 17**) i wychodzimy z pętli za pomocą instrukcji `break` (**linia 18**). Na koniec zwracamy wynik, czyli wartość zmiennej `result` (**linia 21**).

W części głównej programu na początku przygotowujemy dane do problemu: rozmiar tablicy (**linia 3**), tablicę (**linia 4**) oraz wartość poszukiwanego elementu (**linia 5**). Następnie wywołujemy funkcję `linear_search` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w zmiennej `result` (**linia 24**). W zależności od wyniku (**linia 25**) wypisujemy odpowiedni komunikat (**linie 27 i 31**).

## Pozycja elementu

### Implementacja

```pascal linenums="1"
program lsearch;
var
	n: integer = 10;
	arr: array [0..9] of integer = (8, 2, 9, 10, 5, 4, 2, 7, 18, 0);
	number: integer = 5;
	result: integer;
function linear_search(n: integer; arr: array of integer; number: integer): integer;
var
	i: integer;
	result: integer;
begin
	result := -1;
	for i := 0 to n - 1 do
	begin
		if (arr[i] = number) then
		begin
			result := i;
			break;
		end;
	end;
	linear_search := result;
end;
begin
	result := linear_search(n, arr, number);
	if (result = -1) then
	begin
		writeln('Liczby nie ma w tablicy');
	end
	else
	begin
		write('Liczba jest pod indeksem ');
		writeln(result);
	end;
	
end.
```

### Opis implementacji

Funkcja `linear_search` (**linia 7**) zwraca jako wynik liczbę całkowitą i przyjmuje trzy argumenty: rozmiar tablicy, tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przyjmujemy jako potencjalny wynik wartość `-1`, czyli informację, że nie znaleźliśmy elementu w tablicy (**linia 12**). Następnie przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy (**linia 13**). Dla każdego indeksu sprawdzamy, czy element zapisany pod tym indeksem jest równy poszukiwanej wartości (**linia 15**). Jeżeli tak, to zapamiętujemy informację o znalezieniu wartości w zmiennej `result` (**linia 17**) i wychodzimy z pętli za pomocą instrukcji `break` (**linia 18**). Na koniec zwracamy wynik, czyli wartość zmiennej `result` (**linia 21**).

W części głównej programu na początku przygotowujemy dane do problemu: rozmiar tablicy (**linia 3**), tablicę (**linia 4**) oraz wartość poszukiwanego elementu (**linia 5**). Następnie wywołujemy funkcję `linear_search` z wcześniej przygotowanymi parametrami i jej wynik zapisujemy w zmiennej `result` (**linia 24**). W zależności od wyniku (**linia 25**) wypisujemy odpowiedni komunikat (**linie 27 i 31**).

## Wszystkie pozycje elementu

### Implementacja

```pascal linenums="1"
program lsearch;
var
	n: integer = 10;
	arr: array [0..9] of integer = (8, 2, 8, 4, 5, 6, 7, 8, 9, 8);
	number: integer = 8;
procedure linear_search(n: integer; arr: array of integer; number: integer);
var
	i: integer;
begin
	for i := 0 to n - 1 do
	begin
		if (arr[i] = number) then
		begin
			writeln(i);
		end;
	end;
end;
begin
	writeln('Indeksy, pod którymi znajduje się poszukiwana liczba:');
	linear_search(n, arr, number);
end.
```

### Opis implementacji

Procedura `linear_search` (**linia 6**) przyjmuje trzy argumenty: rozmiar tablicy, tablicę do przeszukania oraz wartość poszukiwanego elementu. Na początku funkcji przechodzimy pętlą przez wszystkie kolejne indeksy w tablicy (**linia 10**). Dla każdego indeksu sprawdzamy, czy element zapisany pod tym indeksem jest równy poszukiwanej wartości (**linia 12**). Jeżeli tak, to wypisujemy ten indeks (**linia 14**).

W części głównej programu na początku przygotowujemy dane do problemu: rozmiar tablicy (**linia 3**), tablicę (**linia 4**) oraz wartość poszukiwanego elementu (**linia 5**). Następnie wypisujemy stosowny komunikat (**linia 19**) i wywołujemy funkcję `linear_search` z wcześniej przygotowanymi parametrami (**linia 20**).