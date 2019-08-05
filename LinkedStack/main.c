#include <stdlib.h>
#include <stdio.h>

typedef  char Stack_Entry_Type;
typedef enum{true, false}Boolean;

typedef struct node{
    Stack_Entry_Type entry;
    struct node * Next;
}Node;

typedef struct{
    int no_ele;
    Node * top;
}stack;

void Create_Stack(stack *S){
    S->no_ele = 0;
    S->top = NULL;
}

Boolean Is_Stack_Empty(stack *S){
    return (S->no_ele==0);
}

void Push(stack *S, Stack_Entry_Type item){
    Node *np;
    np = (Node*)malloc(sizeof(Node));
    np->entry = item;
    np->Next = S->top;
    S->top = np;
    S->no_ele++;
}

void Pop(stack *S, Stack_Entry_Type *item){
    Node *np;
    np = (Node*)malloc(sizeof(Node));
    *item = S->top->entry;
    np = S->top;
    S->top = np->Next;
    S->no_ele--;
    free(np);
}

void main()
{
    int i;
    stack S;
    Stack_Entry_Type item;

    Create_Stack(&S);
    char Str[] = "I love rifa";

    for(i=0; Str[i]!='\0'; i++){
        Push(&S, Str[i]);
    }

    while(!Is_Stack_Empty(&S)){
        Pop(&S, &item);
        putchar(item);
    }
}