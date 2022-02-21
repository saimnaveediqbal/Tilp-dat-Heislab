#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>
#include "driver/elevio.h"
#include "door.h"

void openDoor(int floor, int* doorOpen, time_t* startTime){
    printf("Door opening")
    elevio_motorDirection(DIRN_STOP);
    elevio_floorIndicator(floor);
    elevio_doorOpenLamp(1);
    *doorOpen = 1;
    if(elevio_obstruction){
        *startTime = time(NULL);
        printf("Obstruction");
    }
}
int closeDoor(int floor, int* doorOpen){
    elevio_doorOpenLamp(0);
    printf("Door closing");
}