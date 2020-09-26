// Vilius Puskunalis 5 grupe 2 uzduotis
#include <stdio.h>

void SkaitytiMatrica(int N, int Matrica[][N])
{
    printf("Veskite matricos narius:\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf("%d", &Matrica[i][j]);
        }

        // Alternatyva su vienu ciklu, kai i < N * N
        // scanf("%d", &Matrica[i / N][i % N]);
    }
}

int RastiMaziausia(int N, int Masyvas[])
{
    int maziausias = Masyvas[0];

    for (int i = 1; i < N; i++)
    {
        if (Masyvas[i] < maziausias)
        {
            maziausias = Masyvas[i];
        }
    }

    return maziausias;
}

int RastiDidziausia(int N, int Masyvas[])
{
    int didziausias = Masyvas[0];

    for (int i = 1; i < N; i++)
    {
        if (Masyvas[i] > didziausias)
        {
            didziausias = Masyvas[i];
        }
    }

    return didziausias;
}

void RastiBalnoTaskus(int N, int Matrica[][N], int BalnoTaskaiX[], int BalnoTaskaiY[], int *balnoTaskai)
{
    // Indeksai: 0 - maziausias elementas, 1 - didziausias elementas
    int EiluciuElementai[N][2], StulpeliuElementai[N][2], Stulpelis[N];

    for (int i = 0; i < N; i++)
    {
        EiluciuElementai[i][0] = RastiMaziausia(N, Matrica[i]);
        EiluciuElementai[i][1] = RastiDidziausia(N, Matrica[i]);

        // Paverciame stulpeli i eilute
        for (int j = 0; j < N; j++)
        {
            Stulpelis[j] = Matrica[j][i];
        }

        StulpeliuElementai[i][0] = RastiMaziausia(N, Stulpelis);
        StulpeliuElementai[i][1] = RastiDidziausia(N, Stulpelis);

        //printf("Eilute: %d %d\n", EiluciuElementai[i][0], EiluciuElementai[i][1]);
        //printf("Stulpelis: %d %d\n", StulpeliuElementai[i][0], StulpeliuElementai[i][1]);
    }

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (Matrica[i][j] == EiluciuElementai[i][0] && Matrica[i][j] == StulpeliuElementai[j][1]
            || (Matrica[i][j] == EiluciuElementai[i][1] && Matrica[i][j] == StulpeliuElementai[j][0]))
            {
                BalnoTaskaiX[(*balnoTaskai)] = i;
                BalnoTaskaiY[(*balnoTaskai)] = j;
                (*balnoTaskai)++;
            }
        }
    }
}

void SpausdintiBalnoTaskus(int balnoTaskai, int BalnoTaskaiX[], int BalnoTaskaiY[])
{
    if (balnoTaskai == 0)
    {
        printf("Balno tasku nera.\n");
    }
    else
    {
        printf("Balno taskai:\n");

        for (int i = 0; i < balnoTaskai; i++)
        {
            printf("(%d, %d)\n", BalnoTaskaiX[i] + 1, BalnoTaskaiY[i] + 1);
        }
    }
}

int main()
{
    int N;
    printf("Iveskite matricos dydi:\n");
    scanf("%d", &N);

    int Matrica[N][N];
    SkaitytiMatrica(N, Matrica);

    int BalnoTaskaiX[N], BalnoTaskaiY[N], balnoTaskai = 0;
    RastiBalnoTaskus(N, Matrica, BalnoTaskaiX, BalnoTaskaiY, &balnoTaskai);

    SpausdintiBalnoTaskus(balnoTaskai, BalnoTaskaiX, BalnoTaskaiY);

    return 0;
}
