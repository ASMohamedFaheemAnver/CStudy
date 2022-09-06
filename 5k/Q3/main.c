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

int isRemoved = -1;

#define MAX 10
typedef enum
{
    TRUE,
    FALSE
} boolean;
char successfulOrders[MAX][100];
int top = -1;

boolean isStackFull()
{
    return (top == MAX - 1);
}

boolean isStackEmpty()
{
    return (top == -1);
}

void pushSuccessfulOrders(char tv[])
{
    if (isStackFull())
        printf("Order stack overflow!\n");
    else
    {
        top++;
        strcpy(successfulOrders[top], tv);
    }
}

char *popSuccessfulOrders()
{
    if (isStackEmpty())
    {
        printf("Order stack is empty!\n");
        return NULL;
    }
    else
    {
        return (successfulOrders[top--]);
    }
}

void displayLastSuccessfulOrder()
{
    printf("********** LAST SUCCESSFUL ORDER **********\n");
    if (isStackEmpty())
        printf("Successful order stack is empty!\n");
    else
    {
        printf("%s\n", successfulOrders[top]);
    }
    printf("********** LAST SUCCESSFUL ORDER **********\n");
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

void clearTvsText()
{
    FILE *fp;
    // Opening file with name output.txt in writing mode
    fp = fopen("demo.txt", "w");
    // Write the file with concatenated string
    fprintf(fp, "%s", "");
    // Closing the file pointer
    fclose(fp);
}

void writeLinkedListInAlphaOrder(TvNode *root)
{
    if (root != NULL)
    {
        writeLinkedListInAlphaOrder(root->left);
        FILE *fp;
        fp = fopen("demo.txt", "a");
        fprintf(fp, "%s\n", root->tv);
        fclose(fp);
        writeLinkedListInAlphaOrder(root->right);
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

TvNode *minValue(TvNode *root)
{
    if (!root)
        return NULL;
    if (root->left == NULL)
        return root;
    else
        return minValue(root->left);
}

TvNode *removeFromTvLinkedList(TvNode *root, char orderedTv[100])
{
    if (!root)
        return NULL;
    if (strcmp(orderedTv, root->tv) < 0)
        root->left = removeFromTvLinkedList(root->left, orderedTv);
    if (strcmp(orderedTv, root->tv) > 0)
        root->right = removeFromTvLinkedList(root->right, orderedTv);
    else
    {
        if (strcmp(root->tv, orderedTv) != 0)
            // NOT FOUND
            return root;

        isRemoved = 1;
        TvNode *temp;
        if (root->left == NULL)
        {
            temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            temp = root->left;
            free(root);
            return temp;
        }
        temp = minValue(root->right);
        strcpy(root->tv, temp->tv);
        root->right = removeFromTvLinkedList(root->right, temp->tv);
        return root;
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

char *returnFrontQueue()
{
    return queueFront->tv;
}

void removeFrontQueue()
{
    if (isQueueEmpty())
    {
        printf("Queue is empty!\n");
    }
    else
    {
        TvQueueNode *p = queueFront;
        queueFront = queueFront->link;
        p->link = NULL;
        if (queueFront == NULL)
        {
            queueRear = NULL;
        }
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
    printf("7. Cancel last order\n");
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
            if(rootSortedLinkedList != NULL){
                displayLinkedListInAlphaOrder(rootSortedLinkedList);
            } else{
                printf("Tv stock is empty!\n");
            }
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
        case 5:
            space();
            char orderTv[100];
            printf("Enter new your new order tv name : ");
            scanf(" %[^\n]", orderTv);
            insertIntoQueue(orderTv);
            space();
            break;
        case 6:
            space();
            isRemoved = -1;
            char *frontOrder = returnFrontQueue();
            rootSortedLinkedList = removeFromTvLinkedList(rootSortedLinkedList, frontOrder);
            if (isRemoved == 1)
            {
                removeFrontQueue();
                printf("Order successfully processed!");
                pushSuccessfulOrders(frontOrder);
            }
            else
            {
                removeFrontQueue();
                printf("Order can't be processed!");
            }
            space();
            break;
        case 7:
            space();
            char *order = popSuccessfulOrders();
            if (order != NULL)
            {
                insertIntoLinkedList(rootSortedLinkedList, order);
                printf("Order cancelled successfully!");
            }
            space();
            break;
        case 8:
            space();
            displayLastSuccessfulOrder();
            space();
            break;
        case 9:
            space();
            clearTvsText();
            writeLinkedListInAlphaOrder(rootSortedLinkedList);
            printf("TVs.txt updated!");
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
