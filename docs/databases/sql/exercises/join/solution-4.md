# Zadanie 4 - rozwiązanie

```SQL
SELECT Track.Name, Playlist.Name FROM Track JOIN PlaylistTrack USING(TrackId) JOIN Playlist USING(PlaylistId);
```
