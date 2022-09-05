//
// Created by freedom on 9/4/22.
//

#ifndef Q1_UTILS_H
#define Q1_UTILS_H
#include "core-types.h"

Row searchRowLinearly(Row *rows, int length, char searchKey[]);
Row searchRowBinary(Row *rows, int front, int end, char searchKey[]);
void writeRows(Row *rows, int length);
void displayRows(Row *rows, int length);
void swapRow(Row *a, Row *b);
void selectionSortRowsAsc(Row *rows, int length);
void selectionSortRowsDesc(Row *rows, int length);
void bubbleSortRowsAsc(Row *rows, int length);
void bubbleSortRowsDesc(Row *rows, int length);
void displayRow(Row row);
void displayRowLinkList(RowLinkList *rowLinkList);
void displayRootInstruction();
void space();
void selectionSortRowsDecisionMaker(Row *rows, int length);
void bubbleSortRowsDecisionMaker(Row *rows, int length);
void sortRowsDecisionMaker(Row *rows, int length);
void searchRowDecisionMaker(Row *rows, int length);
#endif //Q1_UTILS_H
