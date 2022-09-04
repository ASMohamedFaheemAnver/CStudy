//
// Created by freedom on 9/4/22.
//

#include <stdio.h>
#include <malloc.h>
#include "linkedlist.h"
#include "core-types.h"
#include "utils.h"


// Initialize linked list
void createRowLinkList(RowLinkList *rowLinkList)
{
    rowLinkList->topNode = NULL;
}

// Push row in front position
void pushRowToLinkList(RowLinkList *rowLinkList, Row row)
{
    // Initialize new linked list node
    RowNode *newRowNode;
    newRowNode = (RowNode *)malloc(sizeof(RowNode));
    newRowNode->row = row;
    newRowNode->previous = NULL;
    newRowNode->next = NULL;

    if (rowLinkList->topNode == NULL)
    {
        // Assign new node to top if linked list is empty
        rowLinkList->topNode = newRowNode;
    }
    else
    {
        // Make new node top and previous top node as previous
        newRowNode->previous = rowLinkList->topNode;
        rowLinkList->topNode->next = newRowNode;
        rowLinkList->topNode = newRowNode;
    }
}

void pushRowsToLinkList(RowLinkList *rowLinkList, Row *rows, int length)
{
    // Iterate through rows and push it into linked list
    for (int i = 0; i < length; i++)
    {
        pushRowToLinkList(rowLinkList, rows[i]);
    }
}

// Display linked list
void displayRowLinkList(RowLinkList *rowLinkList)
{
    // Make referent to linked list top
    RowNode *toRowNode = rowLinkList->topNode;
    // Hold exit condition
    int dontExit = 1;
    printf("********** ROWS LINKED LIST ITEM **********\n");
    while (dontExit)
    {
        // Display current node row variable
        displayRow(toRowNode->row);
        // If current node doesn't have previous node exit
        if (toRowNode->previous == NULL)
        {
            dontExit = 0;
        }
        // If current node has previous node, make it as top node
        else
        {
            toRowNode = toRowNode->previous;
        }
    }
    printf("********** ROWS LINKED LIST ITEM **********\n");
}