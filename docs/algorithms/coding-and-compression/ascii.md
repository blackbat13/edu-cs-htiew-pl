# Kod ASCII

ASCII, czyli American Standard Code for Information Interchange, to standard kodowania znaków używany w komputerach i urządzeniach komunikacyjnych do reprezentowania tekstu. Tablica ASCII przypisuje numery (kody) do różnych znaków, takich jak litery, cyfry, znaki interpunkcyjne oraz inne symbole. Istnieją dwie wersje tablicy ASCII: podstawowa i rozszerzona.

1. Podstawowa tablica ASCII: zawiera **128** znaków, które obejmują angielskie litery (zarówno małe, jak i duże), cyfry, znaki interpunkcyjne oraz kontrolne. Znaki te są reprezentowane przez 7-bitowe kody binarne, co pozwala na ich zakodowanie w zakresie od 0 do 127.
2. Rozszerzona tablica ASCII: rozszerza podstawową tablicę do **256** znaków, dodając dodatkowe symbole, znaki specjalne i akcentowane litery używane w różnych językach. Te dodatkowe znaki są reprezentowane przez 8-bitowe kody binarne, co umożliwia ich zakodowanie w zakresie od 128 do 255.

## Podstawowa tablica ASCII

| Liczba | Znak |              Opis             |
|:------:|:----:|:-----------------------------:|
|    0   |  Nul |              zero             |
|    1   |  SQH |       początek nagłówka       |
|    2   |  STX |        początek tekstu        |
|    3   |  ETX |         koniec tekstu         |
|    4   |  EOT |       koniec transmisji       |
|    5   |  ENQ |        wywołanie stacji       |
|    6   |  ACK |         potwierdzenie         |
|    7   |  BEL |            dzwonek            |
|    8   |  BS  |           backspace           |
|    9   |  HT  |       tabulacja pozioma       |
|   10   |  LF  |  przesunięcie o jeden wiersz  |
|   11   |  FT  |       tabulacja pionowa       |
|   12   |  FF  |   przesunięcie o jedną stronę |
|   13   |  CR  |     powrót karetki - ENTER    |
|   14   |  SO  |            wyjście            |
|   15   |  SI  |            wejście            |
|   16   |  DLE | pominięcie znaków sterujących |
|   17   |  DC1 |    sterowanie urządzenia 1    |
|   18   |  DC2 |     sterowanie urządzenia 2   |
|   19   |  DC3 |    sterowanie urządzenia 3    |
|   20   |  DC4 |    sterowanie urządzenia 4    |
|   21   |  NAC |    potwierdzenie negatywne    |
|   22   |  SYN |         synchronizacja        |
|   23   |  ETB |          koniec bloku         |
|   24   |  CAN |           anulowanie          |
|   25   |  EM  |         koniec nośnika        |
|   26   |  SUB |          zastąpienie          |
|   27   |  ESC |             escape            |
|   28   |  FS  | poprzedza dane alfanumeryczne |
|   29   |  GS  |     poprzedza dane binarne    |
|   30   |  RS  |       separator rekordów      |
|   31   |  US  |       separator pozycji       |
|   32   |  SP  |             spacja            |
|   33   |   !  |                               |
|   34   |   "  |                               |
|   35   |   #  |                               |
|   36   |   $  |                               |
|   37   |   %  |                               |
|   38   |   &  |                               |
|   39   |   '  |                               |
|   40   |   (  |                               |
|   41   |   )  |                               |
|   42   |   *  |                               |
|   43   |   +  |                               |
|   44   |   ,  |                               |
|   45   |   -  |                               |
|   46   |   .  |                               |
|   47   |   /  |                               |
|   48   |   0  |                               |
|   49   |   1  |                               |
|   50   |   2  |                               |
|   51   |   3  |                               |
|   52   |   4  |                               |
|   53   |   5  |                               |
|   54   |   6  |                               |
|   55   |   7  |                               |
|   56   |   8  |                               |
|   57   |   9  |                               |
|   58   |   :  |                               |
|   59   |   ;  |                               |
|   60   |   <  |                               |
|   61   |   =  |                               |
|   62   |   >  |                               |
|   63   |   ?  |                               |
|   64   |   @  |                               |
|   65   |   A  |                               |
|   66   |   B  |                               |
|   67   |   C  |                               |
|   68   |   D  |                               |
|   69   |   E  |                               |
|   70   |   F  |                               |
|   71   |   G  |                               |
|   72   |   H  |                               |
|   73   |   I  |                               |
|   74   |   J  |                               |
|   75   |   K  |                               |
|   76   |   L  |                               |
|   77   |   M  |                               |
|   78   |   N  |                               |
|   79   |   O  |                               |
|   80   |   P  |                               |
|   81   |   Q  |                               |
|   82   |   R  |                               |
|   83   |   S  |                               |
|   84   |   T  |                               |
|   85   |   U  |                               |
|   86   |   V  |                               |
|   87   |   W  |                               |
|   88   |   X  |                               |
|   89   |   Y  |                               |
|   90   |   Z  |                               |
|   91   |   [  |                               |
|   92   |   \  |                               |
|   93   |   ]  |                               |
|   94   |   ^  |                               |
|   95   |   _  |                               |
|   96   |   `  |                               |
|   97   |   a  |                               |
|   98   |   b  |                               |
|   99   |   c  |                               |
|   100  |   d  |                               |
|   101  |   e  |                               |
|   102  |   f  |                               |
|   103  |   g  |                               |
|   104  |   h  |                               |
|   105  |   i  |                               |
|   106  |   j  |                               |
|   107  |   k  |                               |
|   108  |   l  |                               |
|   109  |   m  |                               |
|   110  |   n  |                               |
|   111  |   o  |                               |
|   112  |   p  |                               |
|   113  |   q  |                               |
|   114  |   r  |                               |
|   115  |   s  |                               |
|   116  |   t  |                               |
|   117  |   u  |                               |
|   118  |   v  |                               |
|   119  |   w  |                               |
|   120  |   x  |                               |
|   121  |   y  |                               |
|   122  |   z  |                               |
|   123  |   {  |                               |
|   124  |  \|  |                               |
|   125  |   }  |                               |
|   126  |   ~  |                               |
|   127  |  DEL |                               |

## Rozszerzona tablica ASCII (od znaku o numerze 128)

| Liczba | Znak |                                   Opis                                  |
|:------:|:----:|:-----------------------------------------------------------------------:|
|   128  |   Ç  |                   Latin Capital Letter C With Cedilla                   |
|   129  |   ü  |                   Latin Small Letter U With Diaeresis                   |
|   130  |   é  |                     Latin Small Letter E With Acute                     |
|   131  |   â  |                   Latin Small Letter A With Circumflex                  |
|   132  |   ä  |                   Latin Small Letter A With Diaeresis                   |
|   133  |   à  |                     Latin Small Letter A With Grave                     |
|   134  |   å  |                   Latin Small Letter A With Ring Above                  |
|   135  |   ç  |                    Latin Small Letter C With Cedilla                    |
|   136  |   ê  |                   Latin Small Letter E With Circumflex                  |
|   137  |   ë  |                   Latin Small Letter E With Diaeresis                   |
|   138  |   è  |                     Latin Small Letter E With Grave                     |
|   139  |   ï  |                   Latin Small Letter I With Diaeresis                   |
|   140  |   î  |                   Latin Small Letter I With Circumflex                  |
|   141  |   ì  |                     Latin Small Letter I With Grave                     |
|   142  |   Ä  |                  Latin Capital Letter A With Diaeresis                  |
|   143  |   Å  |                  Latin Capital Letter A With Ring Above                 |
|   144  |   É  |                    Latin Capital Letter E With Acute                    |
|   145  |   §  |                          Latin Small Letter Ae                          |
|   146  |   Æ  |                         Latin Capital Letter Ae                         |
|   147  |   ô  |                   Latin Small Letter O With Circumflex                  |
|   148  |   ö  |                   Latin Small Letter O With Diaeresis                   |
|   149  |   ò  |                     Latin Small Letter O With Grave                     |
|   150  |   û  |                   Latin Small Letter U With Circumflex                  |
|   151  |   ù  |                     Latin Small Letter U With Grave                     |
|   152  |   ÿ  |                   Latin Small Letter Y With Diaeresis                   |
|   153  |   Ö  |                  Latin Capital Letter O With Diaeresis                  |
|   154  |   Ü  |                  Latin Capital Letter U With Diaeresis                  |
|   155  |   ¢  |                                Cent Sign                                |
|   156  |   £  |            Pound Sign, Pound Sterling, Irish Punt, Lira Sign            |
|   157  |   ¥  |                           Yen Sign, Yuan Sign                           |
|   158  |   ₧  |                               Peseta Sign                               |
|   159  |   ƒ  | Latin Small Letter F With Hook, Florin Currency Symbol, Function Symbol |
|   160  |   á  |                     Latin Small Letter A With Acute                     |
|   161  |   í  |                     Latin Small Letter I With Acute                     |
|   162  |   ó  |                     Latin Small Letter O With Acute                     |
|   163  |   ú  |                     Latin Small Letter U With Acute                     |
|   164  |   ñ  |            Latin Small Letter N With Tilde, Small Letter Enye           |
|   165  |   Ñ  |          Latin Capital Letter N With Tilde, Capital Letter Enye         |
|   166  |   ª  |                        Feminine Ordinal Indicator                       |
|   167  |   º  |                       Masculine Ordinal Indicator                       |
|   168  |   ¿  |               Inverted Question Mark, Turned Question Mark              |
|   169  |   ⌐  |                   Reversed Not Sign, Beginning Of Line                  |
|   170  |   ¬  |                          Not Sign, Angled Dash                          |
|   171  |   ½  |                         Vulgar Fraction One Half                        |
|   172  |   ¼  |                       Vulgar Fraction One Quarter                       |
|   173  |   ¡  |                        Inverted Exclamation Mark                        |
|   174  |   «  |   Left-Pointing Double Angle Quotation Mark, Left Guillemet, Chevrons   |
|   175  |   »  |       Right-Pointing Double Angle Quotation Mark, Right Guillemet       |
|   176  |   ░  |                               Light Shade                               |
|   177  |   ▒  |                 Medium Shade, Speckles Fill, Dotted Fill                |
|   178  |   ▓  |                                Dark Shade                               |
|   179  |   │  |                       Box Drawings Light Vertical                       |
|   180  |   ┤  |                   Box Drawings Light Vertical And Left                  |
|   181  |   ╡  |               Box Drawings Vertical Single And Left Double              |
|   182  |   ╢  |               Box Drawings Vertical Double And Left Single              |
|   183  |   ╖  |                 Box Drawings Down Double And Left Single                |
|   184  |   ╕  |                 Box Drawings Down Single And Left Double                |
|   185  |   ╣  |                  Box Drawings Double Vertical And Left                  |
|   186  |   ║  |                       Box Drawings Double Vertical                      |
|   187  |   ╗  |                    Box Drawings Double Down And Left                    |
|   188  |   ╝  |                     Box Drawings Double Up And Left                     |
|   189  |   ╜  |                  Box Drawings Up Double And Left Single                 |
|   190  |   ╛  |                  Box Drawings Up Single And Left Double                 |
|   191  |   ┐  |                     Box Drawings Light Down And Left                    |
|   192  |   └  |                     Box Drawings Light Up And Right                     |
|   193  |   ┴  |                   Box Drawings Light Up And Horizontal                  |
|   194  |   ├  |                  Box Drawings Light Down And Horizontal                 |
|   195  |   ├  |                  Box Drawings Light Vertical And Right                  |
|   196  |   ─  |                      Box Drawings Light Horizontal                      |
|   197  |   ┼  |                Box Drawings Light Vertical And Horizontal               |
|   198  |   ╞  |              Box Drawings Vertical Single And Right Double              |
|   199  |   ╟  |              Box Drawings Vertical Double And Right Single              |
|   200  |   ╚  |                     Box Drawings Double Up And Right                    |
|   201  |   ╔  |                    Box Drawings Double Down And Right                   |
|   202  |   ╩  |                  Box Drawings Double Up And Horizontal                  |
|   203  |   ╦  |                 Box Drawings Double Down And Horizontal                 |
|   204  |   ╠  |                  Box Drawings Double Vertical And Right                 |
|   205  |   ═  |                      Box Drawings Double Horizontal                     |
|   206  |   ╬  |               Box Drawings Double Vertical And Horizontal               |
|   207  |   ╧  |               Box Drawings Up Single And Horizontal Double              |
|   208  |   ╨  |               Box Drawings Up Double And Horizontal Single              |
|   209  |   ╤  |              Box Drawings Down Single And Horizontal Double             |
|   210  |   ╥  |              Box Drawings Down Double And Horizontal Single             |
|   211  |   ╙  |                 Box Drawings Up Double And Right Single                 |
|   212  |   ╘  |                 Box Drawings Up Single And Right Double                 |
|   213  |   ╒  |                Box Drawings Down Single And Right Double                |
|   214  |   ╓  |                Box Drawings Down Double And Right Single                |
|   215  |   ╫  |            Box Drawings Vertical Double And Horizontal Single           |
|   216  |   ╪  |            Box Drawings Vertical Single And Horizontal Double           |
|   217  |   ┘  |                      Box Drawings Light Up And Left                     |
|   218  |   ┌  |                    Box Drawings Light Down And Right                    |
|   219  |   █  |                         Full Block, Solid Block                         |
|   220  |   ▄  |                             Lower Half Block                            |
|   221  |   ▌  |                             Left Half Block                             |
|   222  |   ▐  |                             Right Half Block                            |
|   223  |   ▀  |                             Upper Half Block                            |
|   224  |   α  |                         Greek Small Letter Alpha                        |
|   225  |   ß  |                    Latin Small Letter Sharp S, Eszett                   |
|   226  |   Γ  |                        Greek Capital Letter Gamma                       |
|   227  |   π  |                          Greek Small Letter Pi                          |
|   228  |   Σ  |                        Greek Capital Letter Sigma                       |
|   229  |   σ  |                         Greek Small Letter Sigma                        |
|   230  |   µ  |                                Micro Sign                               |
|   231  |   τ  |                         Greek Capital Letter Tau                        |
|   232  |   Φ  |                         Greek Capital Letter Phi                        |
|   233  |   Θ  |                        Greek Capital Letter Theta                       |
|   234  |   Ω  |                        Greek Capital Letter Omega                       |
|   235  |   δ  |                         Greek Small Letter Delta                        |
|   236  |   ∞  |                                 Infinity                                |
|   237  |   φ  |                          Greek Small Letter Phi                         |
|   238  |   ε  |                        Greek Small Letter Epsilon                       |
|   239  |   ∩  |                               Intersection                              |
|   240  |   ≡  |                               Identical To                              |
|   241  |   ±  |                             Plus-Minus Sign                             |
|   242  |   ≥  |                         Greater-Than Or Equal To                        |
|   243  |   ≤  |                          Less-Than Or Equal To                          |
|   244  |   ⌠  |                            Top Half Integral                            |
|   245  |   ⌡  |                           Bottom Half Integral                          |
|   246  |   ÷  |                          Division Sign, Obelus                          |
|   247  |   ≈  |                      Almost Equal To, Asymptotic To                     |
|   248  |   °  |                               Degree Sign                               |
|   249  |   ∙  |                             Bullet Operator                             |
|   250  |   ·  |                          Middle Dot, Interpunct                         |
|   251  |   √  |                        Square Root, Radical Sign                        |
|   252  |   ⁿ  |                     Superscript Latin Small Letter N                    |
|   253  |   ²  |                         Superscript Two, Squared                        |
|   254  |   ■  |                               Black Square                              |
|   255  |      |                         Non-Breaking Space, NBSP                        |


## Implementacja

### C++


[ascii.md](../../programming/c++/algorithms/coding-and-compression/ascii.md)


### Python


[ascii.md](../../programming/python/algorithms/coding-and-compression/ascii.md)

