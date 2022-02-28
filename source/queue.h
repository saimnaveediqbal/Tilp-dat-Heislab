/**
 * @file queue.h
 * @brief Function for managing the floor queue and sending floor destination to elevator
 * @version 0.1
 * @date 2022-02-22
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once
#include <elevio.h>

typedef enum{
    NO_ORDER = 0,
    HALL_UP = 1,
    HALL_DOWN = 2,
    HALL_UP_AND_DOWN = 3,
    CAB = 4
} OrderType; 


OrderType floorOrders[N_FLOORS] = {NO_ORDER, NO_ORDER, NO_ORDER, NO_ORDER};

/**
 * @brief sets the elevator destination based on elevators movement and position and order array
 *
 * @param direction direction of elevators movement
 * @param position position of the elevator, either at or inbetween floors
 * 
 * @return elevator desination

 *
 */
int getDestination(MotorDirection direction, int lastFloor);
/**
 * @brief adds floor order to orders array when a button is pressed
 * 
 * @param requestedFloor 
 * @param btnType 
 * 
 */

void getClosestFloor(int possibleDestinations[], int lastFloor);

void addFloorOrder(int requestedFloor, ButtonType btnType);
/**
 * @brief removes an order from the order array. Used when elevator has arrived
 * 
 * @param floor the floor arrived at
 */
void removeFloorOrder(int floor);
/**
 * @brief removes all orders from the orders array. Used when emergency mode activates
 * 
 */
void emptyFloorOrders();




