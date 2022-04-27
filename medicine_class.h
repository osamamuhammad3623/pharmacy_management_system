#ifndef MEDICINE_CLASS_H
#define MEDICINE_CLASS_H
#include <QString>
using namespace std;

class Medicine{
public:
    int id;
    int quantity;
    int buy_price;
    int sell_price;
    QString name;
    QString supplier_company;
    QString category;
    bool is_alternative;
};

#endif // MEDICINE_CLASS_H
