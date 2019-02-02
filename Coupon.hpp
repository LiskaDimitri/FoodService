//
//  Coupon.hpp
//  Final_Shopping_Project
//
//  Created by Dimitri Liska on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#ifndef Coupon_hpp
#define Coupon_hpp

#include <stdio.h>
#include <string>

class Coupon {
    
private:
    std::string couponName;
    double couponDiscount;
    std::string couponDescription;
    bool isCoupon;
    
public:
    Coupon(std::string couponName, double couponDiscount, std::string couponDescription , bool isItemCoupon);
    
    std::string getcouponName();
    
    void setcouponName(std::string couponName);
    
    double getCouponDiscount();
    
    void setCouponDiscount(int couponDiscount);
    
    std::string getCouponDescription();
    
    void setCouponDescription(std::string couponDescription);
    
    bool isItemCoupon();
    
    void setItemCoupon(bool itemCoupon);
};

#endif /* Coupon_hpp */
