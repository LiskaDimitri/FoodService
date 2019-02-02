//
//  Manager.hpp
//  Final_Shopping_Project
//
//  Created by Dimitri Liska on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#ifndef Manager_hpp
#define Manager_hpp

#include <stdio.h>
//#include <cstdlib>

#include "User.hpp"
#include "Inventory.hpp"

class Manager : User {
    
private:
    //TO-DO if Time
    //Add extra generation
    //static int midStringID;
    
    std::string preStringID = "MANAGER_ID_";
    Inventory* inventory;
    
    void setUserIdNumber(std::string userIdNumber);
public:
    Manager(std::string managerId, std::string managerName, Inventory* inventory);
    
    std::string getIdNumber();
    
    void restockingInventory(std::string itemName, int itemQuantity, double itemPrice);
    
    void updateInventoryPrices(std::string itemName, double itemPrice);
    
    void displayInventoryReport();
    
    void displayInventoryReport(Inventory* inventory);

};

#endif /* Manager_hpp */
