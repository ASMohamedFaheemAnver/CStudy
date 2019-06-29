#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>



int main()
{
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

    return 0;
}

