/*
Program Name: Vending Machine

Author: Taaruni Ananya

Program Description: This program will take three integers as input from the user that represent the number of bottles of drinks to purchase,
to restock, and to purchase afterward. 

This file will define the structs for VendingMachine and declare the functions.
*/

#define INITIAL_INVENTORY 20

typedef struct {
    int inventory;
} VendingMachine;

void VendingMachine_Initialize(VendingMachine* vending_machine);

void VendingMachine_Purchase(VendingMachine* vending_machine, int bottle_count);

void VendingMachine_Restocks(VendingMachine* vending_machine, int bottle_count);

void VendingMachine_InventoryReport(const VendingMachine* vending_machine);