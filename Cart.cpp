//
//  Cart.cpp
//  Final_Shopping_Project
//
//  Created by MrScargs on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#include "Cart.hpp"

//NOT SURE WHY DOES NOT WORK IF IN THE H FILE.
static std::vector<std::string> cartCustomerIdList;

Cart::Cart(){
    //needed to access vector List.
}

Cart::Cart(std::string customerId){
        cartCustomerId = customerId;
//
//    //Consedering moving that into a systemClass.
    cartCustomerIdList.push_back(cartCustomerId);
}

Cart:: ~Cart(){
    
}

void Cart::print() {
    using namespace std;
    
    cout << "---------- Cart Repport: ----------" << endl;
    for (auto& item : cartMap){
        
        cout << std::setw(12) << std::left << item.first << " { " <<
        "Sku: " << std::setw(4) << std::left << item.second.first.getItemSkuNumber() << " -|- " <<
        "Desc: " << std::setw(20) << std::left << item.second.first.getItemDescription() << " -|- " <<
        "Price: " << std::setw(6) << std::left << setprecision(3) << item.second.first.getItemPrice() << " -|- " <<
        "Quantity: " << std::setw(5) << std::left << item.second.second << " } " << endl;
    }
}

void Cart::setFoodName(int string) {
    // TODO - implement Cart::setFoodName
    throw "Not yet implemented";
}

std::string Cart::getFoodNames() {
    // TODO - implement Cart::getFoodNames
    throw "Not yet implemented";
}

void Cart::setFoodQuantity(std::string itemName, int itemQty) {
    // TODO - implement Cart::setFoodQuantity
    throw "Not yet implemented";
}

int Cart::getFoodQuantity(int string) {
    // TODO - implement Cart::getFoodQuantity
    throw "Not yet implemented";
}

void Cart::updateQuantity(std::string foodNme, int foodQty) {
    // TODO - implement Cart::updateQuantity
    throw "Not yet implemented";
}

double Cart::getCartTotal() {
    return this->cartTotalValue;
}

Coupon* Cart::getCartCoupons() {
    // TODO - implement Cart::getCartCoupons
    throw "Not yet implemented";
}
//
//void Cart::setCartCoupons(Coupon cartCoupons[]) {
//    this->cartCoupons = cartCoupons;
//}

Item* Cart::getCartItems() {
    // TODO - implement Cart::getCartItems
    throw "Not yet implemented";
}
//
//void Cart::setCartItems(Item cartItems[]) {
//    this->cartItems = cartItems;
//}

double Cart::getCartTotalCouponValue() {
    return this->cartTotalCouponValue;
}

void Cart::setCartTotalCouponValue(double cartTotalCouponValue) {
    this->cartTotalCouponValue = cartTotalCouponValue;
}

bool Cart::checkForPreviousCart(std::string customerId){
    bool isCartPresent = false;
        if (std::find(cartCustomerIdList.begin(), cartCustomerIdList.end(), customerId ) != cartCustomerIdList.end()){
            isCartPresent = true;
    }
    return isCartPresent;
}
