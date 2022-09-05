//
// Created by freedom on 9/4/22.
//

#ifndef Q1_CORE_TYPES_H
#define Q1_CORE_TYPES_H

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

#endif //Q1_CORE_TYPES_H
