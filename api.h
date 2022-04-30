#ifndef API_H
#define API_H
#include "db/sqlite3.h"
#include "navigation.h"

extern sqlite3* db;

vector<Medicine> check_shortage(int quantity);

vector<Pharmacist> get_pharmacists();

vector<Supplier> get_suppliers();

string insert_medicine(Medicine md);
//string insert_medicine(string id,string name, int quantity, double sell_price, double purchase_price, string category, string supplier);

string insert_pharmacist(Pharmacist ph);
//string insert_pharmacist(string id,string fname,string lname,string username,string password,int salary,int is_admin);

string insert_supplier(Supplier sup);
//string insert_supplier(string id, string name, string telephone, string address);

vector<Medicine> Medicine_available(string id, int quantity); /* not yet */

string remove_pharmacist(string id);

int is_admin(string user_name, string pass);

#endif // API_H
