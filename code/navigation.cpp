#include "navigation.h"

string g_pharmacist_name;

void launch_new_window(Window_Type type, QWidget* current_window){
    switch(type){
        case GUI_Employees_Window:{
            Employee_Window *new_window = new Employee_Window();
            new_window->setWindowTitle("Manage Users");
            new_window->show();
            break;
        }
        case GUI_Medicine_Stock_Window:{
            Medicine_Window *new_window = new Medicine_Window();
            new_window->setWindowTitle("Manage Medicine stock");
            new_window->show();
            break;
        }

        case GUI_Admin_Panel_Window:{
            Admin_Panel *new_window = new Admin_Panel();
            new_window->setWindowTitle("Admin Panel");
            new_window->show();
            break;
        }

        case GUI_Pharmacist_Window:{
            Pharmacist_window *new_window = new Pharmacist_window();
            new_window->setWindowTitle("Pharmacist Window");
            new_window->show();
            break;
        }

        case GUI_Login_Window:{
            MainWindow *new_window = new MainWindow;
            new_window->setWindowTitle("Login");
            new_window->show();
            break;
        }

        case GUI_Supplier_Window:{
            supplier_window *new_window = new supplier_window();
            new_window->setWindowTitle("Manage Suppliers");
            new_window->show();
            break;
        }

        case GUI_Pharmacist_Profile_Window:{
            pharmacist_profile_window *new_window = new pharmacist_profile_window();
            new_window->setWindowTitle("Pharmacist Profile");
            new_window->show();
            break;
        }
    }

    current_window->hide();
}
