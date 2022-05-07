#ifndef API_H
#define API_H
#include "db/sqlite3.h"
#include "navigation.h"

extern sqlite3* db;

vector<Medicine> check_shortage(int quantity);

vector<Pharmacist> get_pharmacists();

vector<Supplier> get_suppliers();

string insert_medicine(Medicine md);

string insert_pharmacist(Pharmacist ph);

string insert_supplier(Supplier sup);

vector<Medicine> Medicine_available(string id, int quantity);

string remove_pharmacist(string id);

int is_admin(string user_name, string pass);

#endif // API_H
