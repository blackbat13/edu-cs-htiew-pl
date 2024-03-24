# Fork

### Przykład

```perl
#!/usr/bin/perl

if (!defined($pid = fork())) {
	die "Nie mozna utworzyc procesu potomnego!";
} elsif ($pid == 0) {
	print "Proces potomny\n";
} else {
    print "Proces rodzica\n";
	# Czekamy na proces potomny
	$ret = waitpid($pid, 0);
	print "Zakonczono obliczenia, id procesu potomnego: $ret\n";
}
```