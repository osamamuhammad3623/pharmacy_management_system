#ifndef API_H
#define API_H
#include "db/sqlite3.h"
#include "QSqlDatabase"
#include "QSqlQuery"
#include "navigation.h"
#include "QMessageBox"


/* will be used to send pharmacist username from login window [mainwindow] to pharmacist window */
extern string ph_username;


extern sqlite3* db;

vector<Medicine> check_shortage(int quantity);

vector<Pharmacist> get_pharmacists();
vector<Supplier> get_suppliers();
vector<Medicine> get_medicines();
double get_medicine_price(string name);
Pharmacist get_pharmacist(string username);

string insert_medicine(Medicine md);
string insert_pharmacist(Pharmacist ph);
string insert_supplier(Supplier sup);
string insert_invoice(string name, string time, string date, int quantity);

vector<Medicine> get_alternatives(string id);
bool medicine_available(string name, int q);
double calculate_profit(string month);

string remove_pharmacist(string id);
string delete_medicine(string id);
string delete_supplier(string sup_id);

int is_admin(string user_name, string pass);

string update_pharmacist(Pharmacist p);
string update_pharmacist_profile(Pharmacist p);
string update_supplier(Supplier s);
string update_medicine(QString name, int quantity);

#endif // API_H
