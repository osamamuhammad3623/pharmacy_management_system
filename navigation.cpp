#include "navigation.h"


void launch_new_window(Window_Type type, QWidget* current_window){
    switch(type){
        case Employees_Window:{
            add_employees_window *emp_window = new add_employees_window();
            emp_window->show();
            break;
            }
        case Medicine_Stock_Window:{
            add_medicine_window *medicine_window = new add_medicine_window();
            medicine_window->show();
            break;
        }

        case Admin_Panel_Window:{
            admin_panel *admin_window = new admin_panel();
            admin_window->show();
            break;
        }

        case Pharmacist_Window:{
            pharmacist_window *ph_window = new pharmacist_window();
            ph_window->show();
            break;
        }

        case Login_Window:{
            MainWindow *main_window = new MainWindow;
            main_window->show();
            break;
        }
    }

    current_window->hide();
}
