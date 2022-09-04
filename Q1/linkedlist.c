//
// Created by freedom on 9/4/22.
//

#include <stdio.h>
#include <malloc.h>
#include "linkedlist.h"
#include "core-types.h"


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

void pushRowsToLinkList(RowLinkList *rowLinkList, Row *rows, int length)
{
    for (int i = 0; i < length; i++)
    {
        pushRowToLinkList(rowLinkList, rows[i]);
    }
}