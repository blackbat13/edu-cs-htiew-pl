# Protokoły komunikacji e-mail

## SMTP (Simple Mail Transfer Protocol)

SMTP, czyli Protokół Prostej Transmisji Poczty, jest standardem internetowym do transmisji wiadomości e-mail. Został zaprojektowany do wysyłania wiadomości z serwera pocztowego do serwera pocztowego. Jest wykorzystywany do komunikacji między serwerami, ale może być również wykorzystany do komunikacji między klientem a serwerem poczty.

Główna wada tego protokołu polega na tym, że nie umożliwia on pobierania wiadomości e-mail z serwera. Z tego powodu, SMTP jest często używany w parze z innymi protokołami, takimi jak POP3 lub IMAP.

## POP3 (Post Office Protocol)

POP3, czyli Protokół Pocztowy, jest standardem internetowym służącym do **pobierania** wiadomości e-mail z serwera pocztowego. Wiadomości są pobierane z serwera do lokalnej skrzynki odbiorczej i **usuwane z serwera**, chyba że użytkownik zdecyduje inaczej.

Największym ograniczeniem tego protokołu jest brak możliwości synchronizacji między różnymi urządzeniami. Jeśli na przykład pobierzesz wiadomość na komputer, nie zobaczysz jej na smartfonie. Z tego powodu, POP3 jest teraz rzadziej stosowany niż IMAP.

## IMAP (Internet Message Access Protocol)

IMAP, czyli Protokół Dostępu do Wiadomości Internetowych, jest standardem internetowym do **zarządzania** wiadomościami e-mail na serwerze. W przeciwieństwie do POP3, który pobiera wiadomości z serwera, IMAP przechowuje wiadomości na serwerze i **synchronizuje je między różnymi urządzeniami**. Dzięki temu, możesz przeglądać swoje wiadomości e-mail na dowolnym urządzeniu z dostępem do Internetu.

IMAP umożliwia również organizowanie wiadomości w foldery na serwerze, co ułatwia zarządzanie pocztą. Ponadto, wszystkie działania takie jak przenoszenie, kasowanie czy oznaczanie wiadomości jako przeczytane są synchronizowane na wszystkich urządzeniach.

!!! warning
	 Pamiętaj, że zarówno SMTP, POP3, jak i IMAP są protokołami **nieszyfrowanymi**. Oznacza to, że twoje wiadomości mogą być przechwycone i odczytane. Dlatego wiele usług pocztowych oferuje zabezpieczone wersje tych protokołów (SMTPS, POP3S, IMAPS), które używają SSL lub TLS do szyfrowania komunikacji.
