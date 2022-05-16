#include "api.h"

vector<Medicine> check_shortage(int quantity) {
    vector<Medicine> v;
    sqlite3_stmt* stmt;
    string query = "SELECT ID,Name ,Quantity,Supplier FROM MEDICINE WHERE Quantity <=" + to_string(quantity);
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    Medicine m;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        m.id = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        m.name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        m.quantity = sqlite3_column_int(stmt, 2);
        m.supplier_company = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        v.push_back(m);
    }
    sqlite3_close(db); return v;
}

vector<Pharmacist> get_pharmacists() {
    vector<Pharmacist> v;
    sqlite3_stmt* stmt;
    string query = "SELECT * FROM PHARMACIST";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    Pharmacist p;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        p.id = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        p.fname = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        p.lname = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        p.username =string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        p.password = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
        p.salary = sqlite3_column_int(stmt, 5);
        p.is_admin = sqlite3_column_int(stmt, 6);
        v.push_back(p);
    }
    sqlite3_close(db); return v;
}

vector<Supplier> get_suppliers() {
    vector<Supplier> v;
    sqlite3_stmt* stmt;
    string query = "SELECT ID, Name , Telephone, Address FROM SUPPLIER";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    Supplier s;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        s.id = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        s.name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        s.phone = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
        s.address = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
        v.push_back(s);
    }
    sqlite3_close(db); return v;
}

string insert_medicine(Medicine md){
    // check that ID is unique
    sqlite3_stmt* stmt;
    string qu = "SELECT ID From MEDICINE";
    sqlite3_prepare_v2(db, qu.c_str(), -1, &stmt, NULL);
    string current_id;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        current_id = (string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
        if (md.id == current_id) {
            sqlite3_close(db); return "ID is already used..Please Enter another ID";
        }
    }

    // check that name is unique
    string q = "SELECT Name From MEDICINE";
    sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    string current_name;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        current_name = (string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
        if (md.name == current_name) {
            sqlite3_close(db); return "Name is already used..Please Enter another name";
        }
    }

    string query = "INSERT INTO MEDICINE(ID,Name,Quantity,Sell,Purchase,Category,Expiry_date,Supplier) VALUES(?,?,?,?,?,?,?,?);";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, md.id.c_str(), md.id.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, md.name.c_str(), md.name.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 3, md.quantity);
    sqlite3_bind_double(stmt, 4, md.sell_price);
    sqlite3_bind_double(stmt, 5, md.purchase_price);
    sqlite3_bind_text(stmt, 6, md.category.c_str(), md.category.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 7, md.expire_date.c_str(), md.expire_date.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 8, md.supplier_company.c_str(), md.supplier_company.length(), SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db); return "Medicine inserted Successfully"; //Medicine inserted Successfully
}

string insert_pharmacist(Pharmacist ph) {
    // check that ID is unique
    sqlite3_stmt* stmt;
    string qu = "SELECT ID From PHARMACIST";
    sqlite3_prepare_v2(db, qu.c_str(), -1, &stmt, NULL);
    string _id;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        _id = (string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
        if (ph.id == _id){
            sqlite3_close(db); return "ID is already used..Please Enter another ID";
        }
    }

    // check that username is unique
    string q = "SELECT Username From PHARMACIST";
    sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    string _username;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        _username = (string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
        if (ph.username == _username) {
            sqlite3_close(db); return "Username is already used..Please enter another Username";
        }
    }


    string query = "INSERT INTO PHARMACIST(ID,FName,LName,Username,Password,Salary,Is_admin) VALUES(?,?,?,?,?,?,?);";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, ph.id.c_str(), ph.id.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, ph.fname.c_str(), ph.fname.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, ph.lname.c_str(), ph.lname.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, ph.username.c_str(), ph.username.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 5, ph.password.c_str(), ph.password.length(), SQLITE_TRANSIENT);
    sqlite3_bind_int(stmt, 6, ph.salary);
    sqlite3_bind_int(stmt, 7, ph.is_admin);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);

    sqlite3_close(db); return "User inserted successfully";

}

string insert_supplier(Supplier sup) {
    // check that ID is unique
    sqlite3_stmt* stmt;
    string qu = "SELECT ID From SUPPLIER";
    sqlite3_prepare_v2(db, qu.c_str(), -1, &stmt, NULL);
    string _id;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        _id = (string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));
        if (sup.id == _id) {
            sqlite3_close(db); return " ID is already used..Please Enter another ID";
        }
    }

    string query = "INSERT INTO SUPPLIER(ID,Name,Telephone,Address) VALUES(?,?,?,?);";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_bind_text(stmt, 1, sup.id.c_str(), sup.id.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 2, sup.name.c_str(), sup.name.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 3, sup.phone.c_str(), sup.phone.length(), SQLITE_TRANSIENT);
    sqlite3_bind_text(stmt, 4, sup.address.c_str(), sup.address.length(), SQLITE_TRANSIENT);
    sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    sqlite3_close(db); return "Supplier inserted successfully";
}

string remove_pharmacist(string id) {
    sqlite3_stmt* stmt;
    string q = "SELECT ID FROM PHARMACIST";
    sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    string current_id;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        current_id = (string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0))));

        if (current_id == id){
            string query = "DELETE FROM PHARMACIST WHERE ID ='" + id + "'";
                  sqlite3_exec(db, query.c_str(), NULL, 0, NULL);
                  sqlite3_close(db); return "Pharmacist is deleted successfully";
        }
    }

    sqlite3_close(db); return "Not found pharmacist with this ID";

}

int is_admin(string user_name, string pass)
{
    int  is_admin =NOT_VALID_CREDENTIALS;

    sqlite3_stmt* stmt;
    string query = "SELECT Is_admin FROM PHARMACIST WHERE Username = '" + user_name + "' AND Password = '"+pass+"'";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    while (sqlite3_step(stmt) == SQLITE_ROW)
         is_admin = sqlite3_column_int(stmt, 0);
    sqlite3_close(db); return is_admin;
}

vector<Medicine> get_alternatives(string name) {
    vector<Medicine> v;
    const unsigned char* cat;
    string str;
    sqlite3_stmt* stmt;

    string query = "SELECT Category FROM MEDICINE WHERE Name = '" + name + "'";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    sqlite3_step(stmt);
    cat = sqlite3_column_text(stmt, 0);
    str = std::string(reinterpret_cast<const char*>(cat));

    query = "SELECT ID,Name,Quantity,Sell FROM MEDICINE WHERE Category = '" + str + "' AND Quantity !=0";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    Medicine m;

    while (sqlite3_step(stmt) == SQLITE_ROW) {

        m.id = std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        m.name= std::string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        m.quantity = sqlite3_column_int(stmt, 2);
        m.sell_price= sqlite3_column_double(stmt, 3);
        m.is_alternative = true;

        v.push_back(m);
    }

    sqlite3_close(db); return v;
}

string update_medicine(string name, int quantity) {
    sqlite3_stmt* stmt;
    string q = "SELECT Quantity FROM MEDICINE WHERE Name = '" +name + "'";
    sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    sqlite3_step(stmt);
    int current_q = sqlite3_column_int(stmt, 0);
    if ((current_q - quantity) <= 0){
        delete_medicine_by_name(name);
    }else{
        QString query = "UPDATE MEDICINE SET Quantity = Quantity - " + QString::number(quantity)+ " WHERE Name = '" + QString::fromStdString(name) + "'";
        sqlite3_exec(db, query.toStdString().c_str(), NULL, 0, NULL);
    }
    sqlite3_close(db); return "success";
}

string delete_medicine_by_name(string name)
{
    string query = "DELETE FROM MEDICINE WHERE Name ='" + name + "'";
    sqlite3_exec(db, query.c_str(), NULL, 0, 0);
    sqlite3_close(db); return "Medicine is deleted successfully";

}

string delete_medicine(string id)
{
    string query = "DELETE FROM MEDICINE WHERE ID ='" + id + "'";
    sqlite3_exec(db, query.c_str(), NULL, 0, 0);
    sqlite3_close(db); return "Medicine is deleted successfully";
}

string delete_supplier(string id)
{
    string query = "DELETE FROM SUPPLIER WHERE ID ='" + id + "'";
    sqlite3_exec(db, query.c_str(), NULL, 0, NULL);
    sqlite3_close(db); return "Supplier is deleted successfully";
}

string update_pharmacist_profile(Pharmacist p) {
    string q = "UPDATE PHARMACIST SET Username = '" + p.username + "', Password = '" + p.password + "' WHERE ID = '" + p.id + "'";
    sqlite3_exec(db, q.c_str(), NULL, 0, NULL);
    sqlite3_close(db); return "Pharmacist is updated Successfully";
}

string update_pharmacist(Pharmacist p) {
    string q = "UPDATE PHARMACIST SET FName = '" + p.fname + "', LName = '" + p.lname + "', Username = '" + p.username + "', Password = '" + p.password + "', Salary = '" + to_string(p.salary) + "' , Is_admin = '" + to_string(p.is_admin) + "' WHERE ID = '" + p.id + "'";
    sqlite3_exec(db, q.c_str(), NULL, 0, NULL);
    sqlite3_close(db); return "Pharmacist is updated Successfully";
}


string update_supplier(Supplier s) {
    string q ="UPDATE SUPPLIER SET Name = '"+s.name +"', Telephone = '"+s.phone +"', Address = '"+s.address+"' WHERE ID = '"+s.id+"'";
    sqlite3_exec(db, q.c_str(), NULL, 0, NULL);
    sqlite3_close(db); return "Supplier is updated Successfully";
}

bool medicine_available(string name, int qu) {
    string q = "SELECT Name, Quantity From MEDICINE";
    sqlite3_stmt* stmt;
    sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    string md_name;
    int md_q;
    while (sqlite3_step(stmt) == SQLITE_ROW) {
        md_name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        md_q = sqlite3_column_int(stmt, 1);

        if (name == md_name && md_q >= qu){
            sqlite3_close(db); return true;
        }
    }

    sqlite3_close(db); return false;

}

vector<Medicine> get_medicines() {
    vector<Medicine> v;
    sqlite3_stmt* stmt;
    string query = "SELECT * FROM MEDICINE";
    sqlite3_prepare_v2(db, query.c_str(), -1, &stmt, NULL);
    Medicine m;
    while (sqlite3_step(stmt) == SQLITE_ROW) {

        m.id = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
        m.name = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
        m.quantity = sqlite3_column_int(stmt, 2);
        m.sell_price = sqlite3_column_double(stmt, 3);
        m.purchase_price= sqlite3_column_double(stmt, 4);
        m.category = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5)));
        m.expire_date = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6)));
        m.supplier_company = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7)));
        v.push_back(m);
    }
    sqlite3_close(db); return v;
}

double get_medicine_price(string name) {
    double d = 0;
    sqlite3_stmt* stmt;

    string q = "SELECT Sell FROM MEDICINE WHERE Name = '" + name + "'";
    sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    sqlite3_step(stmt);
    d = sqlite3_column_double(stmt, 0);
    sqlite3_close(db); return d;
}

Pharmacist get_pharmacist(string username) {
    Pharmacist p;
    sqlite3_stmt* stmt;

    string q = "SELECT ID , FName , LName , Username , Password , Salary , Is_admin FROM PHARMACIST WHERE Username ='" + username + "'";
    sqlite3_prepare_v2(db, q.c_str(), -1, &stmt, NULL);
    sqlite3_step(stmt);
    p.id = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 0)));
    p.fname = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1)));
    p.lname = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2)));
    p.username = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3)));
    p.password = string(reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4)));
    p.salary = sqlite3_column_int(stmt, 5);
    p.is_admin = sqlite3_column_int(stmt, 6);

    sqlite3_close(db); return p;
}
