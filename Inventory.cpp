//
//  Inventory.cpp
//  Final_Shopping_Project
//
//  Created by Dimitri Liska on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#include "Inventory.hpp"

Inventory::Inventory(){
    
}
Inventory::~Inventory(){
    
}

//WORKS
void Inventory::print() {
    using namespace std;
    
    cout << "---------- Inventory Repport: ----------" << endl;
        for (auto& item : inventoryMap){

            std::cout << std::setw(12) << std::left << item.first << " { " <<
            "Sku: " << std::setw(4) << std::left << item.second.first.getItemSkuNumber() << " -|- " <<
            "Desc: " << std::setw(20) << std::left << item.second.first.getItemDescription() << " -|- " <<
            "Price: " << std::setw(6) << std::left << setprecision(3) << item.second.first.getItemPrice() << " -|- " <<
            "Quantity: " << std::setw(5) << std::left << item.second.second << " } " << endl;
    }
    
}

std::map<std::string, std::pair<Item, int>>* Inventory::getInventoryMap() {
    return &inventoryMap;
}

void Inventory::addExistingItem(std::string itemName, int itemQuantity, double itemPrice){
    
    iter = inventoryMap.find(itemName);
    if(iter == inventoryMap.end()){
        
        std::cout << "Item not found, please enter information to add item in database: " << std::endl;
        std::cout << "SKU Number and Item Description: ";
        int itemSkuNumber;
        std::string itemDescription;
        std::cin >> itemSkuNumber >> itemDescription;
        //TODO - Check if SKU number already exist.
        
        bool itemCoupon = false;
        
        addNewItem(itemName, itemSkuNumber, itemDescription, itemPrice, itemCoupon, itemQuantity);
        
//        Item item(itemSkuNumber, itemName, itemDescription, itemPrice, itemCoupon);
//        auto pair = std::make_pair(item , itemQuantity);
//
//        inventoryMap.insert(std::make_pair(itemName, pair));

    }else{
        addItemQuantity(itemName, itemQuantity);
        //        double currentPrice = inventoryMap.find(itemName)->second.first.getItemPrice();
        
        double currentPrice = iter->second.first.getItemPrice();
        if(currentPrice != itemPrice){
            setItemPrice(itemName, itemPrice);
        }
    }
}

void Inventory::addNewItem(std::string itemName, int itemSkuNumber, std::string itemDescription, double itemPrice, bool itemCoupon, int quantity) {
    
    Item item(itemSkuNumber, itemName, itemDescription, itemPrice, itemCoupon);
    auto pair = std::make_pair(item , itemQuantity);
    
    inventoryMap.insert(std::make_pair(itemName, pair));
    //TODO - UPDATE INVENTORY FILE
}

void Inventory::addNewItem(Item item, int itemQuantity, double itemPrice) {
    
    std::string itemName = item.getItemName();
    
    iter = inventoryMap.find(itemName);
    if(iter == inventoryMap.end()){
    
    auto pair = std::make_pair(item , itemQuantity);
    
    inventoryMap.insert(std::make_pair(itemName, pair));
        //TODO - UPDATE INVENTORY FILE
        
    }else{
        addItemQuantity(itemName, itemQuantity);
        
        double currentPrice = iter->second.first.getItemPrice();
        if(currentPrice != itemPrice){
            setItemPrice(itemName, itemPrice);
        }
    }
}

void Inventory::addItemQuantity(std::string itemName, int numberOfItems){
    iter = inventoryMap.find(itemName);
    if(iter != inventoryMap.end()){
    iter->second.second += numberOfItems;
        //TODO - UPDATE INVENTORY FILE
    }
    else{
        std::cout << "could not update item quantity";
    }
}

void Inventory::removeItemQuantity(std::string itemName, int numberOfItems){
    iter = inventoryMap.find(itemName);
    if(iter != inventoryMap.end()){
      iter->second.second -= numberOfItems;
        //TODO - UPDATE INVENTORY FILE
    }
    else{
        std::cout << "could not update item quantity";
    }
}

void Inventory::setItemPrice(std::string itemName, double price){
    iter = inventoryMap.find(itemName);
    if(iter != inventoryMap.end() && price > 0.0){
//        inventoryMap.find(itemName)->second.first.setItemPrice(price);
        iter->second.first.setItemPrice(price);
        //TODO - UPDATE INVENTORY FILE
    }else{
        std::cout << "could not update price";
    }
}

bool Inventory::isItemAvailable(std::string itemName, int quantity){
    return true;
}

void Inventory::updateInventoryFile(std::string itemName){
    inOutInventory.open( "inventory.dat", std::ios::in | std::ios::out | std::ios::binary );
    
    std::map<std::string, std::pair<Item, int>> item;
    
//    inOutInventory.seekg(itemName * sizeof( item ));
//    inOutInventory.read( reinterpret_cast< const char * >( &item ),
//                        sizeof( item ) );
//    inv.setQuantity( inv.getQuantity() + quantity );
//    inv.setPrice( price );
//    inOutInventory.seekp(foodNumber * sizeof( Inventory ));
//    inOutInventory.write( reinterpret_cast< const char * >( &inv ),
//                         sizeof( Inventory ) );
}


////TODO if time
//double Inventory::getInventoryTotalValue() {
//    return this->inventoryTotalValue;
//}
//void Inventory::setInventoryTotalValue(double inventoryTotalValue) {
//    this->inventoryTotalValue = inventoryTotalValue;
//}

//int Inventory::getInventoryTotalQty() {
//    return this->inventoryTotalQty;
//}
//
//void Inventory::setInventoryTotalQty(int inventoryTotalQty) {
//    this->inventoryTotalQty = inventoryTotalQty;
//}
