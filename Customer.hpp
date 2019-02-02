//
//  Customer.hpp
//  Final_Shopping_Project
//
//  Created by Dimitri Liska on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#ifndef Customer_hpp
#define Customer_hpp

#include <stdio.h>
#include <sstream>
#include <iomanip>
#include <algorithm>
//#include <cstdlib>

#include "User.hpp"
#include "Cart.hpp"

class Customer : User {
    
private:
    //TODO - IF TIME
    //extra implement string random generation if time
    //static int midStringID;
    
    std::string preStringID = "CUSTOMER_ID_";
    double customerDebitBalance;
//    Shopping_not_curently_used* shoppingList_Pointer;
    Cart* cart;
    
    void setUserIdNumber(std::string userIdNumber);
    
public:
    Customer(std::string customerId, std::string customerName, double customerBalance);
    
    std::string getIdNumber();
    
    double getCustomerDebitBalance();
    
    void addMoneyToAccount(double amount);
    
    std::string displayAccountInformation();
    
    bool retrieveShoppingListFile();
    
    Cart retrieveSavedCart(std::string customerId);
    
    void updateCartContents(std::string itemAction);
    
    void displayCartReport();
    
    bool checkoutCart();
    
};

#endif /* Customer_hpp */
