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
        printf("%s\n", root->tv);
        displayAlphaOrder(root->right);
    }
}

TvNode *readTvs(TvNode *rootSortedLinkedList)
{
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

void menu()
{
    printf("********** INSTRUCTIONS **********\n");
    printf("Choose between following option to perform actions (Assuming you only type int)!\n");
    printf("1. Display the current stock of TVs\n");
    printf("2. Add a new TV to stock\n");
    printf("3. Display next order information\n");
    printf("4. Display all orders\n");
    printf("5. Add order to queue\n");
    printf("6. Process the next order\n");
    printf("7. Process the next order\n");
    printf("8. Display info of last order\n");
    printf("9. Update TV file\n");
    printf("10. Quit\n");
    printf("********** INSTRUCTIONS **********\n");
}

void space()
{
    printf("\n\n");
}

void main()
{
    TvNode *rootSortedLinkedList = NULL;
    rootSortedLinkedList = readTvs(rootSortedLinkedList);

    // Make decision with user choice
    int dontExit = 1;
    while (dontExit)
    {
        menu();
        space();
        int choice = -1;
        printf("Enter your choice: ");
        // Get user input
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            space();
            printf("********** LINKEDLIST CONTENT **********\n");
            displayAlphaOrder(rootSortedLinkedList);
            printf("********** LINKEDLIST CONTENT **********\n");
            space();
            break;
        case 2:
            space();
            printf("********** LINKEDLIST CONTENT **********\n");
            displayAlphaOrder(rootSortedLinkedList);
            printf("********** LINKEDLIST CONTENT **********\n");
            space();
            break;
        case 10:
            // Exit the program
            printf("Exiting!");
            dontExit = 0;
            break;
        }
    }
}
