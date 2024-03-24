# Zadanie 3 - rozwiązanie

```SQL
SELECT Playlist.Name, Count(Track.TrackId) AS TracksCount FROM Playlist JOIN PlaylistTrack USING(PlaylistId) JOIN Track USING(TrackId) GROUP BY Playlist.PlaylistId ORDER BY TracksCount DESC;
```
