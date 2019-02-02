//
//  Coupon.cpp
//  Final_Shopping_Project
//
//  Created by Dimitri Liska on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#include "Coupon.hpp"

Coupon::Coupon(std::string couponName, double couponDiscount, std::string couponDescription , bool isItemCoupon){
    this->couponName = couponName;
    this->couponDiscount = couponDiscount;
    this->couponDescription = couponDescription;
    this->isCoupon = isItemCoupon;
}

std::string Coupon::getcouponName() {
    return this->couponName;
}

void Coupon::setcouponName(std::string couponName) {
    this->couponName = couponName;
}

double Coupon::getCouponDiscount() {
    return this->couponDiscount;
}

void Coupon::setCouponDiscount(int couponDiscount) {
    this->couponDiscount = couponDiscount;
}

std::string Coupon::getCouponDescription() {
    return this->couponDescription;
}

void Coupon::setCouponDescription(std::string couponDescription) {
    this->couponDescription = couponDescription;
}

bool Coupon::isItemCoupon() {
    return this->isCoupon;
}

void Coupon::setItemCoupon(bool isItemCoupon) {
    this->isCoupon = isItemCoupon;
}
