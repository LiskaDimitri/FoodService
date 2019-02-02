//
//  main.cpp
//  Final_Shopping_Project
//
//  Created by Dimitri Liska on 11/15/18.
//  Copyright © 2018 Developer Sans Frontiere. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <ostream>
#include <sstream>
#include <iomanip>
#include <cstdlib>
//#include <boost/lexical_cast>
//#include <tuple>
#include "Customer.hpp"
#include "Manager.hpp"
#include "Inventory.hpp"
#include "Cart.hpp"
#include "Item.hpp"

using namespace std;

enum ManagerChoices { ADD_M = 1, UPDATE_M, DISPLAY_M, END_M };
enum CustomerChoises { DISPLAY_ACC_C = 1, ADD_C, RETRIEVE_LIST_C, RETRIEVE_CART_C, UPDATE_C, DISPLAY_CART_C, CHECKOUT_C, END_C };

static const int ITEM_NAME_SIZE = 15;
static const int ITEM_DESC_SIZE = 30;

static const int STRUCT_SIZE = 64;

//static const std::size_t itemNameSize = ITEM_NAME_SIZE;
//static const std::size_t itemDescSize = ITEM_DESC_SIZE;

struct invItem {
    int sku; //4 bytes
    char *name; //4 (32bits architecture) or 8 (64bits) for pointers each char = 1 bytes
    char *Desc; // or 1bytes and 1 for each char in array
    bool iscoupon; //8 bytes or 1 bytes
    double price; //1 byte
    int qty; //4 bytes
    
};

//Interface
int managerSelectionMenu();
int customerSelectionMenu();

//Inventory Load & Save Method
void inventorySave(Inventory *inv);
void inventoryLoad(Inventory *inv);

//Input checks
bool managerOptions(const string userInput);
bool customerOptions(const string userInput);
bool hasOnlyDigits(const string userInput);


//Tests
void runTests();
void customerTest();
void managerTest();
void itemTest();
void couponTest();
void inventoryTest(Inventory *inv);
void TestFromStack();
void cartTest();

fstream inOutInventory;

int main(int argc, const char * argv[]) {
    
//    runTests();
    
    // TODO - Login prompt
    string customer = "Customer";
    string manager = "Manager";
    
    //TODO - make menu selection
    string login = manager;
//    string login = customer;
    
    // TODO - check file for existing customer, if not create new account
    Customer cus("2546", "Amanda", 98.65);
    Inventory inv;
    Manager man("9856", "Dimitri", &inv);
    
    // TODO - Load inventory from file to memory
    inventoryTest(&inv);
//    inventoryLoad(&inv);
    
//    inOutInventory.open( "inventory.dat", ios::in | ios::out | ios::binary );
//    if ( !inOutInventory )
//    {
//        inOutInventory.close();
//        ofstream newFile("inventory.dat", ios::out);
//
//        newFile.seekp( 0 );
//
//        for (auto& item : *inv.getInventoryMap()){
//            newFile.write( reinterpret_cast< const char * >( &item ),
//                          sizeof( item ) );
//        }
//        newFile.close();
//        inOutInventory.open( "inventory.dat", ios::in | ios::out | ios::binary );
//    }
//
//    Item banana_Or(4085, "Bananas_O", "Organic bananas", 1.59, false);
//    Item banana_NOr(4070, "Bananas_NOr", "Non Organic bananas", 2.59, false);
//    Item apples(5048, "Apples", "Non-Organic apples", 0.56, false);
//    Item saussage(9843, "Saussage", "Polish Saussage",3.89, false);
//
//    inv.addNewItem( banana_Or, 152, 1.59);
//    inv.addNewItem( banana_NOr, 169, 2.59);
//    inv.addNewItem( apples, 364, 0.99);
//    inv.addNewItem( saussage, 25, 5.79);
    
//    inventorySave(&inv);
    
    int choice;
    if(login == "Manager"){
        while ( ( choice = managerSelectionMenu() ) != END_M ){
            switch ( choice )
            {
                case ADD_M:{
                    // check if new Item or existing Item.
                    // Maybe add an obtion in the menu
                    cout << "Re-stocking inventory selected: ";
                    cout << "Enter the Item name, the Quantity and the price in the form of ##.##:\n?: ";
                    std::string itemName;
                    int itemQuantity;
                    double itemPrice;
                    std::cin >> itemName >> itemQuantity >> itemPrice;
                    man.restockingInventory(itemName, itemQuantity, itemPrice);
                    break;
                }
                case UPDATE_M:{
                    cout << "Update inventory price selected: ";
                    cout << "Enter the Item name to change and the price in the form of ##.##: ";
                    std::string itemName;
                    double itemPrice;
                    std::cin >> itemName >> itemPrice;
                    man.updateInventoryPrices(itemName, itemPrice);
                    break;
                }
                case DISPLAY_M:
                    man.displayInventoryReport();
                    break;
                case END_M:
                    cout << "Ciao";
                    break;
                default:
                    std::cerr << "An Error occured in the selection menu." << endl;
                    break;
            }
//            managerSelectionMenu();
        }
    }else if(login == "Customer"){
        while ( ( choice = customerSelectionMenu() ) != END_C ){
            switch ( choice )
            {
                case DISPLAY_ACC_C:
                    cout << "Display account information selected:" <<endl;
                    cout << cus.displayAccountInformation() << endl;
                    break;
                case ADD_C: {
                    cout << "Add money to account" << endl;
                    cout << "Enter an Amount in the form of ##.##: ";
                    std::string userInput;
                    std::cin >> userInput;
                    if (hasOnlyDigits(userInput)) {
                        double userValue = std::stod(userInput);
                        cus.addMoneyToAccount(userValue);
                    }
                    else{
                        cout << "An Error Occuced please try again" << endl;
                    }
                    break;
                }
                case RETRIEVE_LIST_C:
                    //TODO
                    cout << "Retrieve a shopping list file";
                    break;
                case RETRIEVE_CART_C:
                    //TODO
                    cout << "Retrieve a saved cart";
                    break;
                case UPDATE_C:
                    //TODO
                    cout << "Update cart contents";
                    break;
                case DISPLAY_CART_C:
                    cus.displayCartReport();
                    break;
                case CHECKOUT_C:
                    //TODO
                    cout << "Process the cart (checkout)";
                    break;
                case END_C:
                    cout << "Ciao";
                    break;
                default:
                    std::cerr << "An Error occured in the selection menu." << endl;
                    break;
            }
//            customerSelectionMenu();
        }

    }else{
        cout << "User Selection Error";
    }
    
    return 0;
    
}

int managerSelectionMenu(){
    cout << "\nEnter your choice" << endl
    << "1 - Re-stocking inventory" << endl
    << "2 - Update inventory price" << endl
    << "3 - Display inventory report" << endl
    << "4 - End program\n?: ";
    
    string strMenuChoice = "0";
    cin >> strMenuChoice;
    
    while (!managerOptions(strMenuChoice) ){
       cout << "Incorrect entry, please enter new choice: ";
        cin >> strMenuChoice;
    }
    int menuChoice = std::stoi(strMenuChoice);
    return menuChoice;
}

int customerSelectionMenu()
{
    std::cout << "\nEnter your choice" << endl
    << "1 - Display account information" << endl
    << "2 - Add money to account" << endl
    << "3 - Retrieve a shopping list file" << endl
    << "4 - Retrieve a saved cart" << endl
    << "5 - Update cart contents" << endl
    << "6 - Display cart report" << endl
    << "7 - Process the cart (checkout)" << endl
    << "8 - End program\n?: ";
    
    string strMenuChoice = "0";
    cin >> strMenuChoice;
    
    while (!customerOptions(strMenuChoice) ){
        cout << "Incorrect entry, please enter new choice: ";
        cin >> strMenuChoice;
    }
    int menuChoice = std::stoi(strMenuChoice);
    return menuChoice;
}

bool managerOptions(const string userInput) {
    
    return userInput.find_first_not_of("1234") == string::npos;
}

bool customerOptions(const string userInput) {
    
    return userInput.find_first_not_of("12345678") == string::npos;
}

bool hasOnlyDigits(const string userInput) {
    
    return userInput.find_first_not_of("-.0123456789") == string::npos;
}

void inventorySave(Inventory *inv){
    inOutInventory.open( "inventory.dat", ios::in | ios::out | ios::binary );
    
    if ( !inOutInventory )
    {
        inOutInventory.close();
        ofstream newFile("inventory.dat", ios::out);
        newFile.seekp( 0 );
        newFile.close();
    }
//    else if (inOutInventory){
        ofstream existingFile("inventory.dat", ios::out);
        //TODO - CHANGING FOR AVOIDING REWRITTING FILE FROM BEGENING
        existingFile.seekp( 0 );
        
        for( auto& item : *inv->getInventoryMap()){
            int sku = item.second.first.getItemSkuNumber();
            string strName = item.second.first.getItemName();
            char nameArray[ITEM_NAME_SIZE];
            // TODO if statement cut string of name and description if to long;
//            strName.copy(nameArray, itemNameSize, 0);
            for ( int i=0 ; i < ITEM_NAME_SIZE ; i++ ){
                if (i < strName.size()){
                   nameArray[i] = strName.at(i);
                }
                else{
                    nameArray[i] = ' ';
                }
            }
            nameArray[ITEM_NAME_SIZE - 1]='\0';
            
            string strdesc = item.second.first.getItemDescription();
            char descArray[ITEM_DESC_SIZE];
//            strdesc.copy(descArray, itemDescSize, 0);
            for ( int i=0 ; i < ITEM_DESC_SIZE ; i++ ){
                if (i < strdesc.size()){
                    descArray[i] = strdesc.at(i);
                }
                else{
                    descArray[i] = ' ';
                }
            }
            descArray[ITEM_DESC_SIZE - 1]='\0';
            
            double price = item.second.first.getItemPrice();
            int qty = item.second.second;
            bool iscoupon = item.second.first.isItemCoupon();
            
            invItem invNewItem = {sku, nameArray, descArray, iscoupon, price, qty};
            
            //cout size of and use that size for the struct
            cout << "Structure size: " << sizeof(invNewItem) << endl;
            cout << "sku size: " << sizeof(sku) << endl;
            cout << "pointer nameArray size: " << sizeof(*nameArray) << endl;
            cout << "nameArray size: " << sizeof(nameArray) << endl;
            
            cout << "pointer descSize: " << sizeof(*descArray) << endl;
            cout << "descArray size: " << sizeof(descArray) << endl;
            cout << "bool size: " << sizeof(iscoupon) << endl;
            cout << "price size: " << sizeof(price) << endl;
            cout << "Quantity size: " << sizeof(qty) << endl;
            
            existingFile.write( reinterpret_cast< const char * >( &invNewItem ),
                          STRUCT_SIZE);
        }
        existingFile.close();
//    }
//    else{
//                cout << "An error Occured during Inventory File Saving" << endl;
//    }

//    if ( !inOutInventory )
//    {
//        inOutInventory.close();
//        ofstream newFile("inventory.dat", ios::out);
//
//        newFile.seekp( 0 );
//
//        // POSSIBLE PROBLEM WITH AUTO
//        for (auto& item : *inv->getInventoryMap()){
//            newFile.write( reinterpret_cast< const char * >( &item ),
//                          sizeof( item ) );
//        }
//        newFile.close();
////        inOutInventory.open( "inventory.dat", ios::in | ios::out | ios::binary );
//    }
//    else if (inOutInventory){
//        ofstream existingFile("inventory.dat", ios::out);
//        //TODO - CHANGING FOR AVOIDING REWRITTING FILE FROM BEGENING
//        existingFile.seekp( 0 );
//
//         std::map<std::string, std::pair<Item, int>> item = *inv->getInventoryMap();
////        for (auto& item : *inv->getInventoryMap()){
//            existingFile.write( reinterpret_cast< const char * >( &item ),
//                          sizeof( item ) );
////        }
//        existingFile.close();
//    }else{
//        cout << "An error Occured during Inventory File Saving" << endl;
//    }
}

void inventoryLoad(Inventory *inv){
    std::map<std::string, std::pair<Item, int>> *inventoryMap = inv->getInventoryMap();
    inOutInventory.open( "inventory.dat", ios::in | ios::out | ios::binary );
    if ( !inOutInventory )
    {
        std::cerr << "Inventory File could not be found." << endl;
        exit( EXIT_FAILURE );
    }
    else if (inOutInventory){
        
        fstream existingFile ( "inventory.dat", ios::in | ios::binary ) ;
        
        int sku = 0;
        char nameArray[ITEM_NAME_SIZE];
        char descArray[ITEM_DESC_SIZE];
        double price = 0.00;
        int qty = 0;
        bool isCoupon = false;
        
        invItem invNewItem = {sku, nameArray, descArray, isCoupon, price, qty};
        
        existingFile.read( reinterpret_cast< char * >( &invNewItem ), STRUCT_SIZE);
        
        while(!inOutInventory.eof()){
            
            sku = invNewItem.sku;
            
            //Potential issue if empty spaces in array
            string strName(nameArray);
            string strDesc(descArray);
            price = invNewItem.price;
            qty = invNewItem.qty;
            isCoupon = invNewItem.iscoupon;
            
            Item loadedItem(sku, strName, strDesc, price, isCoupon);
            
            auto pair = std::make_pair(loadedItem , qty);
            
            inventoryMap->insert(std::make_pair(loadedItem.getItemName(), pair));
            
            existingFile.read( reinterpret_cast< char * >( &invNewItem ), STRUCT_SIZE);
        }
    }else{
        cout << "An error Occured during Inventory File Saving" << endl;
    }
    
//    for (auto& row : buffer){
//        std::string itemNameRow = row.first;
//        Item itemtoLoad = row.second.first;
//        int qty = row.second.second;
//
//        auto pair = std::make_pair(itemtoLoad , qty);
//        inventoryMap->insert(std::make_pair(itemNameRow, pair));
//    }
    
    
//    std::pair<std::string, std::pair<Item, int>> buffer;
    
//    inOutInventory.read( reinterpret_cast< char * >( &buffer ),
//                        sizeof( buffer ) );
//
//    inventoryMap = &buffer;
    
//    while(!inOutInventory.eof()){
    
//        Item item2(buffer.at(0).first.)
//
//        inOutInventory.read( reinterpret_cast< char * >( &buffer ),
//                      sizeof( buffer ) );
//
//        Item item(buffer.get, "Bananas_O", "Organic bananas", 1.59, false);
//
//        auto pair = std::make_pair(buffer.first , qty);
//        //
//        //    pair.first.getItemDescription();
//        //
//        //    itemmap.insert(std::make_pair(bananaOr.getItemName(), pair));
    
//        inventoryMap->insert(buffer.at(0));
//    int qtyresult = itemmap.find("Bananas")->second.second;
    //    cout << "Qantity: " << qtyresult;
    //
    //    itemmap.find("Bananas")->second.second = 58;
    //    cout << "Qantity: " << itemmap.find("Bananas")->second.second;
    //
    //        itemmap.insert(itmBanana1.getItemName(), std::make_pair(itmBanana1*,int));
    
//    }
    
}

void runTests(){
    //    customerTest();
    //    managerTest();
    //    itemTest();
    //    couponTest();
    //    TestFromStack();
    //    inventoryTest();
    //    cartTest();
}
    

void customerTest(){
    Customer cus("23236", "Ted Kapusta", 450.00);
    cus.addMoneyToAccount(50.00);
    cout << cus.displayAccountInformation() << endl;
}

void managerTest(){
    Manager man("5432", "Amanda", new Inventory());
    string iD = man.getIdNumber();
}

void itemTest(){
    Item itmBanana(4085, "Bananas", "Organic bananas", 1.59, false);
    
    //TODO for loop for testing Item objects
    cout << "Item 1 - TEST: ";
    cout << "SKU: " << itmBanana.getItemSkuNumber() << " | ";
    cout << "Name: " << itmBanana.getItemName() << " | ";
    cout << "Desc: " << itmBanana.getItemDescription() << " | ";
    cout << "Price: $" << itmBanana.getItemPrice() << " | ";
    cout << "isCoupon: " << itmBanana.isItemCoupon()<< " | " << endl;
    
    
}

void couponTest(){
    Coupon cpn("banana", -0.50, "50cts of organic bananas", true);
    cout << "Name: " << cpn.getcouponName() << " | ";
    cout << "Discout: $" <<cpn.getCouponDiscount() << " | ";
    cout << "Desc: " << cpn.getCouponDescription() << " | ";
    cout << "isCoupon: " << cpn.isItemCoupon() << " | " << endl;
}

void inventoryTest(Inventory *inv){
    Item banana_Or(4085, "Bananas_O", "Organic bananas", 1.59, false);
    Item banana_NOr(4070, "Bananas_NOr", "Non Organic bananas", 2.59, false);
    Item apples(5048, "Apples", "Non-Organic apples", 0.56, false);
    Item saussage(9843, "Saussage", "Polish Saussage",3.89, false);
    Item cereal(3865, "Cereal", "Fruit Loops",5.89, false);
    
    Item peanut_But(7392, "Peanut_But", "Cruchy Peanut Butter",2.49, false);
    Item milk(9123, "Milk", "Super Farm Milk",2.59, false);
    Item coffee(9853, "Coffee", "Dessert Oasis Coffee",8.49, false);
    Item eggs(4532, "Eggs_Farm", "Free range eggs",6.39, false);
    Item avocado(9943, "Avocado", "California Avocado",2.19, false);
    
    Item batteries(9286, "Batteries", "Energizer AAA",12.59, false);
    Item candle(9843, "candle_Yank", "Yankee Candle",7.29, false);
    Item cream_Shav(7453, "Cream_Shav", "Shaving Cream",3.99, false);
    Item soap(2964, "Saop", "Lavander Soap",3.59, false);
    Item bacon(1790, "Bacon", "Smoked Bacon",4.39, false);
    
    Item croissant(1743, "Croissant", "French Croissant",3.89, false);
    Item baguette(1853, "Baguette", "French Baguette",4.59, false);
    Item beer_budL(4865, "Beer_BudL", "Beer Bud Light",12.89, false);
    Item beer_coro(4866, "Beer_Cor", "Beer Corona",11.79, false);
    Item beer_hei(4867, "Beer_Hei", "Beer Heineken",14.79, false);
    
    inv->addNewItem( banana_Or, 152, 1.59);
    inv->addNewItem( banana_NOr, 169, 2.59);
    inv->addNewItem( apples, 364, 0.99);
    inv->addNewItem( saussage, 25, 5.79);
    inv->addNewItem( cereal, 23, 5.89);
    
    inv->addNewItem( peanut_But, 345, 1.59);
    inv->addNewItem( milk, 234, 2.59);
    inv->addNewItem( coffee, 653, 8.49);
    inv->addNewItem( eggs, 234, 6.39);
    inv->addNewItem( avocado, 865, 2.19);
    
    inv->addNewItem( batteries, 56, 3.89);
    inv->addNewItem( candle, 87, 7.29);
    inv->addNewItem( cream_Shav, 98, 3.99);
    inv->addNewItem( soap, 456, 3.59);
    inv->addNewItem( bacon, 254, 4.39);
    
    inv->addNewItem( croissant, 12, 3.89);
    inv->addNewItem( baguette, 24, 4.59);
    inv->addNewItem( beer_budL,342, 12.89);
    inv->addNewItem( beer_coro, 25, 11.79);
    inv->addNewItem( beer_hei, 234, 14.79);
    
    //    std::map<Item*, int> inventoryMap;
    
    //Test with tuple
//    std::map<std::string, std::tuple<Item*, int> > myMap2;
//
//    myMap2.insert(std::make_pair(bananaOr.getItemName(), std::tuple<Item*, int>(new Item(4085, "Bananas", "Organic bananas", 1.59, false), 10)));
//
//    myMap2.insert(std::make_pair(apple.getItemName(), std::tuple<Item*, int>(new Item(4085, "Apples", "Organic bananas", 1.59, false), 20)));
//
//    myMap2.insert(std::make_pair(bananaOr.getItemName(), std::tuple<Item*, int>(new Item(4085, "Bananas", "Organic bananas", 1.59, false), 20)));
    
    //DOES NOT WORK
    //    myMap2.insert(std::make_pair(itmBanana2.getItemName(), std::tuple<Item*, int>(itmBanana2*, 20)));
    
    //    myMap2.find(const "Bananas");
    
    
    //    inventoryMap.insert(std::make_pair(new Item(4085, "Bananas", "Organic bananas", 1.59, false), 10));
    //    inventoryMap.insert(std::make_pair(new Item(4085, "Bananas", "Organic bananas", 1.59, false), 10));
    
    //    inventoryMap[itmBanana1] = 10;
    //    inventoryMap.at("Bananas")
    //    inventoryMap.in
    //    inventoryMap.insert("banana", itmBanana2);
    //    inventoryMap.insert(itmBanana.getItemName(), std::make_pair(itmBanana, 15));
    
    //------------------------------------------
    
    //Test That works
//    std::map<std::string, std::pair<Item, int>> itemmap;
//
//    int qty = 10;
//    auto pair = std::make_pair(bananaOr , qty);
//
//    pair.first.getItemDescription();
//
//    itemmap.insert(std::make_pair(bananaOr.getItemName(), pair));
//
//    int qtyresult = itemmap.find("Bananas")->second.second;
//    cout << "Qantity: " << qtyresult;
//
//    itemmap.find("Bananas")->second.second = 58;
//    cout << "Qantity: " << itemmap.find("Bananas")->second.second;
//
//        itemmap.insert(itmBanana1.getItemName(), std::make_pair(itmBanana1*,int));
//
    //------------------------------------------
    
//    Inventory inv;
//    inv.addNewItem( banana_Or, 152, 1.59);
//    inv.addNewItem( banana_NOr, 169, 2.59);
//    inv.addNewItem( apples, 364, 0.99);
//    inv.addNewItem( saussage, 25, 5.79);
//
//    inv.addItemQuantity(banana_Or.getItemName(), 50);
//    inv.removeItemQuantity(saussage.getItemName(), 20);
//
//    inv.setItemPrice(apples.getItemName(), 1.39);
//
//    inv.print();
}
void cartTest(){
    Customer cus("23236", "Ted Kapusta", 450.00);
    Cart car;
    Cart car2(cus.getIdNumber());
    
    car.print();
    
}

void TestFromStack(){
    std::map<std::string, int> mapOfWords;
    // Inserting data in std::map
    mapOfWords.insert(std::make_pair("earth", 1));
    mapOfWords.insert(std::make_pair("moon", 2));
    mapOfWords["sun"] = 3;
    // Will replace the value of already added key i.e. earth
    mapOfWords["earth"] = 4;
    // Iterate through all elements in std::map
    std::map<std::string, int>::iterator it = mapOfWords.begin();
    while(it != mapOfWords.end())
    {
        std::cout<<it->first<<" :: "<<it->second<<std::endl;
        it++;
    }
    // Check if insertion is successful or not
    if(mapOfWords.insert(std::make_pair("earth", 1)).second == false)
    {
        std::cout<<"Element with key 'earth' not inserted because already existed"<<std::endl;
    }
    // Searching element in std::map by key.
    if(mapOfWords.find("sun") != mapOfWords.end())
        std::cout<<"word 'sun' found"<<std::endl;
    if(mapOfWords.find("mars") == mapOfWords.end())
        std::cout<<"word 'mars' not found"<<std::endl;
    
    //--------------------------------------------------------
    
    int n = 1;
    int a[5] = {1, 2, 3, 4, 5};
    
    // build a pair from two ints
    auto p1 = std::make_pair(n, a[1]);
    std::cout << "The value of p1 is "
    << "(" << p1.first << ", " << p1.second << ")\n";
    
    // build a pair from a reference to int and an array (decayed to pointer)
    auto p2 = std::make_pair(std::ref(n), a);
    n = 7;
    std::cout << "The value of p2 is "
    << "(" << p2.first << ", " << *(p2.second + 2) << ")\n";
    
    //---------------------------------------------------------
}
