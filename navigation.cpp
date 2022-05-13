#include "navigation.h"

string g_pharmacist_name;

void launch_new_window(Window_Type type, QWidget* current_window){
    switch(type){
        case GUI_Employees_Window:{
            Employee_Window *emp_window = new Employee_Window();
            emp_window->setWindowTitle("Manage Users");
            emp_window->show();
            break;
        }
        case GUI_Medicine_Stock_Window:{
            Medicine_Window *medicine_window = new Medicine_Window();
            medicine_window->setWindowTitle("Manage Medicine stock");
            medicine_window->show();
            break;
        }

        case GUI_Admin_Panel_Window:{
            Admin_Panel *admin_window = new Admin_Panel();
            admin_window->show();
            break;
        }

        case GUI_Pharmacist_Window:{
            Pharmacist_window *ph_window = new Pharmacist_window();
            ph_window->show();
            break;
        }

        case GUI_Login_Window:{
            MainWindow *main_window = new MainWindow;
            main_window->show();
            break;
        }

        case GUI_Supplier_Window:{
            supplier_window *main_window = new supplier_window();
            main_window->show();
            break;
        }

        case GUI_Pharmacist_Profile_Window:{
            pharmacist_profile_window *main_window = new pharmacist_profile_window();
            main_window->show();
            break;
        }
    }

    current_window->hide();
}
