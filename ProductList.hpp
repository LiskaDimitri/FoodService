//
//  ProductList.hpp
//  Final_Shopping_Project
//
//  Created by MrScargs on 11/15/18.
//  Copyright © 2018 Ted_Industries. All rights reserved.
//

#ifndef ProductList_hpp
#define ProductList_hpp

#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <ostream>
#include <sstream>
//#include <tuple>

class ProductList {
    
private:
    int listId;
    int listName;
    
public:
    virtual void print() = 0;
    
    void getListId();
    
    void setListId(int listId);
    
    void getListName();
    
    void setListName(int listName);
};

#endif /* ProductList_hpp */
