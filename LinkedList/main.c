#include <stdio.h>
#include <stdlib.h>

// The type of the linked list entry or data
typedef char ListEntryType;

typedef enum {true, false}Boolean;

typedef struct node{
    ListEntryType entry;
    struct node *next;
    struct node *previous;
}Node;

typedef struct{
    Node * topNode;
    int numberOfElement;
}LinkedList;

// This function will initialize the linkedList
void createLinkedList(LinkedList *linkedList){
    // (*linkedList).topNode = NULL;
    // (*linkedList).numberOfElement = 0;
    linkedList->topNode = NULL;
    linkedList->numberOfElement = 0;
}

void push(LinkedList *linkedList, ListEntryType entry){
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));

    newNode->entry = entry;

    if (linkedList->topNode==NULL){
        linkedList->topNode = newNode;
    } else {
        newNode->previous = linkedList->topNode;
        linkedList->topNode->next = newNode;
        linkedList->topNode = newNode;
    }

    linkedList->numberOfElement++;
}

// This function will return the length of the linked list
Boolean isListEmpty(LinkedList *linkedList){
    return (linkedList->numberOfElement==0);
}


// This function will pop the top element (LIFO)
ListEntryType popTop(LinkedList *linkedList){
    char poppedData = linkedList->topNode->entry;
    linkedList->topNode = linkedList->topNode->previous;
    linkedList->numberOfElement--;

    if (!isListEmpty(linkedList)){
        linkedList->topNode->next = NULL;
    }

    return  poppedData;
}

// Check weather the given entry is exist or not
// If the given entry exist the function will return true otherwise false
Boolean isElementExist(LinkedList *linkedList, ListEntryType entry){
    Node * tempTop;
    tempTop = linkedList->topNode;

    while (tempTop!=NULL){
        if (tempTop->entry==entry){
            return true;
        } else{
            tempTop = tempTop->previous;
        }
    }
    return false;
}

// This given function will pop a given entry from the given linkedList
void popGivenData(LinkedList *linkedList, ListEntryType entry){
    if ((linkedList->topNode->next==NULL)&&(linkedList->topNode->entry==entry)){
        linkedList->topNode->previous->next = NULL;
        linkedList->topNode = linkedList->topNode->previous;
        linkedList->numberOfElement--;
    } else{
        Node *tempNode;
        tempNode = linkedList->topNode;
        while (tempNode->previous!=NULL){
            if (tempNode->entry==entry){
                tempNode->next->previous = tempNode->previous;
                tempNode->previous->next = tempNode->next;
                linkedList->numberOfElement--;
            }
            tempNode = tempNode->previous;
        }
        if (tempNode->entry==entry){
            tempNode->next->previous = NULL;
            tempNode->next = NULL;
            linkedList->numberOfElement--;
        }
        tempNode = NULL;
        free(tempNode);
    }
}

// This function will pop the LastElement
ListEntryType popLast(LinkedList *linkedList){
    Node * tempNode;
    tempNode = linkedList->topNode;
    while (tempNode->previous!=NULL){
        tempNode = tempNode->previous;
    }
    char poppedData = tempNode->entry;
    if (tempNode->next!=NULL){
        tempNode->next->previous = NULL;
    }
    linkedList->numberOfElement--;
    free(tempNode);
    return poppedData;
}

void main(){
    LinkedList linkedList;
    createLinkedList(&linkedList);

    push(&linkedList, 'c');
    push(&linkedList, 'b');
    push(&linkedList, 'd');

    printf("%c", popLast(&linkedList));
    printf("%c", popLast(&linkedList));
    printf("%c", popLast(&linkedList));
}