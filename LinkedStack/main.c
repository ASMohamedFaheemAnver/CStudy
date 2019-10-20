#include <stdio.h>
#include <stdlib.h>

typedef char StackEntryType;

typedef enum {true, false}Boolean;

typedef struct node{
    StackEntryType entry;
    struct node * next;
}Node;

typedef struct{
    int noOfElements;
    Node * top;
}Stack;

void createStack(Stack *stack){
    stack->noOfElements = 0;
    stack->top = NULL;
}

void push(Stack *stack, StackEntryType entry){
    Node *newNode;
    newNode = (Node*)malloc(sizeof(Node));
    newNode->entry = entry;
    newNode->next = stack->top;
    stack->top = newNode;
    stack->noOfElements++;
}

void pop(Stack *stack, StackEntryType *entry){
    // We don't need newNode to hold the top
    // Node *newNode;
    // newNode = stack->top;
    *entry = stack->top->entry;
    stack->noOfElements--;
    stack->top = stack->top->next;
    // stack->top = newNode->next;
    // free(newNode);
}

Boolean isStackEmpty(Stack *stack){
    return (stack->noOfElements==0);
}

void main() {
    int i;
    Stack stack;

    StackEntryType entry;

    createStack(&stack);
    char string[] = "I love RiFa";

    for (int i = 0; string[i]!='\0'; i++) {
        push(&stack, string[i]);
    }

    while (!isStackEmpty(&stack)){
        pop(&stack, &entry);
        putchar(entry);
    }
    printf("\n");
    printf("%d", stack.noOfElements);

}