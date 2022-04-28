#ifndef EMPLOYEE_CLASS_H
#define EMPLOYEE_CLASS_H
#include <iostream>
using namespace std;

typedef enum{
    Admin, Pharmacist, Not_Found
}User_type;


class Employee{
public:
    string ph_id;
    string fname;
    string lname;
    string username;
    string password;
    int salary;
    User_type is_pharmacist; /* to differentiate between admin and pharmacist */
};

#endif // EMPLOYEE_CLASS_H
