// Vilius Puskunalis 5 grupe 3 uzduotis
#include <stdio.h>

#define INPUT_FILE "3-3.in"
#define OUTPUT_FILE "3-3.out"
#define MAX_LINE_SIZE 256

int skaityti(char eilutes[][MAX_LINE_SIZE], int *eiluciuSkaicius)
{
    FILE *ivestiesFailas = fopen(INPUT_FILE, "r");

    if (ivestiesFailas != NULL)
    {
        while (!feof(ivestiesFailas))
        {
            // Gali kilti problemu, jei eilute ilgesne, nei nurodymuose
            fgets(eilutes[(*eiluciuSkaicius)++], MAX_LINE_SIZE + 1, ivestiesFailas);
        }

        fclose(ivestiesFailas);
        return 1;
    }

    return 0;
}

void jungtiZodzius(char eilute[])
{
    for (int i = 0; eilute[i + 3] != 0; ++i)
    {
        // Tikriname, ar bruksniais atskirti ne tarpo simboliai
        if (eilute[i] != ' ' && eilute[i + 1] == '-' && eilute[i + 2] != ' ')
        {
            // Perkeliame likusia teksto eilutes dali, taip istrindami bruksni
            for (int j = i + 1; eilute[j] != 0; ++j)
            {
                eilute[j] = eilute[j + 1];
            }

            --i;
        }
    }
}

int rasyti(char eilutes[][MAX_LINE_SIZE], int eiluciuSkaicius)
{
    FILE *isvestiesFailas = fopen(OUTPUT_FILE, "w");

    if (isvestiesFailas != NULL)
    {
        for (int i = 0; i < eiluciuSkaicius; ++i)
        {
            fputs(eilutes[i], isvestiesFailas);
        }

        fclose(isvestiesFailas);
        return 1;
    }

    return 0;
}

int main()
{
    char eilutes[256][MAX_LINE_SIZE];
    int eiluciuSkaicius = 0;

    if (skaityti(eilutes, &eiluciuSkaicius))
    {
        for (int i = 0; i < eiluciuSkaicius; ++i)
        {
            jungtiZodzius(eilutes[i]);
        }

        if (!rasyti(eilutes, eiluciuSkaicius))
        {
            printf("Negalima sukurti rezultatu failo!\n");
        }
    }
    else
    {
        printf("Duomenu failas nerastas!\n");
    }

    return 0;
}
