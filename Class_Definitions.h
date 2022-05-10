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
    double purchase_price;
    double sell_price;
    string name;
    string supplier_company;
    string category;
    bool is_alternative;

    string date_added;
    string expire_date;
};


class Supplier{
public:
    string id;
    string name;
    string phone;
    string address;
};


class invoice_item {
public:
    string name;
    double price;
    int quantity;
};


class invoice{
public:
    string name;
    string quantity;
    string date;
    string time;
};


#endif // CLASS_DEFINITIONS_H
