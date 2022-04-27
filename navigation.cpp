#include "navigation.h"

void launch_employees_window(){
    add_employees_window *emp_window = new add_employees_window();
    emp_window->show();
}

void launch_medicine_window(){
    add_medicine_window *medicine_window = new add_medicine_window();
    medicine_window->show();
}

void launch_admin_window(){
    admin_panel *admin_window = new admin_panel();
    admin_window->show();
}

void launch_pharmacist_window(){
    pharmacist_window *ph_window = new pharmacist_window();
    ph_window->show();
}

void launch_login_window(){
    MainWindow *main_window = new MainWindow;
    main_window->show();
}
