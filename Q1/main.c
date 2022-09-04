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

// Row node for link list block
typedef struct rowNode
{
    Row row;
    struct rowNode *next;
    struct rowNode *previous;
} RowNode;

// Row link list struct
typedef struct
{
    RowNode *topNode;
} RowLinkList;

// Initialize linked list
void createRowLinkList(RowLinkList *rowLinkList)
{
    rowLinkList->topNode = NULL;
}

// Push row in front position
void pushRowToLinkList(RowLinkList *rowLinkList, Row row)
{
    RowNode *newRowNode;
    newRowNode = (RowNode *)malloc(sizeof(RowNode));
    newRowNode->row = row;
    newRowNode->previous = NULL;
    newRowNode->next = NULL;

    if (rowLinkList->topNode == NULL)
    {
        rowLinkList->topNode = newRowNode;
    }
    else
    {
        newRowNode->previous = rowLinkList->topNode;
        rowLinkList->topNode->next = newRowNode;
        rowLinkList->topNode = newRowNode;
    }
}

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
            if (strcmp(rows[i].column0, rows[j].column0) > 0)
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

void displayRow(Row row)
{
    printf("%s %d %d %.2f\n", row.column0, row.column1, row.column2, row.column3);
}

void displayRows(Row *rows, int length)
{
    printf("********** ROWS ITEM **********\n");
    for (int i = 0; i < length; i++)
    {
        displayRow(rows[i]);
    }
    printf("********** ROWS ITEM **********\n");
}

void pushRowsToLinkList(RowLinkList *rowLinkList, Row *rows, int length)
{
    for (int i = 0; i < length; i++)
    {
        pushRowToLinkList(rowLinkList, rows[i]);
    }
}

void displayRowLinkList(RowLinkList *rowLinkList)
{
    RowNode *toRowNode = rowLinkList->topNode;
    int dontExit = 1;
    printf("********** ROWS LINKED LIST ITEM **********\n");
    while (dontExit)
    {
        displayRow(toRowNode->row);
        if (toRowNode->previous == NULL)
        {
            dontExit = 0;
        }
        else
        {
            toRowNode = toRowNode->previous;
        }
    }
    printf("********** ROWS LINKED LIST ITEM **********\n");
}

void displayRootInstruction()
{
    printf("********** INSTRUCTIONS **********\n");
    printf("Choose between following option to perform actions (Assuming you only type int)!\n");
    printf("1. Sort array\n");
    printf("2. Search for a string in array\n");
    printf("3. Insert sorted array into linked list and display it\n");
    printf("4. Quit\n");
    printf("********** INSTRUCTIONS **********\n");
}

void space()
{
    printf("\n\n");
}

void selectionSortRowsDecisionMaker(Row *rows, int length)
{
    printf("********** SELECTION SORTING INSTRUCTIONS **********\n");
    printf("Choose between following option to perform actions (Assuming you only type int)!\n");
    printf("1. Sort in ascending order\n");
    printf("2. Sort in descending order\n");
    printf("********** SELECTION SORTING INSTRUCTIONS **********\n");
    int choice = -1;
    space();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        selectionSortRowsAsc(rows, length);
        space();
        printf("********** AFTER ASCENDING SELECTION SORT **********\n");
        displayRows(rows, length);
        writeRows(rows, length);
        space();
        break;
    case 2:
        selectionSortRowsDesc(rows, length);
        space();
        printf("********** AFTER DESCENDING SELECTION SORT **********\n");
        displayRows(rows, length);
        writeRows(rows, length);
        space();
        break;
    }
}

void bubbleSortRowsDecisionMaker(Row *rows, int length)
{
    printf("********** BUBBLE SORTING INSTRUCTIONS **********\n");
    printf("Choose between following option to perform actions (Assuming you only type int)!\n");
    printf("1. Sort in ascending order\n");
    printf("2. Sort in descending order\n");
    printf("********** BUBBLE SORTING INSTRUCTIONS **********\n");
    int choice = -1;
    space();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        bubbleSortRowsAsc(rows, length);
        space();
        printf("********** AFTER ASCENDING BUBBLE SORT **********\n");
        displayRows(rows, length);
        writeRows(rows, length);
        space();
        break;
    case 2:
        bubbleSortRowsDesc(rows, length);
        space();
        printf("********** AFTER DESCENDING BUBBLE SORT **********\n");
        displayRows(rows, length);
        writeRows(rows, length);
        space();
        break;
    }
}

void sortRowsDecisionMaker(Row *rows, int length)
{
    printf("********** SORTING INSTRUCTIONS **********\n");
    printf("Choose between following option to perform actions (Assuming you only type int)!\n");
    printf("1. Use selection sort\n");
    printf("2. Use bubble sort\n");
    printf("********** SORTING INSTRUCTIONS **********\n");
    int choice = -1;
    space();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        selectionSortRowsDecisionMaker(rows, length);
        break;
    case 2:
        bubbleSortRowsDecisionMaker(rows, length);
        break;
    }
}

void searchRowDecisionMaker(Row *rows, int length)
{
    printf("Enter your search string: ");
    char searchKey[50];
    scanf("%s", &searchKey);
    space();
    printf("********** SEARCH INSTRUCTIONS **********\n");
    printf("Choose between following option to perform actions (Assuming you only type int)!\n");
    printf("1. Use linear search\n");
    printf("2. Use binary search\n");
    printf("********** SEARCH INSTRUCTIONS **********\n");
    int choice = -1;
    space();
    printf("Enter your choice: ");
    scanf("%d", &choice);
    Row foundRow;
    switch (choice)
    {
    case 1:
        foundRow = searchRowLinearly(rows, length, searchKey);
        break;
    case 2:
        selectionSortRowsAsc(rows, length);
        foundRow = searchRowBinary(rows, 0, length - 1, searchKey);
        break;
    }
    if (strcmp(foundRow.column0, "NULL") != 0)
    {
        printf("Found row with following column values\n");
        displayRow(foundRow);
    }
    else
    {
        printf("String not found inside rows\n");
    }
    space();
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

    RowLinkList rowLinkList;

    // Displaying current text.txt structure.
    displayRows(rows, rowsLength);
    space();
    int dontExit = 1;
    int choice = -1;
    while (dontExit)
    {
        displayRootInstruction();
        space();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            space();
            sortRowsDecisionMaker(rows, rowsLength);
            break;
        case 2:
            space();
            searchRowDecisionMaker(rows, rowsLength);
            break;
        case 3:
            createRowLinkList(&rowLinkList);
            selectionSortRowsDesc(rows, rowsLength);
            pushRowsToLinkList(&rowLinkList, rows, rowsLength);
            space();
            displayRowLinkList(&rowLinkList);
            space();
            break;
        case 4:
            printf("Exiting!");
            dontExit = 0;
            break;
        }
    }
}
