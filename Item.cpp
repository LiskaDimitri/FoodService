//
//  Item.cpp
//  Final_Shopping_Project
//
//  Created by MrScargs on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#include "Item.hpp"

Item::Item(int itemSkuNumber, std::string itemName, std::string itemDescription, double itemPrice, bool isItemCoupon){
    this->itemSkuNumber = itemSkuNumber;
    this->itemName = itemName;
    this->itemDescription = itemDescription;
    this->itemPrice = itemPrice;
    this->isCoupon = isItemCoupon;
}

int Item::getItemSkuNumber() {
    return this->itemSkuNumber;
}

void Item::setItemSkuNumber(int itemSkuNumber) {
    this->itemSkuNumber = itemSkuNumber;
}

std::string Item::getItemName() {
    return this->itemName;
}

void Item::setItemName(std::string itemName) {
    this->itemName = itemName;
}

std::string Item::getItemDescription() {
    return this->itemDescription;
}

void Item::setItemDescription(std::string itemDescription) {
    this->itemDescription = itemDescription;
}

double Item::getItemPrice(){
    return this->itemPrice;
}
void Item::setItemPrice(double itemPrice){
    this->itemPrice = itemPrice;
}

bool Item::isItemCoupon() {
    return this->isCoupon;
}

void Item::setItemCoupon(bool itemCoupon) {
    this->isCoupon = itemCoupon;
}

//bool Item::operator < (const Item& itemObj) const {
//    return (this->itemSkuNumber < itemObj.itemSkuNumber) ;
//}

//template<> struct std::less<Item>
//{
//    bool operator() (const Item& firstItem, const Item& secondItem) const
//    {
//        int firstItem sku = firstItem.getItem
//        return firstItem.itemSkuNumber < secondItem.itemSkuNumber;
//    }
//};
