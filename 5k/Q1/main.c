#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "core-types.h"
#include "linkedlist.h"
#include "utils.h"

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
    fp = fopen("text.txt", "r");
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
    // Proper space
    space();
    // Variable to break while loop
    int dontExit = 1;
    // Variable to hold user choice
    int choice = -1;
    while (dontExit)
    {
        // Display the instruction
        displayRootInstruction();
        space();
        // Ask user choice
        printf("Enter your choice: ");
        // Get user input
        scanf("%d", &choice);
        // Make decision with user choice
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
            // Initialize linked list
            createRowLinkList(&rowLinkList);
            // Sort before inserting it into linked list
            selectionSortRowsDesc(rows, rowsLength);
            // Push whole rows to created linked list
            pushRowsToLinkList(&rowLinkList, rows, rowsLength);
            space();
            // Display linked list elements
            displayRowLinkList(&rowLinkList);
            space();
            break;
        case 4:
            // Exit the program
            printf("Exiting!");
            dontExit = 0;
            break;
        }
    }
}
