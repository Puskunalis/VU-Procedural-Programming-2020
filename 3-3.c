// Vilius Puskunalis 5 grupe 3 uzduotis
#include <stdio.h>

#define INPUT_FILE "3-3.in"
#define OUTPUT_FILE "3-3.out"
#define ARRAY_SIZE 256
#define MAX_LINE_SIZE 257

int read(char lines[][MAX_LINE_SIZE], int *linesCount)
{
    FILE *inputFile = fopen(INPUT_FILE, "r");

    if (inputFile != NULL)
    {
        while (!feof(inputFile))
        {
            // Lines longer than 255 symbols may not be parsed correctly
            fgets(lines[(*linesCount)++], MAX_LINE_SIZE, inputFile);
        }

        fclose(inputFile);
        return 1;
    }

    return 0;
}

void connectWords(char line[])
{
    for (int i = 0; line[i + 3] != 0; ++i)
    {
        // Checking whether symbols separated by a dash are not spaces
        if (line[i] != ' ' && line[i + 1] == '-' && line[i + 2] != ' ')
        {
            // Move the rest of the string, this way deleting the dash
            for (int j = i + 1; line[j] != 0; ++j)
            {
                line[j] = line[j + 1];
            }

            --i;
        }
    }
}

int write(char lines[][MAX_LINE_SIZE], int linesCount)
{
    FILE *outputFile = fopen(OUTPUT_FILE, "w");

    if (outputFile != NULL)
    {
        for (int i = 0; i < linesCount; ++i)
        {
            fputs(lines[i], outputFile);
        }

        fclose(outputFile);
        return 1;
    }

    return 0;
}

int main()
{
    char lines[ARRAY_SIZE][MAX_LINE_SIZE];
    int linesCount = 0;

    if (read(lines, &linesCount))
    {
        for (int i = 0; i < linesCount; ++i)
        {
            connectWords(lines[i]);
        }

        if (!write(lines, linesCount))
        {
            printf("Cannot create output file!\n");
        }
    }
    else
    {
        printf("Input file not found!\n");
    }

    return 0;
}
