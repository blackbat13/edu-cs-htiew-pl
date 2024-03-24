# Zadanie 5 - rozwiązanie

```SQL
SELECT DISTINCT Artist.Name, Genre.Name FROM Artist JOIN Album USING(ArtistId) JOIN Track USING(AlbumId) JOIN Genre USING(GenreId);
```
