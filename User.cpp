//
//  User.cpp
//  Final_Shopping_Project
//
//  Created by Dimitri Liska on 11/15/18.
//  Copyright © 2018 Developer Sans Frontiere. All rights reserved.
//

#include "User.hpp"

std::string User::getUserName() {
    return this->userName;
}

void User::setUserName(std::string userName) {
    this->userName = userName;
}
