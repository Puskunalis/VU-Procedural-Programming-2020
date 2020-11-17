// Vilius Puskunalis 5 grupe 3 uzduotis
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ARGS_LENGTH 2

#define ASCII_SPACE 32
#define MAX_LINE_SIZE 256

#define SUCCESS 0
#define READ_ERROR 1
#define WRITE_ERROR 2
#define MEMORY_ERROR 3

char* connectLine(char* line)
{
    char *lineCopy = (char*) malloc(sizeof(char) * (MAX_LINE_SIZE + 1));
    if (lineCopy == NULL)
    {
        return NULL;
    }

    strcpy(lineCopy, line);

    for (int i = 0; lineCopy[i + 3] != 0; ++i)
    {
        // Checking whether symbols separated by a dash are not spaces
        if (lineCopy[i] != ASCII_SPACE && lineCopy[i + 1] == '-' && lineCopy[i + 2] != ASCII_SPACE)
        {
            // Move the rest of the string, this way deleting the dash
            for (int j = i + 1; lineCopy[j] != 0; ++j)
            {
                lineCopy[j] = lineCopy[j + 1];
            }

            --i;
        }
    }

    return lineCopy;
}

int fConnectLines(char* inputFileName, char* outputFileName)
{
    FILE *inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL)
    {
        return READ_ERROR;
    }

    FILE *outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL)
    {
        fclose(inputFile);
        return WRITE_ERROR;
    }

    char *line = (char*) malloc(sizeof(char) * (MAX_LINE_SIZE + 1));
    if (line == NULL)
    {
        fclose(inputFile);
        fclose(outputFile);
        return MEMORY_ERROR;
    }

    while (fgets(line, MAX_LINE_SIZE + 1, inputFile))
    {
        char *parsedLine = connectLine(line);
        if (parsedLine == NULL)
        {
            free(line);
            fclose(inputFile);
            fclose(outputFile);
            return MEMORY_ERROR;
        }

        fputs(parsedLine, outputFile);
        free(parsedLine);
    }

    free(line);
    fclose(inputFile);
    fclose(outputFile);
    return SUCCESS;
}

int main(int argc, char* argv[])
{
    if (argc > ARGS_LENGTH)
    {
        switch (fConnectLines(argv[1], argv[2]))
        {
            case READ_ERROR:
                printf("Input file not found!\n");
                break;
            case WRITE_ERROR:
                printf("Cannot create output file!\n");
                break;
            case MEMORY_ERROR:
                printf("Out of memory!\n");
                break;
            case SUCCESS:
                printf("All done.\n");
                break;
        }
    }
    else
    {
        printf("Usage: 3-3.exe [input file] [output file]\n");
    }

    return 0;
}
