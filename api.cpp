#include "api.h"

sqlite3* db;

vector<Medicine> check_shortage(int quantity) {
    vector<Medicine> v;
    //char* err;
    int result;
    result = sqlite3_open("Pharmacy.db", &db);
    sqlite3_stmt* stmt;
    string query = "SELECT ID,Name ,Quantity,Supplier FROM MEDICINE WHERE Quantity <=" + to_string(quantity);
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    Medicine m;
    while (result = sqlite3_step(stmt) == SQLITE_ROW) {
        m.id = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        m.name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        m.quantity = sqlite3_column_int(stmt, 2);
        m.supplier_company = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        v.push_back(m);
    }
    return v;
}

vector<Pharmacist> get_pharmacists() {
    vector<Pharmacist> v;
    //char* err;
    int result;
    result = sqlite3_open("Pharmacy.db", &db);
    sqlite3_stmt* stmt;
    string query = "SELECT * FROM PHARMACIST";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    Pharmacist p;
    while (result = sqlite3_step(stmt) == SQLITE_ROW) {
        p.id = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        p.fname = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        p.lname = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        p.username =string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        p.password = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
        p.salary = sqlite3_column_int(stmt, 5);
        p.is_admin = sqlite3_column_int(stmt, 6);
        v.push_back(p);
    }
        return v;
}

vector<Supplier> get_suppliers() {
    vector<Supplier> v;
    char* err;
    int result;
    result = sqlite3_open("Pharmacy.db", &db);
    sqlite3_stmt* stmt;
    string query = "SELECT ID, Name , Telephone, Address FROM SUPPLIER";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    Supplier s;
    while (result = sqlite3_step(stmt) == SQLITE_ROW) {
        s.id = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        s.name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        s.phone = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        s.address = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        v.push_back(s);
    }
    return v;

}

string insert_medicine(Medicine md){
    int result = 0;
    sqlite3_stmt* stmt;
    result = sqlite3_open("Pharmacy.db", &db);
    string qu = "SELECT ID From MEDICINE";
    result = sqlite3_prepare_v2(db, qu.c_str(), -1, &stmt, NULL);
    vector<string> ii;

    while (result = sqlite3_step(stmt) == SQLITE_ROW) {
        ii.push_back(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
    }
    for (int i = 0; i < ii.size(); i++) {
        if (md.id == ii[i]) {
            return "ID is already used..Please Enter another ID";
        }
    }

    string q = "SELECT Name From MEDICINE";
    result = sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    vector<string> us;
    while (result = sqlite3_step(stmt) == SQLITE_ROW) {
        us.push_back(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
    }
    for (int i = 0; i < us.size(); i++) {
        if (md.name == us[i]) {
            return "Medicine is already in the stock!!"; // Medicine is already exists!!
        }
    }
    if (md.quantity <= 0 || md.purchase_price <=0 || md.sell_price <=0 ) {
        return "Please Enter valid numbers";
    }

    string query = "INSERT INTO MEDICINE(ID,Name,Quantity,Sell,Purchase,Category,Supplier) VALUES(?,?,?,?,?,?,?);";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, md.id.c_str(), md.id.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, md.name.c_str(), md.name.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, md.quantity);
    sqlite3_bind_double(stmt, 4, md.sell_price);
    sqlite3_bind_double(stmt, 5, md.purchase_price);
    sqlite3_bind_text(stmt, 6, md.category.c_str(), md.category.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, md.supplier_company.c_str(), md.supplier_company.length(), SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return "Medicine inserted Successfully"; //Medicine inserted Successfully
}

string insert_pharmacist(Pharmacist ph) {

    int result = 0;
    sqlite3_stmt* stmt;
    result = sqlite3_open("Pharmacy.db", &db);
    string qu = "SELECT ID From PHARMACIST";
    result = sqlite3_prepare_v2(db, qu.c_str(), -1, &stmt, NULL);
    vector<string> ii;
    while (result = sqlite3_step(stmt) == SQLITE_ROW) {
        ii.push_back(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
    }
    for (int i = 0; i < ii.size(); i++) {
        if (ph.id == ii[i]) {
            return "ID is already used..Please Enter another ID"; // ID is already used..Please Enter another ID
        }
    }

    string q = "SELECT Username From PHARMACIST";
    result = sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    vector<string> us;
    while (result = sqlite3_step(stmt) == SQLITE_ROW) {
        us.push_back(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
    }
    for (int i = 0; i < us.size(); i++) {
        if (ph.username == us[i]) {
            return "Username is already used..Please enter another Username"; // "Username is already used..Please enter another Username"
        }
    }

    string query = "INSERT INTO PHARMACIST(ID,FName,LName,Username,Password,Salary,Is_admin) VALUES(?,?,?,?,?,?,?);";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, ph.id.c_str(), ph.id.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, ph.fname.c_str(), ph.fname.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, ph.lname.c_str(), ph.lname.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, ph.username.c_str(), ph.username.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, ph.password.c_str(), ph.password.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 6, ph.salary);
    sqlite3_bind_int(stmt, 7, ph.is_admin);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    return "Pharmacist inserted successfully";

}

string insert_supplier(Supplier sup) {
    int result = 0;
    sqlite3_stmt* stmt;
    result = sqlite3_open("Pharmacy.db", &db);
    string qu = "SELECT ID From SUPPLIER";
    result = sqlite3_prepare_v2(db, qu.c_str(), -1, &stmt, NULL);
    vector<string> ii;
    while (result = sqlite3_step(stmt) == SQLITE_ROW) {
        ii.push_back(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
    }
    for (int i = 0; i < ii.size(); i++) {
        if (sup.id == ii[i]) {
            return " ID is already used..Please Enter another ID"; // ID is already used..Please Enter another ID
        }
    }

    string query = "INSERT INTO SUPPLIER(ID,Name,Telephone,Address) VALUES(?,?,?,?);";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, sup.id.c_str(), sup.id.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, sup.name.c_str(), sup.name.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, sup.phone.c_str(), sup.phone.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, sup.address.c_str(), sup.address.length(), SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return "Supplier inserted successfully";
}

string remove_pharmacist(string id) {
    vector<string>v;
    bool x = false;
    char* err;
    int result;
    sqlite3_stmt* stmt;
    result = sqlite3_open("Pharmacy.db", &db);
    string q = "SELECT ID FROM PHARMACIST";
    result = sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    while (result = sqlite3_step(stmt) == SQLITE_ROW) {
        v.push_back(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));

    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == id) {
            x = true;
        }
    }
    if (x == true) {
        string query = "DELETE FROM PHARMACIST WHERE ID ='" + id + "'";
              result = sqlite3_exec(db, query.c_str(), NULL, 0, &err);
              return "Pharmacist is deleted successfully";
    }
    else {
        return "Not found pharmacist with this ID";
    }

}

int is_admin(string user_name, string pass)
{
    int result;
    int  is_admin =-1;
    result = sqlite3_open("Pharmacy.db", &db);
    sqlite3_stmt* stmt;
    string query = "SELECT Is_admin FROM PHARMACIST WHERE Username = '" + user_name + "' AND Password = '"+pass+"'";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (result = sqlite3_step(stmt) == SQLITE_ROW)
         is_admin = sqlite3_column_int(stmt, 0);
    return is_admin;
}


vector<Medicine> Medicine_available(string id, int quantity) {
    vector<Medicine> v;
    int x;
    const unsigned char* c;
    string str;
    int result = 0;
    sqlite3_stmt* stmt;
    result = sqlite3_open("Pharmacy.db", &db);

        string query = "SELECT Quantity,Category FROM MEDICINE WHERE ID = '" + id + "'";
        result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
        sqlite3_step(stmt);
        x = sqlite3_column_int(stmt, 0);
        c = sqlite3_column_text(stmt, 1);
        str = std::string(reinterpret_cast<const char*>(c));
        if (x < quantity) {

            string query = "SELECT ID,Name,Quantity,Sell FROM MEDICINE WHERE Category = '" + str + "' AND Quantity !=0";
            result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
            Medicine m;

                  while (result = sqlite3_step(stmt) == SQLITE_ROW) {

                      m.id = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
                      m.name= std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
                      m.quantity = sqlite3_column_int(stmt, 2);
                      m.sell_price= sqlite3_column_double(stmt, 3);
                      m.is_alternative = true;

                      v.push_back(m);

                }
                  return v;
            }


        else {
            char* err;
            Medicine m;
            int price = 0;
            string name;
            string query = "SELECT ID,Name ,Sell FROM MEDICINE WHERE ID ='" + id + "'";
            result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
            sqlite3_step(stmt);
            m.id = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
            m.name = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
            m.sell_price = sqlite3_column_int(stmt, 2);
            m.is_alternative = false;
            v.push_back(m);
            string q = "UPDATE MEDICINE SET Quantity = Quantity -" + to_string(quantity) + " WHERE ID = '" + id + "'";
            result = sqlite3_exec(db, q.c_str(), NULL, 0, &err);
            return v;

        }
    }


string delete_medicine(string med_id)
{
    char* messageError;
    string result;
    string sql = "DELETE FROM MEDICINE WHERE ID = '" + med_id + "' ";

    int exit = sqlite3_open("Pharmacy.db", &db);
    /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
    exit = sqlite3_exec(db, sql.c_str(), NULL, NULL, &messageError);
    if (exit != SQLITE_OK) {
        result = "Couldn't delete the Medicine";
    }
    else {
        result = "Medicine deleted Successfully!";
    }

    return result;
}

string delete_supplier(string id)
{
    vector<string>v;
    bool x = false;
    char* err;
    int result;
    sqlite3_stmt* stmt;
    result = sqlite3_open("Pharmacy.db", &db);
    string q = "SELECT ID FROM SUPPLIER";
    result = sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    while (result = sqlite3_step(stmt) == SQLITE_ROW) {
        v.push_back(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));

    }
    for (int i = 0; i < v.size(); i++) {
        if (v[i] == id) {
            x = true;
        }
    }
    if (x == true) {
        string query = "DELETE FROM SUPPLIER WHERE ID ='" + id + "'";
        result = sqlite3_exec(db, query.c_str(), NULL, 0, &err);
        return "Supplier is deleted successfully";
    }
    else {
        return "Not found supplier with this ID";
    }
}

string update_pharmacist(Pharmacist p) {
    char* err;
    int result = 0;
    result = sqlite3_open("Pharmacy.db", &db);
    string q = "UPDATE PHARMACIST SET FName = '" + p.fname + "', LName = '" + p.lname + "', Username = '" + p.username + "', Password = '" + p.password + "', Salary = '" + to_string(p.salary) + "' , Is_admin = '" + to_string(p.is_admin) + "' WHERE ID = '" + p.id + "'";
    result = sqlite3_exec(db, q.c_str(), NULL, 0, &err);
    return "Pharmacist is updated Successfully";
}

string update_supplier(Supplier s) {
    char* err;
    int result = 0;
    result = sqlite3_open("Pharmacy.db", &db);
    string q ="UPDATE SUPPLIER SET Name = '"+s.name +"', Telephone = '"+s.phone +"', Address = '"+s.address+"' WHERE ID = '"+s.id+"'";
    result = sqlite3_exec(db, q.c_str(), NULL, 0, &err);
    return "Supplier is updated Successfully";
}

bool medicine_available(string name) {
    vector<string> ii;
    char* err;
    int result = 0;
    result = sqlite3_open("Pharmacy.db", &db);
    string q = "SELECT Name From MEDICINE";
    sqlite3_stmt* stmt;
    result = sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    while (result = sqlite3_step(stmt) == SQLITE_ROW) {
        ii.push_back(string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
    }
    for (int i = 0; i < ii.size(); i++) {
        if (name == ii[i]) {
            return true;
        }
    }
    return false;

}

vector<Medicine> get_medicines() {
    vector<Medicine> v;
    char* err;
    int result;
    result = sqlite3_open("Pharmacy.db", &db);
    sqlite3_stmt* stmt;
    string query = "SELECT * FROM MEDICINE";
    result = sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    Medicine m;
    while (result = sqlite3_step(stmt) == SQLITE_ROW) {

        m.id = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        m.name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        m.quantity = sqlite3_column_int(stmt, 2);
        m.sell_price = sqlite3_column_double(stmt, 3);
        m.purchase_price= sqlite3_column_double(stmt, 4);
        m.category = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        m.supplier_company = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
        v.push_back(m);
    }
    return v;
}

double get_medicine_price(string name) {

    int result = 0;
    double d = 0;
    sqlite3_stmt* stmt;
    result = sqlite3_open("Pharmacy.db", &db);
    string q = "SELECT Sell FROM MEDICINE WHERE Name = '" + name + "'";
    result = sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    sqlite3_step(stmt);
    d = sqlite3_column_double(stmt, 0);
    return d;
}

Pharmacist get_pharmacist(string username) {
    Pharmacist p;
    char* err;
    int result = 0;
    sqlite3_stmt* stmt;
    result = sqlite3_open("Pharmacy.db", &db);
    string q = "SELECT ID , FName , LName , Username , Password , Salary , Is_admin FROM PHARMACIST WHERE Username ='" + username + "'";
    result = sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    sqlite3_step(stmt);
    p.id = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
    p.fname = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
    p.lname = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
    p.username = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
    p.password = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
    p.salary = sqlite3_column_int(stmt, 5);
    p.is_admin = sqlite3_column_int(stmt, 6);

    return p;

}
