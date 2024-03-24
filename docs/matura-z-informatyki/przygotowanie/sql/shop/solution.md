# Rozwiązanie

## Zadanie 1

```sql
SELECT * 
    FROM Zamowienia 
    WHERE YEAR(data_zam) = 2015 AND MONTH(data_zam) = 5;
```

## Zadanie 2

```sql
SELECT imie 
    FROM Klienci 
    WHERE imie LIKE '%a';
```

## Zadanie 3

```sql
SELECT Klienci.id_kl, imie, nazwisko 
    FROM Klienci 
        JOIN Zamowienia USING(id_kl) 
    WHERE DAY(data_zam) = 18 AND MONTH(data_zam) = 3 AND YEAR(data_zam) = 2016 
    GROUP BY Klienci.id_kl;
```

## Zadanie 4

```sql
SELECT Klienci.id_kl, imie, nazwisko, SUM(liczba_sztuk * cena) 
    FROM Klienci 
        JOIN Zamowienia USING(id_kl) 
        JOIN Artykuly USING(id_art) 
    GROUP BY Klienci.id_kl 
    ORDER BY nazwisko;
```

## Zadanie 5

```sql
SELECT Klienci.id_kl, imie, nazwisko 
    FROM Klienci 
        JOIN Zamowienia USING(id_kl) 
    WHERE YEAR(data_zam) < 2010 
    GROUP BY Klienci.id_kl;
```

## Zadanie 6

```sql
SELECT Artykuly.id_art, nazwa, COUNT(id_zam) 
    FROM Zamowienia 
        RIGHT JOIN Artykuly USING(id_art) 
    GROUP BY Artykuly.id_art;
```

## Zadanie 7

```sql
SELECT miasto, Artykuly.id_art, SUM(liczba_sztuk) 
    FROM Zamowienia 
        JOIN Klienci USING(id_kl) 
        JOIN Artykuly USING(id_art) 
    GROUP BY miasto, id_art
    HAVING SUM(liczba_sztuk) > 100;
```

## Zadanie 8

```sql
SELECT Artykuly.id_art, nazwa, SUM(liczba_sztuk) 
    FROM Zamowienia 
        RIGHT JOIN Artykuly USING(id_art) 
    GROUP BY id_art;
```

## Zadanie 9

```sql
SELECT id_art, nazwa 
    FROM Artykuly 
    WHERE id_art NOT IN (SELECT id_art FROM Zamowienia);
```

## Zadanie 10

```sql
SELECT Klienci.id_kl, imie, nazwisko 
    FROM Klienci 
        JOIN Zamowienia USING(id_kl) 
        JOIN Artykuly USING(id_art) 
    WHERE id_art IN (10, 20) 
    GROUP BY Klienci.id_kl 
    HAVING COUNT(id_zam) = 2;
```
