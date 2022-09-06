#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Row node for link list block
typedef struct tvNode
{
    char tv[100];
    struct tvNode *left;
    struct tvNode *right;
} TvNode;

typedef struct tvQueueNode
{
    char tv[100];
    struct tvQueueNode *link;
} TvQueueNode;

TvQueueNode *queueFront = NULL;
TvQueueNode *queueRear = NULL;

int isQueueEmpty()
{
    if (queueFront == NULL && queueRear == NULL)
        return 1;
    else
        return 0;
}

void insertIntoQueue(char tv[])
{
    TvQueueNode *temp;
    temp = (TvQueueNode *)malloc(sizeof(TvQueueNode));
    strcpy(temp->tv, tv);
    temp->link = NULL;
    if (isQueueEmpty())
    {
        queueFront = temp;
        queueRear = temp;
    }
    else
    {
        queueRear->link = temp;
        queueRear = temp;
    }
}

TvNode *insertIntoLinkedList(TvNode *root, char tv[])
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
        root->left = insertIntoLinkedList(root->left, tv);
    else
    {
        if (strcmp(root->tv, tv) < 0)
            root->right = insertIntoLinkedList(root->right, tv);
    }
    return (root);
}

void displayLinkedListInAlphaOrder(TvNode *root)
{
    if (root != NULL)
    {
        displayLinkedListInAlphaOrder(root->left);
        printf("%s\n", root->tv);
        displayLinkedListInAlphaOrder(root->right);
    }
}

void displayQueue()
{
    if (isQueueEmpty())
    {
        printf("Queue is empty!\n");
    }
    else
    {
        TvQueueNode *p = queueFront;
        while (p != NULL)
        {
            printf("%s\n", p->tv);
            p = p->link;
        }
    }
}

void displayFrontQueue()
{
    if (isQueueEmpty())
    {
        printf("Queue is empty!\n");
    }
    else
    {
        printf("%s\n", queueFront->tv);
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
        line = strtok(line, "\n");
        rootSortedLinkedList = insertIntoLinkedList(rootSortedLinkedList, line);
    }
    // Closing the file pointer
    fclose(fp);
    return (rootSortedLinkedList);
}

void readTvOrders()
{
    // Opening the file pointer
    FILE *fp;
    // Line buffer size
    size_t len = 0;
    // Get row value into this variable
    char *line;
    // Opening the file and assigning it into file pointer fp
    fp = fopen("orders.txt", "r");
    // Read the whole file
    while (getline(&line, &len, fp) != -1)
    {
        line = strtok(line, "\n");
        insertIntoQueue(line);
    }
    // Closing the file pointer
    fclose(fp);
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
    readTvOrders();

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
            displayLinkedListInAlphaOrder(rootSortedLinkedList);
            printf("********** LINKEDLIST CONTENT **********\n");
            space();
            break;
        case 2:
            space();
            char tv[100];
            printf("Enter new tv to add to the stock : ");
            scanf(" %[^\n]", tv);
            insertIntoLinkedList(rootSortedLinkedList, tv);
            space();
            break;
        case 3:
            space();
            printf("********** NEXT ORDER **********\n");
            displayFrontQueue();
            printf("********** NEXT ORDER **********\n");
            space();
            break;
        case 4:
            space();
            printf("********** QUEUE CONTENT **********\n");
            displayQueue();
            printf("********** QUEUE CONTENT **********\n");
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
