#ifndef PHARMACIST_CLASS_H
#define PHARMACIST_CLASS_H
#include <QString>
using namespace std;

typedef enum{
    Admin, Pharmacist, Not_Found
}User_type;


class Pharmacist{
public:
    QString ph_id;
    QString name;
    QString password;
    int salary;
};

#endif // PHARMACIST_CLASS_H
