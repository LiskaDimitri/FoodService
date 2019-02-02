//
//  Item.hpp
//  Final_Shopping_Project
//
//  Created by MrScargs on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#ifndef Item_hpp
#define Item_hpp

#include <stdio.h>
#include <string>

class Item {
    
private:
    int itemSkuNumber;
    std::string itemName;
    std::string itemDescription;
    double itemPrice;
    bool isCoupon;
    
public:
    Item(int itemSkuNumber, std::string itemName, std::string itemDescription,double itemPrice, bool itemCoupon);
    
    int getItemSkuNumber();
    
    void setItemSkuNumber(int itemSkuNumber);
    
    std::string getItemName();
    
    void setItemName(std::string itemName);
    
    double getItemPrice();
    
    void setItemPrice(double itemPrice);
    
    std::string getItemDescription();
    
    void setItemDescription(std::string itemDescription);
    
    bool isItemCoupon();
    
    void setItemCoupon(bool itemCoupon);
    
//    bool operator < (const Item& item)const;
    
//    template<> struct std::less<Item>;
};

#endif /* Item_hpp */
