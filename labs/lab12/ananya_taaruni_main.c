/*
Program Name: Vending Machine

Author: Taaruni Ananya

Program Description: This program will take three integers as input from the user that represent the number of bottles of drinks to purchase,
to restock, and to purchase afterward. 

This file will act as the main to handle these operations.
*/

#include <stdio.h>
#include "VendingMachine.h"

int main(void) {
    int first_purchase, restock, last_purchase;
    
    printf("\nPlease enter: your first purchase, restock count, and final purchase.\n");
    scanf("%d %d %d", &first_purchase, &restock, &last_purchase);

    VendingMachine vending_machine;

    VendingMachine_Initialize(&vending_machine);

    VendingMachine_Purchase(&vending_machine, first_purchase);

    VendingMachine_Restocks(&vending_machine, restock);

    VendingMachine_Purchase(&vending_machine, last_purchase);

    VendingMachine_InventoryReport(&vending_machine);

    return 0;
}