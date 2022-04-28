#ifndef ةEDICINE_CLASS_H
#define ةEDICINE_CLASS_H
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
    bool is_alternative;
};

#endif // ةEDICINE_CLASS_H
