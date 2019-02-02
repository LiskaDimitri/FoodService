//
//  System.hpp
//  Final_Shopping_Project
//
//  Created by MrScargs on 11/19/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#ifndef System_hpp
#define System_hpp

#include "User.hpp"
#include "Cart.hpp"
#include "Inventory.hpp"
#include "Item.hpp"
#include "Coupon.hpp"
#include <stdio.h>

class System : User {
    
private:
    Cart* sysCar;
    Inventory* sysInv;
public:
    System();
    
    ~System();
    
    void isItemAvailable(std::string itemName,int Quantity);
    
};

#endif /* System_hpp */
