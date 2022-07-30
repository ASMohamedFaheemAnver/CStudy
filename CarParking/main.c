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
Vehicle removed_vehicle;

void slot_alloc(int i) {
    pk_slot = malloc(i*sizeof (Park));
    for(int j = 0; j<i; j++){
        printf("Enter parking slot %d/%d size : ", j+1, i);
        scanf("%s", &pk_slot[j].size);
        pk_slot[j].occupy = false;
    }
}

void display(int i){
    printf("Slot Size : %c | Slot Occupied : %s ", pk_slot[i].size, pk_slot[i].occupy == true ? "true" : "false");
    if(pk_slot[i].occupy == true){
        printf("| Vehicle No : %s | Vehicle Colour : %s | Vehicle Width : %c | Vehicle in time : %d:%d", pk_slot[i].vh.car_no, pk_slot[i].vh.colour, pk_slot[i].vh.width, pk_slot[i].vh.in_time.hour, pk_slot[i].vh.in_time.minute);
    } else{
        printf("| No vehicle parked!");
    }
    printf("\n");
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

void remove_vehicle(int i){
    pk_slot[i].occupy =false;
    removed_vehicle = pk_slot[i].vh;
    printf("Enter out time of the vehicle(%s) in format hh mm (eg. 11 45)  : ", removed_vehicle.car_no);
    scanf("%d", &removed_vehicle.out_time.hour);
    scanf("%d", &removed_vehicle.out_time.minute);
    printf("Removed vehicle with : Vehicle No : %s | Vehicle Colour : %s | Vehicle Width : %c | Vehicle in time : %d:%d | Vehicle out time %d:%d\n", removed_vehicle.car_no, removed_vehicle.colour, removed_vehicle.width, removed_vehicle.in_time.hour, removed_vehicle.in_time.minute, removed_vehicle.out_time.hour, removed_vehicle.out_time.minute);
}

bool park_slot(int i){
    if(pk_slot[i].occupy == true){
        return  false;
    }
    if(pk_slot[i].size == vehicle.width){
        pk_slot[i].occupy = true;
        vehicle.parked = true;
        pk_slot[i].vh = vehicle;
        return  true;
    }
    return false;
}

bool is_parked(int i, char car_no[]){
    return strcmp(car_no, pk_slot[i].vh.car_no) == 0;
}

void main()
{
    int lastDigitOfRegistrationNumber = 8;
    int i = 10+lastDigitOfRegistrationNumber;
    slot_alloc(i);
    printf("################ PARKING STOP CURRENT STATE ################\n");
    for(int k = 0; k<i; k++){
        display(k);
    }
    printf("#############################################################\n");
    bool exit = false;
    while (exit != true){
        char v_no[7];
        printf("Note: If you enter parked vehicle, we will initialize remove them from slot\n");
        printf("Enter vehicle number you want to park or remove : ");
        scanf("%s", v_no);

        bool isAlreadyParked = false;
        int parkedVehicleIndex = -1;
        for (int j = 0; j < i; j++) {
            isAlreadyParked = is_parked(j, v_no);
            if(isAlreadyParked == true){
                parkedVehicleIndex = j;
                break;
            }
        }

        if(!isAlreadyParked){
            vehicle_detail(v_no);
        } else{
            remove_vehicle(parkedVehicleIndex);
        }

        bool isParked = false;
        for (int j = 0; j < i && isAlreadyParked != true; j++) {
            isParked = park_slot(j);
            if(isParked == true){
               break;
            }
        }

        if(isParked == true){
            printf("Parked vehicle with no : %s!\n", vehicle.car_no);
        } else if(isAlreadyParked == false){
            printf("Can't park vehicle with no : %s!\n", vehicle.car_no);
        }

        printf("################ PARKING STOP CURRENT STATE ################\n");
        for(int k = 0; k<i; k++){
            display(k);
        }
        printf("#############################################################\n");
    }
}