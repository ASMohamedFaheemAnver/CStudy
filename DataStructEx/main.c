#include <stdio.h>
#include<string.h>

typedef struct book{
    char book_code[10];
    char title[30];
    int copies;
    int price;
}Book;

void inputData(Book *book){
    for(int i = 0; i<5; i++){
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

void writer(Book book[]){
    char text[500];
    for (int i = 0; i < 5; i++) {
        strcat(text, "BOOK ID : ");
        strcat(text, book[i].book_code);
        strcat(text, " BOOK TITLE : ");
        strcat(text, book[i].title);
        strcat(text, " BOOK COPIES : ");
        char copies[10];
        sprintf(copies, "%d", book[i].copies);
        strcat(text, copies);
        strcat(text, " BOOK PRICE : ");
        char price[10];
        sprintf(price, "%d", book[i].price);
        strcat(text, price);
        strcat(text, "\n");
    }

    FILE * fp;
    fp = fopen ("/home/ubunturifa/Desktop/GitHub/CStudy/DataStructEx/Output.txt","w");
    fprintf (fp, "%s", text);
    fclose(fp);
}

void displayData(Book book[]){
    for (int i = 0; i < 5; i++) {
        printf("BOOK ID : %s BOOK TITLE : %s BOOK COPIES : %d BOOK PRICE : %d\n",
                book[i].book_code, book[i].title,
                book[i].copies, book[i].price);
    }
}

void sortByTitle(Book *book, int choice){
    if(choice==1){
        printf("Sorted books list - 1 order of title\n");
        for (int i = 1; i < 5; i++) {
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
        for (int i = 1; i < 5; i++) {
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
        for (int i = 0; i < 5; i++) {
            int smallest = i;
            for (int j = i+1; j < 1; j++) {
                if (book[smallest].price<book[j].price){
                    smallest = j;
                }
            }
            if (smallest!=i){
                Book temp = book[i];
                book[i] = book[smallest];
                book[smallest] = temp;
            }
        }
        displayData(book);
    } else{
        printf("Sorted books list - 2 order of price\n");
        for (int i = 0; i < 5; i++) {
            int smallest = i;
            for (int j = i+1; j < 1; j++) {
                if (book[smallest].price>book[j].price){
                    smallest = j;
                }
            }
            if (smallest!=i){
                Book temp = book[i];
                book[i] = book[smallest];
                book[smallest] = temp;
            }
        }
        displayData(book);
    }
}

void mainMenu(){
    int choice;
    while (choice!=5){
        printf("Sorting based on\n"
               "1. Ascending order of title\n"
               "2. Descending order of title\n"
               "3. Ascending order of price\n"
               "4. Descending order of title\n"
               "5. Exit the program\n"
               "Enter your choice (1-5) : ");
        scanf("%d", &choice);
        Book book[5];
        switch (choice){
            case 1:
                inputData(&book);
                sortByTitle(book, 1);
                writer(book);
                break;
            case 2:
                inputData(&book);
                sortByTitle(book, 2);
                writer(book);
                break;
            case 3:
                inputData(&book);
                sortByPrice(book, 1);
                writer(book);
                break;
            case 4:
                inputData(&book);
                sortByPrice(book, 2);
                writer(book);
                break;
            default:
                break;
        }
    }
}

void main() {
    mainMenu();
}
