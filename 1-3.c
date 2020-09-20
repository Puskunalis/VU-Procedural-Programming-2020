#include <stdio.h>

int main()
{
    int nelyginiai = 0, skaicius = 0, suma;

    printf("Veskite skaicius, 0 zymi sekos pabaiga:\n");

    do
    {
        suma = 0;

        while (skaicius > 0)
        {
            suma += skaicius % 10;
            skaicius /= 10;
        }

        // Patikrinimui, ar teisingai surandama skaitmenu suma
        // printf("Skaitmenu suma: %d\n", suma);

        if (suma % 2 == 1)
        {
            nelyginiai++;
        }

        // Skaicius nuskaitomas ciklo gale tam, kad galetu
        // buti teisingai naudojama (skaicius != 0) salyga

        scanf("%d", &skaicius);
    } while (skaicius != 0);

    printf("Nariai, kuriu skaitmenu suma nelygine: %d", nelyginiai);

    return 0;
}
