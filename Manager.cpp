//
//  Manager.cpp
//  Final_Shopping_Project
//
//  Created by Dimitri Liska on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#include "Manager.hpp"

Manager::Manager(std::string managerId, std::string managerName, Inventory* inventory) {
    setUserIdNumber(managerId);
    this->userName = managerName;
    this->inventory = inventory;
}

std::string Manager::getIdNumber() {
    return this->userIdNumber;
}

void Manager::setUserIdNumber(std::string userIdNumber) {
    //TO-DO if Time
    //Add extra generation
    this->userIdNumber = preStringID + userIdNumber;
}

void Manager::restockingInventory(std::string itemName, int itemQuantity, double itemPrice) {
    inventory->addExistingItem(itemName, itemQuantity, itemPrice);

}

void Manager::updateInventoryPrices(std::string itemName, double itemPrice) {
    this->inventory->setItemPrice(itemName, itemPrice);
}

void Manager::displayInventoryReport(){
    this->displayInventoryReport(this->inventory);
}

void Manager::displayInventoryReport(Inventory* inventory) {
    inventory->print();
}

//TODO if time add a remove from inventory function
