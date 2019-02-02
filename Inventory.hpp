//
//  Inventory.hpp
//  Final_Shopping_Project
//
//  Created by MrScargs on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#ifndef Inventory_hpp
#define Inventory_hpp

#include <stdio.h>
#include <map>
#include "ProductList.hpp"
#include "Item.hpp"

class Inventory : ProductList {
    
private:
//    std::map<std::string, std::tuple<Item*, int>> inventoryMap;
//    std::map<std::string, std::tuple<Item*, int>>::iterator iter;
    
    std::map<std::string, std::pair<Item, int>> inventoryMap;
    std::map<std::string, std::pair<Item, int>>::iterator iter;
//    std::map<class string, class Item, class Compare = std::less<string>> inventoryMap ;
    
    int itemQuantity;
    double inventoryTotalValue;
    int inventoryTotalQty;
    
    std::fstream inOutInventory;
    void updateInventoryFile(std::string itemName);
    
public:
    Inventory();
    
    ~Inventory();
    
    void print();
    
    std::map<std::string, std::pair<Item, int>>* getInventoryMap();
    
    void addExistingItem(std::string itemName, int quantity, double price);
    
    void addNewItem(std::string itemName, int itemSkuNumber, std::string itemDescription, double itemPrice, bool itemCoupon, int quantity);
    
    void addNewItem(Item item, int itemQuantity, double itemPrice);
    
    void addItemQuantity(std::string itemName, int numberOfItems);
    
    void removeItemQuantity(std::string itemName, int numberOfItems);
    
    void setItemPrice(std::string itemName, double price);
    
    bool isItemAvailable(std::string itemName, int quantity);
    
    ////TODO if time
//    double getInventoryTotalValue();
//
//    void setInventoryTotalValue(double inventoryTotalValue);
    
//    int getInventoryTotalQty();
//
//    void setInventoryTotalQty(int inventoryTotalQty);
};


#endif /* Inventory_hpp */
