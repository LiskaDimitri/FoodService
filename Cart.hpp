//
//  Cart.hpp
//  Final_Shopping_Project
//
//  Created by MrScargs on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#ifndef Cart_hpp
#define Cart_hpp

#include <stdio.h>
#include <map>
#include <vector>
#include "ProductList.hpp"
#include "Item.hpp"
#include "Coupon.hpp"

class Cart : ProductList {
    
private:
    std::string cartCustomerId;
    double cartTotalCouponValue;
    double cartTotalValue;
    
    //Consedering moving that into a systemClass.
//    static std::vector<std::string> cartCustomerIdList;
    
//    std::string foodNames[20];
//    int itemQuantity;
//    int foodQuantity[20];
    /**
     * Implementation Using std::map<Item,int>
     */
//    Coupon cartCoupons[20];
    /**
     * Implementation Using std::map<Item,int>
     */
//    Item cartItems[20];
    
    std::map<std::string, std::pair<Item, int> > cartMap;
    std::map<std::string, std::pair<Item, int>>::iterator iter;
    
    
    
public:
    
    Cart();
    
    Cart(std::string CustomerId);
    
    ~Cart();
    
    void print();
    
    void setFoodName(int string);
    
    std::string getFoodNames();
    
    void setFoodQuantity(std::string itemName, int itemQty);
    
    int getFoodQuantity(int string);
    
    void updateQuantity(std::string foodNme, int foodQty);
    
    double getCartTotal();
    
    Coupon* getCartCoupons();
    
    void setCartCoupons(Coupon cartCoupons[]);
    
    Item* getCartItems();
    
    void setCartItems(Item cartItems[]);
    
    double getCartTotalCouponValue();
    
    void setCartTotalCouponValue(double cartTotalCouponValue);
    
    bool checkForPreviousCart(std::string customerId);
    
    Cart retrieveCart(std::string customerId);
};

#endif /* Cart_hpp */
