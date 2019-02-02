//
//  User.hpp
//  Final_Shopping_Project
//
//  Created by Dimitri Liska on 11/15/18.
//  Copyright © 2018 Developer Sans Frontiere. All rights reserved.
//

#ifndef User_hpp
#define User_hpp

#include <stdio.h>
#include <string>

class User {
    
protected:
    std::string userIdNumber;
    std::string userName;
    
    virtual void setUserIdNumber(std::string userIdNumber) = 0;
    
public:
    virtual std::string getIdNumber() = 0;
    
    std::string getUserName();
    
    void setUserName(std::string userName);
};

#endif /* User_hpp */
