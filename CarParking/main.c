#include <stdio.h>
#include <stdlib.h>

typedef enum
{
    false,
    true
} bool;

struct v_time
{
    int hour;
    int minute;
};

struct vehicle
{
    char car_no[7];
    char colour[10];
    char width;
    bool parked;
    struct v_time in_time;
    struct v_time out_time;
} vh1;

struct park
{
    char size;
    bool occupy;
    struct vehicle vh;
};

struct park *pk_slot;

void slot_alloc(int i) {
    struct park temp_pk_slot[i];
    for(int j = 0; j<i; j++){
        printf("Enter parking slot %d/%d size : ", j+1, i);
        scanf("%s", &temp_pk_slot[j].size);
        temp_pk_slot[j].occupy = true;
    }
    pk_slot = temp_pk_slot;
}

void display(int i){
    printf("Size : %c | Occupy %s\n", pk_slot[i].size, pk_slot[i].occupy == true ? "true" : "false");
}

int main()
{
    int i = 5;
    slot_alloc(i);
    for(int k = 0; k<i; k++){
        display(k);
    }
    return 0;
}