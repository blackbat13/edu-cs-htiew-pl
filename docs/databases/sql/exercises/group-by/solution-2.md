# Zadanie 2 - rozwiązanie

```SQL
SELECT Artist.Name, SUM(Milliseconds)/(1000) AS Seconds, SUM(Milliseconds)/(1000*60) AS Minutes, SUM(Milliseconds)/(1000*60*60) AS Hours FROM Album JOIN Track USING(AlbumId) JOIN Artist USING(ArtistId) GROUP BY Artist.ArtistId ORDER BY Artist.Name ASC;
```
