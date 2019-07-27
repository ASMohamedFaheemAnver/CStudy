/*
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

/*
void update(int *a, int *b){
    int temp = *a;
    *a = *a + *b;
    *b = abs(*b - temp);
}


int main()
{
    /*
    int a, b;
    scanf("%d\n%d", &a, &b);

    switch (a){
        case 1:
            printf("one\n");
            if (b==1){
                break;
            }

        case 2:
            printf("two\n");
            if (b==2){
                break;
            }

        case 3:
            printf("three\n");
            if (b==3){
                break;
            }

        case 4:
            printf("four\n");
            if (b==4){
                break;
            }

        case 5:
            printf("five\n");
            if (b==5){
                break;
            }

        case 6:
            printf("six\n");
            if (b==6){
                break;
            }

        case 7:
            printf("seven\n");
            if (b==7){
                break;
            }

        case 8:
            printf("eight\n");
            if (b==8){
                break;
            }

        case 9:
            printf("nine\n");
            if (b==9){
                break;
            }

        default:
            for (int i = 10; i <= b; i++) {
                if(i%2!=0){
                    printf("odd\n");
                } else{
                    printf("even\n");
                }
            }
    }

    /*
    int n;
    scanf("%d", &n);

    int x;
    int sum = 0;
    while (n!=0){
        x = n%10;
        n = (n-x)/10;
        sum = sum + x;
    }

    printf("%d", sum);

    int a, b;
    int *pa = &a, *pb = &b;

    scanf("%d %d", &a, &b);
    update(pa, pb);
    printf("%d\n%d", a, b);

    return 0;
}



#include <assert.h>
#include <limits.h>
#include <math.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* readline();



int main()
{
    char* n_endptr;
    char* n_str = readline();
    int n = strtol(n_str, &n_endptr, 10);

    if (n_endptr == n_str || *n_endptr != '\0') { exit(EXIT_FAILURE); }
    else if(n==1) printf("one");
    else if(n==2) printf("two");
    else if(n==3) printf("three");
    else if(n==4) printf("four");
    else if(n==5) printf("five");
    else if(n==6) printf("six");
    else if(n==7) printf("seven");
    else if(n==8) printf("eight");
    else if(n==9) printf("nine");
    else  printf("Greater than 9");

    return 0;
}

char* readline() {
    size_t alloc_length = 1024;
    size_t data_length = 0;
    char* data = malloc(alloc_length);

    while (true) {
        char* cursor = data + data_length;
        char* line = fgets(cursor, alloc_length - data_length, stdin);

        if (!line) { break; }

        data_length += strlen(cursor);

        if (data_length < alloc_length - 1 || data[data_length - 1] == '\n') { break; }

        size_t new_length = alloc_length << 1;
        data = realloc(data, new_length);

        if (!data) { break; }

        alloc_length = new_length;
    }

    if (data[data_length - 1] == '\n') {
        data[data_length - 1] = '\0';
    }

    data = realloc(data, data_length);

    return data;
}






int main() {
    int a;
    long b;
    char c;
    float d;
    double e;

    scanf("%d %ld %c %f %lf", &a, &b, &c, &d, &e);
    printf("%d\n%ld\n%c\n%.3f\n%.9lf", a, b, c, d, e);
    return 0;
}





void calculate_the_maximum(int n, int k) {
    int maxAnd = 0;
    int maxOr = 0;
    int maxXor = 0;

    for (int i=1; i<=n; i++) {
        for (int j=i+1; j<=n; j++) {
            if (((i&j) > maxAnd) && ((i&j) < k)) {
                maxAnd = i&j;
            }
            if (((i|j) > maxOr) && ((i|j) < k)) {
                maxOr = i|j;
            }
            if (((i^j) > maxXor) && ((i^j) < k)) {
                maxXor = i^j;
            }
        }
    }

    printf("%d\n%d\n%d\n", maxAnd, maxOr, maxXor);
}

int main() {
    int n, k;

    scanf("%d %d", &n, &k);
    calculate_the_maximum(n, k);

    return 0;
}






int main()
{

    int n;
    scanf("%d", &n);
    int len = n*2 - 1;
    for(int i=0;i<len;i++){
        for(int j=0;j<len;j++){
            int min = i < j ? i : j;
            min = min < len-i ? min : len-i-1;
            min = min < len-j-1 ? min : len-j-1;
            printf("%d ", n-min);
        }
        printf("\n");
    }
    return 0;
}

/*


int main() {

    int n;
    int sum = 0;
    int x;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        sum += x;
    }

    printf("%d", sum);
    return 0;
}
*/


// C program to demonstrate working of Semaphores
// https://stackoverflow.com/questions/45601811/undefined-reference-to-pthread-clion
//target_link_libraries(${PROJECT_NAME} pthread)
#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

sem_t mutex;

void* thread(void* arg)
{
    //wait
    sem_wait(&mutex);
    printf("\nEntered..\n");

    //critical section
    sleep(4);

    //signal
    printf("\nJust Exiting...\n");
    sem_post(&mutex);
}


int main()
{
    sem_init(&mutex, 0, 1);
    pthread_t t1,t2;
    pthread_create(&t1,NULL,thread,NULL);
    sleep(2);
    pthread_create(&t2,NULL,thread,NULL);
    pthread_join(t1,NULL);
    pthread_join(t2,NULL);
    sem_destroy(&mutex);
    return 0;
}