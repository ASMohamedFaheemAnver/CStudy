#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Row node for link list block
typedef struct rowNode
{
    char tv[100];
    struct rowNode *left;
    struct rowNode *right;
} TvNode;

TvNode *insert(TvNode *root, char tv[])
{
    if (!root)
    {
        root = (TvNode *)malloc(sizeof(TvNode));
        strcpy(root->tv, tv);
        root->left = NULL;
        root->right = NULL;
        return (root);
    }
    if (strcmp(root->tv, tv) > 0)
        root->left = insert(root->left, tv);
    else
    {
        if (strcmp(root->tv, tv) < 0)
            root->right = insert(root->right, tv);
    }
    return (root);
}

void displayAlphaOrder(TvNode *root)
{
    if (root != NULL)
    {
        displayAlphaOrder(root->left);
        printf(" %s\n", root->tv);
        displayAlphaOrder(root->right);
    }
}

TvNode *readTvs(TvNode *rootSortedLinkedList){
    // Opening the file pointer
    FILE *fp;
    // Line buffer size
    size_t len = 0;
    // Get row value into this variable
    char *line;
    // Opening the file and assigning it into file pointer fp
    fp = fopen("TVs.txt", "r");
    // Read the whole file
    while (getline(&line, &len, fp) != -1)
    {
        rootSortedLinkedList = insert(rootSortedLinkedList, strtok(line, "\n"));
    }
    // Closing the file pointer
    fclose(fp);
    return (rootSortedLinkedList);
}


void main()
{
    TvNode *rootSortedLinkedList = NULL;
    rootSortedLinkedList = readTvs(rootSortedLinkedList);
    displayAlphaOrder(rootSortedLinkedList);
}
