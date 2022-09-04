#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Represent each row of the text.txt file
typedef struct row
{
    // string
    char column0[10];
    // column two and three
    int column1;
    int column2;
    // column four
    double column3;
} Row;

// Search keyword linearly
Row searchRowLinearly(Row *rows, int length, char searchKey[])
{
    for (int i = 0; i < length; i++)
    {
        if (strcmp(rows[i].column0, searchKey) == 0)
        {
            return rows[i];
        }
    }
    Row notFoundRow;
    strcpy(notFoundRow.column0, "NULL");
    return notFoundRow;
}

// Search keyword linearly
Row searchRowBinary(Row *rows, int front, int end, char searchKey[])
{
    if (end >= front)
    {
        int mid = front + (end - front) / 2;
        if (strcmp(rows[mid].column0, searchKey) == 0)
            return rows[mid];
        if (strcmp(rows[mid].column0, searchKey) > 0)
            return searchRowBinary(rows, front, mid - 1, searchKey);
        return searchRowBinary(rows, mid + 1, end, searchKey);
    }

    Row notFoundRow;
    strcpy(notFoundRow.column0, "NULL");
    return notFoundRow;
}

// Write modified rows inside output.txt file
void writeRows(Row *rows, int length)
{
    // Assigning it to empty string to avoid garbage values concatenated to the string
    char text[1000] = "";
    // Max int and double caster string length
    int stringHolderLength = 50;
    // Will hold casted double and int
    char stringHolder[stringHolderLength];

    // Iterate through rows and concat them to single string
    for (int i = 0; i < length; i++)
    {
        strcat(text, rows[i].column0);
        snprintf(stringHolder, stringHolderLength, " %d ", rows[i].column1);
        strcat(text, stringHolder);
        snprintf(stringHolder, stringHolderLength, "%d ", rows[i].column2);
        strcat(text, stringHolder);
        snprintf(stringHolder, stringHolderLength, "%.2f", rows[i].column3);
        strcat(text, stringHolder);
        strcat(text, "\n");
    }
    // Creating file pointer
    FILE *fp;
    // Opening file with name output.txt in writing mode
    fp = fopen("../output.txt", "w");
    // Write the file with concatenated string
    fprintf(fp, "%s", text);
    // Closing the file pointer
    fclose(fp);
}

// Swap two values
void swapRow(Row *a, Row *b)
{
    Row temp = *a;
    *a = *b;
    *b = temp;
}

// Selection sort ascending order
void selectionSortRowsAsc(Row *rows, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (strcmp(rows[j].column0, rows[minIndex].column0) < 0)
                minIndex = j;
        }
        swapRow(&rows[minIndex], &rows[i]);
    }
}

// Selection sort descending order
void selectionSortRowsDesc(Row *rows, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        int maxIndex = i;
        for (int j = i + 1; j < length; j++)
        {
            if (strcmp(rows[j].column0, rows[maxIndex].column0) > 0)
                maxIndex = j;
        }
        swapRow(&rows[maxIndex], &rows[i]);
    }
}

// Bubble sort ascending order
void bubbleSortRowsAsc(Row *rows, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (strcmp(rows[i].column0, rows[j].column0) < 0)
            {
                Row temp = rows[i];
                rows[i] = rows[j];
                rows[j] = temp;
            }
        }
    }
}

// Bubble sort descending order
void bubbleSortRowsDesc(Row *rows, int length)
{
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = i + 1; j < length; j++)
        {
            if (strcmp(rows[i].column0, rows[j].column0) < 0)
            {
                Row temp = rows[i];
                rows[i] = rows[j];
                rows[j] = temp;
            }
        }
    }
}

void displayRows(Row *rows, int length)
{
    printf("********** ROWS ITEM **********\n");
    for (int i = 0; i < length; i++)
    {
        printf("%s %d %d %.2f\n", rows[i].column0, rows[i].column1, rows[i].column2, rows[i].column3);
    }
    printf("********** ROWS ITEM **********\n");
}

void main()
{
    // Array of struct to represent the whole text.txt file
    int rowsLength = 10;
    Row rows[rowsLength];
    // Opening the file pointer
    FILE *fp;
    // Line buffer size
    size_t len = 0;
    // Get row value into this variable
    char *line;
    // Opening the file and assigning it into file pointer fp
    fp = fopen("../text.txt", "r");

    // Track current line
    int i = 0;
    // Read the whole file
    while (getline(&line, &len, fp) != -1)
    {
        char *token;
        // Tokenizing the line and assigning it into particulate column variable
        token = strtok(line, " ");
        strcpy(rows[i].column0, token);
        rows[i].column1 = atol(strtok(NULL, " "));
        rows[i].column2 = atol(strtok(NULL, " "));
        rows[i].column3 = atof(strtok(NULL, " "));
        i++;
    }
    // Closing the file pointer
    fclose(fp);

    // Displaying the content
    //    displayRows(rows, rowsLength);
    //    bubbleSortRowsAsc(rows, rowsLength);
    //    displayRows(rows, rowsLength);
    //        bubbleSortRowsDesc(rows, rowsLength);
    //    displayRows(rows, rowsLength);

    //    selectionSortRowsAsc(rows, rowsLength);
    //    displayRows(rows, rowsLength);
    //    selectionSortRowsDesc(rows, rowsLength);
    //    displayRows(rows, rowsLength);
    writeRows(rows, rowsLength);
    char keyword[] = "string1";
    int front = 0;
    Row foundRow = searchRowBinary(rows, front, rowsLength - 1, keyword);
    printf("");
}