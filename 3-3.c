// Vilius Puskunalis 5 grupe 3 uzduotis
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_SPACE 32
#define MAX_LINE_SIZE 256

/*
**  Return codes:
**  0 - success
**  1 - read error
**  2 - write error
*/
int connectWords(char* inputFileName, char* outputFileName)
{
    FILE* inputFile;

    if (!strcmp(inputFileName, "stdin"))
    {
        inputFile = stdin;
    }
    else
    {
        inputFile = fopen(inputFileName, "r");

        if (inputFile == NULL)
        {
            return 1;
        }
    }

    FILE* outputFile;

    if (!strcmp(outputFileName, "stdout"))
    {
        outputFile = stdout;
    }
    else
    {
        outputFile = fopen(outputFileName, "w");

        if (outputFile == NULL)
        {
            fclose(inputFile);
            return 2;
        }
    }

    char* line = malloc(MAX_LINE_SIZE + 1);

    while (!feof(inputFile))
    {
        line = fgets(line, MAX_LINE_SIZE + 1, inputFile);

        if (line != NULL)
        {
            for (int i = 0; line[i + 3] != 0; ++i)
            {
                // Checking whether symbols separated by a dash are not spaces
                if (line[i] != ASCII_SPACE && line[i + 1] == '-' && line[i + 2] != ASCII_SPACE)
                {
                    // Move the rest of the string, this way deleting the dash
                    for (int j = i + 1; line[j] != 0; ++j)
                    {
                        line[j] = line[j + 1];
                    }

                    --i;
                }
            }

            fputs(line, outputFile);
        }
    }

    free(line);
    fclose(inputFile);
    fclose(outputFile);
    return 0;
}

int main(int argc, char* argv[])
{
    if (argc > 2)
    {
        int result = connectWords(argv[1], argv[2]);

        if (result == 1)
        {
            printf("Input file not found!\n");
        }
        else if (result == 2)
        {
            printf("Cannot create output file!\n");
        }
    }
    else
    {
        printf("Usage: 3-3.exe [input file] [output file]\n");
    }

    return 0;
}
