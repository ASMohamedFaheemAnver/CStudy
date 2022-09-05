//
// Created by freedom on 9/4/22.
//

#include "utils.h"
#include <stdio.h>
#include <string.h>
#include "core-types.h"


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
    fp = fopen("output.txt", "w");
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
// Display single row element
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

// Ask user to choose between descending and ascending order
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
            // Sort rows using selection sort ascending order
            selectionSortRowsAsc(rows, length);
            space();
            printf("********** AFTER ASCENDING SELECTION SORT **********\n");
            // Display the sorted rows
            displayRows(rows, length);
            // Write it into file
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

// Ask user to choose sorting technique
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
    // Hold user search string
    char searchKey[50];
    // Get user input and assign it to searchKey
    scanf("%s", searchKey);
    space();
    // Instruction
    printf("********** SEARCH INSTRUCTIONS **********\n");
    printf("Choose between following option to perform actions (Assuming you only type int)!\n");
    printf("1. Use linear search\n");
    printf("2. Use binary search\n");
    printf("********** SEARCH INSTRUCTIONS **********\n");
    // Hold user choice
    int choice = -1;
    space();
    // Ask user to choose between linear and binary search
    printf("Enter your choice: ");
    scanf("%d", &choice);
    // Hold found row value
    Row foundRow;
    switch (choice)
    {
        case 1:
            // Use linear search
            foundRow = searchRowLinearly(rows, length, searchKey);
            break;
        case 2:
            // Sort before binary search
            selectionSortRowsAsc(rows, length);
            // Use binary search
            foundRow = searchRowBinary(rows, 0, length - 1, searchKey);
            break;
    }
    // Check row exist or not
    if (strcmp(foundRow.column0, "NULL") != 0)
    {
        // Display found row to user
        printf("Found row with following column values\n");
        displayRow(foundRow);
    }
    else
    {
        // Display not found message
        printf("String not found inside rows\n");
    }
    space();
}