#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum
{
    false,
    true
} bool;

typedef struct time
{
    int hour;
    int minute;
} Time;

typedef struct vehicle
{
    char car_no[7];
    char colour[10];
    char width;
    bool parked;
    struct time in_time;
    struct time out_time;
} Vehicle;

typedef struct park
{
    char size;
    bool occupy;
    struct vehicle vh;
} Park;

Park *pk_slot;
Vehicle vehicle;

void slot_alloc(int i) {
    pk_slot = malloc(i*sizeof (Park));
    for(int j = 0; j<i; j++){
        printf("Enter parking slot %d/%d size : ", j+1, i);
        scanf("%s", &pk_slot[j].size);
        pk_slot[j].occupy = false;
    }
}

void display(int i){
    printf("Size : %c | Occupy : %s\n", pk_slot[i].size, pk_slot[i].occupy == true ? "true" : "false");
}

void vehicle_detail(char v_no[7]){
    strcpy(vehicle.car_no, v_no);
    printf("Enter colour of the vehicle(%s)  : ", vehicle.car_no);
    scanf("%s", vehicle.colour);
    printf("Enter width of the vehicle(%s)  : ", vehicle.car_no);
    scanf("%s", &vehicle.width);
    printf("Enter in time of the vehicle(%s) in format hh mm (eg. 11 45)  : ", vehicle.car_no);
    scanf("%d", &vehicle.in_time.hour);
    scanf("%d", &vehicle.in_time.minute);
}

bool park_slot(int i){
    if(pk_slot[i].occupy == true){
        return  false;
    }
    if(pk_slot[i].size == vehicle.width){
        pk_slot[i].occupy = true;
        pk_slot[i].vh = vehicle;
        return  true;
    }
    return false;
}

void main()
{
    int lastDigitOfRegistrationNumber;
    printf("Enter last number of your registration number : ");
    scanf("%d", &lastDigitOfRegistrationNumber);
    int i = 0+lastDigitOfRegistrationNumber;
    slot_alloc(i);
    for(int k = 0; k<i; k++){
        display(k);
    }
    bool exit = false;
    while (exit != true){
        char v_no[7];
        printf("Enter vehicle number you want to park  : ");
        scanf("%s", v_no);
        vehicle_detail(v_no);
        bool isParked = false;
        for (int j = 0; j < i; j++) {
            isParked = park_slot(j);
            if(isParked == true){
               break;
            }
        }
        if(isParked == true){
            printf("Parked %s!\n", vehicle.car_no);
        } else{
            printf("Can't park %s!\n", vehicle.car_no);
        }
        for(int k = 0; k<i; k++){
            display(k);
        }
    }
}