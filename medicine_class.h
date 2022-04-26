#ifndef MEDICINE_CLASS_H
#define MEDICINE_CLASS_H
#include <iostream>
using namespace std;

class Medicine{
public:
    int id;
    int quantity;
    int buy_price;
    int sell_price;
    string name;
    string supplier_company;
    string category;
};

#endif // MEDICINE_CLASS_H
