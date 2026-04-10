/*
Program Name: Vending Machine

Author: Taaruni Ananya

Program Description: This program will take three integers as input from the user that represent the number of bottles of drinks to purchase,
to restock, and to purchase afterward. 

This file will implement the four functions for VendingMachine's operations
*/

#include <stdio.h>
#include "VendingMachine.h"

void VendingMachine_Initialize(VendingMachine* vending_machine) {
    vending_machine->inventory = INITIAL_INVENTORY;
}

void VendingMachine_Purchase(VendingMachine* vending_machine, int bottle_count) {
    vending_machine->inventory -= bottle_count;
}
 
void VendingMachine_Restocks(VendingMachine* vending_machine, int bottle_count) {
    vending_machine->inventory += bottle_count;
}
 
void VendingMachine_InventoryReport(const VendingMachine* vending_machine) {
    printf("\nInventory: %d bottle\n", vending_machine->inventory);
}