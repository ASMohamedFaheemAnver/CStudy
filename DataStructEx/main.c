#include <stdio.h>
#include<string.h>

typedef struct book{
    char book_code[10];
    char title[30];
    int copies;
    int price;
}Book;

void inputData(Book *book){
    for(int i = 0; i<2; i++){
        printf("BOOK DETAILS NO : %d\n", i+1);
        printf("Enter book code : ");
        scanf("%s", book[i].book_code);
        printf("Enter book title : ");
        scanf("%s", book[i].title);
        printf("Enter no copies : ");
        scanf("%d", &book[i].copies);
        printf("Enter price : ");
        scanf("%d", &book[i].price);
    }
}

void displayData(Book book[]){
    for (int i = 0; i < 2; i++) {
        printf("BOOK ID : %s BOOK TITLE : %s BOOK COPIES : %d BOOK PRICE : %d\n",
                book[i].book_code, book[i].title,
                book[i].copies, book[i].price);
    }
}

void sortByTitle(Book *book, int choice){
    if(choice==1){
        printf("Sorted books list - 1 order of title\n");
        for (int i = 1; i < 2; i++) {
            Book temp = book[i];
            int j;
            for(j = i-1; j>=0 && strcmp(temp.title, book[j].title)<0; j--){
                book[j+1] = book[j];
            }
            book[j+1]=temp;
        }
        displayData(book);
    } else{
        printf("Sorted books list - 2 order of title\n");
        for (int i = 1; i < 2; i++) {
            Book temp = book[i];
            int j;
            for(j = i-1; j>=0 && strcmp(temp.title, book[j].title)>0; j--){
                book[j+1] = book[j];
            }
            book[j+1]=temp;
        }
        displayData(book);
    }
}

void sortByPrice(Book *book, int choice){
    if(choice==1){
        printf("Sorted books list - 1 order of price\n");
        for (int i = 1; i < 2; i++) {
            Book temp = book[i];
            int j;
            for(j = i-1; j>=0 && temp.price>book[j].price; j--){
                book[j+1] = book[j];
            }
            book[j+1]=temp;
        }
        displayData(book);
    } else{
        printf("Sorted books list - 2 order of price\n");
        for (int i = 1; i < 2; i++) {
            Book temp = book[i];
            int j;
            for(j = i-1; j>=0 && temp.price<book[j].price; j--){
                book[j+1] = book[j];
            }
            book[j+1]=temp;
        }
        displayData(book);
    }
}

void main() {
    Book book[5];
    inputData(&book);
    sortByTitle(&book, 1);
    sortByTitle(&book, 2);
    sortByPrice(&book, 1);
    sortByPrice(&book, 2);
}
