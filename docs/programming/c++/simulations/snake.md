# Wężyk

Prosta symulacja, w której znak `#` porusza się w formie "wężyka" po ekranie konsoli - od lewej do prawej i od prawej do lewej.

```cpp
#include <iostream>
#include <cstdlib>

using namespace std;

int main()
{
    for(int i = 0; i < 10; i++)
    {
        if(i% 2 == 0)
        {
            for(int j = 0; j < 50; j++)
            {
                for(int i2 = 0; i2 < 10; i2++)
                {
                    for(int j2 = 0; j2 < 50; j2++)
                    {
                        if(i2 == i && j2 == j)
                        {
                            cout << "#";
                        }
                        else
                        {
                            cout << " ";
                        }
                    }
					
                    cout << endl;
                }
				
                system("cls");
            }
        } else {
            for(int j = 49; j >= 0; j--)
            {
                for(int i2 = 0; i2 < 10; i2++)
                {
                    for(int j2 = 0; j2 < 50; j2++)
                    {
                        if(i2 == i && j2 == j)
                        {
                            cout << "#";
                        }
                        else
                        {
                            cout << " ";
                        }
                    }
					
                    cout << endl;
                }
				
                system("cls");
            }
        }
    }
	
    return 0;
}
```

### Link do implementacji

{% embed url="https://replit.com/@damiankurpiewski/Snake#main.cpp" %}

### Opis implementacji

TODO

{% hint style="warning" %}
Pod systemem Linux zamiast polecenia **cls** używamy polecenia **clear** do wyczyszczenia ekranu terminala.
{% endhint %}
