#include "navigation.h"


void launch_new_window(Window_Type type, QWidget* current_window){
    switch(type){
        case GUI_Employees_Window:{
            Employee_Window *emp_window = new Employee_Window();
            emp_window->show();
            break;
            }
        case GUI_Medicine_Stock_Window:{
            Medicine_Window *medicine_window = new Medicine_Window();
            medicine_window->show();
            break;
        }

        case GUI_Admin_Panel_Window:{
            Admin_Panel *admin_window = new Admin_Panel();
            admin_window->show();
            break;
        }

        case GUI_Pharmacist_Window:{
            Pharmacist_Window *ph_window = new Pharmacist_Window();
            ph_window->show();
            break;
        }

        case GUI_Login_Window:{
            MainWindow *main_window = new MainWindow;
            main_window->show();
            break;
        }
    }

    current_window->hide();
}
