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
