//
//  Customer.cpp
//  Final_Shopping_Project
//
//  Created by Dimitri Liska on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#include "Customer.hpp"

Customer::Customer(std::string customerId, std::string customerName, double customerBalance) {
    setUserIdNumber(customerId);
    this->userName = customerName;
    this->customerDebitBalance = customerBalance;
    this->cart = new Cart(customerId);
}

void Customer::setUserIdNumber(std::string userIdNumber) {
    //TO-DO if Time
    //Add extra generation
    this->userIdNumber = preStringID + userIdNumber;
}

std::string Customer::getIdNumber() {
    return this->userIdNumber;
}

void Customer::addMoneyToAccount(double amount) {
    //TODO
    //Check for input like (negative, wrong)...
    this->customerDebitBalance += amount;
    std::cout << "$" << amount << " was added to the account" << std::endl;
}

double Customer::getCustomerDebitBalance() {
    return this->customerDebitBalance;
}

std::string Customer::displayAccountInformation() {
    //if ints ar used std::to_string()
    std::string ouputstr;
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << getCustomerDebitBalance();
    std::string balanceString = ss.str();
    
    ouputstr = "Customer [ Name: " + getUserName() + " | " + getIdNumber() +
    " | Balance: $" + balanceString + " ]";

    return ouputstr;
}

bool Customer::retrieveShoppingListFile() {
    // TODO - implement Customer::retrieveShoppingListFile
    throw "Not yet implemented";
}

Cart Customer::retrieveSavedCart(std::string customerId) {
    Cart* tempCart = new Cart();
    
    
    
    if(tempCart->checkForPreviousCart(customerId)){
//        this->cart =
    }else if (retrieveShoppingListFile()){
        
    }else{
        this->cart = tempCart;
    }
    
    // TODO - implement Customer::retrieveSavedCart
    
    delete tempCart;
    throw "Not yet implemented";
}

void Customer::updateCartContents(std::string itemAction) {
    // TODO - implement Customer::updateCartContents
    throw "Not yet implemented";
}

void Customer::displayCartReport() {
    this->cart->print();
}

bool Customer::checkoutCart() {
    
    cart->print();
    
    //TODO
    
    //display totalcartvalue
    
    //display totalcouponvalue
    
    //display total owned
    
    //check if balance is enouth
    
    //if balance not enouth offering customer to refill the account with a minimum amount that would cover the total sale;
    
    //remove the cart items from inventory. (possibly using a System class)
   
    delete cart;  //potentioal memory leak issue, consider using a smart pointer;
    
    
    throw "Not yet implemented";
}
