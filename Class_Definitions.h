#ifndef CLASS_DEFINITIONS_H
#define CLASS_DEFINITIONS_H
#include <iostream>
using namespace std;


class Pharmacist{
public:
    string id;
    string fname;
    string lname;
    string username;
    string password;
    int salary;
    int is_admin; /* to differentiate between admin and pharmacist */
};


class Medicine{
public:
    string id;
    int quantity;
    int buy_price;
    int sell_price;
    string name;
    string supplier_company;
    string category;
    bool is_alternative;
};


class Supplier{
public:
    string name;
    string address;
    string phone;
    string id;
};



#endif // CLASS_DEFINITIONS_H
